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
# This file is used to insert an application. It contains the form
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

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
if ($perm->have_perm("user_pending")) {
  $be->box_full($t->translate("Error"), $t->translate("Access denied"));
} else {
  if (isset($name) && !empty($name)) {
				// Look if application is already in table

    $name = trim($name);
    $query="SELECT * FROM software WHERE name='$name' AND type='$type'";

			    // If application in table show existing values to change
    $db->query($query);
    if ($db->num_rows() == 1) {
	updform($query,"update.php");

				// If application is not in table, insert it
    } else {
      insform();
    }
  } else {
    $be->box_full($t->translate("Error"), $t->translate("No Application Name specified")."."
    ."<br>".$t->translate("Please select")." <a href=\"insform.php\">".$t->translate("New Apps")."</a>");
  }
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
