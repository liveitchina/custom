<?php
// $Id$

/**
 * @file
 * Default theme implementation for PCP block
 *
 * Available variables:
 *  $uid: Current user ID.
 *  $pcp_percentage: Profile Complete Bar.
 *  $liveitchina_menu: Menu for LiveitChina Users.
 *  $liveitchina_menu_rendered: Rendered Menu items
 *  $profile_role_bundle: array containing the role as key and profile2 bundle name as value.
 *  $user_role: User role.
 *  $profile_data: Profile2 data object.
 *  $user_full_name: User Full Name;
 *  $user_location: Location of user;
 *
 * @see template_preprocess_pcp_profile_percent_complete()
 */
?>
<div class="user-profile-info clearfix">
  <div class="profile-info-image">
   <?php print $user_picture; ?>
  </div>
  <div class="profile-info-pcp-bar">
    <h2><?php print $user_full_name; ?></h2>
    <h3><?php print $user_location; ?></h3>
    <?php print $pcp_percentage;?>
  </div>
</div>
<div class="user-profile-links clearfix">
  <?php print $liveitchina_menu_rendered;?>
</div>