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
# This is the comment administration file
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

page_open(array("sess" => "SourceWell_Session",
                "auth" => "SourceWell_Auth",
                "perm" => "SourceWell_Perm"));

require("header.inc");

$bx = new box("95%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$bx_small = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("80%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
$bs = new box("100%",$th_strip_frame_color,$th_strip_frame_width,$th_strip_title_bgcolor,$th_strip_title_font_color,$th_strip_title_align,$th_strip_body_bgcolor,$th_strip_body_font_color,$th_strip_body_align);
?>

<!-- content -->
<?
if ($perm->have_perm("admin")) {
  $db = new DB_SourceWell;

  if (!isset($by) || empty($by)) {
    $by = "";
  }
  $alphabet = array ("A","B","C","D","E","F","G","H","I","J","K","L",
				"M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z");
  $msg = "[ ";
  while (list(, $ltr) = each($alphabet)) {
    $msg .= "<a href=\"".basename($PHP_SELF)."?by=$ltr%\">$ltr</a>&nbsp;| ";
  }
  $msg .= "<a href=\"".basename($PHP_SELF)."?by=%\">".$t->translate("All")."</a>&nbsp;]";
  $bs->box_strip($msg);
  $columns = "software.appid,name,user_cmt,subject_cmt,creation_cmt";
  $tables = "comments,software";
  $where = "software.appid = comments.appid AND software.name LIKE '$by'";
  $order = "creation_cmt DESC";
  if (!$result = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where ORDER BY $order")) {
    mysql_die();
  } else {
    $bx->box_begin();
    $bx->box_title($t->translate("Comments"));
    $bx->box_body_begin();		

    echo "<table border=0 align=center cellspacing=1 cellpadding=1 width=100%>\n";
    echo "<tr><td><b>".$t->translate("No").".</b></td>\n";
    echo "<td><b>".$t->translate("Application")."</b></td>\n";
    echo "<td><b>".$t->translate("Subject")."</b></td>\n";
    echo "<td><b>".$t->translate("Author")."</b></td>\n";
    echo "<td><b>".$t->translate("Posted on")."</b></td>\n";
    echo "<td>&nbsp;</td>\n";
    echo "<td>&nbsp;</td></tr>\n";

    $i = 1;
    while($row = mysql_fetch_array($result)) {
      echo "<tr><td>$i</td>\n";
      echo "<td><a href=\"appbyid.php3?id=".($row["appid"])."\">".$row["name"]."</a></td>\n";
      echo "<td>".$row["subject_cmt"]."</td>\n";
      echo "<td>".$row["user_cmt"]."</td>\n";
      $timestamp = mktimestamp($row["creation_cmt"]);
      echo "<td>".timestr_short($timestamp)."</td>\n";

      echo "<td><form action=\"comment.php3\" method=\"POST\">\n";
      echo "<input type=\"hidden\" name=\"modify\" value=\"1\">\n";
      echo "<input type=\"hidden\" name=\"delete\" value=\"0\">\n";
      echo "<input type=\"hidden\" name=\"modification\" value=\"".$row["creation_cmt"]."\">\n";
      echo "<input type=\"hidden\" name=\"id\" value=\"".$row["appid"]."\">\n";
      echo "<input type=\"submit\"value=\"".$t->translate("Modify")."\">\n";
      echo "</form></td>\n";

      echo "<td><form action=\"comment.php3\" method=\"POST\">\n";
      echo "<input type=\"hidden\" name=\"delete\" value=\"1\">\n";
      echo "<input type=\"hidden\" name=\"modify\" value=\"0\">\n";
      echo "<input type=\"hidden\" name=\"modification\" value=\"".$row["creation_cmt"]."\">\n";
      echo "<input type=\"hidden\" name=\"id\" value=\"".$row["appid"]."\">\n";
      echo "<input type=\"submit\"value=\"".$t->translate("Delete")."\">\n";
      echo "</form></td>\n";
      echo "</tr>\n";
      $i++;
    }
    echo "</table>\n";
    $bx->box_body_end();
    $bx->box_end();
    mysql_free_result($result);
    echo "</table>\n";
  }
}
?>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>
