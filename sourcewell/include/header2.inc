<?php

######################################################################
# SourceWell 2
# ================================================
#
# This file contains the common header
#
# Copyright (c) 2001 by
#                Gregorio Robles (grex@scouts-es.org) and
#                Lutz Henckel (lutz.henckel@fokus.gmd.de)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#

# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

if (!isset($login)) {
	page_open(array("sess" => "SourceWell_Session"));
	if (isset($auth) && !empty($auth->auth["perm"])) {
 		 page_close();
 		 page_open(array("sess" => "SourceWell_Session",
  		                 "auth" => "SourceWell_Auth",
 	  	                 "perm" => "SourceWell_Perm"));
	}
}

// Disabling cache
header("Cache-Control: no-cache, must-revalidate");     // HTTP/1.1
header("Pragma: no-cache"); 				// HTTP/1.0

require("config2.inc");
if (!isset($login)) include("sql2.inc");
require("lib2.inc");
require("box2.inc");
require("html2.inc");
require("security2.inc");
require("translation.inc");
require("lang.inc");

$t = new translation($la);
$db = new DB_SourceWell;
$be = new box("error","75%");
?>

<!doctype html public "-//w3c//dtd html 4.0 transitional//en">
<html>
<head>
   <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
   <meta http-equiv="expires" content="0">
   <title><?php echo $sys_name;?> - <?php echo _($sys_title);?></title>
<link rel="stylesheet" type="text/css" href="berlios.css">

<SCRIPT LANGUAGE="JavaScript"> function addNetscapePanel() { 
      if ((typeof window.sidebar == "object") && (typeof window.sidebar.addPanel == "function")) 
      { 
         window.sidebar.addPanel ("SourceWell", 
         "<?php echo $sys_url."sitebar.php3"?>",""); 
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
<body bgcolor="<?php echo $th_body_bgcolor;?>" topmargin="0" bottommargin="0" leftmargin="0" rightmargin="0" marginheight="0" marginwidth="0">

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

<td WIDTH="10"><img SRC="images/blank.gif" BORDER=0 height=1 width=10></td>

<td WIDTH="99%">
<p>&nbsp;
