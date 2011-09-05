<?php

/**
 * @file
 * Abstract classes and base classes.
 */

/**
 * Extended by classes that load settings via the CTools export component.
 */
abstract class LuceneapiSettings {

  /**
   * An object containing the settings loaded via the CTools export API.
   *
   * @var stdClass
   */
  protected $settings;

  /**
   * A registry of plugin definitions grouped by type.
   *
   * @var array
   */
  protected $plugins = array();

  /**
   * Loads settings via the CTools API function, throws an Exception if the
   * settings could not be loaded.
   *
   * @param $name
   *   A string containing the name of the configuration.
   *
   * @throws Exception
   * @see ctools_export_crud_load()
   */
  public function __construct($name) {
    ctools_include('export');
    if (!$this->settings = ctools_export_crud_load($this->getTable(), $name)) {
      throw new Exception(t(
        'Setting %name not defined in table %table.',
        array('%name' => $name, '%table' => $this->getTable())
      ));
    }
  }

  /**
   * Returns the table that stores the configuration.
   *
   * @return
   *   A string containing the table.
   */
  abstract public function getTable();

  /**
   * Gets the machine readable name of the configuration.
   *
   * @return
   *   A string containing the machine readable name of the configuration.
   */
  public function getName() {
    return $this->settings->name;
  }

  /**
   * Gets the human readable name of the configuration.
   *
   * @return
   *   A string containing the machine readable name of the configuration.
   */
  public function getLabel() {
    return $this->settings->label;
  }

  /**
   * Gets the description of the configuration.
   *
   * @return
   *   A string containing the machine readable name of the configuration.
   */
  public function getDescription() {
    return $this->settings->description;
  }

  /**
   * Retrieves the settings loaded via the CTools API.
   *
   * @return
   *   An object containing the settings.
   */
  public function getSettings() {
    return $this->settings;
  }

  /**
   * Uses the CTools to convert the settings to something that is exportable.
   *
   * @return
   *   The export value.
   */
  public function getExport() {
    return ctools_export_crud_export($this->getTable(), $this->settings);
  }

  /**
   * Safely retrieves the value of a setting.
   *
   * @param $settings
   *   A string containing the name of the setting.
   *
   * @return
   *   The settings value, NULL if the setting is not stored.
   */
  public function getSetting($setting) {
    if (isset($this->settings->settings[$setting])) {
      return $this->settings->settings[$setting];
    }
  }

  /**
   * Registers a plugin.
   *
   * @param $type
   *   The type of plugin.
   * @param $id
   *   The id of the specific plugin to register.
   *
   * @return
   *   An instance of this class.
   */
  public function registerPlugin($type, $id) {
    $this->plugins[$type][$id] = ctools_get_plugins('luceneapi', $type, $id);
    return $this;
  }

  /**
   * Unregisters a plugin.
   *
   * @param $type
   *   The type of plugin.
   * @param $id
   *   The id of the specific plugin to unregister.
   *
   * @return
   *   An instance of this class.
   */
  public function unregisterPlugin($type, $id) {
    unset($this->plugins[$type][$id]);
    return $this;
  }

  /**
   * Returns registered plugins.
   *
   * @param $type
   *   The type of plugin.
   *
   * @return
   *   An array containing the registered plugins.
   */
  public function getPlugins($type = NULL) {
    if (NULL !== $type) {
      return isset($this->plugins[$type]) ? $this->plugins[$type] : array();
    }
    else {
      return $this->plugins;
    }
  }

  /**
   * Returns a registered plugin definition.
   *
   * @param $type
   *   The type of plugin.
   * @param $id
   *   The id of the specific plugin being returned.
   *
   * @return
   *   An array containing the plugin.
   */
  public function getPlugin($type, $id) {
    if (!empty($this->plugins[$type][$id])) {
      return $this->plugins[$type][$id];
    }
    else {
      return FALSE;
    }
  }
}

/**
 * Abstract class extended by the backend that interacts with the index.
 */
class LuceneapiIndex extends LuceneapiSettings {

  /**
   * The backend plugin.
   *
   * @var LuceneapiBackend
   */
  protected $backend;

