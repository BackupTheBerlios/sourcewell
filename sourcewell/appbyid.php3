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
# This file shows an app (given by the id parameter)
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

require "header.inc";
require "cmtlib.inc";

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
$db = new DB_SourceWell;

$columns = "*,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt";
$tables = "software,counter,auth_user";
$where = "software.appid='$id' AND software.appid=counter.appid AND software.user=auth_user.username";
$group = "software.appid";
if (!$result = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where GROUP BY $group"))
{
  mysql_die();
} else {
  increasecnt($id,"app_cnt");
  if (($row = mysql_fetch_array($result)) AND $row["status"] == 'A') {
    appfull($row);
    $columns = "*";
    $tables = "comments,auth_user";
    $where = "appid='$id' AND auth_user.username=comments.user_cmt";
    $order = "creation_cmt DESC";
    if (!$result = mysql_db_query($db_name, "SELECT $columns FROM $tables WHERE $where ORDER BY $order")) {
      mysql_die();
    } else {
      while ($row = mysql_fetch_array($result)) {
        cmtshow($row);
      }
    }
  } else {
    switch ($row["status"]) {
      case "P":
        $be->box_full($t->translate("Error"), $t->translate("Application")." <b>".$row["name"]."</b> ".$t->translate("has not yet been reviewed by a $sys_name Editor.<br> Please, be patient. It will be surely done in the next time."));
	break;
      case "M":				
	$be->box_full($t->translate("Error"), $t->translate("Application")." <b>".$row["name"]."</b> ".$t->translate("is modified").".");
	break;
      case "D":
 	$be->box_full($t->translate("Error"), $t->translate("Application")." <b>".$row["name"]."</b> ".$t->translate("is deleted").".");
	break;
      default:
        $be->box_full($t->translate("Error"), $t->translate("Application")." (ID: $id) ".$t->translate("does not exist").".");
	break;
    }
  }
  mysql_free_result($result);
}
?>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>
