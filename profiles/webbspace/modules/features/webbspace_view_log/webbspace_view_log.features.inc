<?php
/**
 * @file
 * webbspace_view_log.features.inc
 */

/**
 * Implements hook_views_api().
 */
function webbspace_view_log_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
