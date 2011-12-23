<?php
/**
 * @file
 * cc_organization.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function cc_organization_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organization_contact|node|organization|form';
  $field_group->group_name = 'group_organization_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organization';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_organization_main';
  $field_group->data = array(
    'label' => 'Contact Info',
    'weight' => '8',
    'children' => array(),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_organization_contact|node|organization|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organization_info|node|organization|form';
  $field_group->group_name = 'group_organization_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organization';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_organization_main';
  $field_group->data = array(
    'label' => 'Basic Info',
    'weight' => '4',
    'children' => array(
      0 => 'field_organization_decs',
      1 => 'field_organization_type',
      2 => 'field_organization_address',
      3 => 'field_organization_logo',
      4 => 'field_organization_link',
      5 => 'field_organization_abbr',
      6 => 'field_organization',
      7 => 'field_organization_phone',
      8 => 'field_organization_coords',
      9 => 'title',
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
  $export['group_organization_info|node|organization|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organization_main|node|organization|form';
  $field_group->group_name = 'group_organization_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organization';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '0',
    'children' => array(
      0 => 'group_organization_contact',
      1 => 'group_organization_info',
      2 => 'group_organization_misc',
      3 => 'group_organization_relationships',
      4 => 'group_organization_stats',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_organization_main|node|organization|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organization_misc|node|organization|form';
  $field_group->group_name = 'group_organization_misc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organization';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_organization_main';
  $field_group->data = array(
    'label' => 'Misc',
    'weight' => '7',
    'children' => array(),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Misc',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_organization_misc|node|organization|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organization_relationships|node|organization|form';
  $field_group->group_name = 'group_organization_relationships';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organization';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_organization_main';
  $field_group->data = array(
    'label' => 'Apps & Services',
    'weight' => '5',
    'children' => array(
      0 => 'field_organization_interactions',
      1 => 'field_organization_services',
      2 => 'field_organization_apps_created',
      3 => 'field_vending_apps',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Apps & Services',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_organization_relationships|node|organization|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organization_stats|node|organization|form';
  $field_group->group_name = 'group_organization_stats';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organization';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_organization_main';
  $field_group->data = array(
    'label' => 'Facts and Stats',
    'weight' => '6',
    'children' => array(
      0 => 'field_organization_wiki',
      1 => 'field_organization_abudget',
      2 => 'field_organization_employees',
      3 => 'field_organization_pbudget',
      4 => 'field_organization_members',
      5 => 'field_organization_branch',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Facts and Stats',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_organization_stats|node|organization|form'] = $field_group;

  return $export;
}
