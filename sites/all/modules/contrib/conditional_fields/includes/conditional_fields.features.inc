<?php
/**
 * @file
 * Features integration hooks.
 */

/**
 * Implements hook_features_export_options().
 */
function conditional_fields_features_export_options() {
  $dependencies = conditional_fields_load_dependencies();
  $entity_info = entity_get_info();
  $options = array();
  foreach ($dependencies as $type => $data) {
    foreach ($data as $dependency => $info) {
      $option = $type . ':' . $dependency;
      if (!isset($options[$dependency])) {
        $options[$option] = $entity_info[$type]['bundles'][$dependency]['label'] . ' (' . $type . ')';
      }
    }
  }
  return $options;
}

/**
 * Implements hook_features_export().
 */
function conditional_fields_features_export($data, &$export, $module_name = '') {
  $export['dependencies']['conditional_fields'] = 'conditional_fields';

  foreach ($data as $entity) {
    $export['features']['conditional_fields'][$entity] = $entity;
  }
}

/**
 * Implments hook_features_export_render()
 */
function conditional_fields_features_export_render($module_name = '', $data) {
  $dependencies = conditional_fields_load_dependencies();
  if (!empty($dependencies)) {
    $code[] = '  $items = array();';
  }
  foreach ($data as $option) {
    $tokens = explode(':', $option);
    $entity = $tokens[0];
    $bundle = $tokens[1];

    if (isset($dependencies[$entity]) && isset($dependencies[$entity][$bundle])) {
      $info = $dependencies[$entity][$bundle];
      foreach ($info as $k => $v) {
        if (isset($v['dependees'])) {
          $code[] = '  $items[] = array(';
          $code[] = "    'entity' => '" . $entity . "',";
          $code[] = "    'bundle' => '" . $bundle . "',";
          $code[] = "    'dependent' => '" . $k . "',";
          $dependee = array_keys($v['dependees']);
          $code[] = "    'dependee' => '" . $dependee[0] . "',";
          $code[] = "    'options' => ";
          $vals = explode("\n", var_export($v['dependees'][$dependee[0]]['options'], TRUE));
          // $code += $vals would work just as well here, but this formats the output nicer.
          foreach ($vals as $val) {
            $code[] = '      ' . $val;
          }
          $code[] = '  );';
        }
      }
    }


  }
  if (empty($code)) {
    return array();
  }

  $code[] = '';
  $code[] = '  return $items;';
  $code =   array('  $items = array();') + $code;
  $output = implode("\n", $code);

  return array('conditional_fields_default_fields' => $output);
}

/**
 * Implements hook_features_rebuild().
 */
function conditional_fields_features_rebuild($module) {
  $defaults = module_invoke($module, 'conditional_fields_default_fields');

  $dependencies = conditional_fields_load_dependencies();
  $instances = field_info_instances();

  if (!empty($defaults)) {
    $node_types = array();
    foreach ($defaults as $field) {
      if (isset($dependencies[$field['entity']][$field['bundle']])) {
        foreach ($dependencies[$field['entity']][$field['bundle']] as $k => $v) {
          if (isset($v['dependees'])) {
            foreach ($v['dependees'] as $foo => $bar) {
              $deps_to_remove[$bar['id']] = $bar['id'];
            }
          }
        }
        conditional_fields_dependency_delete($deps_to_remove);
      }
      $entity_instances = $instances[$field['entity']][$field['bundle']];
      $dependee_id = $entity_instances[$field['dependee']]['id'];
      $dependent_id = $entity_instances[$field['dependent']]['id'];
      $options = $field['options'];
      conditional_fields_dependency_insert($dependee_id, $dependent_id, $options);
    }
  }
}

/**
 * Implements hook_features_revert().
 */
function conditional_fields_features_revert($module) {
  return conditional_fields_features_rebuild($module);
}
