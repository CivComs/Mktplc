<?php
/**
 * @file
 * cc_places_feature.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function cc_places_feature_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'places';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Places';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Places';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'cc_places_map';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  /* Relationship: Content: Deployments, Evaluations and other interactions with apps (field_organization_interactions) */
  $handler->display->display_options['relationships']['field_organization_interactions_nid']['id'] = 'field_organization_interactions_nid';
  $handler->display->display_options['relationships']['field_organization_interactions_nid']['table'] = 'field_data_field_organization_interactions';
  $handler->display->display_options['relationships']['field_organization_interactions_nid']['field'] = 'field_organization_interactions_nid';
  $handler->display->display_options['relationships']['field_organization_interactions_nid']['required'] = 1;
  $handler->display->display_options['relationships']['field_organization_interactions_nid']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Street address */
  $handler->display->display_options['fields']['field_organization_address']['id'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_organization_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_organization_address']['field_api_classes'] = 0;
  /* Field: PHP: WKT City */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'PHP: WKT City';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
$city = $data->field_field_organization_address[0][\'raw\'][\'locality\'];
$geometry = geocode(\'google\',  $city, \'polygon\');
$geo_array = geofield_get_values_from_geometry($geometry);
$city_wkt = $geo_array[\'wkt\'];
print $city_wkt;

?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Coordinates */
  $handler->display->display_options['fields']['field_organization_coords']['id'] = 'field_organization_coords';
  $handler->display->display_options['fields']['field_organization_coords']['table'] = 'field_data_field_organization_coords';
  $handler->display->display_options['fields']['field_organization_coords']['field'] = 'field_organization_coords';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organization' => 'organization',
  );
  /* Filter criterion: Content: What kind of Organization is it? (field_organization_type) */
  $handler->display->display_options['filters']['field_organization_type_tid']['id'] = 'field_organization_type_tid';
  $handler->display->display_options['filters']['field_organization_type_tid']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['filters']['field_organization_type_tid']['field'] = 'field_organization_type_tid';
  $handler->display->display_options['filters']['field_organization_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_organization_type_tid']['vocabulary'] = 'organization_type';
  $handler->display->display_options['filters']['field_organization_type_tid']['hierarchy'] = 1;

  /* Display: Page: Places Main */
  $handler = $view->new_display('page', 'Page: Places Main', 'page');
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'places';

  /* Display: OpenLayers DO: Cities */
  $handler = $view->new_display('openlayers', 'OpenLayers DO: Cities', 'openlayers_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'php',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'field_organization_address',
    'description_field' => 'php_1',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Street address */
  $handler->display->display_options['fields']['field_organization_address']['id'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['text'] = '[field_organization_address-locality], [field_organization_address-administrative_area], [field_organization_address-country]';
  $handler->display->display_options['fields']['field_organization_address']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['alter']['path'] = 'places/[field_organization_address-locality]';
  $handler->display->display_options['fields']['field_organization_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_organization_address']['type'] = 'addressfield_city_only';
  $handler->display->display_options['fields']['field_organization_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_organization_address']['field_api_classes'] = 0;
  /* Field: PHP: WKT City */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'PHP: WKT City';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
$place = $data->field_field_organization_address[0][\'raw\'];
print _cc_places_wkt($place[\'locality\'], $place[\'country\'], $place[\'administrative_area\']);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;

  /* Display: Page: Single Place */
  $handler = $view->new_display('page', 'Page: Single Place', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Places: Single place';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'cc_single_place_map';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Street address */
  $handler->display->display_options['fields']['field_organization_address']['id'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_organization_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_organization_address']['field_api_classes'] = 0;
  /* Field: PHP: WKT City */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'PHP: WKT City';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
$place = $data->field_field_organization_address[0][\'raw\'][\'locality\'];
// _cc_places_wkt is located in cc_places.module
print _cc_places_wkt($place);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Coordinates */
  $handler->display->display_options['fields']['field_organization_coords']['id'] = 'field_organization_coords';
  $handler->display->display_options['fields']['field_organization_coords']['table'] = 'field_data_field_organization_coords';
  $handler->display->display_options['fields']['field_organization_coords']['field'] = 'field_organization_coords';
  $handler->display->display_options['fields']['field_organization_coords']['label'] = '';
  $handler->display->display_options['fields']['field_organization_coords']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_coords']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_coords']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_coords']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_coords']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_coords']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_coords']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_coords']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_coords']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_coords']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_coords']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_coords']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_coords']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_coords']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_coords']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_coords']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_coords']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_coords']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_organization_coords']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_organization_coords']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Street address (field_organization_address:locality) */
  $handler->display->display_options['arguments']['field_organization_address_locality']['id'] = 'field_organization_address_locality';
  $handler->display->display_options['arguments']['field_organization_address_locality']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['arguments']['field_organization_address_locality']['field'] = 'field_organization_address_locality';
  $handler->display->display_options['arguments']['field_organization_address_locality']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_organization_address_locality']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_organization_address_locality']['title'] = '%1';
  $handler->display->display_options['arguments']['field_organization_address_locality']['breadcrumb_enable'] = 1;
  $handler->display->display_options['arguments']['field_organization_address_locality']['breadcrumb'] = '%1';
  $handler->display->display_options['arguments']['field_organization_address_locality']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_organization_address_locality']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_organization_address_locality']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_organization_address_locality']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_organization_address_locality']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_organization_address_locality']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_organization_address_locality']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['field_organization_address_locality']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_organization_address_locality']['validate_options']['code'] = 'return _cc_places_validate_place($argument);';
  $handler->display->display_options['arguments']['field_organization_address_locality']['glossary'] = 0;
  $handler->display->display_options['arguments']['field_organization_address_locality']['limit'] = '0';
  $handler->display->display_options['arguments']['field_organization_address_locality']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['field_organization_address_locality']['break_phrase'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'places/%';

  /* Display: OpenLayers DO: Single Place */
  $handler = $view->new_display('openlayers', 'OpenLayers DO: Single Place', 'openlayers_2');
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'php',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'field_organization_address',
    'description_field' => '',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Street address */
  $handler->display->display_options['fields']['field_organization_address']['id'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['text'] = '[field_organization_address-locality], [field_organization_address-administrative_area], [field_organization_address-country]';
  $handler->display->display_options['fields']['field_organization_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_organization_address']['type'] = 'addressfield_city_only';
  $handler->display->display_options['fields']['field_organization_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_organization_address']['field_api_classes'] = 0;
  /* Field: PHP: WKT City */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'PHP: WKT City';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
$place = $data->field_field_organization_address[0][\'raw\'];
print _cc_places_wkt($place[\'locality\'], $place[\'country\'], $place[\'administrative_area\']);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Street address (field_organization_address:locality) */
  $handler->display->display_options['arguments']['field_organization_address_locality']['id'] = 'field_organization_address_locality';
  $handler->display->display_options['arguments']['field_organization_address_locality']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['arguments']['field_organization_address_locality']['field'] = 'field_organization_address_locality';
  $handler->display->display_options['arguments']['field_organization_address_locality']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_organization_address_locality']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_organization_address_locality']['title'] = '%1';
  $handler->display->display_options['arguments']['field_organization_address_locality']['breadcrumb_enable'] = 1;
  $handler->display->display_options['arguments']['field_organization_address_locality']['breadcrumb'] = '%1';
  $handler->display->display_options['arguments']['field_organization_address_locality']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_organization_address_locality']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_organization_address_locality']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_organization_address_locality']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_organization_address_locality']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_organization_address_locality']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_organization_address_locality']['glossary'] = 0;
  $handler->display->display_options['arguments']['field_organization_address_locality']['limit'] = '0';
  $handler->display->display_options['arguments']['field_organization_address_locality']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['field_organization_address_locality']['break_phrase'] = 0;

  /* Display: Block: Cities list */
  $handler = $view->new_display('block', 'Block: Cities list', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Places: Cities';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Address */
  $handler->display->display_options['fields']['field_organization_address']['id'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['ui_name'] = 'Address';
  $handler->display->display_options['fields']['field_organization_address']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['text'] = '[field_organization_address-locality],[field_organization_address-administrative_area], [field_organization_address-country]';
  $handler->display->display_options['fields']['field_organization_address']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['alter']['path'] = 'places/[field_organization_address-locality]';
  $handler->display->display_options['fields']['field_organization_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['element_class'] = 'views-field-title';
  $handler->display->display_options['fields']['field_organization_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['click_sort_column'] = 'locality';
  $handler->display->display_options['fields']['field_organization_address']['type'] = 'addressfield_city_only';
  $handler->display->display_options['fields']['field_organization_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_organization_address']['group_column'] = 'locality';
  $handler->display->display_options['fields']['field_organization_address']['group_columns'] = array(
    'country' => 'country',
    'administrative_area' => 'administrative_area',
  );
  $handler->display->display_options['fields']['field_organization_address']['field_api_classes'] = 0;
  /* Field: Place URL */
  $handler->display->display_options['fields']['field_organization_address_1']['id'] = 'field_organization_address_1';
  $handler->display->display_options['fields']['field_organization_address_1']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_1']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_1']['ui_name'] = 'Place URL';
  $handler->display->display_options['fields']['field_organization_address_1']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_organization_address_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_organization_address_1']['alter']['text'] = 'places/[field_organization_address_1-locality]';
  $handler->display->display_options['fields']['field_organization_address_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_address_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_address_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_address_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_address_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_address_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_address_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_address_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_address_1']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_organization_address_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_address_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_address_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_address_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_address_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_address_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_address_1']['click_sort_column'] = 'locality';
  $handler->display->display_options['fields']['field_organization_address_1']['type'] = 'addressfield_city_only';
  $handler->display->display_options['fields']['field_organization_address_1']['settings'] = array(
    'use_widget_handlers' => 0,
    'format_handlers' => array(),
  );
  $handler->display->display_options['fields']['field_organization_address_1']['group_column'] = 'locality';
  $handler->display->display_options['fields']['field_organization_address_1']['group_columns'] = array(
    'country' => 'country',
    'administrative_area' => 'administrative_area',
  );
  $handler->display->display_options['fields']['field_organization_address_1']['field_api_classes'] = 0;
  /* Field: Using / Sharing Output */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Using / Sharing Output';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$place = array(
  \'locality\' =>
    isset($data->field_data_field_organization_address_field_organization_add)
    ? $data->field_data_field_organization_address_field_organization_add
    : NULL,
  \'country\' =>
    isset($data->field_data_field_organization_address_field_organization_add_1)
    ? $data->field_data_field_organization_address_field_organization_add_1
    : NULL,
  \'administrative_area\' =>
    isset($data->field_data_field_organization_address_field_organization_add_2)
    ? $data->field_data_field_organization_address_field_organization_add_2
    : NULL
);

echo _cc_helper_using_sharing($place, \'full\', array(124, 127, 128, 129, 130, 131, 132));
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organization' => 'organization',
  );
  /* Filter criterion: Content: Street address (field_organization_address:locality) */
  $handler->display->display_options['filters']['field_organization_address_locality']['id'] = 'field_organization_address_locality';
  $handler->display->display_options['filters']['field_organization_address_locality']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['filters']['field_organization_address_locality']['field'] = 'field_organization_address_locality';
  $handler->display->display_options['filters']['field_organization_address_locality']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['field_organization_address_locality']['value'] = '0';
  /* Filter criterion: Content: What kind of Organization is it? (field_organization_type) */
  $handler->display->display_options['filters']['field_organization_type_tid']['id'] = 'field_organization_type_tid';
  $handler->display->display_options['filters']['field_organization_type_tid']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['filters']['field_organization_type_tid']['field'] = 'field_organization_type_tid';
  $handler->display->display_options['filters']['field_organization_type_tid']['value'] = array(
    124 => '124',
    132 => '132',
    131 => '131',
    128 => '128',
    130 => '130',
    129 => '129',
    127 => '127',
  );
  $handler->display->display_options['filters']['field_organization_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_organization_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_organization_type_tid']['vocabulary'] = 'organization_type';
  $handler->display->display_options['filters']['field_organization_type_tid']['hierarchy'] = 1;
  $handler->display->display_options['block_description'] = 'Places: Cities';
  $handler->display->display_options['block_caching'] = '-1';

  /* Display: Block: Organizations list */
  $handler = $view->new_display('block', 'Block: Organizations list', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Places: Organizations';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Deployments, Evaluations and other interactions with apps (field_organization_interactions) */
  $handler->display->display_options['relationships']['field_organization_interactions_nid']['id'] = 'field_organization_interactions_nid';
  $handler->display->display_options['relationships']['field_organization_interactions_nid']['table'] = 'field_data_field_organization_interactions';
  $handler->display->display_options['relationships']['field_organization_interactions_nid']['field'] = 'field_organization_interactions_nid';
  $handler->display->display_options['relationships']['field_organization_interactions_nid']['required'] = 1;
  $handler->display->display_options['relationships']['field_organization_interactions_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['path']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['path']['alter']['external'] = 0;
  $handler->display->display_options['fields']['path']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['path']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['path']['hide_empty'] = 0;
  $handler->display->display_options['fields']['path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['path']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['path']['absolute'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '60';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Street address */
  $handler->display->display_options['fields']['field_organization_address']['id'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['text'] = '[field_organization_address-locality], [field_organization_address-administrative_area], [field_organization_address-country]';
  $handler->display->display_options['fields']['field_organization_address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['element_class'] = 'location';
  $handler->display->display_options['fields']['field_organization_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_organization_address']['type'] = 'addressfield_city_only';
  $handler->display->display_options['fields']['field_organization_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_organization_address']['field_api_classes'] = 0;
  /* Field: Shared/Using */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Shared/Using';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
//Used _cc_helper_using_sharing and _cc_helper_view_count from custom cc_helper.module.
echo _cc_helper_using_sharing($data->nid, \'full\');
/*echo(theme(\'using_sharing\', array(
  \'using\' => _cc_helper_get_references_count($data->nid, \'interaction\', \'field_interaction_organization\', array(156)),
  \'sharing\' => _cc_helper_sharing($data->nid, FALSE)
)));*/
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organization' => 'organization',
  );
  /* Filter criterion: Content: What kind of Organization is it? (field_organization_type) */
  $handler->display->display_options['filters']['field_organization_type_tid']['id'] = 'field_organization_type_tid';
  $handler->display->display_options['filters']['field_organization_type_tid']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['filters']['field_organization_type_tid']['field'] = 'field_organization_type_tid';
  $handler->display->display_options['filters']['field_organization_type_tid']['value'] = array(
    124 => '124',
    129 => '129',
    132 => '132',
    127 => '127',
    131 => '131',
    128 => '128',
    130 => '130',
  );
  $handler->display->display_options['filters']['field_organization_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_organization_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_organization_type_tid']['vocabulary'] = 'organization_type';
  $handler->display->display_options['filters']['field_organization_type_tid']['hierarchy'] = 1;
  $handler->display->display_options['block_description'] = 'Places: Organizations';
  $handler->display->display_options['block_caching'] = '-1';
  $export['places'] = $view;

  return $export;
}
