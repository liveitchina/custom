<?php

/**
 * Implements hook_views_default_views().
 */
function views_user_activity_views_default_views() {

  $view = new view;
  $view->name = 'user_activity';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'heartbeat_activity';
  $view->human_name = 'User Activity';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User Activity';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'heartbeat_activity';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 1;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No Recent Activity yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Heartbeat activity: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
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
  /* Field: Heartbeat activity: Node target ID */
  $handler->display->display_options['fields']['nid_target']['id'] = 'nid_target';
  $handler->display->display_options['fields']['nid_target']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['nid_target']['field'] = 'nid_target';
  $handler->display->display_options['fields']['nid_target']['label'] = '';
  $handler->display->display_options['fields']['nid_target']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_target']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid_target']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid_target']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid_target']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid_target']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid_target']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid_target']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid_target']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid_target']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid_target']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid_target']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid_target']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid_target']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid_target']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid_target']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid_target']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid_target']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid_target']['format_plural'] = 0;
  /* Field: Heartbeat activity: User activity ID */
  $handler->display->display_options['fields']['uaid']['id'] = 'uaid';
  $handler->display->display_options['fields']['uaid']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['uaid']['field'] = 'uaid';
  $handler->display->display_options['fields']['uaid']['label'] = '';
  $handler->display->display_options['fields']['uaid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uaid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uaid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uaid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uaid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uaid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uaid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uaid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uaid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uaid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uaid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uaid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uaid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uaid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uaid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uaid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uaid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uaid']['format_plural'] = 0;
  /* Field: Heartbeat activity: User ID */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uid']['format_plural'] = 0;
  /* Contextual filter: Heartbeat activity: User ID */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'heartbeat_activity';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['restrict_roles'] = 0;
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  
  /* Display: Block - User Activity */
  $handler = $view->new_display('block', 'Block - User Activity', 'block');
  $handler->display->display_options['block_description'] = 'User Activity';
  $translatables['user_activity'] = array(
    t('Master'),
    t('User Activity'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('No Recent Activity yet.'),
    t('.'),
    t(','),
    t('All'),
    t('Block - User Activity'),
  );

  $views['user_activity'] = $view;

  return $views;
}
