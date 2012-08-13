<?php
/**
 * Implementation of hook_apachesolr_modify_query().
 */
function profile2_liveitchina_apachesolr_query_alter($query) {
  global $language;

  //Show only if status is true
  $query->addFilter('bs_status', TRUE);
  
  if (isset($_GET['loc'])){
    $location = rawurldecode($_GET['loc']);
    $distance = 10;//the distance to search

    if ($coordinates = _liveitchina_get_map($location)){
      //print_r($coordinates);exit;
      $coordinate = $coordinates['lat'].','.$coordinates['lon'];
      $query->addParam('fq', "{!geofilt sfield=coordinates pt=$coordinate d=$distance}");
    }
  }

  switch (arg(1)){
    case 'tutor':
      $query->addParam('fl', 'user_avatar');
      $query->addParam('fl', 'fs_rating');
      $query->addParam('fl', 'im_field_city');
      $query->addParam('fl', 'sm_vid_language');
      $query->addParam('fl', 'ts_summary');
      $query->addParam('fl', 'sm_lang_offered');
      $query->addParam('fl', 'tutor_price');
      $query->addFilter('user_role', 6);
      $query->addParam('fl', 'ts_teaches');
      break;
    case 'exchange-partner':
      $query->addParam('fl', 'user_avatar');
      $query->addParam('fl', 'fs_rating');
      $query->addParam('fl', 'im_field_city');
      $query->addParam('fl', 'sm_vid_language');
      $query->addParam('fl', 'ts_summary');
      $query->addParam('fl', 'sm_lang_offered');
      $query->addParam('fl', 'sm_lang_wanted');
      $query->addFilter('bundle', 'exchange_partner');
      $query->addParam('fl', 'ts_learning');
      $query->addParam('fl', 'ts_teaches');
      $query->addFilter('user_role', 4);
      break;
  }
}

/**
 * Implements hook_apachesolr_index_document_build_ENTITY_TYPE().
 *
 * Adds book module support
 */
