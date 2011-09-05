<?php

/**
 * @file
 */

/**
 * Abstracts interactions with the backend.
 */
abstract class LuceneapiBackend implements Countable {

  /**
   *
   */
  protected $index;

  /**
   *
   */
  public function __construct(LuceneapiIndex $index) {
    $this->index = $index;
    $index->registerPlugin('highlighters', 'summary');
  }

  /**
   * Returns an instance of a LuceneapiQuery object.
   */
  abstract public function newQuery();

  /**
   * Implements the countable interface, returns the number of documents in the
   * index.
   *
   * @return
   *   An integer containing the number of documents in the index.
   */
  public function count() {
    return $this->numDocuments();
  }

  /**
   * @todo Make documents simple arrays.
   */
  abstract public function newDocument();

  /**
   * @todo If documents are arrays, this method won't be needed.
   */
  abstract public function addField($document, $field, $field_name, $text);

  /**
   *
   */
  abstract public function addDocument($document);

  /**
   *
   */
  abstract public function deleteDocument($id);

  /**
   *
   */
  abstract public function deleteDocumentByQuery(LuceneapiQuery $query);

  /**
   *
   */
  abstract public function numDocuments();

  /**
   *
   */
  abstract public function wipeIndex();

  /**
   *
   */
  abstract public function optimizeIndex();

  /**
   *
   */
  abstract public function flushIndex();

  /**
   *
   * @return
   *   An array of LuceneapiHit objects.
   */
  abstract public function search(LuceneapiQuery $query, LuceneapiSearcher $searcher);

  /**
   *
   */
  public function buildQuery() {
  }

  /**
   * Hook fired before batch indexing begins.
   */
  public function preIndexItems() {
    // @todo Give some use cases.
    // Nothing to do ...
  }

  /**
   * Hook fired after batch indexing has completed.
   */
  public function postIndexItems() {
    // @todo Give some use cases.
    // Nothing to do ...
  }

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
  }

  /**
   *
   */
  static public function defaultSearcherSettings() {
  }

}
