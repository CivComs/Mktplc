<?php
/**
 * @file
 * engagement_commons.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function engagement_commons_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'engagement_commons_page';
  $view->description = 'Provides views for engagement commons.';
  $view->tag = 'engagement_commons';
  $view->base_table = 'node';
  $view->human_name = 'Engagement Commons Views';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Engagement Commons';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'nothing' => 'nothing',
    'title' => 'title',
    'field_story_apps' => 'field_story_apps',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  /* Field: Content: Story Image */
  $handler->display->display_options['fields']['field_story_image']['id'] = 'field_story_image';
  $handler->display->display_options['fields']['field_story_image']['table'] = 'field_data_field_story_image';
  $handler->display->display_options['fields']['field_story_image']['field'] = 'field_story_image';
  $handler->display->display_options['fields']['field_story_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_story_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_story_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_story_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_story_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_story_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_story_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_story_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_story_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_story_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_story_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_story_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_story_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_story_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_story_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_story_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_story_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_image']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_story_image']['field_api_classes'] = 0;
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
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'by';
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
  $handler->display->display_options['fields']['name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'story' => 'story',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Story Category (field_story_civic_function) */
  $handler->display->display_options['filters']['field_story_civic_function_tid']['id'] = 'field_story_civic_function_tid';
  $handler->display->display_options['filters']['field_story_civic_function_tid']['table'] = 'field_data_field_story_civic_function';
  $handler->display->display_options['filters']['field_story_civic_function_tid']['field'] = 'field_story_civic_function_tid';
  $handler->display->display_options['filters']['field_story_civic_function_tid']['value'] = array(
    426 => '426',
  );
  $handler->display->display_options['filters']['field_story_civic_function_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_story_civic_function_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_story_civic_function_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_story_civic_function_tid']['vocabulary'] = 'civic_function';

  /* Display: EC Recent Stories (Page) */
  $handler = $view->new_display('page', 'EC Recent Stories (Page)', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Recent Stories Title';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<h2 class="block-title">Recent Stories</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['path'] = 'engagement-commons';

  /* Display: EC Featured Slidehow */
  $handler = $view->new_display('block', 'EC Featured Slidehow', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['row_class'] = 'engagement-commons-slide-row';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 0,
    'field_featured_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['hide_on_single_slide'] = 1;
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 0,
    'field_featured_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['effect'] = 'scrollRight';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'nothing' => 'nothing',
    'title' => 'title',
    'field_story_apps' => 'field_story_apps',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Featured story';
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
  /* Field: Content: Apps references */
  $handler->display->display_options['fields']['field_story_apps']['id'] = 'field_story_apps';
  $handler->display->display_options['fields']['field_story_apps']['table'] = 'field_data_field_story_apps';
  $handler->display->display_options['fields']['field_story_apps']['field'] = 'field_story_apps';
  $handler->display->display_options['fields']['field_story_apps']['label'] = 'utilizing ';
  $handler->display->display_options['fields']['field_story_apps']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_story_apps']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_story_apps']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_story_apps']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_story_apps']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_story_apps']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_story_apps']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_story_apps']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_story_apps']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_story_apps']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_story_apps']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_story_apps']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_story_apps']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_story_apps']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_story_apps']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_story_apps']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_story_apps']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_story_apps']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_story_apps']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_story_apps']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_story_apps']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_story_apps']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_story_apps']['field_api_classes'] = 0;
  /* Field: Content: Featured Image */
  $handler->display->display_options['fields']['field_featured_image']['id'] = 'field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['table'] = 'field_data_field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['field'] = 'field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['label'] = '';
  $handler->display->display_options['fields']['field_featured_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_featured_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_featured_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_featured_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_featured_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_featured_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_featured_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_featured_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_featured_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_featured_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_featured_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_featured_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_featured_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_featured_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_featured_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_featured_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_featured_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_featured_image']['settings'] = array(
    'image_style' => 'engagement_commons_feature',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_featured_image']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'story' => 'story',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Featured Image (field_featured_image:fid) */
  $handler->display->display_options['filters']['field_featured_image_fid']['id'] = 'field_featured_image_fid';
  $handler->display->display_options['filters']['field_featured_image_fid']['table'] = 'field_data_field_featured_image';
  $handler->display->display_options['filters']['field_featured_image_fid']['field'] = 'field_featured_image_fid';
  $handler->display->display_options['filters']['field_featured_image_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_featured_image_fid']['group'] = 1;
  /* Filter criterion: Content: Story Category (field_story_civic_function) */
  $handler->display->display_options['filters']['field_story_civic_function_tid']['id'] = 'field_story_civic_function_tid';
  $handler->display->display_options['filters']['field_story_civic_function_tid']['table'] = 'field_data_field_story_civic_function';
  $handler->display->display_options['filters']['field_story_civic_function_tid']['field'] = 'field_story_civic_function_tid';
  $handler->display->display_options['filters']['field_story_civic_function_tid']['value'] = array(
    426 => '426',
  );
  $handler->display->display_options['filters']['field_story_civic_function_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_story_civic_function_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_story_civic_function_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_story_civic_function_tid']['vocabulary'] = 'civic_function';

  /* Display: EC Trending Apps */
  $handler = $view->new_display('block', 'EC Trending Apps', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Trending Apps';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
  $handler->display->display_options['fields']['field_application_logo']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_application_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_application_logo']['settings'] = array(
    'image_style' => 'dashboard_app_logo-52x54',
    'image_link' => 'content',
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content statistics: Total views */
  $handler->display->display_options['sorts']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['sorts']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['sorts']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'application' => 'application',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Civic Function (field_application_civfunction) */
  $handler->display->display_options['filters']['field_application_civfunction_tid']['id'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['field'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['value'] = array(
    0 => '426',
  );
  $handler->display->display_options['filters']['field_application_civfunction_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['vocabulary'] = 'civic_function';
  $export['engagement_commons_page'] = $view;

  return $export;
}
