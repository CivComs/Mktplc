<?php

/**
 * @file
 * The default format for adresses.
 */

$plugin = array(
  'title' => t('County (for U.S. addresses)'),
  'format callback' => 'addressfield_format_county_generate',
  'type' => 'address',
  'weight' => -100,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function addressfield_format_county_generate(&$format, $address, $context = array()) {
  // We start with a reasonable default: a simple block format suitable
  // for international shipping. We extend it with country-specific heuristics
  // below.

  // The county field.
  if (in_array($address['country'], array('US'))) {
    $format['locality_block']['sub_administrative_area'] = array(
      '#title' => t('County'),
      '#size' => 30,
      '#required' => TRUE,
      '#prefix' => ' ',
      '#attributes' => array('class' => array('sub_administrative_area')),
    );
    $format['locality_block']['locality']['#weight'] = 10;
    $format['locality_block']['sub_administrative_area']['#weight'] = 20;
    $format['locality_block']['administrative_area']['#weight'] = 30;
    $format['locality_block']['postal_code']['#weight'] = 40;
  }
  //drupal_set_message('<pre>' . print_r($format, TRUE) . '</pre>');
}
