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
# This file contains the comment form
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

page_open(array("sess" => "SourceWell_Session",
                "auth" => "SourceWell_Auth",
                "perm" => "SourceWell_Perm"));

require "header.inc";
require "cmtlib.inc";

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
if ($perm->have_perm("admin")) {
  $db = new DB_SourceWell;

  if (isset($delete)) {
    if ($delete == 1) {
      $columns = "*";
      $tables = "comments";
      $where = "creation_cmt='$modification' AND appid='$id'";
      if (!$result = mysql_db_query($db_name, "SELECT $columns FROM $tables WHERE $where")) {
        mysql_die();
      } else {
        $row = mysql_fetch_array($result);
        cmtshow($row);
        $bx->box_begin();
        $bx->box_title($t->translate("Delete this comment? (please, think there's no way for undoing comment deletion)"));
        $bx->box_body_begin();	
        echo "<table><tr><td>\n";
        echo "<form action=\"$PHP_SELF\" method=\"POST\">\n";
        echo "<input type=\"hidden\" name=\"modification\" value=\"".$row["creation_cmt"]."\">\n";
        echo "<input type=\"hidden\" name=\"id\" value=\"".$row["appid"]."\">\n";
        echo "<input type=\"hidden\" name=\"delete\" value=\"2\">\n";
        echo "<input type=\"hidden\" name=\"modify\" value=\"0\">\n";
        echo "<input type=\"submit\" value=\"".$t->translate("Yes, Delete")."\">\n";

        echo "</form></td><td>\n";
        echo "<form action=\"$PHP_SELF\" method=\"POST\">\n";
        echo "<input type=\"hidden\" name=\"modification\" value=\"".$row["creation_cmt"]."\">\n";
        echo "<input type=\"hidden\" name=\"id\" value=\"".$row["appid"]."\">\n";
        echo "<input type=\"hidden\" name=\"modify\" value=\"1\">\n";
        echo "<input type=\"hidden\" name=\"delete\" value=\"0\">\n";
        echo "<input type=\"submit\" value=\"".$t->translate("No, Just Modify")."\">\n";
        echo "</form></td></td></table>\n";

        $bx->box_body_end();
        $bx->box_end();
      }
    }
    if ($delete == 2) {
					// We remove it from our DB
      $tables = "comments";
      $where = "creation_cmt='$modification' AND appid='$id'";
      if (!$result = mysql_db_query($db_name, "DELETE FROM $tables WHERE $where")) {
  	mysql_die();
      }

      $bx->box_begin();
      $bx->box_title($t->translate("Comment Deleted"));
      $bx->box_body_begin();	
      echo "Selected Comment was deleted";
      $bx->box_body_end();
      $bx->box_end();
    }
  }
  if (isset($modify)) {
    if ($modify == 1) {
      $columns = "*";
      $tables = "comments,software";
      $where = "comments.appid='$id' AND software.appid = comments.appid AND creation_cmt='$modification'";
      if (!$result = mysql_db_query($db_name, "SELECT $columns FROM $tables WHERE $where")) {
	mysql_die();
      } else {
        $row = mysql_fetch_array($result);
        cmtmod($row);
      }
    }
    if ($modify == 2) {
				// We insert it into the DB
      $tables = "comments";
      $set = "subject_cmt='$subject',text_cmt='$text',creation_cmt='$modification'";
      $where = "creation_cmt='$modification' AND appid='$id'";
      if (!$result = mysql_db_query($db_name, "UPDATE $tables SET $set WHERE $where")) {
  	mysql_die();
      }
				// We show what we've inserted
      $columns = "*";
      $tables = "comments";
      $where = "creation_cmt='$modification' AND appid='$id'";
      if (!$result = mysql_db_query($db_name, "SELECT $columns FROM $tables WHERE $where")) {
        mysql_die();
      } else {
        $row = mysql_fetch_array($result);
        cmtshow($row);
      }
    }
  }
}
?>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>
