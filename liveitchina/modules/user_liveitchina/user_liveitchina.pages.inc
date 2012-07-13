<?php
function user_liveitchina_promote($user_promote){
  global $user;
  $roles_to_promote = variable_get('liveitchina_profile_role', array());
  if (isset($_GET['role'])) {
    $role = trim(strtolower($_GET['role']));
  }
  else {
    drupal_set_message(t('Role to promote was not specified.'));
    drupal_goto();
  }

  if ($user->uid == $user_promote || user_access('edit own ' . $role . ' profile')) {
    if (isset($roles_to_promote[$role])){
      $myroles = $user_promote->roles;
      $rid = $roles_to_promote[$role];
      $rolenames = user_roles(TRUE);
      if (!array_key_exists($rid, $myroles)){
        $myroles[$rid] = $rolenames[$rid];
        user_save($user_promote, array('roles' => $myroles));
        drupal_set_message($user_promote->realname . ' ' . t('has been promoted as'). ' ' . $rolenames[$rid]);
      }
      else {
        drupal_set_message(t('User is currently promoted as'). ' ' . $rolenames[$rid]);
      }
    }
    else {
      drupal_set_message(t('Invalid role specified.'));
    }
  }
  else {
    drupal_set_message(t('You are not authorized to promote this profile.'));
  }
  drupal_goto();
}

function user_liveitchina_demote($user_promote){
  global $user;
  $roles_to_promote = variable_get('liveitchina_profile_role', array());
  if (isset($_GET['role'])) {
    $role = trim(strtolower($_GET['role']));
  }
  else {
    drupal_set_message(t('Role to demote was not specified.'));
    drupal_goto();
  }
  if ($user->uid == $user_promote || user_access('edit own ' . $role . ' profile')) {
    $role = trim(strtolower($_GET['role']));
    $myroles = $user_promote->roles;
    if (isset($roles_to_promote[$role])){
      $rid = $roles_to_promote[$role];
      $rolenames = user_roles(TRUE);
      if (array_key_exists($rid, $myroles)){
        unset($myroles[$rid]);
        user_save($user_promote, array('roles' => $myroles));
        drupal_set_message($user_promote->realname . ' ' . t('has been remove from'). ' ' . $rolenames[$rid]);
      }
      else {
        drupal_set_message(t('Unable to remove profile as'). ' ' . $rolenames[$rid]);
      }
    }
    else {
      drupal_set_message(t('Invalid role specified.'));
    }
  }
  else {
    drupal_set_message(t('You are not authorized to promote this profile.'));
  }
  drupal_goto();
}

function user_liveitchina_promote_page($user){
  return t('Benefits of Promoting Yourself');
}

/**
 * Theme function; display the profile user page /user/X.
 *
 * @param $items
 *   An array of table rows.
 *
 * @ingroup themeable
 */
function theme_liveitchina_profile_user($vars) {
  $display = $vars['display'];
  $output = '';

  $output .= '
  <div id="liveitchina-profile" class="profile-user">'.
    render($display['image']).
    render($display['first_name']).
  '</div>';
  return $output;
}

function user_liveitchina_preprocess_liveitchina_profile_user(&$vars){
  $user_profile = $vars['profile'];
  $vars['title'] = t('User Information');
  $vars['display']['image'] = field_view_field('profile2', $user_profile, 'field_profile_picture', 'display');
  $vars['display']['first_name'] = field_view_field('profile2', $user_profile, 'field_user_first_name', 'display');
  $vars['display']['middle_name'] = field_view_field('profile2', $user_profile, 'field_user_middle_name', 'display');
  $vars['display']['last_name'] = field_view_field('profile2', $user_profile, 'field_user_last_name', 'display');
}

function user_liveitchina_my_reviews($user_promote){
  return 'This is my review page';
}
/**
 * Main list of relationships for a specified user
 * /
function user_liveitchina_page($account = NULL, $rtid = NULL) {
  global $user;
  if (!$account || !is_object($account) || !$account->uid) {
   $account = $user;
  }
  
  // Check if this is a valid rtid.
  if (!empty($rtid) && !user_relationships_type_load($rtid)) {
   return MENU_NOT_FOUND;
  }
  
  $args = array('user' => $account->uid, 'approved' => TRUE);
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
    : t("My relationships");
  }
  else {
   $msg = isset($relationship_type)
   ? t("%username's %relationships", array('%username' => format_username($account), '%relationships' => $relationship_type->plural_name ? ur_tt("user_relationships:rtid:" . $relationship_type->rtid . ":plural_name", $relationship_type->plural_name) : ur_tt("user_relationships:rtid:" . $relationship_type->rtid . ":name", $relationship_type->name)))
   : t("%username's relationships", array('%username' => format_username($account)));
  }
  drupal_set_title($msg, PASS_THROUGH);
  
  $header = user_relationships_ui_get_table_header(user_relationships_ui_check_access('delete', $account, $relationship_type));
  
  $rows = array();
  foreach ($relationships as $relationship) {
    $rows[$relationship->rid] = user_liveitchina_ui_get_table_row($relationship, $account);
    if (count($rows[$relationship->rid]) < count($header)) {
      // Add an empty space to the operations table row.
      $rows[$relationship->rid][] = '&nbsp;';
    }
  }
  
  if (!empty($rtid)) {
   $empty = t('You do not have any %plural_name.', array('%plural_name' => ur_tt("user_relationships:rtid:$relationship_type->rtid:plural_name", $relationship_type->plural_name)));
  }
  else {
   $empty = t('You do not have any relationships with other users.');
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

function user_liveitchina_ui_get_table_row($relationship, $account) {
  global $user;

  $this_user_str  = $account->uid == $relationship->requestee_id ? 'requester' : 'requestee';
  $this_user      = $relationship->{$this_user_str};

  $row = array(
    theme('username', array('account' => $this_user)),
    ur_tt("user_relationships:rtid:$relationship->rtid:name", $relationship->name)
    . ($relationship->is_oneway ? ($this_user_str == 'requestee' ? t(' (You to Them)') : t(' (Them to You)')) : NULL),
  );

  $permission = $account->uid == $relationship->requestee_id ? 'request' : 'approve';
  $links = array();
  if ($relationship->approved) {
    if (user_relationships_ui_check_access('delete', $account, $relationship)) {
      $links[] = theme('user_relationships_remove_link', array('uid' => $account->uid, 'rid' => $relationship->rid));
    }
  }
  else if (user_relationships_ui_check_access($permission, $account, $relationship)) {
    if ($this_user_str == 'requestee') {
      // Sent requests, display cancel link.
      $links[] = theme('user_relationships_pending_request_cancel_link', array('uid' => $account->uid, 'rid' => $relationship->rid));
    }
    else {
      // Received requests, display approve and decline links.
      $links[] = theme('user_relationships_pending_request_approve_link', array('uid' => $account->uid, 'rid' => $relationship->rid));
      $links[] = theme('user_relationships_pending_request_disapprove_link', array('uid' => $account->uid, 'rid' => $relationship->rid));
    }
  }
  if (!empty($links)) {
    $row[] = implode(' ', $links);
  }

  if (variable_get('user_relationships_show_user_pictures', 0)) {
    array_unshift($row, theme('user_picture', array('account' => $this_user)));
  }

  drupal_alter('user_relationships_ui_table_row', $row, $relationship, $account);

  return $row;
}
//*/