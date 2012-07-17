(function ($) {
  $(document).ready(function(){
    var isSchool = Drupal.settings.lic_search.school;

    $(".show-menu").click(function(e){
        e.preventDefault();
        if($(".show-menu").hasClass("menu-open")){
             $(".show-menu").removeClass("menu-open");
             $("ul#display-menu.children").hide();
         
        } else {
           $("ul#display-menu.children").show();
           $(".show-menu").addClass("menu-open");
        }
    });
    
    $("ul#display-menu.children").mouseup(function() {return false});
    $(".show-menu").mouseup(function() {return false});
    $(document).mouseup(function(e){
        if($(e.target).parent("a.show-menu").length==0){
            $(".show-menu").removeClass("menu-open");
            $("ul#display-menu.children").hide();
        }
    });
    
    if (isSchool){
      $('#region-content h1#page-title').append('<a class="back" href="'+ Drupal.settings.lic_search.url +'"> ' + Drupal.t('Promote my School') + '</a>');
    }
  });
})(jQuery);