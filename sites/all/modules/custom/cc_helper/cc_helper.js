$j = jQuery.noConflict();
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
$j(function(){
if(document.location.pathname=='/node/add/interaction'){
	//alert($_GET);
	$j('#edit-field-interaction-type-und').val(""+$_GET["interaction_id"]+"");
	$j('#edit-field-interaction-application-und').val(""+$_GET["app_id"]+"");
}
});