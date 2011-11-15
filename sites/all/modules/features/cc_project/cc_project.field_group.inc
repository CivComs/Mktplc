<?php
/**
 * @file
 * cc_project.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function cc_project_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_applications|node|project|form';
  $field_group->group_name = 'group_project_applications';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_project_main';
  $field_group->data = array(
    'label' => 'Related Apps',
    'weight' => '44',
    'children' => array(
      0 => 'field_apps_used',
      1 => 'field_apps_result',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Related Apps',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_project_applications|node|project|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_basic|node|project|form';
  $field_group->group_name = 'group_project_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_project_main';
  $field_group->data = array(
    'label' => 'Basic info',
    'weight' => '43',
    'children' => array(
      0 => 'field_description',
      1 => 'field_project_url',
      2 => 'field_date',
      3 => 'field_desc',
      4 => 'field_creators',
      5 => 'field_status',
      6 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_project_basic|node|project|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_categories|node|project|form';
  $field_group->group_name = 'group_project_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_project_main';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '46',
    'children' => array(
      0 => 'field_function',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_project_categories|node|project|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_main|node|project|form';
  $field_group->group_name = 'group_project_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '0',
    'children' => array(
      0 => 'group_project_applications',
      1 => 'group_project_media',
      2 => 'group_project_basic',
      3 => 'group_project_categories',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_project_main|node|project|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_media|node|project|form';
  $field_group->group_name = 'group_project_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_project_main';
  $field_group->data = array(
    'label' => 'Screenshots & Videos',
    'weight' => '45',
    'children' => array(
      0 => 'field_screenshots',
      1 => 'field_videos',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_project_media|node|project|form'] = $field_group;

  return $export;
}
