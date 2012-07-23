<?php

function og_school_promote_profiles($type){
  global $user;

  if ($user->uid) {
    $profile = profile2_load_by_user($user, $type);
    if (!$profile) {
      $profile = profile2_create(array('type' => $type));
      $profile->setUser($user);
      $profile->is_new = TRUE;
    }

    form_load_include($form_state, 'inc', 'profile2_page');
    $user_promote_form = entity_ui_get_form('profile2', $profile, 'edit', $form_state);
    $user_promote_form['top_header']['head']['#markup'] = t('Promoting Yourself as @profile', array('@profile'=> $profile->label ));
    return $user_promote_form;
  }
  else {
    //return drupal_get_form('user_login');
  	return drupal_get_form('user_register_form');
  }
}

function og_school_connect($etid) {
  global $user;
  $entity_type = 'node';
  if ($group = og_get_group($entity_type, $etid)) {
   if (empty($uid)) {
    $account = clone($user);
  
    if (!$account->uid) {
     $dest = drupal_get_destination();
     if (variable_get('user_register', 1)) {
      drupal_set_message(t('In order to join the school, you must <a href="!login">login</a>. After you have successfully done so, you will need to request membership again.', array('!login' => url("user/login", array('query' => $dest)))));
     }
     else {
      drupal_set_message(t('In order to join the school, you must <a href="!login">login</a> or <a href="!register">register</a> a new account. After you have successfully done so, you will need to request membership again.', array('!register' => url("user/register", array('query' => $dest)), '!login' => url("user/login", array('query' => $dest)))));
     }
     drupal_goto('user');
    }
   }
   else {
    $account = user_load($uid);
   }
  
   $entity = entity_load($entity_type, array($etid));
   $entity = reset($entity);

   $redirect = FALSE;
   $params = array(
     '@user' => format_username($account),
     // TODO: check user has permissions to see label (e.g. node title).
     '@group' => og_entity_label($entity_type, $entity),
   );
   if (og_is_member($group->gid, 'user', $account, array(OG_STATE_BLOCKED))) {
    // User is blocked, give them access denied.
    drupal_access_denied();
   }
   if (og_is_member($group->gid, 'user', $account, array(OG_STATE_PENDING))) {
    // User is pending, return them back.
    $message = $account->uid == $user->uid ? t('You already have a pending request for @group.', $params) : t('@user already has a pending membership for the  the group @group.', $params);
    $redirect = TRUE;
   }
  
   if (og_is_member($group->gid, 'user', $account, array(OG_STATE_ACTIVE))) {
    // User is already a member, return them back.
    $message = $account->uid == $user->uid ? t('You are already a connected to group @group.', $params) : t('@user is already a member of the group @group.', $params);
    $redirect = TRUE;
   }
  
   if (!empty($message)) {
    drupal_set_message($message);
   }
   if ($redirect) {
    _group_ui_redirect($entity_type, $entity);
   }

   if (og_user_access($group->gid, 'subscribe', $account) || 
       og_user_access($group->gid, 'subscribe without approval', $account)) {
    // Show the user a subscription confirmation.
    return drupal_get_form('og_school_confirm_connect', $group, $account);
   }
   drupal_access_denied();
  }
  // Not a valid group node.
  drupal_not_found();

}

function og_school_confirm_connect($form, &$form_state, $group, $account) {
  $form['group'] = array('#type' => 'value', '#value' => $group);
  $form['account'] = array('#type' => 'value', '#value' => $account);
  
  // Add group membership form.
  // TODO: We need to associate a group membership with group?
  $type = OG_MEMBERSHIP_TYPE_DEFAULT;
  $form['membership_type'] = array('#type' => 'value', '#value' => $type);
  $dummy_entity = og_membership_create(0, 'user', 0, array('type' => $type));
  $form['membership_fields'] = array(
    '#prefix' => '<div id="og-ui-membership-type">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
    '#parents' => array('membership_fields'),
  );
  field_attach_form('og_membership', $dummy_entity, $form['membership_fields'], $form_state);
  
  if (og_user_access($group->gid, 'subscribe without approval')) {
   // Hide the user request field.
   if (!empty($form['membership_fields'][OG_MEMBERSHIP_REQUEST_FIELD])) {
    $form['membership_fields'][OG_MEMBERSHIP_REQUEST_FIELD]['#access'] = FALSE;
   }
  }

  $label = og_label($group->gid);
  return confirm_form($form, t('Are you sure you want to connect to %title?', array('%title' => $label)), "$group->entity_type/$group->etid", ' ', t('Connect'), t('Cancel'));
}

function og_school_confirm_connect_validate($form, &$form_state) {
  // @see entity_form_field_validate().
  $dummy_entity = new stdClass();
  if (!empty($form_state['values']['membership_fields'])) {
    $dummy_entity = (object) $form_state['values']['membership_fields'];
  }
  $dummy_entity->type = $form_state['values']['membership_type'];

  field_attach_form_validate('og_membership', $dummy_entity, $form['membership_fields'], $form_state);
}

/**
 * Submit handler; Confirm OG membership.
 */
function og_school_confirm_connect_submit($form, &$form_state) {
 $group = $form_state['values']['group'];
 $account = $form_state['values']['account'];

 $state = og_user_access($group->gid, 'subscribe without approval') ? OG_STATE_ACTIVE : OG_STATE_PENDING;
 $values = array(
   'entity' => $account,
   'state' => $state,
   'membership type' => $form_state['values']['membership_type'],
   'membership fields' => $form_state['values']['membership_fields'],
 );
 og_group($group->gid, $values);

 // Redirect.
 $form_state['redirect'] = "node/$group->etid";
}

function og_school_unsubscribe($etid) {
  $entity_type = 'node';
  if ($group = og_get_group($entity_type, $etid)) {
    global $user;
    $label = og_label($group->gid);
    // Check the user isn't the manager of the group.
    $manager = $group->user();
    //drupal_set_message(print_r($group->user(), true));
    if ($group != $user->uid) {
      $account = clone $user;
      if (og_is_member($group->gid, 'user', $account, array(OG_STATE_ACTIVE, OG_STATE_PENDING))) {
        // Show the user a subscription confirmation.
        return drupal_get_form('og_school_confirm_unsubscribe', $group, $account);
      }
    }
    else {
      drupal_set_message(t('As a administrator of %group, you can not leave the school.', array('%group' => $label)));
    }
    $entity= $group->getEntity();
    _group_ui_redirect($group->entity_type, $entity);
  }
  // Not a valid group.
  drupal_not_found();
}

/**
 * Confirm unsubscribe form.
 */
function og_school_confirm_unsubscribe($form, &$form_state, $group, $account) {
  $form['group'] = array('#type' => 'value', '#value' => $group);
  $form['account'] = array('#type' => 'value', '#value' => $account);

  $label = og_label($group->gid);
  return confirm_form(
    $form,
    t('Are you sure you want to unsubscribe from the %title?', 
      array('%title' => $label)
    ),
    "node/$group->etid",
    ' ',
    t('Remove'),
    t('Cancel')
  );
}

/**
 * Submit handler; Confirm OG unsubscription.
 */
function og_school_confirm_unsubscribe_submit($form, &$form_state) {
  $group = $form_state['values']['group'];
  $account = $form_state['values']['account'];

  og_ungroup($group->gid, 'user', $account);

  // TODO: Determine where to go next - Group if accessible, or else site front
  // page.
  $form_state['redirect'] = "node/$group->etid";
}