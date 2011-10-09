<?php
/**
 * @file
 * webbspace_note.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function webbspace_note_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function webbspace_note_node_info() {
  $items = array(
    'note' => array(
      'name' => t('Note'),
      'base' => 'node_content',
      'description' => t('A note is posted on a board by a user or character.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
