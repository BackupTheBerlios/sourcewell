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
// $Id: start.inc,v 1.28 2002/05/07 22:01:17 grex Exp $

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
<a href="<?php echo $config_sys_url_title;?>">
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
<td><a href="<?php $sess->purl("index.php3") ?>" class="menus"><?php echo _("Recent Apps"); ?></a>
<br><a href="<?php $sess->purl("faq.php3") ?>" class="menus"><?php echo _("Q&amp;A"); ?></a>

<br><br>

<?php
if (isset($auth) && !empty($auth->auth["perm"]) && !($logout) ) {
  if ($perm->have_perm("user") || $perm->have_perm("user_pending") || $perm->have_perm("editor") || $perm->have_perm("admin") || $perm->have_perm("anonymous")) {
?>
<a href="<?php $sess->purl("logout.php3") ?>" class="menus"><?php echo _("Logout"); ?></a>
<?php
  }
} else {
?>
<a href="<?php $sess->purl("login.php3") ?>" class="menus"><?php echo _("Login"); ?></a>
<?php
}
?>
<br><a href="<?php $sess->purl("register.php3") ?>" class="menus"><?php echo _("New User"); ?></a>
<br><a href="<?php $sess->purl("remind.php3") ?>" class="menus"><?php echo _("Forgot Password"); ?></a>
<?php
if (isset($auth) && !empty($auth->auth["perm"]) && !($logout)) {
	if (($perm->have_perm("user") || $perm->have_perm("user_pending") || $perm->have_perm("editor") || $perm->have_perm("admin")) && !($perm->have_perm("anonymous"))) {
?>
<br><a href="<?php $sess->purl("chguser.php3") ?>" class="menus"><?php echo _("Change User"); ?></a>
<?php
	}
}

if (($config_perm_users == "all") || (isset($perm) && $perm->have_perm($config_perm_users))  && !($logout)) {
?>
<br><a href="<?php $sess->purl("users.php3") ?>" class="menus"><?php echo _("Users"); ?></a>
<?php
}
?>
<br>
<br><a href="<?php $sess->purl("categories.php3") ?>" class="menus"><?php echo _("Apps Index"); ?></a>
<?php

echo "<br><a href=\"".$sess->url("app_edi.php3")."\" class=\"menus\">"._("New App")."</a>\n";
echo "<br><a href=\"".$sess->url("appbyuser.php3")."\" class=\"menus\">"._("Update Apps")."</a>\n";

if (($config_perm_apppend == "all") || (isset($perm) && $perm->have_perm($config_perm_apppend))  && !($logout)) {
  $count;
  $db->query("SELECT COUNT(*) FROM software WHERE status='P'");
  $db->next_record();
  $count = $db->f("COUNT(*)");
  $db->query("SELECT COUNT(*) FROM temp WHERE status='P'");
  $db->next_record();
  $count += $db->f("COUNT(*)");
  echo "<br><a href=\"".$sess->url("admapp.php3")."\" class=\"menus\">"._("Pending Apps")." [".$count."]</a>\n";
}

if (($config_perm_appdom == "all") || (isset($perm) && $perm->have_perm($config_perm_appdom))  && !($logout)) {
  $count = 0;
  $db->query("SELECT COUNT(*) FROM software WHERE status='D'");
  $db->next_record();
  $count = $db->f("COUNT(*)");
  $db->query("SELECT COUNT(*) FROM temp WHERE status='D'");
  $db->next_record();
  $count += $db->f("COUNT(*)");
  echo "<br><a href=\"".$sess->url("admapp.php3?status=D")."\" class=\"menus\">"._("Deleted Apps")." [".$count."]</a>\n";
  $count = 0;
  $db->query("SELECT COUNT(*) FROM software WHERE status='M'");
  $db->next_record();
  $count = $db->f("COUNT(*)");
  $db->query("SELECT COUNT(*) FROM temp WHERE status='M'");
  $db->next_record();
  $count += $db->f("COUNT(*)");
  echo "<br><a href=\"".$sess->url("admapp.php3?status=M")."\" class=\"menus\">"._("Modified Apps")." [".$count."]</a>\n";
}

if (($config_perm_developer == "all") || (isset($perm) && $perm->have_perm($config_perm_developer))  && !($logout)) {
  echo "<br><a href=\"".$sess->url("developers.php3")."\" class=\"menus\">"._("Authors")."</a>\n";
}
?>
<br><a href="<?php $sess->purl("licenses.php3"); ?>" class="menus"><?php echo _("Licenses"); ?></a>
<br>
<?php
if ($ml_list) {
  echo "<br><a href=\"".$sess->url("newsletter.php3")."\" class=\"menus\">"._("Newsletter")."</a>\n";
}
?>
<br><a href="<?php $sess->purl("backend.php3"); ?>" class="menus"><?php echo _("Backend"); ?></a>
<br><a href="<?php $sess->purl("stats.php3?option=general"); ?>" class="menus"><?php echo _("Statistics"); ?></a>
</td>
</tr>
</table>
<!-- end BerliOS menu -->
<!-- Admin menu -->
<?php

