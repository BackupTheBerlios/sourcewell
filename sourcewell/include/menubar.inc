<!-- BerliOS menu -->
<table BORDER=0 CELLSPACING=0 CELLPADDING=3 WIDTH="100%">
<tr BGCOLOR="<?php echo $th_navstrip_bgcolor;?>">
<td ALIGN=CENTER>
<span class="titlebar"><font color="<?php echo $th_navstrip_font_color;?>"><?php echo $sys_name?></font></span></td>
</tr>

<tr ALIGN=RIGHT BGCOLOR="<?php echo $th_nav_bgcolor;?>">
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
<?php
/*
// The credits have been moved to the footer
<br><a href="/html" class="menus"><?php echo _("About"); ?></a>
*/
?>
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
<table BORDER=0 CELLSPACING=0 CELLPADDING=3 WIDTH="100%">
<tr BGCOLOR="<?php echo $th_navstrip_bgcolor;?>">
<td ALIGN=CENTER><img SRC="http://www.berlios.de/images/blank.gif" height="1" width="135" border=0><br>
<span class="titlebar"><font color="<?php echo $th_navstrip_font_color;?>"><?php echo _("Administration"); ?></font></span></td>
</tr>

<tr ALIGN=RIGHT BGCOLOR="<?php echo $th_nav_bgcolor;?>">
<td>
<?php

  if (($config_perm_admuser == "all") || (isset($perm) && $perm->have_perm($config_perm_admuser))  && !($logout)) {
    $db->query("SELECT COUNT(*) FROM auth_user");
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
<table BORDER=0 CELLSPACING=0 CELLPADDING=3 WIDTH="100%">
<tr BGCOLOR="<?php echo $th_navstrip_bgcolor;?>">
<td ALIGN=CENTER><img SRC="http://www.berlios.de/images/blank.gif" height="1" width="135" border=0><br>
<span class="titlebar"><font color="<?php echo $th_navstrip_font_color;?>"><?php echo _("Search"); ?></font></span></td>
</tr>

<tr ALIGN=RIGHT BGCOLOR="<?php echo $th_nav_bgcolor;?>">
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
<table BORDER=0 CELLSPACING=0 CELLPADDING=3 WIDTH="100%">
<tr BGCOLOR="<?php echo $th_navstrip_bgcolor;?>">
<td ALIGN=CENTER><img SRC="http://www.berlios.de/images/blank.gif" height="1" width="135" border=0><br>
<span class="titlebar"><font color="<?php echo $th_navstrip_font_color;?>"><?php echo _("Language");?></font></span></td>
</tr>

<tr ALIGN=RIGHT BGCOLOR="<?php echo $th_nav_bgcolor;?>">
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
while (list(, $ln) = each($la_array)) {
	if ($la == $ln) {
		$sel = "selected";
	} else {
		$sel ="";
	}
	echo "<option value=\"$ln\" $sel>"._($ln)."\n";
}
?>
</select>
<?php
echo "<p><input TYPE=\"submit\" NAME=\"go\" VALUE=\""._("Go")."\">";
?>
</form>
</td>
</tr>
</table>
<?php
if (ereg("Gecko", "$HTTP_USER_AGENT")) {
	echo "<p align=center><a href=\"javascript:addNetscapePanel();\"><img SRC=\"images/add-button.gif\" BORDER=0 height=45 width=100></a>\n";
}
?>
<!-- end Language menu -->
