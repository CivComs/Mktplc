<?php

function cc_helper_field_attach_form($entity_type, $entity, &$form, &$form_state, $langcode) {
  if(!isset($form['field_organization_address'])) {
    return FALSE;
  }
  $form['field_organization_address'][$langcode]['#element_validate'][] = '_cc_helper_address_validate';
	$arr = array(''=>t('--None--'))+$form['field_organization_address'][$langcode][0]['locality_block']['administrative_area']['#options'];
	$form['field_organization_address'][$langcode][0]['locality_block']['administrative_area']['#options']= $arr;
}

function _cc_helper_address_validate($element, $form_state) {
  $items = drupal_array_get_nested_value($form_state['values'], $element['#parents']);
  $p = $element['#parents'];
  $p[array_search('field_organization_address', $element['#parents'])] = 'field_organization_type';
  $tids = drupal_array_get_nested_value($form_state['values'], $p);
  $tid = isset($tids[0]['tid']) ? $tids[0]['tid'] : 0;
  $m = array();
  foreach ($items as $delta => $item) {
		$ms = _cc_helper_org_address_error(
      isset($item['thoroughfare']) ? $item['thoroughfare'] : FALSE,
      isset($item['premise']) ? $item['premise'] : FALSE,
      isset($item['locality']) ? $item['locality'] : FALSE,
      isset($item['administrative_area']) ? $item['administrative_area'] : FALSE,
      isset($item['sub_administrative_area']) ? $item['sub_administrative_area'] : FALSE,
      isset($item['country']) ? $item['country'] : FALSE,
      $tid
    );
		if($ms!='') {
			$m[]=$ms;
		};
  }
  if (!empty($m)) {
    form_error($element, implode(' ', $m));
  }
}

/*
$address - address field item. $tid - "what kind of Organization is it".
*/
function _cc_helper_org_address_error($a1, $a2, $l, $ar, $sar, $c, $tid = 0) {
  $m = '';
  if (($a1 || $a2 || $tid == 127) && (!$l || !$ar || !$c)) {
    $m = t('Please, provide city, state and country in address field.');
  }
  elseif (($tid == 130 || $tid == 129 || $l || $sar) && (!$ar || !$c)) {
    $m = t('Please, provide state and country in address field.');
  }
  elseif (($tid == 131 || $ar) && !$c) {
    $m = t('Please, provide country in address field.');
  }
  return $m;
}