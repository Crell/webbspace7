<?php
/**
 * @file
 * webbspace_page_note_add.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function webbspace_page_note_add_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
