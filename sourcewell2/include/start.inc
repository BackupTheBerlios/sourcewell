<?php
/* vim: set expandtab tabstop=4 shiftwidth=4: */
// +----------------------------------------------------------------------+
// |        SourceWell 2 - The GPL Software Announcement System           |
// +----------------------------------------------------------------------+
// |      Copyright (c) 2001-2002 BerliOS, FOKUS Fraunhofer Institut      |
// +----------------------------------------------------------------------+
// | This program is free software. You can redistribute it and/or modify |
// | it under the terms of the GNU General Public License as published by |
// | the Free Software Foundation; either version 2 or later of the GPL.  |
// +----------------------------------------------------------------------+
// | Authors: Gregorio Robles <grex@scouts-es.org>                        |
// |          Lutz Henckel <lutz.henckel@fokus.fhg.de>                    |
// |          Carlos Martín Ugalde <carlos@scouts-es.org>                 |
// +----------------------------------------------------------------------+
//
// $Id: start.inc,v 1.32 2002/05/09 14:19:02 grex Exp $

if (!isset($login)) {
    page_open(array('sess' => 'SourceWell_Session'));
    if (isset($auth) && !empty($auth->auth['perm'])) {
 	    page_close();
 	    page_open(array('sess' => 'SourceWell_Session',
  	                    'auth' => 'SourceWell_Auth',
	                    'perm' => 'SourceWell_Perm'));
    } elseif (isset($auth)) {
        $auth->logout();
    } else {
        /* TODO */
    }
}

// Disabling cache
header('Cache-Control: no-cache, must-revalidate');     // HTTP/1.1
header('Pragma: no-cache'); 				// HTTP/1.0

$_INC_PATH = '/home/groups/sourcewell/htdocs/sourcewell2/include/';

require($_INC_PATH.'config.inc');
config_inc('lib');
config_inc('html');
config_inc('Table');

//setlocale('LC_TIME', 'es_ES');
//config_inc('Lang');
//config_inc('Translation');
//$t = new Translation($la);
//$$config_database_variable = new DB_SourceWell;

$db = new DB_SourceWell;

$table = new Table();
$table_error = new Table('error', '80%');

?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
   <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
   <meta http-equiv="expires" content="0">
   <meta name="Author" content="<?php echo $config_meta_author;?>">
   <meta name="Description" content="<?php echo $config_meta_description;?>">
   <meta name="KeyWords" content="<?php echo $config_meta_keywords;?>">
   <title><?php echo $config_sys_name;?> - <?php echo _($config_sys_title);?></title>
   <link rel="stylesheet" type="text/css" href="berlios.css">
   <link rel="shortcut icon" href="berlios.ico">
</head>
<body bgcolor="<?php echo $th_body_bgcolor;?>">

<!-- top strip -->
<table border="0" cellspacing="0" cellpadding="2" width="100%" 
       bgcolor="<?php echo $config_navstrip_bgcolor;?>">
<tr>
<td width="45%"><span class=maintitlebar>
<?php
$i = 0;
while (list($title, $url) = each($config_TopStripArray)) {
	if ($i > 0)
		echo "\n | ";
	echo "<b><a href=\"$url\" class=\"maintitlebar\">"._("$title")."</a></b>";
	$i++;
};
echo "\n</span></td><td width=\"55%\" align=\"right\">\n";
if (isset($auth) && !empty($auth->auth["perm"])  && !($logout)) {
	echo "<font color=\"".$config_nav_bgcolor."\">"._("Logged in")." <b>".$auth->auth["uname"]."</b> (<b>".$auth->auth["perm"]."</b>) / "._("Expires")." <b>".timestr_short($auth->auth["exp"])."</b></font>";
} else {
	echo "<font color=\"".$config_nav_bgcolor."\"><b>"._("Not Logged in")."</b><font>";
}
?>

</td>
</tr>

</table>
<!-- end top strip -->

<!-- top title -->

<table border="0" cellspacing="0" cellpadding="0" width="100%">

<tr valign="top" bgcolor="<?php echo $config_nav_bgcolor;?>">
<td bgcolor="#FFFFFF">
<a href="<?php echo $config_sys_url_image;?>">
<img src="<?php echo $config_sys_logo_image;?>" border="0" 
height="<?php echo $config_sys_logo_height;?>" width="<?php echo $config_sys_logo_width;?>"
vspace="5" hspace="5" alt="<?php echo $config_sys_logo_alt;?>"></a>
</td>

<td width="10">
<img src="images/blank.gif" border="0" height="1" width="10" alt="">
</td>

<td align="left" valign="middle" > <!-- removed att: width="99%" -->
<p align="left">
<font color="<?php echo $config_nav_font_color;?>">
<b><font size="+1"><?php echo $config_sys_name;?></font></b>
<br><?php echo _($config_sys_title);?></font></p>
</td>

<!-- beta string -->
<td align="center" valign="middle">
<center>
<font size="+2" color="red">ALPHA ALPHA</font><br>
<?php echo _("This site is being beta tested"); ?>, 
<?php echo _("please send any and all"); ?>
 <a href="mailto:sourcewell-support@lists.berlios.de?subject=SourceWell Beta Feedback&cc=grex@scouts-es.org"
