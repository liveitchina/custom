<?php

/**
 * Implements hook_menu().
 */
function liveitchina_menu() {
  $items['user/my-promotions'] = array(
    'title' => 'My Promotions',
    'access callback' => 'user_is_logged_in',
    'page callback' => 'liveitchina_my_promotions',
    'weight' => 9,
    'menu_name' => 'user-menu',
    'file' => 'liveitchina.pages.inc',
  );
  $items['connect/%user/request/%/%ctools_js'] = array(
    'title' => 'Connect',
    'page callback' => 'liveitchina_user_relationships_ui_request_ajax',
    'page arguments' => array(1, 3),
    'access callback' => TRUE,//'user_relationships_ui_check_access',
    //'access arguments' => array('request'),
    'type' => MENU_CALLBACK,
  );
  $items['connect/%user/request'] = array(
    'title' => 'Create a relationship',
    'type' => MENU_CALLBACK,
    'access callback' => TRUE,//'user_relationships_ui_check_access',
    //'access arguments' => array('request'),
    'page callback' => 'liveitchina_user_relationships_ui_request_ajax',
    'page arguments' => array(1),
    'modal'=> TRUE,
  );
  $items['user/%user/connections/%user_relationships/remove'] = array(
    'title' => 'Remove relationship',
    'type' => MENU_CALLBACK,
    'access callback' => 'user_relationships_ui_check_access',
    'access arguments' => array('delete', 1),
    'page callback' => 'liveitchina_user_relationships_ui_remove_ajax',
    'page arguments' => array(1, 3),
  );
  $items['user/connectivity/%user/%'] = array(
    'title' => 'My Tutor / Exchange Partner',//'My Relationship',
    //'title callback' => 'liveitchina_relationship_name',
    //'title arguments' => array('user_relationships'),
    //'access arguments' => array('delete', 1),
    'type' => MENU_CALLBACK,
    'access callback' => 'user_is_logged_in',//TRUE,
    'page callback' => 'drupal_get_form',
    'page arguments' => array('liveitchina_user_connectivity_form', 2, 3),
  );
  //*
  $items['connect/%user/request/%/%ctools_js'] = array(
      'title' => 'Connect',
      'page callback' => 'liveitchina_user_relationships_ui_request_ajax',
      'page arguments' => array(1, 3),
      'access callback' => TRUE,//'user_relationships_ui_check_access',
  //'access arguments' => array('request'),
      'type' => MENU_CALLBACK,
  );
  /*
  //My Tutor or Exchange Partner
  $items['user/%user/connectivity/%user_relationships'] = array(
      'title' => 'My Tutor / Exchange Partner',
  //'title callback' => 'liveitchina_relationship_name',
  //'title arguments' => array('user_relationships'),
      'type' => MENU_CALLBACK,
      'access callback' => TRUE,
  //'access arguments' => array('delete', 1),
      //'file' => 'liveitchina.pages.inc',
      'page callback' => 'liveitchina_already_connected_form',
      'page arguments' => array(1, 3),
  );
  //*/
  /*/ Registration and login pages.
  $items['user/%user/bookmarks'] = array(
    'title' => 'User account',
    'title callback' => 'user_menu_title',
    'page callback' => 'liveitchina_user_bookmark',
    'page arguments' => array(1),
    'access callback' => TRUE,
    'file' => 'user.pages.inc',
    'file path' => drupal_get_path('module', 'user'),
    'weight' => -10,
    'menu_name' => 'menu-liveitchina',
  );//*/

  return $items;
}

function liveitchina_user_bookmark($user){
	
}
/**
 * Implements hook_menu_alter().
 */
function liveitchina_menu_alter(&$items) {
  $menu_to_item = array(
    'user/register',
    'user/%user',
    'user/%user/view',
    'user/%user/edit',
    'user/%user/relationships',
    'relationships/received',
    'relationships/sent',
    'search/news-and-happenings',
    'search/news-and-happenings/%menu_tail',
    'messages',
  );
  foreach ($menu_to_item as $item){
     $items[$item]['type'] = MENU_NORMAL_ITEM;
  }
  $items['user/register']['title'] = 'Register';
  $items['relationships']['title'] = 'My Connections';
  $items['user/%user/relationships/list']['title'] = 'All Connections';
  $items['messages']['title'] = 'Inbox';

  //$items['user/%user/bookmarks']['type'] = MENU_NORMAL_ITEM;
  //$items['user/%user/bookmarks']['title'] = 'This is it';
  //$items['user/%user/bookmarks']['menu_name'] = 'menu-liveitchina';

}