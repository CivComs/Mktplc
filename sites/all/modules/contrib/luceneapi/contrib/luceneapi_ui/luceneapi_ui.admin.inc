<?php

/**
 * @file
 *
 */

/**
 * Builds the part of the form that is displayed when a search page is being
 * added to the system.
 *
 * @see luceneapi_ui_settings_form()
 */
function luceneapi_ui_add_searcher_form($form, &$form_state) {

  // Initializes form with common settings.
  $form = luceneapi_ui_settings_form($form, $form_state, 'luceneapi_searcher');

  // Sets the descriptions and button text.
  $form['label']['#description'] = t('The human-readable name of the search page configuration.');
  $form['name']['#description'] = t('A unique machine-readable name for the search page configuration. It must only contain lowercase letters, numbers, and underscores.');
  $form['info']['description']['#description'] = t('The description of the search page configuration.');

  $form['info']['index_name'] = array(
    '#title' => t('Index'),
    '#type' => 'select',
    '#options' => luceneapi_ui_get_index_options(),
    '#description' => t('The index that is searched by this searcher.'),
    '#required' => TRUE,
    '#weight' => -30,
  );

  $form['#submit'][] = 'luceneapi_ui_add_searcher_form_submit';

  return $form;
}

/**
 * Builds the full search page settings form.
 *
 * @see luceneapi_ui_add_searcher_form()
 */