function profile2_liveitchina_apachesolr_index_document_build_profile2(ApacheSolrDocument $document, $profile2, $env_id) {
//make sure to index only those that have user profile.
  if (!in_array($profile2->type, array('exchange_partner', 'tutor')) ) {
    return;
  }

  $user_data = user_load($profile2->uid);
  $user = profile2_load_by_user($profile2->uid, 'user');
  if (count($user) == 0){
    return;
  }

  //add custom display
  if ($profile2->type == 'exchange_partner'){
    $teaches = _profile2_liveitchina_teaches($profile2);
    $document->addField('ts_teaches', $teaches);
    $learning = _profile2_liveitchina_learning( $profile2);
    $document->addField('ts_learning', $learning);
  }
  else {
    $teaches = _profile2_liveitchina_teaches($profile2);
    $document->addField('ts_teaches', $teaches);
  }
  

  //replace label with realname
  $document->label = $user_data->realname;
  //hide from search by default
  $document->bs_status = FALSE;

  $document->addField('user_realname', $user_data->realname);

  //*/index user_rating
  if (isset($profile2->field_rating['und'][0]['average'])){
    //$document->addField('rating', $profile2->field_rating['und'][0]['average']);
    $document->addField('fs_rating', $profile2->field_rating['und'][0]['average']);
  }//*/
  //index user_avatar
  if (isset($user_data->picture->fid)){
   $document->addField('user_avatar', $user_data->picture->fid);
  }
  else{
  
  }
  
  //index TERMIDs from user
  $fields = array(
    'field_city'=> array(
      'source'=>'tid'
    ),
    'field_area'=> array(
      'source'=>'tid'
    ),
    'field_district'=> array(
      'source'=>'tid'
    ),
    'field_user_nationality'=> array(
      'source'=>'tid'
    ),
    'field_user_occupation'=> array(
      'source'=>'tid'
    ),
    'field_interest'=> array(
      'source'=>'tid'
    ),
    'field_user_education'=> array(
      'source'=>'tid'
    ),
    'field_language_wanted'=> array(
      'source'=>'tid'
    ),
    'field_user_address'=> array(
      'source'=>'country'
    ),
    'field_user_first_name' => array(
      'source'=>'value',
      'field'=>'user_first_name'
    ),
    'field_user_chinese_name' => array(
      'source'=>'value',
      'field'=>'user_chinese_name'
    ),
    'field_user_middle_name' => array(
      'source'=>'value',
      'field'=>'user_middle_name'
    ),
    'field_user_last_name' => array(
      'source'=>'value',
      'field'=>'user_last_name'
    ),
    'field_description' => array(
      'source'=>'value',
      'field'=>'user_desc'
    ),
    'field_summary' => array(
      'source'=>'value',
      'field'=>'user_elevator_speech'
    ),
    'field_user_philosophy' => array(
      'source'=>'value',
      'field'=>'user_philosophy'
    ),
    'field_user_commitment' => array(
      'source'=>'value',
      'field'=>'user_commitment'
    ),
    'field_user_activity' => array(
      'source'=>'value',
      'field'=>'user_activity'
    ),
    'field_user_phone' => array(
      'source'=>'value',
      'field'=>'user_phone'
    ),
    'field_user_website' => array(
      'source'=>'value',
      'field'=>'user_website',
    ),
    'field_location' => array(
      'source'=>'lat',
      'field'=>'coordinates',
    ),
  );

  foreach ($fields as $field=>$field_info){
    if ($field_values = field_get_items('profile2', $user, $field)){
      foreach ($field_values as $value) {
        switch ($field_info['source']){
          case 'tid':
            $document->addField('im_'.$field, $value['tid']);
            break;
          case 'country':
            $document->addField('user_address', $value['country']);
            break;
          case 'value':
            $document->addField($field_info['field'], apachesolr_clean_text($value['value']));
            break;
          case 'lat':
            $document->addField($field_info['field'], $value['lat'] . ','. $value['lng']);
            break;
        }
      }
    }
  }

  //index user_role or additional fields base on profile type
  $profile_fields = array(
    'tutor'=> array(
      array(
        'source'=>'field_summary',
        'field' => 'ts_summary',
        'index' => 'value',
      ),
      array(
        'source'=>'field_description',
        'field'=>'ts_description',
        'index'=>'value',
      ),
      array(
        'source'=>'field_lang_offered',
        'field'=> 'sm_lang_offered',
        'index'=> 'name',
      ),
      array(
        'source'=>'field_lang_offered',
        'field'=> 'filter_language',
        'index'=> 'tid',
      ),
      array(
        'source'=>'field_user_tutor_price',
        'field'=> 'tutor_price',
        'index'=> 'value',
      ),
      /*'SM_FIELD_USER_TUTOR_AVAILABILITY',
       'IM_FIELD_USER_TUTOR_LANG_OFFERED',
  'SM_FIELD_USER_TUTOR_PRICE',
  'SM_FIELD_USER_TUTOR_MEETING_LOC',
  'IM_FIELD_USER_TUTOR_INTEREST',
  'SM_FIELD_USER_TUTOR_EXP_YEAR',*/
    ),
    'exchange_partner'=> array(
      array(
        'source'=>'field_summary',
        'field'=>'ts_summary',
        'index'=>'value',
      ),
      array(
        'source'=>'field_description',
        'field' => 'ts_description',
        'index' => 'value',
      ),
      array(
        'source'=>'field_lang_offered',
        'field'=>'filter_language',
        'index'=>'tid',
      ),
      array(
        'source'=>'field_language_wanted',
        'field'=>'filter_language',
        'index'=>'tid',
      ),
      array(
        'source'=>'field_lang_offered',
        'field'=>'sm_lang_offered',
        'index'=>'name',
      ),
      array(
        'source'=>'field_language_wanted',
        'field'=>'sm_lang_wanted',
        'index'=>'name',
      ),
      /*'im_field_user_partner_lang_offer',
       'is_field_user_partner_offered_ye',
  'im_field_user_partner_lang_wante',
  'is_field_user_partner_wanted_yea',
  'sm_field_user_partner_availabili',
  'sm_field_user_partner_meeting_lo',
  */
    ),
  );
  $var_profileuser = variable_get('liveitchina_profile_role', array());
  $user_roles = array_keys($user_data->roles);
  $roles = array_intersect($var_profileuser, $user_roles);
  if (array_key_exists($profile2->type, $roles)){
   $document->addField('user_role', $var_profileuser[$profile2->type]);
   $document->bs_status = TRUE;
  
   //index extra fields not being indexed by apachesolr look for @$profile_fields
   $pfields = $profile_fields[$profile2->type];
   foreach ( $pfields as $pfield ){
    if ($field_values = field_get_items('profile2', $profile2, $pfield['source'])){
     foreach ($field_values as $value) {
      if ($pfield['index']=='value'){
       $document->addField($pfield['field'], apachesolr_clean_text($value[$pfield['index']]));
      }
      elseif ($pfield['index']=='name'){
        $term = taxonomy_term_load($value['tid']);
        $document->addField($pfield['field'], $term->name);
      }
      else {
        $document->addField($pfield['field'], $value[$pfield['index']]);
      }
     }
    }
   }
  }
  
  print_r($document);exit;
}