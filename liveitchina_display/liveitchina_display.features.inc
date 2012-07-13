<?php
/**
 * @file
 * liveitchina_display.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function liveitchina_display_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}