function luceneapi_ui_searcher_settings_form($form, &$form_state, LuceneapiSearcher $searcher) {

  // Initializes form with basic settings.
  $form = luceneapi_ui_add_searcher_form($form, $form_state);
  $form['#submit'] = array('luceneapi_ui_settings_form_submit');

  // Sets the searcher object as a form property.
  $form['#luceneapi']['searcher'] = $searcher;
  $form['#luceneapi']['index'] = $searcher->getIndex();

  // Adds default values to the basic option.
  $form['label']['#default_value'] = $searcher->getLabel();
  $form['name']['#default_value'] = $searcher->getName();
  $form['name']['#disabled'] = TRUE;
  $form['info']['index_name']['#default_value'] = $searcher->getSettings()->index_name;
  $form['info']['index_name']['#disabled'] = TRUE;
  $form['info']['description']['#default_value'] = $searcher->getDescription();

  // Adds other values that shouldn't be stored as settings.
  $form['#luceneapi']['excluded_values'] = array_merge(
    $form['#luceneapi']['excluded_values'],
    array('search_path', 'page_title',)
  );

  //
  // Vertical tabs
  //

  $form['settings'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => 10,
  );

  $form['info'] = array_merge($form['info'], array(
    '#type' => 'fieldset',
    '#title' => t('Information'),
    '#group' => 'settings',
    '#weight' => -50,
  ));

  $form['search_page'] = array(
    '#type' => 'fieldset',
    '#title' => t('Search page'),
    '#group' => 'settings',
    '#weight' => -40,
  );

  $form['search_form'] = array(
    '#type' => 'fieldset',
    '#title' => t('Search form'),
    '#group' => 'settings',
    '#weight' => -30,
  );

  /*
  $form['sort'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sortable fields'),
    '#group' => 'settings',
    '#weight' => -20,
  );
  */

  $form['bias'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content bias'),
    '#group' => 'settings',
    '#weight' => -10,
  );

  //
  // Search page
  //

  $form['search_page']['search_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path'),
    '#default_value' => $searcher->getSettings()->search_path,
    '#description' => t('The path to the search page.'),
    '#maxlength' => 255,
  );

  $form['search_page']['page_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $searcher->getSettings()->page_title,
    '#description' => t('The title of the search page.'),
    '#maxlength' => 255,
  );

  $form['search_page']['limit'] = array(
    '#type' => 'textfield',
    '#size' => 4,
    '#title' => t('Results per page'),
    '#default_value' => $searcher->getSetting('limit'),
    '#description' => t('Number of items that will be shown per search results page.'),
  );

  $form['search_page']['highlighter'] = array(
    '#type' => 'radios',
    '#title' => t('Highlighter'),
    '#default_value' => $searcher->getSetting('highlighter'),
    '#description' => t('The plugin that builds the search result snippet.'),
    '#options' => luceneapi_ui_get_registered_plugin_options(
      'highlighters', $form['#luceneapi']['index']
    )
  );

  //
  // Search form
  //

  $form['search_form']['form_prompt'] = array(
    '#type' => 'textfield',
    '#title' => t('Prompt'),
    '#default_value' => $searcher->getSetting('form_prompt'),
    '#description' => t('The search form label that prompts the user to enter keywords for the search.'),
    '#maxlength' => 255,
  );

  $form['search_form']['button_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Button text'),
    '#default_value' => $searcher->getSetting('button_text'),
    '#description' => t('The search form button text.'),
    '#maxlength' => 255,
  );

  //
  // Sortable fields
  //

  /*
  $form['sort']['sortable_fields'] = array(
    '#theme' => 'luceneapi_ui_sortable_fields_table',
    '#luceneapi' => &$form['#luceneapi'],
  );

  $form['sort']['sortable_fields']['sortable_fields'] = array(
    '#type' => 'checkboxes',
    '#options' => array(),
    '#default_value' => $searcher->getSetting('sortable_fields'),
  );

  $weights = $searcher->getSetting('sortable_fields_weight');
  foreach ($form['#luceneapi']['index']->getSortableFields() as $field_name => $field_info) {
    $form['sort']['sortable_fields']['sortable_fields']['#options'][$field_name] = '';
    $form['sort']['sortable_fields']['sortable_fields_weight:' . $field_name] = array(
      '#type' => 'select',
      '#options' => range(-50, 50),
      '#default_value' => isset($weights[$field_name]) ? $weights[$field_name] : 0,
      '#attributes' => array('class' => array('luceneapi-ui-sortable-fields-weight')),
    );
  }
  */

  //
  // Content bias
  //

  $form['bias']['bias_fields'] = array(
    '#theme' => 'luceneapi_ui_bias_fields_table',
    '#luceneapi' => &$form['#luceneapi'],
  );

  $bias_options = array(0 => t("Don't search")) + drupal_map_assoc(array(
    '21.0', '13.0', '8.0', '5.0', '3.0', '2.0', '1.0', '0.8', '0.5', '0.3', '0.2', '0.1'
  ));

  $bias = $searcher->getSetting('bias');
  foreach ($form['#luceneapi']['index']->getBiasFields() as $field_name => $field_info) {
    $form['bias']['bias_fields']['bias:' . $field_name] = array(
      '#type' => 'select',
      '#default_value' => isset($bias[$field_name]) ? $bias[$field_name] : 0,
      '#options' => $bias_options,
    );
  }

  //
  // Finalizes form
  //

  $form['#validate'][] = 'luceneapi_ui_searcher_form_validate';

  // Allows plugins to add form overrides, returns form.
  $index = $searcher->getIndex();
  $index->getIndexer()->searcherSettingsForm($form, $form_state, $searcher);
  $index->getBackend()->searcherSettingsForm($form, $form_state, $searcher);
  return $form;
}

/**
 *
 */
function theme_luceneapi_ui_bias_fields_table(array $variables) {
  $output = '';

  $header = array(
    'label' => array('data' => t('Field name')),
    'bias' => array('data' => t('Content bias'))
  );

  // Gets grouped fields.
  $groups = luceneapi_ui_get_field_groups(
    $variables['element']['#luceneapi']['index'], TRUE, 'luceneapi_filter_bias_field'
  );

  // Builds field options.
  $rows = array();
  foreach ($groups as $group_name => $group) {

    // Adds group header to table.
    $rows['__group:' . $group_name] = array(
      'data' => array(
        'indexed' => array(
          'colspan' => 2,
          'data' => '<strong>' . check_plain($group_name) . '</strong>',
        ),
      ),
    );

    // Sorts field by label, adds to table.
    uasort($group, 'luceneapi_ui_sort_label');
    foreach ($group as $field_name => $field_info) {
      $rows[$field_name] = array(
        'data' => array(
          'label' => array(
            'data' => check_plain($field_info['label']) . "<div class='description'>" . filter_xss($field_info['description']) . '</div>',
          ),
          'bias' => array(
            'data' => drupal_render($variables['element']['bias:' . $field_name]),
          ),
        ),
      );
    }
  }

  $output .= drupal_render_children($variables['element']);
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'luceneapi-ui-fields')));

  return $output;
}

