var $_GET = {};
(function () {
    var e,
        a = /\+/g,  // Regex for replacing addition symbol with a space
        r = /([^&=]+)=?([^&]*)/g,
        d = function (s) { return decodeURIComponent(s.replace(a, " ")); },
        q = window.location.search.substring(1);

    while (e = r.exec(q))
       $_GET[d(e[1])] = d(e[2]);
})();

jQuery(document).ready(function(){
	if(document.location.pathname=='/node/add/interaction'){
		//alert($_GET);
		if(($_GET["interaction_id"]!=undefined)/*&&($_GET["app_id"]!=undefined)*/){
			$('#edit-field-interaction-type-und').val(""+$_GET["interaction_id"]+"");
			$('#edit-field-interaction-application-und').val(""+$_GET["app_id"]+"");
		}
	}
});