<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ====================================================
#
# Copyright (c) 2001 by
#                Lutz Henckel (lutz.henckel@fokus.gmd.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This file shows an app (given by the id parameter)
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

require("./include/header.inc");
require("./include/cmtlib.inc");

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php

$query = "SELECT *,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt FROM software,counter,auth_user WHERE software.appid='$id' AND software.appid=counter.appid AND software.user=auth_user.username GROUP BY software.appid";

increasecnt($id,"app_cnt");

$db->query($query);
if ($db->next_record()) {

  $db_status = $db->f("status");
  if ($db_status == 'A') {
    appfull($query);


				// Shows the comments on this app
    $query="SELECT * FROM comments,auth_user WHERE appid='$id' AND auth_user.username=comments.user_cmt ORDER BY creation_cmt DESC";
    cmtshow($query);
  } else {
    switch ($db_status) {
      case "P":
        $be->box_full($t->translate("Error"), $t->translate("Application")." <b>".$db->f("name")."</b> ".$t->translate("has not yet been reviewed by a $sys_name Editor.<br> Please, be patient. It will be surely done in the next time."));
	break;
      case "M":				
	$be->box_full($t->translate("Error"), $t->translate("Application")." <b>".$db->f("name")."</b> ".$t->translate("is modified").".");
	break;
      case "D":
 	$be->box_full($t->translate("Error"), $t->translate("Application")." <b>".$db->f("name")."</b> ".$t->translate("is deleted").".");
	break;
      default:
        $be->box_full($t->translate("Error"), $t->translate("Application")." (ID: $id) ".$t->translate("does not exist").".");
	break;
    }
  }
} else {
  $be->box_full($t->translate("Error"), $t->translate("Application")." (ID: $id) ".$t->translate("does not exist").".");
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