/**
 * Validates searcher settings form.
 */
function luceneapi_ui_searcher_form_validate($form, &$form_state) {
  try {

    // Performs basic validation of the menu path.
    if (FALSE === ($url = parse_url($form_state['values']['search_path']))) {
      throw new Exception(t('Path not valid.'));
    }
    if (!empty($url['host'])) {
      throw new Exception(t('Path must be local.'));
    }
    if (empty($url['path'])) {
      throw new Exception(t('Path required.'));
    }
    if (0 === strpos($url['path'], '/')) {
      throw new Exception(t('Path cannot start with a forward slash.'));
    }

    // Parses query string into array of variables.
    $qstring = isset($url['query']) ? $url['query'] : '';
    parse_str($qstring, $vars);

    // Parses path, checks if %keys token is in the menu path or query string.
    $parts = explode('/', $url['path']);
    if (FALSE !== ($pos = array_search('%keys', $parts))) {
      // Validates position of %keys token.
      if (count($parts) != $pos + 1) {
        throw new Exception(t('The <em>keys</em> token must be the last item in the path.'));
      }
      elseif (!$pos) {
        throw new Exception(t('The <em>keys</em> token cannot be the only item in the path.'));
      }
    }
    else {
      // Attempts to extract %keys token from query string.
      if (FALSE === ($keys = array_search('%keys', $vars))) {
        throw new Exception(t('The <em>keys</em> token is required.'));
      }
    }

  }
  catch (Exception $e) {
    form_set_error('search_path', $e->getMessage());
  }
}

/**
 * Constructs the import for for search page configurations.
 *
 * @see luceneapi_ui_import_searcher_form()
 */
function luceneapi_ui_import_searcher_form($form, &$form_state) {
  $form = luceneapi_ui_import_form($form, $form_state, 'luceneapi_searcher');
  $form['#submit'][] = 'luceneapi_ui_import_searcher_form_submit';
  $form['#validate'][] = 'luceneapi_ui_import_searcher_form_validate';
  return $form;
}

/**
 * Validates luceneapi_ui_import_searcher_form form submissions.
 */
function luceneapi_ui_import_searcher_form_validate($form, &$form_state) {
  try {
    // Loads object, throws exception on any errors.
    ctools_include('export');
    $object = ctools_export_crud_import('luceneapi_searcher', $form_state['values']['code']);
    if (is_string($object)) {
      throw new Exception($object);
    }

    // Makes sure an object doesn't already exist.
    if (ctools_export_crud_load($form['#table'], $object->name)) {
      throw new Exception(t('Configuration options already exist with the same name.'));
    }

    // Sets the object variable.
    form_set_value($form['object'], $object, $form_state);

  }
  catch (Exception $e) {
    form_set_error('code', filter_xss_admin($e->getMessage()));
  }
}

/**
 * Rebuilds the menu after a searcher is imported.
 */
function luceneapi_ui_import_searcher_form_submit($form, &$form_state) {
  ctools_export_load_object_reset('luceneapi_searcher');
  menu_rebuild();
}

/**
 *
 */
function luceneapi_ui_import_form_submit($form, &$form_state) {
  ctools_include('export');
  if (FALSE !== ctools_export_crud_save($form['#table'], $form_state['values']['object'])) {
    drupal_set_message(t('The configuration options have been imported.'));
    $form_state['redirect'] = luceneapi_ui_calculate_settings_path($form['#table']);
  }
  else {
    drupal_set_message(t('Error importing configuration options.'), 'error');
  }
}

/**
 *
 */
