<?php

/**
 * @file
 *
 */

/**
 * Extends LuceneapiIndexer.
 */
class LuceneapiNodeLuceneapiIndexer extends LuceneapiIndexer {

  /**
   * Returns node ID's that are queued to be indexed.
   *
   * @param $index
   *   A LuceneapiIndex object.
   * @param $length
   *   An integer cotaining the number of results to return.
   */
  public function getQueue(LuceneapiIndex $index, $length = 0) {
    $query = luceneapi_node_get_queue_query($index);
    if ($length) {
      $query->range(0, $length);
    }
    return $query->execute();
  }

  /**
   * Resets the index queue.
   */
  public function resetQueue(LuceneapiIndex $index) {
    db_update('luceneapi_node_index_queue')
      ->fields(array('changed' => REQUEST_TIME))
      ->condition('index_name', $index->getName())
      ->execute();
  }

  /**
   * Invoked just prior to building the item for indexing.
   */
  public function preBuildItem($item, LuceneapiIndex $index) {
    db_merge('luceneapi_node_index_queue')
      ->key(array(
        'nid' => $item->id,
        'index_name' => $index->getName(),
      ))
      ->fields(array(
        'changed' => 0,
      ))
      ->execute();
  }

  /**
   * Builds an item for indexing. In this case we are loading the node and
   * building the search display.
   *
   * @param $item
   *   A mixed value containing the item being indexed.
   * @param $index
   *   A LuceneapiIndex object.
   * @return
   *   A mixed value containing the item built for indexing.
   */
  public function buildItem($item, LuceneapiIndex $index) {
    $nid = (is_object($item)) ? $item->id : $item;
    if ($node = node_load($nid)) {
      $build = node_view($node, 'search_index');
      unset($build['#theme']);
      return $build;
    }
    else {
      throw new Exception('Error loading node <em>' . check_plain($nid) . '</em>.');
    }
  }

  /**
   * Deleted the current document from the index.
   *
   * @param $item
   *   A mixed value containing the item being built.
   * @param $index
   *   A LuceneapiIndex object.
   */
  public function preAddDocument($item, LuceneapiIndex $index) {
    $backend = $index->getBackend();
    $backend->deleteDocumentByQuery(
      $backend->newQuery()->addFilter('term', $item->id, 'nid')
    );
  }

  /**
   * Process an item display in search results.
   *
   * @param $hit
   *   A LuceneapiHit object.
   * @param $searcher
   *   A LuceneapiSearcher object.
   *
   * @return
   *   A mixed value containing the item built for indexing.
   */
  public function buildResult(LuceneapiHit $hit, LuceneapiSearcher $searcher) {

    // Fakes the user object.
    $account = new stdClass();
    $account->uid = $hit->uid;
    $account->name = $hit->name;

    // Builds and returns the result.
    $result = array(
      'link' => $hit->link,
      'type' => check_plain(node_type_get_name($hit->bundle)),
      'title' => $hit->title,
      'user' => theme('username', array('account' => $account)),
      'date' => strtotime($hit->changed),
      'node' => $hit,
      'extra' => $hit->extra,
      'score' => $hit->score,
      'snippet' => $searcher->getHighlighter($hit->body),
      'language' => $hit->language,
    );

    return $result;
  }

  /**
   * Allows for alterations to the index form.
   */
  public function indexSettingsForm(&$form, &$form_state, LuceneapiIndex $index) {
    $form['node'] = array(
      '#type' => 'fieldset',
      '#title' => t('Node restrictions'),
      '#group' => 'settings',
      '#weight' => -45,
    );

    $form['node']['excluded_types'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Content types excluded from index'),
      '#options' => array_map('check_plain', node_type_get_names()),
      '#default_value' => $index->getSetting('excluded_types'),
    );

    $form['node']['restrictions'] = array(
      '#markup' => '<strong>' . t('Additional restrictions') . '</strong>',
      '#weight' => 20,
    );

    $form['node']['index_unpublished'] = array(
      '#type' => 'checkbox',
      '#title' => t('Index unpublished nodes'),
      '#default_value' => $index->getSetting('index_unpublished'),
      '#weight' => 25,
    );
  }

  /**
   * Allows for alterations to the searcher form.
   */
  public function searcherSettingsForm(&$form, &$form_state, LuceneapiSearcher $searcher) {
    $form['node'] = array(
      '#type' => 'fieldset',
      '#title' => t('Node restrictions'),
      '#group' => 'settings',
      '#weight' => -25,
    );

    $form['node']['node_language'] = array(
      '#type' => 'checkbox',
      '#title' => t('Only return results that are language neutral or in the current language'),
      '#default_value' => $searcher->getSetting('node_language'),
    );
  }

