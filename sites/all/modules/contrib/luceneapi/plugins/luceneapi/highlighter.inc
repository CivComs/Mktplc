<?php

/**
 * @file
 */

/**
 *
 */
class LuceneapiHighlighter {

  /**
   * The text being
   *
   * @var string
   */
  protected $string;

  /**
   * The searcher object.
   *
   * @var LuceneapiSearcher
   */
  protected $searcher;

  /**
   *
   */
  public function __construct($text, LuceneapiSearcher $searcher) {
    $this->text = $text;
    $this->searcher = $searcher;
  }

  /**
   *
   */
  public function execute() {
    return $text;
  }

  /**
   *
   */
  public function __toString() {
    return $this->execute();
  }
}
