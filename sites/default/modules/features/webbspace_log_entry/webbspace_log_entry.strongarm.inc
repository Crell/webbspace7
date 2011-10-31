<?php
/**
 * @file
 * webbspace_log_entry.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function webbspace_log_entry_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_log_entry';
  $strongarm->value = array();
  $export['menu_options_log_entry'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_log_entry';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_log_entry'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_log_entry';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_log_entry'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_log_entry';
  $strongarm->value = '1';
  $export['node_preview_log_entry'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_log_entry';
  $strongarm->value = 1;
  $export['node_submitted_log_entry'] = $strongarm;

  return $export;
}
