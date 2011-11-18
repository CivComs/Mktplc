<?php
/**
 * @file
 * cc_project.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function cc_project_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'projects';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Projects';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = 'A "Project" is a website or initiative that is created by using one or more "Apps".  For instance, <a href="http://apps.civiccommons.org/projects/nysenate-gov" target="_blank">NYsenate.gov</a> is a "project", and <a href="http://apps.civiccommons.org/apps/drupal" target="_blank">Drupal</a> is an "app" -- a piece of software that was used as part of that project.  If this proves to be confusing, we\'ll change it! :)';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = '<div class="edit-content-button"><a href="/node/[nid]/edit">+ edit details</a></div>';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['footer']['area']['tokenize'] = 0;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_project_url']['id'] = 'field_project_url';
  $handler->display->display_options['fields']['field_project_url']['table'] = 'field_data_field_project_url';
  $handler->display->display_options['fields']['field_project_url']['field'] = 'field_project_url';
  $handler->display->display_options['fields']['field_project_url']['label'] = '';
  $handler->display->display_options['fields']['field_project_url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_url']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_url']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_url']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_project_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_project_url']['field_api_classes'] = 0;
  /* Field: Content: Date Created */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Created';
  $handler->display->display_options['fields']['field_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_date']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'custom_1',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_date']['field_api_classes'] = 0;
  /* Field: Content: Creator(s) */
  $handler->display->display_options['fields']['field_creators']['id'] = 'field_creators';
  $handler->display->display_options['fields']['field_creators']['table'] = 'field_data_field_creators';
  $handler->display->display_options['fields']['field_creators']['field'] = 'field_creators';
  $handler->display->display_options['fields']['field_creators']['label'] = 'Created by';
  $handler->display->display_options['fields']['field_creators']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_creators']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_creators']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_creators']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_creators']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_creators']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_creators']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_creators']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_creators']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_creators']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_creators']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_creators']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_creators']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_creators']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_creators']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_creators']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_creators']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_creators']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_creators']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_creators']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_creators']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_creators']['field_api_classes'] = 0;
  /* Field: Content: Apps used */
  $handler->display->display_options['fields']['field_apps_used']['id'] = 'field_apps_used';
  $handler->display->display_options['fields']['field_apps_used']['table'] = 'field_data_field_apps_used';
  $handler->display->display_options['fields']['field_apps_used']['field'] = 'field_apps_used';
  $handler->display->display_options['fields']['field_apps_used']['label'] = 'Using';
  $handler->display->display_options['fields']['field_apps_used']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_apps_used']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_apps_used']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_apps_used']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_apps_used']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_apps_used']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_apps_used']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_apps_used']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_apps_used']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_apps_used']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_apps_used']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_apps_used']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_apps_used']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_apps_used']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_apps_used']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_apps_used']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_apps_used']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_apps_used']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_apps_used']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_apps_used']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_apps_used']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_apps_used']['field_api_classes'] = 0;
  /* Field: Content: Civic function */
  $handler->display->display_options['fields']['field_function']['id'] = 'field_function';
  $handler->display->display_options['fields']['field_function']['table'] = 'field_data_field_function';
  $handler->display->display_options['fields']['field_function']['field'] = 'field_function';
  $handler->display->display_options['fields']['field_function']['label'] = 'Tags';
  $handler->display->display_options['fields']['field_function']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_function']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_function']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_function']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_function']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_function']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_function']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_function']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_function']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_function']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_function']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_function']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_function']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_function']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_function']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_function']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_function']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_function']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_function']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_function']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_function']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_function']['separator'] = ' ';
  $handler->display->display_options['fields']['field_function']['field_api_classes'] = 0;
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
    'project' => 'project',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'projects';

  /* Display: At a glance */
  $handler = $view->new_display('block', 'At a glance', 'block_1');
  $export['projects'] = $view;

  $view = new view;
  $view->name = 'projects_use_this_app';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'projects use this app';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'projects use this app';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Apps used (field_apps_used) */
  $handler->display->display_options['relationships']['field_apps_used_nid']['id'] = 'field_apps_used_nid';
  $handler->display->display_options['relationships']['field_apps_used_nid']['table'] = 'field_data_field_apps_used';
  $handler->display->display_options['relationships']['field_apps_used_nid']['field'] = 'field_apps_used_nid';
  $handler->display->display_options['relationships']['field_apps_used_nid']['required'] = 1;
  $handler->display->display_options['relationships']['field_apps_used_nid']['delta'] = '-1';
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
  /* Contextual filter: Content: Apps used (field_apps_used) */
  $handler->display->display_options['arguments']['field_apps_used_nid']['id'] = 'field_apps_used_nid';
  $handler->display->display_options['arguments']['field_apps_used_nid']['table'] = 'field_data_field_apps_used';
  $handler->display->display_options['arguments']['field_apps_used_nid']['field'] = 'field_apps_used_nid';
  $handler->display->display_options['arguments']['field_apps_used_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_apps_used_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_apps_used_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_apps_used_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_apps_used_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_apps_used_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_apps_used_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_apps_used_nid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['projects_use_this_app'] = $view;

  return $export;
}
