<?php
/**
 * @file
 * cc_api_views.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function cc_api_views_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'application_api';
  $view->description = 'Provides a view of Application nodes specifically for the public API.';
  $view->tag = 'api';
  $view->base_table = 'node';
  $view->human_name = 'Application API';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Application API';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
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
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search Terms';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keywords';
  $handler->display->display_options['filters']['keys']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Civic Function (field_application_civfunction) */
  $handler->display->display_options['filters']['field_application_civfunction_tid']['id'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['table'] = 'field_data_field_application_civfunction';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['field'] = 'field_application_civfunction_tid';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['operator_id'] = 'field_application_civfunction_tid_op';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['label'] = 'Civic Function (Taxonomy Term ID)';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['operator'] = 'field_application_civfunction_tid_op';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['identifier'] = 'civicfunction';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_application_civfunction_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['vocabulary'] = 'civic_function';
  $handler->display->display_options['filters']['field_application_civfunction_tid']['error_message'] = 1;
  /* Filter criterion: Content: License (field_application_license) */
  $handler->display->display_options['filters']['field_application_license_tid']['id'] = 'field_application_license_tid';
  $handler->display->display_options['filters']['field_application_license_tid']['table'] = 'field_data_field_application_license';
  $handler->display->display_options['filters']['field_application_license_tid']['field'] = 'field_application_license_tid';
  $handler->display->display_options['filters']['field_application_license_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_application_license_tid']['expose']['operator_id'] = 'field_application_license_tid_op';
  $handler->display->display_options['filters']['field_application_license_tid']['expose']['label'] = 'License (Taxonomy Term ID)';
  $handler->display->display_options['filters']['field_application_license_tid']['expose']['operator'] = 'field_application_license_tid_op';
  $handler->display->display_options['filters']['field_application_license_tid']['expose']['identifier'] = 'application_license';
  $handler->display->display_options['filters']['field_application_license_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_application_license_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_application_license_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_application_license_tid']['vocabulary'] = 'software_licenses';
  $handler->display->display_options['filters']['field_application_license_tid']['error_message'] = 1;
  /* Filter criterion: Content: Key features (field_application_featurs) */
  $handler->display->display_options['filters']['field_application_featurs_value']['id'] = 'field_application_featurs_value';
  $handler->display->display_options['filters']['field_application_featurs_value']['table'] = 'field_data_field_application_featurs';
  $handler->display->display_options['filters']['field_application_featurs_value']['field'] = 'field_application_featurs_value';
  $handler->display->display_options['filters']['field_application_featurs_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_application_featurs_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_application_featurs_value']['expose']['operator_id'] = 'field_application_featurs_value_op';
  $handler->display->display_options['filters']['field_application_featurs_value']['expose']['label'] = 'Key Features (String)';
  $handler->display->display_options['filters']['field_application_featurs_value']['expose']['operator'] = 'field_application_featurs_value_op';
  $handler->display->display_options['filters']['field_application_featurs_value']['expose']['identifier'] = 'key_features';
  $handler->display->display_options['filters']['field_application_featurs_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_application_featurs_value']['expose']['multiple'] = FALSE;

  /* Display: Field View */
  $handler = $view->new_display('page', 'Field View', 'field_view');
  $handler->display->display_options['display_description'] = 'Field view of Applications.  Use this display for simple objects.';
  $handler->display->display_options['path'] = 'api/views/render/application_api';

  /* Display: Node View */
  $handler = $view->new_display('page', 'Node View', 'node_view');
  $handler->display->display_options['display_description'] = 'Provides same as Field View but renders full node object.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'api/views/render/application_api/full';
  $export['application_api'] = $view;

  $view = new view;
  $view->name = 'interaction_api';
  $view->description = 'Provides a view of Interaction nodes specifically for the public API.';
  $view->tag = 'api';
  $view->base_table = 'node';
  $view->human_name = 'Interaction API';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Interaction API';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'default';
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
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Keyword Search (String)';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keywords';
  $handler->display->display_options['filters']['keys']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Did what (field_interaction_type) */
  $handler->display->display_options['filters']['field_interaction_type_tid']['id'] = 'field_interaction_type_tid';
  $handler->display->display_options['filters']['field_interaction_type_tid']['table'] = 'field_data_field_interaction_type';
  $handler->display->display_options['filters']['field_interaction_type_tid']['field'] = 'field_interaction_type_tid';
  $handler->display->display_options['filters']['field_interaction_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_interaction_type_tid']['expose']['operator_id'] = 'field_interaction_type_tid_op';
  $handler->display->display_options['filters']['field_interaction_type_tid']['expose']['label'] = 'Interaction Type (Taxonomy Term ID)';
  $handler->display->display_options['filters']['field_interaction_type_tid']['expose']['operator'] = 'field_interaction_type_tid_op';
  $handler->display->display_options['filters']['field_interaction_type_tid']['expose']['identifier'] = 'interaction_type';
  $handler->display->display_options['filters']['field_interaction_type_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_interaction_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_interaction_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_interaction_type_tid']['vocabulary'] = 'interaction_type';
  $handler->display->display_options['filters']['field_interaction_type_tid']['error_message'] = 1;
  /* Filter criterion: Content: Who (field_interaction_organization) */
  $handler->display->display_options['filters']['field_interaction_organization_nid']['id'] = 'field_interaction_organization_nid';
  $handler->display->display_options['filters']['field_interaction_organization_nid']['table'] = 'field_data_field_interaction_organization';
  $handler->display->display_options['filters']['field_interaction_organization_nid']['field'] = 'field_interaction_organization_nid';
  $handler->display->display_options['filters']['field_interaction_organization_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_interaction_organization_nid']['expose']['operator_id'] = 'field_interaction_organization_nid_op';
  $handler->display->display_options['filters']['field_interaction_organization_nid']['expose']['label'] = 'Organization (Node ID)';
  $handler->display->display_options['filters']['field_interaction_organization_nid']['expose']['operator'] = 'field_interaction_organization_nid_op';
  $handler->display->display_options['filters']['field_interaction_organization_nid']['expose']['identifier'] = 'organization';
  $handler->display->display_options['filters']['field_interaction_organization_nid']['expose']['reduce'] = 0;
  /* Filter criterion: Content: With what (field_interaction_application) */
  $handler->display->display_options['filters']['field_interaction_application_nid']['id'] = 'field_interaction_application_nid';
  $handler->display->display_options['filters']['field_interaction_application_nid']['table'] = 'field_data_field_interaction_application';
  $handler->display->display_options['filters']['field_interaction_application_nid']['field'] = 'field_interaction_application_nid';
  $handler->display->display_options['filters']['field_interaction_application_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_interaction_application_nid']['expose']['operator_id'] = 'field_interaction_application_nid_op';
  $handler->display->display_options['filters']['field_interaction_application_nid']['expose']['label'] = 'Application (Node ID)';
  $handler->display->display_options['filters']['field_interaction_application_nid']['expose']['operator'] = 'field_interaction_application_nid_op';
  $handler->display->display_options['filters']['field_interaction_application_nid']['expose']['identifier'] = 'application';
  $handler->display->display_options['filters']['field_interaction_application_nid']['expose']['reduce'] = 0;

  /* Display: Field View */
  $handler = $view->new_display('page', 'Field View', 'field_view');
  $handler->display->display_options['display_description'] = 'Interaction nodes output as simple fields.';
  $handler->display->display_options['path'] = 'api/views/render/interactions';

  /* Display: Node View */
  $handler = $view->new_display('page', 'Node View', 'node_view');
  $handler->display->display_options['display_description'] = 'Search interactions and output data as full nodes.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'api/views/render/interactions/full';
  $export['interaction_api'] = $view;

  $view = new view;
  $view->name = 'organization_api';
  $view->description = 'Provides a view of Organization nodes specifically for the public API.';
  $view->tag = 'api';
  $view->base_table = 'node';
  $view->human_name = 'Organization API';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Organization API';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'default';
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
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search Terms (String)';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keywords';
  $handler->display->display_options['filters']['keys']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Deployments, Evaluations and other interactions with apps (field_organization_interactions) */
  $handler->display->display_options['filters']['field_organization_interactions_nid']['id'] = 'field_organization_interactions_nid';
  $handler->display->display_options['filters']['field_organization_interactions_nid']['table'] = 'field_data_field_organization_interactions';
  $handler->display->display_options['filters']['field_organization_interactions_nid']['field'] = 'field_organization_interactions_nid';
  $handler->display->display_options['filters']['field_organization_interactions_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organization_interactions_nid']['expose']['operator_id'] = 'field_organization_interactions_nid_op';
  $handler->display->display_options['filters']['field_organization_interactions_nid']['expose']['label'] = 'Interaction (Node ID)';
  $handler->display->display_options['filters']['field_organization_interactions_nid']['expose']['operator'] = 'field_organization_interactions_nid_op';
  $handler->display->display_options['filters']['field_organization_interactions_nid']['expose']['identifier'] = 'interactions';
  $handler->display->display_options['filters']['field_organization_interactions_nid']['expose']['reduce'] = 0;
  /* Filter criterion: Content: for Vendors: What Application Services do they provide? (field_organization_services) */
  $handler->display->display_options['filters']['field_organization_services_tid']['id'] = 'field_organization_services_tid';
  $handler->display->display_options['filters']['field_organization_services_tid']['table'] = 'field_data_field_organization_services';
  $handler->display->display_options['filters']['field_organization_services_tid']['field'] = 'field_organization_services_tid';
  $handler->display->display_options['filters']['field_organization_services_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organization_services_tid']['expose']['operator_id'] = 'field_organization_services_tid_op';
  $handler->display->display_options['filters']['field_organization_services_tid']['expose']['label'] = 'Application Services (Taxonomy Term ID)';
  $handler->display->display_options['filters']['field_organization_services_tid']['expose']['operator'] = 'field_organization_services_tid_op';
  $handler->display->display_options['filters']['field_organization_services_tid']['expose']['identifier'] = 'services';
  $handler->display->display_options['filters']['field_organization_services_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_organization_services_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_organization_services_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_organization_services_tid']['vocabulary'] = 'app_services_provided';
  $handler->display->display_options['filters']['field_organization_services_tid']['error_message'] = 1;
  /* Filter criterion: Content: What kind of Organization is it? (field_organization_type) */
  $handler->display->display_options['filters']['field_organization_type_tid']['id'] = 'field_organization_type_tid';
  $handler->display->display_options['filters']['field_organization_type_tid']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['filters']['field_organization_type_tid']['field'] = 'field_organization_type_tid';
  $handler->display->display_options['filters']['field_organization_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organization_type_tid']['expose']['operator_id'] = 'field_organization_type_tid_op';
  $handler->display->display_options['filters']['field_organization_type_tid']['expose']['label'] = 'Kind of Organization? (Taxonomy Term ID)';
  $handler->display->display_options['filters']['field_organization_type_tid']['expose']['operator'] = 'field_organization_type_tid_op';
  $handler->display->display_options['filters']['field_organization_type_tid']['expose']['identifier'] = 'organization_type';
  $handler->display->display_options['filters']['field_organization_type_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_organization_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_organization_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_organization_type_tid']['vocabulary'] = 'organization_type';
  $handler->display->display_options['filters']['field_organization_type_tid']['error_message'] = 1;

  /* Display: Field View */
  $handler = $view->new_display('page', 'Field View', 'field_view');
  $handler->display->display_options['display_description'] = 'Organizations as simple fields.';
  $handler->display->display_options['path'] = 'api/views/render/organizations';

  /* Display: Node View */
  $handler = $view->new_display('page', 'Node View', 'node_view');
  $handler->display->display_options['display_description'] = 'Renders full node for searching Organizations.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'api/views/render/organizations/full';
  $export['organization_api'] = $view;

  return $export;
}
