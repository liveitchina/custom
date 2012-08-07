(function ($) {
  Drupal.behaviors.liveitchina = {
    attach: function(context) {
  var uvOptions = {};
  //(function() {
    var uv = document.createElement('script'); uv.type = 'text/javascript'; uv.async = true;
    //uv.src = ('https:' == document.location.protocol ? 'https://' : 'http://') + 'widget.uservoice.com/Kqe5f3u6uUyZoGp8Js1WQ.js';
    uv.src = ('https:' == document.location.protocol ? 'https://' : 'http://') + 'widget.uservoice.com/037doNR5GhOAsK23dyMJQ.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(uv, s);
  //})();
    }
  };
})(jQuery);