<?php
/**
 * @file
 * webbspace_board.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function webbspace_board_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function webbspace_board_node_info() {
  $items = array(
    'board' => array(
      'name' => t('Board'),
      'base' => 'node_content',
      'description' => t('A Board is where the action is.  It is a group on which posting takes place, through characters.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
