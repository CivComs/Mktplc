<?php
/**
 * @file
 * cc_interaction.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function cc_interaction_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interaction_details|node|interaction|form';
  $field_group->group_name = 'group_interaction_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'interaction';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_interaction_main';
  $field_group->data = array(
    'label' => 'Interaction: Who did What?',
    'weight' => '2',
    'children' => array(
      0 => 'field_interaction_organization',
      1 => 'field_interaction_application',
      2 => 'field_interaction_type',
      3 => 'field_interaction_date',
      4 => 'field_url',
      5 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Interaction: Who did What?',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '<big>A Marketplace Interaction captures which Organizations did what, with what.</big> <br /> For example : <em> "New York City Department of Information Technology and Telecommunications deployed Accela"</em><br /><br /><br />',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_interaction_details|node|interaction|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interaction_info|node|interaction|form';
  $field_group->group_name = 'group_interaction_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'interaction';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_interaction_main';
  $field_group->data = array(
    'label' => 'Skip this',
    'weight' => '3',
    'children' => array(
      0 => 'field_interaction_project',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Skip this',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_interaction_info|node|interaction|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interaction_main|node|interaction|form';
  $field_group->group_name = 'group_interaction_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'interaction';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '0',
    'children' => array(
      0 => 'group_interaction_details',
      1 => 'group_interaction_info',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_interaction_main|node|interaction|form'] = $field_group;

  return $export;
}
