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
# This file contains the form for adding comments to an app
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
require("./include/cmtlib.inc");

$bx = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
if ($perm->have_perm("user_pending")) {
  $be->box_full($t->translate("Error"), $t->translate("Access denied"));
} else {
  if (isset($id)) {
    $query = "SELECT * FROM software WHERE appid='$id'";
    $db->query($query);
    $db->next_record();
			// If application in table ask for comment

    $db_status = $db->f("status");
    if ($db->num_rows() > 0 AND ($db_status != 'P')) {
      cmtform($query);
			// If application is not in table or pending
    } else {
      if ($db_status != 'P') {
        $be->box_full($t->translate("Error"), $t->translate("Application")." (ID: $id) ".$t->translate("does not exist").".");
      } else {
	$be->box_full($t->translate("Error"), $t->translate("Application")." <b>".$db->f("name")."</b> ".$t->translate("has not yet been reviewed by a $sys_name Editor.<BR> Please, be patient. It will be surely done in the next time."));
      }
    }
  } else {
    $be->box_full($t->translate("Error"), $t->translate("No Application ID specified"));
  }
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
