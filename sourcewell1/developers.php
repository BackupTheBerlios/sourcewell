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
# This file lists the developers of the apps in alphabetical order
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
if (($config_perm_developer != "all") && (!isset($perm) || !$perm->have_perm($config_perm_developer))) {
  $be->box_full($t->translate("Error"), $t->translate("Access denied"));
} else {

  if (!isset($by) || empty($by)) {
    $by = "";
  }

  $alphabet = array ("A","B","C","D","E","F","G","H","I","J","K","L",
		"M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z");
  $msg = "[ ";

  while (list(, $ltr) = each($alphabet)) {
    $msg .= "<a href=\"".$sess->self_url().$sess->add_query(array("by" => $ltr."%"))."\">$ltr</a>&nbsp;| ";
  }

  $msg .= "<a href=\"".$sess->self_url().$sess->add_query(array("by" => "%"))."\">".$t->translate("All")."</a>&nbsp;| ";
  $msg .= "<a href=\"".$sess->self_url().$sess->add_query(array("by" => ""))."\">".$t->translate("Unknown")."</a>&nbsp;]";

  $bs->box_strip($msg);
  $db->query("SELECT DISTINCT developer,email FROM software WHERE developer LIKE '$by' ORDER BY developer ASC");
  $bx->box_begin();
  $bx->box_title($t->translate("Authors"));
  $bx->box_body_begin();		
?>
<table border=0 align=center cellspacing=1 cellpadding=1 width=100%>
<?php
  echo "<tr><td><b>".$t->translate("No").".</b></td><td><b>#&nbsp;".$t->translate("Apps")."</b></td><td><b>".$t->translate("Names")."</b></td><td><b>".$t->translate("E-Mail")."</b></td></tr>\n";
  $i = 1;
  while($db->next_record()) {
    $developer = addslashes($db->f("developer"));
    $email = $db->f("email");
    $db2 = new DB_SourceWell;
    $db2->query("SELECT COUNT(*) FROM software WHERE developer='$developer' AND email='$email' AND status='A'");
    $db2->next_record();
    if ($db2->f("COUNT(*)")) {
      $num = "[".sprintf("%03d",$db2->f("COUNT(*)"))."]";
      echo "<tr><td>".sprintf("%d",$i)."</td>\n";
      if (empty($developer)) {
	echo "<td><a href=\"".$sess->url("appbydev.php").$sess->add_query(array("developer" => "", "email" => "$email"))."\">$num</a></td>\n";
	echo "<td>".$t->translate("Unknown")."</td>\n";
      } else {
	echo "<td><a href=\"".$sess->url("appbydev.php").$sess->add_query(array("developer" => $db->f("developer"), "email" => "$email"))."\">$num</a></td>\n";
        echo "<td>".$db->f("developer")."</td>\n";
      }
      if (!empty($email)) {
        echo "<td>&lt;<a href=\"mailto:".$email."\">".ereg_replace("@"," at ",htmlentities($email))."</a>&gt;</td>\n";
      } else {
        echo "<td>&nbsp;</td>\n";
      }
      echo "</tr>\n";
      $i++;
    }
  }
  echo "</table>\n";
  $bx->box_body_end();
  $bx->box_end();
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
qpage_close();
?>
