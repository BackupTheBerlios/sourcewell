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

page_open(array("sess" => "SourceWell_Session"));
if (isset($auth) && !empty($auth->auth["perm"])) {
  page_close();
  page_open(array("sess" => "SourceWell_Session",
                  "auth" => "SourceWell_Auth",
                  "perm" => "SourceWell_Perm"));
}

require "header.inc";

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
$bs = new box("100%",$th_strip_frame_color,$th_strip_frame_width,$th_strip_title_bgcolor,$th_strip_title_font_color,$th_strip_title_align,$th_strip_body_bgcolor,$th_strip_body_font_color,$th_strip_body_align);
?>

<!-- content -->
<?php
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

$msg .= "<a href=\"".basename($PHP_SELF)."?by=%\">".$t->translate("All")."</a>&nbsp;| ";
$msg .= "<a href=\"".basename($PHP_SELF)."\">".$t->translate("Unknown")."</a>&nbsp;]";

$bs->box_strip($msg);
$columns = "developer,email";
$tables = "software";
$where = "developer LIKE '$by'";
$order = "developer ASC";
if (!$result = mysql_db_query($db_name,"SELECT DISTINCT $columns FROM $tables WHERE $where ORDER BY $order")) {
  mysql_die();
} else {
  $bx->box_begin();
  $bx->box_title($t->translate("Authors"));
  $bx->box_body_begin();		
?>
<table border=0 align=center cellspacing=1 cellpadding=1 width=100%>
<?php
  echo "<tr><td><b>".$t->translate("No").".</b></td><td><b>#&nbsp;".$t->translate("Apps")."</b></td><td><b>".$t->translate("Names")."</b></td><td><b>".$t->translate("E-Mail")."</b></td></tr>\n";
  $i = 1;
  while($row = mysql_fetch_array($result)) {
    $columns = "COUNT(*)";
    $tables = "software";
    $where = "developer=\"".$row["developer"]."\" AND status=\"A\"";
    $num = "";
    if ($resultn = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where")) {
      $rown = mysql_fetch_row($resultn);
      if ($rown[0] > 0) {
        $num = "[".sprintf("%03d",$rown[0])."]";
        mysql_free_result($resultn);
	echo "<tr><td>".sprintf("%d",$i)."</td>\n";
	if (empty($row["developer"])) {
	  echo "<td><a href=\"appbydev.php3?developer=\">$num</a></td>\n";
	  echo "<td>".$t->translate("Unknown")."</td>\n";
	  echo "<td>&nbsp;</td>\n";
	} else {
	  echo "<td><a href=\"appbydev.php3?developer=".rawurlencode($row["developer"])."\">$num</a></td>\n";
	  echo "<td>".$row["developer"]."</td>\n";
	  if (!empty($row["email"])) {
	    echo "<td>&lt;<a href=\"mailto:".$row["email"]."\">".ereg_replace("@"," at ",htmlentities($row["email"]))."</a>&gt;</td>\n";
	  } else {
	    echo "<td>&nbsp;</td>\n";
	  }
	  echo "</tr>\n";
	}
	$i++;
      }
    }
  }
  echo "</table>\n";
  $bx->box_body_end();
  $bx->box_end();
  mysql_free_result($result);
}
?>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>