  /**
   *
   */
  static public function defaultIndexSettings() {
    return array(
      'excluded_types' => array(),
      'index_unpublished' => 0,
    );
  }

  /**
   *
   */
  static public function defaultSearcherSettings() {
    return array(
      'node_language' => 1,
    );
  }
}



/**
 * Implements hook_luceneapi_field_info().
 */
function luceneapi_node_luceneapi_field_info($indexer_module) {
  if ('node' != $indexer_module) {
    return;
  }

  //
  // Entity fields
  //

  if (module_exists('field')) {
    module_load_include('inc', 'luceneapi', 'luceneapi.field');
    $fields = luceneapi_get_entity_field_info('node');
    $fields['body']['field type'] = 'text';
    $fields['body']['default bias'] = '1.0';
    $fields['body']['configurable'] = FALSE;
    $fields['body']['group'] = t('Required fields');
  }

  //
  // Required fields
  //

  $fields['nid'] = array(
    'label' => t('Node ID'),
    'description' => t('The unique identifier of the node.'),
    'field type' => 'keyword',
    'data type' => 'integer',
    'sortable' => TRUE,
    'extract callback' => 'luceneapi_node_extract_property',
    'configurable' => FALSE,
    'group' => t('Required fields'),
  );

  $fields['link'] = array(
    'label' => t('Node link'),
    'description' => t('Link to the node.'),
    'field type' => 'unindexed',
    'extract callback' => 'luceneapi_node_extract_link',
    'configurable' => FALSE,
    'group' => t('Required fields'),
  );

  $fields['uid'] = array(
    'label' => t('User ID'),
    'description' => t("The node author's user ID."),
    'field type' => 'keyword',
    'data type' => 'integer',
    'sortable' => TRUE,
    'extract callback' => 'luceneapi_node_extract_property',
    'configurable' => FALSE,
    'group' => t('Required fields'),
  );

  $fields['title'] = array(
    'label' => t('Title'),
    'description' => t('The node title'),
    'field type' => 'text',
    'data type' => 'string',
    'extract callback' => 'luceneapi_node_extract_property',
    'configurable' => FALSE,
    'default bias' => '5.0',
    'group' => t('Required fields'),
  );

  $fields['bundle'] = array(
    'label' => t('Entity bundle'),
    'description' => t('The machine readable name of the content type used in filtering.'),
    'field type' => 'keyword',
    'extract callback' => 'luceneapi_node_extract_property',
    'extract arguments' => array('type'),
    'configurable' => FALSE,
    'group' => t('Required fields'),
  );

  $fields['extra'] = array(
    'label' => t('Extra result information'),
    'description' => t('Extra information displayed with the search result.'),
    'field type' => 'unindexed',
    'extract callback' => 'luceneapi_node_extract_extra',
    'configurable' => FALSE,
    'group' => t('Required fields'),
  );

  $fields['name'] = array(
    'label' => t('Author'),
    'description' => t("The node author's username."),
    'field type' => 'unindexed',
    'extract callback' => 'luceneapi_node_extract_property',
    'default bias' => '3.0',
    'configurable' => FALSE,
    'group' => t('Required fields'),
  );

  $fields['changed'] = array(
    'label' => t('Last modified'),
    'description' => t('The date the node was last modified.'),
    'field type' => 'keyword',
    'data type' => 'date',
    'sortable' => TRUE,
    'extract callback' => 'luceneapi_node_extract_property',
    'configurable' => FALSE,
    'group' => t('Required fields'),
  );

  $fields['language'] = array(
    'label' => t('Language'),
    'description' => t('The language the node is associated with.'),
    'field type' => 'keyword',
    'extract callback' => 'luceneapi_node_extract_language',
    'sortable' => TRUE,
    'configurable' => FALSE,
    'group' => t('Required fields'),
  );

  //
  // Node properties
  //

  $fields['type'] = array(
    'label' => t('Content type'),
    'description' => t('The label of the content type used in textual searches.'),
    'field type' => 'unstored',
    'data type' => 'string',
    'extract callback' => 'luceneapi_node_extract_node_type',
    'group' => t('Node properties'),
  );

  $fields['status'] = array(
    'label' => t('Published'),
    'field type' => 'keyword',
    'data type' => 'boolean',
    'sortable' => TRUE,
    'extract callback' => 'luceneapi_node_extract_property',
    'group' => t('Node properties'),
  );

  $fields['sticky'] = array(
    'label' => t('Sticky at top of lists'),
    'field type' => 'keyword',
    'data type' => 'boolean',
    'sortable' => TRUE,
    'extract callback' => 'luceneapi_node_extract_property',
    'group' => t('Node properties'),
  );

  $fields['promote'] = array(
    'label' => t('Promoted to front page'),
    'field type' => 'keyword',
    'data type' => 'boolean',
    'sortable' => TRUE,
    'extract callback' => 'luceneapi_node_extract_property',
    'group' => t('Node properties'),
  );

  $fields['tnid'] = array(
    'label' => t('Translation set ID'),
    'description' => t('The node ID of the source post.'),
    'field type' => 'keyword',
    'data type' => 'integer',
    'sortable' => TRUE,
    'extract callback' => 'luceneapi_node_extract_property',
    'group' => t('Node properties'),
  );

  $fields['translate'] = array(
    'label' => t('Translation required'),
    'field type' => 'keyword',
    'data type' => 'boolean',
    'sortable' => TRUE,
    'extract callback' => 'luceneapi_node_extract_property',
    'group' => t('Node properties'),
  );

  $fields['created'] = array(
    'label' => t('Authored on'),
    'description' => t('The date the node was created.'),
    'field type' => 'keyword',
    'data type' => 'date',
    'sortable' => TRUE,
    'extract callback' => 'luceneapi_node_extract_property',
    'group' => t('Node properties'),
  );

  $fields['nodeaccess'] = array(
    'label' => t('Node access'),
    'description' => t('Index node access information to prevent people from searching content they don\'t have access to.'),
    'field type' => 'unstored',
    'extract callback' => 'luceneapi_node_extract_nodeaccess',
    'group' => t('Node properties'),
  );

  //
  // HTML Tags
  //

  $fields['tags_heading_large'] = array(
    'label' => t('Large headings'),
    'description' => t('Text in H1 tags.'),
    'field type' => 'unstored',
    'extract callback' => 'luceneapi_node_extract_tag_text',
    'extract arguments' => array(array('h1')),
    'default bias' => '5.0',
    'group' => t('Node tag text'),
  );

  $fields['tags_heading_medium'] = array(
    'label' => t('Medium headings'),
    'description' => t('Text in H2, H3 tags.'),
    'field type' => 'text',
    'extract callback' => 'luceneapi_node_extract_tag_text',
    'extract arguments' => array(array('h2', 'h3')),
    'default bias' => '3.0',
    'group' => t('Node tag text'),
  );

  $fields['tags_heading_small'] = array(
    'label' => t('Small headings'),
    'description' => t('Text in H4, H5, H6 tags.'),
    'field type' => 'unstored',
    'extract callback' => 'luceneapi_node_extract_tag_text',
    'extract arguments' => array(array('h4', 'h5', 'h6')),
    'default bias' => '2.0',
    'group' => t('Node tag text'),
  );

  $fields['tags_inline'] = array(
    'label' => t('Inline tags'),
    'description' => t('Text in U, B, I, STRONG, EM tags.'),
    'field type' => 'unstored',
    'extract callback' => 'luceneapi_node_extract_tag_text',
    'extract arguments' => array(array('u', 'b', 'i', 'strong', 'em')),
    'default bias' => '1.0',
    'group' => t('Node tag text'),
  );

  $fields['tags_a'] = array(
    'label' => t('Anchor links'),
    'description' => t('Text in A tags.'),
    'field type' => 'unstored',
    'extract callback' => 'luceneapi_node_extract_link_text',
    'default bias' => 0,
    'group' => t('Node tag text'),
  );

  return $fields;
}

