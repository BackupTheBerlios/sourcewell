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
# This page lists the users registered in our system
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
$be = new box("80%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
$bs = new box("100%",$th_strip_frame_color,$th_strip_frame_width,$th_strip_title_bgcolor,$th_strip_title_font_color,$th_strip_title_align,$th_strip_body_bgcolor,$th_strip_body_font_color,$th_strip_body_align);
?>

<!-- content -->
<?php
$db = new DB_SourceWell;

if (!isset($by) || empty($by)) {
  $by = "%";
}

$alphabet = array ("A","B","C","D","E","F","G","H","I","J","K","L",
		"M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z");
$msg = "[ ";

while (list(, $ltr) = each($alphabet)) {
  $msg .= "<a href=\"".basename($PHP_SELF)."?by=$ltr%\">$ltr</a> | ";
}

$msg .= "<a href=\"".basename($PHP_SELF)."?by=%\">".$t->translate("All")."</a> ]";

$bs->box_strip($msg);
$columns = "*";
$tables = "auth_user";
$where = "username LIKE '$by'";
$order = "username ASC";
if (!$result = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where ORDER BY $order")) {
  mysql_die();
} else {
  $bx->box_begin();
  $bx->box_title($t->translate("Users"));
  $bx->box_body_begin();
  echo "<table border=0 align=center cellspacing=1 cellpadding=1 width=100%>\n";
  echo "<tr><td><b>".$t->translate("No").".</b></td><td><b>#&nbsp;".$t->translate("Apps")."</b></td><td><b>".$t->translate("Username")."</b></td><td><b>".$t->translate("Realname")."</b></td><td><b>".$t->translate("E-Mail")."</b></td></tr>\n";

  $i = 1;
  while($row = mysql_fetch_array($result)) {
    $columns = "COUNT(*)";
    $tables = "software";
    $where = "user=\"".$row["username"]."\" AND status=\"A\"";
    $num = "";
    if ($resultn = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where")) {
      $rown = mysql_fetch_row($resultn);
      $num = "[".sprintf("%03d",$rown[0])."]";
      mysql_free_result($resultn);
    }
    echo "<tr><td>".sprintf("%d",$i)."</td>\n";
    echo "<td><a href=\"appbyuser.php3?usr=".$row["username"]."\">$num</a></td>\n";
    echo "<td>".$row["username"]."</td>\n";
    echo "<td>".$row["realname"]."</td>";
    echo "<td>&lt;<a href=\"mailto:".$row["email_usr"]."\">".ereg_replace("@"," at ",htmlentities($row["email_usr"]))."</a>&gt;</td>";
    echo "</tr>\n";
    $i++;
  }
  echo "</table>\n";
}
$bx->box_body_end();
$bx->box_end();

?>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>
