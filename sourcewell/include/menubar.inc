<!-- BerliOS menu -->
<table BORDER=0 CELLSPACING=0 CELLPADDING=3 WIDTH="100%" BGCOLOR="<?php echo $th_nav_bgcolor;?>">
<tr BGCOLOR="<?php echo $th_navstrip_bgcolor;?>">
<td ALIGN=CENTER>
<span class="titlebar"><font color="<?php echo $th_navstrip_font_color?>"><?php echo $sys_name?></font></span></td>
</tr>

<tr ALIGN=RIGHT BGCOLOR="<?php echo $th_nav_bgcolor;?>">
<td><a href="index.php3" class="menus"><?php echo $t->translate("Recent Apps"); ?></a>
<br><a href="faq.php3" class="menus"><?php echo $t->translate("Q&amp;A"); ?></a>

<br><br>

<?php
if (isset($auth) && !empty($auth->auth["perm"]) && !($logout) ) {
	if ($perm->have_perm("user") || $perm->have_perm("user_pending") || $perm->have_perm("editor") || $perm->have_perm("admin")) {
		$db = @mysql_pconnect($db_host, $db_name, $db_password);
		echo "<a href=\"logout.php3\" class=\"menus\">".$t->translate("Logout")."</a>\n";
	}
} else {
	echo "<a href=\"login.php3\" class=\"menus\">".$t->translate("Login")."</a>\n";
}
?>
<br><a href="register.php3" class="menus"><?php echo $t->translate("New User"); ?></a>
<br><a href="remind.php3" class="menus"><?php echo $t->translate("Forgot Password"); ?></a>
<?php
if (isset($auth) && !empty($auth->auth["perm"]) && !($logout)) {
	if ($perm->have_perm("user") || $perm->have_perm("user_pending") || $perm->have_perm("editor") || $perm->have_perm("admin")) {
		echo "<br><a href=\"chguser.php3\" class=\"menus\">".$t->translate("Change User")."</a>\n";
	}
}
?>
<br><a href="users.php3" class="menus"><?php echo $t->translate("Users"); ?></a>
<br>
<br><a href="categories.php3" class="menus"><?php echo $t->translate("Apps Index"); ?></a>
<?php
if (isset($auth) && !empty($auth->auth["perm"]) && !($logout)) {
	echo "<br><a href=\"insform.php3\" class=\"menus\">".$t->translate("New Apps")."</a>\n";
	echo "<br><a href=\"appbyuser.php3\" class=\"menus\">".$t->translate("Update Apps")."</a>\n";
    if ($perm->have_perm("editor")) {
        $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE status='P'");
        $row = mysql_fetch_row($result);
        echo "<br><a href=\"apppend.php3\" class=\"menus\">".$t->translate("Pending Apps")." [$row[0]]</a>\n";
        mysql_free_result($result);
        $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE status='D'");
        $row = mysql_fetch_row($result);
        echo "<br><a href=\"appdom.php3?action=delete\" class=\"menus\">".$t->translate("Deleted Apps")." [$row[0]]</a>\n";
        $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE status='M'");
        $row = mysql_fetch_row($result);
        echo "<br><a href=\"appdom.php3?action=modify\" class=\"menus\">".$t->translate("Modified Apps")." [$row[0]]</a>\n";
        mysql_free_result($result);
    }
}
?>
<br><a href="developers.php3" class="menus"><?php echo $t->translate("Authors"); ?></a>
<br><a href="licenses.php3" class="menus"><?php echo $t->translate("Licenses"); ?></a>
<br>
<br><a href="newsletter.php3" class="menus"><?php echo $t->translate("Newsletter"); ?></a>
<br><a href="backend.php3" class="menus"><?php echo $t->translate("Backend"); ?></a>
<br><a href="stats.php3?option=general" class="menus"><?php echo $t->translate("Statistics"); ?></a>
<br><a href="/html" class="menus"><?php echo $t->translate("About"); ?></a>
</td>
</tr>
</table>
<!-- end BerliOS menu -->
<!-- Admin menu -->
<?php
if (isset($auth) && !empty($auth->auth["perm"]) && !($logout)) {
	if ($perm->have_perm("admin")) {
?>
<table BORDER=0 CELLSPACING=0 CELLPADDING=3 WIDTH="100%">
<tr BGCOLOR="<?php echo $th_navstrip_bgcolor;?>">
<td ALIGN=CENTER><img SRC="http://www.berlios.de/images/blank.gif" height="1" width="135" border=0><br>
<span class="titlebar"><font color="<?php echo $th_navstrip_font_color;?>"><?php echo $t->translate("Administration"); ?></font></span></td>
</tr>

<tr ALIGN=RIGHT BGCOLOR="<?php echo $th_nav_bgcolor;?>">
<td>
<?php
		$result = mysql_db_query($db_name,"SELECT COUNT(*) FROM auth_user");
		$row = mysql_fetch_row($result);
		echo "<a href=\"admuser.php3\" class=\"menus\">".$t->translate("Users")." [$row[0]]</a>\n";
		mysql_free_result($result);
		echo "<br><a href=\"nladm.php3?period=daily\" class=\"menus\">".$t->translate("Daily Newsletter")."</a>\n";
		echo "<br><a href=\"nladm.php3?period=weekly\" class=\"menus\">".$t->translate("Weekly Newsletter")."</a>\n";
		echo "<br><a href=\"admsec.php3\" class=\"menus\">".$t->translate("Sections")."</a>\n";
		echo "<br><a href=\"admcat.php3\" class=\"menus\">".$t->translate("Categories")."</a>\n";
		echo "<br><a href=\"admlicens.php3\" class=\"menus\">".$t->translate("Licenses")."</a>\n";
		echo "<br><a href=\"admcomment.php3\" class=\"menus\">".$t->translate("Comments")."</a>\n";
		echo "<br><a href=\"admdate.php3\" class=\"menus\">".$t->translate("Check Date")."</a>\n";

?>
</td>
</tr>
</table>
<?php
	}
}
?>
<!-- end Admin menu -->
<!-- Search menu -->
<table BORDER=0 CELLSPACING=0 CELLPADDING=3 WIDTH="100%">
<tr BGCOLOR="<?php echo $th_navstrip_bgcolor;?>">
<td ALIGN=CENTER><img SRC="http://www.berlios.de/images/blank.gif" height="1" width="135" border=0><br>
<span class="titlebar"><font color="<?php echo $th_navstrip_font_color;?>"><?php echo $t->translate("Search"); ?></font></span></td>
</tr>

<tr ALIGN=RIGHT BGCOLOR="<?php echo $th_nav_bgcolor;?>">
<td align=center>
<p>
<form action="appsearch.php3">
<input TYPE="text" SIZE="10" NAME="search" VALUE="">
<?php
echo "<p><input TYPE=\"submit\" NAME=\"Search\" VALUE=\"".$t->translate("Search")."\">";
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
<span class="titlebar"><font color="<?php echo $th_navstrip_font_color;?>"><?php echo $t->translate("Language");?></font></span></td>
</tr>

<tr ALIGN=RIGHT BGCOLOR="<?php echo $th_nav_bgcolor;?>">
<td align=center>
<p>
<form action="<?php echo $PHP_SELF; ?>">
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
	echo "<option value=\"$ln\" $sel>".$t->translate($ln)."\n";
}
?>
</select>
<?php
echo "<p><input TYPE=\"submit\" NAME=\"go\" VALUE=\"".$t->translate("Go")."\">";
?>
</form>
</td>
</tr>
</table>
<!-- end Language menu -->