  /**
   * The indexer plugin.
   *
   * @var LuceneapiIndexer
   */
  protected $indexer;

  /**
   * An array of instantiated normalizer plugins.
   *
   * @var array
   */
  protected $normalizers = array();

  /**
   * Maps query types to plugin classes.
   *
   * @var array
   */
  protected $filters = array();

  /**
   * Loads settings, instantiates indexer and backend objects.
   */
  public function __construct($name) {
    parent::__construct($name);

    // Loads backend object.
    if (empty($this->settings->backend)) {
      throw new Exception(t(
        'Backend required for index "@name".',
        array('@name' => $this->settings->backend)
      ));
    }

    // Loads the backend plugin class.
    if ($class = luceneapi_get_plugin_class('backends', $this->settings->backend)) {
      $this->backend = new $class($this);
    }
    else {
      throw new Exception(t(
        'Error loading "@plugin" plugin.',
        array('@plugin' => $this->settings->backend)
      ));
    }

    // Loads the indexer object.
    if (empty($this->settings->indexer)) {
      throw new Exception(t(
        'Indexer required for index "@name".',
        array('@name' => $name)
      ));
    }
    elseif (!$this->indexer = luceneapi_indexer_load($this->settings->indexer)) {
      throw new Exception(t(
        'Error loading "@plugin" plugin.',
        array('@plugin' => $this->settings->indexer)
      ));
    }

    // Allows modules to alter the index.
    module_invoke_all('luceneapi_index_open', $this);

    // Instantiates normalizer plugins.
    // @todo Let's figure out how to lazy load these.
    foreach ($this->getPlugins('normalizers') as $plugin) {
      $class = ctools_plugin_get_class($plugin, 'handler');
      $type = call_user_func(array($class, 'getDataType'));
      $instance = new $class();
      $this->normalizers[$type][] = $instance;
    }

    // Registers query type plugins by class.
    foreach ($this->getPlugins('filters') as $plugin) {
      $class = ctools_plugin_get_class($plugin, 'handler');
      $type = call_user_func(array($class, 'getType'));
      $this->filters[$type] = $class;
    }
  }

  /**
   * Returns the table storing the index configurations.
   */
  public function getTable() {
    return 'luceneapi_index';
  }

  /**
   * Returns the backend.
   */
  public function getBackend() {
    return $this->backend;
  }

  /**
   * Returns the indexer.
   */
  public function getIndexer() {
    return $this->indexer;
  }

  /**
   *
   */
  public function getFields() {
    return $this->indexer->getFields();
  }

  /**
   *
   */
  public function getEnabledFields() {
    return array_intersect_key(
      $this->indexer->getFields(),
      array_filter($this->getSetting('enabled_fields'))
    );
  }

  /**
   *
   */
  public function getSortableFields() {
    return array_intersect_key(
      array_filter($this->getFields(), 'luceneapi_filter_sortable_field'),
      $this->getEnabledFields()
    );
  }

  /**
   *
   */
  public function getBiasFields() {
    return array_intersect_key(
      array_filter($this->getFields(), 'luceneapi_filter_bias_field'),
      $this->getEnabledFields()
    );
  }

  /**
   * Helper function that instantiates a filter instance.
   *
   * @param $type
   *   A string containing the type of filter, i.e. "term", "wildcard", etc.
   *
   * @return
   *   An LuceneapiFilter object.
   */
  public function getFilter($type) {
    if (isset($this->filters[$type])) {
      return new $this->filters[$type]($this);
    }
    else {
      throw new Exception(t(
        'Filter "@type" not registered.',
        array('@type' => $type)
      ));
    }
  }

  /**
   * Calls the normalize hook in the appropriate normalizer class to act on the
   * text.
   *
   * @param $text
   *   A string containing the text.
   * @param $field
   *   An array containing the field definitions or a string containing the
   *   name of the field.
   *
   * @return
   *   A string containing the normalized text.
   */
  public function normalizeText($text, $field) {
    if (is_array($field) || ($field = $this->indexer->getField($field))) {
      if (isset($this->normalizers[$field['data type']])) {
        foreach ($this->normalizers[$field['data type']] as $normalizer) {
          $text = $normalizer->execute($text, $field['data type options']);
        }
      }
    }
    return $text;
  }