function luceneapi_ui_add_index_form($form, &$form_state) {

  // Initializes form with common settings.
  $form = luceneapi_ui_settings_form($form, $form_state, 'luceneapi_index');

  // Sets the descriptions and button text.
  $form['label']['#description'] = t('The human-readable name of the index configuration.');
  $form['name']['#description'] = t('A unique machine-readable name for the index configuration. It must only contain lowercase letters, numbers, and underscores.');
  $form['info']['description']['#description'] = t('The description of the index configuration.');

  $form['info']['indexer'] = array(
    '#title' => t('Indexer'),
    '#type' => 'select',
    '#options' => luceneapi_ui_get_plugin_options('indexers'),
    '#description' => t('Select the content that is being indexed.'),
    '#required' => TRUE,
    '#weight' => -30,
  );

  $form['info']['backend'] = array(
    '#title' => t('Backend'),
    '#type' => 'select',
    '#options' => luceneapi_ui_get_plugin_options('backends'),
    '#description' => t('Select the engine used to index and search the content.'),
    '#required' => TRUE,
    '#weight' => -20,
  );

  $form['#submit'][] = 'luceneapi_ui_add_index_form_submit';

  return $form;
}

/**
 *
 */
function luceneapi_ui_index_settings_form($form, &$form_state, LuceneapiIndex $index) {

  // Initializes form with basic settings.
  $form = luceneapi_ui_add_index_form($form, $form_state);
  $form['#submit'] = array('luceneapi_ui_settings_form_submit');

  // Sets the searcher object as a form property.
  $form['#luceneapi']['index'] = $index;

  // Adds default values to the basic option.
  $form['label']['#default_value'] = $index->getLabel();
  $form['name']['#default_value'] = $index->getName();
  $form['name']['#disabled'] = TRUE;
  $form['info']['backend']['#default_value'] = $index->getSettings()->backend;
  $form['info']['backend']['#disabled'] = TRUE;
  $form['info']['indexer']['#default_value'] = $index->getSettings()->indexer;
  $form['info']['indexer']['#disabled'] = TRUE;
  $form['info']['description']['#default_value'] = $index->getDescription();

  // Adds other values that shouldn't be stored as settings.
  $form['#luceneapi']['excluded_values'] = array_merge(
    $form['#luceneapi']['excluded_values'],
    array('wipe', 'reindex', 'optimize', 'indexer', 'backend')
  );

  //
  // Vertical tabs
  //

  $form['settings'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => 10,
  );

  $form['info'] = array_merge($form['info'], array(
    '#type' => 'fieldset',
    '#title' => t('Information'),
    '#group' => 'settings',
    '#weight' => -60,
  ));

  $form['fields'] = array(
    '#type' => 'fieldset',
    '#title' => t('Fields'),
    '#group' => 'settings',
    '#weight' => -50,
  );

  $form['indexing'] = array(
    '#type' => 'fieldset',
    '#title' => t('Indexing'),
    '#group' => 'settings',
    '#weight' => -40,
  );

  $form['performance'] = array(
    '#type' => 'fieldset',
    '#title' => t('Performance'),
    '#group' => 'settings',
    '#weight' => -30,
  );

  $form['statistics'] = array(
    '#type' => 'fieldset',
    '#title' => t('Statistics'),
    '#group' => 'settings',
    '#weight' => -10,
  );

  //
  // Fields
  //

  $form['fields']['enabled_fields'] = array(
    '#theme' => 'luceneapi_ui_fields_table',
    '#luceneapi' => &$form['#luceneapi'],
  );

  // Builds weight options.
  // NOTE: We build the checkboxes one at a time so we can disable a selected
  // subset, specifically the fields that are not configurable.
  $enabled_fields = $index->getSetting('enabled_fields', array());
  foreach ($index->getFields() as $field_name => $field_info) {
    $element = &$form['fields']['enabled_fields'];
    $element["enabled_fields:$field_name"] = array(
      '#type' => 'checkbox',
    );
    if ($field_info['configurable']) {
      $element["enabled_fields:$field_name"]['#default_value'] = (int) !empty($enabled_fields[$field_name]);
    }
    else {
      $element["enabled_fields:$field_name"]['#default_value'] = 1;
      $element["enabled_fields:$field_name"]['#disabled'] = TRUE;
    }
  }

  //
  // Indexing
  //

  $form['indexing']['update_limit'] = array(
    '#type' => 'select',
    '#title' => t('Items to index per update'),
    '#default_value' => $index->getSetting('update_limit', 50),
    '#options' => drupal_map_assoc(array(10, 20, 50, 100, 200, 500)),
    '#description' => t('The maximum number of items that will be indexed per update.'),
  );

  $form['indexing']['index_on_cron'] = array(
    '#type' => 'checkbox',
    '#title' => t('Update index via cron'),
    '#default_value' => $index->getSetting('index_on_cron', 1),
    '#description' => t('By default the index is updated on cron runs. If this setting is disabled, the index will not be automatically maintained by Drupal.'),
  );

  //
  // Performance
  //

  $form['performance']['optimize'] = array(
    '#type' => 'submit',
    '#value' => t('Optimize index'),
    '#submit' => array('luceneapi_ui_optimize_index_submit'),
  );

  $form['performance']['optimize-desc'] = array(
    '#type' => 'item',
    '#description' => t('Consolidate index segments to improve search performance.'),
  );

  $form['performance']['optimize_on_update'] = array(
    '#type' => 'checkbox',
    '#title' => t('Optimize on update'),
    '#default_value' => $index->getSetting('optimize_on_update', 1),
    '#description' => t('Automatically optimize the index after it is updated via cron.'),
  );

  //
  // Statistics
  //

  $form['statistics']['actions'] = array(
    '#type' => 'actions',
  );

  $form['statistics']['actions']['reindex'] = array(
    '#type' => 'submit',
    '#value' => t('Reindex content'),
    '#submit' => array('luceneapi_ui_reindex_index_submit'),
  );

  $form['statistics']['actions']['wipe'] = array(
    '#type' => 'submit',
    '#value' => t('Wipe index'),
    '#submit' => array('luceneapi_ui_wipe_index_submit'),
  );

  $form['statistics']['actions']['wipe_description'] = array(
    '#type' => 'item',
    '#description' => t('Reindexing the site resets the index queue so content will be reindexed on subsequent cron runs. Wiping the index immediately purges all documentes from the index.'),
  );

  //
  // Finalizes form
  //

  // Allows plugins to add form overrides, returns form.
  $index->getIndexer()->indexSettingsForm($form, $form_state, $index);
  $index->getBackend()->indexSettingsForm($form, $form_state, $index);
  return $form;
}