/**
 * Invokes hook_node_search_result() to extract extra information displayed in
 * the search results.
 *
 * @param $build
 *   A mixed value containing the data being indexed.
 * @param $field
 *   An array containing the field definition.
 * @return
 *   A string containing the text being indexed.
 */
function luceneapi_node_extract_extra($build, array $field) {
  return join(' - ', module_invoke_all('node_search_result', $build['#node']));
}

/**
 * Extracts language from the "language" node property.
 *
 * @param $build
 *   A mixed value containing the data being indexed.
 * @param $field
 *   An array containing the field definition.
 * @return
 *   A string containing the text being indexed.
 */
function luceneapi_node_extract_language($build, array $field) {
  return empty($build['#node']->language) ? LANGUAGE_NONE : $build['#node']->language;
}

/**
 * Extracts the node link.
 *
 * @param $build
 *   A mixed value containing the data being indexed.
 * @param $field
 *   An array containing the field definition.
 * @return
 *   A string containing the text being indexed.
 */
function luceneapi_node_extract_link($build, array $field) {
  $uri = entity_uri('node', $build['#node']);
  return url($uri['path'], array_merge($uri['options'], array('absolute' => TRUE)));
}

/**
 * Extracts the human readable node type from the node.
 *
 * @param $build
 *   A mixed value containing the data being indexed.
 * @param $field
 *   An array containing the field definition.
 * @return
 *   The normalized, or formatted text.
 */
