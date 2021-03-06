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
# This file contains the common header
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

// Disabling cache
header("Last-Modified: ".gmdate("D, d M Y H:i:s")." GMT");
header("Expires: ".gmdate("D, d M Y H:i:s")." GMT");
header("Cache-Control: no-cache, must-revalidate");     // HTTP/1.1
header("Pragma: no-cache");                             // HTTP/1.0

require("./include/config.inc");
require("./include/lib.inc");
require("./include/translation.inc");
require("./include/lang.inc");
require("./include/box.inc");
$t = new translation($la);
$db = new DB_SourceWell;
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
   <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
   <meta http-equiv="expires" content="0">
   <title><?php echo $sys_name;?> - <?php echo $t->translate($sys_title);?></title>
<link rel="STYLESHEET" type="text/css" href="style.php">
<link rel="SHORTCUT ICON" href="favicon.ico">

<SCRIPT type="text/javascript"> function addNetscapePanel() { 
      if ((typeof window.sidebar == "object") && (typeof window.sidebar.addPanel == "function")) 
      { 
         window.sidebar.addPanel ("<?php echo $sys_name ?>", 
         "http:<?php echo $sys_url."sitebar.php"?>",""); 
      } 
      else 
      { 
         var rv = window.confirm ("This page is enhanced for use with Netscape 6.  " + "Would you like to upgrade now?"); 
         if (rv) 
            document.location.href = "http://home.netscape.com/download/index.html";
      } 
   } 
//--> </SCRIPT>

</head>
<body bgcolor="<?php echo $th_body_bgcolor;?>">

<?php
require("top_strip.inc");
require("top_title.inc");
?>

<table BORDER=0 CELLSPACING=0 CELLPADDING=0 WIDTH="100%" >
<tr VALIGN=TOP BGCOLOR="<?php echo $th_body_bgcolor;?>">
<td BGCOLOR="<?php echo $th_nav_bgcolor;?>">
<?php
require("menubar.inc");
?>
</td>

<td width="10"><img src="images/blank.gif" border="0" height="1" width="10" alt=""></td>

<td WIDTH="99%">
<br>
<?php
if ( file_exists("./include/adsense.php") ) {
        include("./include/adsense.php");
}
?>
<br>
