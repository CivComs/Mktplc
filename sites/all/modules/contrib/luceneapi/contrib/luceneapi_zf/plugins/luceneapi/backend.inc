<?php

/**
 * @file
 */

/**
 *
 */
class LuceneapiZfLuceneapiBackend extends LuceneapiBackend {

  /**
   * The Lucene analyzer used by this index.
   *
   * @var Zend_Search_Lucene_Analysis_Analyzer
   */
  protected $analyzer;

  /**
   * The Lucene index associated with this instance.
   *
   * @var Zend_Search_Lucene_Proxy
   */
  protected $zendIndex;

  /**
   * The last query executed via LuceneapiZendFrameworkBackend::search().
   *
   * @var Zend_Search_Lucene_Search_Query
   */
  protected $lastQuery;

  /**
   * An array of Zend_Search_Lucene_Proxy objects.
   *
   * @var array
   */
  static protected $zendIndexes = array();

  /**
   * Opens the Zend Framework index.
   *
   * @param $index
   *   A LuceneapiIndex object.
   */
  public function __construct(LuceneapiIndex $index) {
    parent::__construct($index);

    // Makes sure the library is initialized, loads required include files.
    luceneapi_zf_library_initialize();
    module_load_include('inc', 'luceneapi_zf', 'luceneapi_zf.zend');

    // Registers plugins.
    $index
      ->registerPlugin('normalizers', 'boolean')
      ->registerPlugin('normalizers', 'date')
      ->registerPlugin('normalizers', 'decimal')
      ->registerPlugin('normalizers', 'float')
      ->registerPlugin('normalizers', 'integer')
      ->registerPlugin('normalizers', 'boolean')
      ->registerPlugin('normalizers', 'string')
      ->registerPlugin('highlighters', 'zend_framework')
      ->registerPlugin('filters', 'luceneapi_zf_keys')
      ->registerPlugin('filters', 'luceneapi_zf_term')
      ->registerPlugin('filters', 'luceneapi_zf_wildcard');

    // Creates index directory if not already created.
    // @todo Index needs a machine readable name.
    $filepath = 'public://luceneapi/' . $this->index->getName();
    if (!file_exists($filepath) && drupal_mkdir($filepath, NULL, TRUE)) {
      file_create_htaccess($filepath);
    }

    // Opens the index associated with the filepath.
    $this->zendIndex = self::openIndex($filepath);

    // Instantiates and sets the numeric, case insentive, UTF-8 analyzer.
    $this->analyzer = new Zend_Search_Lucene_Analysis_Analyzer_Common_Utf8Num_CaseInsensitive();

    // Add shortwords token filter if minimum word length is set.
    $min_word_length = $this->index->getSetting('min_word_length', 0);
    if ($min_word_length) {
      $this->analyzer->addFilter(new LuceneapiTokenFilterShortWords($min_word_length));
    }

    // Add stopwords token filter if stopwords are set.
    $stopwords = $this->parseStopwords();
    if (!empty($stopwords)) {
      $this->analyzer->addFilter(
        new Zend_Search_Lucene_Analysis_TokenFilter_StopWords($stopwords)
      );
    }

    // Add "Drupal" token filter if drupal preprocessing is enabled.
    if ($this->index->getSetting('drupal_preprocessing')) {
      $this->analyzer->addFilter(new LuceneapiTokenFilterDrupal());
    }
  }

  /**
   * Parses stopwords into an array of words.
   *
   * @param $text
   *   A string containing the raw setting text.
   * @return
   *   An array of stopwords.
   */
  public function parseStopwords() {
    $text = $this->index->getSetting('stopwords');
    $stopwords = array();
    $continue = TRUE;
    $byte_position = 0;
    do {
      if (preg_match('/[\p{L}\p{N}]+/u', $text, $match, PREG_OFFSET_CAPTURE, $byte_position)) {
        $stopwords[] = drupal_strtolower($match[0][0]);
        $byte_position = $match[0][1] + strlen($match[0][0]);
      }
      else {
        $continue = FALSE;
      }
    }
    while ($continue);
    return $stopwords;
  }

