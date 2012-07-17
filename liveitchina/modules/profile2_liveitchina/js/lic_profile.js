(function ($) {
  Drupal.behaviors.lic_profile = {
    attach: function(context) {
      $('#region-content h1#page-title', context).append('<a class="back" href="#"> << ' + Drupal.t('Back to Search Results') + '</a>');
      $('a.back').click(function(){
          parent.history.back();
          return false;
      });
    }
  };
})(jQuery);