/**
 *
 */
function theme_luceneapi_ui_fields_table(array $variables) {
  $output = '';

  $header = array(
    'indexed' => array(),
    'label' => array('data' => t('Field name')),
  );

  // Gets grouped fields.
  $groups = luceneapi_ui_get_field_groups($variables['element']['#luceneapi']['index']);

  // Builds field options.
  $rows = array();
  foreach ($groups as $group_name => $group) {

    // Adds group header to table.
    $rows['__group:' . $group_name] = array(
      'data' => array(
        'indexed' => array(
          'colspan' => 2,
          'data' => '<strong>' . check_plain($group_name) . '</strong>',
        ),
      ),
    );

    // Sorts field by label, adds to table.
    uasort($group, 'luceneapi_ui_sort_label');
    foreach ($group as $field_name => $field_info) {
      $rows[$field_name] = array(
        'data' => array(
          'indexed' => array(
            'data' => drupal_render($variables['element']["enabled_fields:$field_name"]),
          ),
          'label' => array(
            'data' => check_plain($field_info['label']) . "<div class='description'>" . filter_xss($field_info['description']) . '</div>',
          ),
        ),
      );
    }
  }

  $output .= drupal_render_children($variables['element']);
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'luceneapi-ui-fields')));

  return $output;
}

/**
 *
 * @param array $variables
 */
