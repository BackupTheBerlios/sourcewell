<?php
/* vim: set expandtab tabstop=4 shiftwidth=4: */
// +----------------------------------------------------------------------+
// |        SourceWell 2 - The GPL Software Announcement System           |
// +----------------------------------------------------------------------+
// |      Copyright (c) 2001-2002 BerliOS, FOKUS Fraunhofer Institut      |
// +----------------------------------------------------------------------+
// | This program is free software. You can redistribute it and/or modify |
// | it under the terms of the GNU General Public License as published by |
// | the Free Software Foundation; either version 2 or later of the GPL.  |
// +----------------------------------------------------------------------+
// | Authors: Gregorio Robles <grex@scouts-es.org>                        |
// +----------------------------------------------------------------------+
//
// $Id: header.inc,v 1.9 2002/05/09 17:07:03 grex Exp $

/**
 * TODO: global explanation of this file
 * structure and possibilities
 * say that there are partial explanations along this file
 */


/* PHPLib authentication object */
/* @see PHPLib */

global $auth;

/* Visual configuration parameters
   Have a look at config.inc for further details */

global $config_meta_author;
global $config_meta_description;
global $config_meta_keywords;
global $config_sys_name;
global $config_sys_title;
global $config_sys_logo_image;
global $config_sys_logo_height;
global $config_sys_logo_width;
global $config_sys_logo_alt
global $config_navstrip_bgcolor;
global $config_navstrip_font_color;
global $config_nav_font_color;
global $config_nav_bgcolor;
global $config_TopStripArray;
global $config_sys_url_image;
global $config_org_url;
global $config_org_logo_image;
global $config_org_logo_alt;
global $config_org_logo_height;
global $config_org_logo_width;
global $config_body_bgcolor;
global $config_nav_bar_array;
global $config_adm_bar_array;
global $config_la_array;
global $config_addNetscapePanel;

/**
 * Todo: explanation
 */

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

<?php
/**
 * TODO: explanation
 */
?>

<!-- top strip -->
<table border="0" cellspacing="0" cellpadding="2" width="100%" bgcolor="<?php echo $config_navstrip_bgcolor;?>">
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
    echo "<font color=\"".$config_nav_bgcolor."\"><b>"._("Not Logged in")."</b></font>";
}
?>
    </td>
  </tr>
</table>
<!-- end top strip -->

<?php
/**
 * TODO: explanation
 */
?>

<!-- top title -->
<table border="0" cellspacing="0" cellpadding="0" width="100%">
  <tr valign="top" bgcolor="<?php echo $config_nav_bgcolor;?>">
    <td bgcolor="#FFFFFF">
      <a href="<?php echo $config_sys_url_image;?>">
      <img src="<?php echo $config_sys_logo_image;?>" border="0" 
       height="<?php echo $config_sys_logo_height;?>"
       width="<?php echo $config_sys_logo_width;?>"
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
          This site is being beta tested, please send any and all
        <a href="mailto:sourcewell-support@lists.berlios.de?subject=SourceWell Beta Feedback&cc=grex@scouts-es.org">feedback</a>!
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

<?php
/**
 * TODO: explanation
 */
?>

<!-- navigation bar -->
<table border="0" cellspacing="0" cellpadding="0" width="100%" >
  <tr valign="top" bgcolor="<?php echo $config_body_bgcolor;?>">
    <td bgcolor="<?php echo $config_nav_bgcolor;?>">

<!-- BerliOS menu -->
<table border="0" cellspacing="0" cellpadding="3" width="100%">
  <tr bgcolor="<?php echo $config_navstrip_bgcolor;?>">
    <td align="center">
      <span class="titlebar"><font color="<?php echo $config_navstrip_font_color;?>"><?php echo $config_sys_name?></font></span>
    </td>
  </tr>

  <tr align="right" bgcolor="<?php echo $config_nav_bgcolor;?>">
    <td>
<?php

while (list(, $value) = each($config_nav_bar_array)) {
    // Polimorfism
    print $value->render();
}

print "    </td>\n";
print "  </tr>\n";
print "</table>\n";
print "<!-- end BerliOS menu -->\n";

/* Administration Menu */

$links = '';
while (list(, $value) = each($config_adm_bar_array)) {
    // Polimorfism
    $links .= $value->render();
    if ($links) {
        print "<!-- Admin menu -->\n";
	print "<table border=\"0\" cellspacing=\"0\" cellpadding=\"3\" width=\"100%\">\n";
	print "  <tr bgcolor=\"<?php echo $config_navstrip_bgcolor;?>\">\n";
	print "    <td align=\"center\"><img src=\"http://www.berlios.de/images/blank.gif\" height=\"1\" width=\"135\" border=\"0\" alt=\"\"><br>\n";
	print "      <span class=\"titlebar\"><font color=\"$config_navstrip_font_color\">"._('Administration')."</font></span></td>\n";
	print "  </tr>\n";
        print "  <tr ALIGN=RIGHT bgcolor=\"$config_nav_bgcolor\">\n";
        print "    <td>\n";
        print $links;
        print "    </td>\n";
	print "  </tr>\n";
	print "</table>\n";
	print "<!-- end Admin menu -->\n";
    }
}
?>

<!-- Search menu -->
<table border=0 cellspacing=0 cellpadding=3 width="100%">
  <tr bgcolor="<?php echo $config_navstrip_bgcolor;?>">
    <td align="center">
      <img src="http://www.berlios.de/images/blank.gif" height="1" width="135" border=0 alt="">
      <br>
      <span class="titlebar"><font color="<?php echo $config_navstrip_font_color;?>"><?php echo _("Search"); ?></font></span>
    </td>
  </tr>

  <tr align="right" bgcolor="<?php echo $config_nav_bgcolor;?>">
    <td align="center">
      <p>
<?php
htmlp_form_action('appsearch.php3', '', 'get');
htmlp_form_textField('search', '', $size = 10);
print '<p>';
htmlp_form_submit(_('Search'));
htmlp_form_end();
?>
    </td>
  </tr>
</table>
<!-- end Search menu -->

<!-- Language menu -->
<table border="0" cellspacing="0" cellpadding="3" width="100%">
  <tr bgcolor="<?php echo $config_navstrip_bgcolor;?>">
    <td ALIGN=CENTER><img src="http://www.berlios.de/images/blank.gif" height="1" width="135" border=0><br>
      <span class="titlebar"><font color="<?php echo $config_navstrip_font_color;?>"><?php echo _("Language");?></font></span>
    </td>
  </tr>

  <tr ALIGN=RIGHT bgcolor="<?php echo $config_nav_bgcolor;?>">
    <td align=center>
      <p>
<?php
htmlp_form_action();
while (is_array($HTTP_GET_VARS) 
		&& list($key, $val) = each($HTTP_GET_VARS)) {
	if ($key != "lang" && $key != "go") {
  	    htmlp_form_hidden($key, $val);
	}
}
htmlp_form_select($lang);
while (list(, $ln) = each($config_la_array)) {
    htmlp_form_select_option($ln, $la, _($ln));;
}
htmlp_form_select_end();
print "<p>\n";
htmlp_form_submit(_('Go'));
htmlp_form_end();
?>
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
  <td width="10">
    <img src="images/blank.gif" border="0" height="1" width="10" alt="">
  </td>
  <td width="99%">
    <p>&nbsp;

<!--_____________________________________________________________________-->
<!--_________________________Starting Content____________________________-->
<!--_____________________________________________________________________-->
