<?php

/**
 * @file
 * Passes selected ids as arguments to a page.
 * The ids might be entity ids or revision ids, depending on the type of the
 * VBO field.
 */

/**
 * Implementation of hook_action_info().
 */
function views_bulk_operations_argument_selector_action_info() {
  return array(
    'views_bulk_operations_argument_selector_action' => array(
      'label' => t('Pass ids as arguments to a page'),
      'type' => 'entity',
      'aggregate' => TRUE,
      'configurable' => TRUE,
      'hooks' => array(),
    ),
  );
}

/**
* Implementation of a Drupal action.
* Passes selected ids as arguments to a view.
*/
function views_bulk_operations_argument_selector_action($entities, $context = array()) {
  $base_url = $context['url'];
  $arguments = implode(',', array_keys($entities));
  // Add a trailing slash if missing.
  if (substr($base_url, -1, 1) != '/') {
    $base_url .= '/';
  }
  drupal_goto($base_url . $arguments);
}

function views_bulk_operations_argument_selector_action_form($context) {
  $form['url'] = array(
    '#title' => t('URL'),
    '#type' => 'textfield',
    '#description' => t('Enter a URL that the user will be sent to.'),
    '#default_value' => @$context['url'],
    '#required' => TRUE,
  );
  return $form;
}

function views_bulk_operations_argument_selector_action_submit($form, $form_state) {
  return array('url' => $form_state['values']['url']);
}
