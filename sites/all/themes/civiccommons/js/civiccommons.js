
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


/*jQuery(document).ready(function() {	
	setTimeout(function(){
		var t = $('#popup_FrameDecorationDiv_0').css('top');
		console.log(t);
		var k = parseInt(t.slice(0,t.length-2));
		k = k+1;
		console.log(k);
		$('#popup_FrameDecorationDiv_0').css('top', k);
	 }, 10000);
});*/

/*jQuery(document).ready(function() {
	document.getElementById('#page-title').innerHTML = "Hello";
	$('#page-title').css('color','#ff00ff');
	console.log("hello");
	console.log($('#popup_FrameDecorationDiv_4').css('bottom'));
	
});

jQuery(document).ready(function() {	
	console.log("hello");
	/*jQuery('#page-title').text('hello');*/
	
	/*console.log('t=');
	 jQuery("#OpenLayers.Geometry.Point_34").click(function(){
			setTimeout(function(){
				var t = jQuery('#popup_FrameDecorationDiv_0').css('top');
				console.log(t);
			 }, 1000);
	 });
			  jQuery("#popup_close").click(function(){
				alert("CLICK");
				console.log(jQuery('#popup_FrameDecorationDiv_0').css('bottom'));
				jQuery('#popup_FrameDecorationDiv_0').css('padding-left','8px');
				
		   });
		   
		  jQuery('#popup').css('height','90px'); 
	 
		
	
});
*/
