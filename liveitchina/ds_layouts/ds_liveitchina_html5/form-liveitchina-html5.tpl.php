<?php

/**
 * @file
 * Display Suite 2 column with top and bottom template HTML 5 version.
 */
?>
<div class="ds-liveitchina-html5 clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <?php if ($header): ?>
    <header class="group-header<?php print $header_classes; ?>">
      <?php print $header; ?>
    </header>
  <?php endif; ?>
    <div class="ds-content clearfix">
  <?php if ($left): ?>
    <aside class="grid-4 alpha omega group-left<?php print $left_classes; ?>">
      <?php print $left; ?>
    </aside>
  <?php endif; ?>

  <?php if ($right): ?>
    <section class="grid-12 omega group-right<?php print $right_classes; ?>">
      <?php print $right; ?>
    </section>
  <?php endif; ?>
    </div>
  <?php if ($footer): ?>
    <footer class="group-footer<?php print $footer_classes; ?>">
      <?php print $footer; ?>
    </footer>
  <?php endif; ?>
</div>
<?php if ($display): ?>
<div class="group-display<?php print $display_classes; ?>">
  <?php print $display; ?>
</div>
<?php endif; ?>
<div class="clearfix">
<?php
  // Print the rest of the form.
  print drupal_render_children($form);
?>
</div>