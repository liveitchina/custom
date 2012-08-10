<div class="user-info clearfix">
  <div class="user-info-image grid-2 alpha">
   <?php print l($image, $path, array('html'=>TRUE)); ?>
  </div>
  <div class="user-info-detail grid-4 alpha">
    <h2><?php print l($name, $path); ?></h2>
    <span>(<?php print $profile; ?>)</span>
  </div>
</div>