function theme_luceneapi_ui_sortable_fields_table(array $variables) {
  $output = '';

  $header = array(
    'enabled' => array('class' => 'select-all'),
    'label' => array('data' => t('Field name')),
    'weight' => array('data' => t('Weight')),
  );

  $index = $variables['element']['#luceneapi']['index'];

  // Builds field options.
  $rows = array();
  $index = $variables['element']['#luceneapi']['index'];
  foreach ($index->getSortableFields() as $field_name => $field_info) {
    $rows[$field_name] = array(
      'class' => array('draggable'),
      'data' => array(
        'enabled' => array(
          'data' => drupal_render($variables['element']['sortable_fields'][$field_name]),
        ),
        'label' => array(
          'data' => check_plain($field_info['label']) . "<div class='description'>" . filter_xss($field_info['description']) . '</div>',
        ),
        'weight' => array(
          'data' => drupal_render($variables['element']['sortable_fields_weight:' . $field_name]),
        ),
      ),
    );

  }

  $output .= drupal_render_children($variables['element']);
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'luceneapi-ui-sortable-fields')));
  drupal_add_tabledrag('luceneapi-ui-sortable-fields', 'order', 'sibling', 'luceneapi-ui-sortable-fields-weight');

  drupal_add_js('misc/tableselect.js');
  return $output;
}

/**
 * Optimizes the index.
 */
function luceneapi_ui_optimize_index_submit($form, &$form_state) {
  try {
    $index = $form['#luceneapi']['index'];
    $index->getBackend()->optimizeIndex();
    drupal_set_message(t('Index successfully optimized.'));
  }
  catch (Exception $e) {
    drupal_set_message(t('Error optimizing index.'), 'error');
    watchdog_exception('luceneapi', $e);
  }
}

/**
 * Resets the index queue.
 */
function luceneapi_ui_reindex_index_submit($form, &$form_state) {
  try {
    $index = $form['#luceneapi']['index'];
    $index->getIndexer()->resetQueue($index);
    drupal_set_message(t('The index will be rebuilt.'));
  }
  catch (Exception $e) {
    drupal_set_message(t('Error resetting index queue.'), 'error');
    watchdog_exception('luceneapi', $e);
  }
}

/**
 * Wipes the index.
 */
function luceneapi_ui_wipe_index_submit($form, &$form_state) {
  try {
    $index = $form['#luceneapi']['index'];
    $index->getIndexer()->resetQueue($index);
    $index->getBackend()->wipeIndex();
    drupal_set_message(t('Index successfully wiped.'));
  }
  catch (Exception $e) {
    drupal_set_message(t('Error wiping index.'), 'error');
    watchdog_exception('luceneapi', $e);
  }
}

/**
 *
 */
function luceneapi_ui_import_form($form, &$form_state, $table) {
  $form['#table'] = $table;

  $form['code'] = array(
    '#type' => 'textarea',
    '#title' => t('Import configuration options'),
    '#rows' => 10,
    '#required' => TRUE,
  );

  $form['object'] = array(
    '#type' => 'value',
    '#value' => FALSE,
  );

  // Adds submit and cancel buttons.
  $form['actions'] = array(
    '#type' => 'actions'
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import configuration'),
  );

  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => luceneapi_ui_calculate_settings_path($table),
  );

  $form['#submit'][] = 'luceneapi_ui_import_form_submit';

  return $form;
}

/**
 *
 * @see luceneapi_ui_import_searcher_form()
 */
function luceneapi_ui_import_index_form($form, &$form_state) {
  $form = luceneapi_ui_import_form($form, $form_state, 'luceneapi_index');
  $form['#validate'][] = 'luceneapi_ui_import_index_form_validate';
  return $form;
}

/**
 * Validates luceneapi_ui_import_index_form form submissions.
 */
