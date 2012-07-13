(function($) {
  Drupal.behaviors.og_school = {
    attach: function(context, settings) {
      $("#edit-field-lang-others", context).css('display','none');
      $("#edit-field-lang-offered-und-21", context).click(function() {
    	if ($('#edit-field-lang-offered-und-21:checked', context).val() !== undefined){
    		$("#edit-field-lang-others", context).css('display','block');
        }else{
        	$("#edit-field-lang-others", context).css('display','none');
        }
      });
    }
  };
})(jQuery);