  /**
   *
   */
  static public function &openIndex($filepath) {
    if (!isset(self::$zendIndexes[$filepath])) {
      try {
        self::$zendIndexes[$filepath] = Zend_Search_Lucene::open($filepath);
      }
      catch (Zend_Exception $e) {
        self::$zendIndexes[$filepath] = Zend_Search_Lucene::create($filepath);
      }
    }
    return self::$zendIndexes[$filepath];
  }

  /**
   *
   *
   */
  static public function closeIndex($filepath) {
    unset(self::$zendIndexes[$filepath]);
  }

  /**
   * Ensures our index specific settings are applied before indexing.
   */
  public function preIndexItems() {
    $this->setIndexSettings();
  }

  /**
   *
   */
  public function postIndexItems() {
    if ($this->index->getSetting('optimize_on_update')) {
      $this->optimizeIndex();
    }
    else {
      $this->flushIndex();
    }
  }

  /**
   * Sets index settings that are required prior to indexing.
   */
  public function setIndexSettings() {
    $this->zendIndex->setMaxBufferedDocs($this->index->getSetting('max_buffered_docs', 10));
    $this->zendIndex->setMergeFactor($this->index->getSetting('merge_factor', 10));
    Zend_Search_Lucene_Analysis_Analyzer::setDefault($this->analyzer);
    Zend_Search_Lucene_Search_QueryParser::setDefaultEncoding(LUCENEAPI_ENCODING);
  }

  /**
   * Sets query settings that are required prior to parsing or building queries.
   */
  public function setQuerySettings(LuceneapiSearcher $searcher) {
    // The minimum prefix length cannot be shorter than Minimum word length.
    // @see http://drupal.org/node/722296.
    $min_prefix_length = max(
      $this->index->getSetting('min_word_length', 0),
      $searcher->getSetting('minimum_prefix', 2)
    );

    $this->setIndexSettings();
    Zend_Search_Lucene_Search_QueryParser::setDefaultOperator($searcher->getSetting('default_operator', 1));
    Zend_Search_Lucene_Search_Query_Wildcard::setMinPrefixLength($min_prefix_length);
  }

  /**
   * Instantiates a new Query object for this backend.
   *
   * @return
   *   A LuceneapiZfQuery object.
   */
  public function newQuery() {
    return new LuceneapiZfQuery($this->index);
  }

  /**
   *
   */
  public function getLastQuery() {
    return $this->lastQuery;
  }

  /**
   *
   */
  public function search(LuceneapiQuery $query, LuceneapiSearcher $searcher) {
    $results = array();
    try {

      // Gets sort parameters, searches the index, stores query object.
      $sort = array();
      foreach ($query->getSorts() as $field => $order) {
        $sort[] = $field;
        $sort[] = $order;
      }

      // Sets settings required by the analyzer for parsing, invokes alter hook,
      // converts the query into Zend's query API.
      $this->setQuerySettings($searcher);
      drupal_alter('luceneapi_query', $query);
      $zend_query = $query->convert();

      // Sets result set limit, a value of zero means no limit.
      Zend_Search_Lucene::setResultSetLimit($this->index->getSetting('resultset_limit'));

      // Executes the search.
      $parameters = array_merge(array(&$zend_query), $sort);
      $hits = call_user_func_array(array(&$this->zendIndex, 'find'), $parameters);
      $this->lastQuery = $zend_query;

      // Sets global pager information, pages $hits array.
      $query->initializePager(count($hits));
      $hits = array_slice($hits, $query->getOffset(), $query->getLimit());

      // Builds array of LuceneapiHit objects.
      foreach ($hits as $hit) {
        $results[] = new LuceneapiZfLuceneapiHit($hit);
      }

    }
    catch (Exception $e) {
      if (0 === strpos($e->getMessage(), 'At least')) {
        form_set_error('keys', filter_xss($e->getMessage()));
      }
      else {
        // Exceptions should bubble up to searcher.
        throw $e;
      }
    }

    // Returns array of LuceneapiHit objects.
    return $results;
  }

  /**
   *
   */
  public function newDocument() {
    return new Zend_Search_Lucene_Document();
  }

  /**
   *
   */
  public function addDocument($document) {
    $this->zendIndex->addDocument($document);
  }

  /**
   *
   */
  public function deleteDocument($id) {
    $this->zendIndex->delete($id);
  }

