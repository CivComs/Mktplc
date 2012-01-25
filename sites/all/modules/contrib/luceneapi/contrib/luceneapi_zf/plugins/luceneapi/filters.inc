<?php

/**
 * @file
 * Contains Zend Framework query type plugins.
 */

/**
 *
 */
class LuceneapiZfLuceneapiFilterTerm extends LuceneapiFilterTerm {

  /**
   * Returns a query.
   *
   * @return
   *   A Zend_Search_Lucene_Search_Query object.
   */
  public function execute() {
    $query = new Zend_Search_Lucene_Search_Query_Term(
      new Zend_Search_Lucene_Index_Term($this->text, $this->field)
    );
    $query->setBoost($this->boost);
    return $query;
  }
}

/**
 * Plugin for filtering by keys entered by the user.
 */
class LuceneapiZfLuceneapiFilterKeys extends LuceneapiFilterKeys {

  /**
   * Stores the bias field settings.
   *
   * @var array
   */
  protected $biasFields;

  /**
   * Returns a query.
   *
   * @return
   *   A Zend_Search_Lucene_Search_Query object.
   */
  public function execute() {
    $query = Zend_Search_Lucene_Search_QueryParser::parse($this->text);
    if (NULL !== $this->searcher) {
      if (!$this->biasFields) {
        $this->biasFields = array_filter($this->searcher->getSetting('bias'));
      }
      $query = $this->rebuildQuery($query, $this->searcher);
    }
    return $query;
  }

  /**
   * Rebuilds a Zend query object to make use of the bias settings.
   *
   * @param $old_query
   *   A Zend_Search_Lucene_Search_Query object.
   *
   * @return
   *   A Zend_Search_Lucene_Search_Query object.
   */
  public function rebuildQuery(Zend_Search_Lucene_Search_Query $query) {
    $parts = explode('_', get_class($query));
    $method = 'rebuild' . $parts[count($parts) - 1] . 'Query';
    return method_exists($this, $method) ? $this->$method($query) : $query;
  }

  /**
   * Rebuilds a boolean query for use with bias settings.
   *
   * @param $old_query
   *   A Zend_Search_Lucene_Search_Query_Boolean object containing the original
   *   query.
   *
   * @return
   *   A Zend_Search_Lucene_Search_Query_Boolean object.
   */
  public function rebuildBooleanQuery(Zend_Search_Lucene_Search_Query_Boolean $old_query) {
    $new_query = new Zend_Search_Lucene_Search_Query_Boolean();
    $new_query->setBoost($old_query->getBoost());
    $signs = $old_query->getSigns();
    foreach ($old_query->getSubqueries() as $key => $subquery) {
      if ($new_subquery = $this->rebuildQuery($subquery)) {
        $new_query->addSubquery($new_subquery, $signs[$key]);
      }
    }
    return $new_query;
  }

  /**
   * Rebuilds a fuzzy query for use with bias settings.
   *
   * @param $old_query
   *   A Zend_Search_Lucene_Search_Query_Preprocessing_Fuzzy object containing the
   *   original query.
   *
   * @return
   *   A Zend_Search_Lucene_Search_Query_Boolean object.
   */
  public function rebuildFuzzyQuery(Zend_Search_Lucene_Search_Query_Preprocessing_Fuzzy $old_query) {
    if (NULL === $old_query->getField()) {
      $new_query = new Zend_Search_Lucene_Search_Query_Boolean();
      foreach ($this->biasFields as $field => $bias) {
        $word = $this->index->normalizeText($old_query->getWord(), $field);
        $subquery = new Zend_Search_Lucene_Search_Query_Preprocessing_Fuzzy(
          $word, LUCENEAPI_ENCODING, $field, $old_query->getMinimumSimilarity()
        );
        $subquery->setBoost($old_query->getBoost() * $bias);
        $new_query->addSubquery($subquery);
      }
    }
    else {
      $word = $this->index->normalizeText($old_query->getWord(), $old_query->getField());
      $new_query = new Zend_Search_Lucene_Search_Query_Preprocessing_Fuzzy(
        $word, LUCENEAPI_ENCODING, $old_query->getField(), $old_query->getMinimumSimilarity()
      );
      $new_query->setBoost($old_query->getBoost());
    }
    return $new_query;
  }

  /**
   * Rebuilds a phrase query for use with bias settings.
   *
   * @param $old_query
   *   A Zend_Search_Lucene_Search_Query_Preprocessing_Phrase object containing
   *   the original query.
   *
   * @return
   *   A Zend_Search_Lucene_Search_Query_Boolean object.
   */
  public function rebuildPhraseQuery(Zend_Search_Lucene_Search_Query_Preprocessing_Phrase $old_query) {
    if (NULL === $old_query->getField()) {
      $new_query = new Zend_Search_Lucene_Search_Query_Boolean();
      foreach ($this->biasFields as $field => $bias) {
        $phrase = $this->index->normalizeText($old_query->getPhrase(), $field);
        $subquery = new Zend_Search_Lucene_Search_Query_Preprocessing_Phrase(
          $phrase, LUCENEAPI_ENCODING, $field
        );
        $subquery->setBoost($old_query->getBoost() * $bias);
        $subquery->setSlop($old_query->getSlop());
        $new_query->addSubquery($subquery);
      }
    }
    else {
      $phrase = $this->index->normalizeText($old_query->getPhrase(), $old_query->getField());
      $new_query = new Zend_Search_Lucene_Search_Query_Preprocessing_Phrase(
        $phrase, LUCENEAPI_ENCODING, $old_query->getField()
      );
      $new_query->setBoost($old_query->getBoost());
      $new_query->setSlop($old_query->getSlop());
    }
    return $new_query;
  }

