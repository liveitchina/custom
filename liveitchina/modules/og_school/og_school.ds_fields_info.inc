<?php
/**
 * Implements hook_ds_fields_info().
 */
function og_school_ds_fields_info($entity_type) {
  $fields = array();
  $fields['node']['school_links'] = array(
    'title' => 'School Links',
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_og_school_ds_school_links',
  );
  $fields['node']['school_actions'] = array(
    'title' => t('School Action'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_og_school_ds_school_actions',
  );
  $fields['node']['school_information'] = array(
    'title' => 'School - Additional Information',
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_og_school_school_information',
  );
  $fields['node']['school_address'] = array(
    'title' => 'School - Address',
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_og_school_school_address',
  );
  $fields['node']['school_administrator'] = array(
    'title' => 'School - See Administrator',
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_og_school_school_administrator',
  );
  $fields['node']['school_title'] = array(
    'title' => 'School - Title',
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_og_school_school_title',
  );
  $fields['node']['school_teaches'] = array(
    'title' => 'School - Teaches',
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_og_school_teaches',
  );
  $fields['reply']['reviewer_author'] = array(
    'title' => 'Reviewer Name',
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_og_school_ds_reviewer_author',
  );
  $fields['node']['school_title_feat'] = array(
        'title' => 'School - Title Featured',
        'field_type' => DS_FIELD_TYPE_FUNCTION,
        'function' => '_og_school_school_title_feat',
  );
  return $fields;
}