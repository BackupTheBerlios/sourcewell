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
# This is the Netscape 6 sitebar of the system
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
// Disabling cache
header("Cache-Control: no-cache, must-revalidate");     // HTTP/1.1
header("Pragma: no-cache"); 				// HTTP/1.0

require "config.inc";
require "lib.inc";
require("translation.inc");
require("lang.inc");
require("box.inc");
$t = new translation($la);
$db = new DB_SourceWell;

$bx = new box("95%",$th_box_frame_color,0,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
?>

<!doctype html public "-//w3c//dtd html 4.0 transitional//en">
<html>
<head>
   <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
   <meta http-equiv="expires" content="0">
   <meta http-equiv="Refresh" content="1200; URL=<?php echo $sys_url."sitebar.php3"?>">
   <title><?php echo $sys_name;?> - <?php echo $t->translate($sys_title);?></title>
<link rel="stylesheet" type="text/css" href="berlios.css">
</head>
<body bgcolor="<?php echo $th_body_bgcolor;?>" topmargin="0" bottommargin="0" leftmargin="0" rightmargin="0" marginheight="0" marginwidth="0">

<!-- content -->

<p>&nbsp;
<?php
$bx->box_begin();
$bx->box_title($t->translate("Recent Apps"));
$db->query("SELECT * FROM software,counter,auth_user WHERE software.appid=counter.appid AND software.user=auth_user.username AND software.status='A' ORDER BY software.modification DESC limit 20");
$i=0;
$bx->box_body_begin();
while($db->next_record()) {
  echo "<li><a href=\"".$sys_url."appbyid.php3?id=".$db->f("appid")."\" target=\"_content\">".$db->f("name")."</a> ".$db->f("version")."</li>\n";
  $i++;
}
$bx->box_body_end();
$bx->box_end();

@page_close();
?>
