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
# This file lists the pending apps
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

require "./include/header.inc";

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
$bs = new box("100%",$th_strip_frame_color,$th_strip_frame_width,$th_strip_title_bgcolor,$th_strip_title_font_color,$th_strip_title_align,$th_strip_body_bgcolor,$th_strip_body_font_color,$th_strip_body_align);
?>

<!-- content -->
<?php
if (($config_perm_apppend != "all") && (!isset($perm) || !$perm->have_perm($config_perm_apppend))) {
  $be->box_full($t->translate("Error"), $t->translate("Access denied"));
} else {

// $iter is a variable for printing the Top Statistics in steps of 10 apps
  if (!isset($iter)) $iter=0;
  $iter*=10;

  $columns = "COUNT(*)";
  $tables = "pending,auth_user";
  $where = "pending.user=auth_user.username";

// We need to know the total number of apps
  $db->query("SELECT $columns FROM $tables WHERE $where");
  $db->next_record();
  $numiter = ($db->f("COUNT(*)")/10);

  $columns = "*";
  $order = "pending.modification DESC";

  $limit = "$iter,10";

  $query = "SELECT $columns FROM $tables WHERE $where ORDER BY $order LIMIT $limit";
  appupdate($query);

  $db->query($query);
  if ($db->num_rows() < 1) {
    $msg = $t->translate("No pending Apps exist");
    $bx->box_full($t->translate("Pending Apps"), $msg);
  }
  if ($numiter > 1) {
    $url = "apppend.php";
    $urlquery = array("by" => "Date");
    show_more ($iter,$numiter,$url,$urlquery);
  }
}

?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
