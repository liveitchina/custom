<?php

/**
 * Implementation of hook_apachesolr_modify_query().
 */
function og_school_apachesolr_query_alter($query) {
  switch (arg(1)){
    case 'school':
      $query->addFilter('bundle', 'school');
      //$query->addParam('fl', 'ts_view_mode');
      $query->addParam('fl', 'im_field_lang_offered');
      $query->addParam('fl', 'is_logo');
      $query->addParam('fl', 'fs_rating');
      $query->addParam('fl', 'ts_summary');
      $query->addParam('fl', 'sm_field_price');
      $query->addParam('fl', 'im_field_city');
      $query->addParam('fl', 'im_field_district');
      $query->addParam('fl', 'ts_teaches');
    break;
  }
}

/**
 * Implements hook_apachesolr_index_document_build_node().
 */
function og_school_apachesolr_index_document_build_node(ApacheSolrDocument $document, $node, $env_id) {
  //index language offered
  switch ($node->type){
    case 'school':
      $document->bs_status = $node->status;
      $teaches = og_school_teaches($node);
      $document->addField('ts_teaches', $teaches);
      /*
      if ($logos = field_get_items('node', $node, 'field_logo', LANGUAGE_NONE)){
        $school_logo = array_pop($logos);
        $logo = $school_logo['fid'];
      }
      else {
        $avatar = field_info_field('field_user_avatar');
        $school_logo = file_load($avatar['settings']['default_image']);
        $logo = $school_logo->fid;
      }
      $document->addField('is_logo', $logo);
      //*/
      if ($school_rating= field_get_items('node', $node, 'field_rating')){
        $rating = array_pop($school_rating);
        $document->addField('fs_rating', $rating['average']);
      }

      $idxfields = array(
        'field_summary' => array(
           'source' => 'value',
           'field' => 'ts_summary',
        ),
        'field_school_name' => array(
           'source' => 'label',
           'field' => 'label',
        ),
        'field_location'=> array(
           'source' => 'lat',
           'field' => 'coordinates',
        ),
        'field_lang_offered'=> array(
           'source' => 'tid',
           'field' => 'filter_language',
        ),
        'field_lang_others'=> array(
          'source' => 'tid',
          'field' => 'im_field_lang_others',
        ),
        'field_area'=> array(
          'source' => 'tid',
          'field' => 'filter_area',
        ),
      		'field_map_api'=> array(
      				'source'=>'value',
      				'field'=>'zs_mapresult',
      		)
      );
      foreach ($idxfields as $field=>$fieldInfo){
        if ($items = field_get_items('node', $node, $field)){
          foreach ($items as $item){
            switch ($fieldInfo['source']){
              case 'lat':
              	 //print_r($item);exit;
                $latlon = $item['lat'] . ','. $item['lng'];
                $reverseGeocode = liveitchina_reverse_geocode( $latlon );
                if (is_array($reverseGeocode)){
                  foreach ($reverseGeocode as $geoInd=>$geoValue) {
                    $document->addField("ts_mapapi_{$geoInd}", $geoValue );
                    $document->addField("ss_mapapi_{$geoInd}", $geoValue );
                    $neighbors = array('locality', 'sublocality');
                    if (in_array($geoInd, $neighbors)){
                      $document->addField('sm_filter_neighborhood', $geoValue );
                    }
                  }
                }
                $document->addField($fieldInfo['field'], $latlon );
                break;
              case 'tid':
                $document->addField($fieldInfo['field'], $item['tid']);
              break;
              case 'value':
                $document->addField($fieldInfo['field'], $item['value']);
              break;
              case 'label':
                $document->label = $item['value'];
              break;
            }
          }
        }
      }
    break;
  }
  //print_r($node); exit;
  //print_r($document); exit;
}
/*
function profile2_liveitchina_node_update($node){
  if(node_apachesolr_indexable($node)){
    drupal_cron_run();
  }
}//*/