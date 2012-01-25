<?php
/**
 * @file
 * cc_application.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function cc_application_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'application_categories';
  $view->description = 'Terms linked to corresponding applications.';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Find More In (Terms)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Find More In';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['separator'] = ' ';
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
  /* Relationship: Nodes Related To A Term */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'taxonomy_index';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['ui_name'] = 'Nodes Related To A Term';
  $handler->display->display_options['relationships']['nid']['label'] = 'Nodes Related To A Term';
  $handler->display->display_options['relationships']['nid']['required'] = 1;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['tid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['tid']['format_plural'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name] ([nid])';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'cc/apps/tags/[tid]';
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'application' => 'application',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'civic_function' => 'civic_function',
    'development_status' => 'development_status',
    'requirements' => 'requirements',
    'software_delivery_method' => 'software_delivery_method',
    'software_function' => 'software_function',
    'software_licenses' => 'software_licenses',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 0;
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'return _cc_helper_is_term_in_node(arg(1), $row->tid)';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['block_description'] = 'Find More In';
  $export['application_categories'] = $view;

  $view = new view;
  $view->name = 'applications';
  $view->description = '';
  $view->tag = 'apps';
  $view->base_table = 'node';
  $view->human_name = 'СС Applications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recently added apps';
  $handler->display->display_options['css_class'] = 'apps-list';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['link_display'] = 'page_5';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  /* Relationship: Content: Add Deployment, Creation, Evaluation, Support (field_application_interactions) */
  $handler->display->display_options['relationships']['field_application_interactions_nid']['id'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['table'] = 'field_data_field_application_interactions';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['field'] = 'field_application_interactions_nid';
  /* Sort criterion: Content: When (field_interaction_date) */
  $handler->display->display_options['sorts']['field_interaction_date_value']['id'] = 'field_interaction_date_value';
  $handler->display->display_options['sorts']['field_interaction_date_value']['table'] = 'field_data_field_interaction_date';
  $handler->display->display_options['sorts']['field_interaction_date_value']['field'] = 'field_interaction_date_value';
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

  /* Display: Page: placeholder */
  $handler = $view->new_display('page', 'Page: placeholder', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Apps';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Apps page header';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'We are working to build the most complete and up-to-date database of government and civic software
-- both the apps themselves and where theyre used.  You can help by <a href="/node/add/application" class="button-add1">adding a new app</a> or 
      by <a href="/node/add/interaction?interaction_id=156" class="button-add2">link an app to an agency/organization that has used it</a>.
  ';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<!-- [nid] -->';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 1;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'application' => 'application',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '0';
  $handler->display->display_options['path'] = 'applications';

  /* Display: Block: Apps most watched */
  $handler = $view->new_display('block', 'Block: Apps most watched', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Most Watched';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_2';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_application_civfunction' => 'field_application_civfunction',
    'count' => 'count',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: watching_app counter */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['label'] = 'app_watch_counter';
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'watching_app';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = 0;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'civic_function' => 'civic_function',
    'agency_type' => 0,
    'app_services_provided' => 0,
    'app_user_role' => 0,
    'branch' => 0,
    'country' => 0,
    'development_status' => 0,
    'interaction_type' => 0,
    'level_of_government' => 0,
    'organization_type' => 0,
    'place_type' => 0,
    'requirements' => 0,
    'software_delivery_method' => 0,
    'software_function' => 0,
    'software_licenses' => 0,
    'software_type' => 0,
    'tags' => 0,
    'vendor_services' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_application_logo']['id'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['table'] = 'field_data_field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['field'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['label'] = '';
  $handler->display->display_options['fields']['field_application_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_application_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_application_logo']['field_api_classes'] = 0;
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
  /* Field: Content: Short Description for Search Results */
  $handler->display->display_options['fields']['field_application_sdesc']['id'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['table'] = 'field_data_field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['field'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['label'] = '';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['preserve_tags'] = '<a> <br> <br/> <br />';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['html'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_sdesc']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['field_api_classes'] = 0;
  /* Field: Content: Civic Function */
  $handler->display->display_options['fields']['field_application_civfunction']['id'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['field'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['label'] = '';
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_civfunction']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['empty'] = 'Uncategorized';
  $handler->display->display_options['fields']['field_application_civfunction']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_civfunction']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['field_api_classes'] = 0;
  /* Field: Flags: Flag counter */
  $handler->display->display_options['fields']['count']['id'] = 'count';
  $handler->display->display_options['fields']['count']['table'] = 'flag_counts';
  $handler->display->display_options['fields']['count']['field'] = 'count';
  $handler->display->display_options['fields']['count']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['fields']['count']['label'] = '';
  $handler->display->display_options['fields']['count']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['count']['alter']['text'] = '<span class="count">[count]</span> watching';
  $handler->display->display_options['fields']['count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['count']['empty_zero'] = 0;
  $handler->display->display_options['fields']['count']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['count']['format_plural'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom_1';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Flags: Flag counter */
  $handler->display->display_options['sorts']['count']['id'] = 'count';
  $handler->display->display_options['sorts']['count']['table'] = 'flag_counts';
  $handler->display->display_options['sorts']['count']['field'] = 'count';
  $handler->display->display_options['sorts']['count']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['sorts']['count']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['block_description'] = 'Apps: Most Watched';

  /* Display: Block: Apps most used */
  $handler = $view->new_display('block', 'Block: Apps most used', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Most Widely Used';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_3';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '2';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_application_civfunction' => 'field_application_civfunction',
    'php' => 'php',
    'changed' => 'changed',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Add Deployment, Creation, Evaluation, Support (field_application_interactions) */
  $handler->display->display_options['relationships']['field_application_interactions_nid']['id'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['table'] = 'field_data_field_application_interactions';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['field'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['required'] = 1;
  $handler->display->display_options['relationships']['field_application_interactions_nid']['delta'] = '-1';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = 0;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'civic_function' => 'civic_function',
    'agency_type' => 0,
    'app_services_provided' => 0,
    'app_user_role' => 0,
    'branch' => 0,
    'country' => 0,
    'development_status' => 0,
    'interaction_type' => 0,
    'level_of_government' => 0,
    'organization_type' => 0,
    'place_type' => 0,
    'requirements' => 0,
    'software_delivery_method' => 0,
    'software_function' => 0,
    'software_licenses' => 0,
    'software_type' => 0,
    'tags' => 0,
    'vendor_services' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_application_logo']['id'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['table'] = 'field_data_field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['field'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['label'] = '';
  $handler->display->display_options['fields']['field_application_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_application_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_application_logo']['field_api_classes'] = 0;
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
  /* Field: Content: Short Description for Search Results */
  $handler->display->display_options['fields']['field_application_sdesc']['id'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['table'] = 'field_data_field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['field'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['label'] = '';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['preserve_tags'] = '<a> <br> <br/> <br />';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['html'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_sdesc']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['field_api_classes'] = 0;
  /* Field: Content: Civic Function */
  $handler->display->display_options['fields']['field_application_civfunction']['id'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['field'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['label'] = '';
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_civfunction']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['empty'] = 'Uncategorized';
  $handler->display->display_options['fields']['field_application_civfunction']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_application_civfunction']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_civfunction']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['field_api_classes'] = 0;
  /* Field: PHP: Count &quot;Deployed&quot; interactions */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'PHP: Count "Deployed" interactions';
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
  $handler->display->display_options['fields']['php']['hide_empty'] = 1;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$nid = $data->nid;
$count = _cc_helper_app_locs($nid);
return $count;

';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print $value ? \'used in \'. $value . \' \'. format_plural($value, \'place\', \'places\') : \'\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom_1';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: PHP */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['sorts']['php']['php_sort'] = 'if ($row1->php < $row2->php) {return 1;}';
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
    'application' => 'application',
  );
  /* Filter criterion: Content: Did what (field_interaction_type) */
  $handler->display->display_options['filters']['field_interaction_type_tid']['id'] = 'field_interaction_type_tid';
  $handler->display->display_options['filters']['field_interaction_type_tid']['table'] = 'field_data_field_interaction_type';
  $handler->display->display_options['filters']['field_interaction_type_tid']['field'] = 'field_interaction_type_tid';
  $handler->display->display_options['filters']['field_interaction_type_tid']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['filters']['field_interaction_type_tid']['value'] = array(
    156 => '156',
  );
  $handler->display->display_options['filters']['field_interaction_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_interaction_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_interaction_type_tid']['vocabulary'] = 'interaction_type';
  $handler->display->display_options['block_description'] = 'Apps: Most Widely Used';

  /* Display: Block: Apps recently added */
  $handler = $view->new_display('block', 'Block: Apps recently added', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recently added apps';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_4';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '3';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_application_civfunction' => 'field_application_civfunction',
    'changed' => 'changed',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = 0;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'civic_function' => 'civic_function',
    'agency_type' => 0,
    'app_services_provided' => 0,
    'app_user_role' => 0,
    'branch' => 0,
    'country' => 0,
    'development_status' => 0,
    'interaction_type' => 0,
    'level_of_government' => 0,
    'organization_type' => 0,
    'place_type' => 0,
    'requirements' => 0,
    'software_delivery_method' => 0,
    'software_function' => 0,
    'software_licenses' => 0,
    'software_type' => 0,
    'tags' => 0,
    'vendor_services' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_application_logo']['id'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['table'] = 'field_data_field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['field'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['label'] = '';
  $handler->display->display_options['fields']['field_application_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_application_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_application_logo']['field_api_classes'] = 0;
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
  /* Field: Content: Short Description for Search Results */
  $handler->display->display_options['fields']['field_application_sdesc']['id'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['table'] = 'field_data_field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['field'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['label'] = '';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['preserve_tags'] = '<a> <br> <br/> <br />';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['html'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_sdesc']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['field_api_classes'] = 0;
  /* Field: Content: Civic Function */
  $handler->display->display_options['fields']['field_application_civfunction']['id'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['field'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['label'] = '';
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_civfunction']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['empty'] = 'Uncategorized';
  $handler->display->display_options['fields']['field_application_civfunction']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_application_civfunction']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_civfunction']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['field_api_classes'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['text'] = '<strong>Updated</strong>[changed]';
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom_1';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  $handler->display->display_options['block_description'] = 'Apps: Recently Added';

  /* Display: Block: Apps recently deployed */
  $handler = $view->new_display('block', 'Block: Apps recently deployed', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Apps: Recently deployed';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_5';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '5';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'nid' => 'nid',
    'field_interaction_organization' => 'field_interaction_organization',
    'field_organization_address' => 'field_organization_address',
    'field_interaction_date' => 'field_interaction_date',
    'field_application_civfunction' => 'field_application_civfunction',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Add Deployment, Creation, Evaluation, Support (field_application_interactions) */
  $handler->display->display_options['relationships']['field_application_interactions_nid']['id'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['table'] = 'field_data_field_application_interactions';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['field'] = 'field_application_interactions_nid';
  /* Relationship: Content: Who (field_interaction_organization) */
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['id'] = 'field_interaction_organization_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['table'] = 'field_data_field_interaction_organization';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['field'] = 'field_interaction_organization_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['required'] = 1;
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['delta'] = '-1';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = 0;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'civic_function' => 'civic_function',
    'agency_type' => 0,
    'app_services_provided' => 0,
    'app_user_role' => 0,
    'branch' => 0,
    'country' => 0,
    'development_status' => 0,
    'interaction_type' => 0,
    'level_of_government' => 0,
    'organization_type' => 0,
    'place_type' => 0,
    'requirements' => 0,
    'software_delivery_method' => 0,
    'software_function' => 0,
    'software_licenses' => 0,
    'software_type' => 0,
    'tags' => 0,
    'vendor_services' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_application_logo']['id'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['table'] = 'field_data_field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['field'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['label'] = '';
  $handler->display->display_options['fields']['field_application_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_application_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_application_logo']['field_api_classes'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="/node/[nid]">[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Who */
  $handler->display->display_options['fields']['field_interaction_organization']['id'] = 'field_interaction_organization';
  $handler->display->display_options['fields']['field_interaction_organization']['table'] = 'field_data_field_interaction_organization';
  $handler->display->display_options['fields']['field_interaction_organization']['field'] = 'field_interaction_organization';
  $handler->display->display_options['fields']['field_interaction_organization']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['fields']['field_interaction_organization']['label'] = '';
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['text'] = 'is being used by [field_interaction_organization]';
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['max_length'] = '140';
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['preserve_tags'] = '<a>';
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_interaction_organization']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_interaction_organization']['element_wrapper_class'] = 'views-field-field-application-sdesc';
  $handler->display->display_options['fields']['field_interaction_organization']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_interaction_organization']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['field_api_classes'] = 0;
  /* Field: Content: Street address */
  $handler->display->display_options['fields']['field_organization_address']['id'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['relationship'] = 'field_interaction_organization_nid';
  $handler->display->display_options['fields']['field_organization_address']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['alter']['text'] = '[field_interaction_organization], [field_organization_address]';
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
  /* Field: Content: Civic Function */
  $handler->display->display_options['fields']['field_application_civfunction']['id'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['field'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['label'] = '';
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_civfunction']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['empty'] = 'Uncategorized';
  $handler->display->display_options['fields']['field_application_civfunction']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_civfunction']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['field_api_classes'] = 0;
  /* Field: Content: When */
  $handler->display->display_options['fields']['field_interaction_date']['id'] = 'field_interaction_date';
  $handler->display->display_options['fields']['field_interaction_date']['table'] = 'field_data_field_interaction_date';
  $handler->display->display_options['fields']['field_interaction_date']['field'] = 'field_interaction_date';
  $handler->display->display_options['fields']['field_interaction_date']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['fields']['field_interaction_date']['label'] = '';
  $handler->display->display_options['fields']['field_interaction_date']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['text'] = '<strong>Deployed</strong> [field_interaction_date]';
  $handler->display->display_options['fields']['field_interaction_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_interaction_date']['element_wrapper_class'] = 'meta';
  $handler->display->display_options['fields']['field_interaction_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_interaction_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['settings'] = array(
    'format_type' => 'custom_1',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_interaction_date']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: When (field_interaction_date) */
  $handler->display->display_options['sorts']['field_interaction_date_value']['id'] = 'field_interaction_date_value';
  $handler->display->display_options['sorts']['field_interaction_date_value']['table'] = 'field_data_field_interaction_date';
  $handler->display->display_options['sorts']['field_interaction_date_value']['field'] = 'field_interaction_date_value';
  $handler->display->display_options['sorts']['field_interaction_date_value']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['sorts']['field_interaction_date_value']['order'] = 'DESC';
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
    'application' => 'application',
  );
  /* Filter criterion: Content: Did what (field_interaction_type) */
  $handler->display->display_options['filters']['field_interaction_type_tid']['id'] = 'field_interaction_type_tid';
  $handler->display->display_options['filters']['field_interaction_type_tid']['table'] = 'field_data_field_interaction_type';
  $handler->display->display_options['filters']['field_interaction_type_tid']['field'] = 'field_interaction_type_tid';
  $handler->display->display_options['filters']['field_interaction_type_tid']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['filters']['field_interaction_type_tid']['value'] = array(
    0 => '156',
  );
  $handler->display->display_options['filters']['field_interaction_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_interaction_type_tid']['vocabulary'] = 'interaction_type';
  $handler->display->display_options['block_description'] = 'Apps: Recently deployed';

  /* Display: Page: All Apps */
  $handler = $view->new_display('page', 'Page: All Apps', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Apps';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 0;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '6';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no results that match your criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Add Deployment, Creation, Evaluation, Support (field_application_interactions) */
  $handler->display->display_options['relationships']['field_application_interactions_nid']['id'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['table'] = 'field_data_field_application_interactions';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['field'] = 'field_application_interactions_nid';
  /* Relationship: Content: Who (field_interaction_organization) */
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['id'] = 'field_interaction_organization_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['table'] = 'field_data_field_interaction_organization';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['field'] = 'field_interaction_organization_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_application_logo']['id'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['table'] = 'field_data_field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['field'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['label'] = '';
  $handler->display->display_options['fields']['field_application_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_application_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_application_logo']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
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
  /* Field: Content: Short Description for Search Results */
  $handler->display->display_options['fields']['field_application_sdesc']['id'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['table'] = 'field_data_field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['field'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['label'] = '';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_sdesc']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Added';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'cc_date_short';
  /* Field: PHP: Count &quot;Deployed&quot; interactions */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'PHP: Count "Deployed" interactions';
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
  $handler->display->display_options['fields']['php']['php_value'] = '$nid = $data->nid;
$count = _cc_helper_get_references_count($nid);
return $count;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print $value ? \'<span class="count">\'. $value. \'</span>\'. \' \'. t(\'places\') : \'\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '6';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = 'if ($row1->php < $row2->php) {return 1;}';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'added';
  /* Sort criterion: Global: PHP */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['php']['expose']['label'] = 'most used';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['sorts']['php']['php_sort'] = 'if ($row1->php < $row2->php) {return 1;}';
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
    'application' => 'application',
  );
  /* Filter criterion: Content: Civic Function (field_application_civfunction) */
  $handler->display->display_options['filters']['field_application_civfunction_tid']['id'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['field'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['operator_id'] = 'field_application_civfunction_tid_op';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['label'] = 'Civic Function';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['operator'] = 'field_application_civfunction_tid_op';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['identifier'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['vocabulary'] = 'civic_function';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['error_message'] = 1;
  $handler->display->display_options['path'] = 'all/apps';

  /* Display: Page: Apps Most Watched */
  $handler = $view->new_display('page', 'Page: Apps Most Watched', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Most watched apps';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 0;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '7';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no results that match your criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: watching_app counter */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'watching_app';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = 0;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'civic_function' => 'civic_function',
    'agency_type' => 0,
    'app_services_provided' => 0,
    'app_user_role' => 0,
    'branch' => 0,
    'country' => 0,
    'development_status' => 0,
    'interaction_type' => 0,
    'level_of_government' => 0,
    'organization_type' => 0,
    'place_type' => 0,
    'requirements' => 0,
    'software_delivery_method' => 0,
    'software_function' => 0,
    'software_licenses' => 0,
    'software_type' => 0,
    'tags' => 0,
    'vendor_services' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_application_logo']['id'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['table'] = 'field_data_field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['field'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['label'] = '';
  $handler->display->display_options['fields']['field_application_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_application_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_application_logo']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
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
  /* Field: Content: Short Description for Search Results */
  $handler->display->display_options['fields']['field_application_sdesc']['id'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['table'] = 'field_data_field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['field'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['label'] = '';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_sdesc']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['field_api_classes'] = 0;
  /* Field: Content: Civic Function */
  $handler->display->display_options['fields']['field_application_civfunction']['id'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['field'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['label'] = '';
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_civfunction']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_civfunction']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['field_api_classes'] = 0;
  /* Field: Flags: Flag counter */
  $handler->display->display_options['fields']['count']['id'] = 'count';
  $handler->display->display_options['fields']['count']['table'] = 'flag_counts';
  $handler->display->display_options['fields']['count']['field'] = 'count';
  $handler->display->display_options['fields']['count']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['fields']['count']['label'] = '';
  $handler->display->display_options['fields']['count']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['count']['alter']['text'] = '<span class="count">[count]</span> watching';
  $handler->display->display_options['fields']['count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['count']['empty_zero'] = 0;
  $handler->display->display_options['fields']['count']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['count']['format_plural'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom_1';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Flags: Flag counter */
  $handler->display->display_options['sorts']['count']['id'] = 'count';
  $handler->display->display_options['sorts']['count']['table'] = 'flag_counts';
  $handler->display->display_options['sorts']['count']['field'] = 'count';
  $handler->display->display_options['sorts']['count']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['sorts']['count']['order'] = 'DESC';
  $handler->display->display_options['sorts']['count']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['count']['expose']['label'] = 'Most watched';
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
    'application' => 'application',
  );
  /* Filter criterion: Content: Civic Function (field_application_civfunction) */
  $handler->display->display_options['filters']['field_application_civfunction_tid']['id'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['field'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['operator_id'] = 'field_application_civfunction_tid_op';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['label'] = 'Civic Function';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['operator'] = 'field_application_civfunction_tid_op';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['identifier'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['vocabulary'] = 'civic_function';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['error_message'] = 1;
  $handler->display->display_options['path'] = 'most-watched/apps';

  /* Display: Page: Apps Most Used */
  $handler = $view->new_display('page', 'Page: Apps Most Used', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Most used apps';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 0;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '8';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no results that match your criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Add Deployment, Creation, Evaluation, Support (field_application_interactions) */
  $handler->display->display_options['relationships']['field_application_interactions_nid']['id'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['table'] = 'field_data_field_application_interactions';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['field'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['required'] = 1;
  $handler->display->display_options['relationships']['field_application_interactions_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_application_logo']['id'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['table'] = 'field_data_field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['field'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['label'] = '';
  $handler->display->display_options['fields']['field_application_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_application_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_application_logo']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
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
  /* Field: Content: Short Description for Search Results */
  $handler->display->display_options['fields']['field_application_sdesc']['id'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['table'] = 'field_data_field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['field'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['label'] = '';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_sdesc']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['field_api_classes'] = 0;
  /* Field: PHP: Count &quot;Deployed&quot; interactions */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'PHP: Count "Deployed" interactions';
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
  $handler->display->display_options['fields']['php']['php_value'] = '$nid = $data->nid;
$count = _cc_helper_get_references_count($nid);
return $count;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print $value ? format_plural($value, \'<span class="count">1</span> place\',  \'<span class="count">@count</span> places\') : \'\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = 'if ($row1->php < $row2->php) {return 1;}';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Most used */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['ui_name'] = 'Most used';
  $handler->display->display_options['sorts']['php']['order'] = 'DESC';
  $handler->display->display_options['sorts']['php']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['php']['expose']['label'] = 'Most used';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['sorts']['php']['php_sort'] = 'if ($row1->php < $row2->php) {return -1;}
if ($row1->php > $row2->php) {return 1;}';
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
    'application' => 'application',
  );
  /* Filter criterion: Content: Civic Function (field_application_civfunction) */
  $handler->display->display_options['filters']['field_application_civfunction_tid']['id'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['field'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['operator_id'] = 'field_application_civfunction_tid_op';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['label'] = 'Civic Function';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['operator'] = 'field_application_civfunction_tid_op';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['identifier'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['vocabulary'] = 'civic_function';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['error_message'] = 1;
  $handler->display->display_options['path'] = 'most-used/apps';

  /* Display: Page: Apps recently added */
  $handler = $view->new_display('page', 'Page: Apps recently added', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recently added apps';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 0;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no results that match your criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = 0;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'civic_function' => 'civic_function',
    'agency_type' => 0,
    'app_services_provided' => 0,
    'app_user_role' => 0,
    'branch' => 0,
    'country' => 0,
    'development_status' => 0,
    'interaction_type' => 0,
    'level_of_government' => 0,
    'organization_type' => 0,
    'place_type' => 0,
    'requirements' => 0,
    'software_delivery_method' => 0,
    'software_function' => 0,
    'software_licenses' => 0,
    'software_type' => 0,
    'tags' => 0,
    'vendor_services' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_application_logo']['id'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['table'] = 'field_data_field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['field'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['label'] = '';
  $handler->display->display_options['fields']['field_application_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_application_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_application_logo']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
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
  /* Field: Content: Short Description for Search Results */
  $handler->display->display_options['fields']['field_application_sdesc']['id'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['table'] = 'field_data_field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['field'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['label'] = '';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_sdesc']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['field_api_classes'] = 0;
  /* Field: Content: Civic Function */
  $handler->display->display_options['fields']['field_application_civfunction']['id'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['field'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['label'] = '';
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_civfunction']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_civfunction']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Added';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom_1';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Added';
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
    'application' => 'application',
  );
  /* Filter criterion: Content: Civic Function (field_application_civfunction) */
  $handler->display->display_options['filters']['field_application_civfunction_tid']['id'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['field'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['operator_id'] = 'field_application_civfunction_tid_op';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['label'] = 'Civic Function';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['operator'] = 'field_application_civfunction_tid_op';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['identifier'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['vocabulary'] = 'civic_function';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['error_message'] = 1;
  $handler->display->display_options['path'] = 'recent/apps';

  /* Display: Page: Apps Recently Deployed */
  $handler = $view->new_display('page', 'Page: Apps Recently Deployed', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recently deployed apps';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 0;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no results that match your criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Add Deployment, Creation, Evaluation, Support (field_application_interactions) */
  $handler->display->display_options['relationships']['field_application_interactions_nid']['id'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['table'] = 'field_data_field_application_interactions';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['field'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_application_interactions_nid']['delta'] = '-1';
  /* Relationship: Content: Who (field_interaction_organization) */
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['id'] = 'field_interaction_organization_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['table'] = 'field_data_field_interaction_organization';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['field'] = 'field_interaction_organization_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['required'] = 1;
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="/node/[nid]">[title]</a> is being used by';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Street address */
  $handler->display->display_options['fields']['field_organization_address']['id'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['relationship'] = 'field_interaction_organization_nid';
  $handler->display->display_options['fields']['field_organization_address']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_organization_address']['alter']['alter_text'] = 1;
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
  $handler->display->display_options['fields']['field_organization_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_organization_address']['field_api_classes'] = 0;
  /* Field: Content: Who */
  $handler->display->display_options['fields']['field_interaction_organization']['id'] = 'field_interaction_organization';
  $handler->display->display_options['fields']['field_interaction_organization']['table'] = 'field_data_field_interaction_organization';
  $handler->display->display_options['fields']['field_interaction_organization']['field'] = 'field_interaction_organization';
  $handler->display->display_options['fields']['field_interaction_organization']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['fields']['field_interaction_organization']['label'] = '';
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['text'] = '[field_interaction_organization], [field_organization_address]';
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_interaction_organization']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_interaction_organization']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_interaction_organization']['field_api_classes'] = 0;
  /* Field: Content: When */
  $handler->display->display_options['fields']['field_interaction_date']['id'] = 'field_interaction_date';
  $handler->display->display_options['fields']['field_interaction_date']['table'] = 'field_data_field_interaction_date';
  $handler->display->display_options['fields']['field_interaction_date']['field'] = 'field_interaction_date';
  $handler->display->display_options['fields']['field_interaction_date']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['fields']['field_interaction_date']['label'] = '';
  $handler->display->display_options['fields']['field_interaction_date']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['text'] = 'Added [field_interaction_date]';
  $handler->display->display_options['fields']['field_interaction_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_interaction_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_interaction_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_interaction_date']['settings'] = array(
    'format_type' => 'cc_date_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_interaction_date']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: When (field_interaction_date) */
  $handler->display->display_options['sorts']['field_interaction_date_value']['id'] = 'field_interaction_date_value';
  $handler->display->display_options['sorts']['field_interaction_date_value']['table'] = 'field_data_field_interaction_date';
  $handler->display->display_options['sorts']['field_interaction_date_value']['field'] = 'field_interaction_date_value';
  $handler->display->display_options['sorts']['field_interaction_date_value']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['sorts']['field_interaction_date_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_interaction_date_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_interaction_date_value']['expose']['label'] = 'Added';
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
    'application' => 'application',
  );
  /* Filter criterion: Content: Did what (field_interaction_type) */
  $handler->display->display_options['filters']['field_interaction_type_tid']['id'] = 'field_interaction_type_tid';
  $handler->display->display_options['filters']['field_interaction_type_tid']['table'] = 'field_data_field_interaction_type';
  $handler->display->display_options['filters']['field_interaction_type_tid']['field'] = 'field_interaction_type_tid';
  $handler->display->display_options['filters']['field_interaction_type_tid']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['filters']['field_interaction_type_tid']['value'] = array(
    156 => '156',
  );
  $handler->display->display_options['filters']['field_interaction_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_interaction_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_interaction_type_tid']['vocabulary'] = 'interaction_type';
  /* Filter criterion: Content: Civic Function (field_application_civfunction) */
  $handler->display->display_options['filters']['field_application_civfunction_tid']['id'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['field'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['operator_id'] = 'field_application_civfunction_tid_op';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['label'] = 'Civic Function';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['operator'] = 'field_application_civfunction_tid_op';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['identifier'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['vocabulary'] = 'civic_function';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['error_message'] = 1;
  $handler->display->display_options['path'] = 'deployed/apps';

  /* Display: Block: Apps this org has created/shared (nice) */
  $handler = $view->new_display('block', 'Block: Apps this org has created/shared (nice)', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Apps this !org_type has created (!count)';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_3';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '11';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_application_civfunction' => 'field_application_civfunction',
    'php' => 'php',
    'changed' => 'changed',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['empty'] = TRUE;
  $handler->display->display_options['footer']['php']['php_output'] = '<?php
 print \'<div class="edit-content-button">\'
 . l(\'+ add an app this org has created\', \'node/\' . arg(1) . \'/edit\', array(
  \'attributes\' => array(\'class\' => array(\'button\')),
  \'fragment\' => \'edit-field-organization-apps-created\'
 ))
 . \'</div>\';
?>
';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = 0;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'civic_function' => 'civic_function',
    'agency_type' => 0,
    'app_services_provided' => 0,
    'app_user_role' => 0,
    'branch' => 0,
    'country' => 0,
    'development_status' => 0,
    'interaction_type' => 0,
    'level_of_government' => 0,
    'organization_type' => 0,
    'place_type' => 0,
    'requirements' => 0,
    'software_delivery_method' => 0,
    'software_function' => 0,
    'software_licenses' => 0,
    'software_type' => 0,
    'tags' => 0,
    'vendor_services' => 0,
  );
  /* Relationship: Content: Who Created the Application? (field_application_creator) */
  $handler->display->display_options['relationships']['field_application_creator_nid']['id'] = 'field_application_creator_nid';
  $handler->display->display_options['relationships']['field_application_creator_nid']['table'] = 'field_data_field_application_creator';
  $handler->display->display_options['relationships']['field_application_creator_nid']['field'] = 'field_application_creator_nid';
  $handler->display->display_options['relationships']['field_application_creator_nid']['required'] = 1;
  $handler->display->display_options['relationships']['field_application_creator_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_application_logo']['id'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['table'] = 'field_data_field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['field'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['label'] = '';
  $handler->display->display_options['fields']['field_application_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_application_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_application_logo']['field_api_classes'] = 0;
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
  /* Field: Content: Short Description for Search Results */
  $handler->display->display_options['fields']['field_application_sdesc']['id'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['table'] = 'field_data_field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['field'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['label'] = '';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['preserve_tags'] = '<a> <br> <br/> <br />';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['html'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_sdesc']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['field_api_classes'] = 0;
  /* Field: Content: Civic Function */
  $handler->display->display_options['fields']['field_application_civfunction']['id'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['field'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['label'] = '';
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_civfunction']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['empty'] = 'Uncategorized';
  $handler->display->display_options['fields']['field_application_civfunction']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_application_civfunction']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_civfunction']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['field_api_classes'] = 0;
  /* Field: PHP: Count &quot;Deployed&quot; interactions */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'PHP: Count "Deployed" interactions';
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
  $handler->display->display_options['fields']['php']['hide_empty'] = 1;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$nid = $data->nid;
$count = _cc_helper_app_locs($nid);
return $count;

';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print $value ? \'used in \'. $value . \' \'. format_plural($value, \'place\', \'places\') : \'\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom_1';
  /* Field: Content: What kind of Organization is it? */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['label'] = '';
  $handler->display->display_options['fields']['field_organization_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_organization_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: PHP */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['sorts']['php']['php_sort'] = 'if ($row1->php < $row2->php) {return 1;}';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_application_creator_nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
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
    'application' => 'application',
  );
  $handler->display->display_options['block_description'] = 'Apps: that this org has created (nice)';

  /* Display: Block: Apps this org has used */
  $handler = $view->new_display('block', 'Block: Apps this org has used', 'block_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Apps This !org_type Has Used (!count)';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_3';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '12';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_application_civfunction' => 'field_application_civfunction',
    'php' => 'php',
    'changed' => 'changed',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['empty'] = FALSE;
  $handler->display->display_options['footer']['php']['php_output'] = '<?php
 print \'<div class="edit-content-button">\'
 . l(t(\'+ add an app this org has used\'), \'node/add/interaction\', array(
  \'attributes\' => array(\'class\' => array(\'button\'))
 ))
 . \'</div>\';
?>
';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Add one';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<?php
 print \'<div class="edit-content-button">\'
 . l(t(\'+ add an app this org has used\'), \'node/add/interaction\', array(
  \'attributes\' => array(\'class\' => array(\'button\'))
 ))
 . \'</div>\';
?>';
  $handler->display->display_options['empty']['area']['format'] = 'php_code';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Related Interaction */
  $handler->display->display_options['relationships']['field_application_interactions_nid']['id'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['table'] = 'field_data_field_application_interactions';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['field'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['ui_name'] = 'Related Interaction';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['label'] = 'Interactions';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_application_interactions_nid']['delta'] = '-1';
  /* Relationship: Content: Who (field_interaction_organization) */
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['id'] = 'field_interaction_organization_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['table'] = 'field_data_field_interaction_organization';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['field'] = 'field_interaction_organization_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_application_logo']['id'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['table'] = 'field_data_field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['field'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['label'] = '';
  $handler->display->display_options['fields']['field_application_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_application_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_application_logo']['field_api_classes'] = 0;
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
  /* Field: Content: What kind of Organization is it? */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['fields']['field_organization_type']['label'] = '';
  $handler->display->display_options['fields']['field_organization_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_organization_type']['field_api_classes'] = 0;
  /* Field: Content: Short Description for Search Results */
  $handler->display->display_options['fields']['field_application_sdesc']['id'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['table'] = 'field_data_field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['field'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['label'] = '';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['preserve_tags'] = '<a> <br> <br/> <br />';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['html'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_sdesc']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['created']['alter']['text'] = 'added [created]';
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'n/j/y';
  /* Field: Content: Civic Function */
  $handler->display->display_options['fields']['field_application_civfunction']['id'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['field'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['label'] = '';
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_civfunction']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['empty'] = 'Uncategorized';
  $handler->display->display_options['fields']['field_application_civfunction']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_civfunction']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['field_api_classes'] = 0;
  /* Field: PHP: Count &quot;Deployed&quot; interactions */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'PHP: Count "Deployed" interactions';
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
  $handler->display->display_options['fields']['php']['php_value'] = '$nid = $data->nid;
$count = _cc_helper_app_locs($nid);
return $count;
';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print $value ? \'used in \'. $value . \' \'. format_plural($value, \'place\', \'places\') : \'\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom_1';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Organization ID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_interaction_organization_nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Organization ID';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
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
    'application' => 'application',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    156 => '156',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'interaction_type';
  $handler->display->display_options['block_description'] = 'KKKApps: that this org has used';

  /* Display: Block: Apps made in This place */
  $handler = $view->new_display('block', 'Block: Apps made in This place', 'block_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Apps made in !place';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_3';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '14';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_application_civfunction' => 'field_application_civfunction',
    'php' => 'php',
    'changed' => 'changed',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Who Created the Application? (field_application_creator) */
  $handler->display->display_options['relationships']['field_application_creator_nid']['id'] = 'field_application_creator_nid';
  $handler->display->display_options['relationships']['field_application_creator_nid']['table'] = 'field_data_field_application_creator';
  $handler->display->display_options['relationships']['field_application_creator_nid']['field'] = 'field_application_creator_nid';
  $handler->display->display_options['relationships']['field_application_creator_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_application_creator_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_application_logo']['id'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['table'] = 'field_data_field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['field'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['label'] = '';
  $handler->display->display_options['fields']['field_application_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_application_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_application_logo']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Short Description for Search Results */
  $handler->display->display_options['fields']['field_application_sdesc']['id'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['table'] = 'field_data_field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['field'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['label'] = '';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['preserve_tags'] = '<a> <p> <br> <br/> <br />';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_sdesc']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['field_api_classes'] = 0;
  /* Field: Content: Civic Function */
  $handler->display->display_options['fields']['field_application_civfunction']['id'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['field'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['label'] = '';
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_civfunction']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['empty'] = 'Uncategorized';
  $handler->display->display_options['fields']['field_application_civfunction']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_civfunction']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['field_api_classes'] = 0;
  /* Field: PHP: Count &quot;Deployed&quot; interactions */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'PHP: Count "Deployed" interactions';
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
  $handler->display->display_options['fields']['php']['php_value'] = '$nid = $data->nid;
$count = _cc_helper_app_locs($nid);
return $count;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print $value ? \'used in \'. $value . \' \'. format_plural($value, \'place\', \'places\') : \'\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom_1';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Street address (field_organization_address:locality) */
  $handler->display->display_options['arguments']['field_organization_address_locality']['id'] = 'field_organization_address_locality';
  $handler->display->display_options['arguments']['field_organization_address_locality']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['arguments']['field_organization_address_locality']['field'] = 'field_organization_address_locality';
  $handler->display->display_options['arguments']['field_organization_address_locality']['relationship'] = 'field_application_creator_nid';
  $handler->display->display_options['arguments']['field_organization_address_locality']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_organization_address_locality']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_organization_address_locality']['title'] = 'Apps made in %1';
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
    'application' => 'application',
  );
  $handler->display->display_options['block_description'] = 'KKKApps: apps in place';
  $export['applications'] = $view;

  $view = new view;
  $view->name = 'apps_browse_by';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Apps: Browse By (Home Page)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Block: Software Type';
  $handler->display->display_options['css_class'] = 'category-list';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'nid' => 'nid',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relationship: Content: Civic Function (field_application_civfunction) */
  $handler->display->display_options['relationships']['field_application_civfunction_tid']['id'] = 'field_application_civfunction_tid';
  $handler->display->display_options['relationships']['field_application_civfunction_tid']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['relationships']['field_application_civfunction_tid']['field'] = 'field_application_civfunction_tid';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_application_civfunction_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 0;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
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

  /* Display: Block: Civic Function */
  $handler = $view->new_display('block', 'Block: Civic Function', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Block: Civic function';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'nid' => 'nid',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Civic Function (field_application_civfunction) */
  $handler->display->display_options['relationships']['field_application_civfunction_tid']['id'] = 'field_application_civfunction_tid';
  $handler->display->display_options['relationships']['field_application_civfunction_tid']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['relationships']['field_application_civfunction_tid']['field'] = 'field_application_civfunction_tid';
  $handler->display->display_options['relationships']['field_application_civfunction_tid']['required'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_application_civfunction_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['block_description'] = 'Civic Function (simple list)';
  $handler->display->display_options['block_caching'] = '1';

  /* Display: Block: Software Type */
  $handler = $view->new_display('block', 'Block: Software Type', 'block_1');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Software Function (field_application_softfunction) */
  $handler->display->display_options['relationships']['field_application_softfunction_tid']['id'] = 'field_application_softfunction_tid';
  $handler->display->display_options['relationships']['field_application_softfunction_tid']['table'] = 'field_data_field_application_softfunction';
  $handler->display->display_options['relationships']['field_application_softfunction_tid']['field'] = 'field_application_softfunction_tid';
  $handler->display->display_options['relationships']['field_application_softfunction_tid']['required'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_application_softfunction_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
  $handler->display->display_options['block_description'] = 'Software Type (simple list)';
  $handler->display->display_options['block_caching'] = '1';

  /* Display: Block: Places */
  $handler = $view->new_display('block', 'Block: Places', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'places-list';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['style_options']['fill_single_line'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'php' => 'php',
    'nid' => 'nid',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['label'] = '"Table" headings';
  $handler->display->display_options['header']['area_1']['empty'] = FALSE;
  $handler->display->display_options['header']['area_1']['content'] = '<h2 class="block-title">
<span class="browse">Browse places</span>
<span class="using">Using</span>
<span class="created">Created</span>
</h2>';
  $handler->display->display_options['header']['area_1']['format'] = 'full_html';
  $handler->display->display_options['header']['area_1']['tokenize'] = 0;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: &quot;More&quot; Link */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['ui_name'] = '"More" Link';
  $handler->display->display_options['footer']['php']['empty'] = FALSE;
  $handler->display->display_options['footer']['php']['php_output'] = '<?php echo l(t(\'More places >\'), \'places\'); ?>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Place URL */
  $handler->display->display_options['fields']['field_organization_address_1']['id'] = 'field_organization_address_1';
  $handler->display->display_options['fields']['field_organization_address_1']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_1']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_1']['ui_name'] = 'Place URL';
  $handler->display->display_options['fields']['field_organization_address_1']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_organization_address_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_organization_address_1']['alter']['text'] = 'places/[field_organization_address_1-locality] ';
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
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_organization_address_1']['group_column'] = 'locality';
  $handler->display->display_options['fields']['field_organization_address_1']['group_columns'] = array(
    'country' => 'country',
    'administrative_area' => 'administrative_area',
  );
  $handler->display->display_options['fields']['field_organization_address_1']['field_api_classes'] = 0;
  /* Field: Content: Street address */
  $handler->display->display_options['fields']['field_organization_address']['id'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['text'] = '[field_organization_address-locality]';
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
  /* Field: PHP: Using */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'PHP: Using';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['php']['php_value'] = '$place = array(
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
return _cc_helper_using($place);';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: PHP: Sharing */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'PHP: Sharing';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = '$place = array(
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
return _cc_helper_sharing($place);';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Content: Street address */
  $handler->display->display_options['fields']['field_organization_address_2']['id'] = 'field_organization_address_2';
  $handler->display->display_options['fields']['field_organization_address_2']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_2']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_2']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_address_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_address_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_address_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_address_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_address_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_address_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_address_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_address_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_address_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_address_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_address_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_address_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_address_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_address_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_address_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_address_2']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_address_2']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_organization_address_2']['type'] = 'using_sharing';
  $handler->display->display_options['fields']['field_organization_address_2']['settings'] = array(
    'count_by' => 'city',
    'filter_by' => array(
      124 => '124',
      132 => '132',
      131 => '131',
      128 => '128',
      130 => '130',
      129 => '129',
      127 => '127',
    ),
    'appearance' => '',
  );
  $handler->display->display_options['fields']['field_organization_address_2']['group_column'] = 'locality';
  $handler->display->display_options['fields']['field_organization_address_2']['group_columns'] = array(
    'country' => 'country',
    'administrative_area' => 'administrative_area',
  );
  $handler->display->display_options['fields']['field_organization_address_2']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: PHP */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['order'] = 'DESC';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['sorts']['php']['php_sort'] = 'return $row1->php + $row1->php_1 - $row2->php - $row2->php_1;';
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
  $handler->display->display_options['block_description'] = 'Places - homepage list';
  $handler->display->display_options['block_caching'] = '1';

  /* Display: Block: Places - simple grid */
  $handler = $view->new_display('block', 'Block: Places - simple grid', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Block: Places (simple grid)';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'places-list-simple browse-by-grid';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'php' => 'php',
    'nid' => 'nid',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: &quot;More&quot; Link */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['ui_name'] = '"More" Link';
  $handler->display->display_options['footer']['php']['empty'] = FALSE;
  $handler->display->display_options['footer']['php']['php_output'] = '<?php echo l(t(\'More places >\'), \'places\'); ?>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Place URL */
  $handler->display->display_options['fields']['field_organization_address_1']['id'] = 'field_organization_address_1';
  $handler->display->display_options['fields']['field_organization_address_1']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_1']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address_1']['ui_name'] = 'Place URL';
  $handler->display->display_options['fields']['field_organization_address_1']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_organization_address_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_organization_address_1']['alter']['text'] = 'places/[field_organization_address_1-locality] ';
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
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_organization_address_1']['group_column'] = 'locality';
  $handler->display->display_options['fields']['field_organization_address_1']['group_columns'] = array(
    'country' => 'country',
    'administrative_area' => 'administrative_area',
  );
  $handler->display->display_options['fields']['field_organization_address_1']['field_api_classes'] = 0;
  /* Field: Content: Street address */
  $handler->display->display_options['fields']['field_organization_address']['id'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_address']['alter']['text'] = '[field_organization_address-locality]';
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
  /* Field: PHP: Using */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'PHP: Using';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['php']['php_value'] = '$place = array(
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
return _cc_helper_using($place);';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: PHP: Sharing */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'PHP: Sharing';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = '$place = array(
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
return _cc_helper_sharing($place);';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: PHP: Using / Sharing */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['ui_name'] = 'PHP: Using / Sharing';
  $handler->display->display_options['fields']['php_2']['label'] = '';
  $handler->display->display_options['fields']['php_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_2']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = '$row->php + $row->php_1;';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
$total = $row->php + $row->php_1;
if ($total > 0) echo "($total)";
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: PHP */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['order'] = 'DESC';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['sorts']['php']['php_sort'] = 'return $row1->php + $row1->php_1 - $row2->php - $row2->php_1;';
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
  $handler->display->display_options['block_description'] = 'Places (simple list)';
  $handler->display->display_options['block_caching'] = '1';
  $export['apps_browse_by'] = $view;

  $view = new view;
  $view->name = 'apps_org_has_created';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'apps this organization has created and shared';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'apps this organization has created and shared';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['empty'] = TRUE;
  $handler->display->display_options['footer']['php']['php_output'] = '<a class="button" href="/node/<?php echo(arg(1)); ?>/edit#field-organization-apps-created-add-more-wrapper">+add an app this organization has created or shared</a>';
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
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
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Who Created the Application? (field_application_creator) */
  $handler->display->display_options['arguments']['field_application_creator_nid']['id'] = 'field_application_creator_nid';
  $handler->display->display_options['arguments']['field_application_creator_nid']['table'] = 'field_data_field_application_creator';
  $handler->display->display_options['arguments']['field_application_creator_nid']['field'] = 'field_application_creator_nid';
  $handler->display->display_options['arguments']['field_application_creator_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_application_creator_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_application_creator_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_application_creator_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_application_creator_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_application_creator_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_application_creator_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_application_creator_nid']['not'] = 0;
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

  /* Display: vendors */
  $handler = $view->new_display('block', 'vendors', 'block');
  $export['apps_org_has_created'] = $view;

  $view = new view;
  $view->name = 'apps_this_organization_has_creat';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Apps This Organization Has Created And Shared';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Apps This !org_type Has Created And Shared (!count)';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['label'] = 'Button';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = '<?php
 echo l(
 t( \'+ add an app this org has created\'),
  \'node/add/interaction\',
  array(\'arguments\' => array(\'class\' => \'button\'))
 );
?>';
  $handler->display->display_options['footer']['area']['format'] = 'php_code';
  $handler->display->display_options['footer']['area']['tokenize'] = 1;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  /* Relationship: Content: Add Deployment, Creation, Evaluation, Support (field_application_interactions) */
  $handler->display->display_options['relationships']['field_application_interactions_nid']['id'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['table'] = 'field_data_field_application_interactions';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['field'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_application_interactions_nid']['delta'] = '-1';
  /* Relationship: Content: Who (field_interaction_organization) */
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['id'] = 'field_interaction_organization_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['table'] = 'field_data_field_interaction_organization';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['field'] = 'field_interaction_organization_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['delta'] = '-1';
  /* Relationship: Flags: watching_app counter */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['label'] = 'watching_app counter';
  $handler->display->display_options['relationships']['flag_count_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'watching_app';
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_application_logo']['id'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['table'] = 'field_data_field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['field'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['label'] = '';
  $handler->display->display_options['fields']['field_application_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_application_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_application_logo']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Short Description for Search Results */
  $handler->display->display_options['fields']['field_application_sdesc']['id'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['table'] = 'field_data_field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['field'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['label'] = '';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_sdesc']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['field_api_classes'] = 0;
  /* Field: Places */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Places';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['text'] = '<span class="amount">[php]</span>';
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
  $handler->display->display_options['fields']['php']['hide_empty'] = 1;
  $handler->display->display_options['fields']['php']['empty_zero'] = 1;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return _cc_helper_app_locs($data->node_field_data_field_interaction_application_nid);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php echo \'<span class="amount">\' . $value . \'</span> \' . format_plural($value, \'place\', \'places\'); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Flags: Flag counter */
  $handler->display->display_options['fields']['count']['id'] = 'count';
  $handler->display->display_options['fields']['count']['table'] = 'flag_counts';
  $handler->display->display_options['fields']['count']['field'] = 'count';
  $handler->display->display_options['fields']['count']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['fields']['count']['label'] = '';
  $handler->display->display_options['fields']['count']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['count']['alter']['text'] = '<div class="places">[php]</div><div class="flags">[count]</div>';
  $handler->display->display_options['fields']['count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['count']['element_wrapper_class'] = 'places-flags';
  $handler->display->display_options['fields']['count']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['count']['hide_empty'] = 1;
  $handler->display->display_options['fields']['count']['empty_zero'] = 1;
  $handler->display->display_options['fields']['count']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['count']['format_plural'] = 0;
  $handler->display->display_options['fields']['count']['suffix'] = ' watching';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_interaction_organization_nid';
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
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    154 => '154',
    155 => '155',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'interaction_type';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_attachment_summary'] = FALSE;
  $handler->display->display_options['hide_attachment_summary'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<a class="button" href="/node/add/interaction">+ add an app this org has created and shared</a>
';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: What kind of Organization is it? */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['relationship'] = 'field_interaction_organization_nid';
  $handler->display->display_options['fields']['field_organization_type']['label'] = '';
  $handler->display->display_options['fields']['field_organization_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_organization_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_organization_type']['field_api_classes'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_application_logo']['id'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['table'] = 'field_data_field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['field'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['label'] = '';
  $handler->display->display_options['fields']['field_application_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_application_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_application_logo']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Short Description for Search Results */
  $handler->display->display_options['fields']['field_application_sdesc']['id'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['table'] = 'field_data_field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['field'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['label'] = '';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_sdesc']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['field_api_classes'] = 0;
  /* Field: Places */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Places';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['text'] = '<span class="amount">[php]</span>';
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
  $handler->display->display_options['fields']['php']['hide_empty'] = 1;
  $handler->display->display_options['fields']['php']['empty_zero'] = 1;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return _cc_helper_app_locs($row->nid);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php echo \'<span class="amount">\' . $value . \'</span> \' . format_plural($value, \'place\', \'places\'); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Flags: Flag counter */
  $handler->display->display_options['fields']['count']['id'] = 'count';
  $handler->display->display_options['fields']['count']['table'] = 'flag_counts';
  $handler->display->display_options['fields']['count']['field'] = 'count';
  $handler->display->display_options['fields']['count']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['fields']['count']['label'] = '';
  $handler->display->display_options['fields']['count']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['count']['alter']['text'] = '<div class="places">[php]</div><div class="flags">[count]</div>';
  $handler->display->display_options['fields']['count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['count']['element_wrapper_class'] = 'places-flags';
  $handler->display->display_options['fields']['count']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['count']['hide_empty'] = 1;
  $handler->display->display_options['fields']['count']['empty_zero'] = 1;
  $handler->display->display_options['fields']['count']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['count']['format_plural'] = 0;
  $handler->display->display_options['fields']['count']['suffix'] = ' watching';
  $handler->display->display_options['block_description'] = 'Apps This Organization Has Created And Shared';
  $export['apps_this_organization_has_creat'] = $view;

  $view = new view;
  $view->name = 'apps_this_organization_has_used';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Apps This Organization Has Used';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Apps This !org_type Has Used (!count)';
  $handler->display->display_options['css_class'] = 'apps-list';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['empty'] = FALSE;
  $handler->display->display_options['footer']['php']['php_output'] = '<div class="edit-content-button"><a href="/node/add/application" class="button">+ add an app this org has used</a></div>';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<a href="/node/add/interaction" class="button">+ add an app this org has used</a>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Content: Add Deployment, Creation, Evaluation, Support (field_application_interactions) */
  $handler->display->display_options['relationships']['field_application_interactions_nid']['id'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['table'] = 'field_data_field_application_interactions';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['field'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_application_interactions_nid']['delta'] = '-1';
  /* Relationship: Content: Who (field_interaction_organization) */
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['id'] = 'field_interaction_organization_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['table'] = 'field_data_field_interaction_organization';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['field'] = 'field_interaction_organization_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['delta'] = '-1';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_application_logo']['id'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['table'] = 'field_data_field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['field'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['label'] = '';
  $handler->display->display_options['fields']['field_application_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_application_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_application_logo']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_interaction_application_nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: What kind of Organization is it? */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['fields']['field_organization_type']['label'] = '';
  $handler->display->display_options['fields']['field_organization_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_organization_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['text'] = '[field_organization_type]';
  $handler->display->display_options['fields']['field_organization_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_organization_type']['field_api_classes'] = 0;
  /* Field: Content: Short Description for Search Results */
  $handler->display->display_options['fields']['field_application_sdesc']['id'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['table'] = 'field_data_field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['field'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['relationship'] = 'field_interaction_application_nid';
  $handler->display->display_options['fields']['field_application_sdesc']['label'] = '';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_sdesc']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['created']['alter']['text'] = 'added [created]';
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'n/j/y';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_interaction_organization_nid';
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
    'interaction' => 'interaction',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    156 => '156',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'interaction_type';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Add Deployment, Creation, Evaluation, Support (field_application_interactions) */
  $handler->display->display_options['relationships']['field_application_interactions_nid']['id'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['table'] = 'field_data_field_application_interactions';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['field'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_application_interactions_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_application_interactions_nid']['delta'] = '-1';
  /* Relationship: Content: Who (field_interaction_organization) */
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['id'] = 'field_interaction_organization_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['table'] = 'field_data_field_interaction_organization';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['field'] = 'field_interaction_organization_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_interaction_organization_nid']['delta'] = '-1';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = 0;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'civic_function' => 'civic_function',
    'agency_type' => 0,
    'app_services_provided' => 0,
    'app_user_role' => 0,
    'branch' => 0,
    'country' => 0,
    'development_status' => 0,
    'interaction_type' => 0,
    'level_of_government' => 0,
    'organization_type' => 0,
    'place_type' => 0,
    'requirements' => 0,
    'software_delivery_method' => 0,
    'software_function' => 0,
    'software_licenses' => 0,
    'software_type' => 0,
    'tags' => 0,
    'vendor_services' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_application_logo']['id'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['table'] = 'field_data_field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['field'] = 'field_application_logo';
  $handler->display->display_options['fields']['field_application_logo']['label'] = '';
  $handler->display->display_options['fields']['field_application_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['empty_zero'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_application_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_application_logo']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_interaction_application_nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: What kind of Organization is it? */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['fields']['field_organization_type']['label'] = '';
  $handler->display->display_options['fields']['field_organization_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_organization_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['text'] = '[field_organization_type]';
  $handler->display->display_options['fields']['field_organization_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_organization_type']['field_api_classes'] = 0;
  /* Field: Content: Short Description for Search Results */
  $handler->display->display_options['fields']['field_application_sdesc']['id'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['table'] = 'field_data_field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['field'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['relationship'] = 'field_interaction_application_nid';
  $handler->display->display_options['fields']['field_application_sdesc']['label'] = '';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_sdesc']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['field_api_classes'] = 0;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['php']['php_value'] = '$nid = $data->nid;
$count = _cc_helper_app_locs($nid);
return $count;
';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print $value ? \'used in \'. $value . \' \'. format_plural($value, \'place\', \'places\') : \'\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Civic Function */
  $handler->display->display_options['fields']['field_application_civfunction']['id'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['field'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['label'] = '';
  $handler->display->display_options['fields']['field_application_civfunction']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_civfunction']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_application_civfunction']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_civfunction']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['field_api_classes'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['changed']['date_format'] = 'cc_date_short';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="meta">
<span class="civic-function">[field_application_civfunction]</span> 
<span class="places-used">[php]</span> 
<span class="date-updated">updated [changed]</span>
</div>';
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
    'application' => 'application',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'field_application_interactions_nid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    156 => '156',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'interaction_type';
  $handler->display->display_options['block_description'] = 'Apps This Organization Has Used';
  $export['apps_this_organization_has_used'] = $view;

  $view = new view;
  $view->name = 'at_a_glance_application_';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'At a glance (Application)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Who\'s using this app';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = '<div class="edit-content-button"><a href="/node/[nid]/edit">+ edit details</a></div>';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['footer']['area']['tokenize'] = 1;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'created by';
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
  $handler->display->display_options['fields']['php']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['empty'] = '-';
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return _cc_helper_creators_info($data->nid);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php echo $value; ?>
';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Software Requirements */
  $handler->display->display_options['fields']['field_application_reqs']['id'] = 'field_application_reqs';
  $handler->display->display_options['fields']['field_application_reqs']['table'] = 'field_data_field_application_reqs';
  $handler->display->display_options['fields']['field_application_reqs']['field'] = 'field_application_reqs';
  $handler->display->display_options['fields']['field_application_reqs']['label'] = 'Technical requirements';
  $handler->display->display_options['fields']['field_application_reqs']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_application_reqs']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_reqs']['empty'] = '-';
  $handler->display->display_options['fields']['field_application_reqs']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_application_reqs']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_reqs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_reqs']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['field_api_classes'] = 0;
  /* Field: Content: Software Type */
  $handler->display->display_options['fields']['field_application_deliverymeth']['id'] = 'field_application_deliverymeth';
  $handler->display->display_options['fields']['field_application_deliverymeth']['table'] = 'field_data_field_application_deliverymeth';
  $handler->display->display_options['fields']['field_application_deliverymeth']['field'] = 'field_application_deliverymeth';
  $handler->display->display_options['fields']['field_application_deliverymeth']['label'] = 'Type';
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_deliverymeth']['empty'] = '-';
  $handler->display->display_options['fields']['field_application_deliverymeth']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_application_deliverymeth']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_deliverymeth']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_deliverymeth']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['field_api_classes'] = 0;
  /* Field: Content: License */
  $handler->display->display_options['fields']['field_application_license']['id'] = 'field_application_license';
  $handler->display->display_options['fields']['field_application_license']['table'] = 'field_data_field_application_license';
  $handler->display->display_options['fields']['field_application_license']['field'] = 'field_application_license';
  $handler->display->display_options['fields']['field_application_license']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_license']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_license']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_license']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_application_license']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_license']['empty'] = '-';
  $handler->display->display_options['fields']['field_application_license']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_license']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_license']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_license']['field_api_classes'] = 0;
  /* Field: Content: Releases */
  $handler->display->display_options['fields']['field_application_rlss']['id'] = 'field_application_rlss';
  $handler->display->display_options['fields']['field_application_rlss']['table'] = 'field_data_field_application_rlss';
  $handler->display->display_options['fields']['field_application_rlss']['field'] = 'field_application_rlss';
  $handler->display->display_options['fields']['field_application_rlss']['label'] = 'Latest release';
  $handler->display->display_options['fields']['field_application_rlss']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_rlss']['empty'] = '-';
  $handler->display->display_options['fields']['field_application_rlss']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_rlss']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_application_rlss']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_rlss']['delta_reversed'] = 1;
  $handler->display->display_options['fields']['field_application_rlss']['separator'] = '';
  $handler->display->display_options['fields']['field_application_rlss']['field_api_classes'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: App Homepage */
  $handler->display->display_options['fields']['field_application_homepage']['id'] = 'field_application_homepage';
  $handler->display->display_options['fields']['field_application_homepage']['table'] = 'field_data_field_application_homepage';
  $handler->display->display_options['fields']['field_application_homepage']['field'] = 'field_application_homepage';
  $handler->display->display_options['fields']['field_application_homepage']['label'] = '';
  $handler->display->display_options['fields']['field_application_homepage']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_homepage']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_homepage']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_application_homepage']['type'] = 'url';
  $handler->display->display_options['fields']['field_application_homepage']['field_api_classes'] = 0;
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
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'At a glance';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '[field_application_homepage]';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 1;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = '<div class="edit-content-button"><a href="/node/[nid]/edit">+ edit details</a></div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['footer']['area']['tokenize'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Software Function */
  $handler->display->display_options['fields']['field_application_softfunction']['id'] = 'field_application_softfunction';
  $handler->display->display_options['fields']['field_application_softfunction']['table'] = 'field_data_field_application_softfunction';
  $handler->display->display_options['fields']['field_application_softfunction']['field'] = 'field_application_softfunction';
  $handler->display->display_options['fields']['field_application_softfunction']['label'] = '';
  $handler->display->display_options['fields']['field_application_softfunction']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_softfunction']['alter']['text'] = '[field_application_civfunction]';
  $handler->display->display_options['fields']['field_application_softfunction']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_softfunction']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_softfunction']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_softfunction']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_softfunction']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_softfunction']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_softfunction']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_softfunction']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_softfunction']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_softfunction']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_softfunction']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_softfunction']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_softfunction']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_softfunction']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_application_softfunction']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_softfunction']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_softfunction']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_softfunction']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_softfunction']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_softfunction']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_softfunction']['separator'] = ' ';
  $handler->display->display_options['fields']['field_application_softfunction']['field_api_classes'] = 0;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Created by';
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
  $handler->display->display_options['fields']['php']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 1;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return _cc_helper_creators_info($data->nid);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php echo $value; ?>
';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Software Requirements */
  $handler->display->display_options['fields']['field_application_reqs']['id'] = 'field_application_reqs';
  $handler->display->display_options['fields']['field_application_reqs']['table'] = 'field_data_field_application_reqs';
  $handler->display->display_options['fields']['field_application_reqs']['field'] = 'field_application_reqs';
  $handler->display->display_options['fields']['field_application_reqs']['label'] = 'Technical requirements';
  $handler->display->display_options['fields']['field_application_reqs']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_reqs']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_reqs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_reqs']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_reqs']['field_api_classes'] = 0;
  /* Field: Content: Host URL */
  $handler->display->display_options['fields']['field_application_hosturl']['id'] = 'field_application_hosturl';
  $handler->display->display_options['fields']['field_application_hosturl']['table'] = 'field_data_field_application_hosturl';
  $handler->display->display_options['fields']['field_application_hosturl']['field'] = 'field_application_hosturl';
  $handler->display->display_options['fields']['field_application_hosturl']['label'] = '';
  $handler->display->display_options['fields']['field_application_hosturl']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_application_hosturl']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_application_hosturl']['alter']['text'] = '<a href="[field_application_hosturl-url]">Code repository</a>';
  $handler->display->display_options['fields']['field_application_hosturl']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_hosturl']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_hosturl']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_hosturl']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_hosturl']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_hosturl']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_hosturl']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_hosturl']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_hosturl']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_hosturl']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_hosturl']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_hosturl']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_hosturl']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_hosturl']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_hosturl']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_hosturl']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_hosturl']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_application_hosturl']['type'] = 'url';
  $handler->display->display_options['fields']['field_application_hosturl']['field_api_classes'] = 0;
  /* Field: Content: License */
  $handler->display->display_options['fields']['field_application_license']['id'] = 'field_application_license';
  $handler->display->display_options['fields']['field_application_license']['table'] = 'field_data_field_application_license';
  $handler->display->display_options['fields']['field_application_license']['field'] = 'field_application_license';
  $handler->display->display_options['fields']['field_application_license']['label'] = '';
  $handler->display->display_options['fields']['field_application_license']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_application_license']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_license']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_license']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_license']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_license']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_license']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_license']['empty'] = '-';
  $handler->display->display_options['fields']['field_application_license']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_license']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_license']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_license']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_license']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_license']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_license']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_license']['field_api_classes'] = 0;
  /* Field: Content: Software Type */
  $handler->display->display_options['fields']['field_application_deliverymeth']['id'] = 'field_application_deliverymeth';
  $handler->display->display_options['fields']['field_application_deliverymeth']['table'] = 'field_data_field_application_deliverymeth';
  $handler->display->display_options['fields']['field_application_deliverymeth']['field'] = 'field_application_deliverymeth';
  $handler->display->display_options['fields']['field_application_deliverymeth']['label'] = 'Type';
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['text'] = '[field_application_deliverymeth] ([field_application_license]): [field_application_hosturl]';
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_deliverymeth']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_deliverymeth']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_deliverymeth']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_deliverymeth']['field_api_classes'] = 0;
  /* Field: Content: Releases */
  $handler->display->display_options['fields']['field_application_rlss']['id'] = 'field_application_rlss';
  $handler->display->display_options['fields']['field_application_rlss']['table'] = 'field_data_field_application_rlss';
  $handler->display->display_options['fields']['field_application_rlss']['field'] = 'field_application_rlss';
  $handler->display->display_options['fields']['field_application_rlss']['label'] = 'Latest release';
  $handler->display->display_options['fields']['field_application_rlss']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_rlss']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_application_rlss']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_rlss']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_application_rlss']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_rlss']['delta_reversed'] = 1;
  $handler->display->display_options['fields']['field_application_rlss']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_rlss']['separator'] = '';
  $handler->display->display_options['fields']['field_application_rlss']['field_api_classes'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: App Homepage */
  $handler->display->display_options['fields']['field_application_homepage']['id'] = 'field_application_homepage';
  $handler->display->display_options['fields']['field_application_homepage']['table'] = 'field_data_field_application_homepage';
  $handler->display->display_options['fields']['field_application_homepage']['field'] = 'field_application_homepage';
  $handler->display->display_options['fields']['field_application_homepage']['label'] = '';
  $handler->display->display_options['fields']['field_application_homepage']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['field_application_homepage']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['field_application_homepage']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_homepage']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_homepage']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_homepage']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_application_homepage']['type'] = 'url';
  $handler->display->display_options['fields']['field_application_homepage']['field_api_classes'] = 0;
  /* Field: Content: Standards Implemented */
  $handler->display->display_options['fields']['field_application_stds']['id'] = 'field_application_stds';
  $handler->display->display_options['fields']['field_application_stds']['table'] = 'field_data_field_application_stds';
  $handler->display->display_options['fields']['field_application_stds']['field'] = 'field_application_stds';
  $handler->display->display_options['fields']['field_application_stds']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_stds']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_stds']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_stds']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_stds']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_stds']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_stds']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_stds']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_stds']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_stds']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_stds']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_stds']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_stds']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_application_stds']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_stds']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_application_stds']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_stds']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_application_stds']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_stds']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_stds']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_stds']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_stds']['field_api_classes'] = 0;
  /* Field: Content: Civic Function */
  $handler->display->display_options['fields']['field_application_civfunction']['id'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['field'] = 'field_application_civfunction';
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_civfunction']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_civfunction']['separator'] = ' ';
  $handler->display->display_options['fields']['field_application_civfunction']['field_api_classes'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Categories';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_application_civfunction] [field_application_softfunction]';
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
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['empty'] = '-';
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_application_tags']['id'] = 'field_application_tags';
  $handler->display->display_options['fields']['field_application_tags']['table'] = 'field_data_field_application_tags';
  $handler->display->display_options['fields']['field_application_tags']['field'] = 'field_application_tags';
  $handler->display->display_options['fields']['field_application_tags']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_tags']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_tags']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_tags']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_tags']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_tags']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_tags']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_tags']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_tags']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_tags']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_tags']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_tags']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_tags']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_application_tags']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_tags']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_tags']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_tags']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_tags']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_tags']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_tags']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_application_tags']['field_api_classes'] = 0;
  $handler->display->display_options['block_description'] = 'At a glance (Apps)';

  /* Display: Places / add a place (App) */
  $handler = $view->new_display('block', 'Places / add a place (App)', 'block_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = FALSE;
  $handler->display->display_options['header']['php']['php_output'] = '<?php
$result = 0;
$args = $view->args;
$nid = $args[0];
$result = _cc_helper_app_locs($nid); //cc_helper.module
if($result) {
echo(\'<div class="views-field views-field-field-application-used-in"> <span class="views-label">Used in</span> <div class="cc-app-places"> <div class="cc-places-count">\' . $result . \'</div> <div class="cc-places-postfix">\'.format_plural($result, \'place\', \'places\').\'</div></div></div><a href="#block-views-cc-organizations-block">See where &rarr;</a>\');
} else {
 echo \'<div class="views-field views-field-field-application-used-in">We don\\\'t know where this app is used yet.</div>\';
}
?>';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<div class="edit-content-button"><a href="/node/add/interaction/?edit%5Bfield_interaction_type%5D%5Bund%5D=156&edit%5Bfield_interaction_application%5D%5Bund%5D%5B0%5D%5Bnid%5D=%1%20%5Bnid%3A%20[nid]%5D&compact-overlay=true&destination=node/[nid]">+ add a place</a></div>';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  $handler->display->display_options['block_description'] = 'Places / add a place (App)';
  $export['at_a_glance_application_'] = $view;

  $view = new view;
  $view->name = 'clone_of_apps_browse_by_apps_pag';
  $view->description = '';
  $view->tag = 'default apps browse';
  $view->base_table = 'node';
  $view->human_name = 'Apps: Browse By (Apps Page)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Browse by Software Type';
  $handler->display->display_options['css_class'] = 'browse-by-grid';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'nid' => 'nid',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relationship: Content: Civic Function (field_application_civfunction) */
  $handler->display->display_options['relationships']['field_application_civfunction_tid']['id'] = 'field_application_civfunction_tid';
  $handler->display->display_options['relationships']['field_application_civfunction_tid']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['relationships']['field_application_civfunction_tid']['field'] = 'field_application_civfunction_tid';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_application_civfunction_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
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

  /* Display: Block: Civic Function (Apps page) */
  $handler = $view->new_display('block', 'Block: Civic Function (Apps page)', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Browse Apps by Function';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'nid' => 'nid',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Civic Function (field_application_civfunction) */
  $handler->display->display_options['relationships']['field_application_civfunction_tid']['id'] = 'field_application_civfunction_tid';
  $handler->display->display_options['relationships']['field_application_civfunction_tid']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['relationships']['field_application_civfunction_tid']['field'] = 'field_application_civfunction_tid';
  $handler->display->display_options['relationships']['field_application_civfunction_tid']['required'] = 1;
  $handler->display->display_options['block_description'] = 'Civic Function (simple grid)';

  /* Display: Block: Software Type */
  $handler = $view->new_display('block', 'Block: Software Type', 'block_1');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Software Function (field_application_softfunction) */
  $handler->display->display_options['relationships']['field_application_softfunction_tid']['id'] = 'field_application_softfunction_tid';
  $handler->display->display_options['relationships']['field_application_softfunction_tid']['table'] = 'field_data_field_application_softfunction';
  $handler->display->display_options['relationships']['field_application_softfunction_tid']['field'] = 'field_application_softfunction_tid';
  $handler->display->display_options['relationships']['field_application_softfunction_tid']['required'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_application_softfunction_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
  $handler->display->display_options['block_description'] = 'Software Type (simple grid)';

  /* Display: Block: Places */
  $handler = $view->new_display('block', 'Block: Places', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Places';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Street address */
  $handler->display->display_options['fields']['field_organization_address']['id'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['table'] = 'field_data_field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['field'] = 'field_organization_address';
  $handler->display->display_options['fields']['field_organization_address']['label'] = '';
  $handler->display->display_options['fields']['field_organization_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_organization_address']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_organization_address']['alter']['text'] = '[field_organization_address-locality]';
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
  $handler->display->display_options['fields']['field_organization_address']['click_sort_column'] = 'locality';
  $handler->display->display_options['fields']['field_organization_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['field_organization_address']['group_column'] = 'locality';
  $handler->display->display_options['fields']['field_organization_address']['field_api_classes'] = 0;
  /* Field: PHP: Place link */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'PHP: Place link';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['text'] = '[php]';
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['path'] = 'places/[php]';
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
  $handler->display->display_options['fields']['php']['php_value'] = 'return $data->field_data_field_organization_address_field_organization_add;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
print $value;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
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
  $handler->display->display_options['block_description'] = 'Places';

  /* Display: Block: requirements */
  $handler = $view->new_display('block', 'Block: requirements', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Browse by Software Requirements';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Software Requirements (field_application_reqs) */
  $handler->display->display_options['relationships']['field_application_reqs_tid']['id'] = 'field_application_reqs_tid';
  $handler->display->display_options['relationships']['field_application_reqs_tid']['table'] = 'field_data_field_application_reqs';
  $handler->display->display_options['relationships']['field_application_reqs_tid']['field'] = 'field_application_reqs_tid';
  $handler->display->display_options['relationships']['field_application_reqs_tid']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_application_reqs_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
  $handler->display->display_options['block_description'] = 'Software Requirements (simple grid)';

  /* Display: Block: license */
  $handler = $view->new_display('block', 'Block: license', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Browse by Software License';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: License (field_application_license) */
  $handler->display->display_options['relationships']['field_application_license_tid']['id'] = 'field_application_license_tid';
  $handler->display->display_options['relationships']['field_application_license_tid']['table'] = 'field_data_field_application_license';
  $handler->display->display_options['relationships']['field_application_license_tid']['field'] = 'field_application_license_tid';
  $handler->display->display_options['relationships']['field_application_license_tid']['required'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_application_license_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['format_plural'] = 0;
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
  $handler->display->display_options['block_description'] = 'Software License (simple grid)';
  $export['clone_of_apps_browse_by_apps_pag'] = $view;

  $view = new view;
  $view->name = 'find_more_in_applications_';
  $view->description = 'List of applications from "Find More In" block with terms.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Find More In (Applications)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Find More In';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
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
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['tid']['title'] = 'Applications in %1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['add_table'] = 0;
  $handler->display->display_options['arguments']['tid']['require_value'] = 0;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments']['tid']['set_breadcrumb'] = 0;
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'cc/apps/tags/%';
  $export['find_more_in_applications_'] = $view;

  $view = new view;
  $view->name = 'related_apps_block';
  $view->description = 'List of applications related to a current one. Also contains list of terms linked to corresponding applications (separate view).';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Related Apps Block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related Apps';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['label'] = '"Find More In" Title';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = '<div class="cc-rel-apps-find-more-in-title">Find More In</div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['footer']['area']['tokenize'] = 0;
  /* Footer: Find More In (Terms) */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['ui_name'] = 'Find More In (Terms)';
  $handler->display->display_options['footer']['view']['label'] = 'Find More In';
  $handler->display->display_options['footer']['view']['empty'] = TRUE;
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'application_categories:block_1';
  $handler->display->display_options['footer']['view']['inherit_arguments'] = 1;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area_1']['id'] = 'area_1';
  $handler->display->display_options['footer']['area_1']['table'] = 'views';
  $handler->display->display_options['footer']['area_1']['field'] = 'area';
  $handler->display->display_options['footer']['area_1']['empty'] = TRUE;
  $handler->display->display_options['footer']['area_1']['content'] = ' <?php echo \'<div class="edit-content-button"><a href="/node/\'.arg(1).\'/edit#field-application-relapps-values" class="button">+ add related app</a> </div>\'; ?>';
  $handler->display->display_options['footer']['area_1']['format'] = 'php_code';
  $handler->display->display_options['footer']['area_1']['tokenize'] = 1;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = ' <?php echo \'<div class="relatedapp" style="display: none;"><a href="/node/\'.arg(1).\'/edit#field-application-relapps-values" class="button">+ add related app</a> </div><br/><br/>\'; ?>';
  $handler->display->display_options['empty']['area']['format'] = 'php_code';
  $handler->display->display_options['empty']['area']['tokenize'] = 1;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
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
  /* Field: Content: Who Created the Application? */
  $handler->display->display_options['fields']['field_application_creator']['id'] = 'field_application_creator';
  $handler->display->display_options['fields']['field_application_creator']['table'] = 'field_data_field_application_creator';
  $handler->display->display_options['fields']['field_application_creator']['field'] = 'field_application_creator';
  $handler->display->display_options['fields']['field_application_creator']['label'] = '';
  $handler->display->display_options['fields']['field_application_creator']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_creator']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_creator']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_creator']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_creator']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_creator']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_creator']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_creator']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_creator']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_creator']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_creator']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_creator']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_creator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_creator']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_creator']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_creator']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_creator']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_creator']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_application_creator']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_application_creator']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_application_creator']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_application_creator']['separator'] = '<br />';
  $handler->display->display_options['fields']['field_application_creator']['field_api_classes'] = 0;
  /* Field: Content: Short Description for Search Results */
  $handler->display->display_options['fields']['field_application_sdesc']['id'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['table'] = 'field_data_field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['field'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['label'] = '';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_sdesc']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['field_api_classes'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Related apps (field_application_relapps) */
  $handler->display->display_options['arguments']['field_application_relapps_nid']['id'] = 'field_application_relapps_nid';
  $handler->display->display_options['arguments']['field_application_relapps_nid']['table'] = 'field_data_field_application_relapps';
  $handler->display->display_options['arguments']['field_application_relapps_nid']['field'] = 'field_application_relapps_nid';
  $handler->display->display_options['arguments']['field_application_relapps_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_application_relapps_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_application_relapps_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_application_relapps_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_application_relapps_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_application_relapps_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_application_relapps_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_application_relapps_nid']['not'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
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
  /* Field: Content: Short Description for Search Results */
  $handler->display->display_options['fields']['field_application_sdesc']['id'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['table'] = 'field_data_field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['field'] = 'field_application_sdesc';
  $handler->display->display_options['fields']['field_application_sdesc']['label'] = '';
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application_sdesc']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_application_sdesc']['field_api_classes'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  $export['related_apps_block'] = $view;

  return $export;
}
