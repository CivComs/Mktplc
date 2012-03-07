<?php
/**
 * @file
 * cc_stories.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function cc_stories_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_story_basics|node|story|form';
  $field_group->group_name = 'group_story_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'story';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_story_content';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_story_apps',
      2 => 'field_story_orgs',
      3 => 'field_story_civic_function',
      4 => 'title',
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
  $export['group_story_basics|node|story|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_story_content|node|story|form';
  $field_group->group_name = 'group_story_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'story';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_story_basics',
      1 => 'group_story_images',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_story_content|node|story|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_story_images|node|story|form';
  $field_group->group_name = 'group_story_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'story';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_story_content';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '3',
    'children' => array(
      0 => 'field_story_image',
      1 => 'field_featured_image',
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
  $export['group_story_images|node|story|form'] = $field_group;

  return $export;
}
