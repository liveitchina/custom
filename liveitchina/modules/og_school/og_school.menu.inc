<?php

/*
 * Implements hook_menu().
*/
function og_school_menu() {
  $items['school/promote/%'] = array(
    'title' => 'Promote Your School',
    'access callback' => TRUE,
    'page callback' => 'og_school_promote_profiles',
    'type' => MENU_NORMAL_ITEM,
    'page arguments' => array(1),
    'file' => 'og_school.pages.inc',
  );
  $items['school/%/connect'] = array(
    'type' => MENU_CALLBACK,
    'file' => 'og_school.pages.inc',
    'page callback' => 'og_school_connect',
    'page arguments' => array(1),
    'access callback' => 'user_is_logged_in',
    'title' => 'Connect',
  );
  $items['school/%node/book'] = array(
      'type' => MENU_CALLBACK,
      'file' => 'og_school.pages.inc',
      'page callback'      => 'drupal_get_form',
      'page arguments' => array('og_school_book_form', 1),//'apachesolr_settings', 1),
      'access callback' => 'user_is_logged_in',
      'title' => 'Book',
  );
  $items['school/%/unsubscribe'] = array(
    'type' => MENU_CALLBACK,
    'file' => 'og_school.pages.inc',
    'page callback' => 'og_school_unsubscribe',
    'page arguments' => array(1),
    'access callback' => 'og_user_access_by_entity',
    'access arguments' => array('unsubscribe', 'node', 1),
    'title' => 'Leave group',
  );
  return $items;
}

/**
 * Implements hook_menu_alter().
 */
function og_school_menu_alter(&$items) {
  $items['search/school']['type'] = MENU_NORMAL_ITEM;
  $items['search/school']['menu_name'] = 'main-menu';
  $items['search/school']['title'] = 'Find School';
  $items['search/school']['weight'] = -49;
  $items['search/school/%menu_tail']['type'] = MENU_NORMAL_ITEM;
  //drupal_set_message(print_r($items, true));
  $items['user/%user/connections/school']['type'] = MENU_LOCAL_TASK;
}