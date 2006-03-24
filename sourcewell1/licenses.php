<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ====================================================
#
# Copyright (c) 2001-2006 by
#     Lutz Henckel (lutz.henckel@fokus.fraunhofer.de) and
#     Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# Lists the software licenses
# It also gives the number of existing apps for each license
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
$bs = new box("100%",$th_strip_frame_color,$th_strip_frame_width,$th_strip_title_bgcolor,$th_strip_title_font_color,$th_strip_title_align
,$th_strip_body_bgcolor,$th_strip_body_font_color,$th_strip_body_align);
?>

<!-- content -->
<?php
// $iter is a variable for printing the developers in steps of 10
if (!isset($iter)) $iter=0;
$iter*=10;

if (isset($find) && ! empty($find)) {
      $by = "%".$find."%";
}
if (!isset($by) || empty($by)) {
  $by = "%";
}

$alphabet = array ("A","B","C","D","E","F","G","H","I","J","K","L",
              "M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z");
$msg = "[ ";

while (list(, $ltr) = each($alphabet)) {
  $msg .= "<a href=\"".htmlentities($sess->url("licenses.php").$sess->add_query(array("by" => $ltr."%")))."\">$ltr</a>&nbsp;| ";
}

$msg .= "<a href=\"".htmlentities($sess->url("licenses.php").$sess->add_query(array("by" => "%")))."\">".$t->translate("All")."</a>&nbsp;] ";
$msg .= "<form action=\"".$sess->url("licenses.php")."\">"
     ."<p>Search for <input TYPE=\"text\" SIZE=\"10\" NAME=\"find\" VALUE=\"".$find."\">"
     ."&nbsp;<input TYPE=\"submit\" NAME= \"Find\" VALUE=\"Go\"></form>";

$bs->box_strip($msg);

$columns = "COUNT(*)";
$tables = "licenses";
$where = "license LIKE '$by'";

// We need to know the total number of users
$query = "SELECT $columns FROM $tables WHERE $where";
$db->query($query);
$db->next_record();
$numiter = ($db->f("COUNT(*)")/10);

$limit = "$iter,10";

$db->query("SELECT DISTINCT * FROM licenses WHERE license LIKE '$by' ORDER BY license ASC LIMIT $limit");
$bx->box_begin();
$bx->box_title($t->translate("Licenses"));
$bx->box_body_begin();
$i = 1;
echo "<table border=0 align=center cellspacing=1 cellpadding=1 width=\"100%\">\n";
echo "<tr><td><b>".$t->translate("No").".</b></td><td><b>#&nbsp;".$t->translate("Apps")."</b></td><td><b>".$t->translate("License")."</b></td></tr>\n";
while($db->next_record()) {
  $license = $db->f("license");
  $db2 = new DB_SourceWell;
  $db2->query("SELECT COUNT(*) FROM software WHERE license='$license' AND status='A'");
  $db2->next_record();
  $num = "[".sprintf("%03d",$db2->f("COUNT(*)"))."]";
  echo "<tr><td>$i</td><td><a href=\"".htmlentities($sess->url("appbylic.php").$sess->add_query(array("license" => $license)))."\">$num</a></td><td><a href=\"".$db->f("url")."\" target=\"_blank\">".$license."</a></td></tr>\n";
  $i++;
}
echo "</table>\n";
$bx->box_body_end();
$bx->box_end();

if ($numiter > 1) {
  $url = "licenses.php";
  $urlquery = array("by" => "$by","find" => "$find");
  show_more ($iter,$numiter,$url,$urlquery);
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
