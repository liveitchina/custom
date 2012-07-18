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
  //default sort order by score
  $sort = array('score', 'desc');

  //reset the available sort
  $query->removeAvailableSort('ds_created');
  $query->removeAvailableSort('sort_name');
  $query->removeAvailableSort('bundle');
  $query->removeAvailableSort('sort_label');
  
  $sorts['sort_label'] = array(
    'title'=> 'Name',
    'default'=> 'asc',
  );
  $sorts['ds_created'] = array(
    'title'=> 'Most recent',
    'default'=> 'desc',
  );
  $sorts['fs_rating'] = array(
    'title'=> 'Ratings',
    'default'=> 'desc',
  );
  
  foreach ($sorts as $sortKey=>$sortDetail){
    $query->setAvailableSort($sortKey, array(
      'title' => t($sortDetail['title']),
      'default' => $sortDetail['default'],
      )
    );
  }
  //Most relevant
  
  switch (arg(1)){
    case 'tutor':
      $query->setAvailableSort('tutor_price', array(
        'title' => t('Most affordable'),
        'default' => 'desc',
        )
      );
      $sort = array('tutor_price', 'desc');
      break;
    case 'exchange_partner':
      $sort = array('fs_rating', 'desc');
      break;
    case 'site':
      $sort = array('fs_rating', 'desc');
      break;
    case 'school':
      $query->setAvailableSort('sm_field_school_price', array(
        'title' => t('Most affordable'),
        'default' => 'desc',
        )
      );
      $sort = array('fs_rating', 'desc');
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
  }

  $query->setSolrsort($sort[0],$sort[1]);
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