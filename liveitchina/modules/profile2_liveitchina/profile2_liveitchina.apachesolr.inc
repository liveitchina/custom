<?php
/**
 * Implementation of hook_apachesolr_modify_query().
 */
function profile2_liveitchina_apachesolr_query_alter($query) {
  global $language;

  switch (arg(1)){
    case 'tutor':
      $query->addFilter('user_role', 6);
      $query->addParam('fl', 'user_avatar');
      $query->addParam('fl', 'fs_rating');
      $query->addParam('fl', 'sm_vid_language');
      $query->addParam('fl', 'ts_summary');
      $query->addParam('fl', 'sm_lang_offered');
      $query->addParam('fl', 'tutor_price');
      $query->addParam('fl', 'zs_teaches');
      break;
    case 'exchange-partner':
      $query->addFilter('user_role', 4);
      $query->addParam('fl', 'user_avatar');
      $query->addParam('fl', 'fs_rating');
      $query->addParam('fl', 'sm_vid_language');
      $query->addParam('fl', 'ts_summary');
      $query->addParam('fl', 'sm_lang_offered');
      $query->addParam('fl', 'sm_lang_wanted');
      $query->addFilter('bundle', 'exchange_partner');
      $query->addParam('fl', 'ts_learning');
      $query->addParam('fl', 'zs_teaches');
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
    $document->addField('zs_teaches', $teaches);
    $learning = _profile2_liveitchina_learning( $profile2);
    $document->addField('ts_learning', $learning);
  }
  else {
    $teaches = _profile2_liveitchina_teaches($profile2);
    $document->addField('zs_teaches', $teaches);
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
    /*
    'field_user_address'=> array(
      'source'=>'country'
    ),
    */
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
    'field_map_api'=> array(
      'source'=>'map',
      'field'=>'zs_mapresult',
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
          case 'map':
            _apachesolr_liveitchina_index_map($value['value'], $document);
            break;
          case 'lat':
            $latlon = $value['lat'] . ','. $value['lng'];
            $document->addField($field_info['field'], $latlon );
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
  /*
  if ($profile2->uid == 119) {
    print_r($profile2);exit;
  }
  //*/
}