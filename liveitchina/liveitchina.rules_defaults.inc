<?php 

/**
 * @file
 * Defines default rules.
 *
 */

/**
 * Implements hook_default_rules_configuration().
 */
function liveitchina_default_rules_configuration() {

  $configs = array();
  foreach (_liveitchina_rules_default_rules_configuration() as $key => $default) {
    $configs[$key] = rules_import($default);
  }

  return $configs;

}

/**
 * Helper function to define exports from rules.
 * The defaults will be imported with rules_import command.
 */
function _liveitchina_rules_default_rules_configuration() {

  $configs = array();

  $configs['rules_send_email_to_admin_on_registration'] = '{ "rules_send_email_to_admin_on_registration" : {
    "LABEL" : "Send email to admin on registration",
    "PLUGIN" : "reaction rule",
    "TAGS" : [ "email", "registration" ],
    "REQUIRES" : [ "rules" ],
    "ON" : [ "user_insert" ],
    "DO" : [
      { "mail" : {
          "to" : "[site:mail]",
          "subject" : "LiveitChina Registration",
          "message" : "A new user has been created: [account:mail]",
          "from" : "no-reply@liveitchina.com"
        }
      }
    ]
  }
}';

  return $configs;

}