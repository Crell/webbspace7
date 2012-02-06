<?php
/**
 * @file
 * webbspace_note.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function webbspace_note_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_note';
  $strongarm->value = array();
  $export['menu_options_note'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_note';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_note'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_note';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_note'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_note';
  $strongarm->value = '1';
  $export['node_preview_note'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_note';
  $strongarm->value = 0;
  $export['node_submitted_note'] = $strongarm;

  return $export;
}
