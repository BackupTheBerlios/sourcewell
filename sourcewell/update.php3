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
} else {
  if (isset($id)) {
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
	
    $columns = "modification,version,status";
    $tables = "software";
	$where = "appid='$id'";
	$db->query("SELECT $columns FROM $tables WHERE $where");
    if ($db->num_rows() > 0) {
		$db->next_record();
    	$modification = $db->f("modification");
    	$oldversion = $db->f("version");
    	$status = $db->f("status");
	}
	
    $columns = "*";
    $section = trim(strtok($seccat, "/"));
    $category = trim(strtok("."));
    $set = "type='$type',version='$version',section='$section',category='$category',license='$license',homepage='$homepage',download='$download',changelog='$changelog',rpm='$rpm',deb='$deb',tgz='$tgz',cvs='$cvs',screenshots='$screenshots',mailarch='$mailarch',developer='$developer',description='$description',email='$email',depend='$depend',urgency='$urgency'";

    switch ($action) {
      case "update":
	    $set .= ",user='".$auth->auth["uname"]."'";
		if ($version == $oldversion) {
		    $set .= ",modification='$modification'";
		} else {
			$set .= ",modification=NOW()";
		}
	    if ($perm->have_perm("editor")) {
		  if ($status != 'D') {
	        $set .= ",status='A'";
		  }
	    } else {
	      $set .= ",status='P'";
	    }
	    break;
      case "review":
	    $set .= ",modification='$modification'";
	    $set .= ",status='A'";
	    break;
      case "delete":
	    $set .= ",modification='$modification'";
	    $set .= ",status='D'";
	    break;
      case "undelete":
	    $set .= ",modification='$modification'";
	    if ($perm->have_perm("editor")) {
	      $set .= ",status='A'";
	    } else {
	      $set .= ",status='P'";
	    }
	    break;
    }
    $where = "appid='$id'";
    $db->query("UPDATE $tables SET $set WHERE $where");

				// Insert new history if apps is updated
    if ($action == "update" && $version != $oldversion) {
      $tables = "history";
      $set = "appid='$id',user_his='".$auth->auth["uname"]."',creation_his=NOW(),version_his='$version'";
      $db->query("INSERT $tables SET $set");
    }

		// Select and show new/updated application with comments
    $columns = "*,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt";
    $tables = "software,counter,auth_user";
    $where = "software.appid='$id' AND software.appid=counter.appid AND software.user=auth_user.username";
    $group = "software.appid";
    $query = "SELECT $columns FROM $tables WHERE $where GROUP BY $group";
    appfull($query);

    $query = "SELECT * FROM comments,auth_user WHERE appid='$id' AND auth_user.username=comments.user_cmt ORDER BY creation_cmt DESC";
    cmtshow($query);


    if ($ml_notify) {
      $db->query("SELECT name,version,type FROM software WHERE appid='$id'");
      $db->next_record();
      $message = $action." application ".$db->f("name")." ".$db->f("version")." (".typestr($db->f("type")).") by ".$auth->auth["uname"];
      mailuser("editor", $action." application", $message);
    }
  } else {
    $be->box_full($t->translate("Error"), $t->translate("No Application ID specified")."."
  ."<br>".$t->translate("Please select")." <a href=\"".$sess->url("appbyuser.php3")."\">".$t->translate("Change Apps")."</a>.");
  }
}
?>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>