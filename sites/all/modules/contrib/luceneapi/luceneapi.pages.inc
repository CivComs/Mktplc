<?php

/**
 * @file
 *
 */

/**
 * @todo Error handling.
 */
function luceneapi_search_page($searcher_name, $keys = '') {
  $build = array();
  try {

    // Instantiates searcher, parses path information, gets keys from the path
    // information if the keys are pulled from the query string.
    $searcher = new LuceneapiSearcher($searcher_name);
    $path_info = $searcher->parseSearchPath();
    if (!strlen($keys) && !empty($path_info['values']['keys'])) {
      $keys = (string) $_GET[$path_info['variables']['keys']];
    }

    // Adds the search form to the page.
    $build['search_form'] = drupal_get_form('luceneapi_search_form', $searcher, $keys);

    // If search keys were passed, execute the search.
    if (strlen($keys)) {

      // Initializes the search query.
      $query = $searcher->newQuery()
        ->addFilter('keys', $keys, $searcher)
        ->setLimit($path_info['values']['limit']);

      // Iterates over results, builds item.
      $results = array();
      foreach ($searcher->search($query) as $hit) {
        $results[] = $searcher->buildResult($hit);
      }

      // Adds search results to the render array.
      $build['search_results'] = array(
        '#theme' => 'search_results',
        '#results' => $results,
        '#module' => 'luceneapi',
      );
    }
  }
  catch (Exception $e) {
    luceneapi_handle_exception($e);
  }

  return $build;
}

/**
 *
 */
function luceneapi_search_form($form, &$form_state, LuceneapiSearcher $searcher, $keys = '') {

  // Loads the core Search CSS file, use the core search module's classes.
  drupal_add_css(drupal_get_path('module', 'search') . '/search.css');
  $form['#id'] = 'search-form';
  $form['#attributes']['class'][] = 'search-form';

  $form['#searcher'] = $searcher;

  $form['basic'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('container-inline')),
  );

  $prompt = $searcher->getSetting('form_prompt', t('Enter terms'));
  $form['basic']['keys'] = array(
    '#type' => 'textfield',
    '#title' => check_plain($prompt),
    '#default_value' => $keys,
    '#size' => $prompt ? 20 : 40,
    '#maxlength' => 255,
  );

  $form['basic']['submit'] = array(
    '#type' => 'submit',
    '#value' => check_plain($searcher->getSetting('button_text', t('Search'))),
  );

  return $form;
}

/**
 * Processes luceneapi_search_form form submissions.
 */
function luceneapi_search_form_submit(&$form, &$form_state) {
  $searcher = $form['#searcher'];

  // Determines redirect path based on where the keys are.
  $path_info = $searcher->parseSearchPath();
  if (FALSE !== $path_info['keys position']) {
    $redirect = $path_info['parent'] . '/' . $form_state['values']['keys'];
  }
  else {
    $query = array($path_info['variables']['keys'] => $form_state['values']['keys']);
    $redirect = array($path_info['path'], array('query' => $query));
  }

  // Redirects to path set in configuration.
  $form_state['redirect'] = $redirect;
}
