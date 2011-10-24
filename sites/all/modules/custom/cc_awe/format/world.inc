<?php

$plugin = array(
  'title' => t('World Data'),
  'format callback' => 'cc_awe_format_world_generate',
  'type' => 'world',
  'weight' => -80,
);

//Note that we do not make difference between "administrative area", "region", "state".

//Output region name instead of it's code.
function _cc_awe_pre_render($format) {
  $format['#address']['administrative_area'] = _cc_awe_region(
    $format['#address']['administrative_area'],
    $format['#address']['country']
  );
  return $format;
}

//$format - input form.
//$address - address itself.
//$context - additional data.
function cc_awe_format_world_generate(&$format, $address, $context = array()) {
  if($context['mode'] == 'render') {
    if($address['country'] == 'US' || $address['country'] == 'CA') {
      return FALSE;
    }
    $format['#pre_render'][] = '_cc_awe_pre_render';
    return FALSE;
  }
  if($address['country'] == 'US' || $address['country'] == 'CA') {
    $regs = array_filter(
      $format['locality_block']['administrative_area']['#options'],
      '_cc_awe_is_not_separator'
    );
  }else{
    $regs = _cc_awe_regions($address['country']);
  }
  unset($format['locality_block']['administrative_area']);
  $format['locality_block']['administrative_area'] = array(
    '#title' => t('State'),
    '#type' => 'select',
    '#options' => $regs
  );
}
