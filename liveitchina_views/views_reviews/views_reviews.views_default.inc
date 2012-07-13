<?php

/**
 * Implements hook_views_default_views().
 */
function views_reviews_views_default_views() {

  $view = new view;
  $view->name = 'reviews';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'reply';
  $view->human_name = 'Reviews';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Reviews';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No Reviews yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Reply: Reply ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'reply';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Sort criterion: Reply: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'reply';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Reply: Entity_id */
  $handler->display->display_options['arguments']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['table'] = 'reply';
  $handler->display->display_options['arguments']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['entity_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['entity_id']['default_argument_options']['code'] = 'if ($profile_id = arg(1)){
  if (is_numeric($profile_id)){
  $profile_type=arg(0);
  $profile_type = str_replace(\'profile-\',\'\', $profile_type);
  $profile = profile2_load_by_user($profile_id, $profile_type);
  //$entity = entity_load($profile->entity_type, array($profile->pid));
  //drupal_set_message(print_r($entity, true));
  return (isset($profile->pid))?$profile->pid:0;
  }
  }
  return 0;';
  $handler->display->display_options['arguments']['entity_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['entity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['entity_id']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['entity_id']['validate']['type'] = 'numeric';
  $handler->display->display_options['arguments']['entity_id']['validate']['fail'] = 'empty';
  $handler->display->display_options['arguments']['entity_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['entity_id']['not'] = 0;
  
  /* Display: Profile2 Reviews - Block */
  $handler = $view->new_display('block', 'Profile2 Reviews - Block', 'profile');
  $handler->display->display_options['display_description'] = 'Reviews by profile';
  $translatables['reviews'] = array(
    t('Master'),
    t('Reviews'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No Reviews yet.'),
    t('Reply ID'),
    t('.'),
    t(','),
    t('All'),
    t('Profile2 Reviews - Block'),
    t('Reviews by profile'),
  );
  

  $views['reviews'] = $view;

  return $views;
}
