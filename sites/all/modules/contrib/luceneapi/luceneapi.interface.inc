<?php

/**
 * @file
 * Search Lucene API interfaces.
 */

/**
 *
 */
interface LuceneapiFilterKeysInterface {

  /**
   * Hook that allows for instantiating the plugin and setting the default
   * arguments through calls to LuceneapiQuery::addFilter().
   *
   * @param $text
   *   A string containing the search keys entered by the user.
   * @param $searcher
   *   Optionally allows developers to pass the $searcher object.
   *
   * @return
   *   A LuceneapiFilter object.
   */
  public function setArguments($text, $searcher = NULL);
}

/**
 *
 */
interface LuceneapiFilterTermInterface {

  /**
   * Hook that allows for instantiating the plugin and setting the default
   * arguments through calls to LuceneapiQuery::addFilter().
   *
   * @param $text
   *   A string containing the term text.
   * @param $field
   *   The field being filtered.
   * @param $sign
   *   The sign flagging how the filter should be applied.
   * @param $boost
   *   How much relevance is placed on the filter in scoring operations.
   *
   * @return
   *   A LuceneapiFilter object.
   */
  public function setArguments($text, $field = NULL, $sign = TRUE, $boost = '1.0');
}
