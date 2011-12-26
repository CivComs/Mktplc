<?php
/**
 * @file
 * cc_application.features.fe_block_boxes.inc
 */

/**
 * Implementation of hook_default_fe_block_boxes().
 */
function cc_application_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'has your agency used or tried this app?';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'cc_add_interaction';
  $fe_block_boxes->body = '<?php 
//print(_cc_helper_render_tried_this_app_form()); 
$dest=drupal_get_destination();
?>
<!--
<form action="/node/add/interaction" method="get">
<input type="hidden" name="app_id" hidden value="<?php echo arg(1); ?>">
<input type="hidden" name="destination" hidden value="<?php echo $dest[\'destination\']; ?>">
<div class="has-you-tried">Has your agency used or tried this app?</div>
<div>Yes, we 
<select name="interaction_id">
<?php foreach(taxonomy_get_tree(16) as $row){
echo \'<option value="\'.$row->tid.\'">\'.$row->name.\'</option>\';
}; ?>
</select>
 it 
<input type="submit" value="Go">
</div>
</form>
-->';

  $export['cc_add_interaction'] = $fe_block_boxes;

  return $export;
}
