<?php

/**
 * @file
 * Standard Lucene normalizers.
 */

/**
 * Normalizes boolean values.
 */
class LuceneapiNormalizerBoolean {

  /**
   * Returns the data type.
   */
  static public function getDataType() {
    return 'boolean';
  }

  /**
   * Returns the normalized string.
   */
  public function execute($text, array $options) {
    return !empty($text) ? 'T' : 'F';
  }
}

/**
 * Normalizes date values.
 */
class LuceneapiNormalizerDate {

  /**
   * Returns the data type.
   */
  static public function getDataType() {
    return 'date';
  }

  /**
   * Returns the normalized string.
   */
  public function execute($text, array $options) {
    return is_numeric($text) ? gmdate('Y-m-d\TH:i:s\Z', $text) : $text;
  }
}

/**
 * Normalizes decimal values.
 */
class LuceneapiNormalizerDecimal {

  /**
   * Returns the data type.
   */
  static public function getDataType() {
    return 'decimal';
  }

  /**
   * Returns the normalized string.
   */
  public function execute($text, array $options) {
    $parts = explode($options['decimal_separator'], $text);
    $pad_length = $options['precision'] - $options['scale'];
    $parts[0] = str_pad(ltrim($text, '0'), $pad_length, '0', STR_PAD_LEFT);
    $parts[1] = str_pad(ltrim($text, '0'), $options['scale'], '0', STR_PAD_RIGHT);
    return join($options['decimal_separator'], $parts);
  }
}

/**
 * Normalizes float values.
 */
class LuceneapiNormalizerFloat {

  /**
   * Returns the data type.
   */
  static public function getDataType() {
    return 'float';
  }

  /**
   * Returns the normalized string.
   */
  public function execute($text, array $options) {
    // @todo Normalize this.
    return $text;
  }
}

/**
 * Normalizes integer values.
 */
class LuceneapiNormalizerInteger {

  /**
   * Returns the data type.
   */
  static public function getDataType() {
    return 'integer';
  }

  /**
   * Returns the normalized string.
   */
  public function execute($text, array $options) {
    return str_pad(ltrim($text, '0'), 11, '0', STR_PAD_LEFT);
  }
}

/**
 * Normalizes string values.
 */
class LuceneapiNormalizerString {

  /**
   * Returns the data type.
   */
  static public function getDataType() {
    return 'string';
  }

  /**
   * Returns the normalized string.
   */
  public function execute($text, array $options) {
    return decode_entities(luceneapi_strip_tags($text));
  }
}
