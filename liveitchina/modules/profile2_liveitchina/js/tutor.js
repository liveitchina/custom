(function ($) {
  Drupal.behaviors.tutor = {
    attach: function(context) {
      //cantonese
      $(".form-item.form-type-checkbox.form-item-profile-tutor-field-lang-offered-und-4").append($("#edit-profile-tutor-field-cantonese-years"));
      if ($('#edit-profile-tutor-field-lang-offered-und-4:checked').val() !== undefined){
        $("#edit-profile-tutor-field-cantonese-years").css('display','block');
      }else{
        $("#edit-profile-tutor-field-cantonese-years").css('display','none');
      }
      jQuery("#edit-profile-tutor-field-lang-offered-und-4").click(function() {
        if ($('#edit-profile-tutor-field-lang-offered-und-4:checked').val() !== undefined){
          $("#edit-profile-tutor-field-cantonese-years").css('display','block');
        }else{
          $("#edit-profile-tutor-field-cantonese-years").css('display','none');
        }
      });
      //english
      $(".form-item.form-type-checkbox.form-item-profile-tutor-field-lang-offered-und-5").append($("#edit-profile-tutor-field-english-years"));
      if ($('#edit-profile-tutor-field-lang-offered-und-5:checked').val() !== undefined){
        $("#edit-profile-tutor-field-english-years").css('display','block');
      }else{
        $("#edit-profile-tutor-field-english-years").css('display','none');
      }
      jQuery("#edit-profile-tutor-field-lang-offered-und-5").click(function() {
        if ($('#edit-profile-tutor-field-lang-offered-und-5:checked').val() !== undefined){
          $("#edit-profile-tutor-field-english-years").css('display','block');
        }else{
          $("#edit-profile-tutor-field-english-years").css('display','none');
        }
      });
      //mandarin
      $(".form-item.form-type-checkbox.form-item-profile-tutor-field-lang-offered-und-20").append($("#edit-profile-tutor-field-mandarin-years"));
      if ($('#edit-profile-tutor-field-lang-offered-und-20:checked').val() !== undefined){
        $("#edit-profile-tutor-field-mandarin-years").css('display','block');
      }else{
        $("#edit-profile-tutor-field-mandarin-years").css('display','none');
      }
      jQuery("#edit-profile-tutor-field-lang-offered-und-20").click(function() {
        if ($('#edit-profile-tutor-field-lang-offered-und-20:checked').val() !== undefined){
          $("#edit-profile-tutor-field-mandarin-years").css('display','block');
        }else{
          $("#edit-profile-tutor-field-mandarin-years").css('display','none');
        }
      });
      //others
      $(".form-item.form-type-checkbox.form-item-profile-tutor-field-lang-offered-und-21").append($("#edit-profile-tutor-field-tutor-others"));
      $(".form-item.form-type-checkbox.form-item-profile-tutor-field-lang-offered-und-21").append($("#edit-profile-tutor-field-others-years"));
      if ($('#edit-profile-tutor-field-lang-offered-und-21:checked').val() !== undefined){
        $("#edit-profile-tutor-field-tutor-others").css('display','block');
        $("#edit-profile-tutor-field-others-years").css('display','block');
      }else{
        $("#edit-profile-tutor-field-tutor-others").css('display','none');
        $("#edit-profile-tutor-field-others-years").css('display','none');
      }
      jQuery("#edit-profile-tutor-field-lang-offered-und-21").click(function() {
        if ($('#edit-profile-tutor-field-lang-offered-und-21:checked').val() !== undefined){
          $("#edit-profile-tutor-field-tutor-others").css('display','block');
          $("#edit-profile-tutor-field-others-years").css('display','block');
        }else{
          $("#edit-profile-tutor-field-tutor-others").css('display','none');
          $("#edit-profile-tutor-field-others-years").css('display','none');
        }
      });
    }
  };
})(jQuery);