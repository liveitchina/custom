<?php
/**
 * @file
 * liveit_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function liveit_features_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function liveit_features_views_api() {
  return array("version" => "3.0");
}