function luceneapi_ui_import_index_form_validate($form, &$form_state) {
  try {
    // Loads object, throws exception on any errors.
    ctools_include('export');
    $object = ctools_export_crud_import('luceneapi_index', $form_state['values']['code']);
    if (is_string($object)) {
      throw new Exception($object);
    }

    // Makes sure an object doesn't already exist.
    if (ctools_export_crud_load($form['#table'], $object->name)) {
      throw new Exception(t('Configuration options already exist with the same name.'));
    }

    // Sets the object variable.
    form_set_value($form['object'], $object, $form_state);

  }
  catch (Exception $e) {
    form_set_error('code', filter_xss_admin($e->getMessage()));
  }
}

/**
 * Basic settings common to all configuration.
 *
 * @param $form,
 *
 * @param &$form_state
 *
 * @param $table
 *   A string containing the table the configuration options are stored in.
 */
function luceneapi_ui_settings_form($form, &$form_state, $table) {

  // Adds LuceneAPI settings.
  $form['#luceneapi'] = array(
    'table' => $table,
    'excluded_values' => array(
      'form_build_id', 'form_token', 'form_id', 'op', 'submit', 'submit_list',
      'settings__active_tab', 'name', 'label', 'description',
    ),
  );

  // An array of settings that shouldn't be exported.
  $form['excluded_values'] = array(
    '#type' => 'value',
    '#value' => array(),
  );

  $form['label'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => '',
    '#required' => TRUE,
    '#size' => 30,
    '#maxlength' => 32,
    '#weight' => -50,
  );

  $form['name'] = array(
    '#type' => 'machine_name',
    '#maxlength' => 32,
    '#required' => TRUE,
    '#machine_name' => array(
      'exists' => 'luceneapi_searcher_load',
      'source' => array('label'),
    ),
    '#description' => '',
    '#weight' => -40,
  );

  $form['info']['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textfield',
    '#required' => FALSE,
    '#maxlength' => 255,
    '#description' => '',
  );

  $form['actions'] = array(
    '#type' => 'actions',
    '#weight' => 20,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  $form['actions']['submit_list'] = array(
    '#type' => 'submit',
    '#value' => t('Save and go back to list'),
  );

  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => luceneapi_ui_calculate_settings_path($table),
  );

  return $form;
}

/**
 * Processes luceneapi_ui_add_index_form form submissions.
 */
function luceneapi_ui_add_index_form_submit($form, &$form_state) {

  // Initializes defaults.
  $settings = new stdClass();
  $settings = ctools_export_crud_new('luceneapi_index');
  $settings->label = $form_state['values']['label'];
  $settings->name = $form_state['values']['name'];
  $settings->description = $form_state['values']['description'];
  $settings->backend = $form_state['values']['backend'];
  $settings->indexer = $form_state['values']['indexer'];

  $backend = luceneapi_get_plugin_class('backends', $settings->backend);
  $indexer = luceneapi_get_plugin_class('indexers', $settings->indexer);

  // Gets default settings.
  $settings->settings = array();
  $settings->settings += call_user_func(array($backend, 'defaultIndexSettings'));
  $settings->settings += call_user_func(array($indexer, 'defaultIndexSettings'));
  $settings->settings += array(
    'enabled_fields' => array(),
    'update_limit' => 50,
    'index_on_cron' => 1,
    'optimize_on_update' => 1,
  );

  // Saves our values in the database, sets redirect path on success.
  if (FALSE !== ($return = ctools_export_crud_save('luceneapi_index', $settings))) {
    drupal_set_message(t('The configuration options have been saved.'));
    $form_state['redirect'] = luceneapi_ui_get_redirect_path(
      $settings->name, 'luceneapi_index',  $form_state['clicked_button']
    );
  }
  else {
    drupal_set_message(t('Error saving configuration options.'), 'error');
  }
}

/**
 * Processes luceneapi_ui_add_index_form form submissions.
 */
