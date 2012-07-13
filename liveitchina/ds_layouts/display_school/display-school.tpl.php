<?php if ($header): ?>
  <div class="group-header<?php print $header_classes; ?>">
    <?php print $header; ?>
  </div>
<?php endif; ?>
<div class="clearfix">
<?php if ($left): ?>
  <div class="grid-8 alpha<?php print $left_classes; ?>">
    <?php print $left; ?>
  </div>
<?php endif; ?>
<?php if ($right): ?>
  <div class="grid-8 alpha omega<?php print $right_classes; ?>">
    <?php print $right; ?>
  </div>
<?php endif; ?>
</div>
<?php if ($main): ?>
  <div class="group-main<?php print $main_classes; ?>">
    <?php print $main; ?>
  </div>
<?php endif; ?>
<?php if ($footer): ?>
  <div class="group-footer<?php print $footer_classes; ?>">
    <?php print $footer; ?>
  </div>
<?php endif; ?>
<div class="clearfix">
<?php
  // Print the rest of the form.
  print drupal_render_children($form);
?>
</div>