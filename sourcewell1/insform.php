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
# This is the form for inserting apps
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

require("./include/prepend.php3");

page_open(array("sess" => "SourceWell_Session",
                "auth" => "SourceWell_Auth",
                "perm" => "SourceWell_Perm"));

require("./include/header.inc");

$bx = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
if ($perm->have_perm("user_pending")) {
  $be->box_full($t->translate("Error"), $t->translate("Access denied"));
  $auth->logout();
} else {

  $bx->box_begin();
  $bx->box_title($t->translate("New Application"));
  $bx->box_body_begin();

  echo "<form action=\"".$sess->url("insapp.php")."\" method=\"POST\">";
?>
<table border=0 cellspacing=0 cellpadding=3>
<tr><td align=right><?php echo $t->translate("Application Name") ?> (128):</td><td><input type="TEXT" name="name" size=40 maxlength=128>
</td></tr>
<tr><td align=right><?php echo $t->translate("Type") ?> :</td><td>
<select name="type">
<?php
  echo "<option value=\"S\">".$t->translate("Stable")."</option>\n";
  echo "<option value=\"D\">".$t->translate("Development")."</option>\n";
?>
</select>
</td></tr>
<tr><td>&nbsp;</td>
<?php
  echo "<td><input type=\"submit\" value=\"".$t->translate("Insert")."\">";
?>
</td></tr>
</form>
</table>
<?php
  $bx->box_body_end();
  $bx->box_end();
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
