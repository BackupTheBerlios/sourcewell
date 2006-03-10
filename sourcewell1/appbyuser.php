<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ====================================================
#
# Copyright (c) 2001-2004 by
#     Lutz Henckel (lutz.henckel@fokus.fraunhofer.de) and
#     Gregorio Robles (grex@scouts-es.org)
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

  if (isset($find) && ! empty($find)) {
	$with = "%".$find."%";
  }
  if (!isset($with) || empty($with)) {
    $with = "%";
  }

  $alphabet = array ("A","B","C","D","E","F","G","H","I","J","K","L",
		"M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z");
  $msg = "[ ";

  while (list(, $ltr) = each($alphabet)) {
    $msg .= "<a href=\"".htmlentities($sess->url("appbyuser.php").$sess->add_query(array("with" => $ltr."%")))."\">$ltr</a>&nbsp;| ";
  }

  $msg .= "<a href=\"".htmlentities($sess->url("appbyuser.php").$sess->add_query(array("with" => "%")))."\">".$t->translate("All")."</a>&nbsp;]";
  $msg .= "<form action=\"".$sess->self_url()."\">"
	   ."<p>Search for <input TYPE=\"text\" SIZE=\"10\" NAME=\"find\" VALUE=\"".$find."\">"
       ."<input TYPE=\"hidden\" NAME= \"usr\" VALUE=\"$usr\">"
       ."&nbsp;<input TYPE=\"submit\" NAME= \"Find\" VALUE=\"Go\"></form>";

  $bs->box_strip($msg);

$columns = "COUNT(*)";
$from = "software,auth_user,counter";
$where = "software.user=auth_user.username AND software.user=\"$usr\" AND software.appid=counter.appid AND software.name LIKE '$with'";
if (!isset($auth) || empty($auth->auth["perm"]) || !$perm->have_perm("editor")) {
  $where .= " AND software.status = 'A'";
}

// We need to know the total number of apps inserted by the user
$query = "SELECT $columns FROM $from WHERE $where";
// echo "<p>$query\n";
$db->query($query);
$db->next_record();
$numiter = ($db->f("COUNT(*)")/10);

$columns = "*,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt";
$tables = "software,auth_user,counter";
$where = "software.user=auth_user.username AND software.user=\"$usr\" AND software.appid=counter.appid AND software.name LIKE '$with'";

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

$sort = $t->translate("sorted by").": "
."<a href=\"".htmlentities($sess->url("appbyuser.php").$sess->add_query(array("with" => "$with","find" => "$find","by" => "Date")))."\">".$t->translate("Date")."</a>"
." | <a href=\"".htmlentities($sess->url("appbyuser.php").$sess->add_query(array("with" => "$with","find" => "$find","by" => "Importance")))."\">".$t->translate("Importance")."</a>"
." | <a href=\"".htmlentities($sess->url("appbyuser.php").$sess->add_query(array("with" => "$with","find" => "$find","by" => "Urgency")))."\">".$t->translate("Urgency")."</a>"
." | <a href=\"".htmlentities($sess->url("appbyuser.php").$sess->add_query(array("with" => "$with","find" => "$find","by" => "Name")))."\">".$t->translate("Name")."</a>\n";

$bs->box_strip($sort);

$query = "SELECT $columns FROM $tables WHERE $where ORDER BY $order LIMIT $limit";
appupdate($query);

$db->query($query);
if ($db->num_rows() < 1) {
  $msg = $t->translate("No Apps of User exist").".";
  $bx->box_full($t->translate("Apps of User"), $msg);
}

if ($numiter > 1) {
  $url = "appbyuser.php";
  $urlquery = array("with" => "$with","find" => "$find","usr" => $usr, "by" => $by);
  show_more ($iter,$numiter,$url,$urlquery);
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
