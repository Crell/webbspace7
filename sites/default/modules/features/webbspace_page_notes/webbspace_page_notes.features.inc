<?php
/**
 * @file
 * webbspace_page_notes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function webbspace_page_notes_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
