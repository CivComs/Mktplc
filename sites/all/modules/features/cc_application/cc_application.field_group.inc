<?php
/**
 * @file
 * cc_application.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function cc_application_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_media|node|application|default';
  $field_group->group_name = 'group_app_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Photos and Videos',
    'weight' => '2',
    'children' => array(
      0 => 'field_application_demourl',
      1 => 'group_app_screenshots',
      2 => 'group_app_tutorials',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Photos and Videos',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_app_media|node|application|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_screenshots|node|application|default';
  $field_group->group_name = 'group_app_screenshots';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_app_media';
  $field_group->data = array(
    'label' => 'Screenshots',
    'weight' => '9',
    'children' => array(
      0 => 'field_application_screenshots',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Screenshots',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_app_screenshots|node|application|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_tutorials|node|application|default';
  $field_group->group_name = 'group_app_tutorials';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_app_media';
  $field_group->data = array(
    'label' => 'Tutorials',
    'weight' => '10',
    'children' => array(
      0 => 'field_application_tutors',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Tutorials',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_app_tutorials|node|application|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_application_basic|node|application|form';
  $field_group->group_name = 'group_application_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_application_main';
  $field_group->data = array(
    'label' => 'Basic Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_application_sdesc',
      1 => 'field_application_logo',
      2 => 'field_application_creator',
      3 => 'field_application_description',
      4 => 'field_application_civfunction',
      5 => 'field_application_homepage',
      6 => 'field_application_tags',
      7 => 'title',
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
  $export['group_application_basic|node|application|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_application_categories|node|application|form';
  $field_group->group_name = 'group_application_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_application_main';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '5',
    'children' => array(
      0 => 'field_application_license',
      1 => 'field_application_deliverymeth',
      2 => 'field_application_softfunction',
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
  $export['group_application_categories|node|application|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_application_features|node|application|form';
  $field_group->group_name = 'group_application_features';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_application_main';
  $field_group->data = array(
    'label' => 'Features & Requirements',
    'weight' => '1',
    'children' => array(
      0 => 'field_application_rlss',
      1 => 'field_application_featurs',
      2 => 'field_application_reqs',
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
  $export['group_application_features|node|application|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_application_main|node|application|form';
  $field_group->group_name = 'group_application_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '0',
    'children' => array(
      0 => 'group_application_sfthosted',
      1 => 'group_application_categories',
      2 => 'group_application_basic',
      3 => 'group_application_media',
      4 => 'group_application_orgs',
      5 => 'group_application_relations',
      6 => 'group_application_features',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_application_main|node|application|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_application_media|node|application|form';
  $field_group->group_name = 'group_application_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_application_main';
  $field_group->data = array(
    'label' => 'Screenshots & Videos',
    'weight' => '2',
    'children' => array(
      0 => 'field_application_screenshots',
      1 => 'field_application_tutors',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Screenshots & Videos',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_application_media|node|application|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_application_misc|node|application|form';
  $field_group->group_name = 'group_application_misc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Misc',
    'weight' => '1',
    'children' => array(
      0 => 'field_application_type',
      1 => 'field_application_ss_id',
      2 => 'field_application_rating',
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
  $export['group_application_misc|node|application|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_application_orgs|node|application|form';
  $field_group->group_name = 'group_application_orgs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_application_main';
  $field_group->data = array(
    'label' => 'Deployment & Support',
    'weight' => '3',
    'children' => array(
      0 => 'field_application_vendors',
      1 => 'field_application_interactions',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Deployment & Support',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_application_orgs|node|application|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_application_relations|node|application|form';
  $field_group->group_name = 'group_application_relations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_application_main';
  $field_group->data = array(
    'label' => 'Related Technologies',
    'weight' => '4',
    'children' => array(
      0 => 'field_application_relapps',
      1 => 'field_application_projects',
      2 => 'field_project_resulted',
      3 => 'field_application_stds',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Related Technologies',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_application_relations|node|application|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_application_sfthosted|node|application|form';
  $field_group->group_name = 'group_application_sfthosted';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_application_main';
  $field_group->data = array(
    'label' => 'Code Repo & Demo Hosting (If Applicable)',
    'weight' => '6',
    'children' => array(
      0 => 'field_application_hostname',
      1 => 'field_application_hosturl',
      2 => 'field_application_demourl',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Code Repo & Demo Hosting (If Applicable)',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_application_sfthosted|node|application|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_info|node|application|default';
  $field_group->group_name = 'group_basic_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'application';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic info',
    'weight' => '0',
    'children' => array(
      0 => 'field_application_logo',
      1 => 'field_application_description',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basic info',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_basic_info|node|application|default'] = $field_group;

  return $export;
}
