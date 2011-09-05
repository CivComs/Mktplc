<?php

/**
 * @file
 */

/**
 *
 */
class LuceneapiHighlighterSummary extends LuceneapiHighlighter {

  /**
   *
   */
  public function execute() {
    return truncate_utf8($this->text, 255);
  }
}