  /**
   * Rebuilds a range query for use with bias settings.
   *
   * @param $old_query
   *   A Zend_Search_Lucene_Search_Query_Range object containing the original
   *   query.
   *
   * @return
   *   A Zend_Search_Lucene_Search_Query_Boolean object.
   */
  public function rebuildRangeQuery(Zend_Search_Lucene_Search_Query_Range $old_query) {
    if (NULL === $query->getLowerTerm()->field) {
      $new_query = new Zend_Search_Lucene_Search_Query_Boolean();
      foreach ($this->biasFields as $field => $bias) {
        $lower_text = $this->index->normalizeText($old_query->getLowerTerm()->text, $field);
        $upper_text = $this->index->normalizeText($old_query->getUpperTerm()->text, $field);
        $subquery = new Zend_Search_Lucene_Search_Query_Range(
          new Zend_Search_Lucene_Index_Term($lower_text, $field),
          new Zend_Search_Lucene_Index_Term($upper_text, $field),
          $old_query->isInclusive()
        );
        $subquery->setBoost($old_query->getBoost() * $bias);
        $new_query->addSubquery($subquery);
      }
    }
    else {
      $field = $old_query->getLowerTerm()->field;
      $lower_text = $this->index->normalizeText($old_query->getLowerTerm()->text, $field);
      $upper_text = $this->index->normalizeText($old_query->getUpperTerm()->text, $field);
      $new_query = new Zend_Search_Lucene_Search_Query_Range(
        new Zend_Search_Lucene_Index_Term($lower_text, $field),
        new Zend_Search_Lucene_Index_Term($upper_text, $field),
        $old_query->isInclusive()
      );
      $subquery->setBoost($old_query->getBoost());
    }
    return $new_query;
  }

  /**
   * Rebuilds a term query for use with bias settings.
   *
   * @param $old_query
   *   A Zend_Search_Lucene_Search_Query_Preprocessing_Term object containing the
   *   original query.
   *
   * @return
   *   A Zend_Search_Lucene_Search_Query_Boolean object.
   */
  public function rebuildTermQuery(Zend_Search_Lucene_Search_Query_Preprocessing_Term $old_query) {
    if (NULL === $old_query->getField()) {
      $new_query = new Zend_Search_Lucene_Search_Query_Boolean();
      foreach ($this->biasFields as $field => $bias) {
        $word = $this->index->normalizeText($old_query->getWord(), $field);
        $subquery = new Zend_Search_Lucene_Search_Query_Preprocessing_Term(
          $word, LUCENEAPI_ENCODING, $field
        );
        $subquery->setBoost($old_query->getBoost() * $bias);
        $new_query->addSubquery($subquery);
      }
    }
    else {
      $word = $this->index->normalizeText($old_query->getWord(), $old_query->getField());
      $new_query = new Zend_Search_Lucene_Search_Query_Preprocessing_Term(
        $word, LUCENEAPI_ENCODING, $old_query->getField()
      );
      $new_query->setBoost($old_query->getBoost());
    }
    return $new_query;
  }

  /**
   * Rebuilds a multi-term query for use with bias settings.
   *
   * @param $old_query
   *   A Zend_Search_Lucene_Search_Query_Preprocessing_Term object containing the
   *   original query.
   * @return
   *   A Zend_Search_Lucene_Search_Query_Boolean object.
   */
  public function rebuildMultiTermQuery(Zend_Search_Lucene_Search_Query_MultiTerm $old_query) {
    $terms = $query->getTerms();
    $field = (count($terms)) ? $terms[0]->field : NULL;
    if (NULL === $field) {
      $new_query = new Zend_Search_Lucene_Search_Query_Boolean();
      foreach ($this->biasFields as $field => $bias) {
        $new_terms = array();
        foreach ($old_query->getTerms() as $term) {
          $text = $this->index->normalizeText($term->text, $field);
          $new_terms[] = new Zend_Search_Lucene_Index_Term($text, $field);
        }
        $subquery = new Zend_Search_Lucene_Search_Query_MultiTerm(
          $new_terms, $old_query->getSigns()
        );
        $subquery->setBoost($old_query->getBoost() * $bias);
        $new_query->addSubquery($subquery);
      }
    }
    else {
      $new_terms = array();
      foreach ($old_query->getTerms() as $term) {
        $text = $this->index->normalizeText($term->text, $field);
        $new_terms[] = new Zend_Search_Lucene_Index_Term($text, $field);
      }
      $new_query = new Zend_Search_Lucene_Search_Query_MultiTerm(
        $new_terms, $old_query->getSigns()
      );
      $new_query->setBoost($old_query->getBoost());
    }
    return $new_query;
  }
}

/**
 *
 */
class LuceneapiZfLuceneapiFilterWildcard extends LuceneapiFilter {

  /**
   * Returns the type of query.
   *
   * @return
   *   A string containing the query type.
   */
  public static function getType() {
    return 'wildcard';
  }

  /**
   * Returns a query.
   *
   * @return
   *   A Zend_Search_Lucene_Search_Query object.
   */
  public function execute() {
    $query = new Zend_Search_Lucene_Search_Query_Wildcard(
      new Zend_Search_Lucene_Index_Term($this->text, $this->field)
    );
    $query->setBoost($this->boost);
    return $query;
  }
}
