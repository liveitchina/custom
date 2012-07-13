<?php

/**
 * Implements hook_views_default_views().
 */
function views_user_connections_views_default_views() {

  $view = new view;
  $view->name = 'user_connections';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'user_relationships';
  $view->human_name = 'User Connections';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My %2';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit own user profile';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No Connection yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: User relationships: Requestee user */
  $handler->display->display_options['relationships']['requestee_id']['id'] = 'requestee_id';
  $handler->display->display_options['relationships']['requestee_id']['table'] = 'user_relationships';
  $handler->display->display_options['relationships']['requestee_id']['field'] = 'requestee_id';
  $handler->display->display_options['relationships']['requestee_id']['required'] = 0;
  /* Relationship: User relationships: Requester user */
  $handler->display->display_options['relationships']['requester_id']['id'] = 'requester_id';
  $handler->display->display_options['relationships']['requester_id']['table'] = 'user_relationships';
  $handler->display->display_options['relationships']['requester_id']['field'] = 'requester_id';
  $handler->display->display_options['relationships']['requester_id']['required'] = 0;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'requestee_id';
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
  $handler->display->display_options['fields']['uid']['link_to_user'] = 0;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'requester_id';
  $handler->display->display_options['fields']['realname']['label'] = 'User';
  $handler->display->display_options['fields']['realname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['external'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['realname']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['realname']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['html'] = 0;
  $handler->display->display_options['fields']['realname']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['realname']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['realname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['realname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['realname']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['realname']['link_to_user'] = 1;
  /* Contextual filter: User relationships: Requester user */
  $handler->display->display_options['arguments']['requester_id']['id'] = 'requester_id';
  $handler->display->display_options['arguments']['requester_id']['table'] = 'user_relationships';
  $handler->display->display_options['arguments']['requester_id']['field'] = 'requester_id';
  $handler->display->display_options['arguments']['requester_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['requester_id']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['requester_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['requester_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['requester_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['requester_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['requester_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['requester_id']['not'] = 0;
  /* Filter criterion: User relationships: Relationship type */
  $handler->display->display_options['filters']['rtype']['id'] = 'rtype';
  $handler->display->display_options['filters']['rtype']['table'] = 'user_relationships';
  $handler->display->display_options['filters']['rtype']['field'] = 'rtype';
  $handler->display->display_options['filters']['rtype']['value'] = array(
  		0 => '3',
  );
  
  /* Display: Tutors */
  $handler = $view->new_display('page', 'Tutors', 'page_tutor');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Tutors';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User relationships: Requestee user */
  $handler->display->display_options['relationships']['requestee_id']['id'] = 'requestee_id';
  $handler->display->display_options['relationships']['requestee_id']['table'] = 'user_relationships';
  $handler->display->display_options['relationships']['requestee_id']['field'] = 'requestee_id';
  $handler->display->display_options['relationships']['requestee_id']['required'] = 0;
  /* Relationship: User relationships: Requester user */
  $handler->display->display_options['relationships']['requester_id']['id'] = 'requester_id';
  $handler->display->display_options['relationships']['requester_id']['table'] = 'user_relationships';
  $handler->display->display_options['relationships']['requester_id']['field'] = 'requester_id';
  $handler->display->display_options['relationships']['requester_id']['required'] = 0;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'requester_id';
  $handler->display->display_options['relationships']['profile']['required'] = 0;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
  		'user' => 'user',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'requester_id';
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
  $handler->display->display_options['fields']['uid']['link_to_user'] = 0;
  /* Field: Profile: Profile Picture */
  $handler->display->display_options['fields']['field_profile_picture']['id'] = 'field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['table'] = 'field_data_field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['field'] = 'field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_picture']['label'] = 'Picture';
  $handler->display->display_options['fields']['field_profile_picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_profile_picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_picture']['settings'] = array(
  		'image_style' => 'profile_main',
  		'image_link' => '',
  );
  $handler->display->display_options['fields']['field_profile_picture']['field_api_classes'] = 0;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'requester_id';
  $handler->display->display_options['fields']['realname']['label'] = 'User';
  $handler->display->display_options['fields']['realname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['external'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['realname']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['realname']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['html'] = 0;
  $handler->display->display_options['fields']['realname']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['realname']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['realname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['realname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['realname']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['realname']['link_to_user'] = 1;
  /* Field: User relationships: Relationship type */
  $handler->display->display_options['fields']['rtype']['id'] = 'rtype';
  $handler->display->display_options['fields']['rtype']['table'] = 'user_relationships';
  $handler->display->display_options['fields']['rtype']['field'] = 'rtype';
  $handler->display->display_options['fields']['rtype']['label'] = 'Relationship';
  $handler->display->display_options['fields']['rtype']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['external'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['rtype']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['rtype']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['html'] = 0;
  $handler->display->display_options['fields']['rtype']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['rtype']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['rtype']['hide_empty'] = 0;
  $handler->display->display_options['fields']['rtype']['empty_zero'] = 0;
  $handler->display->display_options['fields']['rtype']['hide_alter_empty'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User relationships: Requestee user */
  $handler->display->display_options['arguments']['requestee_id']['id'] = 'requestee_id';
  $handler->display->display_options['arguments']['requestee_id']['table'] = 'user_relationships';
  $handler->display->display_options['arguments']['requestee_id']['field'] = 'requestee_id';
  $handler->display->display_options['arguments']['requestee_id']['relationship'] = 'requestee_id';
  $handler->display->display_options['arguments']['requestee_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['requestee_id']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['requestee_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['requestee_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['requestee_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['requestee_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['requestee_id']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['requestee_id']['validate_options']['restrict_roles'] = 0;
  $handler->display->display_options['arguments']['requestee_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['requestee_id']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User relationships: Relationship type */
  $handler->display->display_options['filters']['rtype']['id'] = 'rtype';
  $handler->display->display_options['filters']['rtype']['table'] = 'user_relationships';
  $handler->display->display_options['filters']['rtype']['field'] = 'rtype';
  $handler->display->display_options['filters']['rtype']['value'] = array(
  		0 => '3',
  );
  $handler->display->display_options['path'] = 'user/%/relationships/tutor';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Tutors';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'Tutors';
  $handler->display->display_options['tab_options']['weight'] = '0';
  
  /* Display: Students */
  $handler = $view->new_display('page', 'Students', 'page_student');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Students';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User relationships: Requester user */
  $handler->display->display_options['relationships']['requester_id']['id'] = 'requester_id';
  $handler->display->display_options['relationships']['requester_id']['table'] = 'user_relationships';
  $handler->display->display_options['relationships']['requester_id']['field'] = 'requester_id';
  $handler->display->display_options['relationships']['requester_id']['required'] = 0;
  /* Relationship: User relationships: Requestee user */
  $handler->display->display_options['relationships']['requestee_id']['id'] = 'requestee_id';
  $handler->display->display_options['relationships']['requestee_id']['table'] = 'user_relationships';
  $handler->display->display_options['relationships']['requestee_id']['field'] = 'requestee_id';
  $handler->display->display_options['relationships']['requestee_id']['required'] = 0;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'requester_id';
  $handler->display->display_options['relationships']['profile']['required'] = 0;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
  		'user' => 'user',
  );
  /* Relationship: User relationships: Requestee user is current user */
  $handler->display->display_options['relationships']['requestee_id_current']['id'] = 'requestee_id_current';
  $handler->display->display_options['relationships']['requestee_id_current']['table'] = 'user_relationships';
  $handler->display->display_options['relationships']['requestee_id_current']['field'] = 'requestee_id_current';
  $handler->display->display_options['relationships']['requestee_id_current']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'requester_id';
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
  $handler->display->display_options['fields']['uid']['link_to_user'] = 0;
  /* Field: Profile: Profile Picture */
  $handler->display->display_options['fields']['field_profile_picture']['id'] = 'field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['table'] = 'field_data_field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['field'] = 'field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_picture']['label'] = 'Picture';
  $handler->display->display_options['fields']['field_profile_picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_profile_picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_picture']['settings'] = array(
  		'image_style' => 'profile_main',
  		'image_link' => '',
  );
  $handler->display->display_options['fields']['field_profile_picture']['field_api_classes'] = 0;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'requester_id';
  $handler->display->display_options['fields']['realname']['label'] = 'User';
  $handler->display->display_options['fields']['realname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['external'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['realname']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['realname']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['html'] = 0;
  $handler->display->display_options['fields']['realname']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['realname']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['realname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['realname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['realname']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['realname']['link_to_user'] = 1;
  /* Field: User relationships: Relationship type */
  $handler->display->display_options['fields']['rtype']['id'] = 'rtype';
  $handler->display->display_options['fields']['rtype']['table'] = 'user_relationships';
  $handler->display->display_options['fields']['rtype']['field'] = 'rtype';
  $handler->display->display_options['fields']['rtype']['label'] = 'Relationship';
  $handler->display->display_options['fields']['rtype']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['external'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['rtype']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['rtype']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['html'] = 0;
  $handler->display->display_options['fields']['rtype']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['rtype']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['rtype']['hide_empty'] = 0;
  $handler->display->display_options['fields']['rtype']['empty_zero'] = 0;
  $handler->display->display_options['fields']['rtype']['hide_alter_empty'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User relationships: Requestee user */
  $handler->display->display_options['arguments']['requestee_id']['id'] = 'requestee_id';
  $handler->display->display_options['arguments']['requestee_id']['table'] = 'user_relationships';
  $handler->display->display_options['arguments']['requestee_id']['field'] = 'requestee_id';
  $handler->display->display_options['arguments']['requestee_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['requestee_id']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['requestee_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['requestee_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['requestee_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['requestee_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['requestee_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['requestee_id']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User relationships: Relationship type */
  $handler->display->display_options['filters']['rtype']['id'] = 'rtype';
  $handler->display->display_options['filters']['rtype']['table'] = 'user_relationships';
  $handler->display->display_options['filters']['rtype']['field'] = 'rtype';
  $handler->display->display_options['filters']['rtype']['value'] = array(
  		0 => '5',
  );
  $handler->display->display_options['path'] = 'user/%/relationships/student';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Students';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  
  /* Display: All */
  $handler = $view->new_display('page', 'All', 'page_all');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Students';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User relationships: Requester user */
  $handler->display->display_options['relationships']['requester_id']['id'] = 'requester_id';
  $handler->display->display_options['relationships']['requester_id']['table'] = 'user_relationships';
  $handler->display->display_options['relationships']['requester_id']['field'] = 'requester_id';
  $handler->display->display_options['relationships']['requester_id']['required'] = 0;
  /* Relationship: User relationships: Requestee user */
  $handler->display->display_options['relationships']['requestee_id']['id'] = 'requestee_id';
  $handler->display->display_options['relationships']['requestee_id']['table'] = 'user_relationships';
  $handler->display->display_options['relationships']['requestee_id']['field'] = 'requestee_id';
  $handler->display->display_options['relationships']['requestee_id']['required'] = 0;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'requester_id';
  $handler->display->display_options['relationships']['profile']['required'] = 0;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
  		'user' => 'user',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'requester_id';
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
  $handler->display->display_options['fields']['uid']['link_to_user'] = 0;
  /* Field: Profile: Profile Picture */
  $handler->display->display_options['fields']['field_profile_picture']['id'] = 'field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['table'] = 'field_data_field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['field'] = 'field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_picture']['label'] = 'Picture';
  $handler->display->display_options['fields']['field_profile_picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_profile_picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_picture']['settings'] = array(
  		'image_style' => 'profile_main',
  		'image_link' => '',
  );
  $handler->display->display_options['fields']['field_profile_picture']['field_api_classes'] = 0;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'requester_id';
  $handler->display->display_options['fields']['realname']['label'] = 'User';
  $handler->display->display_options['fields']['realname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['external'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['realname']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['realname']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['html'] = 0;
  $handler->display->display_options['fields']['realname']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['realname']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['realname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['realname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['realname']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['realname']['link_to_user'] = 1;
  /* Field: User relationships: Relationship type */
  $handler->display->display_options['fields']['rtype']['id'] = 'rtype';
  $handler->display->display_options['fields']['rtype']['table'] = 'user_relationships';
  $handler->display->display_options['fields']['rtype']['field'] = 'rtype';
  $handler->display->display_options['fields']['rtype']['label'] = 'Relationship';
  $handler->display->display_options['fields']['rtype']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['external'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['rtype']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['rtype']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['rtype']['alter']['html'] = 0;
  $handler->display->display_options['fields']['rtype']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['rtype']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['rtype']['hide_empty'] = 0;
  $handler->display->display_options['fields']['rtype']['empty_zero'] = 0;
  $handler->display->display_options['fields']['rtype']['hide_alter_empty'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User relationships: Requestee user */
  $handler->display->display_options['arguments']['requestee_id']['id'] = 'requestee_id';
  $handler->display->display_options['arguments']['requestee_id']['table'] = 'user_relationships';
  $handler->display->display_options['arguments']['requestee_id']['field'] = 'requestee_id';
  $handler->display->display_options['arguments']['requestee_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['requestee_id']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['requestee_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['requestee_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['requestee_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['requestee_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['requestee_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['requestee_id']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'user/%/relationships/all';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'All Connections';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['user_connections'] = array(
  		t('Master'),
  		t('My %2'),
  		t('more'),
  		t('Apply'),
  		t('Reset'),
  		t('Sort by'),
  		t('Asc'),
  		t('Desc'),
  		t('Items per page'),
  		t('- All -'),
  		t('Offset'),
  		t('No Connection yet.'),
  		t('requestee'),
  		t('requester'),
  		t('User'),
  		t('All'),
  		t('Tutors'),
  		t('My Tutors'),
  		t('Profile'),
  		t('Picture'),
  		t('user/[uid]'),
  		t('Relationship'),
  		t('Students'),
  		t('My Students'),
  );

  $views['user_connections'] = $view;

  return $views;
}
