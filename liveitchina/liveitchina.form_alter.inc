<?php
function liveitchina_form_user_login_block_alter(&$form, &$form_state, $form_id) {
  $form['name']['#title'] = t('Email Address');
  unset($form['links']);
  $form['pass']['#suffix'] = '<span class="forgot-password">' . l(t('Forgot Password').'?','user/password') . '</span>';
  $form['actions']['submit']['#prefix'] = '<span class="signup suffix-1">' . l(t('Sign Up for Free'),'user/register') . '</span>';
}

function liveitchina_form_reply_add_form_alter(&$form, &$form_state, $form_id) {
  $form['metatags']['#access'] = FALSE;
  $form['field_rating']['#access'] = FALSE;
  array_unshift($form['#submit'], 'liveitchina_cast_review_vote_submit');
  $form['review_link'] = array(
    '#markup' => '<a id="write-review-link" class="element-invisible">'. t('Write Review').'</a>',
    '#weight'=> -1,
  );
}

function liveitchina_form_search_block_form_alter(&$form, &$form_state, $form_id) {
  unset($form['search_block_form']);
  $search_page = apachesolr_search_page_load('core_search');
  $apachesolr_has_searched = apachesolr_has_searched($search_page->env_id);
  $searcher = NULL;
  $default_search = DEFAULT_SEARCH_TERM;
  $default['location'] = 'all';
  $fq = NULL;
  if ($apachesolr_has_searched) {
    $query = apachesolr_current_query($search_page->env_id);
    $searcher = $query->getSearcher();
    // We use the presence of filter query params as a flag for the retain filters checkbox.
    $q = $query->getParam('q');
    $default_search = $q;
    $default_location = $query->getParam('fq');
    foreach($default_location as $loc){
      list($lic_filter, $lic_value) = explode(':', $loc);
      if ($lic_filter == 'im_field_city'){
        $opt_query = array ('f' => array('city:' . $lic_value));
        $default['location'] = serialize($opt_query);
      }
    }
  }
  
  $form['search_form_key'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'grid-8 omega'
      ),
    )
  );
  $form['search_form_key']['search_block_form'] = array(
    '#title' => t('Search').' <span>('.t('e.g. Mandarin School, Tutor, learn Cantonese').')</span>',
    '#title_display' => 'before',
    '#type' => 'textfield',
    '#size' => 40,
    '#default_value' => $default_search,
    '#attributes' => array(
      'title' => t('Enter the terms you wish to search for.'),
      'onblur' => "if (this.value == '') {this.value = '" . t(DEFAULT_SEARCH_TERM) . "';jQuery(this).css('color','#b9b9b9');}",
      'onfocus' => "if (this.value == '" . t(DEFAULT_SEARCH_TERM) . "') {this.value = '';}jQuery(this).css('color','#7b7a7a !important');",
    )
  );
  $form['search_form_location'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'grid-4 omega'
      ),
    )
  );
  $form['search_form_location']['location'] = array(
    '#title' => t('Choose your Location') ,
    '#title_display' => 'before',
    '#type' => 'select',
    '#multiple' => FALSE,
    '#options' => _liveitchina_location(),
    '#default_value' => $default['location'],
    '#attributes' => array(
      'title' => t('Choose your Location'),
    )
  );
  
  $form['actions']['city-add']['#markup'] = ' <span id ="city-add">' . 
                                            t('Add Your ') . 
                                            l(t('City'),'contact-us') . '?</span>';
  $form['actions']['city-add']['#weight'] = '-500';
  
  $form['actions']['#attributes'] = array(
    'class' => array(
      'grid-2 omega'
    ),
    'id' => array(
      'edit-actions1'
    )
  );
  //print_r($form);
  $form['actions']['submit']['#markup'] = 'testing alng';
  $form['actions']['submit']['#value'] = t('Go');
  $form['#submit'] = array('liveitchina_search_box_form_submit');
}

