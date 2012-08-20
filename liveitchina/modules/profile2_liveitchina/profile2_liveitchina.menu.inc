<?php

/*
 * Implements hook_menu().
*/
function profile2_liveitchina_menu() {
  $items['promotes'] = array(
    'file' => 'profile2_liveitchina.pages.inc',
    'title' => 'Promote Yourself',
    'page callback' => 'user_liveitchina_promote_page',
    'access callback' => TRUE,
    'type' => MENU_NORMAL_ITEM,
    'page arguments' => array(1),
  );
  $promotions = array('exchange_partner', 'tutor');
  foreach ($promotions as $promo){
    $items['promote/'.$promo] = array(
      'file' => 'profile2_liveitchina.pages.inc',
      'title' => 'Promote profile',
      'title callback' => 'user_liveitchina_title',
      'title arguments' => array(1),
      'access callback' => TRUE,
      'page callback' => 'profile2_liveitchina_promote_profiles',
      'type' => MENU_NORMAL_ITEM,
      'page arguments' => array(1),
    );
  }
  return $items;
}

/**
 * Implements hook_menu_alter().
 */
function profile2_liveitchina_menu_alter(&$items) {
  $menu_to_item = array(
    'search/tutor'=> array(
      'weight' => -48,
      'title' => 'Find Tutor',
      'menu_name' => 'main-menu',
      'type' => MENU_NORMAL_ITEM,
    ),
    'search/tutor/%menu_tail'=> array(
      'type' => MENU_NORMAL_ITEM,
    ),
    'search/exchange-partner'=> array(
      'weight' => -47,
      'menu_name' => 'main-menu',
      'title'=> 'Find Exchange Partner',
      'type' => MENU_NORMAL_ITEM,
    ),
    'search/exchange-partner/%menu_tail' => array(
      'type' => MENU_NORMAL_ITEM,
    ),
    'profile-tutor/%profile2_by_uid/edit' => array(
      'type' => MENU_NORMAL_ITEM,
    ),
    'profile-exchange_partner/%profile2_by_uid/edit' => array(
      'type' => MENU_NORMAL_ITEM,
    ),
  );

  //drupal_set_message(print_r($items, true));
  //$items += $menu_to_item;
  foreach ($menu_to_item as $item=>$attrib){
    foreach ($attrib as $i=>$v){
      $items[$item][$i] = $v;
    }
  }

}