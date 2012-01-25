<?php

/**
 * @file
 */

/**
 * Abstract class extended by all Search Lucene API indexers.
 */
abstract class LuceneapiIndexer {

  /**
   * The machine readable name of the indexer.
   */
  protected $_name;

  /**
   *
   */
  protected $_fields = array();

  /**
   * Loads settings, instantiates indexer.
   */
  public function __construct($indexer_module) {
    $this->_name = $indexer_module;
    $this->_fields = luceneapi_get_field_info($indexer_module);
  }

  /**
   * Returns the index name.
   */
  public function getName() {
    return $this->_name;
  }

  /**
   * Returns fields.
   */
  public function getFields() {
    return $this->_fields;
  }

  /**
   * Returns fields.
   */
  public function getField($field_name) {
    return isset($this->_fields[$field_name]) ? $this->_fields[$field_name]: FALSE;
  }

  /**
   * Hook that is invoked prior to the item being built for indexing.
   *
   * @param $item
   *   A mixed value containing the item being built.
   * @param $index
   *   A LuceneapiIndex object.
   */
  public function preBuildItem($item, LuceneapiIndex $index) {
    // Is there anything that needs to be done prior to building and indexing
    // the item?  Do you have to update the queue, for example?
  }

  /**
   * Hook that is invoked prior to adding the document to the index. This is
   * usually used to remove the old document from the index.
   *
   * @param $item
   *   A mixed value containing the item being built.
   * @param $index
   *   A LuceneapiIndex object.
   */
  public function preAddDocument($item, LuceneapiIndex $index) {
    // Do we need to remove the old document?
  }

  /**
   * Builds the item for indexing.
   *
   * @param $item
   *   A mixed value containing the item being built.
   * @return
   *   A mixed value containing the built item.
   */
  abstract public function buildItem($item, LuceneapiIndex $index);

  /**
   * Builds the search result.
   *
   */
  abstract public function buildResult(LuceneapiHit $hit, LuceneapiSearcher $searcher);

  /**
   * Returns items that are queued to be indexed.
   *
   * @param $index
   *   A LuceneapiIndex object.
   * @param $length
   *   An integer containing the number if items to return.
   */
  abstract public function getQueue(LuceneapiIndex $index, $length = 0);

  /**
   * Clears the index queue so that all content is reindexed.
   *
   * @param $index
   *   A LuceneapiIndex object.
   */
  abstract public function resetQueue(LuceneapiIndex $index);

  /**
   * Allows for alterations to the index form.
   */
  public function indexSettingsForm(&$form, &$form_state, LuceneapiIndex $index) {
  }

  /**
   * Allows for alterations to the searcher form.
   */
  public function searcherSettingsForm(&$form, &$form_state, LuceneapiSearcher $searcher) {
  }

  /**
   *
   */
  static public function defaultIndexSettings() {
    return array();
  }

  /**
   *
   */
  static public function defaultSearcherSettings() {
    return array();
  }

}
