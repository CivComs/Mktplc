<?php
//Renderable array of shadowboxed images. Argument - node with 'field_image'.
function _cc_formatters_shadowbox_gallery($node) {
	$items = field_get_items('node', $node, 'field_image');
	$instance = field_info_instance('node', 'field_image', 'image');
	$display = field_get_display($instance, 'full', $node);
	$settings = $display['settings'];
	$gallery = array();
	foreach($items as $item) {
		$gallery[] = array(
			'#theme' => 'shadowbox_formatter',
			'#itemid' => NULL,
			'#item' => $item,
			'#image_style' => $settings['image_style'],
			'#image_link' => $settings['image_link'],
			'#gallery' => 'field_image',
			'#title' => '',
			'#attached' => array('library' => array(0 => array('shadowbox', 'shadowbox')))
		);
	}
	return $gallery;
}
