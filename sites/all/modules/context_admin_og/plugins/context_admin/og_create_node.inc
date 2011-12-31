<?php

/**
 * @file
 * Context admin plugin that auto populates the group.
 */

// Only registers plugin if there are group content types.
if (context_admin_og_get_types()) {
  $plugin = array(
    'title' => t('Create node with auto group membership'),
    'description' => t('Creates a node with the group audience prepopulated from context.'),
    'required context' => new ctools_context_required(t('Node'), 'node'),
    'content form' => 'context_admin_og_create_node_form',
    'content form submit' => 'context_admin_og_create_node_form_submit',
    'render' => 'context_admin_og_create_node_render_page',
    'form alter' => 'context_admin_og_create_node_form_alter',
  );
}

/**
 * Returns all available group content types.
 *
 * @return array
 *   An associative array keyed by machine readable name of the content type to
 *   the display name.
 *
 *  @todo Is there an OG API function for this?
 */
function context_admin_og_get_types() {
  $types = &drupal_static(__FUNCTION__, array());
  if (!$types) {
    foreach (node_type_get_names() as $name => $label) {
      if (og_is_group_content_type('node', $name)) {
        $types[$name] = $label;
      }
    }
  }
  return $types;
}

/**
 * Builds and returns the plugin settings form.
 *
 * @ingroup forms
 */
function context_admin_og_create_node_form($form, &$form_state, $contexts = array()) {

  // Gets all availabe group content types.
  $types = context_admin_og_get_types();

  // Gets configurations, sets defaults.
  $conf = $form_state['conf'] + array(
    'type' => key($types),
    'redirect_path' => 'node/%node:nid',
    'use_panels' => 0,
  );

  $form['type'] = array(
    '#type' => 'radios',
    '#title' => t('Node type'),
    '#options' => array_map('check_plain', $types),
    '#default_value' => $conf['type'],
    '#description' => t('Select the node type being created.'),
  );

  $form['redirect_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirect path'),
    '#default_value' => $conf['redirect_path'],
    '#description' => t('Define a custom path to redirect to after the node creation. This path will be translated with the node tokens of the parent node. Note: This overrides auto forwarding back to the original node.'),
  );

  $form['use_panels'] = array(
    '#access' => module_exists('panels'),
    '#type' => 'checkbox',
    '#title' => t('Render the node create form using Panels and Page Manager'),
    '#description' => t('Enable node/%node/edit in Page Manager. Unchecked renders node create form with Drupal\'s node templating system. This will prevent redirects from working.'),
    '#default_value' => $conf['use_panels'],
  );

  $rows = array();
  foreach ($contexts as $context) {
    $cid = '%' . check_plain($context->keyword) . ':';
    foreach (ctools_context_get_converters($cid, $context) as $keyword => $title) {
      $rows[] = array(
        check_plain($keyword),
        t('@identifier: @title', array('@title' => $title, '@identifier' => $context->identifier)),
      );
    }
  }

  $header = array(t('Keyword'), t('Value'));
  $form['display_title']['contexts'] = array(
    '#type' => 'fieldset',
    '#title' => t('Substitutions'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#value' => theme('table', array('header' => $header, 'rows' => $rows)),
  );

  return $form;
}

/**
 * Processes context_admin_og_create_node_form form submissions.
 */
function context_admin_og_create_node_form_submit($form, &$form_state) {
  $form_state['conf']['type'] = $form_state['values']['type'];
  $form_state['conf']['redirect_path'] = $form_state['values']['redirect_path'];
  $form_state['conf']['use_panels'] = $form_state['values']['use_panels'];
}

/**
 * Renders the node form.
 *
 * @param $handler
 *   An object containing the handler.
 * @param $contexts
 *   An array of ctools_context objects.
 * @param $args
 *   An array of arguments extracted form the path.
 *
 * @return
 *   A FAPI array containing the form.
 *
 * @ingroup forms
 *
 * @see context_admin_node_add_wrapper().
 */
function context_admin_og_create_node_render_page($handler, $contexts, $args) {
  $fields = array(
    'group_audience' => array(
      'language' => LANGUAGE_NONE,
      'key' => 'gid',
      'values' => array(
        $contexts[$handler->conf['submitted_context']]->data->nid
      ),
    ),
  );
  $use_panels = !empty($handler->conf['use_panels']);
  return context_admin_node_add_wrapper($handler->conf['type'], $fields, $use_panels);
}

/**
 * Form altering function for the node form.
 */
function context_admin_og_create_node_form_alter(&$form, &$form_state, $form_id, $page) {
  if ('context_admin_node_form_wrapper' == $form_id) {
    $conf = $page['handler']->conf;

    // Hides the "group_audience" field from display.
    $form['group_audience']['#access'] = FALSE;
    $form['group_audience']['und']['#required'] = FALSE;

    // Adds submit handler if the redirect path was set.
    if ($conf['redirect_path']) {

      $form['page_context'] = array(
        '#type' => 'value',
        '#value' => array(
          'contexts' => $page['contexts'],
          'submitted_context' => $conf['submitted_context'],
        ),
      );

      $form['redirect_path'] = array(
        '#type' => 'value',
        '#value' => $conf['redirect_path'],
      );

      // Adds submit handler that performs the redirect.
      $form['actions']['submit']['#submit'][] = 'context_admin_og_create_node_submit';
    }
  }
}

/**
 * Processes context_admin_node_form_wrapper form submissions.
 */
function context_admin_og_create_node_submit($form, &$form_state) {
  $values = &$form_state['values'];
  $form_state['no_redirect'] = FALSE;

  // Sets the redirect path.
  $path = $values['redirect_path'];
  $contexts = $values['page_context']['contexts'];
  $form_state['redirect'] = ctools_context_keyword_substitute($path, array(), $contexts);
}
