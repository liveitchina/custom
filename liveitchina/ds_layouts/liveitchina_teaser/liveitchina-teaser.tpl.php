<div class="liveitchina-teaser <?php print $classes;?> clearfix">
  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
  <?php if ($header): ?>
  <div class="ds-header<?php print $header_classes; ?>">
    <?php print $header; ?>
  </div>
  <?php endif; ?>
  <div class="ds-content clearfix">
  <?php if ($left): ?>
    <aside class="grid-4 <?php print $left_classes; ?>">
      <?php print $left; ?>
    </aside>
  <?php endif; ?>
  <?php if ($right): ?>
    <section class="grid-12 alpha omega<?php print $right_classes; ?>">
      <?php print $right; ?>
    </section>
  <?php endif; ?>
  </div>
</div>