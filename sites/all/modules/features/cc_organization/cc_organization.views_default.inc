<?php
/**
 * @file
 * cc_organization.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function cc_organization_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'at_a_glance';
  $view->description = 'Some information about current organization.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'At A Glance (Organization)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'At A Glance';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Header: Apps Organization Using */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'Apps Organization Using';
  $handler->display->display_options['header']['area']['label'] = 'Using';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php
 $result = 0;
 $a = views_get_view(\'apps_this_organization_has_used\');
 if(method_exists($a, \'set_display\') && method_exists($a, \'render\')) {
  $a->set_display(\'block\');
  $a->render();
 }
 if(isset($a->total_rows)) {
  if($a->total_rows > 0) {
   echo(\'<div class="cc-org-apps"><div class="cc-org-prefix">Using</div><div class="cc-org-count">\' . $a->total_rows . \'</div><div class="cc-org-postfix">apps</div></div>\');
  }
 }
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* Header: Apps Organization Sharing */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['ui_name'] = 'Apps Organization Sharing';
  $handler->display->display_options['header']['area_1']['label'] = 'Sharing';
  $handler->display->display_options['header']['area_1']['empty'] = FALSE;
  $handler->display->display_options['header']['area_1']['content'] = '<?php
 $result = 0;
 $a = views_get_view(\'apps_this_organization_has_creat\');
 if(method_exists($a, \'set_display\') && method_exists($a, \'render\')) {
  $a->set_display(\'block\');
  $a->render();
 }
 if(isset($a->total_rows)) {
  if($a->total_rows > 0) {
   echo(\'<div class="cc-org-apps"><div class="cc-org-prefix">Sharing</div><div class="cc-org-count">\' . $a->total_rows . \'</div><div class="cc-org-postfix">apps</div></div>\');
  }
 }
?>';
  $handler->display->display_options['header']['area_1']['format'] = 'php_code';
  $handler->display->display_options['header']['area_1']['tokenize'] = 0;
  /* Field: Contact Group Start */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Contact Group Start';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="org-contact"><div class="org-contact-title">Contact</div>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Content: Street address */
  $handler->display->display_options['fields']['field_organization_address']['id'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['text'] = '<div>[field_organization_address]';
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
  $handler->display->display_options['fields']['field_organization_address']['hide_empty'] = 1;
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
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_organization_link']['id'] = 'field_organization_link';
  $handler->display->display_options['fields']['field_organization_link']['table'] = 'field_data_field_organization_link';
  $handler->display->display_options['fields']['field_organization_link']['field'] = 'field_organization_link';
  $handler->display->display_options['fields']['field_organization_link']['label'] = '';
  $handler->display->display_options['fields']['field_organization_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_link']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_organization_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_organization_link']['type'] = 'url';
  $handler->display->display_options['fields']['field_organization_link']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '</div><div class="org-details"><div class="org-details-title">Details</div>';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_1']['hide_alter_empty'] = 0;
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = 'Type';
  $handler->display->display_options['fields']['term_node_tid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['hide_empty'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'agency_type' => 0,
    'app_services_provided' => 0,
    'app_user_role' => 0,
    'branch' => 0,
    'civic_function' => 0,
    'country' => 0,
    'development_status' => 0,
    'interaction_type' => 0,
    'level_of_government' => 0,
    'organization_type' => 0,
    'place_type' => 0,
    'requirements' => 0,
    'software_licenses' => 0,
    'software_type' => 0,
    'tags' => 0,
    'vendor_services' => 0,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Staff';
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
  $handler->display->display_options['fields']['php']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 1;
  $handler->display->display_options['fields']['php']['empty_zero'] = 1;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if(isset($data->field_field_organization_members)) {
 if(is_array($data->field_field_organization_members)) {
  echo(count($data->field_field_organization_members));
 }
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Annual budget */
  $handler->display->display_options['fields']['field_organization_abudget']['id'] = 'field_organization_abudget';
  $handler->display->display_options['fields']['field_organization_abudget']['table'] = 'field_data_field_organization_abudget';
  $handler->display->display_options['fields']['field_organization_abudget']['field'] = 'field_organization_abudget';
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_organization_abudget']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_abudget']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_organization_abudget']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_organization_abudget']['field_api_classes'] = 0;
  /* Field: Content: Who works there? */
  $handler->display->display_options['fields']['field_organization_members']['id'] = 'field_organization_members';
  $handler->display->display_options['fields']['field_organization_members']['table'] = 'field_data_field_organization_members';
  $handler->display->display_options['fields']['field_organization_members']['field'] = 'field_organization_members';
  $handler->display->display_options['fields']['field_organization_members']['label'] = 'Staff';
  $handler->display->display_options['fields']['field_organization_members']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_organization_members']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_members']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_members']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_organization_members']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_members']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_organization_members']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_organization_members']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['field_api_classes'] = 0;
  /* Field: Content: Typical project budget */
  $handler->display->display_options['fields']['field_organization_pbudget']['id'] = 'field_organization_pbudget';
  $handler->display->display_options['fields']['field_organization_pbudget']['table'] = 'field_data_field_organization_pbudget';
  $handler->display->display_options['fields']['field_organization_pbudget']['field'] = 'field_organization_pbudget';
  $handler->display->display_options['fields']['field_organization_pbudget']['label'] = 'Typical Project Budget';
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['text'] = '[field_organization_address], [field_organization_link], [term_node_tid], [php]';
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_organization_pbudget']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_pbudget']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_organization_pbudget']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_organization_pbudget']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '</div>';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_2']['hide_alter_empty'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Apps Organization Using */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'Apps Organization Using';
  $handler->display->display_options['header']['area']['label'] = 'Using';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<?php
//Used _cc_helper_using_sharing and _cc_helper_view_count from custom cc_helper.module.
echo _cc_helper_using_sharing(arg(1), \'full\');
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Street address */
  $handler->display->display_options['fields']['field_organization_address']['id'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['text'] = '[field_organization_address-locality], [field_organization_address-administrative_area]';
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
  $handler->display->display_options['fields']['field_organization_address']['hide_empty'] = 1;
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
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_organization_link']['id'] = 'field_organization_link';
  $handler->display->display_options['fields']['field_organization_link']['table'] = 'field_data_field_organization_link';
  $handler->display->display_options['fields']['field_organization_link']['field'] = 'field_organization_link';
  $handler->display->display_options['fields']['field_organization_link']['label'] = '';
  $handler->display->display_options['fields']['field_organization_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_link']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_organization_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_organization_link']['type'] = 'url';
  $handler->display->display_options['fields']['field_organization_link']['field_api_classes'] = 0;
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = 'Type';
  $handler->display->display_options['fields']['term_node_tid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['hide_empty'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'agency_type' => 0,
    'app_services_provided' => 0,
    'app_user_role' => 0,
    'branch' => 0,
    'civic_function' => 0,
    'country' => 0,
    'development_status' => 0,
    'interaction_type' => 0,
    'level_of_government' => 0,
    'organization_type' => 0,
    'place_type' => 0,
    'requirements' => 0,
    'software_licenses' => 0,
    'software_type' => 0,
    'tags' => 0,
    'vendor_services' => 0,
  );
  /* Field: Content: Number of Employees */
  $handler->display->display_options['fields']['field_organization_employees']['id'] = 'field_organization_employees';
  $handler->display->display_options['fields']['field_organization_employees']['table'] = 'field_data_field_organization_employees';
  $handler->display->display_options['fields']['field_organization_employees']['field'] = 'field_organization_employees';
  $handler->display->display_options['fields']['field_organization_employees']['label'] = 'Staff';
  $handler->display->display_options['fields']['field_organization_employees']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_employees']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_employees']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_employees']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_employees']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_employees']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_employees']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_employees']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_employees']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_employees']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_employees']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_employees']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_employees']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_organization_employees']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_organization_employees']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_employees']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_employees']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_employees']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_employees']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_organization_employees']['field_api_classes'] = 0;
  /* Field: Content: Annual budget */
  $handler->display->display_options['fields']['field_organization_abudget']['id'] = 'field_organization_abudget';
  $handler->display->display_options['fields']['field_organization_abudget']['table'] = 'field_data_field_organization_abudget';
  $handler->display->display_options['fields']['field_organization_abudget']['field'] = 'field_organization_abudget';
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_organization_abudget']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_abudget']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_organization_abudget']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_abudget']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_organization_abudget']['field_api_classes'] = 0;
  /* Field: Content: Who works there? */
  $handler->display->display_options['fields']['field_organization_members']['id'] = 'field_organization_members';
  $handler->display->display_options['fields']['field_organization_members']['table'] = 'field_data_field_organization_members';
  $handler->display->display_options['fields']['field_organization_members']['field'] = 'field_organization_members';
  $handler->display->display_options['fields']['field_organization_members']['label'] = 'Staff';
  $handler->display->display_options['fields']['field_organization_members']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_organization_members']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_members']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_members']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_organization_members']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_members']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_organization_members']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_organization_members']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_organization_members']['field_api_classes'] = 0;
  /* Field: Content: Typical project budget */
  $handler->display->display_options['fields']['field_organization_pbudget']['id'] = 'field_organization_pbudget';
  $handler->display->display_options['fields']['field_organization_pbudget']['table'] = 'field_data_field_organization_pbudget';
  $handler->display->display_options['fields']['field_organization_pbudget']['field'] = 'field_organization_pbudget';
  $handler->display->display_options['fields']['field_organization_pbudget']['label'] = 'Typical Project Budget';
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['text'] = '[field_organization_address], [field_organization_link], [term_node_tid], [php]';
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_organization_pbudget']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_pbudget']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_organization_pbudget']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_pbudget']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_organization_pbudget']['field_api_classes'] = 0;
  $handler->display->display_options['block_description'] = 'At A Glance';
  $export['at_a_glance'] = $view;

  $view = new view;
  $view->name = 'cc_organizations';
  $view->description = '';
  $view->tag = 'organizations';
  $view->base_table = 'node';
  $view->human_name = 'Organizations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'App: Deployed places';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'cc_organizations_map';
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['empty'] = FALSE;
  $handler->display->display_options['footer']['php']['php_output'] = '';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<img class="setmap" src="/sites/all/themes/civiccommons/images/map-blank.png">