  /**
   * Returns content queued to be indexed.
   */
  public function getQueue() {
    $limit = $this->getSetting('update_limit');
    return $this->getIndexer()->getQueue($this, $limit);
  }

  /**
   * Indexes all items in the queue.
   */
  public function indexItems() {
    $vars = array('@name' => $this->getName());
    watchdog('luceneapi', 'Index update started: @name', $vars);
    $this->backend->preIndexItems();
    foreach ($this->getQueue() as $item) {
      try {
        $this->indexItem($item);
      }
      catch (Exception $e) {
        watchdog_exception('luceneapi', $e);
      }
    }
    $this->backend->postIndexItems();
    watchdog('luceneapi', 'Index update complete: @name', $vars);
  }

  /**
   * Indexes an item.
   *
   * @param $item
   *   An object containing the item being indexed.
   */
  public function indexItem($item) {
    try {

      // Invokes preBuildItem() hook, builds item for indexing.
      $this->indexer->preBuildItem($item, $this);
      $build = $this->indexer->buildItem($item, $this);

      // Instantiates document, iterates over fields and adds to document.
      $document = $this->backend->newDocument();
      foreach ($this->getEnabledFields() as $field_name => $field) {

        // Extracts text through the field's extract callback.
        $arguments = array($build, $field);
        if (!empty($field['extract arguments'])) {
          $arguments = array_merge($arguments, $field['extract arguments']);
        }
        $text = call_user_func_array($field['extract callback'], $arguments);
        if (FALSE === $text) {
          $text = (isset($field['default value'])) ? $field['default value'] : '';
        }

        // Did the extract callback return text, or text for multiple fields?
        // An example of where multiple fields are returned is the nodeaccess
        // extract callback luceneapi_node_extract_nodeaccess().
        $index_fields = (!is_array($text)) ? array($field_name => $text) : $text;

        // Iterate over all fields to be indexed, normalizes text and adds to
        // the Lucene document.
        foreach ($index_fields as $index_field_name => $text) {
          $text = $this->normalizeText($text, $field);
          $this->backend->addField($document, $field, $index_field_name, $text);
        }
      }

      // Invokes the preAddDocument() hook, adds the document to index.
      $this->indexer->preAddDocument($item, $this);
      $this->backend->addDocument($document);
    }
    catch (Exception $e) {
      watchdog_exception('luceneapi', $e);
    }
  }
}

/**
 * Performs searches.
 */
class LuceneapiSearcher extends LuceneapiSettings {

  /**
   * The LuceneapiIndex object associate with this searcher.
   *
   * @var LuceneapiIndex
   */
  protected $index;

  /**
   *
   * @var array
   */
  protected $pathInfo;

  /**
   * The highlighter class name.
   *
   * @var string
   */
  protected $highlighterClassName;

  /**
   * Loads the index object.
   */
  public function __construct($name) {
    parent::__construct($name);

    // Instantiates the backend class.
    if (empty($this->settings->index_name)) {
      throw new Exception(t(
        'Index required for searcher "@name".',
        array('@name' => $name)
      ));
    }

    if (!$this->index = luceneapi_index_load($this->settings->index_name)) {
      throw new Exception(t(
        'Error loading index "@name".',
        array('@name' => $this->settings->index_name)
      ));
    }

    // Loads the highlighter class name.
    $plugin = $this->index->getPlugin('highlighters', $this->getSetting('highlighter'));
    $this->highlighterClassName = ctools_plugin_get_class($plugin, 'handler');
  }

  /**
   *
   */
  public function getTable() {
    return 'luceneapi_searcher';
  }

  /**
   * Returns the LuceneapiIndex object associated with this searcher.
   *
   * @return
   *   A LuceneapiIndex object.
   */
  public function getIndex() {
    return $this->index;
  }

  /**
   * Returns an instantiated highlighter plugin.
   *
   * @param $text
   *   A string containing the text to be highlighted.
   *
   * @return
   *   A LuceneapiHighlighter instance.
   *
   * @todo Error handling
   */
  public function getHighlighter($text) {
    return new $this->highlighterClassName($text, $this);
  }

