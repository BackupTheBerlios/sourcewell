<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ================================================
#
# Copyright (c) 2001-2004 by
#                Lutz Henckel (lutz.henckel@fokus.fraunhofer.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This file indexes the sections and categories available in our system
# It also shows the number of apps in each one
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

require("./include/header.inc");

$bx = new box("95%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
echo "<table border=0 align=center cellspacing=0 cellpadding=0 width=100%>\n";
echo "<tr><td width=40% valign=top>\n";
$bx->box_begin();
$bx->box_title($t->translate("Sections"));
$bx->box_body_begin();
$db->query("SELECT DISTINCT section FROM categories");
while($db->next_record()) {
  $current_section=$db->f("section");
  $db2 = new DB_SourceWell;
  $db2->query("SELECT COUNT(*) FROM software WHERE section='$current_section' AND status='A'");
  $db2->next_record();
  $num = "[".sprintf("%03d",$db2->f("COUNT(*)"))."]";  
  echo "$num <a href=\"".$sess->url("categories.php").$sess->add_query(array("section" => $db->f("section")))."\">".$db->f("section")."<br></a>\n";
}
$bx->box_body_end();
$bx->box_end();	
?>

</td>
<td width=60% valign=top>

<?php
if (isset($section)) {
  $db->query("SELECT category FROM categories WHERE section='$section' ORDER BY category ASC");
  $bx->box_begin();
  $bx->box_title($t->translate("Categories"));
  $bx->box_body_begin();
  while($db->next_record()) {
    $current_category = $db->f("category");
    $db2->query("SELECT COUNT(*) FROM software WHERE section='$section' AND category='$current_category' AND status='A'");
    $db2->next_record();
    $num = "[".sprintf("%03d",$db2->f("COUNT(*)"))."]";
    echo "$num <a href=\"".$sess->url("appbycat.php").$sess->add_query(array("section" => $section, "category" => $db->f("category")))."\">".$db->f("category")."</a><br>\n";
  }
$bx->box_body_end();
$bx->box_end();
}
?>
</td></tr>
</table>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
