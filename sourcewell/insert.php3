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
# This file inserts an applications
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

  if (empty($name) || empty($version)) {
    $be->box_full($t->translate("Error"), $t->translate("Parameter missing"));
  } else {

				// Insert application
				// If a user with editor permission
				// inserts one app, he doesn't need to extra validate it!
    if ($perm->have_perm("editor")) {
      $status = 'A';
    } else {
      $status = 'P';
    }

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

    $tables = "software";
    $section = trim(strtok($seccat, "/"));
    $category = trim(strtok("."));
    $columns = "*";
    $where = "name='$name' AND type='$type'";
 
    $db->query("SELECT $columns FROM $tables WHERE $where");
    if ($db->num_rows() > 0) {
      $be->box_full($t->translate("Error"), $t->translate("Application")." $name ".$t->translate("already exists"));
    } else {
      $set = "name='$name',type='$type',version='$version',section='$section',category='$category',license='$license',homepage='$homepage',download='$download',changelog='$changelog',rpm='$rpm',deb='$deb',tgz='$tgz',cvs='$cvs',screenshots='$screenshots',mailarch='$mailarch',developer='$developer',description='$description',modification=NOW(),creation=NOW(),email='$email',depend='$depend',user='".$auth->auth["uname"]."',urgency='$urgency',status='$status'";

      $db->query("INSERT $tables SET $set");

					// Get new application index
      $columns = "*";
      $where = "name='$name' AND type='$type'";
      $db->query("SELECT $columns FROM $tables WHERE $where");
      $db->next_record();

					// Insert new history
      $tables = "history";
      $set = "appid='".$db->f("appid")."',user_his='".$auth->auth["uname"]."',creation_his='".$db->f("modification")."',version_his='".$db->f("version")."'";
      $db->query("INSERT $tables SET $set");

				// Insert new counters
      $tables = "counter";
      $set = "appid=".$db->f("appid");
      $db->query("INSERT $tables SET $set");

				// Select and show new/updated application with counters
     $columns = "*,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt";
     $tables = "software,counter,auth_user";
     $where = "software.appid=".$db->f("appid")." AND software.appid=counter.appid AND software.user=auth_user.username";
     $group = "software.appid";

     $query  = "SELECT $columns FROM $tables WHERE $where GROUP BY $group";
     appfull($query);

     if ($ml_notify) {
        $msg = "insert application $name $version (".typestr($type).") by ".$auth->auth["uname"].".";
	mailuser("editor", "insert application", $msg);
      }
    }
  }
}
?>
<!-- end content -->

<?php
require("footer.inc");
@page_close();
?>