';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Content: Deployments, Evaluations and other interactions with apps (field_organization_interactions) */
  $handler->display->display_options['relationships']['field_organization_interactions_nid']['id'] = 'field_organization_interactions_nid';
  $handler->display->display_options['relationships']['field_organization_interactions_nid']['table'] = 'field_data_field_organization_interactions';
  $handler->display->display_options['relationships']['field_organization_interactions_nid']['field'] = 'field_organization_interactions_nid';
  $handler->display->display_options['relationships']['field_organization_interactions_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_organization_interactions_nid']['delta'] = '-1';
  /* Relationship: Content: With what: App (field_interaction_application) */
  $handler->display->display_options['relationships']['field_interaction_application_nid']['id'] = 'field_interaction_application_nid';
  $handler->display->display_options['relationships']['field_interaction_application_nid']['table'] = 'field_data_field_interaction_application';
  $handler->display->display_options['relationships']['field_interaction_application_nid']['field'] = 'field_interaction_application_nid';
  $handler->display->display_options['relationships']['field_interaction_application_nid']['relationship'] = 'field_organization_interactions_nid';
  $handler->display->display_options['relationships']['field_interaction_application_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_interaction_application_nid']['delta'] = '0';
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
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_organization_decs']['id'] = 'field_organization_decs';
  $handler->display->display_options['fields']['field_organization_decs']['table'] = 'field_data_field_organization_decs';
  $handler->display->display_options['fields']['field_organization_decs']['field'] = 'field_organization_decs';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_interaction_application_nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
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
  /* Filter criterion: Content: Did What: (field_interaction_type) */
  $handler->display->display_options['filters']['field_interaction_type_tid']['id'] = 'field_interaction_type_tid';
  $handler->display->display_options['filters']['field_interaction_type_tid']['table'] = 'field_data_field_interaction_type';
  $handler->display->display_options['filters']['field_interaction_type_tid']['field'] = 'field_interaction_type_tid';
  $handler->display->display_options['filters']['field_interaction_type_tid']['relationship'] = 'field_organization_interactions_nid';
  $handler->display->display_options['filters']['field_interaction_type_tid']['value'] = array(
    156 => '156',
  );
  $handler->display->display_options['filters']['field_interaction_type_tid']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['field_interaction_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_interaction_type_tid']['vocabulary'] = 'interaction_type';

  /* Display: Block: Places where this app is in use */
  $handler = $view->new_display('block', 'Block: Places where this app is in use', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Places where this app is in use';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['empty'] = FALSE;
  $handler->display->display_options['footer']['php']['php_output'] = '<?php $dest = drupal_get_destination();?>
<div class="add-deployment-button">
<a href="<?php echo \'/node/add/interaction?app_id=\'.arg(1).\'&interaction_id=156&destination=\'.$dest[\'destination\'];?>">+ add a place</a>
</div>
';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<img class="setmap" src="/sites/all/themes/civiccommons/images/map-blank.png">
';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;

  /* Display: OpenLayers DO: Orgs for Apps */
  $handler = $view->new_display('openlayers', 'OpenLayers DO: Orgs for Apps', 'openlayers_1');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['grouping'] = 'field_organization_coords';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'field_organization_coords',
    'other_lon' => 'field_organization_coords',
    'wkt' => 'field_organization_coords',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => 'field_organization_decs',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
  /* Field: Content: Coordinates */
  $handler->display->display_options['fields']['field_organization_coords']['id'] = 'field_organization_coords';
  $handler->display->display_options['fields']['field_organization_coords']['table'] = 'field_data_field_organization_coords';
  $handler->display->display_options['fields']['field_organization_coords']['field'] = 'field_organization_coords';
  $handler->display->display_options['fields']['field_organization_coords']['label'] = '';
  $handler->display->display_options['fields']['field_organization_coords']['exclude'] = TRUE;
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
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_organization_decs']['id'] = 'field_organization_decs';
  $handler->display->display_options['fields']['field_organization_decs']['table'] = 'field_data_field_organization_decs';
  $handler->display->display_options['fields']['field_organization_decs']['field'] = 'field_organization_decs';
  $handler->display->display_options['fields']['field_organization_decs']['label'] = '';
  $handler->display->display_options['fields']['field_organization_decs']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['field_organization_decs']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_decs']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_decs']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_organization_decs']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_decs']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_decs']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_organization_decs']['field_api_classes'] = 0;

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '30';
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
  $handler->display->display_options['displays'] = array(
    'block' => 'block',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Block: Organizations by place */
  $handler = $view->new_display('block', 'Block: Organizations by place', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Agencies and organizations in this place';
  $handler->display->display_options['display_description'] = 'Organizations in given place';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no apps used in <strong class="cc-place-name">%1</strong> yet. Be the first to <a href="/node/add/interaction">tell your story</a>!';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 1;
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
  /* Field: Using / Sharing */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Using / Sharing';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 1;
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
echo _cc_helper_using_sharing($data->nid, \'\');
/*echo(_cc_helper_using_sharing(
  _cc_helper_get_references_count($data->nid, \'interaction\', \'field_interaction_organization\', array(156)),
  _cc_helper_sharing($data->nid)//_cc_helper_get_references_count($data->nid, \'interaction\', \'field_interaction_organization\', array(154,155))
));*/
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
  $handler->display->display_options['arguments']['field_organization_address_locality']['title'] = 'Government entities in %1';
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
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    124 => '124',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'organization_type';
  $handler->display->display_options['block_description'] = 'Agencies and organizations';

  /* Display: Block: Organizations by place (2) */
  $handler = $view->new_display('block', 'Block: Organizations by place (2)', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Agencies and organizations in this place';
  $handler->display->display_options['display_description'] = 'Organizations (not government) in given place';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no apps used in <strong class="cc-place-name">%1</strong> yet. Be the first to <a href="/node/add/interaction">tell your story</a>!';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 1;
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
  /* Field: Using / Sharing */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Using / Sharing';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 1;
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
echo _cc_helper_using_sharing($data->nid, \'\');
/*echo(_cc_helper_using_sharing(
  _cc_helper_get_references_count($data->nid, \'interaction\', \'field_interaction_organization\', array(156)),
  _cc_helper_sharing($data->nid)//_cc_helper_get_references_count($data->nid, \'interaction\', \'field_interaction_organization\', array(154,155))
));*/
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
  $handler->display->display_options['arguments']['field_organization_address_locality']['title'] = 'Companies and organizations in %1';
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
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['operator'] = 'not';
  $handler->display->display_options['filters']['tid']['value'] = array(
    124 => '124',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'organization_type';
  $handler->display->display_options['block_description'] = 'Agencies and organizations';
  $export['cc_organizations'] = $view;

  $view = new view;
  $view->name = 'commercial_services';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Commercial Services';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Commercial Services';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = 'Services Offered';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* Field: Content: for Vendors: What Application Services do they provide? */
  $handler->display->display_options['fields']['field_organization_services']['id'] = 'field_organization_services';
  $handler->display->display_options['fields']['field_organization_services']['table'] = 'field_data_field_organization_services';
  $handler->display->display_options['fields']['field_organization_services']['field'] = 'field_organization_services';
  $handler->display->display_options['fields']['field_organization_services']['label'] = '';
  $handler->display->display_options['fields']['field_organization_services']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_services']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_services']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_services']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_services']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_services']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_services']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_services']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_services']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_services']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_services']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_services']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_services']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_services']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_services']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_services']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_services']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_services']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_organization_services']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_organization_services']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_organization_services']['field_api_classes'] = 0;
  /* Sort criterion: Content: for Vendors: What Application Services do they provide? (field_organization_services) */
  $handler->display->display_options['sorts']['field_organization_services_tid']['id'] = 'field_organization_services_tid';
  $handler->display->display_options['sorts']['field_organization_services_tid']['table'] = 'field_data_field_organization_services';
  $handler->display->display_options['sorts']['field_organization_services_tid']['field'] = 'field_organization_services_tid';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
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
  /* Filter criterion: Content: for Vendors: What Application Services do they provide? (field_organization_services) */
  $handler->display->display_options['filters']['field_organization_services_tid']['id'] = 'field_organization_services_tid';
  $handler->display->display_options['filters']['field_organization_services_tid']['table'] = 'field_data_field_organization_services';
  $handler->display->display_options['filters']['field_organization_services_tid']['field'] = 'field_organization_services_tid';
  $handler->display->display_options['filters']['field_organization_services_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_organization_services_tid']['value'] = '';
  $handler->display->display_options['filters']['field_organization_services_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_organization_services_tid']['vocabulary'] = 'app_services_provided';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = 'Services Offered';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['block_description'] = 'Commercial Services Block';
  $export['commercial_services'] = $view;

  $view = new view;
  $view->name = 'vendors_who_service_this_app';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'vendors who service this app';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'vendors who service this app';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Which Vendors Provide Support? */
  $handler->display->display_options['fields']['field_application_vendors']['id'] = 'field_application_vendors';
  $handler->display->display_options['fields']['field_application_vendors']['table'] = 'field_data_field_application_vendors';
  $handler->display->display_options['fields']['field_application_vendors']['field'] = 'field_application_vendors';
  $handler->display->display_options['fields']['field_application_vendors']['label'] = '';
  $handler->display->display_options['fields']['field_application_vendors']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_vendors']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_vendors']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_vendors']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_vendors']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_vendors']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_vendors']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_vendors']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_vendors']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_vendors']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_vendors']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_vendors']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_vendors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_vendors']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_vendors']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_vendors']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_vendors']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_vendors']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_vendors']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_vendors']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_vendors']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_vendors']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_application_vendors']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
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
    'application' => 'application',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['vendors_who_service_this_app'] = $view;

  $view = new view;
  $view->name = 'vendors_who_service_this_app_blo';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Vendors Who Service This App (Block)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Vendors Who Service This App';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = '<?php
 echo(l(
  t(\'+add a vendor\'),
  \'node/\' . arg(1) . \'/edit\',
  array(
   \'attributes\' => array(\'class\' => \'button\'),
   \'fragment\' => \'edit-field-application-vendors\'
  )
 ));
?>';
  $handler->display->display_options['footer']['area']['format'] = 'php_code';
  $handler->display->display_options['footer']['area']['tokenize'] = 0;
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
  /* Contextual filter: Content: Apps this organization provides support / services for (field_vending_apps) */
  $handler->display->display_options['arguments']['field_vending_apps_nid']['id'] = 'field_vending_apps_nid';
  $handler->display->display_options['arguments']['field_vending_apps_nid']['table'] = 'field_data_field_vending_apps';
  $handler->display->display_options['arguments']['field_vending_apps_nid']['field'] = 'field_vending_apps_nid';
  $handler->display->display_options['arguments']['field_vending_apps_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_vending_apps_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_vending_apps_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_vending_apps_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_vending_apps_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_vending_apps_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_vending_apps_nid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['field_vending_apps_nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_vending_apps_nid']['validate_options']['types'] = array(
    'application' => 'application',
  );
  $handler->display->display_options['arguments']['field_vending_apps_nid']['validate_options']['access'] = 0;
  $handler->display->display_options['arguments']['field_vending_apps_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_vending_apps_nid']['not'] = 0;
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['vendors_who_service_this_app_blo'] = $view;

  return $export;
}
