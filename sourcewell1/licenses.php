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
# This file indexes the software licenses
# It also gives the number of inserted apps for each license
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

require("./include/prepend.php3");

page_open(array("sess" => "SourceWell_Session"));
if (isset($auth) && !empty($auth->auth["perm"])) {
  page_close(); 
  page_open(array("sess" => "SourceWell_Session",
                  "auth" => "SourceWell_Auth",
                  "perm" => "SourceWell_Perm"));
}

require "./include/header.inc";

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
$db->query("SELECT DISTINCT * FROM licenses ORDER BY license ASC");
$bx->box_begin();
$bx->box_title($t->translate("Licenses"));
$bx->box_body_begin();
$i = 1;
echo "<table border=0 align=center cellspacing=1 cellpadding=1 width=100%>\n";
echo "<tr><td><b>".$t->translate("No").".</b></td><td><b>#&nbsp;".$t->translate("Apps")."</b></td><td><b>".$t->translate("License")."</b></td></tr>\n";
while($db->next_record()) {
  $license = $db->f("license");
  $db2 = new DB_SourceWell;
  $db2->query("SELECT COUNT(*) FROM software WHERE license='$license' AND status='A'");
  $db2->next_record();
  $num = "[".sprintf("%03d",$db2->f("COUNT(*)"))."]";
  echo "<tr><td>$i</td><td><a href=\"".$sess->url("appbylic.php").$sess->add_query(array("license" => $license))."\">$num</a></td><td><a href=\"".$db->f("url")."\" target=\"_blank\">".$license."</a></td></tr>\n";
  $i++;
}
echo "</table>\n";
$bx->box_body_end();
$bx->box_end();
?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
