<?php

/**
 * Implements hook_views_default_views().
 */
function views_school_activity_views_default_views() {

  $view = new view;
  $view->name = 'school_activity';
  $view->description = 'Basic heartbeat activity streams in fields mode';
  $view->tag = 'default';
  $view->base_table = 'heartbeat_activity';
  $view->human_name = 'School Activity';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Heartbeat Activity View page';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'picture' => 'picture',
    'message' => 'message',
    'created_at' => 'message',
    'buttons' => 'message',
    'attachments' => 'message',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'message' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created_at' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'buttons' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'attachments' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No Activity';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Heartbeat activity: Node ID */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'heartbeat_activity';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = 0;
  /* Relationship: Heartbeat activity: User ID */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'heartbeat_activity';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Relationship: Heartbeat activity: User target ID */
  $handler->display->display_options['relationships']['uid_target']['id'] = 'uid_target';
  $handler->display->display_options['relationships']['uid_target']['table'] = 'heartbeat_activity';
  $handler->display->display_options['relationships']['uid_target']['field'] = 'uid_target';
  $handler->display->display_options['relationships']['uid_target']['required'] = 0;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid_target';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = 1;
  $handler->display->display_options['fields']['picture']['image_style'] = 'activity_avatar';
  /* Field: Heartbeat activity: Activity message */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  $handler->display->display_options['fields']['message']['label'] = '';
  $handler->display->display_options['fields']['message']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['message']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['message']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['message']['alter']['external'] = 0;
  $handler->display->display_options['fields']['message']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['message']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['message']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['message']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['message']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['message']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['message']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['message']['alter']['html'] = 0;
  $handler->display->display_options['fields']['message']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['message']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['message']['hide_empty'] = 0;
  $handler->display->display_options['fields']['message']['empty_zero'] = 0;
  $handler->display->display_options['fields']['message']['hide_alter_empty'] = 0;
  /* Field: Heartbeat activity: Creation date */
  $handler->display->display_options['fields']['created_at']['id'] = 'created_at';
  $handler->display->display_options['fields']['created_at']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['created_at']['field'] = 'created_at';
  $handler->display->display_options['fields']['created_at']['label'] = '';
  $handler->display->display_options['fields']['created_at']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created_at']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created_at']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created_at']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created_at']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created_at']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created_at']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created_at']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created_at']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created_at']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created_at']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created_at']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created_at']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_at']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created_at']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created_at']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created_at']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created_at']['date_format'] = 'time ago';
  /* Field: Heartbeat activity: Buttons */
  $handler->display->display_options['fields']['buttons']['id'] = 'buttons';
  $handler->display->display_options['fields']['buttons']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['buttons']['field'] = 'buttons';
  $handler->display->display_options['fields']['buttons']['label'] = '';
  $handler->display->display_options['fields']['buttons']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['buttons']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['buttons']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['buttons']['alter']['external'] = 0;
  $handler->display->display_options['fields']['buttons']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['buttons']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['buttons']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['buttons']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['buttons']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['buttons']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['buttons']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['buttons']['alter']['html'] = 0;
  $handler->display->display_options['fields']['buttons']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['buttons']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['buttons']['hide_empty'] = 0;
  $handler->display->display_options['fields']['buttons']['empty_zero'] = 0;
  $handler->display->display_options['fields']['buttons']['hide_alter_empty'] = 0;
  /* Field: Heartbeat activity: Attachments */
  $handler->display->display_options['fields']['attachments']['id'] = 'attachments';
  $handler->display->display_options['fields']['attachments']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['attachments']['field'] = 'attachments';
  $handler->display->display_options['fields']['attachments']['label'] = '';
  $handler->display->display_options['fields']['attachments']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['attachments']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['attachments']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['attachments']['alter']['external'] = 0;
  $handler->display->display_options['fields']['attachments']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['attachments']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['attachments']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['attachments']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['attachments']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['attachments']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['attachments']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['attachments']['alter']['html'] = 0;
  $handler->display->display_options['fields']['attachments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['attachments']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['attachments']['hide_empty'] = 0;
  $handler->display->display_options['fields']['attachments']['empty_zero'] = 0;
  $handler->display->display_options['fields']['attachments']['hide_alter_empty'] = 0;
  /* Sort criterion: Heartbeat activity: Creation date */
  $handler->display->display_options['sorts']['created_at']['id'] = 'created_at';
  $handler->display->display_options['sorts']['created_at']['table'] = 'heartbeat_activity';
  $handler->display->display_options['sorts']['created_at']['field'] = 'created_at';
  $handler->display->display_options['sorts']['created_at']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  
  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'School Activity - Block';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $translatables['school_activity'] = array(
    t('Master'),
    t('Heartbeat Activity View page'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No Activity'),
    t('content'),
    t('User ID'),
    t('User target ID'),
    t('All'),
    t('Block'),
    t('School Activity - Block'),
  );

  $views['school_activity'] = $view;

  return $views;
}
