<?php
/**
 * Implements hook_ds_fields_info().
 */
function user_liveitchina_ds_fields_info($entity_type) {
  $fields = array();
  $fields['user']['user_profile_name'] = array(
    'title' => t('User Full Name'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_user_liveitchina_ds_field_user_profile_name',
  );
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
  $fields['user']['profile_ratings'] = array(
        'title' => t('Ratings'),
        'field_type' => DS_FIELD_TYPE_FUNCTION,
        'function' => '_user_liveitchina_ds_ratings',
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
  $fields['user']['tutor_rating'] = array(
            'title' => 'Tutor - Rating ',
            'field_type' => DS_FIELD_TYPE_FUNCTION,
            'function' => '_user_liveitchina_rating_tutor',
  );
  $fields['user']['exchange_partner_rating'] = array(
              'title' => 'Exchange Partner - Rating ',
              'field_type' => DS_FIELD_TYPE_FUNCTION,
              'function' => '_user_liveitchina_rating_exchange_partner',
  );
  $fields['user']['profile_learning'] = array(
        'title' => t('Profile - Learning'),
        'field_type' => DS_FIELD_TYPE_FUNCTION,
        'function' => '_user_liveitchina_ds_profile_learning',
  );
  return $fields;
}