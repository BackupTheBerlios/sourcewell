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
# This file shows the app and the inserted comment
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

page_open(array("sess" => "SourceWell_Session",
                "auth" => "SourceWell_Auth",
                "perm" => "SourceWell_Perm"));

require "header.inc";
require "cmtlib.inc";

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
if ($perm->have_perm("user_pending")) {
  $be->box_full($t->translate("Error"), $t->translate("Access denied"));
  $auth->logout();
} else {
  if (isset($id)) {

			// Insert new comment
    $tables = "comments";
    $set = "appid='$id',user_cmt='".$auth->auth["uname"]."',subject_cmt='$subject',text_cmt='$text',creation_cmt=NOW()";
    $db->query("INSERT $tables SET $set");

    # sends email to system administrators

    if ($GLOBALS["ml_notify"]) {
         $msg = "New Comment inserted by ".$auth->auth["uname"].".\n\n";
         $msg .= "Subject: ".$subject."\n\n";
         $msg .= "Body: ".$text"\n\n\n";
         $msg .= $sys_url."app.php3?appid=".$id;
    	 mailuser("editor", "comment inserted", $msg);
    }

		// Select and show new/updated application with comments
    $columns = "*,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt";
    $tables = "software,counter,auth_user";
    $where = "software.appid='$id' AND software.appid=counter.appid AND software.user=auth_user.username";
    $group = "software.appid";
    $query = "SELECT $columns FROM $tables WHERE $where GROUP BY $group";
    appfull($query);
				// we show the comments if available
    $query = "SELECT * FROM comments,auth_user WHERE appid='$id' AND auth_user.username=comments.user_cmt ORDER BY creation_cmt DESC";
    cmtshow($query);
  } else {
    $be->box_full($t->translate("Error"), $t->translate("No Application ID specified"));
  }
}
?>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>
