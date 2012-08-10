<div class="user-info clearfix">
  <div class="user-info-image grid-2 alpha">
   <?php print l($image, $path, array('html'=>TRUE)); ?>
  </div>
  <div class="user-info-detail grid-3 alpha">
    <h2><?php print $name; ?></h2>
    <span>(<?php print $profile['name'] ?>)</span>
  </div>
</div>