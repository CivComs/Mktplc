<?php

/**
 * @file
 */

/**
 *
 */
class LuceneapiZfLuceneapiHighlighter extends LuceneapiHighlighter {

  /**
   * @todo Improve this, it is wicked hacky.
   */
  public function execute() {

    $text = $this->searcher
      ->getIndex()
      ->getBackend()
      ->getLastQuery()
      ->htmlFragmentHighlightMatches($this->text);

    // Initializes offset, ranges.
    $offset = 0;
    $ranges = array();

    // Initializes "needle".
    $needle = '<b';
    $needle_len = strlen($needle);

    // Find the matches.
    // @see search_excerpt()
    // @todo Find a better way to do this.
    $length = 0;
    while ($length < 256 && FALSE !== ($pos = strpos($text, $needle, $offset))) {
      $offset = $pos + strlen($needle_len);
      if ($length >= 256) {
        break;
      }
      if (FALSE !== ($q = strpos(' ' . $text, ' ', max(0, $pos - 61)))) {
        $end = substr($text . ' ', $pos, 130);
        if (($s = strrpos($end, ' ')) !== FALSE) {
          // Account for the added spaces.
          $q = max($q - 1, 0);
          $s = min($s, drupal_strlen($end) - 1);
          $ranges[$q] = $pos + $s;
          $length += $pos + $s - $q;
        }
      }
    }

    // Sort the text ranges by starting position.
    ksort($ranges);
    if (empty($ranges)) {
      return truncate_utf8($text, 256);
    }

    // Now we collapse overlapping text ranges into one. The sorting makes it O(n).
    $newranges = array();
    foreach ($ranges as $from2 => $to2) {
      if (!isset($from1)) {
        $from1 = $from2;
        $to1 = $to2;
        continue;
      }
      if ($from2 <= $to1) {
        $to1 = max($to1, $to2);
      }
      else {
        $newranges[$from1] = $to1;
        $from1 = $from2;
        $to1 = $to2;
      }
    }
    $newranges[$from1] = $to1;

    // Fetch text.
    $out = array();
    foreach ($newranges as $from => $to) {
      $out[$from] = substr($text, $from, $to - $from);

      // Hacky, hacky, hacky.  Check if string ends with <b.
      // @todo If you get to this point, see the todo in the docblock.
      if (strrpos($out[$from], '<b') === strlen($out[$from]) - 2) {
        $out[$from] = substr($out[$from], 0, strlen($out[$from]) - 2);
      }
    }

    // Let translators have the ... separator text as one chunk.
    $dots = explode('!excerpt', t('... !excerpt ... !excerpt ...'));

    $text = (isset($newranges[0]) ? '' : $dots[0]) . implode($dots[1], $out) . $dots[2];

    return $text;
  }
}
