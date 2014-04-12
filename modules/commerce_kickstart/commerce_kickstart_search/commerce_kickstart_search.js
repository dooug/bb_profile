(function ($) {

var oldLive = $.fn.live;
$.fn.live = function( types, data, fn ) {
  if ( oldLive ) {
    return oldLive.apply( this, arguments );
  }
  $( this.context ).on( types, this.selector, data, fn );
  return this;
};

  // Disable checkboxes when the user clicks on one of them. (prevent
  // multi-clic
  Drupal.behaviors.kickstartSearch = {
    attach:function (context) {
      $('.facetapi-checkbox').live('click', function(e) {
        $('.facetapi-checkbox').attr("disabled", true);
      });
    }
  }
})(jQuery);
