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
# Update existing apps.
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

require("./include/prepend.php3");

page_open(array("sess" => "SourceWell_Session",
                "auth" => "SourceWell_Auth",
                "perm" => "SourceWell_Perm"));

require "./include/header.inc";
require("./include/cmtlib.inc");

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
    $name = trim($name);
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
    $user = trim($user);
	
    $columns = "modification,creation,version,status";
    $tables = "software";
	$where = "appid='$id'";
	$db->query("SELECT $columns FROM $tables WHERE $where");
    if ($db->num_rows() > 0) {
		$db->next_record();
    	$modification = $db->f("modification");
    	$creation = $db->f("creation");
    	$oldversion = $db->f("version");
    	$status = $db->f("status");
	}
	
    $columns = "*";
    $section = trim(strtok($seccat, "/"));
    $category = trim(strtok("."));
    $set = "name='$name',type='$type',version='$version',section='$section',category='$category',license='$license',homepage='$homepage',download='$download',changelog='$changelog',rpm='$rpm',deb='$deb',tgz='$tgz',cvs='$cvs',screenshots='$screenshots',mailarch='$mailarch',developer='$developer',description='$description',email='$email',depend='$depend',urgency='$urgency',creation='$creation',user='$user'";

    switch ($action) {
      case "update":
		if ($version == $oldversion) {
		    $set .= ",modification='$modification'";
		} else {
			$set .= ",modification=NOW()";
		}
	    $set .= ",status='P'";
	    $set = "appid='$id',".$set;
		$tables = "pending";
		$operation = "INSERT";
        $where = "";
	    break;
      case "delete":
	    $set .= ",modification='$modification'";
	    $set .= ",status='D'";
		$operation = "UPDATE";
        $where = "WHERE appid='$id'";
	    break;
      case "undelete":
	    $set .= ",modification='$modification'";
		$set .= ",status='P'";
	    $set = "appid='$id',".$set;
		$tables = "pending";
		$operation = "INSERT";
		$where = "";
	    break;
    }
    $db->query("$operation $tables SET $set $where");
	// echo "<p>$operation $tables SET $set $where\n";

	// Select and show new/updated application with comments
    if ($operation == "UPDATE") {
      $tables = "software,counter,auth_user";
      $where = "software.appid='$id' AND software.appid=counter.appid AND software.user=auth_user.username";
      $group = "software.appid";
      $query = "SELECT $columns FROM $tables WHERE $where GROUP BY $group";
      appfull($query);

      $query = "SELECT * FROM comments,auth_user WHERE appid='$id' AND auth_user.username=comments.user_cmt ORDER BY creation_cmt DESC";
      cmtshow($query);
    } else { // $operation = "INSERT"
      $tables = "pending,auth_user";
      $where = "pending.name='$name' AND type='$type' AND version='$version' AND pending.user=auth_user.username";
      $group = "pending.name";

      $query  = "SELECT * FROM $tables WHERE $where GROUP BY $group";
	  // echo "<p>$query\n";

      apppend($query);
    }

    if ($ml_notify) {
      $db->query("SELECT name,version,type FROM software WHERE appid='$id'");
      $db->next_record();
      $message = $action." application ".$db->f("name")." ".$db->f("version")." (".typestr($db->f("type")).") by ".$auth->auth["uname"];
      mailuser("editor", $action." application", $message);
    }
  } else {
    $be->box_full($t->translate("Error"), $t->translate("No Application ID specified")."."
  ."<br>".$t->translate("Please select")." <a href=\"".$sess->url("appbyuser.php")."\">".$t->translate("Change Apps")."</a>.");
  }
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
