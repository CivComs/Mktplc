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
  
  return system_settings_form($form);
}