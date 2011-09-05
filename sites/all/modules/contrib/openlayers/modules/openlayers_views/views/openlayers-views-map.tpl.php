<?php
// $Id: openlayers-views-map.tpl.php,v 1.1.2.4.2.2 2010/12/03 00:05:45 tmcw Exp $

/**
 * @file
 * Template file for map
 *
 * @param map String rendered map HTML.
 */
?>
<?php if (!empty($map)): ?>
  <div class='openlayers-views-map'><?php print $map ?></div>
<?php endif; ?>
