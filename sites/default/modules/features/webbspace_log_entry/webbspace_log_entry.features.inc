<?php
/**
 * @file
 * webbspace_log_entry.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function webbspace_log_entry_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function webbspace_log_entry_node_info() {
  $items = array(
    'log_entry' => array(
      'name' => t('Log entry'),
      'base' => 'node_content',
      'description' => t('A captain\'s log entry on a given board.'),
      'has_title' => '1',
      'title_label' => t('Date'),
      'help' => '',
    ),
  );
  return $items;
}
