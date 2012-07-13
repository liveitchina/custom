(function($){
  /**
   * Hide submit button in select widget facet.
   **/
  Drupal.behaviors.FacetapiHideSubmit = {
  attach: function(context) {
    $('.facetapi-widget-select-facet input.ctools-auto-submit-click:not(.facetapi-hide-submit-processed)', context)
    .addClass('facetapi-hide-submit-processed').hide();
  }}

})(jQuery);