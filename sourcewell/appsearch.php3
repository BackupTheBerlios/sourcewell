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
# This file proceeds search of applications by their name
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

require("header.inc");

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$bs = new box("100%",$th_strip_frame_color,$th_strip_frame_width,$th_strip_title_bgcolor,$th_strip_title_font_color,$th_strip_title_align,$th_strip_body_bgcolor,$th_strip_body_font_color,$th_strip_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
$db = new DB_SourceWell;

      // When there's a search for a blank line, we look for "xxxxxxxx"
if (!isset($search) || $search=="") {
  $search = "xxxxxxxx";
}

// $iter is a variable for printing the Top Statistics in steps of 10 apps
if (!isset($iter)) $iter=0;
$iter*=10;

$columns = "COUNT(*)";
$tables = "software,counter";
$where = "software.appid=counter.appid AND software.status='A' AND software.name LIKE '%$search%'";

// We need to know the total number of apps
$result = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where");
$row = mysql_fetch_row($result);
$numiter = ($row[0]/10);
mysql_free_result($result);

$columns = "*,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt";
$tables = "software,counter,auth_user";
$where = "software.appid=counter.appid AND software.user=auth_user.username AND software.status='A' AND software.name LIKE '%$search%' GROUP BY software.appid";
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
  if (mysql_num_rows($result) < 1) {
    $bx->box_full($t->translate("Search"),$t->translate("No Application found"));
  } else {
    $sort = $t->translate("sorted by").": "
    ."<a href=\"".basename($PHP_SELF)."?search=".rawurlencode($search)."&by=Date\">".$t->translate("Date")."</a>"
    ." | <a href=\"".basename($PHP_SELF)."?search=".rawurlencode($search)."&by=Importance\">".$t->translate("Importance")."</a>"
    ." | <a href=\"".basename($PHP_SELF)."?search=".rawurlencode($search)."&by=Urgency\">".$t->translate("Urgency")."</a>"
    ." | <a href=\"".basename($PHP_SELF)."?search=".rawurlencode($search)."&by=Name\">".$t->translate("Name")."</a>\n";
    $bs->box_strip($sort);
    while($row = mysql_fetch_array($result)) {
      appdat($row);
    }
    mysql_free_result($result);
    if ($numiter > 1) {
      $url = basename($PHP_SELF)."?search=$search&by=$by&";
      show_more ($iter,$numiter,$url);
    }
  }
}
?>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>