  /**
   * Returns the parsed search path.
   *
   * @return
   *   An array containing the parsed search path.
   */
  public function parseSearchPath() {
    if (NULL === $this->pathInfo) {
      // Parses the path information.
      $path = $this->getSettings()->search_path;
      $this->pathInfo = luceneapi_parse_search_path($path);

      // Applies defaults from settings.
      if (!$this->pathInfo['values']['limit']) {
        $this->pathInfo['values']['limit'] = $this->getSetting('limit');
      }
      if (!$this->pathInfo['values']['sort']) {
        // @todo Implement this setting.
      }

    }
    return $this->pathInfo;
  }

  /**
   * Instantiates a new query object.
   *
   * @return
   *   A LuceneapiQuery object.
   */
  public function newQuery() {
    return $this->index->getBackend()->newQuery();
  }

  /**
   * Executes a search, returns the matches.
   *
   * @param $query
   *   An LuceneapiQuery object containing the search query.
   * @return
   *   An array of search "hits".
   */
  public function search(LuceneapiQuery $query) {
    try {
      return $this->index->getBackend()->search($query, $this);
    }
    catch (Exception $e) {
      luceneapi_handle_exception($e);
    }
    return array();
  }

  /**
   *
   */
  public function getTotalRows() {
    return $this->index->getBackend()->getTotalRows();
  }

  /**
   * Builds the search result for the matched item.
   *
   * @param $hit
   *   A LuceneapiHit object.
   * @return
   *   An array suitable for theming.
   * @todo Error handling
   */
  public function buildResult(LuceneapiHit $hit) {
    return $this->index->getIndexer()->buildResult($hit, $this);
  }
}

/**
 *
 *
 */
abstract class LuceneapiHit {

  /**
   *
   */
  public $id;

  /**
   *
   */
  public $score;

  /**
   *
   */
  protected $hit;

  /**
   *
   */
  public function __construct($hit) {
    $this->hit = $hit;
    $this->setId($hit);
  }

  /**
   *
   */
  abstract public function setId($hit);

  /**
   *
   */
  abstract public function setScore($hit);

  /**
   *
   */
  abstract public function getFieldValue($field);

  /**
   *
   */
  public function __get($field) {
    return $this->getFieldValue($field);
  }
}

/**
 * Base class for filter plugins.
 */
abstract class LuceneapiFilter {

  /**
   * The index being searched.
   *
   * @var LuceneapiIndex
   */
  protected $index;

  /**
   * The field being filtered.
   *
   * @var string
   */
  protected $field;

  /**
   * The text being filtered.
   *
   * @var string
   */
  protected $text = '';

  /**
   * The boost factor for the filter.
   *
   * @var string
   */
  protected $boost = 1.0;

  /**
   * A boolean or NULL flagging the sign of the filter.
   *
   * @var boolean|NULL
   */
  protected $sign = NULL;

  /**
   * Sets the index.
   *
   * @param $index
   *   A LuceneapiIndex object.
   */
  public function __construct(LuceneapiIndex $index) {
    $this->index = $index;
  }

  /**
   * Defines the type of filter, i.e. "term", "wildcard", etc.
   *
   * @var string
   */
  abstract public static function getType();

  /**
   * Sets the field being searched.
   *
   * @param $field
   *   A string|NULL value containing the field.
   *
   * @return
   *   An instance of this class.
   */
  public function setField($field) {
    $this->field = $field;
    return $this;
  }

  /**
   *
   */
  public function getField() {
    return $this->field;
  }

  /**
   *
   * @return
   *   An instance of this class.
   */
  public function setText($text) {
    $this->text = $text;
    return $this;
  }

  /**
   *
   */
  public function getText() {
    return $this->text;
  }

  /**
   *
   * @return
   *   An instance of this class.
   */
  public function setBoost($boost) {
    $this->boost = $boost;
    return $this;
  }

  /**
   *
   */
  public function getBoost() {
    return $this->boost;
  }

