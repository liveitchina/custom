<?php
/**
 * Implements hook_ds_fields_info().
 */
function user_liveitchina_ds_fields_info($entity_type) {
  $fields = array();

  $fields['user']['user_display'] = array(
    'title' => t('User - Display'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_user_liveitchina_ds_display',
  );
  $fields['user']['user_actions'] = array(
    'title' => t('User - Actions'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_user_liveitchina_ds_actions',
  );
  ///*
  $fields['user']['profile_teaches_tutor'] = array(
        'title' => t('Profile - Teaches (tutor)'),
        'field_type' => DS_FIELD_TYPE_FUNCTION,
        'function' => '_user_liveitchina_ds_profile_teaches',
  );
  //*/
  $fields['user']['profile_cost_tutor'] = array(
        'title' => t('Tutor - Cost'),
        'field_type' => DS_FIELD_TYPE_FUNCTION,
        'function' => '_user_liveitchina_ds_profile_cost',
  );
  
  $fields['user']['profile_desc_tutor'] = array(
          'title' => t('Tutor - Description'),
          'field_type' => DS_FIELD_TYPE_FUNCTION,
          'function' => '_user_liveitchina_ds_profile_desc',
  );
  $fields['user']['user_title'] = array(
        'title' => 'Tutor - Name Title ',
        'field_type' => DS_FIELD_TYPE_FUNCTION,
        'function' => '_user_liveitchina_name_title',
  );
  $fields['user']['exchange_partner_title'] = array(
          'title' => 'Exchange Partner - Name Title ',
          'field_type' => DS_FIELD_TYPE_FUNCTION,
          'function' => '_user_liveitchina_name_title_exchange_partner',
  );
  return $fields;
}