function luceneapi_node_extract_node_type($build, array $field) {
  return node_type_get_name($build['#node']->type);
}

/**
 * Extracts the nodeaccess information, adds a field per node access realm.
 *
 * @param $build
 *   A mixed value containing the data being indexed.
 * @param $field
 *   An array containing the field definition.
 * @return
 *   An array containing the normalized text for the various node access fields.
 */
function luceneapi_node_extract_nodeaccess($build, array $field) {
  $fields = array();
  if (count(module_implements('node_grants'))) {

    // Gets node access grants.
    $result = db_select('node_access', 'na')
      ->fields('na', array('realm', 'gid'))
      ->condition(db_or()->condition('nid', '0')->condition('nid', $build['#node']->nid))
      ->condition('na.grant_view', '1')
      ->execute();

    // Iterates over grants, builds fields.
    foreach ($result as $record) {
      $fields['nodeaccess_' . $record->realm][] = $record->gid;
    }

    // Flattens values to strings so they can be indexed.
    array_walk($fields, 'luceneapi_node_flatten_nodeaccess_fields');
  }

  // Returns an array keyed by field name to value.
  return $fields;
}

/**
 * Extracts text from node properties.
 *
 * @param $build
 *   A mixed value containing the data being indexed.
 * @param $field
 *   An array containing the field definition.
 * @param $property
 *   The node object property.
 * @return
 *   A string containing the text being indexed.
 */
function luceneapi_node_extract_property($build, array $field, $property = NULL) {
  if (NULL === $property) {
    $property = $field['name'];
  }
  return isset($build['#node']->$property) ? $build['#node']->$property : FALSE;
}

/**
 * Extracts text inside HTML tags.
 *
 * @param $build
 *   A mixed value containing the data being indexed.
 * @param $field
 *   An array containing the field definition.
 * @param $tags
 *   An array of tags.
 * @return
 *   A string containing the text being indexed.
 */
function luceneapi_node_extract_tag_text($build, array $field, array $tags = array()) {
  // @todo Cache this in a static variable.
  $text = drupal_render($build['body']);
  preg_match_all('@<(' . join('|', $tags) . ')[^>]*>(.*)</\1>@Ui', $text, $matches);
  return join(' ', $matches[2]);
}

/**
 * Extracts text inside HTML anchor tags.
 *
 * @param $build
 *   A mixed value containing the data being indexed.
 * @param $field
 *   An array containing the field definition.
 * @return
 *   A string containing the text being indexed.
 */
function luceneapi_node_extract_link_text($build, array $field) {
  // @todo Cache this in a static variable.
  $text = drupal_render($build['body']);
  preg_match_all('@<(a)[^>]*>(.*)</\1>@Ui', $text, $matches);
  return join(' ', array_filter($matches[2], 'luceneapi_node_filter_auto_generated_links'));
}

/**
 * Filters links auto-generated by the url filter.
 *
 * @param $text
 *   A string containing the text.
 * @return
 *   A boolean flagging whether or not the link was auto generated.
 */
function luceneapi_node_filter_auto_generated_links($text) {
  return !preg_match('@(?:http://|https://|ftp://|mailto:|smb://|afp://|file://|gopher://|news://|ssl://|sslv2://|sslv3://|tls://|tcp://|udp://|www\.)[a-zA-Z0-9]+@', $text);
}

/**
 * Flattens node access field data into a single string.  Useful as an
 * array_walk() callback.
 *
 * @param $field
 *   An array containing the nodeaccess information.
 * @param $field_name
 *   A string containing the Lucene field name.
 */
function luceneapi_node_flatten_nodeaccess_fields(&$field, $field_name) {
  $field = join(' ', $field);
}