  /**
   * Sets the sign.
   *
   * @param $sign
   *   A boolean|NULL value denotig the sign.
   *
   * @return
   *   An instance of this class.
   */
  public function setSign($sign) {
    $this->sign = $sign;
    return $this;
  }

  /**
   * Returns the sign associated with the filter.
   *
   * @return
   *   A boolean or NULL denoting the sign.
   */
  public function getSign() {
    return $this->sign;
  }

  /**
   * Performs the conversion to the backend's native query API.
   *
   * @return
   *   A mixed value containing the query clause.
   */
  abstract public function execute();
}

/**
 * Base for query builders.
 */
abstract class LuceneapiQuery {

  /**
   * The index being queried.
   *
   * @var LuceneapiIndex
   */
  protected $index;

  /**
   * An array of sorts.
   *
   * @var array
   */
  protected $sorts = array();

  /**
   * An array of filters.
   *
   * @var array
   */
  protected $filters = array();

  /**
   * The number for results to return.
   *
   * @var int
   */
  protected $limit;

  /**
   * The zero-based offset of where the resultset should start.
   *
   * @var int
   */
  protected $offset;

  /**
   * The total number of rows returned by the query.
   *
   * @var int
   */
  protected $totalRows = 0;

  /**
   * Stores the query in the backend's native API after it was converted by
   * the LuceneapiQuery::convert() method.
   *
   * @var mixed
   */
  protected $lastQuery;

  /**
   * Initializes the query, stores the index.
   *
   * @param $index
   *   A LuceneapiIndex object containing the index being searched.
   */
  public function __construct(LuceneapiIndex $index) {
    $this->index = $index;
  }

  /**
   * Returns the index object associated with this query.
   *
   * @return
   *   A LuceneapiIndex object.
   */
  public function getIndex() {
    return $this->index;
  }

  /**
   * Returns the index object associated with this query.
   *
   * @return
   *   A LuceneapiIndex object.
   */
  public function getLastQuery() {
    return $this->lastQuery;
  }

  /**
   * Add a sort to the query.
   *
   * @param $field
   *   A string containing the machine readable name of the field.
   * @param $order
   *   An integer containing the order, see the SORT_* constants.
   *
   * @return
   *   An instance of this class.
   */
  public function addSort($field, $order = SORT_ASC) {
    $this->sorts[$field] = (SORT_ASC == $order) ? SORT_ASC : SORT_DESC;
    return $this;
  }

  /**
   * Returns an array of sort orders keyed by field name.
   *
   * @return
   *   An array of sorts.
   */
  public function getSorts() {
    return $this->sorts;
  }

  /**
   * Add a field to the query.
   *
   * @param $filter
   *   A LuceneapiFilter object containing the filter.
   *
   * @return
   *   An instance of this class.
   */
  public function addFilter($filter) {
    if (!$filter instanceof LuceneapiFilter) {
      $filter = $this->getFilter($filter);
      if (method_exists($filter, 'setArguments')) {
        $args = func_get_args();
        array_shift($args);
        call_user_func_array(array($filter, 'setArguments'), $args);
      }
    }
    $this->filters[] = $filter;
    return $this;
  }

  /**
   * Helper function that instantiates a filter instance.
   *
   * @param $type
   *   A string containing the type of filter, i.e. "term", "wildcard", etc.
   *
   * @return
   *   A LuceneapiFilter object.
   */
  public function getFilter($type) {
    return $this->index->getFilter($type);
  }

  /**
   * Sets the number of results to return.
   *
   * @param $limit
   *   The number of records to return from the result set.
   *
   * @return
   *   An instance of this class.
   */
  public function setLimit($limit) {
    $this->limit = $limit;
    return $this;
  }

  /**
   * Gets number of results to return.
   *
   * @return
   *   An integer containing the limit.
   */
  public function getLimit() {
    return $this->limit;
  }

  /**
   * Sets the number to start on.
   *
   * @param $offset
   *   The number of records to return from the result set.
   *
   * @return
   *   An instance of this class.
   */
  public function setOffset($offset) {
    $this->offset = $offset;
  }

