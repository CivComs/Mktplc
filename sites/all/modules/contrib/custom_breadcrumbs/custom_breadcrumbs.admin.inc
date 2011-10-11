<?php
// $Id: custom_breadcrumbs.admin.inc,v 1.3.2.2 2011/01/09 00:44:53 mgn Exp $

/**
 * @file
 * Admin page callback file for the custom_breadcrumbs module.
 */

/**
 * Lists all current custom breadcrumbs, and provides a link to the edit page.
 */
function custom_breadcrumbs_page() {
  $breadcrumbs = _custom_breadcrumbs_load_all_breadcrumbs(TRUE);

  $header = array(t('Node type'), '');

  $rows = array();
  foreach ($breadcrumbs as $breadcrumb) {
    $row = array();
    $row[] = $breadcrumb->node_type . (!empty($breadcrumb->visibility_php) ? ' ' . t('with PHP snippet') : '');
    $row[] = l(t('edit'), 'admin/structure/custom_breadcrumbs/edit/' . $breadcrumb->bid);
    $rows[] = $row;
  }
  if (count($rows) == 0) {
    $rows[] = array(array('data' => t('No custom breadcrumbs have been defined.'), 'colspan' => 2));
  }

  $rows[] = array(array('data' => l(t('Add a new custom breadcrumb'), 'admin/structure/custom_breadcrumbs/add'), 'colspan' => 2));

  $build = array();
  $build['breadcrumb_table'] = array('#markup' => theme('table', array('header' => $header, 'rows' => $rows)));

  return $build;
}

/**
 * Displays an edit form for a custom breadcrumb record.
 */
function custom_breadcrumbs_form($form, &$form_state) {
  $bid = arg(4);
  if (isset($bid)) {
    $breadcrumb = _custom_breadcrumbs_load_breadcrumb($bid);
    $form['bid'] = array(
      '#type' => 'hidden',
      '#value' => $bid,
    );
  }

  $options = array();
  $types = node_type_get_names();
  foreach ($types as $type => $name) {
    $options[$type] = $name;
  }

  $form['node_type'] = array(
    '#type' => 'select',
    '#title' => t('Node type'),
    '#required' => TRUE,
    '#options' => $options,
    '#description' => t('The node type this custom breadcrumb trail will apply to.'),
    '#default_value' => isset($breadcrumb->node_type) ? $breadcrumb->node_type : NULL,
  );

  $form['visibility_php'] = array(
    '#type' => 'textarea',
    '#title' => t('Breadcrumb visibility'),
    '#access' => user_access('use php in custom breadcrumbs'),
    '#description' => t('Determine whether this breadcrumb should be displayed by using a snippet of PHP to return TRUE or FALSE. Note that this code has access to the $node variable, and can check its type or any other property.'),
    '#default_value' => isset($breadcrumb->visibility_php) ? $breadcrumb->visibility_php : '',
  );

  $form['titles'] = array(
    '#type' => 'textarea',
    '#title' => t('Titles'),
    '#required' => TRUE,
    '#description' => t('A list of titles for the breadcrumb links, one on each line.'),
    '#default_value' => isset($breadcrumb->titles) ? $breadcrumb->titles : NULL,
  );

  $form['paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Paths'),
    '#required' => TRUE,
    '#description' => t('A list of Drupal paths for the breadcrumb links, one on each line.'),
    '#default_value' => isset($breadcrumb->paths) ? $breadcrumb->paths : NULL,
  );

  if (module_exists('token')) {
    $form['help'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#title' => t('Placeholder tokens'),
      '#description' => t("The following placeholder tokens can be used in both paths and titles. When used in a path or title, they will be replaced with the appropriate values."),
    );

    $form['help']['tokens'] = array(
      '#markup' => theme('token_tree', array('token_types' => 'all', 'click_insert' => FALSE)),
    );
  }
  $form['help2'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Special identifiers'),
    '#description' => t("The following identifiers can be used to achieve a special behavior. Identifiers should be added to the paths area in the following format:  identifier|path.<br />For example: %pathauto_id|[ogname-raw]", array('%pathauto_id' => '<pathauto>')),
  );
  $form['help2']['tokens'] = array('#markup' => theme('custom_breadcrumbs_help_identifiers'));

  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  if ($bid) {
    $form['buttons']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('custom_breadcrumbs_form_delete'),
    );
  }

  return $form;
}

function custom_breadcrumbs_form_validate($form, &$form_state) {
  $path_count = count(explode("\n", trim($form_state['values']['paths'])));
  $title_count = count(explode("\n", trim($form_state['values']['titles'])));
  if ($title_count != $path_count) {
    $error_field = ($title_count < $path_count) ? 'titles' : 'paths';
    form_set_error($error_field, t('Every link path must have a matching title. There are !paths paths, and !titles titles.', array('!paths' => $path_count, '!titles' => $title_count)));
  }
}

function custom_breadcrumbs_form_submit($form, &$form_state) {
  $breadcrumb = (object)$form_state['values'];
  custom_breadcrumbs_save_breadcrumb($breadcrumb);
  $form_state['redirect'] = 'admin/structure/custom_breadcrumbs';
}

function custom_breadcrumbs_form_delete($form, &$form_state) {
  _custom_breadcrumbs_delete_breadcrumb($form_state['values']['bid']);
  $form_state['redirect'] = 'admin/structure/custom_breadcrumbs';
}
