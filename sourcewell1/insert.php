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
	$auth->logout();
} else {

  if (empty($name) || empty($version)) {
    $be->box_full($t->translate("Error"), $t->translate("Parameter missing"));
  } else {
    $status = 'P';

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

    $section = trim(strtok($seccat, "/"));
    $category = trim(strtok("."));
 
    $set = "name='$name',type='$type',version='$version',section='$section',category='$category',license='$license',homepage='$homepage',download='$download',changelog='$changelog',rpm='$rpm',deb='$deb',tgz='$tgz',cvs='$cvs',screenshots='$screenshots',mailarch='$mailarch',developer='$developer',description='$description',modification=NOW(),creation=NOW(),email='$email',depend='$depend',user='".$auth->auth["uname"]."',urgency='$urgency',status='$status'";

    $db->query("INSERT pending SET $set");

	// Select and show new/updated application with counters
    $where = "pending.name='$name' AND type='$type' AND version='$version' AND pending.user=auth_user.username";
    $group = "pending.name";

    $query  = "SELECT * FROM pending,auth_user WHERE $where GROUP BY $group";
    apppend($query);

    if ($ml_notify) {
      $msg = "insert application $name $version (".typestr($type).") by ".$auth->auth["uname"].".";
	  mailuser("editor", "insert application", $msg);
    }
  }
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
