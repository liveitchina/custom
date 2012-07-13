<?php
/**
 * @file
 * liveitchina_display.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function liveitchina_display_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|default';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'share_this' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'user_complete_name' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_user_elevator_speech' => array(
      'ft' => array(
        'func' => 'theme_ds_field_reset',
      ),
    ),
  );
  $export['user|user|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function liveitchina_display_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|default';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_liveitchina_html5';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'right' => array(
        0 => 'user_complete_name',
        1 => 'field_user_review_rate',
        2 => 'field_user_location_district',
        3 => 'field_user_elevator_speech',
        4 => 'user_relationships_ui',
        5 => 'field_user_nicemessages_enabled',
      ),
      'header' => array(
        0 => 'share_this',
      ),
      'left' => array(
        0 => 'field_user_avatar',
      ),
    ),
    'fields' => array(
      'user_complete_name' => 'right',
      'share_this' => 'header',
      'field_user_avatar' => 'left',
      'field_user_review_rate' => 'right',
      'field_user_location_district' => 'right',
      'field_user_elevator_speech' => 'right',
      'user_relationships_ui' => 'right',
      'field_user_nicemessages_enabled' => 'right',
    ),
    'classes' => array(),
  );
  $export['user|user|default'] = $ds_layout;

  return $export;
}
