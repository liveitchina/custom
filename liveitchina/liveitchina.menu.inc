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
    'page callback' => 'modal_forms_connect',
    'page arguments' => array(1, 3),
    'access callback' => 'user_relationships_ui_check_access',
    'access arguments' => array('request'),
    'type' => MENU_CALLBACK,
  );
  $items['connect/%user/request'] = array(
    'title' => 'Create a relationship',
    'type' => MENU_CALLBACK,
    'access callback' => 'user_relationships_ui_check_access',
    'access arguments' => array('request'),
    'page callback' => 'modal_forms_connect',
    'page arguments' => array(1),
    'file' => 'user_relationships_ui.forms.inc',
    'file path' => drupal_get_path('module', 'user_relationships_ui'),
    'modal'=> TRUE,
  );

  return $items;
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

}