<?php
/**
 * Menu callback; my promotions
 */
function liveitchina_my_promotions() {
  global $user, $language;
  //$profile = profile2_load_by_user($user);
  return profile2_user_view($user, 'full', $language->language);
}
