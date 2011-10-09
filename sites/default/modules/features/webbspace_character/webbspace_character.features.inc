<?php
/**
 * @file
 * webbspace_character.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function webbspace_character_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function webbspace_character_node_info() {
  $items = array(
    'character' => array(
      'name' => t('Character'),
      'base' => 'node_content',
      'description' => t('A character played by a user.  Most posts are made by a Character.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
