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
# This file indexes the sections and categories available in our system
# It also shows the number of apps in each one
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

require("header.inc");

$bx = new box("95%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
$db = new DB_SourceWell;

$columns = "section";
$tables = "categories";
if (!$result = mysql_db_query($db_name,"SELECT DISTINCT $columns FROM $tables")) {
  mysql_die();
} else {
?>
<table border=0 align=center cellspacing=0 cellpadding=0 width=100%>
<tr><td width=40% valign=top>
<?php
  $bx->box_begin();
  $bx->box_title($t->translate("Sections"));
  $bx->box_body_begin();
  while($row = mysql_fetch_array($result)) {
    $columns = "COUNT(*)";
    $tables = "software";
    $where = "section='".$row["section"]."' AND status='A'";
    $num = "";
    if ($resultn = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where")) {
      $rown = mysql_fetch_row($resultn);
      $num = "[".sprintf("%03d",$rown[0])."]";
      mysql_free_result($resultn);
    }
    echo "$num <a href=\"categories.php3?section=".rawurlencode($row["section"])."\">".$row["section"]."<br></a>\n";
  }
  $bx->box_body_end();
  $bx->box_end();	
  mysql_free_result($result);
}
?>

</td>
<td width=60% valign=top>

<?php
if (isset($section)) {
  $columns = "category";
  $tables = "categories";
  $where = "section = '$section'";
  $order = "category ASC";
  if (!$result = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where ORDER BY $order")) {
    mysql_die();
  } else {
    $bx->box_begin();
    $bx->box_title($t->translate("Categories"));
    $bx->box_body_begin();
    while($row = mysql_fetch_array($result)) {
      $columns = "COUNT(*)";
      $tables = "software";
      $where = "section='$section' AND category='".$row["category"]."' AND status='A'";
      $num = "";
      if ($resultn = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where")) {
        $rown = mysql_fetch_row($resultn);
        $num = "[".sprintf("%03d",$rown[0])."]";
        mysql_free_result($resultn);
      }
      echo "$num <a href=\"appbycat.php3?section=".$section."&category=".rawurlencode($row["category"])."\">".$row["category"]."</a><br>\n";
    }

    $bx->box_body_end();
    $bx->box_end();
    mysql_free_result($result);
  }
}
?>
</td></tr>
</table>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>
