<?php
/**
 * Implementation of hook_apachesolr_query_alter().
 */
function apachesolr_liveitchina_apachesolr_query_alter($query) {
  global $language;
  //Filter by language
  //$query->addFilter('ss_language', $language->language);
  
  //Show only if status is true
  $query->addFilter('bs_status', TRUE);
  
  //Parameters
  $query->addParam('fl', 'bundle');
  $query->addParam('fl', 'user_role');
  switch (arg(1)){
    case 'site':
      $paramFields = array(
      'sm_lang_offered',
      'tutor_price',
      'sm_lang_offered',
      'sm_lang_wanted',
      'user_avatar',
      'fs_rating',
      'ts_teaches',
      'fs_rating',
      'ts_learning',
      'im_field_district',
      'sm_vid_language',
      'ts_view_mode',
      'im_field_lang_offered',
      'is_logo',
      'ts_summary',
      'sm_field_price',
      'im_field_city',
      );
      foreach ($paramFields as $paramField){
        $query->addParam('fl', $paramField);
      }
      //$query->addParam('qf','bundle_name^4000');
      //$query->addParam('qf','ts_teaches^10');
      //$query->addParam('qf','ts_learning^10');

      break;
    case 'news-and-happenings':
      $query->addParam('fl', 'ts_view_mode');
      $query->addFilter('ss_bundle', 'news');
      break;
  }
}

/**
 * Implementation of hook_apachesolr_query_prepare().
 */

function apachesolr_liveitchina_apachesolr_query_prepare($query) {
  $query->removeAvailableSort('ds_created');
  $query->removeAvailableSort('sort_name');
  $query->removeAvailableSort('bundle');
  $query->removeAvailableSort('sort_label');
  
  $query->setAvailableSort('sort_label', array(
    'title' => t('Name'),
    'default' => 'asc',
  ));
  $query->setAvailableSort('ds_created', array(
    'title' => t('Most recent'),
    'default' => 'desc',
  ));
  $query->setAvailableSort('fs_rating', array(
    'title' => t('Ratings'),
    'default' => 'desc',
  )
  );
  //Most relevant
  
  switch (arg(1)){
   case 'tutor':
    $query->setAvailableSort('tutor_price', array(
      'title' => t('Most affordable'),
      'default' => 'desc',
      )
    );
    break;
  }
  
  //sort for login Exchange Partner
  /*
   * Top Match
  * Most relevant
  * Most recent
  * Most affordable
  *
  */
  
  // There is an existing sort
  if (isset($_GET['solrsort'])) {
   $sort = explode(' ', $_GET['solrsort']);
   $query->setSolrsort($sort[0], $sort[1]);
  }
  else {
   $query->setSolrsort('score','dsc');
  }
}

/**
 * Implements hook_apachesolr_index_document_build_node().
 */
function apachesolr_liveitchina_apachesolr_index_document_build_node(ApacheSolrDocument $document, $node, $env_id) {
  //index language offered
  switch ($node->type){
   case 'article':
   case 'video':
   case 'person_of_the_week':
   case 'photo':
     ob_start();
     $element = node_view($node, 'custom_teaser');
     print drupal_render($element);
     $output = ob_get_contents();
     ob_end_clean();
     $document->addField('ts_view_mode', $output);
     $document->addField('ss_bundle', 'news');
     break;
  }
}