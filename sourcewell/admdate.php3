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
# This file checks the dates of the apps to avoid having changes as
# updates
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
$bi = new box("80%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("80%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
if (!$perm->have_perm("admin")) {
  $be->box_full($t->translate("Error"), $t->translate("Access denied"));
  $auth->logout();
} else {
  $db = new DB_SourceWell;

  if (!isset($action)) $action = "check";
  $where = "";
  if (isset($id)) $where = "WHERE appid='$id'";
			
				// Check application
  $columns = "*";
  $tables = "software";
  if (!$result = mysql_db_query($db_name, "SELECT $columns FROM $tables $where")) {
    mysql_die();
  } else {
    $i = 0;
    while ($row = mysql_fetch_array($result)) {
      $hcolumns = "*";
      $htables = "history";
      $hwhere = "appid = '$row[appid]'";
      $horder = "creation_his DESC";
      if (!$hresult = mysql_db_query($db_name, "SELECT $hcolumns FROM $htables WHERE $hwhere ORDER BY $horder")) {
	mysql_die();
      } else {
        $hrow = mysql_fetch_array($hresult);
	if ($row[modification] != $hrow[creation_his]) {
	  $timestamp = mktimestamp($row[modification]);
	  $title = "<b>$row[name] ($row[appid])</b>";
	  $bx->box_begin();
	  $bx->box_title($title);
	  $body = "Modification date: ".timestr($timestamp)."\n";
	  $timestamp = mktimestamp($hrow[creation_his]);
	  $body .= "<br>History date: ".timestr($timestamp)."\n";
	  $bx->box_body($body);
	  switch ($action) {
	    case "check":
	      $title = "<a href=\"$PHP_SELF?action=update&id=$row[appid]\"><img src=\"images/recycled.png\" border=0 alt=\"".$t->translate("Update")."\"></a>\n";
	      $bx->box_title($title);
	      break;
	    case "update":
	      $set = "modification = '$hrow[creation_his]'";
	      $where = "appid = '$row[appid]'";
		if (!$uresult = mysql_db_query($db_name, "UPDATE $tables SET $set WHERE $where")) {
		  mysql_die();
		} else {
		  $timestamp = mktimestamp($hrow[creation_his]);
		  $title = "Modification date is updated to ".timestr($timestamp)."\n";
		  $bx->box_title($title);
		}
	      break;
	    default:
	      $be->box_full($t->translate("Error"), $t->translate("Invalid action"));
	      break;
	  }
	  $bx->box_end();
	  $i++;
	}
	mysql_free_result($hresult);
      }
    }
    if ($i < 1) {
      $msg = $t->translate("All dates are consistent");
      $bi->box_full($t->translate("Check Date"), $msg);
    }
    mysql_free_result($result);
  }
}
?>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>
