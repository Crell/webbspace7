<?php
/**
 * @file
 * webbspace_page_note_add.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function webbspace_page_note_add_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'add_note';
  $page->task = 'page';
  $page->admin_title = 'Add note';
  $page->admin_description = '';
  $page->path = 'node/%node/notes/add';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'context_exists',
        'settings' => array(
          'exists' => '1',
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'og_is_node_group',
        'settings' => NULL,
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'entity_bundle:node',
        'settings' => array(
          'type' => array(
            'board' => 'board',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
      3 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'create note content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'action',
    'title' => 'Start new thread',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_add_note_menu_context';
  $handler->task = 'page';
  $handler->subtask = 'add_note';
  $handler->handler = 'menu_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Context Admin',
    'no_blocks' => FALSE,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'context_admin_options' => 'og_create_node',
    'type' => 'note',
    'redirect_path' => 'node/%node:nid',
    'use_panels' => 0,
    'submitted_context' => 'argument_entity_id:node_1',
  );
  $page->default_handlers[$handler->name] = $handler;
  $pages['add_note'] = $page;

  return $pages;

}
