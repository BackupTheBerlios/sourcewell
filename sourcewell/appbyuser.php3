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
# This file shows the apps inserted by the user
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

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
$bs = new box("100%",$th_strip_frame_color,$th_strip_frame_width,$th_strip_title_bgcolor,$th_strip_title_font_color,$th_strip_title_align,$th_strip_body_bgcolor,$th_strip_body_font_color,$th_strip_body_align);
?>

<!-- content -->
<?php
$db = new DB_SourceWell;

if (!isset($usr) || empty($usr)) {
  if (isset($auth)) {
    $usr = $auth->auth["uname"];
  } else {
    $usr = "";
  }
}

// $iter is a variable for printing the Top Statistics in steps of 10 apps
if (!isset($iter)) $iter=0;
$iter*=10;

$columns = "COUNT(*)";
$from = "software,auth_user,counter";
$where = "software.user=auth_user.username AND software.user=\"$usr\" AND software.appid=counter.appid";
if (!isset($auth) || empty($auth->auth["perm"]) || !$perm->have_perm("editor")) {
  $where .= " AND software.status = 'A'";
}

// We need to know the total number of apps inserted by the user
$result = mysql_db_query($db_name,"SELECT $columns FROM $from WHERE $where");
$row = mysql_fetch_row($result);
$numiter = ($row[0]/10);

$columns = "*,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt";
$tables = "software,auth_user,counter";
$where = "software.user=auth_user.username AND software.user=\"$usr\" AND software.appid=counter.appid";

if (!isset($auth) || empty($auth->auth["perm"]) || !$perm->have_perm("editor")) {
  $where .= " AND software.status = 'A'";
}
$where .= " GROUP BY software.appid";

switch ($by) {
  case "Importance":
    $order = "sum_cnt DESC";
    break;			
  case "Urgency":
    $order = "software.urgency DESC";
    break;			
  case "Name":
    $order = "software.name ASC";
    break;			
  case "Date":
  default:
    $by = "Date";
    $order = "software.modification DESC";
    break;
}

$limit = "$iter,10";
if (!$result = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where ORDER BY $order LIMIT $limit")) {
  mysql_die();
} else {
  $sort = $t->translate("sorted by").": "
  ."<a href=\"".basename($PHP_SELF)."?usr=$usr&by=Date\">".$t->translate("Date")."</a>"
  ." | <a href=\"".basename($PHP_SELF)."?usr=$usr&by=Importance\">".$t->translate("Importance")."</a>"
  ." | <a href=\"".basename($PHP_SELF)."?usr=$usr&by=Urgency\">".$t->translate("Urgency")."</a>"
  ." | <a href=\"".basename($PHP_SELF)."?usr=$usr&by=Name\">".$t->translate("Name")."</a>\n";

  $bs->box_strip($sort);
  while ($row = mysql_fetch_array($result)) {
    appupdate($row);
  }
  if (mysql_num_rows($result) < 1) {
    $msg = $t->translate("No Apps of User exist").".";
    $bx->box_full($t->translate("Apps of User"), $msg);
  }
  mysql_free_result($result);

  if ($numiter > 1) {
    $url = basename($PHP_SELF)."?usr=$usr&by=$by&";
    show_more ($iter,$numiter,$url);
  }
} 
?>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>
