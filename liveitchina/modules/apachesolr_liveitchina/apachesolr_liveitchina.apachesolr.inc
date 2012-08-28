<?php
/**
 * Implementation of hook_apachesolr_query_alter().
 */
function apachesolr_liveitchina_apachesolr_query_alter($query) {
  global $language;
  //Show only if status is true
  $query->addFilter('bs_status', TRUE);

  if (isset($_GET['loc']) && !empty($_GET['loc'])){
    $location = rawurldecode($_GET['loc']);

    $query->addFilter('ts_mapapi_formatted_address', $location);

    if ($dist = $query->getFilters('distance')){
      $query->removeFilter('distance');
      if ($coordinates = _liveitchina_get_map($location)){
        $coordinate = $coordinates['lat'].','.$coordinates['lon'];
        $distance = str_replace(array('(',')'),'', $dist[0]['#value']);
        $query->addParam('fq', "{!geofilt sfield=coordinates pt=$coordinate d=$distance}");
        /*
        $query->addParam('fq','{!geofilt}' );
   $query->addParam('sfield','coordinates' );
   $query->addParam('pt', '21.346617,-82.098747');
   $query->addParam('d', 5);
   $query->addParam('sort', 'geodist() asc');
         */
      }
    }
  }

  $query->addParam('fl', 'bundle');
  $query->addParam('fl', 'user_role');
  switch (arg(1)){
    case 'site':
      $paramFields = array(
        'tutor_price',
        'sm_lang_wanted',
        'user_avatar',
        'ts_learning',
        'sm_vid_language',
        'ts_view_mode',
      );
      foreach ($paramFields as $paramField){
        $query->addParam('fl', $paramField);
      }

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
      $sort = array('fs_rating', 'desc');
      break;
    case 'exchange-partner':
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
    case 'news-and-happenings':
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