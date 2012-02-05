<?php
/**
 * @file
 * webbspace_board.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function webbspace_board_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_board';
  $strongarm->value = array();
  $export['menu_options_board'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_board';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_board'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_board';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_board'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_board';
  $strongarm->value = '1';
  $export['node_preview_board'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_board';
  $strongarm->value = 0;
  $export['node_submitted_board'] = $strongarm;

  return $export;
}
