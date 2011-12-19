<?php
/**
 * @file
 * cc_taxonomy.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function cc_taxonomy_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'taxonomy_term_listing';
  $view->description = 'A view to emulate Drupal core\'s handling of taxonomy/term.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Taxonomy term listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'apps-list';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_organization_logo']['id'] = 'field_organization_logo';
  $handler->display->display_options['fields']['field_organization_logo']['table'] = 'field_data_field_organization_logo';
  $handler->display->display_options['fields']['field_organization_logo']['field'] = 'field_organization_logo';
  $handler->display->display_options['fields']['field_organization_logo']['label'] = '';
  $handler->display->display_options['fields']['field_organization_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_organization_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_organization_logo']['field_api_classes'] = 0;
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
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title_enable'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = 1;
  /* Contextual filter: Content: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['exception']['title_enable'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['specify_validation'] = 1;
  /* Contextual filter: Content: Updated date */
  $handler->display->display_options['arguments']['changed_fulldate']['id'] = 'changed_fulldate';
  $handler->display->display_options['arguments']['changed_fulldate']['table'] = 'node';
  $handler->display->display_options['arguments']['changed_fulldate']['field'] = 'changed_fulldate';
  $handler->display->display_options['arguments']['changed_fulldate']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['changed_fulldate']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['changed_fulldate']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['changed_fulldate']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['changed_fulldate']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'type' => 'type',
    'changed' => 'changed',
    'php' => 'php',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_organization_logo']['id'] = 'field_organization_logo';
  $handler->display->display_options['fields']['field_organization_logo']['table'] = 'field_data_field_organization_logo';
  $handler->display->display_options['fields']['field_organization_logo']['field'] = 'field_organization_logo';
  $handler->display->display_options['fields']['field_organization_logo']['label'] = '';
  $handler->display->display_options['fields']['field_organization_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_organization_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_organization_logo']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['field_organization_decs']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_decs']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_decs']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_decs']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_decs']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_decs']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_organization_decs']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['field_organization_decs']['field_api_classes'] = 0;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
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
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
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
  $handler->display->display_options['fields']['changed']['date_format'] = 'cc_date_short';
  $handler->display->display_options['path'] = 'taxonomy/term/%';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 15;
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'taxonomy/term/%/%/feed';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['taxonomy_term_listing'] = $view;

  return $export;
}
