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
# This file shows the apps with a certain license given as parameter
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

// $iter is a variable for printing the Top Statistics in steps of 10 apps
if (!isset($iter)) $iter=0;
$iter*=10;

// We extract the URL for the license_text

$db->query("SELECT url FROM licenses WHERE license='$license'");
$db->next_record();
$license_text = $db->f("url");


// We need to know the total number of apps with the given license
$db->query("SELECT COUNT(*) FROM software WHERE license='$license' AND status='A'");
$db->next_record();
$numiter = ($db->f("COUNT(*)")/10);

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

$db->query("SELECT *,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt FROM software,counter WHERE license='$license' AND status='A' AND software.appid=counter.appid GROUP BY software.appid ORDER BY $order LIMIT $limit");

$sort = $t->translate("sorted by").": "
."<a href=\"".$sess->self_url().$sess->add_query(array("license" => $license, "by" => "Date"))."\">".$t->translate("Date")."</a>"
." | <a href=\"".$sess->self_url().$sess->add_query(array("license" => $license, "by" => "Importance"))."\">".$t->translate("Importance")."</a>"
." | <a href=\"".$sess->self_url().$sess->add_query(array("license" => $license, "by" => "Urgency"))."\">".$t->translate("Urgency")."</a>"
." | <a href=\"".$sess->self_url().$sess->add_query(array("license" => $license, "by" => "Name"))."\">".$t->translate("Name")."</a>\n";

$bs->box_strip($sort);
appcat($query,$t->translate("License").": ".$license." (<a href=\"".$sess->url("licenses.php3").$sess->add_query(array("license" => $license))."\">license text</a>)",$iter+1);

if ($numiter > 1) {
  $url = "appbylic.php3";
  $urlquery = array("license" => $license, "by" => $by);
  show_more ($iter,$numiter,$url,$urlquery);
}
?>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>
