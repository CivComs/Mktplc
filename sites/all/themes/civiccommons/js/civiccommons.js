
// Fire of row evenizers on page load
jQuery(document).ready(evenizeRowHeights(".view-applications .views-row .views-field-field-application-sdesc"));
jQuery(document).ready(evenizeRowHeights(".view-places .views-row .field-content"));
jQuery(document).ready(evenizeRowHeights(".meta"));


/*
#
#  makes all app listing rows the same height --
#  using the height of the tallest row for everything.
#
*/
function evenizeRowHeights(selector) {

  return function() {
  	var rowMaxHeight = 0;
  	jQuery(selector).each(function () {
  		 var elHeight = jQuery(this).height();
  		 if(elHeight > rowMaxHeight){
  			 rowMaxHeight = elHeight;
  		 }
  	});
  		jQuery(selector).each(function () {
				jQuery(this).height(rowMaxHeight);
  	});
  }  
  	
}



