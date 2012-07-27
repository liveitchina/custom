<?php
//module_load_include('inc', 'user_relationships', 'user_relationships_ui.pages.inc');

/**
 * @file
 * Custom Relationships for LiveitChina
 */

/**
 * Main list of relationships for a specified user
 */
function user_relationships_liveitchina_page($account = NULL, $rtid = NULL) {
  global $user;
  if (!$account || !is_object($account) || !$account->uid) {
    $account = $user;
  }

  // Check if this is a valid rtid.
  if (!empty($rtid) && !user_relationships_type_load($rtid)) {
   return MENU_NOT_FOUND;
  }

  $args = array('requester_id' => $account->uid, 'approved' => TRUE);
  $relationship_type = NULL;
  if (!empty($rtid)) {
   $relationship_type = user_relationships_type_load($rtid);
   $args['rtid'] = $rtid;
  }
  else {
   // Get hidden relationships.
   $hidden = db_query('SELECT rtid FROM {user_relationships_ui_settings} WHERE hide = 1')->fetchCol();
   if (!empty($hidden)) {
    $args['exclude_rtids'] = $hidden;
   }
  }

  $options = array(
    'include_user_info' => TRUE,
    'paging' => variable_get('user_relationships_relationships_per_page', 16),
  );

  $relationships = user_relationships_load($args, $options);
  
  if ($account->uid == $user->uid) {
   $msg = isset($relationship_type)
   ? t("My %relationships", array('%relationships' => $relationship_type->plural_name ? ur_tt("user_relationships:rtid:" . $relationship_type->rtid . ":plural_name", $relationship_type->plural_name) : ur_tt("user_relationships:rtid:" . $relationship_type->rtid . ":name", $relationship_type->name)))
   : t("My connections");
  }
  else {
   $msg = isset($relationship_type)
   ? t("%username's %relationships", array('%username' => format_username($account), '%relationships' => $relationship_type->plural_name ? ur_tt("user_relationships:rtid:" . $relationship_type->rtid . ":plural_name", $relationship_type->plural_name) : ur_tt("user_relationships:rtid:" . $relationship_type->rtid . ":name", $relationship_type->name)))
   : t("%username's connections", array('%username' => format_username($account)));
  }
  drupal_set_title($msg, PASS_THROUGH);
  
  $header = user_relationships_ui_get_table_header(user_relationships_ui_check_access('delete', $account, $relationship_type));
  
  $rows = array();
  foreach ($relationships as $relationship) {
   $rows[$relationship->rid] = user_relationships_ui_get_table_row($relationship, $account);
   if (count($rows[$relationship->rid]) < count($header)) {
    // Add an empty space to the operations table row.
    $rows[$relationship->rid][] = '&nbsp;';
   }
  }
  
  if (!empty($rtid)) {
   $empty = t('You do not have any %plural_name.', array('%plural_name' => ur_tt("user_relationships:rtid:$relationship_type->rtid:plural_name", $relationship_type->plural_name)));
  }
  else {
   $empty = t('You do not have any connections with other users.');
  }
  
  $output = array(
    'list' => array(
      '#theme' => 'table',
      '#rows' => $rows,
      '#header' => $header,
      '#empty' => $empty,
      '#attributes' => array('class' => array('user-relationships-listing-table')),
    ),
    // Theme pager so that it uses the correct pager query.
    'pager' => array(
      '#markup' => theme('pager'),
    )
  );
  
  return $output;
}