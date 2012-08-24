<?php

/**
 * Implements hook_views_default_views().
 */
function views_term_map_views_default_views() {

  $view = new view;
  $view->name = 'term_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Term Map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Term Map';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['name']['convert_spaces'] = 0;
  /* Field: Taxonomy term: Map */
  $handler->display->display_options['fields']['field_map']['id'] = 'field_map';
  $handler->display->display_options['fields']['field_map']['table'] = 'field_data_field_map';
  $handler->display->display_options['fields']['field_map']['field'] = 'field_map';
  $handler->display->display_options['fields']['field_map']['label'] = '';
  $handler->display->display_options['fields']['field_map']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_map']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_map']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_map']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_map']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_map']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_map']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_map']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_map']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_map']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_map']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_map']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_map']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_map']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_map']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_map']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_map']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_map']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_map']['type'] = 'geofield_openlayers';
  $handler->display->display_options['fields']['field_map']['settings'] = array(
    'map_preset' => 'liveitchina_geofield_widget_map',
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_map']['field_api_classes'] = 0;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['code'] = '
  $field_values = array();
  $district =  array_shift($field_values);
  //drupal_set_message(print_r($district, true));
  return $district[\'tid\'];';
  $handler->display->display_options['arguments']['tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['not'] = 0;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'city' => 'city',
  );
  
  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_district');
  $translatables['term_map'] = array(
    t('Master'),
    t('Term Map'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Block'),
  );
  

  $views['term_map'] = $view;

  return $views;
}
