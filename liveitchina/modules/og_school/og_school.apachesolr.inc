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
      if ($logos = field_get_items('node', $node, 'field_logo')){
        $school_logo = array_pop($logos);
        $document->addField('is_logo', $school_logo['fid']);
      }
      else {
        $avatar = field_info_field('field_user_avatar');
        $school_logo = file_load($avatar['settings']['default_image']);
        $document->addField('is_logo', $school_logo->fid);
      }

      if ($school_names = field_get_items('node', $node, 'field_school_name')){
        $school_name = array_pop($school_names);
        $document->label = $school_name['value'];
      }

      if ($summary = field_get_items('node', $node, 'field_summary')){
        $summary = array_pop($summary);
        $document->addField('ts_summary', $summary['value']);
      }

      if ($school_rating= field_get_items('node', $node, 'field_rating')){
        $rating = array_pop($school_rating);
        $document->addField('fs_rating', $rating['average']);
      }

      if ($school_language = field_get_items('node', $node, 'field_lang_offered')){
        foreach ($school_language as $language){
          $document->addField('filter_language', $language['tid']);
        }
      }
      if ($school_language = field_get_items('node', $node, 'field_lang_others')){
        foreach ($school_language as $language){
        //$document->addField('filter_language', $language['tid']);
          $document->addField('im_field_lang_others', $language['tid']);
        }
      }

      if ($area_terms = field_get_items('node', $node, 'field_area')){
        foreach ($area_terms as $area_term) {
          $document->addField('filter_area', $area_term['tid']);
        }
      }
      /*
      ob_start();
      $element = node_view($node, 'search_result');
      print drupal_render($element);
      $output = ob_get_contents();
      ob_end_clean();
      $document->addField('ts_view_mode', $output);
      */
      break;
  }
}