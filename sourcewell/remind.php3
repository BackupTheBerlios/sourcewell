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
# This file permits that users can get their forgotten password via e-mail
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

$bx = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
$bx->box_begin();
$bx->box_title($t->translate("Forgot Password"));
$bx->box_body_begin();
echo "<form method=\"post\" action=\"remindme.php3\">\n";
echo "<table border=0 cellspacing=0 cellpadding=3>\n";
echo "<tr><td align=right>".$t->translate("Username").":</td><td><input type=\"text\" name=\"username\" size=20 maxlength=32 value=\"\"></td></tr>\n";
echo "<tr valign=middle align=left>\n";
echo "<td align=right>".$t->translate("E-Mail").":</td><td><input type=\"text\" name=\"email_usr\" size=20 maxlength=32 value=\"\"></td></tr>\n";
echo "<tr valign=middle align=left><td></td><td>\n";
echo "<input type=\"submit\" name=\"remind\" value=\"".$t->translate("Remind me")."\">\n";
echo "</td></tr></form></table>\n";
$bx->box_body_end();
$bx->box_end();
?>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>
