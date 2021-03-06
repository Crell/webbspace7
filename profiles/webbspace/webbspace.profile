<?php

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function webbspace_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  debug(__FILE__ . ': ' . __LINE__);
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}

/**
 * Computes the value of the position label field on Characters at save time.
 *
 * @see _computed_field_compute_value()
 */
function computed_field_field_position_label_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  // The position label is the Position value and Custom Position value,
  // concatenated with an &.

  $positions = array();

  // Currently the field is configured to be single-value, but just to be
  // on the safe side we'll treat it as multi-value. Besides, it means we get
  // to use an anonymous function. :-)
  $tids = array_map(function($term) { return $term['tid']; }, field_get_items($entity_type, $entity, 'field_position'));

  foreach (taxonomy_term_load_multiple($tids) as $term) {
    $positions[] = entity_label('taxonomy_term', $term);
  }
  foreach (field_get_items($entity_type, $entity, 'field_position_custom') as $custom_position) {
    $positions[] = $custom_position['value'];
  }

  // Compress all of the position values together into a string.
  // Figuring out the structure of this value array took way longer than it
  // should have. Documentation EPIC FAIL!
  $entity_field[0]['value'] = implode(' & ', $positions);
}

/**
 * Computes the display of the position label field on Charaters, at view time.
 *
 * @see computed_field_field_formatter_view()
 */
function computed_field_field_position_label_display($field, $entity_field_item, $entity_lang, $langcode) {
  return check_plain($entity_field_item['value']);
}

/**
 * Computes the value of the character label field on Notes at save time.
 *
 * @see _computed_field_compute_value()
 */
function computed_field_field_character_label_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  // The character label is the Rank, name, and position of the character at the
  // time the node is saved.  Note that the character has to be loaded via a
  // reference field.

  // As with position label, none of this should be multi-value in practice
  // but we're treating it as if it were for robustness, just in case.

  $character_ref = field_get_items($entity_type, $entity, 'field_character');

  if ($character_ref) {
    $target_ids = array_map(function($ref) { return $ref['target_id']; }, $character_ref);
    $target_type = $instance['entity_type'];

    $characters = entity_load_multiple_by_name($target_type, $target_ids);
    foreach ($characters as $character) {
      $position_labels = array_filter(array_map(function($position) { return $position['value']; }, field_get_items($target_type, $character, 'field_position_label')));

      // We have to cast field_get_items() to an array, because for no-value
      // it returns FALSE, not an empty array like a non-braindead function would.
      $rank_tids = array_filter(array_map(function($term) { return $term['tid']; }, (array)field_get_items($target_type, $character, 'field_rank')));

      $ranks_labels = array();

      if ($rank_tids) {
        foreach (taxonomy_term_load_multiple($rank_tids) as $term) {
          $ranks_labels[] = entity_label('taxonomy_term', $term);
        }
      }

      // We can get away with literal replacement here instead of @ because
      // this text is saved to the database;  It's check_plain()ed on display,
      // so we don't want to double-encode things.
      if ($position_labels) {
        $character_labels[] = t('!rank !name (!position)', array(
          '!rank' => implode(', ', $ranks_labels),
          '!name' => entity_label($target_type, $character),
          '!position' => implode(', ', $position_labels),
        ));
      }
      else {
        $character_labels[] = t('!rank !name', array(
          '!rank' => implode(', ', $ranks_labels),
          '!name' => entity_label($target_type, $character),
        ));
      }
    }

    // An empty rank field would leave whitespace before the character name.
    // It's easier to just trim the result rather than introduce another possible
    // code path above.
    $character_labels = array_map('trim', $character_labels);

    $entity_field[0]['value'] = implode(' & ', $character_labels);
  }
  else {
    // There is no character referenced, so use the user's name instead.

    // This assumes the entity is a node.  In all of our use cases, it is.
    $account = user_load($entity->uid);

    // This will normally return the login name. We want the display name, of
    // course.  We need to figure out a login name/display name split yet.
    // @todo Figure out how to make this the display name, not login name.
    $entity_field[0]['value'] = entity_label('user', $account);
  }
}

/**
 * Computes the display of the position label field on Charaters, at view time.
 *
 * @see computed_field_field_formatter_view()
 */
function computed_field_field_character_label_display($field, $entity_field_item, $entity_lang, $langcode) {
  return check_plain($entity_field_item['value']);
}

/**
 * Form alter for context admin node add forms.
 *
 * @todo Turn this into a patch against auto_nodetitle.
 */
function webbspace_form_context_admin_node_form_wrapper_alter(&$form, &$form_state, $form_id) {
  auto_nodetitle_form_node_form_alter($form, $form_state, $form_id);
}
