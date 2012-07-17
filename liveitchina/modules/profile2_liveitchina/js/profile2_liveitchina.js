(function ($) {
  Drupal.behaviors.profile2_liveitchina = {
    attach: function(context) {
      $('#region-content h1#page-title', context).appendTo('<a class="back" href="#"> Back</a>');
      $('a.back').click(function(){
          parent.history.back();
          return false;
      });
    }
  };
})(jQuery);