><?php echo _("feedback"); ?></a>!
</center>
</td>

<!-- logo at right -->
<td valign="middle">
<a href="<?php echo $config_org_url;?>" target="_blank">
<img src="<?php echo $config_org_logo_image;?>" alt="<?php echo $config_org_logo_alt;?>" 
hspace="10" border="0" height="<?php echo $config_org_logo_height;?>" 
width="<?php echo $config_org_logo_width;?>" align="RIGHT"></a>
</td>
</tr>
<!-- end logo at right -->

<tr>
<td colspan="5" bgcolor="<?php echo $config_navstrip_bgcolor;?>">
<img src="images/blank.gif" height="1" width="1" alt="">
</td>
</tr>

</table>

<!-- end top title -->

<table border=0 cellspacing=0 cellpadding=0 width="100%" >
<tr valign="top" bgcolor="<?php echo $config_body_bgcolor;?>">
<td bgcolor="<?php echo $config_nav_bgcolor;?>">

<!-- BerliOS menu -->
<table border=0 cellspacing=0 cellpadding=3 width="100%">
<tr bgcolor="<?php echo $config_navstrip_bgcolor;?>">
<td ALIGN=CENTER>
<span class="titlebar"><font color="<?php echo $config_navstrip_font_color;?>"><?php echo $config_sys_name?></font></span></td>
</tr>

<tr ALIGN=RIGHT bgcolor="<?php echo $config_nav_bgcolor;?>">
<?php

while (list(, $value) = each($nav_bar_array)) {
    // Polimorfism
    $value->render();
}
?>

</td>
</tr>
</table>
<!-- end BerliOS menu -->
<!-- Admin menu -->

<table border=0 cellspacing=0 cellpadding=3 width="100%">
<tr bgcolor="<?php echo $config_navstrip_bgcolor;?>">
<td ALIGN=CENTER><img src="http://www.berlios.de/images/blank.gif" height="1" width="135" border=0><br>
<span class="titlebar"><font color="<?php echo $config_navstrip_font_color;?>"><?php echo _("Administration"); ?></font></span></td>
</tr>

<tr ALIGN=RIGHT bgcolor="<?php echo $config_nav_bgcolor;?>">
<td>
<?php

while (list(, $value) = each($adm_bar_array)) {
    // Polimorfism
    $value->render();
}
?>
</td>
</tr>
</table>
<!-- end Admin menu -->
<!-- Search menu -->
<table border=0 cellspacing=0 cellpadding=3 width="100%">
<tr bgcolor="<?php echo $config_navstrip_bgcolor;?>">
<td ALIGN=CENTER><img src="http://www.berlios.de/images/blank.gif" height="1" width="135" border=0><br>
<span class="titlebar"><font color="<?php echo $config_navstrip_font_color;?>"><?php echo _("Search"); ?></font></span></td>
</tr>

<tr ALIGN=RIGHT bgcolor="<?php echo $config_nav_bgcolor;?>">
<td align=center>
<p>
<form action="<?php $sess->purl("appsearch.php3"); ?>">
<input TYPE="text" SIZE="10" NAME="search" VALUE="">
<?php
echo "<p><input TYPE=\"submit\" NAME=\"Search\" VALUE=\""._("Search")."\">";
?>
</form>
</td>
</tr>
</table>
<!-- end Search menu -->
<!-- Language menu -->
<table border=0 cellspacing=0 cellpadding=3 width="100%">
<tr bgcolor="<?php echo $config_navstrip_bgcolor;?>">
<td ALIGN=CENTER><img src="http://www.berlios.de/images/blank.gif" height="1" width="135" border=0><br>
<span class="titlebar"><font color="<?php echo $config_navstrip_font_color;?>"><?php echo _("Language");?></font></span></td>
</tr>

<tr ALIGN=RIGHT bgcolor="<?php echo $config_nav_bgcolor;?>">
<td align=center>
<p>
<form action="<?php $sess->pself_url()?>">
<?php
while (is_array($HTTP_GET_VARS) 
		&& list($key, $val) = each($HTTP_GET_VARS)) {
	if ($key != "lang" && $key != "go") {
		echo "<input TYPE=\"hidden\" NAME=\"$key\" VALUE=\"$val\">\n";
	}
}
?>
<select name="lang" size=1>
<?php
while (list(, $ln) = each($config_la_array)) {
    if ($la == $ln) {
	$sel = 'selected';
    } else {
	$sel ='';
    }
    echo "<option value=\"$ln\" $sel>"._($ln)."\n";
}
?>
</select>
<?php
echo "<p><input TYPE=\"submit\" name=\"go\" value=\""._("Go")."\">";
?>
</form>
</td>
</tr>
</table>
<?php
if (ereg('Gecko', '$HTTP_USER_AGENT') && $config_addNetscapePanel) {
  include('netscapePanel.ihtml');
}
?>
<!-- end Language menu -->


</td>
<td width="10"><img src="images/blank.gif" border=0 height=1 width=10></td>
<td width="99%">
<p>&nbsp;
