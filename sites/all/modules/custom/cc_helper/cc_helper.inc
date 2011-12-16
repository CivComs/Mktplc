<?php

function cc_helper_field_attach_form($entity_type, $entity, &$form, &$form_state, $langcode) {
  if(!isset($form['field_organization_address'])) {
    return FALSE;
  }
  $curr_addr = field_get_items(
    $entity_type,
    $entity,
    'field_organization_address'
  );
  $curr_admar =
    isset($curr_addr[0]['administrative_area'])
    ? $curr_addr[0]['administrative_area']
    : '';
  $form['field_organization_address'][$langcode]['#element_validate'][] = '_cc_helper_address_validate';
  $form['field_organization_address'][$langcode][0]['locality_block']['administrative_area']['#default_value'] = $curr_admar;
  $form['field_organization_address'][$langcode][0]['locality_block']['administrative_area']['#attributes'] = array('class' => array('administrative-area'));
  drupal_add_js(drupal_get_path('module', 'cc_helper') . '/cc_helper_address.js');
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
    }
  }
  if (!empty($m)) {
    form_error($element, implode(' ', $m));
  }
}

/*
$tid - "what kind of Organization is it".
*/
function _cc_helper_org_address_error($a1, $a2, $l, $ar, $sar, $c, $tid = 0) {
  $req = array(
    'address' => FALSE && (!$a1 || !$a2),
    'city' => ($a1 || $a2 || ($tid == 127)) && !$l,
    'county' => ($tid == 129) && !$sar,
    'state' => ($sar || $l || $a1 || $a2 || ($tid == 130) || ($tid == 129) || ($tid == 127)) && !$ar,
    'country' => ($ar || $sar || $l || $a1 || $a2 || ($tid == 131) || ($tid == 130) || ($tid == 129) || ($tid == 127)) && !$c
  );
  $flds = array_keys(array_filter($req));
  return empty($flds) ? '' : t(
    'Following data is required but absent: !fields.',
    array('!fields' => implode(', ', $flds))
  );
}
