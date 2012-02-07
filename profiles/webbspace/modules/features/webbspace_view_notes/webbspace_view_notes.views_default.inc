<?php
/**
 * @file
 * webbspace_view_notes.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function webbspace_view_notes_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'notes';
  $view->description = 'Lists of notes on a board';
  $view->tag = 'webbspace';
  $view->base_table = 'node';
  $view->human_name = 'Notes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['display_comment'] = 'Under Construction: Views Tree is not yet working, and the character name link is not going to handle no-character condition right now very well.';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No-results message';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No notes have been posted in this group recently.  That\'s so sad. :-(';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Group membership: Node group membership */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = 0;
  /* Relationship: Character reference */
  $handler->display->display_options['relationships']['field_character_target_id']['id'] = 'field_character_target_id';
  $handler->display->display_options['relationships']['field_character_target_id']['table'] = 'field_data_field_character';
  $handler->display->display_options['relationships']['field_character_target_id']['field'] = 'field_character_target_id';
  $handler->display->display_options['relationships']['field_character_target_id']['ui_name'] = 'Character reference';
  $handler->display->display_options['relationships']['field_character_target_id']['label'] = 'Character';
  $handler->display->display_options['relationships']['field_character_target_id']['required'] = 0;
  /* Field: Nid (hidden) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Nid (hidden)';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Parent nid (hidden) */
  $handler->display->display_options['fields']['field_parent_note']['id'] = 'field_parent_note';
  $handler->display->display_options['fields']['field_parent_note']['table'] = 'field_data_field_parent_note';
  $handler->display->display_options['fields']['field_parent_note']['field'] = 'field_parent_note';
  $handler->display->display_options['fields']['field_parent_note']['ui_name'] = 'Parent nid (hidden)';
  $handler->display->display_options['fields']['field_parent_note']['label'] = '';
  $handler->display->display_options['fields']['field_parent_note']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_parent_note']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_parent_note']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_parent_note']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_parent_note']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_parent_note']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_parent_note']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_parent_note']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_parent_note']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_parent_note']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_parent_note']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_parent_note']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_parent_note']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_parent_note']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_parent_note']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_parent_note']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_parent_note']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_parent_note']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_parent_note']['click_sort_column'] = 'target_id';
  $handler->display->display_options['fields']['field_parent_note']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_parent_note']['field_api_classes'] = 0;
  /* Field: Character id (hidden) */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'field_character_target_id';
  $handler->display->display_options['fields']['nid_1']['ui_name'] = 'Character id (hidden)';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid_1']['link_to_node'] = 0;
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Posted date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['ui_name'] = 'Posted date';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_type'] = '0';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'webb_date';
  /* Field: Character */
  $handler->display->display_options['fields']['field_character_label']['id'] = 'field_character_label';
  $handler->display->display_options['fields']['field_character_label']['table'] = 'field_data_field_character_label';
  $handler->display->display_options['fields']['field_character_label']['field'] = 'field_character_label';
  $handler->display->display_options['fields']['field_character_label']['ui_name'] = 'Character';
  $handler->display->display_options['fields']['field_character_label']['label'] = '';
  $handler->display->display_options['fields']['field_character_label']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_character_label']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_character_label']['alter']['path'] = 'node/[nid_1]';
  $handler->display->display_options['fields']['field_character_label']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_character_label']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_character_label']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_character_label']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_character_label']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_character_label']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_character_label']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_character_label']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_character_label']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_character_label']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_character_label']['element_type'] = '0';
  $handler->display->display_options['fields']['field_character_label']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_character_label']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_character_label']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_character_label']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_character_label']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_character_label']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Contextual filter: OG membership: Group gid */
  $handler->display->display_options['arguments']['group']['id'] = 'group';
  $handler->display->display_options['arguments']['group']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group']['field'] = 'group';
  $handler->display->display_options['arguments']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['group']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['group']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'note' => 'note',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'notes');
  $handler->display->display_options['display_comment'] = 'The OG integration on this view may not work yet.';
  $handler->display->display_options['argument_input'] = array(
    'group' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG membership: Group gid',
    ),
  );
  $export['notes'] = $view;

  return $export;
}
