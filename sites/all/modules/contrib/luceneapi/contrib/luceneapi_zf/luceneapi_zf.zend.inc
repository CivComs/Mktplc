<?php

/**
 * @file
 * Classes that extend Zend Framework classes. These classes can be lazy-loaded
 * by Drupal's registry since they extend Zend classes which are not registered.
 */

/**
 * Adds a token filter that uses Drupal's preprocessing hooks.
 */
class LuceneapiTokenFilterDrupal extends Zend_Search_Lucene_Analysis_TokenFilter {

  /**
   * Invokes hook_search_preprocess().
   *
   * We don't call search_invoke_preprocess() directly so we don't have to
   * depend on the core search module.
   *
   * @param $src_token
   *   A Zend_Search_Lucene_Analysis_Token object.
   *
   * @return
   *   A Zend_Search_Lucene_Analysis_Token object.
   *
   * @see search_invoke_preprocess()
   */
  public function normalize(Zend_Search_Lucene_Analysis_Token $src_token) {
    // Gets token text, invokes hook_search_preprocess().
    $processed_text = $src_token->getTermText();
    foreach (module_implements('search_preprocess') as $module) {
      $processed_text = module_invoke($module, 'search_preprocess', $processed_text);
    }

    // Returns the new processed token.
    $new_token = new Zend_Search_Lucene_Analysis_Token(
      $processed_text,
      $src_token->getStartOffset(),
      $src_token->getEndOffset()
    );
    $new_token->setPositionIncrement($src_token->getPositionIncrement());
    return $new_token;
  }
}

/**
 * Adds a "ShortWords" token filter to facilitate our minimum word length
 * setting. This filter ignores numeric values.
 */
class LuceneapiTokenFilterShortWords extends Zend_Search_Lucene_Analysis_TokenFilter_ShortWords {

  /**
   * Filters non-numeric shortwords.
   *
   * @param $src_token
   *   A Zend_Search_Lucene_Analysis_Token object.
   *
   * @return
   *   A Zend_Search_Lucene_Analysis_Token object.
   */
  public function normalize(Zend_Search_Lucene_Analysis_Token $src_token) {
    if (!is_numeric($src_token->getTermText())) {
      return parent::normalize($src_token);
    }
    else {
      return $src_token;
    }
  }
}
