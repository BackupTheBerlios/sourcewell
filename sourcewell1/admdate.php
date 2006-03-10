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
# This file checks the dates of the apps to avoid having changes as
# updates
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
$bi = new box("80%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("80%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
if (($config_perm_admdate != "all") && (!isset($perm) || !$perm->have_perm($config_perm_admdate))) {
  $be->box_full($t->translate("Error"), $t->translate("Access denied"));
} else {

  if (!isset($action)) $action = "check";
  $where = "WHERE status='A'";
  if (isset($id)) $where .= " AND appid='$id'";
			
// Check application
  $db->query("SELECT * FROM software $where");
  // echo"<p>SELECT * FROM software $where\n";
  $i=0;
  while($db->next_record()) {
    $db_appid = $db->f("appid");
    $db2 = new DB_SourceWell;
    $db2->query("SELECT * FROM history WHERE appid='$db_appid' ORDER BY creation_his DESC");
    $db2_exists = $db2->next_record();
    $db_modification = $db->f("modification");
    $db2_creation_his = $db2->f("creation_his");
    if ($db_modification != $db2_creation_his) {
      $timestamp = mktimestamp($db_modification);
      $title = "<b><a href=\"".htmlentities($sess->url("appbyid.php").$sess->add_query(array("id"=> $db->f(appid))))."\">".$db->f(name)."</a> (".$db->f(appid).")</b>";
      $bx->box_begin();
      $bx->box_title($title);
      $body = "Modification date: ".timestr($timestamp)."\n";
      $timestamp = mktimestamp($db2_creation_his);
      $body .= "<br>History date: ".timestr($timestamp)."\n";
      $bx->box_body($body);    
      switch ($action) {
	case "check":
          if ($db2_exists) $action2 = "update";
          else $action2 = "insert";
	  $title = "<a href=\"".htmlentities($sess->self_url().$sess->add_query(array("action" => $action2, "id"=> $db_appid)))."\"><img src=\"images/recycled.png\" border=0 alt=\"".$t->translate("Update")."\"></a>\n";
	  $bx->box_title($title);
	  break;
        case "update":
          $db3 = new DB_SourceWell;
          $db3->query("UPDATE software SET modification='$db2_creation_his' WHERE appid='$db_appid'");
          $timestamp = mktimestamp($db2_creation_his);
          $title = "Modification date is updated to ".timestr($timestamp)."\n";
          $bx->box_title($title);
          break;
        case "insert":
          $db3 = new DB_SourceWell;
          $db_user = $db->f("user");
          $db_version = $db->f("version");
          $db3->query("INSERT history SET appid='$db_appid', user_his='$db_user', creation_his='$db_modification', version_his='$db_version'");
          // echo "<p>INSERT history SET appid='$db_appid', user_his='$db_user', creation_his='$db_modification', version_his='$db_version'\n";
          $timestamp = mktimestamp($db_modification);
          $title = "History date is updated to ".timestr($timestamp)."\n";
          $bx->box_title($title);
        break;
        default:
	  $be->box_full($t->translate("Error"), $t->translate("Invalid action"));
	  break;
      }
      $bx->box_end();
      $i++;
    }
  }
  if ($i < 1) {
    $msg = $t->translate("All dates are consistent");
    $bi->box_full($t->translate("Check Date"), $msg);
  }
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
