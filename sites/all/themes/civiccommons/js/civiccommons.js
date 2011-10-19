
// Fire of row evenizers on page load
jQuery(document).ready(evenizeRowHeights(".view-applications .views-row"));
jQuery(document).ready(evenizeRowHeights(".view-places .views-row"));



/*
#
#  makes all app listing rows the same height --
#  using the height of the tallest row for everything.
#
*/
function evenizeRowHeights(selector) {

  return function() {
  	var rowMaxHeight = 0;
  	jQuery(selector).each(function (i) {
  		 var elHeight = jQuery(this).height();
  		 if(parseInt(elHeight) > rowMaxHeight){
  			 rowMaxHeight = parseInt(elHeight);
  		 }
  	});
  		jQuery(selector).each(function (i) {
  		jQuery(this).css('height',rowMaxHeight+'px !important');
  	});
  }  
  	
}