function luceneapi_ui_add_searcher_form_submit($form, &$form_state) {

  // Initializes defaults.
  $settings = new stdClass();
  $settings = ctools_export_crud_new('luceneapi_searcher');
  $settings->label = $form_state['values']['label'];
  $settings->name = $form_state['values']['name'];
  $settings->description = $form_state['values']['description'];
  $settings->index_name = $form_state['values']['index_name'];
  $settings->search_path = 'search/' . $settings->name . '/%keys';
  $settings->page_title = $settings->label;

  $index = luceneapi_index_load($form_state['values']['index_name']);

  // Gets default settings.
  $settings->settings = array();
  $settings->settings += call_user_func(array($index->getBackend(), 'defaultSearcherSettings'));
  $settings->settings += call_user_func(array($index->getIndexer(), 'defaultSearcherSettings'));
  $settings->settings += array(
    'form_prompt' => 'Enter your keywords',
    'button_text' => 'Search',
    'highlighter' => 'summary',
    'limit' => 10,
    'sortable_fields' => array(),
    'sortable_fields_weight' => array(),
    'bias' => array(),
  );

  // Saves our values in the database, sets redirect path on success.
  if (FALSE !== ($return = ctools_export_crud_save('luceneapi_searcher', $settings))) {
    drupal_set_message(t('The configuration options have been saved.'));
    $form_state['redirect'] = luceneapi_ui_get_redirect_path(
      $settings->name, 'luceneapi_searcher',  $form_state['clicked_button']
    );

    // Menu rebuild needed to pick up search path.
    ctools_export_load_object_reset('luceneapi_searcher');
    menu_rebuild();
  }
  else {
    drupal_set_message(t('Error saving configuration options.'), 'error');
  }
}

/**
 * Processes luceneapi_ui form submissions.
 */
function luceneapi_ui_settings_form_submit($form, &$form_state) {
  $rebuild_menu = FALSE;

  // Loads settings object.
  $settings = ctools_export_crud_load(
    $form['#luceneapi']['table'], $form_state['values']['name']
  );

  // Handles top level settings.
  $settings->label = $form_state['values']['label'];
  $settings->description = $form_state['values']['description'];
  if (!empty($form_state['values']['search_path'])) {
    // If the search path has changed, rebuild the menu.
    if ($settings->search_path != $form_state['values']['search_path']) {
      $rebuild_menu = TRUE;
    }
    $settings->search_path = $form_state['values']['search_path'];
  }
  if (!empty($form_state['values']['page_title'])) {
    $settings->page_title = $form_state['values']['page_title'];
  }

  // Builds array of excluded values, saves all other values as settings.
  $settings->settings = array_diff_key($form_state['values'], array_flip(
    $form['#luceneapi']['excluded_values'] + $form_state['values']['excluded_values']
  ));

  // Converts the "enabled fields" checkboxes to an associative array.
  // NOTE: They are built individually so we can disable a subset of checkboxes.
  if ('luceneapi_index' == $form['#luceneapi']['table']) {
    luceneapi_ui_combine_settings('enabled_fields', $settings);
    $fields = $form['#luceneapi']['index']->getFields();
    foreach ($settings->settings['enabled_fields'] as $field => $value) {
      if (!$fields[$field]['configurable']) {
        $settings->settings['enabled_fields'][$field] = 1;
      }
    }
  }

  // Converts fields to associative arrays for readability.
  if ('luceneapi_searcher' == $form['#luceneapi']['table']) {
    luceneapi_ui_combine_settings('sortable_fields_weight', $settings);
    luceneapi_ui_combine_settings('bias', $settings);
  }

  // Saves our values in the database, rebuilds menu if necessary.
  if (FALSE !== ($return = ctools_export_crud_save($form['#luceneapi']['table'], $settings))) {
    drupal_set_message(t('The configuration options have been saved.'));
    if ($rebuild_menu) {
      ctools_export_load_object_reset($form['#luceneapi']['table']);
      menu_rebuild();
    }
  }
  else {
    drupal_set_message(t('Error saving configuration options.'), 'error');
  }

  // Sets the redirect path.
  $form_state['redirect'] = luceneapi_ui_get_redirect_path(
    $settings->name, $form['#luceneapi']['table'],  $form_state['clicked_button']
  );

  // Sets the active tab if any.
  // @todo Find a way to keep current tab open on form submission.
  if (!empty($form_state['values']['settings__active_tab'])) {
    //dsm($form_state['values']['settings__active_tab']);
  }
}
