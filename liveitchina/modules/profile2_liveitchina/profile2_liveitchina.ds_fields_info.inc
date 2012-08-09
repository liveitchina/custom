<?php
/**
 * Implements hook_ds_fields_info().
 */
function profile2_liveitchina_ds_fields_info($entity_type) {
  $fields = array();

  $fields['profile2']['user_actions'] = array(
    'title' => t('Connect Action'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_profile2_liveitchina_ds_user_actions',
  );
  $fields['profile2']['user_match'] = array(
    'title' => t('User Match'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_profile2_liveitchina_ds_user_match',
  );
  $fields['profile2']['user_links'] = array(
    'title' => t('User Links'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_profile2_liveitchina_ds_user_links',
  );
  $fields['profile2']['user_photo'] = array(
    'title' => t('Photo'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_profile2_liveitchina_ds_field_user_photo',
  );
  $fields['profile2']['user_edit_profile'] = array(
    'title' => t('Edit Links'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_profile2_liveitchina_ds_field_user_edit_profile',
  );
  $fields['profile2']['user_profile_header'] = array(
    'title' => t('Profile Header'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_profile2_liveitchina_ds_field_user_profile_header',
  );
  $fields['profile2']['user_profile_name'] = array(
    'title' => t('User Full Name'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_profile2_liveitchina_ds_field_user_profile_name',
  );
  $fields['profile2']['additional_information'] = array(
    'title' => t('Additional Information'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_profile2_liveitchina_ds_field_additional_information',
  );
  $fields['profile2']['profile_rating'] = array(
    'title' => t('Profile Rating'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_profile2_liveitchina_ds_profile_rating',
  );
  $fields['profile2']['profile_teaches'] = array(
    'title' => t('Profile - Teaches'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_profile2_liveitchina_ds_profile_teaches',
  );
  $fields['profile2']['profile_learning'] = array(
      'title' => t('Profile - Learning'),
      'field_type' => DS_FIELD_TYPE_FUNCTION,
      'function' => '_profile2_liveitchina_ds_profile_learning',
  );
  $fields['profile2']['profile_cost'] = array(
    'title' => t('Tutor - Cost'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_profile2_liveitchina_ds_profile_cost',
  );
  $fields['profile2']['profile_review_form']= array(
    'title' => t('Review Form'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_profile2_liveitchina_ds_reviews',
  );
  $fields['profile2']['liveitchina_sharethis'] = array(
    'title' => 'LiveitChina ShareThis',
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_liveitchina_ds_sharethis',
  );
  return $fields;
}