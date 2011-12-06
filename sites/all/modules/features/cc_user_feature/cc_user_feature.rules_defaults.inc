<?php
/**
 * @file
 * cc_user_feature.rules_defaults.inc
 */

/**
 * Implementation of hook_default_rules_configuration().
 */
function cc_user_feature_default_rules_configuration() {
  $items = array();
  $items['rules_punlish_content'] = entity_import('rules_config', '{ "rules_punlish_content" : {
      "LABEL" : "punlish content",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "DO" : [ { "node_publish" : { "node" : [ "node" ] } } ]
    }
  }');
  return $items;
}
