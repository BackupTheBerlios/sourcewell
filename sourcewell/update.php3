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
# (explanation) 
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
if ($perm->have_perm("user_pending") || ($action == "review" && !$perm->have_perm("editor")) || ($action == "change" && !$perm->have_perm("editor"))) {
    $be->box_full($t->translate("Error"), $t->translate("Access denied"));
    $auth->logout();
} else {
  if (isset($id)) {
    $db = new DB_SourceWell;

					// Update application
    $type = trim($type);
    $version = trim($version);
    $license = trim($license);
    $homepage = trim($homepage);
    $download = trim($download);
    $changelog = trim($changelog);
    $rpm = trim($rpm);
    $deb = trim($deb);
    $tgz = trim($tgz);
    $cvs = trim($cvs);
    $screenshots = trim($screenshots);
    $mailarch = trim($mailarch);
    $developer = trim($developer);
    $description = trim($description);
    $email = trim($email);
    $depend = trim($depend);
    $urgency = trim($urgency);

    $columns = "*";
    $tables = "software";
    $section = trim(strtok($seccat, "/"));
    $category = trim(strtok("."));
    $set = "type='$type',version='$version',section='$section',category='$category',license='$license',homepage='$homepage',download='$download',changelog='$changelog',rpm='$rpm',deb='$deb',tgz='$tgz',cvs='$cvs',screenshots='$screenshots',mailarch='$mailarch',developer='$developer',description='$description',email='$email',depend='$depend',urgency='$urgency'";

    switch ($action) {
      case "update":
	$set = $set.",modification=NOW(),user='".$auth->auth["uname"]."'";
	if ($perm->have_perm("editor")) {
	  $set = $set.",status='A'";
	} else {
	  $set = $set.",status='P'";
	}
	break;
      case "review":
	$set = $set.",modification='$modification'";
	$set = $set.",status='A'";
	break;
      case "change":
	$set = $set.",modification='$modification'";
	$set = $set.",status='$status'";
	break;
      case "delete":
	$set = $set.",modification='$modification'";
	$set = $set.",status='D'";
	break;
      case "undelete":
	$set = $set.",modification='$modification'";
	if ($perm->have_perm("editor")) {
	  $set = $set.",status='A'";
	} else {
	  $set = $set.",status='P'";
	}
	break;
    }
    $where = "appid='$id'";
    if (!$result = mysql_db_query($db_name, "UPDATE $tables SET $set WHERE $where")) {
      mysql_die();
    } else {

						// Insert new history if apps is updated
      if ($action == "update") {
        $tables = "history";
        $set = "appid='$id',user_his='".$auth->auth["uname"]."',creation_his=NOW(),version_his='$version'";
        if (!$result = mysql_db_query($db_name, "INSERT $tables SET $set")) {
	  mysql_die();
        }
      }

						// Modify existing history if apps is changed
      if ($action == "change") {
        $tables = "history";
        $set = "creation_his='$modification',version_his='$version'";
        $where = "appid='$id' AND creation_his='$modification' AND version_his='$oldversion'";
        if (!$result = mysql_db_query($db_name, "UPDATE $tables SET $set WHERE $where")) {
	  mysql_die();
        }
      }

				// Select and show new/updated application with comments
      $columns = "*,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt";
      $tables = "software,counter,auth_user";
      $where = "software.appid='$id' AND software.appid=counter.appid AND software.user=auth_user.username";
      $group = "software.appid";

      if (!$result = mysql_db_query($db_name, "SELECT $columns FROM $tables WHERE $where GROUP BY $group")) {
        mysql_die();
      } else {
        if ($row = mysql_fetch_array($result)) {
          appfull($row);
          $columns = "*";
          $tables = "comments,auth_user";
          $where = "appid='$id' AND auth_user.username=comments.user_cmt";
          $order = "creation_cmt DESC";
          if (!$result = mysql_db_query($db_name, "SELECT $columns FROM $tables WHERE $where ORDER BY $order")) {
 	    mysql_die();
          } else {
	    while ($rowc = mysql_fetch_array($result)) {
	      cmtshow($rowc);
	    }
          }
          if ($ml_notify) {
  	    $message = $action." application ".$row["name"]." ".$row["version"]." (".typestr($row["type"]).") by ".$auth->auth["uname"];
	    mailuser("editor", $action." application", $message);
          }
        } else {
          $be->box_full($t->translate("Error"), $t->translate("Application")." (ID: $id) ".$t->translate("does not exist"));
        }
      }
    }
  } else {
    $be->box_full($t->translate("Error"), $t->translate("No Application ID specified")."."
    ."<br>".$t->translate("Please select")." <a href=\"appbyuser.php3\">".$t->translate("Change Apps")."</a>.");
  }
}
?>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>
