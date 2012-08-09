Before deployment, make sure to backup all code and database. Very important!
We recommend clone the current site to a separate location so that you can compare what changes have been done.
There is a known issue for the module globalredirect 1.4 with i18n. Please update it to 1.5 or disable it before integration.

Preparation
1. Put the feature code inside site/<yoursite>/modules (or any sub-directory)
2. In drupal, go to Structure > Features
3. Enable the Liveit Features provided by Pantarei-design
4. When it asks for whether disabling a list of modules, click leave enabled.
5. After a while, back to Features page, you will the State (right side ) of the Feature just enabled before Overridden. Click the Overridden link.
6. You might want to review the change, click Review overrides. Otherwise check Strongarm and Views then Revert components.
7. go to admin/config/regional/translate/update. click update at the bottom
8. The language switch drop down box with change. Please replace it with a custom block like:
<a href="?language=en">English</a> | <a href="?language=zh-hant">繁體</a> | <a href="?language=zh-hans">簡体</a>. The layout and the presentation can be freely changed but the redirect/link result should be http://<domain>/<whatever_was_here>?language=en

Content Translation
1. Edit one of the content with content translation enabled (e.g. photo, basic page, article, etc)
2. Click translate on the Edit bar
3. add translation. Replace English content with your desired language then save.

Menu Translation
1. Structure > Menus. In Main menu row, click list links
2. edit About Live it China, then click Translate on the top right
3. add translation on the desired language
4. edit the menu link title for that language.
5. edit the path: you should input the node id for that language. (To get the node id for a specific node, edit that node and refer to the url) Then save. It will resolve to the url alias. If the original link is not a link to a node, just keep the path unchanged.
6. Repeat step 2 for all menu items. after translating all items. Rearrange the menu (Traditional chinese item should only under Traditional chinese item, etc)

Field Label Translation
1. Structure > Content Types
2. manage fields for Article (same for other content types)
3. edit one of the fields like Body. Then click translate on top right.
4. Then do the translation on each language.

Field Value Translation (Field-level Translation)
1. Structure > Content Types
2. manage fields for School (Only this type is enabled for field-level translation)
3. edit the fields you need (e.g. Description, summary). You will want to keep most non-text field not translatable
4. click Enable translation at the bottom and confirm. It may takes some time.
5. Now you can edit one of the School and translate just like Content Translation but only for the fields enabled

Taxonomy Translation
1. Structure > Taxonomy
2. edit vocabulary on the Taxonomy you need to translate. Make sure the Multilingual options is 'Localize. Terms are common for all languages, but their name and description may be localized.' Then go back to Taxonomy page.
3. Click list terms and edit one of the terms.
4. Click Translate on top right. Then you can the translation just like above.

Miscellaneous
1. Sometimes you just can't find where a word can be translated
2. Configuration > Regional and Language > Translate Interface > Translate
3. You can find most interface related strings here. Just search for the string you need.

Reference plain Drupal site with multilingual deployment:
http://staging.liveitchina.pantarei-design.com/