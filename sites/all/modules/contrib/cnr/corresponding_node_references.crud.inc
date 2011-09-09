<?php
/**
 * @file
 * Include file providing corresponding node reference insert, update, and delete handling.
 */

/**
 * Add any corresponding references on node insertion.
 *
 * @param $home_node the node object catched in the node api on this node a reference is made to the away node
 * @param $home_field the field on the home node used to make the reference
 * @param $away_node_type the type of the away node
 * @param $away_field the name of the field on the away node referencing to the home node
 */
function corresponding_node_references_insert($home_node, $home_field, $away_node_type, $away_field) {
  $old_node = node_load($home_node->nid, NULL, TRUE);

  // Determine the nodereference values after the insert.
  if (isset($home_node->$home_field) && is_array($home_node->$home_field)) {
    foreach ($home_node->$home_field as $lang => $fields) {
      foreach ($fields as $reference) {
        if (!empty($reference['nid'])) {
          // Load the referenced node if it is of the specified away type.
          //TODO: Do this with EntityFieldQuery
          //See http://api.drupal.org/api/drupal/modules--node--node.module/function/node_load_multiple/7
          if ($referenced_node = node_load($reference['nid'], NULL, FALSE)) {
            if ($referenced_node->type == $away_node_type) {
              // Add the new reference.
              // If there are no other references, we need to make sure this is delta 0
              if ($referenced_node->{$away_field}[$lang][0]['nid'] == NULL) {
                $referenced_node->{$away_field}[$lang][0]['nid'] = $home_node->nid;
              }
              else {
                // Add the new reference.
                //Check for doubles, could happen when nodes of same type are referenced
                $exists = FALSE;
                foreach ($referenced_node->{$away_field}[$lang] as $key => $value) {
                  if ($value['nid'] == $home_node->nid) {
                    $exists = TRUE;
                    break;

                  }
                }

                if  (!$exists) {
                  $referenced_node->{$away_field}[$lang][] = array('nid' => $home_node->nid);
                }
              }
              _corresponding_node_references_update($referenced_node);
            }
          }
        }
      }
    }
  }
}

/**
 * Change corresponding references on node updating.
 *
 * Corresponding changes are made for any references removed or added.
 *
 * @param $home_node the node object catched in the node api on this node a reference is made to the away node
 * @param $home_field the field on the home node used to make the reference
 * @param $away_node_type the type of the away node
 * @param $away_field the name of the field on the away node referencing to the home node
 * @param $process_unchanged whether or not to process node reference fields whose values have not changed.
 *   This is useful for nodes that existed before installing this module and have corresponding node
 *   reference fields that don't match up.
 */
