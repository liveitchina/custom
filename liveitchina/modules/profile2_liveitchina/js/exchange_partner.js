(function ($) {
  Drupal.behaviors.exchange = {
    attach: function(context) {
      //cantonese
      $(".form-item.form-type-checkbox.form-item-profile-exchange-partner-field-lang-offered-und-4").append($("#edit-profile-exchange-partner-field-off-cantonese-years"));
      if ($('#edit-profile-exchange-partner-field-lang-offered-und-4:checked').val() !== undefined){
        $("#edit-profile-exchange-partner-field-off-cantonese-years").css('display','block');
      }else{
        $("#edit-profile-exchange-partner-field-off-cantonese-years").css('display','none');
      }
      jQuery("#edit-profile-exchange-partner-field-lang-offered-und-4").click(function() {
        if ($('#edit-profile-exchange-partner-field-lang-offered-und-4:checked').val() !== undefined){
          $("#edit-profile-exchange-partner-field-off-cantonese-years").css('display','block');
        }else{
          $("#edit-profile-exchange-partner-field-off-cantonese-years").css('display','none');
        }
      });
      //english
      $(".form-item.form-type-checkbox.form-item-profile-exchange-partner-field-lang-offered-und-5").append($("#edit-profile-exchange-partner-field-off-english-years"));
      if ($('#edit-profile-exchange-partner-field-lang-offered-und-5:checked').val() !== undefined){
        $("#edit-profile-exchange-partner-field-off-english-years").css('display','block');
      }else{
        $("#edit-profile-exchange-partner-field-off-english-years").css('display','none');
      }
      jQuery("#edit-profile-exchange-partner-field-lang-offered-und-5").click(function() {
        if ($('#edit-profile-exchange-partner-field-lang-offered-und-5:checked').val() !== undefined){
          $("#edit-profile-exchange-partner-field-off-english-years").css('display','block');
        }else{
          $("#edit-profile-exchange-partner-field-off-english-years").css('display','none');
        }
      });
      //mandarin
      $(".form-item.form-type-checkbox.form-item-profile-exchange-partner-field-lang-offered-und-20").append($("#edit-profile-exchange-partner-field-off-mandarin-years"));
      if ($('#edit-profile-exchange-partner-field-lang-offered-und-20:checked').val() !== undefined){
        $("#edit-profile-exchange-partner-field-off-mandarin-years").css('display','block');
      }else{
        $("#edit-profile-exchange-partner-field-off-mandarin-years").css('display','none');
      }
      jQuery("#edit-profile-exchange-partner-field-lang-offered-und-20").click(function() {
        if ($('#edit-profile-exchange-partner-field-lang-offered-und-20:checked').val() !== undefined){
          $("#edit-profile-exchange-partner-field-off-mandarin-years").css('display','block');
        }else{
          $("#edit-profile-exchange-partner-field-off-mandarin-years").css('display','none');
        }
      });
      //others
      $(".form-item.form-type-checkbox.form-item-profile-exchange-partner-field-lang-offered-und-21").append($("#edit-profile-exchange-partner-field-off-exch-other"));
      $(".form-item.form-type-checkbox.form-item-profile-exchange-partner-field-lang-offered-und-21").append($("#edit-profile-exchange-partner-field-off-others-years"));
      if ($('#edit-profile-exchange-partner-field-lang-offered-und-21:checked').val() !== undefined){
        $("#edit-profile-exchange-partner-field-off-others-years").css('display','block');
        $("#edit-profile-exchange-partner-field-off-exch-other").css('display','block');
      }else{
        $("#edit-profile-exchange-partner-field-off-others-years").css('display','none');
        $("#edit-profile-exchange-partner-field-off-exch-other").css('display','none');
      }
      jQuery("#edit-profile-exchange-partner-field-lang-offered-und-21").click(function() {
        if ($('#edit-profile-exchange-partner-field-lang-offered-und-21:checked').val() !== undefined){
          $("#edit-profile-exchange-partner-field-off-others-years").css('display','block');
          $("#edit-profile-exchange-partner-field-off-exch-other").css('display','block');
        }else{
          $("#edit-profile-exchange-partner-field-off-others-years").css('display','none');
          $("#edit-profile-exchange-partner-field-off-exch-other").css('display','none');
        }        
      });
      ///*
      //WANTED
      $(".form-item.form-type-checkbox.form-item-profile-exchange-partner-field-language-wanted-und-4").append($("#edit-profile-exchange-partner-field-wan-cantonese-years"));
      if ($('#edit-profile-exchange-partner-field-language-wanted-und-4:checked').val() !== undefined){
        $("#edit-profile-exchange-partner-field-wan-cantonese-years").css('display','block');
      }else{
        $("#edit-profile-exchange-partner-field-wan-cantonese-years").css('display','none');
      }
      jQuery("#edit-profile-exchange-partner-field-language-wanted-und-4").click(function() {
        if ($('#edit-profile-exchange-partner-field-language-wanted-und-4:checked').val() !== undefined){
          $("#edit-profile-exchange-partner-field-wan-cantonese-years").css('display','block');
        }else{
          $("#edit-profile-exchange-partner-field-wan-cantonese-years").css('display','none');
        }
      });
      //english
      $(".form-item.form-type-checkbox.form-item-profile-exchange-partner-field-language-wanted-und-5").append($("#edit-profile-exchange-partner-field-wan-english-years"));
      if ($('#edit-profile-exchange-partner-field-language-wanted-und-5:checked').val() !== undefined){
        $("#edit-profile-exchange-partner-field-wan-english-years").css('display','block');
      }else{
        $("#edit-profile-exchange-partner-field-wan-english-years").css('display','none');
      }
      jQuery("#edit-profile-exchange-partner-field-language-wanted-und-5").click(function() {
        if ($('#edit-profile-exchange-partner-field-language-wanted-und-5:checked').val() !== undefined){
          $("#edit-profile-exchange-partner-field-wan-english-years").css('display','block');
        }else{
          $("#edit-profile-exchange-partner-field-wan-english-years").css('display','none');
        }
      });
      //mandarin
      $(".form-item.form-type-checkbox.form-item-profile-exchange-partner-field-language-wanted-und-20").append($("#edit-profile-exchange-partner-field-wan-mandarin-years"));
      if ($('#edit-profile-exchange-partner-field-language-wanted-und-20:checked').val() !== undefined){
        $("#edit-profile-exchange-partner-field-wan-mandarin-years").css('display','block');
      }else{
        $("#edit-profile-exchange-partner-field-wan-mandarin-years").css('display','none');
      }
      jQuery("#edit-profile-exchange-partner-field-language-wanted-und-20").click(function() {
        if ($('#edit-profile-exchange-partner-field-language-wanted-und-20:checked').val() !== undefined){
          $("#edit-profile-exchange-partner-field-wan-mandarin-years").css('display','block');
        }else{
          $("#edit-profile-exchange-partner-field-wan-mandarin-years").css('display','none');
        }
      });
      //others
      $(".form-item.form-type-checkbox.form-item-profile-exchange-partner-field-language-wanted-und-21").append($("#edit-profile-exchange-partner-field-wan-exch-other"));
      $(".form-item.form-type-checkbox.form-item-profile-exchange-partner-field-language-wanted-und-21").append($("#edit-profile-exchange-partner-field-wan-others-years"));
      if ($('#edit-profile-exchange-partner-field-language-wanted-und-21:checked').val() !== undefined){ 
        $("#edit-profile-exchange-partner-field-wan-others-years").css('display','block');
        $("#edit-profile-exchange-partner-field-wan-exch-other").css('display','block');
      }else{
        $("#edit-profile-exchange-partner-field-wan-others-years").css('display','none');
        $("#edit-profile-exchange-partner-field-wan-exch-other").css('display','none');
      }
      jQuery("#edit-profile-exchange-partner-field-language-wanted-und-21").click(function() {
        if ($('#edit-profile-exchange-partner-field-language-wanted-und-21:checked').val() !== undefined){
          $("#edit-profile-exchange-partner-field-wan-others-years").css('display','block');
          $("#edit-profile-exchange-partner-field-wan-exch-other").css('display','block');
        }else{
          $("#edit-profile-exchange-partner-field-wan-others-years").css('display','none');
          $("#edit-profile-exchange-partner-field-wan-exch-other").css('display','none');
        }
      });
      //*/
    }
  };
})(jQuery);