  /**
   *
   */
  public function deleteDocumentByQuery(LuceneapiQuery $query) {
    $this->setIndexSettings();
    foreach ($this->zendIndex->find($query->convert()) as $hit) {
      $this->zendIndex->delete($hit->id);
    }
  }

  /**
   *
   */
  public function numDocuments() {
    return $this->zendIndex->numDocs();
  }

  /**
   *
   */
  public function addField($document, $field, $field_name, $text) {
    $document->addField(Zend_Search_Lucene_Field::$field['field type'](
      $field_name, $text, LUCENEAPI_ENCODING
    ));
  }

  /**
   *
   */
  public function wipeIndex() {
    for ($count = 0; $count < $this->zendIndex->maxDoc(); $count++) {
      $this->zendIndex->delete($count);
    }
    $this->zendIndex->optimize();
  }

  /**
   *
   */
  public function optimizeIndex() {
    $this->zendIndex->optimize();
  }

  /**
   *
   */
  public function flushIndex() {
    $this->zendIndex->commit();
  }

  /**
   * Allows for alterations to the index form.
   */
  public function indexSettingsForm(&$form, &$form_state, LuceneapiIndex $index) {

    //
    // Preprocessing
    //

    $form['preprocessing'] = array(
      '#type' => 'fieldset',
      '#title' => t('Preprocessing'),
      '#group' => 'settings',
      '#weight' => -35,
    );

    $form['preprocessing']['drupal_preprocessing'] = array(
      '#type' => 'checkbox',
      '#title' => t("Enable Drupal's preprocessing system"),
      '#default_value' => $index->getSetting('drupal_preprocessing'),
      '#description' => t('Using Drupal\'s preprocessing system allows for integration with contributed modules that provide functionality such as word stemming.'),
    );

    $options  = array(0 => t('No minimum'));
    $options += drupal_map_assoc(range(2, 10));
    $form['preprocessing']['min_word_length'] = array(
      '#type' => 'select',
      '#title' => t('Minimum word length'),
      '#options' => $options,
      '#default_value' => $index->getSetting('min_word_length'),
      '#description' => t('Terms shorter than this length are neither indexed nor searched. Note that this setting may effect facets, as values shorter than the specified length will not be indexed. Numeric values are <em>NOT</em> subject to this limitation.'),
    );

    $form['preprocessing']['stopwords'] = array(
      '#type' => 'textarea',
      '#title' => t('Stop words'),
      '#default_value' => $index->getSetting('stopwords'),
      '#description' => t(
        'A list of words that are not indexed. Words are separated by spaces and new lines. See the %directory directory for lists of stopwords in common languages.',
        array('%directory' => drupal_get_path('module', 'luceneapi') . '/conf')
      ),
    );

    //
    // Performance
    //

    $options  = array(0 => t('No minimum'));
    $options += drupal_map_assoc(range(1, 10));
    $form['performance']['minimum_prefix'] = array(
      '#type' => 'select',
      '#title' => t('Minimum wildcard prefix'),
      '#options' => $options,
      '#default_value' => $index->getSetting('minimum_prefix'),
      '#description' => t('The minimum number of non-wildcard characters required for wildcard queries.'),
    );

    $form['performance']['resultset_limit'] = array(
      '#type' => 'textfield',
      '#size' => 5,
      '#title' => t('Result set limit'),
      '#default_value' => $index->getSetting('resultset_limit'),
      '#description' => t('Helps limit score calculation when searching larger indexes. This greatly reduces both search time and memory consumption. Note that the first <i>n</i> number of results are returned, not the <i>n</i> best number of results. Set to <em>0</em> for no limit. A good starting point for larger indexes is <em>1000</em>.'),
    );

    $form['performance']['max_buffered_docs'] = array(
      '#type' => 'select',
      '#title' => t('Maximum buffered documents'),
      '#default_value' => $index->getSetting('max_buffered_docs'),
      '#options' => drupal_map_assoc(array(10, 20, 50, 100, 200, 500, 1000)),
      '#description' => t('The minimal number of documents required before the buffered in-memory documents are written into a new segment. Setting to a higher value may improve indexing performance but will also increase memory consumption.'),
    );

    $form['performance']['merge_factor'] = array(
      '#type' => 'select',
      '#title' => t('Merge factor'),
      '#default_value' => $index->getSetting('merge_factor'),
      '#options' => drupal_map_assoc(array(10, 20, 50, 100, 200, 500, 1000)),
      '#description' => t('Lower values increase the quality of unoptimized indexes, while larger values increase indexing performance. Setting the value too high may trigger the <em>too many open files </em> error determined by OS limitations.'),
    );

    //
    // Caching
    //

    $form['cache'] = array(
      '#type' => 'fieldset',
      '#title' => t('Caching'),
      '#group' => 'settings',
      '#weight' => -20,
    );

    $form['cache']['caching_enabled'] = array(
      '#type' => 'checkbox',
      '#title' => t('Cache search results'),
      '#default_value' => $index->getSetting('caching_enabled'),
      '#description' => t('Caching search results improves the performance of sites where repeated search queries are made.'),
    );

    $form['cache']['cache_threshold'] = array(
      '#type' => 'textfield',
      '#size' => 5,
      '#title' => t('Cache threshold'),
      '#default_value' => $index->getSetting('cache_threshold'),
      '#description' => t('Do not cache results larger than this threshold. Setting to <em>0</em> means there is no threshold.'),
    );

    $form['cache']['number_cached'] = array(
      '#type' => 'textfield',
      '#size' => 5,
      '#title' => t('Maximum size of cached result set'),
      '#default_value' => $index->getSetting('number_cached'),
      '#description' => t('The first <i>n</i> number of results in a result set will be cached. Setting to <em>0</em> will cache the maximum number of results the database will allow.'),
    );

    $form['cache']['actions'] = array(
      '#type' => 'actions',
    );

    $form['cache']['actions']['clear_cache'] = array(
      '#type' => 'submit',
      '#value' => t('Clear Search Lucene API cache'),
    );

    $form['cache']['actions']['clear_cache_description'] = array(
      '#type' => 'item',
      '#description' => t('Purge cached items related to this search page.'),
    );
  }

