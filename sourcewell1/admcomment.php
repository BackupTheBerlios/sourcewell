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
# This is the comment administration file
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

require("./include/prepend.php3");

require("./include/prepend.php3");

page_open(array("sess" => "SourceWell_Session"));
if (isset($auth) && !empty($auth->auth["perm"])) {
  page_close();
  page_open(array("sess" => "SourceWell_Session",
                  "auth" => "SourceWell_Auth",
                  "perm" => "SourceWell_Perm"));
}

require("./include/header.inc");

$bx = new box("95%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$bx_small = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("80%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
$bs = new box("100%",$th_strip_frame_color,$th_strip_frame_width,$th_strip_title_bgcolor,$th_strip_title_font_color,$th_strip_title_align,$th_strip_body_bgcolor,$th_strip_body_font_color,$th_strip_body_align);
?>

<!-- content -->
<?
if (($config_perm_admcomment != "all") && (!isset($perm) || !$perm->have_perm($config_perm_admcomment))) {
  $be->box_full($t->translate("Error"), $t->translate("Access denied"));
} else {
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
    $msg .= "<a href=\"".htmlentities($sess->self_url().$sess->add_query(array("by"=>$ltr."%")))."\">$ltr</a>&nbsp;| ";
  }
  $msg .= "<a href=\"".htmlentities($sess->self_url().$sess->add_query(array("by"=>"%")))."\">".$t->translate("All")."</a>&nbsp;]";
  $msg .= "<form action=\"".$sess->url("admcomment.php")."\">"
       ."<p>Search for <input TYPE=\"text\" SIZE=\"10\" NAME=\"find\" VALUE=\"".$find."\">"
       ."&nbsp;<input TYPE=\"submit\" NAME= \"Find\" VALUE=\"Go\"></form>";

  $bs->box_strip($msg);

  $columns = "COUNT(*)";
  $tables = "comments,software";
  $where = "software.appid = comments.appid AND software.name LIKE '$by'";

// We need to know the total number of users
  $query = "SELECT $columns FROM $tables WHERE $where";
  $db->query($query);
  $db->next_record();
  $numiter = ($db->f("COUNT(*)")/10);

  $limit = "$iter,10";

  $db->query("SELECT software.appid,name,user_cmt,subject_cmt,creation_cmt FROM comments,software WHERE software.appid = comments.appid AND software.name LIKE '$by' ORDER BY creation_cmt DESC LIMIT $limit");
  $bx->box_begin();
  $bx->box_title($t->translate("Comments"));
  $bx->box_body_begin();		

  echo "<table border=0 align=center cellspacing=1 cellpadding=1 width=\"100%\">\n";
  echo "<tr><td><b>".$t->translate("No").".</b></td>\n";
  echo "<td><b>".$t->translate("Application")."</b></td>\n";
  echo "<td><b>".$t->translate("Subject")."</b></td>\n";
  echo "<td><b>".$t->translate("Author")."</b></td>\n";
  echo "<td><b>".$t->translate("Posted on")."</b></td>\n";
  echo "<td>&nbsp;</td>\n";
  echo "<td>&nbsp;</td></tr>\n";

  $i = 1;
  while($db->next_record()) {
    echo "<tr><td>$i</td>\n";
    echo "<td><a href=\"".htmlentities($sess->url("appbyid.php?id=".$db->f("appid"))."")."\">".$db->f("name")."</a></td>\n";
    echo "<td>".$db->f("subject_cmt")."</td>\n";
    echo "<td>".$db->f("user_cmt")."</td>\n";
    $timestamp = mktimestamp($db->f("creation_cmt"));
    echo "<td>".timestr_short($timestamp)."</td>\n";

    echo "<td><form action=\"".$sess->url("comment.php")."\" method=\"POST\">\n";
    echo "<input type=\"hidden\" name=\"modify\" value=\"1\">\n";
    echo "<input type=\"hidden\" name=\"delete\" value=\"0\">\n";
    echo "<input type=\"hidden\" name=\"modification\" value=\"".$db->f("creation_cmt")."\">\n";    
    echo "<input type=\"hidden\" name=\"id\" value=\"".$db->f("appid")."\">\n";
    echo "<input type=\"submit\"value=\"".$t->translate("Modify")."\">\n";
    echo "</form></td>\n";

    echo "<td><form action=\"".$sess->url("comment.php")."\" method=\"POST\">\n";
    echo "<input type=\"hidden\" name=\"delete\" value=\"1\">\n";
    echo "<input type=\"hidden\" name=\"modify\" value=\"0\">\n";
    echo "<input type=\"hidden\" name=\"modification\" value=\"".$db->f("creation_cmt")."\">\n";
    echo "<input type=\"hidden\" name=\"id\" value=\"".$db->f("appid")."\">\n";
    echo "<input type=\"submit\"value=\"".$t->translate("Delete")."\">\n";
    echo "</form></td>\n";
    echo "</tr>\n";
    $i++;
  }
  echo "</table>\n";
  $bx->box_body_end();
  $bx->box_end();

  if ($numiter > 1) {
    $url = "admcomment.php";
    $urlquery = array("by" => "$by","find" => "$find");
    show_more ($iter,$numiter,$url,$urlquery);
  }
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