  /**
   * Gets the offset.
   *
   * @return
   *   An integer containing the offset.
   */
  public function getOffset() {
    return $this->offset;
  }

  /**
   * Sets the total number of rows returned by the query.
   *
   * @param $total_rows
   *   The total number of rows returned by the query.
   *
   * @return
   *   An instance of this class.
   */
  public function setTotalRows($total_rows) {
    $this->totalRows = $total_rows;
    return $this;
  }

  /**
   * Gets the total number of rows returned by the query.
   *
   * @return
   *   An integer containing the total number of rows.
   */
  public function getTotalRows($total_rows) {
    return $this->totalRows;
  }

  /**
   * Initializes pager information if the limit is set and the offset is not.
   *
   * @param $total_rows
   *   An integer containing the total number of rows returned by the query.
   *
   * @return
   *   An instance of this class.
   */
  public function initializePager($total_rows) {
    $this->totalRows = $total_rows;
    if ($this->limit && NULL === $this->offset) {
      $element = PagerDefault::$maxElement++;
      $page = pager_default_initialize($this->totalRows, $this->limit, $element);
      $this->offset = $page * $this->limit;
    }
    return $this;
  }

  /**
   * Converts the query into the backend's native API.
   *
   * NOTE: Remember to set the LuceneapiQuery::lastQuery property!
   *
   * @return
   *   A mixed value containing the object.
   */
  abstract public function convert();
}

/**
 * Base class for normalizer plugins.
 */
abstract class LuceneapiNormalizer {

  /**
   * Returns the data type.
   *
   * @return
   *   A string containing the data type.
   */
  abstract static public function getDataType();

  /**
   * Normalizes the text.
   *
   * @param $text
   *   A string containing the text being normalized.
   * @param $options
   *   An array of additional options used to normalize the text.
   *
   * @return
   *   A string containing the normalized text.
   */
  abstract public function execute($text, array $options);
}

/**
 * Base class for term filters.
 */
class LuceneapiFilterTerm extends LuceneapiFilter implements LuceneapiFilterTermInterface {

  /**
   * Returns the type of query.
   *
   * @return
   *   A string containing the query type.
   */
  static public function getType() {
    return 'term';
  }

  /**
   * Sets arguments.
   */
  public function setArguments($text, $field = NULL, $sign = TRUE, $boost = '1.0') {
    $this->field = $field;
    $this->sign = $sign;
    $this->boost = $boost;

    // Normalizes text if necessary.
    if (NULL !== $this->field) {
      $this->text = $this->index->normalizeText($text, $field);
    }
    else {
      $this->text = $text;
    }
  }

  /**
   * Performs the conversion to the backend's native query API.
   *
   * @return
   *   A mixed value containing the query clause.
   */
  public function execute() {
    // This still has the be implemented...
  }
}

/**
 * Base class for term filters.
 */
class LuceneapiFilterKeys extends LuceneapiFilter implements LuceneapiFilterKeysInterface {

  /**
   * The searcher object.
   *
   * @var LuceneapiSearcher
   */
  protected $searcher;

  /**
   * Ensures the search keys are required by default.
   *
   * @var boolean|NULL
   */
  protected $sign = TRUE;

  /**
   * Returns the type of query.
   *
   * @return
   *   A string containing the query type.
   */
  static public function getType() {
    return 'keys';
  }

  /**
   * Hook that allows for instantiating the plugin and setting the default
   * arguments through calls to LuceneapiQuery::addFilter().
   */
  public function setArguments($text, $searcher = NULL) {
    $this->text = $text;
    if ($searcher instanceof LuceneapiSearcher) {
      $this->searcher = $searcher;
    }
  }

  /**
   * Sets the searcher object so we can pull the bias fields.
   *
   * @param $searcher
   *   A LuceneapiSearcher object.
   * @return
   *   An instance of this class.
   */
  public function setSearcher(LuceneapiSearcher $searcher) {
    $this->searcher = $searcher;
    return $this;
  }

  /**
   * Performs the conversion to the backend's native query API.
   *
   * @return
   *   A mixed value containing the query clause.
   */
  public function execute() {
    // This still has the be implemented...
  }
}
