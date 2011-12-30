<?php
/**
 * @file
 * Admin settings for CC API.
 */

/**
 * Page callback for admin settings.
 */
function cc_api_admin_settings($form, &$form_state) {
  $form = array();
  
  // Get node types
  $node_types = node_type_get_types();
  $options = array();
  $defaults = array('application', 'interaction', 'organization');
  foreach ($node_types as $type_id => $node_type) {
    $options[$type_id] = $node_type->name;
  }
  
  // Create form
  $form['cc_api_doc_page_title'] = array(
    '#type' => 'textfield',
    '#title' => t('API Documentation Page Title'),
    '#default_value' => variable_get('cc_api_doc_page_title', t('Marketplace API')),
    '#description' => t('The title of the page of the documentation.'),
  );
  $form['cc_api_doc_page_path'] = array(
    '#type' => 'textfield',
    '#title' => t('API Documentation Path'),
    '#default_value' => variable_get('cc_api_doc_page_path', 'api'),
    '#description' => t('The path to the API documentation.  This should be a Drupal path, which means to trailing or leading slashes, something like <em>developers</em> or <em>example/api</em>.  If you change this you will have to <strong>Clear the menu cache</strong>.'),
  );
  $form['cc_api_doc_page_data_model_content_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('API Documentation Page Content Types'),
    '#options' => $options,
    '#default_value' => variable_get('cc_api_doc_page_data_model_content_types', $defaults),
    '#description' => t('Determine which content types will show up on the API page.  This does not affect the API access, just what the user sees in the documentation section.  Leaving all of them blank will default to showing all content types.'),
  );
  
  return system_settings_form($form);
}