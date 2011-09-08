(function ($) {
	$(document).ready(function() {
		$('.field-type-node-reference').each(function() {
			if($(this).find('.sb-image').length > 0) {
				$(this).find('.field-item').each(function(index) {
					if(index > 0) {
						$(this).hide();
					}else{
						$(this).find('img').hide();
						$(this).find('a').append('Photos');
					}
				});
			}
		});
	});
}(jQuery));