function corresponding_node_references_update($home_node, $home_field, $away_node_type, $away_field, $process_unchanged = FALSE) {
  //Since node is not saved yet, $old_node and $home_node are different!
  $old_node = node_load($home_node->nid, NULL, FALSE);
  $old = $new = array();

  // Determine the nodereference values before the update.
  if (isset($old_node->$home_field) && is_array($old_node->$home_field)) {
    foreach ($old_node->$home_field as $lang => $fields) {
      $old[$lang] = array();
      foreach ($fields as $reference) {
        if (!empty($reference['nid'])) {
          $old[$lang][] = $reference['nid'];
        }
      }
    }
  }

  // If we are processing unchanged references, remove all new references from the old references.
  if ($process_unchanged) {
    foreach ($old as $lang => $data) {
      $old[$lang]  = array_diff($old[$lang], $new[$lang]);
    }
  }

  // Determine the nodereference values after the update.
  if (isset($home_node->$home_field) && is_array($home_node->$home_field)) {
    foreach ($home_node->$home_field as $lang => $fields) {
      $new[$lang] = array();
      foreach ($fields as $reference) {
        if (!empty($reference['nid'])) {
          $new[$lang][] = $reference['nid'];
        }
      }
    }
  }

  // Handle removed references.
  if ( !empty($old) ) {
    foreach ($old as $lang => $data) {
      if ($removed = array_diff($old[$lang], $new[$lang])) {
        foreach ($removed as $nid) {
          // Load the referenced node if it is of the specified away type.
          if ($referenced_node = node_load($nid, NULL, FALSE)) {
            //Self-references are handled by the node_reference module anyway
            if ($referenced_node->type == $away_node_type && $nid != $home_node->nid) {
              if (isset($referenced_node->{$away_field}[$lang]) && is_array($referenced_node->{$away_field}[$lang])) {
                // Iterate through the away node's references.
                foreach ($referenced_node->{$away_field}[$lang] as $key => $value) {
                  // Remove references to the deleted node.
                  if ($value['nid'] && $value['nid'] == $home_node->nid) {
                    unset($referenced_node->{$away_field}[$lang][$key]);
                    _corresponding_node_references_update($referenced_node);
                    break;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  // Handle added references.
  // No array diff a reference overload could of happend or a mass update
  if ($added = $new) {
    foreach ($added as $added_lang => $added_langdata) {
      foreach ($added_langdata as $nid) {

        // Load the referenced node if it is of the specified away type.
        if ($referenced_node = node_load($nid, NULL, FALSE)) {
          //Self-references are handled by the node_reference module anyway
          if ($referenced_node->type == $away_node_type && $nid != $home_node->nid) {
            // Detect whether the reference already exists.
            $exists = FALSE;
            if (isset($referenced_node->$away_field) && !empty($referenced_node->$away_field)) {
              foreach ($referenced_node->{$away_field}[$added_lang] as $data) {
                if ($data['nid'] == $home_node->nid) {
                  $exists = TRUE;
                  break;
                }
              }
            }

            //Empty places are removed
            //Yes this means the deltas change on the away node when a reference is made on the home node
            $values = array();
            if (isset($referenced_node->{$away_field}[$added_lang])) {
              foreach ($referenced_node->{$away_field}[$added_lang] as $value) {
                if (!empty($value['nid'])) {
                  $values[] = $value;
                }
              }
            }
            $referenced_node->{$away_field}[$added_lang] = $values;

            // Add the new reference. Don't create a duplicate.
            if (!$exists) {
              //Get the allowed values
              $unlimited = FALSE;
              $field = field_info_field($away_field);
              if ($field) {
                if ($field['cardinality'] == -1) {
                  $unlimited = TRUE;
                  $allowed_references = 0;
                }
                else {
                  $allowed_references = $field['cardinality'];
                }

                //check for reference overloading
                $references = count($referenced_node->{$away_field}[$added_lang]) + 1;
                if (($allowed_references >= $references) || $unlimited) {
                  $referenced_node->{$away_field}[$added_lang][] = array('nid' => $home_node->nid);
                  _corresponding_node_references_update($referenced_node);
                }
                else {
                  $t_reference = format_plural($references, '1 reference', '@count references');
                  $t_allowed = format_plural($allowed_references, '1 reference is', '@count references are');
                  drupal_set_message(
                  t('Reference overloading: @title would of had @t_reference and only @t_allowed permitted. Before adding a reference,
            	       you would need to <a href="@url">edit</a> @title to remove an existing reference and resave this node to have make it correspond.
            	      Or you could allow this reference instance to have more references, go to the cck field settings of the instance',
                  array(
                     '@title' => $referenced_node->title,
                      '@url' => url('node/' . $referenced_node->nid),
                      '@t_reference' => $t_reference,
                      '@t_allowed' => $t_allowed,
                  )
                  ),
                  'error'
                  );
                }
              }
            }
          }
        }
      }
    }
  }
}

/**
 * Remove corresponding references on node deletion.
 *
 * @param $home_node the node object catched in the node api on this node a reference is made to the away node
 * @param $home_field the field on the home node used to make the reference
 * @param $away_node_type the type of the away node
 * @param $away_field the name of the field on the away node referencing to the home node
 */
function corresponding_node_references_delete($home_node, $home_field, $away_node_type, $away_field) {
  // Iterate through the field's references.
  foreach ($home_node->$home_field as $lang => $langdata) {
    foreach ($langdata as $reference) {
      if (!empty($reference['nid'])) {
        // Load the referenced node if it is of the specified away type.
        if ($referenced_node = node_load($reference['nid'], NULL, FALSE)) {
          if ($referenced_node->type == $away_node_type) {
            // Iterate through the away node's references.
            foreach ($referenced_node->{$away_field}[$lang] as $key => $value) {
              // Remove references to the deleted node.
              if ($value['nid'] && $value['nid'] == $home_node->nid) {
                unset($referenced_node->{$away_field}[$lang][$key]);
                _corresponding_node_references_update($referenced_node);
                break;
              }
            }
          }
        }
      }
    }
  }
}

/**
 * Update field data.
 *
 * @param $node the referenced node to be updated
 */
function _corresponding_node_references_update(&$node) {
  node_save($node);
}
