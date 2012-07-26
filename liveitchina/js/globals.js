jQuery(document).ready(function () {
  /*
  jQuery('#block-locale-language .block-content ul').each(function(){
    var list=jQuery(this),
    sortform = jQuery(document.createElement('form')).insertBefore(jQuery(this).hide()).attr('id','form-switcher-locale');
    select = jQuery(document.createElement('select')).appendTo(sortform);
    select.change(function(){
      window.location = jQuery(this).val();
    });

    jQuery('>li a', this).each(function(){
      var target=jQuery(this).attr('target'),
          option=jQuery(document.createElement('option'))
          .appendTo(select)
          .val(this.href)
          .html(jQuery(this).html());
    });
    list.remove();
  });
*/
  jQuery('.block-slider').each(function(index, value){
    var link = jQuery(document.createElement('a')).attr({
          "href":"#",
          "class":"slider-button"
        });

    link.text("+").bind('click',function(index, value){
      event.preventDefault();
      jQuery(this).siblings('.block-content, .view').slideToggle('slow', function(){
      var parent = jQuery(this).parent('.block-slider');
      if (parent.hasClass('toggle-open')){
        parent.removeClass('toggle-open').addClass('toggle-close');
      }
      else{
        parent.removeClass('toggle-close').addClass('toggle-open');
      }
    });
  });

  jQuery(this).append(link).addClass('toggle-open');
    if (!jQuery(this).hasClass('connections')){
      jQuery('.slider-button',this).trigger('click');
    }
  });
      
  jQuery('.hscroller-link').click(function(event){
    event.preventDefault();
    var hashId = this.hash;
    if (hashId == '#write-review-link'){
      jQuery(hashId).parents('form').parent('.block-content').slideToggle('slow', function(){
        if (jQuery(this).hasClass('toggle-open')){
          jQuery(this).parent('.block-slider').removeClass('toggle-open').addClass('toggle-close');
        }
        else{
          jQuery(this).parent('.block-slider').removeClass('toggle-close').addClass('toggle-open');
        }

      });
    }
    jQuery('html,body').animate({scrollTop:jQuery(this.hash).offset().top}, 500);
  });
});