  /**
   * Allows for alterations to the searcher form.
   */
  public function searcherSettingsForm(&$form, &$form_state, LuceneapiSearcher $searcher) {

    //
    // Search page
    //

    $form['search_form']['default_operator'] = array(
      '#type' => 'select',
      '#title' => t('Default operator'),
      '#default_value' => $searcher->getSetting('default_operator'),
      '#options' => array(
        'and' => t('AND'),
        'or' => t('OR'),
      ),
      '#description' => t('Default operator for queries submitted through the search form.'),
    );
  }

  /**
   *
   */
  static public function defaultIndexSettings() {
    return array(
      'drupal_preprocessing' => 1,
      'min_word_length' => 0,
      'stopwords' => '',
      'minimum_prefix' => 3,
      'resultset_limit' => 0,
      'max_buffered_docs' => 10,
      'merge_factor' => 10,
      'caching_enabled' => 1,
      'cache_threshold' => 5000,
      'number_cached' => 0,
    );
  }

  /**
   *
   */
  static public function defaultSearcherSettings() {
    return array(
      'limit' => 10,
      'default_operator' => 'and',
      'highlighter' => 'zend_framework',
      'bias' => array(
        'body' => '1.0',
        'title' => '5.0',
        'name' => '3.0',
      ),
    );
  }
}

/**
 * The Zend Framework backend's implementation of the Query API.
 */
class LuceneapiZfQuery extends LuceneapiQuery {

  /**
   * Converts the query to Zend's query API.
   *
   * @return
   *   A Zend_Search_Lucene_Search_Query_Boolean object.
   */
  public function convert() {
    $query = new Zend_Search_Lucene_Search_Query_Boolean();
    foreach ($this->filters as $filter) {
      if ($subquery = $filter->execute()) {
        $query->addSubquery($subquery, $filter->getSign());
      }
    }
    $this->lastQuery = $query;
    return $query;
  }

}

/**
 *
 *
 */
class LuceneapiZfLuceneapiHit Extends LuceneapiHit {

  /**
   *
   */
  public function setId($hit) {
    $this->id = $hit->id;
  }

  /**
   *
   */
  public function setScore($hit) {
    $this->score = $hit->score;
  }

  /**
   *
   */
  public function getFieldValue($field) {
    try {
      return $this->hit->$field;
    }
    catch (Exception $e) {
      return '';
    }
  }
}

