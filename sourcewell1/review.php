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
# Review pending apps.
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

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
if ($perm->have_perm("user_pending") || ($action == "review" && !$perm->have_perm("editor")) || ($action == "change" && !$perm->have_perm("editor"))) {
    $be->box_full($t->translate("Error"), $t->translate("Access denied"));
} else {
  if (isset($idx)) {
					// Review application
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
	
    $section = trim(strtok($seccat, "/"));
    $category = trim(strtok("."));
    $set = "name='$name',type='$type',version='$version',section='$section',category='$category',license='$license',homepage='$homepage',download='$download',changelog='$changelog',rpm='$rpm',deb='$deb',tgz='$tgz',cvs='$cvs',screenshots='$screenshots',mailarch='$mailarch',developer='$developer',description='$description',email='$email',depend='$depend',urgency='$urgency',creation='$creation',modification='$modification',user='$user',status='A'";

    switch ($action) {
      case "review":
		if ($id == 0) {
		  $operation = "INSERT";
          	  $where = "";
                  $oldversion = 0;
		} else {
		  $operation = "UPDATE";
          	  $where = "WHERE appid='$id'";
		  $db->query("SELECT version FROM software WHERE appid='$id'");
    	  	  if ($db->num_rows() > 0) {
			$db->next_record();
	    		$oldversion = $db->f("version");
		  }
		}

        	$db->query("$operation software SET $set $where");
	    	// echo "<p>$operation software SET $set $where\n";

		if ($id == 0) {
		  // Get new application index
		  $db->query("SELECT appid FROM software WHERE name='$name' AND type='$type'");
		  // echo "<p>SELECT appid FROM software WHERE name='$name' AND type='$type'\n";
		  $db->next_record();
		  $id = $db->f("appid");
		  // echo "<p>ID: $id\n";

		  // Insert new counters
		  $db->query("INSERT counter SET appid='$id'");
		  // echo "<p>INSERT counter SET appid='$id'\n";
		}
                if ($oldversion != stripslashes($version)) {
                  // Insert new history
                  $db->query("INSERT history SET appid='$id',user_his='$user',creation_his='$modification',version_his='$version'");
                  // echo "<p>INSERT history SET appid='$id',user_his='$user',creation_his='$modification',version_his='$version'\n";
		}

		// Select and show new/updated application with counters
		$columns = "*,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt";
		$tables = "software,counter,auth_user";
		$where = "software.appid='$id' AND software.appid=counter.appid AND software.user=auth_user.username";
		$group = "software.appid";
		
		$query  = "SELECT $columns FROM $tables WHERE $where GROUP BY $group";
		// echo "<p>SELECT $columns FROM $tables WHERE $where GROUP BY $group";
		appfull($query);

		// Delete pending apps
		$where = "idx='$idx'";
		$db->query("DELETE FROM pending WHERE $where");
		// echo "<p>DELETE FROM pending WHERE $where\n";
	    break;
      case "delete":
		$where = "idx='$idx'";
		$db->query("DELETE FROM pending WHERE $where");
		$bx->box_full($t->translate("Done"), $t->translate("Pending Application deleted"));
	    break;
    }

	// Notify administrators
    if ($ml_notify) {
      $message = $action." application $name $version (".typestr($type).") by ".$auth->auth["uname"];
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