if (
    (($config_perm_admuser == "all") ||
       ($config_perm_admlicens == "all") ||
       ($config_perm_admcomment == "all") ||
       ($config_perm_admsec == "all") ||
       ($config_perm_admcat == "all") ||
       ($config_perm_nladm == "all") ||
       ($config_perm_admfaq == "all") ||
       ($config_perm_configure == "all"))
  || (isset($perm) &&
       (($perm->have_perm($config_perm_admuser)) ||
        ($perm->have_perm($config_perm_admlicens)) ||
        ($perm->have_perm($config_perm_admcomment)) ||
        ($perm->have_perm($config_perm_admsec)) ||
        ($perm->have_perm($config_perm_admcat)) ||
        ($perm->have_perm($config_perm_nladm)) ||
        ($perm->have_perm($config_perm_admfaq)) ||
        ($perm->have_perm($config_perm_configure) ) ))
  && !($logout)) {

?>
<table border=0 cellspacing=0 cellpadding=3 width="100%">
<tr bgcolor="<?php echo $config_navstrip_bgcolor;?>">
<td ALIGN=CENTER><img src="http://www.berlios.de/images/blank.gif" height="1" width="135" border=0><br>
<span class="titlebar"><font color="<?php echo $config_navstrip_font_color;?>"><?php echo _("Administration"); ?></font></span></td>
</tr>

<tr ALIGN=RIGHT bgcolor="<?php echo $config_nav_bgcolor;?>">
<td>
<?php

  if (($config_perm_admuser == "all") || (isset($perm) && $perm->have_perm($config_perm_admuser))  && !($logout)) {
    $db->query("SELECT COUNT(*) FROM auconfig_user");
    $db->next_record();
    echo "<a href=\"".$sess->url("admuser.php3")."\" class=\"menus\">"._("Users")." [".$db->f("COUNT(*)")."]</a>\n";
  }

  if (($config_perm_admsec == "all") || (isset($perm) && $perm->have_perm($config_perm_admsec))  && !($logout)) {
    $db->query("SELECT DISTINCT section FROM categories GROUP BY section");
    $db->next_record();
    echo "<br><a href=\"".$sess->url("admsec.php3")."\" class=\"menus\">"._("Sections")." [".$db->num_rows()."]</a>\n";
  }

  if (($config_perm_admcat == "all") || (isset($perm) && $perm->have_perm($config_perm_admcat))  && !($logout)) {
    $db->query("SELECT COUNT(*) FROM categories");
    $db->next_record();
    echo "<br><a href=\"".$sess->url("admcat.php3")."\" class=\"menus\">"._("Categories")." [".$db->f("COUNT(*)")."]</a>\n";
  }

  if (($config_perm_admlicens == "all") || (isset($perm) && $perm->have_perm($config_perm_admlicens))  && !($logout)) {
    $db->query("SELECT COUNT(*) FROM licenses");
    $db->next_record();
    echo "<br><a href=\"".$sess->url("admlicens.php3")."\" class=\"menus\">"._("Licenses")." [".$db->f("COUNT(*)")."]</a>\n";
  }

  if (($config_perm_admcomment == "all") || (isset($perm) && $perm->have_perm($config_perm_admcomment))  && !($logout)) {
    $db->query("SELECT COUNT(*) FROM comments");
    $db->next_record();
    echo "<br><a href=\"".$sess->url("admcomment.php3")."\" class=\"menus\">"._("Comments")." [".$db->f("COUNT(*)")."]</a>\n";
  }

  if (($config_perm_admfaq == "all") || (isset($perm) && $perm->have_perm($config_perm_admfaq))  && !($logout)) {
    $db->query("SELECT COUNT(*) FROM faq WHERE language='$la'");
    $db->next_record();
    echo "<br><a href=\"".$sess->url("admfaq.php3")."\" class=\"menus\">"._("Q&amp;A")." [".$db->f("COUNT(*)")."]</a>\n";
  }

  if (($config_perm_admdate == "all") || (isset($perm) && $perm->have_perm($config_perm_admdate))  && !($logout)) {
    $db->query("SELECT COUNT(*) FROM history,software WHERE software.modification!=history.creation_his AND history.version_his=software.version AND history.appid=software.appid");
    $db->next_record();
    echo "<br><a href=\"".$sess->url("admdate.php3")."\" class=\"menus\">"._("Check Date")." [".$db->f("COUNT(*)")."]</a>\n";
  }

  if (($config_perm_nladm == "all") || (isset($perm) && $perm->have_perm($config_perm_nladm))  && !($logout) && ($ml_list)) {
				// Daily Newsletter
    $where = "DATE_FORMAT(software.modification,'%Y-%m-%d')=\"".date("Y-m-d")."\"";
    $db->query("SELECT COUNT(*) FROM software WHERE $where AND status='A'"); 
    $db->next_record();
    echo "<br><a href=\"".$sess->url("nladm.php3?period=daily")."\" class=\"menus\">"._("Daily Newsletter")." [".$db->f("COUNT(*)")."]</a>\n";
				// Weekly Newsletter
    $lastday = time() - 7 * 24 * 60 * 60;
    $where = "DATE_FORMAT(software.modification,'%Y-%m-%d')<=\"".date("Y-m-d")."\" AND DATE_FORMAT(software.modification,'%Y-%m-%d')>\"".date("Y-m-d",$lastday)."\"";
    $db->query("SELECT COUNT(*) FROM software WHERE $where AND status='A'"); 
    $db->next_record();
    echo "<br><a href=\"".$sess->url("nladm.php3?period=weekly")."\" class=\"menus\">"._("Weekly Newsletter")." [".$db->f("COUNT(*)")."]</a>\n";
  }

  if (($config_perm_configure == "all") || (isset($perm) && $perm->have_perm($config_perm_configure))  && !($logout)) {
    echo "<br><a href=\"".$sess->url("configure.php3")."\" class=\"menus\">"._("Configure")."</a>\n";
  }

?>
</td>
</tr>
</table>
<?php
}
?>
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
