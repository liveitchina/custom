<?php

/**
 * @file
 * Display suite fields.
 */

/**
 * Implements hook_ds_fields_info().
 */
function liveitchina_ds_fields_info($entity_type) {
  $fields = array();
  $fields['node']['submitted_by'] = array(
    'title' => 'Submitted by',
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_liveitchina_ds_submitted_by',
  );
  $fields['node']['page_title'] = array(
    'title' => 'Page Title',
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_liveitchina_ds_page_title',
  );
  $fields['node']['liveitchina_sharethis'] = array(
    'title' => 'LiveitChina ShareThis',
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_liveitchina_ds_sharethis',
  );
  $fields['reply']['reviewer_author'] = array(
    'title' => 'Reviewer Name',
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_liveitchina_ds_reviewer_author',
  );
  $fields['reply']['reviewer_details'] = array(
    'title' => 'Reviewer Name',
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => '_og_school_ds_reviewer_details',
  );
  return $fields;
}

/**
 * Implements hook_ds_layout_info().
 */
function liveitchina_ds_layout_info() {
  $path = drupal_get_path('module', 'liveitchina');
  $layouts['display_school'] = array(
    'label' => t('School Display Layout'),
    'path' => $path . '/ds_layouts/display_school',
    'regions' => array(
      'header' => t('Header'),
      'left' => t('Left'),
      'right' => t('Right'),
      'main' => t('Content'),
      'footer' => t('Footer'),
    ),
  );
  $layouts['liveitchina_teaser'] = array(
    'path' => $path . '/ds_layouts/liveitchina_teaser',
    'label' => t('LiveitChina Teaser Template'),
    'regions' => array(
      'header' => t('Header'),
      'left' => t('Left'),
      'right' => t('Right'),
    ),
  );
  $layouts['ds_liveitchina_html5'] = array(
    'path' => $path . '/ds_layouts/ds_liveitchina_html5',
    'label' => t('LiveitChina User Template'),
    'regions' => array(
      'header' => t('Header'),
      'left' => t('Left'),
      'right' => t('Right'),
      'footer' => t('Footer'),
      'display' => t('Display'),
    ),
    'css' => TRUE,
  );
  $layouts['form_liveitchina_html5'] = array(
    'path' => $path . '/ds_layouts/form_liveitchina_html5',
    'label' => t('LiveitChina User Template'),
    'regions' => array(
      'header' => t('Header'),
      'left' => t('Left'),
      'right' => t('Right'),
      'footer' => t('Footer'),
      'display' => t('Display'),
    ),
    // Add this line if there is a default css file.
    'css' => TRUE,
    'form' => TRUE,
  );
  $layouts['form_school'] = array(
    'label' => t('School Form Layout'),
    'path' => $path . '/ds_layouts/form_school',
    'regions' => array(
      'header' => t('Header'),
      'left' => t('Left'),
      'right' => t('Right'),
      'main' => t('Content'),
      'footer' => t('Footer')
    ),
    'form' => TRUE,
  );
  return $layouts;
}