<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ====================================================
#
# Copyright (c) 2001-2003 by
#                Lutz Henckel (lutz.henckel@fokus.gmd.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This file allows the administrator to insert, rename and
# delete categories 
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
#
# $Id: admcat.php,v 1.2 2003/02/28 11:03:39 helix Exp $
#
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

$bx = new box("80%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("80%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
$bs = new box("100%",$th_strip_frame_color,$th_strip_frame_width,$th_strip_title_bgcolor,$th_strip_title_font_color,$th_strip_title_align,$th_strip_body_bgcolor,$th_strip_body_font_color,$th_strip_body_align);
?>

<!-- content -->
<?php
if (($config_perm_admcat != "all") && (!isset($perm) || !$perm->have_perm($config_perm_admcat))) {
  $be->box_full($t->translate("Error"), $t->translate("Access denied"));
} else {

  $bx->box_begin();
  $bx->box_title($t->translate("Category Administration"));
  $bx->box_body_begin();

			         // Insert a new Category

  $bs->box_strip($t->translate("Insert a Category"));
  echo "<form action=\"".$sess->url("inscat.php")."\" method=\"POST\">\n";
  echo "<table border=0 cellspacing=0 cellpadding=3 width=100%>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Section").":</td><td width=70%>\n";
  echo "<select name=\"section\">\n";
  sec("Console");     // We select the first one to avoid having a blank line
  echo "</select></td></tr>\n";
  echo "<tr><td align=right>".$t->translate("New Category")." (64):</td><td><input type=\"TEXT\" name=\"category\" size=40 maxlength=64>\n";
  echo "</td></tr>\n";
  echo "<tr><td>&nbsp;</td>\n";
  echo "<td><input type=\"submit\" value=\"".$t->translate("Insert")."\">";
  echo "</td></tr>\n";
  echo "</form>\n";
  echo "</table>\n";
  echo "<BR>\n";

			          // Rename/Update a Category

  $bs->box_strip($t->translate("Rename a Category"));
  echo "<form action=\"".$sess->url("inscat.php")."\" method=\"POST\">\n";
  echo "<table border=0 cellspacing=0 cellpadding=3 width=100%>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Category").":</td><td width=70%>\n";
  echo "<select name=\"sec_and_cat\">\n";
  seccat("Console/Backup");     // We select the first one to avoid having a blank line
  echo "</select></td></tr>\n";
  echo "<tr><td align=right>".$t->translate("New Category Name")." (64):</td><td><input type=\"TEXT\" name=\"new_category\" size=40 maxlength=64>\n";
  echo "</td></tr>\n";
  echo "<tr><td>&nbsp;</td>\n";
  echo "<td><input type=\"submit\" value=\"".$t->translate("Rename")."\">";
  echo "</td></tr>\n";
  echo "</form>\n";
  echo "</table>\n";
  echo "<BR>\n";

					  // Delete a Category

  $bs->box_strip($t->translate("Delete a Category"));
  echo "<form action=\"".$sess->url("inscat.php")."\" method=\"POST\">\n";
  echo "<table border=0 cellspacing=0 cellpadding=3 width=100%>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Category").":</td><td width=70%>\n";
  echo "<select name=\"sec_and_cat\">\n";
  seccat("Console/Backup");     // We select the first one to avoid having a blank line
  echo "</select></td></tr>\n";
  echo "</td></tr>\n";
  echo "<tr><td>&nbsp;</td>\n";
  echo "<input type=\"hidden\" name=\"del_category\" value=\"warning\">\n";
  echo "<td><input type=\"submit\" value=\"".$t->translate("Delete")."\">";
  echo "</td></tr>\n";
  echo "</form>\n";
  echo "</table>\n";
  $bx->box_body_end();
  $bx->box_end();
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
