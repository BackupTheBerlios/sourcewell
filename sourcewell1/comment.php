<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ================================================
#
# Copyright (c) 2001-2004 by
#                Lutz Henckel (lutz.henckel@fokus.fraunhofer.de) and
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

require("./include/prepend.php3");

page_open(array("sess" => "SourceWell_Session"));
if (isset($auth) && !empty($auth->auth["perm"])) {
  page_close();
  page_open(array("sess" => "SourceWell_Session",
                  "auth" => "SourceWell_Auth",
                  "perm" => "SourceWell_Perm"));
}

require "./include/header.inc";
require("./include/cmtlib.inc");

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
if (($config_perm_admcomment != "all") && (!isset($perm) || !$perm->have_perm($config_perm_admcomment))) {
  $be->box_full($t->translate("Error"), $t->translate("Access denied"));
} else {

  if (isset($delete)) {
    if ($delete == 1) {
      $query = "SELECT * FROM comments WHERE creation_cmt='$modification' AND appid='$id'";
      cmtshow($query);

      $db->query($query);
      $db->next_record();
      $bx->box_begin();
      $bx->box_title($t->translate("Delete this comment? (please, think there's no way for undoing comment deletion)"));
      $bx->box_body_begin();	
      echo "<table><tr><td>\n";
      echo "<form action=\"".$sess->self_url()."\" method=\"POST\">\n";
      echo "<input type=\"hidden\" name=\"modification\" value=\"".$db->f("creation_cmt")."\">\n";
      echo "<input type=\"hidden\" name=\"id\" value=\"".$db->f("appid")."\">\n";
      echo "<input type=\"hidden\" name=\"delete\" value=\"2\">\n";
      echo "<input type=\"hidden\" name=\"modify\" value=\"0\">\n";
      echo "<input type=\"submit\" value=\"".$t->translate("Yes, Delete")."\">\n";

      echo "</form></td><td>\n";
      echo "<form action=\"".$sess->self_url()."\" method=\"POST\">\n";
      echo "<input type=\"hidden\" name=\"modification\" value=\"".$db->f("creation_cmt")."\">\n";
      echo "<input type=\"hidden\" name=\"id\" value=\"".$db->f("appid")."\">\n";
      echo "<input type=\"hidden\" name=\"modify\" value=\"1\">\n";
      echo "<input type=\"hidden\" name=\"delete\" value=\"0\">\n";
      echo "<input type=\"submit\" value=\"".$t->translate("No, Just Modify")."\">\n";
      echo "</form></td></td></table>\n";

      $bx->box_body_end();
      $bx->box_end();
    }
    if ($delete == 2) {
					// We remove it from our DB
      $db->query("DELETE FROM comments WHERE creation_cmt='$modification' AND appid='$id'");
      if ($db->affected_rows() < 1) {
        $be->box_full($t->translate("Error"), $t->translate("Database error"));
      }

      $bx->box_begin();
      $bx->box_title($t->translate("Comment Deleted"));
      $bx->box_body_begin();	
      echo $t->translate("Selected Comment was deleted");
      $bx->box_body_end();
      $bx->box_end();
    }
  }
  if (isset($modify)) {
    if ($modify == 1) {
      $query = "SELECT * FROM comments,software WHERE comments.appid='$id' AND software.appid = comments.appid AND creation_cmt='$modification'";
      cmtmod($query);
    }
    if ($modify == 2) {
				// We insert it into the DB
      $db->query("UPDATE comments SET subject_cmt='$subject',text_cmt='$text',creation_cmt='$modification' WHERE creation_cmt='$modification' AND appid='$id'");
      if ($db->affected_rows() < 1) {
        $be->box_full($t->translate("Error"), $t->translate("Database error"));
      }
				// We show what we've inserted

      $query = "SELECT * FROM comments WHERE creation_cmt='$modification' AND appid='$id'";
      cmtshow($query);
    }
  }
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>