/*
 * Implements hook_form_ID_alter();
* User Register Form
*/
function liveitchina_form_user_register_form_alter(&$form, &$form_state, $form_id) {
  $form['#prefix'] = '<div class="register-preface">'. t('Lorem ipsum dolor sit amet.').'</div>';
  if (isset($form['account']['pass'])){
    $form['account']['pass']['#prefix'] ='<div style="float:right; right:0;"><span class="form-required">*</span>' . t('Mandatory') . '</div><h2 class="register-password">'. t('Password') . '</h2>';
  }
  $form['account']['first_name'] = array(
    '#prefix'=>'<div style="float:right; right:0;"><span class="form-required">*</span>' . t('Mandatory') . '</div><h2 class="register-login-info">'. t('Log In Information') . '</h2>',
    '#type' => 'textfield',
    '#title' => t('First Name'),
    '#maxlength' => 60,
    '#description' => '',
    '#required' => 1,
    '#default_value' => '',
    '#access' => 1,
    '#weight' => -30,
  );
  $form['account']['last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Last Name'),
    '#maxlength' => 60,
    '#description' => '',
    '#required' => 1,
    '#default_value' => '',
    '#access' => 1,
    '#weight' => -29,
  );
  $form['actions']['submit']['#prefix'] = '<input class="form-submit webform-cancel" type="button" value="Cancel" onClick="history.go(-1)"/>';
  $form['actions']['submit']['#value'] = t('Submit');
  $form['#pre_render'][] = 'liveitchina_user_register_form_alter_weight';
}

/*
 * Alter the weight of register form;
*/
function liveitchina_user_register_form_alter_weight($elements) {
  $elements['account']['#weight'] = -30;
  $elements['picture']['#weight'] = -20;
  $elements['actions']['#weight'] = -10;
  return $elements;
}

/**
 * hook_form_alter() to catch the approval form
 */
function liveitchina_form_liveitchina_user_relationships_ui_request_alter(&$form, $form_state, $form_id) {
  // In case the form is an error form which the UI module has encountered
  if (!isset($form['error']) && !variable_get('user_relationships_elaborations_api_only', FALSE)) {
    // Make sure that the select box holding the relationship types is above the elaboration textarea.
    $form['rtid']['#weight'] = -10;
    // Adding text area to elaborate when creating a new relationship with another user.
    $form['elaboration'] = array(
        '#type' => 'textarea',
        '#title' => t('Comments'),
        '#rows' => 3,
        '#cols' => 50,
        '#description' => t('Add more details about your relationship. Both parties will be able to view these comments.'),
        '#weight' => 5,
    );
    $form['#submit'][] = 'user_relationship_elaborations_request_submit';
  }
}

function liveitchina_form_webform_client_form_27_alter(&$form, &$form_state, $form_id) {
  $form['actions']['submit']['#prefix'] = '<input class="form-submit webform-cancel" type="button" value="Cancel" onClick="history.go(-1)"/>';
}

function liveitchina_form_user_profile_form_alter(&$form, &$form_state, $form_id){
  $form['picture']['#access'] = false;
}

function liveitchina_form_profile2_edit_user_form_alter(&$form, &$form_state, $form_id) {
  $form['#submit'][] = '_liveitchina_add_picture_to_user';
}

/**
 * hook_form_alter() to catch the approval form
 * /
function liveitchina_form_alter(&$form, $form_state, $form_id) {
  switch ($form_id) {
    case 'user_relationships_ui_pending_requested':
      if (!variable_get('user_relationships_elaborations_api_only', FALSE)) {
        $form['elaboration'] = array(
            '#type'           => 'textarea',
            '#title'          => t('Comments'),
            '#default_value'  => isset($form_state['values']['elaboration']) ? $form_state['values']['elaboration'] : user_relationships_get_elaboration($form['rid']['#value']),
            '#description'    => t('Add more details about your relationship. Both parties will be able to view these comments.')
        );
        $form['#submit'][] = 'user_relationship_elaborations_submit';
      }
      break;
    
    case 'user_relationships_admin_settings':
      $form['user_relationships_elaborations'] = array(
      '#type'   => 'fieldset',
      '#title'  => t('Elaborations'),
      '#weight' => 0,
      '#group' => 'settings',
      );
      $form['user_relationships_elaborations']['user_relationships_elaborations_api_only'] = array(
          '#type'           => 'checkbox',
          '#title'          => t('Do not use the elaborations UI'),
          '#description'    => t('Check this if you only need the API provided by the UR-Elaborations module'),
          '#default_value'  => variable_get('user_relationships_elaborations_api_only', FALSE),
      );
      break;
  }
}//*/