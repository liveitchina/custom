<?php

/**
 * Implementation of hook_apachesolr_modify_query().
 */
function og_school_apachesolr_query_alter($query) {
  switch (arg(1)){
    case 'school':
      $query->addFilter('bundle', 'school');
    case 'site':
      $query->addParam('fl', 'im_field_lang_offered');
      $query->addParam('fl', 'im_field_lang_others');
      $query->addParam('fl', 'is_logo');
      $query->addParam('fl', 'fs_rating');
      $query->addParam('fl', 'ts_summary');
      $query->addParam('fl', 'sm_field_price');
      $query->addParam('fl', 'im_field_city');
      $query->addParam('fl', 'im_field_district');
      $query->addParam('fl', 'zs_teaches');
      $query->addParam('fl', 'zs_image');
      $query->addParam('fl', 'sm_lang_offered');
      $query->addParam('fl', 'sm_lang_others');
      $query->addParam('fl', 'ss_discount');
    break;
  }
}

/**
 * Implements hook_apachesolr_index_document_build_node().
 */
function og_school_apachesolr_index_document_build_node(ApacheSolrDocument $document, $node, $env_id) {
  //index language offered
  //print_r($node);exit;
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
    case 'school':
      $idxfields = array();
      $neighbors = array('locality', 'sublocality');
      //*
  
      $idxfields = array(
        'field_school_name' => array(
           'source' => 'label',
           'field' => 'label',
        ),//*
        'field_summary' => array(
          'source' => 'value',
          'field' => 'ts_summary',
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
        'field_rating'=> array(
          'source' => 'average',
          'field' => 'fs_rating',
        ),
        'field_location'=> array(
          'source' => 'lat',
          'field' => 'coordinates',
        ),
        'field_map_api'=> array(
          'source'=>'map',
          'field'=>'zs_mapresult',
        ),
        'field_discount' => array(
          'source'=>'value',
          'field'=>'ss_discount',
        ),
        'field_lang_offered' => array(
          'field'=>'sm_lang_offered',
          'source'=>'name',
        ),
        'field_lang_others' => array(
          'field'=>'sm_lang_others',
          'source'=>'name',
        ),
      );//*/
      foreach ($idxfields as $field=>$fieldInfo){
        if ($items = field_get_items('node', $node, $field)){
          foreach ($items as $item){
            switch ($fieldInfo['source']){
              case 'lat':
                $latlon = $item['lat'] . ','. $item['lng'];
                $document->addField($fieldInfo['field'], $latlon );
                break;
              case 'map':
                $reverseGeocode = unserialize( $item['value'] );
                if (is_array($reverseGeocode)){
                  foreach ($reverseGeocode as $geoInd=>$geoValue) {
                    $document->addField("ts_mapapi_{$geoInd}", $geoValue );
                    $document->addField("ss_mapapi_{$geoInd}", $geoValue );
                    if (in_array($geoInd, $neighbors)){
                      $document->addField('sm_filter_neighborhood', $geoValue );
                    }
                  }
                }
                $document->addField($fieldInfo['field'], $item['value']);
                break;
              case 'label':
                $document->label = $item['value'];
                break;
              case 'name':
                $term = taxonomy_term_load($item['tid']);
                $document->addField($fieldInfo['field'], $term->name);
                //print_r($item);exit;
                break;
              default:
                $document->addField($fieldInfo['field'], $item[$fieldInfo['source']]);
            }
          }
        }
      }
  
      if ($logos = field_get_items('node', $node, 'field_logo')){
        $school_logo = $logos[0];
        $document->addField('zs_image', $school_logo['uri']);
        $document->addField('is_logo', $school_logo['fid']);
      }
      else {
        $avatar = field_info_field('field_user_avatar');
        $school_logo = file_load($avatar['settings']['default_image']);
        //$logo = $school_logo->fid;
        $document->addField('zs_image', $school_logo->uri);
        $document->addField('is_logo', $school_logo->fid);
      }
    break;
  }
}
/*
function profile2_liveitchina_node_update($node){
  if(node_apachesolr_indexable($node)){
    drupal_cron_run();
  }
}//*/