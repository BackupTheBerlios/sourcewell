<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ================================================
#
# Copyright (c) 2001 by
#                Lutz Henckel (lutz.henckel@fokus.gmd.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This is the file with the Frequently Asked Questions
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################  


page_open(array("sess" => "SourceWell_Session"));
if (isset($auth) && !empty($auth->auth["perm"])) {
  page_close();
  page_open(array("sess" => "SourceWell_Session",
                  "auth" => "SourceWell_Auth",
                  "perm" => "SourceWell_Perm"));
}

require("header.inc");

$bx = new box("80%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
require("$la-faq.inc");
$i = 1;
$msg = "";
while (list($key, $val) = each($qa)) {
  $msg .= "<li><a href=#".$i++.">$key</a>";
} 

$bx->box_full($t->translate("Frequently Asked Questions"), $msg);
reset($qa);
$i = 1;
while (list($key, $val) = each($qa)) {
  echo "<a name=".$i++.">\n";
  $bx->box_full($t->translate("Question").": ".$key, "<b>".$t->translate("Answer").":</b> ".$val);
}
?>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>
