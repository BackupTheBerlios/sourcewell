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
# This file is used to insert an application. It contains the form
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

page_open(array("sess" => "SourceWell_Session",
                "auth" => "SourceWell_Auth",
                "perm" => "SourceWell_Perm"));

require("header.inc");

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
if ($perm->have_perm("user_pending")) {
  $be->box_full($t->translate("Error"), $t->translate("Access denied"));
  $auth->logout();
} else {
  if (isset($name) && !empty($name)) {
    $db = new DB_SourceWell;
				// Look if application is already in table

    $name = trim($name);
    $columns = "*";
    $tables = "software";
    $where = "name='$name' AND type='$type'";
    if (!$result = mysql_db_query($db_name, "SELECT $columns FROM $tables WHERE $where")) {
      mysql_die();
    } else {

				// If application in table show existing values to change
      if ($row = mysql_fetch_array($result)) {
	updform($row);

				// If application is not in table, insert it
      } else {
	insform();
      }
    }
  } else {
    $be->box_full($t->translate("Error"), $t->translate("No Application Name specified")."."
    ."<br>".$t->translate("Please select")." <a href=\"insform.php3\">".$t->translate("New Apps")."</a>");
  }
}
?>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>
