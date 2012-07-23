<?php

function profile2_liveitchina_promote_profiles($type){
  global $user;

  switch ($type) {
    case 'exchange_partner':
    case 'tutor':
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
        //$user_promote_form['top_header']['body']['#markup'] = t('Lorem ipsum dolor sit amet');
        return $user_promote_form;
      }
      else {
        //return drupal_get_form('user_login');
      	return drupal_get_form('user_register_form');
      }
    break;
  }
  return;
}