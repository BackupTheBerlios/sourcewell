<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ===================================================================
#
# Copyright (c) 2001 by
#                Lutz Henckel (lutz.henckel@fokus.gmd.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# Main Library file.
# You'll find in SourceWell's documentation a good explanation of the
# functions that are coded in this file.
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

#
# Shows an error when the database access fails
#

function mysql_die() {
    global $t,$be;
	if (isset($be)) {
        $be->box_full($t->translate("Database Access failed"), mysql_errno()." : ".mysql_error());
    }
}

#
# Returns time in timestamp format 
#

function mktimestamp($time) {
    $timestamp = mktime(substr($time,8,2),substr($time,10,2),substr($time,12,2),substr($time,4,2),substr($time,6,2),substr($time,0,4));
    return $timestamp;
}

#
#
#

function timestr($timestamp) {
    global $t;
    $time = strftime("%A, %e. %B %Y, %H:%M:%S %Z", $timestamp);
    return $time;
}

function timestr_short($timestamp){
    global $t;
    $time = strftime("%a,%e.%b,%H:%M:%S", $timestamp);
    return $time;
}

function timestr_comment($timestamp){
    global $t;
    $time = strftime("%e. %b, %H:%M", $timestamp);
    return $time;
}

#
# appfull: Shows the whole information stored about an app
#

function appfull($row) {
    global $bx, $t;
	$bx->box_begin();
	$bx->box_title($row["name"]." ".$row["version"]." (".typestr($row["type"]).")");
	$bx->box_body_begin();
    $timestamp = mktimestamp($row["modification"]);
    echo "<b>".$t->translate("by")." <a href=\"mailto:".$row["email_usr"]."\">".$row["user"]."</a> - ".timestr($timestamp)."</b>\n";
    echo "<p>".$row["description"]."\n";
    echo "<table border=0 cellspacing=1 cellpadding=3 width=100% bgcolor=".$GLOBALS["th_box_body_bgcolor"].">\n";
    if (!empty($row["homepage"])) {
    	echo "<tr valign=top><td align=right><b>".$t->translate("Homepage").":</b></td><td><a href=\"redirect.php3?id=".$row["appid"]."&type=homepage_cnt&url=".$row["homepage"]."\" target=_blank>".$row["homepage"]."</a> (".$row["homepage_cnt"]." ".$t->translate("hits").")</td></tr>\n";
    }
    if (!empty($row["download"])) {
    	echo "<tr valign=top><td align=right><b>".$t->translate("Download").":</b></td><td width=75%><a href=\"redirect.php3?id=".$row["appid"]."&type=download_cnt&url=".$row["download"]."\" target=_blank>".$row["download"]."</a> (".$row["download_cnt"]." ".$t->translate("hits").")</td></tr>\n";
    }
    if (!empty($row["changelog"])) {
    	echo "<tr valign=top><td align=right><b>".$t->translate("Changelog").":</b></td><td><a href=\"redirect.php3?id=".$row["appid"]."&type=changelog_cnt&url=".$row["changelog"]."\" target=_blank>".$row["changelog"]."</a> (".$row["changelog_cnt"]." ".$t->translate("hits").")</td></tr>\n";
    }
    if (!empty($row["rpm"])) {
    	echo "<tr valign=top><td align=right><b>".$t->translate("Red Hat Package").":</b></td><td><a href=\"redirect.php3?id=".$row["appid"]."&type=rpm_cnt&url=".$row["rpm"]."\" target=_blank>".$row["rpm"]."</a> (".$row["rpm_cnt"]." ".$t->translate("hits").")</td></tr>\n";
    }
    if (!empty($row["deb"])) {
    	echo "<tr valign=top><td align=right><b>".$t->translate("Debian Package").":</b></td><td><a href=\"redirect.php3?id=".$row["appid"]."&type=deb_cnt&url=".$row["deb"]."\" target=_blank>".$row["deb"]."</a> (".$row["deb_cnt"]." ".$t->translate("hits").")</td></tr>\n";
    }
    if (!empty($row["tgz"])) {
    	echo "<tr valign=top><td align=right><b>".$t->translate("Slackware Package").":</b></td><td><a href=\"redirect.php3?id=".$row["appid"]."&type=tgz_cnt&url=".$row["tgz"]."\" target=_blank>".$row["tgz"]."</a> (".$row["tgz_cnt"]." ".$t->translate("hits").")</td></tr>\n";
    }
    if (!empty($row["cvs"])) {
    	echo "<tr valign=top><td align=right><b>".$t->translate("CVS Tree").":</b></td><td><a href=\"redirect.php3?id=".$row["appid"]."&type=cvs_cnt&url=".$row["cvs"]."\" target=_blank>".$row["cvs"]."</a> (".$row["cvs_cnt"]." ".$t->translate("hits").")</td></tr>\n";
    }
    if (!empty($row["screenshots"])) {
    	echo "<tr valign=top><td align=right><b>".$t->translate("Screenshots").":</b></td><td><a href=\"redirect.php3?id=".$row["appid"]."&type=screenshots_cnt&url=".$row["screenshots"]."\" target=_blank>".$row["screenshots"]."</a> (".$row["screenshots_cnt"]." ".$t->translate("hits").")</td></tr>\n";
    }
    if (!empty($row["mailarch"])) {
    	echo "<tr valign=top><td align=right><b>".$t->translate("Mailing List Archive").":</b></td><td><a href=\"redirect.php3?id=".$row["appid"]."&type=mailarch_cnt&url=".$row["mailarch"]."\" target=_blank>".$row["mailarch"]."</a> (".$row["mailarch_cnt"]." ".$t->translate("hits").")</td></tr>\n";
    }
    echo "<tr valign=top><td align=right><b>".$t->translate("Type").":</b></td>\n";
	echo "<td>".typestr($row["type"])."</td>\n";
	echo "</tr>\n";
    echo "<tr valign=top><td align=right><b>".$t->translate("Version").":</b></td><td>".$row["version"]."</td></tr>\n";
    echo "<tr valign=top><td align=right><b>".$t->translate("Author").":</b></td><td>";
    echo $row["developer"];
	if (!empty($row["email"]))
		echo " &lt;<a href=\"mailto:".$row["email"]."\">".ereg_replace("@"," at ",htmlentities($row["email"]))."</a>&gt;";
	echo "</td></tr>\n";

    $result_lic = mysql_db_query($GLOBALS["db_name"],"SELECT * FROM licenses WHERE license='".$row["license"]."'");
    $row_lic = mysql_fetch_array($result_lic);
    echo "<tr valign=top><td align=right><b>".$t->translate("License").":</b></td><td><a href=\"".$row_lic["url"]."\" target=_blank>".$row["license"]."</a>&nbsp;</td></tr>\n";
    mysql_free_result($result_lic);
    echo "<tr valign=top><td align=right><b>".$t->translate("Section/Category").":</b></td><td><a href=\"appbycat.php3?section=".urlencode($row["section"])."&category=".urlencode($row["category"])."\">".$row["section"]."/".$row["category"]."</a></td></tr>\n";
    if (!empty($row["depend"])) {
    	echo "<tr valign=top><td align=right><b>".$t->translate("Depends on").":</b></td><td>".$row["depend"]."</td></tr>\n";
    }
	if ($row["urgency"] == 0)
		$row["urgency"] = 2;
    echo "<tr valign=top><td align=right><b>".$t->translate("Urgency").":</b></td><td>".$t->translate(urgency($row["urgency"]))."</td></tr>\n";
    echo "<tr><td align=right><b>".$t->translate("Application ID").":</b></td><td><a href=\"appbyid.php3?id=".$row["appid"]."\">".$row["appid"]."</a> (".$row["app_cnt"]." ".$t->translate("hits").")</td></tr>\n";
	switch ($row["status"]) {
	case 'P':
		echo "<tr valign=top><td align=right><b>".$t->translate("Status").":</b></td><td>";
		echo $t->translate("Waiting for Review by an Editor");
		echo "</td></tr>\n";
		break;
	case 'D':
		echo "<tr valign=top><td align=right><b>".$t->translate("Status").":</b></td><td>";
		echo $t->translate("deleted");
		echo "</td></tr>\n";
		break;
    }
    $result_his = mysql_db_query($GLOBALS["db_name"],"SELECT * FROM history WHERE appid=".$row["appid"]." ORDER BY creation_his DESC");
    $i = 0;
    while ($row_his = mysql_fetch_array($result_his)) {
        $timestamp = mktimestamp($row_his["creation_his"]);
        if ($i == 0) {
            echo "<tr valign=top><td align=right valign=top><b>".$t->translate("Announcements").":</b></td><td>";
        } else {
            echo "<br>";
        }
        echo $row_his["version_his"]." ".$t->translate("by")." ".$row_his["user_his"]." ".$t->translate("on")." ".timestr($timestamp)."\n";
        $i += 1;
    }
    mysql_free_result($result_his);
    $result_dev = mysql_db_query($GLOBALS["db_name"],"SELECT * FROM software WHERE developer=\"".$row["developer"]."\" AND appid != \"".$row["appid"]."\"");
    $i = 0;
    while ($row_dev = mysql_fetch_array($result_dev)) {
        if ($i == 0) {
            echo "<tr valign=top><td align=right valign=top><b>".$t->translate("Others by Author").":</b></td><td>";
        } else {
            echo "<br>";
        }
        echo "<a href=\"appbyid.php3?id=".$row_dev["appid"]."\">".$row_dev["name"]." ".$row_dev["version"]."</a> (".typestr($row_dev["type"]).")\n";
        $i++;
    }
    mysql_free_result($result_dev);
	echo "</td></tr></table>\n";
	$bx->box_body_end();
	$bx->box_title_begin();
    echo "<a href=\"updapp.php3?id=".$row["appid"]."\"><img src=\"images/recycled.png\" border=0 alt=\"".$t->translate("Update")."\"></a>&nbsp;&nbsp;<a href=\"cmtapp.php3?id=".$row["appid"]."\"><img src=\"images/txt.png\" border=0 alt=\"".$t->translate("Comment")."\"></a>\n";
	$bx->box_title_end();
    $bx->box_end();
}

#
# appcat: shows the apps from a certain category
# title puts the name of the category as title of the table
# iter allows to show the apps in steps of x apps each time
#

function appcat($result,$title,$iter) {
    global $bx,$t;
	$bx->box_begin();
	$bx->box_title($t->translate($title));
	$bx->box_body_begin();
	echo "<table border=0 align=center cellspacing=0 cellpadding=3 width=100%>\n";
	$i = $iter;
	while($row = mysql_fetch_array($result)) {
    	echo "<tr><td align=right valign=top width=4%><b>$i</b></td><td width=96%><b><a href=\"appbyid.php3?id=".$row["appid"]."\">".$row["name"]." ".$row["version"]."</a> (".typestr($row["type"]).")</b>\n";
    	echo "<br>".$row["description"]."\n";
		echo "<br><b>".$t->translate("Importance").":</b> ".$row["sum_cnt"];
		if ($row["urgency"] == 0)
			$row["urgency"] = 2;
		echo "; <b>".$t->translate("Urgency").":</b> ".$t->translate(urgency($row["urgency"]))."\n";
    	$timeupd = mktimestamp($row["modification"]);
    	$timecre = mktimestamp($row["creation"]);
		if (strcmp($timeupd, $timecre)) {
			echo "<br><b>".$t->translate("Updated").":</b> ".timestr($timeupd)."\n";
		}
    	$timecre = mktimestamp($row["creation"]);
    	echo "<br><b>".$t->translate("Created").":</b> ".timestr($timecre)."</td>\n";
		$i++;
    }
    echo "</tr></table>\n";
	$bx->box_body_end();
	$bx->box_end();
}


## appdat($row):
##
## Display Application data

function appdat($row) {
	global $bx;
    appd($row);
    $bx->box_end();
}


## appupdate($row):
##
## Display Application data and Update Link

function appupdate($row) {
    global $perm, $bx, $t;
    appd($row);
	$bx->box_title_begin();
    echo "<table width=100% border=0 cellspacing=0 cellpadding=3><tr valign=bottom>\n";
	switch ($row["status"]) {
	case 'P':
		echo "<td width=40%><a href=\"updapp.php3?id=".$row["appid"]."\"><img src=\"images/recycled.png\" border=0 alt=\"".$t->translate("Review")."\"></a></td>\n";
		echo "<td width=60% align=right border=0><b>".$t->translate("Waiting for Review by an Editor")."</b>\n";
		break;
	case 'D':
		echo "<td width=40%><a href=\"updapp.php3?id=".$row["appid"]."\"><img src=\"images/recycled.png\" border=0 alt=\"".$t->translate("Review")."\"></a></td>\n";
		echo "<td width=60% align=right border=0><b>".$t->translate("Is deleted")."</b>\n";
		break;
	case 'M':
		echo "<td width=40%><a href=\"updapp.php3?id=".$row["appid"]."\"><img src=\"images/recycled.png\" border=0 alt=\"".$t->translate("Review")."\"></a></td>\n";
		echo "<td width=60% align=right border=0><b>".$t->translate("Is modified")."</b>\n";
		break;
	default:
		echo "<td width=100%><a href=\"updapp.php3?id=".$row["appid"]."\"><img src=\"images/recycled.png\" border=0 alt=\"".$t->translate("Update")."\"></a>\n";
		break;
	}
	echo "</td></tr></table>\n";
	$bx->box_title_end();
	$bx->box_end();
}


## appd($row):
##
## Common support for functions appdat and appupdate

function appd($row) {
    global $bx,$t;
	$bx->box_begin();
	$bx->box_title_begin();
    echo "<table border=0 cellspacing=0 cellpadding=0 width=100%>\n";
    echo "<tr valign=bottom>";
    echo "<td width=30%><b><a href=\"appbyid.php3?id=".$row["appid"]."\">".$row["name"]." ".$row["version"]."</a> (".typestr($row["type"]).")</b></td>\n";
    echo "<td width=70% align=right>\n";
	if (isset($row["sum_cnt"])) {
		echo "<img src=\"images/importance.png\" alt=\"".$t->translate("Importance")."\"><b>(".$row["sum_cnt"].")</b>\n";
	}
	if ($row["urgency"] == 0)
		$row["urgency"] = 2;
    echo "&nbsp;";
	for ($i = 1; $i < $row["urgency"]; $i++) {
		echo "<img src=\"images/bell.png\" alt=\"".$t->translate("Urgency").":".$t->translate(urgency($row["urgency"]))."\">";
	}
    if (!empty($row["homepage"])) {
    	echo "&nbsp;&nbsp;<a href=\"redirect.php3?id=".$row["appid"]."&type=homepage_cnt&url=".$row["homepage"]."\" target=_blank><img src=\"images/html.png\" border=0 alt=\"".$t->translate("Homepage")."\"></a>\n";
    }
    if (!empty($row["download"])) {
    	echo "&nbsp;&nbsp;<a href=\"redirect.php3?id=".$row["appid"]."&type=download_cnt&url=".$row["download"]."\" target=_blank><img src=\"images/binary2.png\" border=0 alt=\"".$t->translate("Download")."\"></a>\n";
    }
    if (!empty($row["changelog"])) {
    	echo "&nbsp;&nbsp;<a href=\"redirect.php3?id=".$row["appid"]."&type=changelog_cnt&url=".$row["changelog"]."\" target=_blank><img src=\"images/info.png\" border=0 alt=\"".$t->translate("Changelog")."\"></a>\n";
    }
    $result_cnt = mysql_db_query($GLOBALS["db_name"],"SELECT COUNT(*) FROM comments WHERE appid='".$row["appid"]."'");
    $row_cnt = mysql_fetch_row($result_cnt);
    if ($row_cnt[0] <= 0) {
        $num = "";
    } else {
        $num = "<b>[".$row_cnt[0]."]</b>";
    }
    echo "&nbsp;&nbsp;<a href=\"cmtapp.php3?id=".$row["appid"]."\"><img src=\"images/txt.png\" border=0 alt=\"".$t->translate("Comments")."\"></a> $num</a>\n";
    mysql_free_result($result_cnt);
    echo "&nbsp;&nbsp;<a href=\"appbycat.php3?section=".urlencode($row["section"])."&category=".urlencode($row["category"])."\"><b>".$row["section"]."/".$row["category"]."</b></a>\n";
    echo "</td></tr>\n";
    echo "</table>\n";
	$bx->box_title_end();
	$bx->box_body_begin();
    $timestamp = mktimestamp($row["modification"]);
    echo "<b>".$t->translate("by")." <a href=\"mailto:".$row["email_usr"]."\">".$row["user"]."</a> - ".timestr($timestamp)."</b>\n";
    echo "<p>".$row["description"]."\n";
	$bx->box_body_end();
}


## appday($start):
##
## Display marginal Application data

function appday($start) {
	global $bx;
    $columns = "appid, name, version";
    $tables = "software";
    $where = "DATE_FORMAT(software.modification,'%Y-%m-%d')=\"$start\" AND software.status='A'";
    $order = "software.modification DESC";
    if (!$result = mysql_db_query($GLOBALS["db_name"],"SELECT $columns FROM $tables WHERE $where ORDER BY $order"))
    {
        mysql_die();
    } else {
        if (mysql_num_rows($result) > 0) {
			$bx->box_begin();
			$bx->box_title_begin();
            $time = mktime(0,0,0,substr($start,5,2),substr($start,8,2),substr($start,0,4));
            echo "<center><b><a href=\"index.php3?start=".strftime("%Y-%m-%d", $time)."&days=1\">".strftime("%A, %e. %b", $time)."</b></center></a>";
			$bx->box_title_end();
			$bx->box_body_begin();
            while($row = mysql_fetch_array($result)) {
                echo "<li><a href=\"appbyid.php3?id=".$row["appid"]."\">".$row["name"]." ".$row["version"]."</a></li>\n";
            }
			$bx->box_body_end();
			$bx->box_end();
        }
        mysql_free_result($result);
    }
}


function updform($row) {
    global $bx, $perm, $t;
	$bx->box_begin();
	$bx->box_title($t->translate("Update Application"));
	$bx->box_body_begin();
    echo "<form action=\"update.php3\" method=\"POST\">\n";
    echo "<table border=0 align=center cellspacing=0 cellpadding=3 width=100%>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Application Name")." (128):</td><td width=70%><b>".$row["name"]."</b></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Type").":</td><td width=70%>\n";
	echo typestr($row["type"])."</td></tr>\n";
	echo "<input type=\"hidden\" name=\"type\" value=\"".$row["type"]."\">\n";
    echo "<tr><td align=right width=30%>".$t->translate("Version")." (16):</td><td width=70%><input type=\"TEXT\" name=\"version\" size=16 maxlength=16 value=\"".$row["version"]."\"></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Section/Category").":</td><td width=70%>\n";
    echo "<select name=\"seccat\">\n";
    seccat($row);
    echo "</select></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("License").":</td><td width=70%>\n";
    echo "<select name=\"license\">\n";
    license($row);
    echo "</select></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Homepage")." (255):</td><td width=70%><input type=\"TEXT\" name=\"homepage\" size=40 maxlength=255 value=\"".$row["homepage"]."\">&nbsp;[<a href=\"".$row["homepage"]."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Download")." (255):</td><td width=70%><input type=\"TEXT\" name=\"download\" size=40 maxlength=255 value=\"".$row["download"]."\">&nbsp;[<a href=\"".$row["download"]."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Changelog")." (255):</td><td width=70%><input type=\"TEXT\" name=\"changelog\" size=40 maxlength=255 value=\"".$row["changelog"]."\">&nbsp;[<a href=\"".$row["changelog"]."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Red Hat Package")." (255):</td><td width=70%><input type=\"TEXT\" name=\"rpm\" size=40 maxlength=255 value=\"".$row["rpm"]."\">&nbsp;[<a href=\"".$row["rpm"]."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Debian Package")." (255):</td><td width=70%><input type=\"TEXT\" name=\"deb\" size=40 maxlength=255 value=\"".$row["deb"]."\">&nbsp;[<a href=\"".$row["deb"]."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Slackware Package")." (255):</td><td width=70%><input type=\"TEXT\" name=\"tgz\" size=40 maxlength=255 value=\"".$row["tgz"]."\">&nbsp;[<a href=\"".$row["tgz"]."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("CVS Tree")." (255):</td><td width=70%><input type=\"TEXT\" name=\"cvs\" size=40 maxlength=255 value=\"".$row["cvs"]."\">&nbsp;[<a href=\"".$row["cvs"]."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Screenshots")." (255):</td><td width=70%><input type=\"TEXT\" name=\"screenshots\" size=40 maxlength=255 value=\"".$row["screenshots"]."\">&nbsp;[<a href=\"".$row["screenshots"]."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Mailing List Archive")." (255):</td><td width=70%><input type=\"TEXT\" name=\"mailarch\" size=40 maxlength=255 value=\"".$row["mailarch"]."\">&nbsp;[<a href=\"".$row["mailarch"]."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Description")." (*):</td><td width=70%><textarea cols=40 rows=7 name=\"description\" wrap=\"virtual\" maxlength=255>".$row["description"]."</textarea></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Author")." (64):</td><td width=70%><input type=\"TEXT\" name=\"developer\" size=40 maxlength=64 value=\"".$row["developer"]."\"></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("E-Mail")." (128):</td><td width=70%><input type=\"TEXT\" name=\"email\" size=40 maxlength=128 value=\"".$row["email"]."\">&nbsp;[<a href=\"mailto:".$row["email"]."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Depends on")." (128):</td><td width=70%><input type=\"TEXT\" name=\"depend\" size=40 maxlength=128 value=\"".$row["depend"]."\"></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Urgency").":</td><td width=70%>\n";
    echo "<select name=\"urgency\">\n";
    echo "<option value=1";
    if ($row["urgency"] == 1) echo " selected";
    echo ">".$t->translate("low")."\n";
    echo "<option value=2";
    if ($row["urgency"] == 2 || $row["urgency"] == 0) echo " selected";
    echo ">".$t->translate("medium")."\n";
    echo "<option value=3";
    if ($row["urgency"] == 3) echo " selected";
    echo ">".$t->translate("high")."\n";
    echo "</select></td></tr>\n";
    if ($perm->have_perm("editor")) {
        echo "<tr><td align=right width=30%>".$t->translate("Status").":</td><td width=70%>\n";
		switch ($row["status"]) {
        case 'A':
			echo $t->translate("active")."\n";
			break;
		case 'P':
			echo $t->translate("pending")."\n";
			break;
		case 'D':
			echo $t->translate("deleted")."\n";
		}
        echo "</td></tr>\n";

        echo "<tr><td align=right width=30%>".$t->translate("Action").":</td><td width=70%>\n";
        echo "<select name=\"action\">\n";
        if ($row["status"] == 'P') {
	        echo "<option value=\"review\"";
	        echo ">".$t->translate("Review")."\n";
		} else {
			echo "<option value=\"update\"";
			echo ">".$t->translate("Update")."\n";
		}
        echo "<option value=\"change\"";
        echo ">".$t->translate("Change")."\n";
        if ($row["status"] == 'D' || $row["status"] == 'M') {
			echo "<option value=\"undelete\"";
			echo ">".$t->translate("Undelete")."\n";
		} else {
			echo "<option value=\"delete\"";
			echo ">".$t->translate("Delete")."\n";
		}
        echo "</select></td></tr>\n";
		echo "<tr><td align=right width=30%>&nbsp;</td><td width=70%><input type=\"Submit\" value=\"".$t->translate("Go")."\"></td></tr>\n";
    } else {
		echo "<input type=\"hidden\" name=\"action\" value=\"update\">\n";
		echo "<tr><td align=right width=30%>&nbsp;</td><td width=70%><input type=\"Submit\" value=\"".$t->translate("Update")."\"></td></tr>\n";
	}

    echo "<input type=\"hidden\" name=\"id\" value=\"".$row["appid"]."\">\n";
    echo "<input type=\"hidden\" name=\"status\" value=\"".$row["status"]."\">\n";
    echo "<input type=\"hidden\" name=\"oldstable\" value=\"".$row["stable"]."\">\n";
    echo "<input type=\"hidden\" name=\"olddevel\" value=\"".$row["devel"]."\">\n";
    echo "<input type=\"hidden\" name=\"modification\" value=\"".$row["modification"]."\">\n";
    echo "</form>\n";
    echo "</td></tr>\n";
    echo "</table>\n";
	$bx->box_body_end();
	$bx->box_end();
}


function insform() {
    global $PHP_SELF, $bx, $t;
	$bx->box_begin();
	$bx->box_title($t->translate("Insert Application"));
	$bx->box_body_begin();
    echo "<table border=0 align=center cellspacing=0 cellpadding=3>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Application Name")." (128):</td><td width=70%><b>".$GLOBALS["name"]."</b></td></tr>\n";
    echo "<form action=\"insert.php3\" method=\"POST\">\n";
    echo "<input type=\"hidden\" name=\"name\" value=\"".$GLOBALS["name"]."\">\n";
    echo "<tr><td align=right width=30%>".$t->translate("Type").":</td><td width=70%>\n";
	echo typestr($GLOBALS["type"])."</td></tr>\n";
	echo "<input type=\"hidden\" name=\"type\" value=\"".$GLOBALS["type"]."\">\n";
    echo "<tr><td align=right width=30%>".$t->translate("Version")." (16):</td><td width=70%><input type=\"TEXT\" name=\"version\" size=16 maxlength=16></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Section/Category").":</td><td width=70%>\n";
    echo "<select name=\"seccat\">\n";
    seccat("");
    echo "</select></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("License").":</td><td width=70%>\n";
    echo "<select name=\"license\">\n";
	$row["license"] = "GPL";
    license($row);
    echo "</select></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Homepage")." (255):</td><td width=70%><input type=\"TEXT\" name=\"homepage\" size=40 maxlength=255></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Download")." (255):</td><td width=70%><input type=\"TEXT\" name=\"download\" size=40 maxlength=255></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Changelog")." (255):</td><td width=70%><input type=\"TEXT\" name=\"changelog\" size=40 maxlength=255></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Red Hat Package")." (255):</td><td width=70%><input type=\"TEXT\" name=\"rpm\" size=40 maxlength=255></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Debian Package")." (255):</td><td width=70%><input type=\"TEXT\" name=\"deb\" size=40 maxlength=255></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Slackware Package")." (255):</td><td width=70%><input type=\"TEXT\" name=\"tgz\" size=40 maxlength=255></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("CVS Tree")." (255):</td><td width=70%><input type=\"TEXT\" name=\"cvs\" size=40 maxlength=255></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Screenshots")." (255):</td><td width=70%><input type=\"TEXT\" name=\"screenshots\" size=40 maxlength=255></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Mailing List Archive")." (255):</td><td width=70%><input type=\"TEXT\" name=\"mailarch\" size=40 maxlength=255></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Description")." (*):</td><td width=70%><textarea cols=40 rows=7 name=\"description\" wrap=\"virtual\" maxlength=255></textarea></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Author")." (64):</td><td width=70%><input type=\"TEXT\" name=\"developer\" size=40 maxlength=64></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("E-Mail")." (128):</td><td width=70%><input type=\"TEXT\" name=\"email\" size=40 maxlength=128></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Depends on")." (128):</td><td width=70%><input type=\"TEXT\" name=\"depend\" size=40 maxlength=128></td></tr>\n";
    echo "<tr><td align=right width=30%>".$t->translate("Urgency").":</td><td width=70%>\n";
	echo "<select name=\"urgency\">\n";
	echo "<option value=1>".$t->translate("low")."\n";
	echo "<option value=2 selected>".$t->translate("medium")."\n";
	echo "<option value=3>".$t->translate("high")."\n";
    echo "</select></td></tr>\n";
    echo "<tr><td align=right width=30%>&nbsp;</td><td width=70%><input type=\"Submit\" value=\"".$t->translate("Insert")."\"></td></tr>\n";
    echo "</form>\n";
    echo "</td></tr>\n";
    echo "</table>\n";
	$bx->box_body_end();
	$bx->box_end();
}

function inssec($string) {
    global $PHP_SELF, $bx, $t;
	$bx->box_begin();
	$bx->box_title($t->translate("Insert a Category"));
	$bx->box_body_begin();
    echo "<table border=0 align=center cellspacing=0 cellpadding=3 width=100%>\n";
    echo "<form action=\"inscat.php3\" method=\"POST\">\n";

    if ($string == "yes") {
		// Inserting Sections and/or Categories
      echo "<tr><td align=right>".$t->translate("Section").":</td><td><b>".$GLOBALS["section"]."</b></td></tr>\n";
      echo "<input type=\"hidden\" name=\"section\" value=\"".$GLOBALS["section"]."\">\n";

    } else {
      echo "<tr><td align=right>".$t->translate("Section").":</td><td>\n";
      echo "<select name=\"section\">\n";
      sec($GLOBALS["section"]);     // We select the first one to avoid having a blank line
      echo "</select></td></tr>\n";
    }

    echo "<tr><td align=right>".$t->translate("Category")." (64):</td><td><input type=\"TEXT\" name=\"category\" size=40 maxlength=64></td></tr>\n";
    echo "<tr><td align=right>&nbsp;</td><td><input type=\"Submit\" value=\"".$t->translate("Insert")."\"></td></tr>\n";
    echo "</form>\n";
    echo "</td></tr>\n";
    echo "</table>\n";
	$bx->box_body_end();
	$bx->box_end();
}


// 
//  sec($row)
//  Displays the different section/category pairs as a select form 
//  $row ist the SELECTED attribute
// 

function seccat($row) {
    $columns = "*";
    $tables = "categories";
    $order = "section,category ASC";
    if (!$result = mysql_db_query($GLOBALS["db_name"],"SELECT $columns FROM $tables ORDER BY $order"))
    {
        mysql_die();
    } else {
        while ($rown = mysql_fetch_array($result)) {
            echo "<option";
	    	if ($rown["section"] == $row["section"] && $rown["category"] == $row["category"]) echo " selected";
    	    	echo ">".$rown["section"]."/".$rown["category"]."\n";
        }
    }
}

// 
//  sec($row)
//  Displays the different sections as a select form 
//  $row ist the SELECTED attribute
// 

function sec($row) {
    $columns = "section";
    $tables = "categories";
    $order = "section ASC";
    if (!$result = mysql_db_query($GLOBALS["db_name"],"SELECT DISTINCT $columns FROM $tables ORDER BY $order"))
    {
        mysql_die();
    } else {
        while ($rown = mysql_fetch_array($result)) {
            echo "<option";
	    if ($rown["section"] == $row) echo " selected";
    	    echo ">". $rown["section"]."\n";
        }
    }
}

// 
//  license ($row)
//  Displays the different licenses as a select form 
//  $row ist the SELECTED attribute
// 


function license($row) {
    $columns = "*";
    $tables = "licenses";
    $order = "license ASC";
    if (!$result = mysql_db_query($GLOBALS["db_name"],"SELECT $columns FROM $tables ORDER BY $order"))
    {
        mysql_die();
    } else {
        while ($rown = mysql_fetch_array($result)) {
            echo "<option";
	    	if ($rown["license"] == $row["license"]) echo " selected";
    	    echo ">".$rown["license"]."\n";
        }
    }
}

function urgency($int) {
	switch ($int) {
	case 1:
		return "low";
		break;
	case 2:
		return "medium";
		break;
	case 3:
		return "high";
		break;
	default:
		return "medium";
		break;
	}
}


## show_more($iter,$maxiter,$url)
##
## shows 10 apps of the current iteraction $iter
## until it reaches the maximum number of iteractions $maxiter


function show_more($iter,$maxiter,$url) {

  $iter /=10;
  echo "<table border=0 width=600><tr>";
  echo "<td>&nbsp;</td>\n";
  echo "<td align=right>";

  $maxiter= Floor($maxiter);

  if ($iter > 3) {
      echo "<a href=\"".$url."iter=0\">&lt;&lt;</a>\n";
  }

  $number = $iter - 3;
  if ($number < 0) $number = 0;
  if ($iter > 2) {
    echo "<a href=\"".$url."iter=$number\">&lt;</a>\n";
  }

  switch ($iter) {
    case 0: $bias=0; break;
    case 1: $bias=1; break;
    case ($maxiter-1): if ($iter>3) {$bias=3;} else {$bias=2;} break;
    case ($maxiter): if ($iter>4) {$bias=4;} else {$bias=2;} break;
    default: $bias=2; break;
  }

  for($i=$iter-$bias;$i<$maxiter+1 && $i<($iter+5-$bias);$i++) {
    $number1 = $i*10 +1;
    $number2 = $number1 + 9;
    $number = strval($number1)."-".strval($number2);
    if ($i != $iter) echo "<a href=\"".$url."iter=$i\">&nbsp;$number</a>\n";
    else echo "<B>&nbsp;$number</B>\n"; 
   }

  $number = $iter + 5 - $bias;
  if ($number > $maxiter+$bias) $number =$maxiter+$bias;
  if ($iter < $maxiter-4+$bias) {
    echo "<a href=\"".$url."iter=$number\"> &gt;</a>\n";
  }

  $number = $iter + 10 - $bias;
  if ($number > $maxiter) $number = $maxiter;
  if ($iter < $maxiter-5 +$bias) {
    echo "<a href=\"".$url."iter=$number\"> &gt;&gt;</a>\n";
  }

   echo "</td>\n";
   echo "</tr></table><BR>";
}

function wrap($string,$width=75,$break=" ") {
	$out = "";
	$lin = "";
	$tok = strtok($string,$break);
	while ($tok) {
		if ((strlen($lin) + strlen($tok)) > $width) {
			$out .= $lin."\n";
			$lin = "";
		}
		if (strlen($lin) > 0)
			$lin .= " ";
		$lin .= $tok;
		$tok = strtok (" ");
	}
	$out .= $lin;
	return $out;
}

function typestr($type) {
	global $t;
	if ($type == "S")
		$str = $t->translate("Stable");
	if ($type == "D")
		$str = $t->translate("Development");
	return $str;
}

function increasecnt($id, $type) {
    $columns = "*";
    $tables = "counter";
    $where = "appid='$id'";
    if (!$result = mysql_db_query($GLOBALS["db_name"], "SELECT $columns FROM $tables WHERE $where")) {
        mysql_die();
    } else {
//
// If application in table and first access today update counters
//
		$first = checkcnt($id, $GLOBALS[REMOTE_ADDR], $type);
        if (($row = mysql_fetch_array($result)) && $first) {
            $columns = $type;
            $tables = "counter";
            $counter = $row["$type"] + 1;
            $set = "$type='$counter'";
            $where = "appid='$id'";
            if (!$resultn = mysql_db_query($GLOBALS["db_name"], "UPDATE $tables SET $set WHERE $where")) {
				mysql_die();
			}
		}
		mysql_free_result($result);
	}
}

function checkcnt($id, $ipaddr, $type) {
	$ret = 1;
//
// Delete all entries from yesterday
//
	$today = date("Y-m-d");
	$tables = "counter_check";
	$where = "DATE_FORMAT(creation_cnt,'%Y-%m-%d') != '$today'";
	if (!$result = mysql_db_query($GLOBALS["db_name"], "DELETE FROM $tables WHERE $where")) {
		mysql_die();
	} else {
		$columns = "*";
		$where = "appid='$id' AND cnt_type='$type' AND ipaddr='$ipaddr'";
		if (!$result = mysql_db_query($GLOBALS["db_name"], "SELECT $columns FROM $tables WHERE $where")) {
			mysql_die();
		} else {
//
// If remote host already accessed the apps link,
// don´t increase corresponding counter
//
			if ($row = mysql_fetch_array($result)) {
				$ret = 0;
			} else {
// Include entry for remote host
				$set = "appid='$id',cnt_type='$type',ipaddr='$ipaddr'";
				if (!$resultn = mysql_db_query($GLOBALS["db_name"], "INSERT $tables SET $set")) {
					mysql_die();
				}
			}
			mysql_free_result($result);
		}
	}
	return $ret;
}

function nlmsg($period) {
	$columns = "*,SUM(homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt) AS sum_cnt";
	$tables = "software, counter, auth_user";
	switch ($period) {
	case "weekly":
		$lastday = time() - 7 * 24 * 60 * 60;
		$where = "DATE_FORMAT(software.modification,'%Y-%m-%d')<=\"".date("Y-m-d")."\" AND DATE_FORMAT(software.modification,'%Y-%m-%d')>\"".date("Y-m-d",$lastday)."\"";
		break;
	case "daily":
	default:
		$where = "DATE_FORMAT(software.modification,'%Y-%m-%d')=\"".date("Y-m-d")."\"";
		break;
	}
	$where .= " AND software.appid=counter.appid AND software.user=auth_user.username AND software.status='A' GROUP BY software.appid";
	$order = "software.modification DESC";

	if (!$result = mysql_db_query($GLOBALS["db_name"],"SELECT $columns FROM $tables WHERE $where ORDER BY $order")) {
		mysql_die();
	}
	if (mysql_num_rows($result) <= 0)
		return 0;
	$msg = $GLOBALS["sys_name"]." $period newsletter for ".date("l, dS of F Y, H:i:s T")."\n";
	$msg .= "Number of announcements: ".mysql_num_rows($result)."\n";
	$msg .= "\n               -----------------------------\n";
	$msg .= "                   Annoucements Headlines\n";
	$msg .= "               -----------------------------\n\n";

	$i = 1;
	while (($row = mysql_fetch_array($result))) {
		$msg .= "$i: ".$row["name"]." ".$row["version"]." ";
		if ($row["type"] == 'S')
			$msg .= "(Stable)\n";
		if ($row["type"] == 'D')
			$msg .= "(Development)\n";
		$i++;
	}
	$msg .= "\n               -----------------------------\n";
	$msg .= "                   Annoucements Details\n";
	$msg .= "               -----------------------------\n";

	@mysql_data_seek($result, 0);

	$i = 1;
	while (($row = mysql_fetch_array($result))) {
		$timestamp = mktimestamp($row["modification"]);
		$msg .= "\nAnnouncement : $i\n";
		$msg .= "Name         : ".$row["name"]."\n";
		$msg .= "Date         : ".date("l, dS of F Y, H:i:s T", $timestamp)."\n";
		$msg .= "Type         : ";
		if ($row["type"] == 'S')
			$msg .= "Stable\n";
		if ($row["type"] == 'D')
			$msg .= "Development\n";
		$msg .= "Version      : ".$row["version"]."\n";
		if ($period == "daily") {
			$msg .= "License      : ".$row["license"]."\n";
			$msg .= "Section      : ".$row["section"]."\n";
			$msg .= "Category     : ".$row["category"]."\n";
			$msg .= "Importance   : ".$row["sum_cnt"]."\n";
			$msg .= "Urgency      : ".urgency($row["urgency"])."\n";
			if (!empty($row["homepage"]))
				$msg .= "\nHomepage     : ".$row["homepage"]."\n";
			if (!empty($row["download"]))
				$msg .= "Download     : ".$row["download"]."\n";
			if (!empty($row["changelog"]))
				$msg .= "Changelog    : ".$row["changelog"]."\n";
			if (!empty($row["rpm"]))
				$msg .= "RPM          : ".$row["rpm"]."\n";
			if (!empty($row["deb"]))
				$msg .= "deb          : ".$row["deb"]."\n";
			if (!empty($row["tgz"]))
				$msg .= "tgz          : ".$row["tgz"]."\n";
			if (!empty($row["cvs"]))
				$msg .= "CVS Tree     : ".$row["cvs"]."\n";
			if (!empty($row["screenshots"]))
				$msg .= "Screenshots  : ".$row["screenshots"]."\n";
			if (!empty($row["mailarch"]))
				$msg .= "Mailing List Archive : ".$row["mailarch"]."\n";
			$msg .= "\nDescription : \n".wrap($row["description"])."\n";
			$msg .= "\nAuthor       : ".$row["developer"]."\n";
			if (!empty($row["email"]))
				$msg .= "Email        : ".$row["email"]."\n";
			if (!empty($row["depend"]))
				$msg .= "Depens on    : ".$row["depend"]."\n";
			$msg .= "\n";
		}
		$msg .= $GLOBALS["sys_name"]."   : http://sourcewell.berlios.de/appbyid.php3?id=".$row["appid"]."\n";
		$msg .= "\n               -----------------------------\n";
		$i++;
	}
	$msg .= "\nYou get this ".$GLOBALS["sys_name"]." $period newsletter,"
		."\nbecause you have subscribed to the mailing list ";
	switch ($period) {
	case "weekly":
		$msg .= "\n".$GLOBALS["ml_weeklynewstoaddr"]."."
			."\nTo unsubscribe from this mailing list,"
			."\nsend a message by email to"
			."\n".$GLOBALS["ml_weeklynewsreqaddr"]
			."\nwith \"unsubscribe <password>\" as subject or visit"
			."\n".$GLOBALS["ml_weeklylisturl"];
		break;
	case "daily":
	default:
		$msg .= "\n".$GLOBALS["ml_newstoaddr"]."."
			."\nTo unsubscribe from this mailing list,"
			."\nsend a message by email to"
			."\n".$GLOBALS["ml_newsreqaddr"]
			."\nwith \"unsubscribe <password>\" as subject or visit"
			."\n".$GLOBALS["ml_listurl"];
		break;
	}
	$msg .=	"\nand follow the instructions there."
		."\n\n - ".$GLOBALS["sys_name"]." crew";
	mysql_free_result($result);
	return $msg;
}

function mailuser($perms, $subj, $message) {
	global $t;
	$columns = "email_usr";
	$tables = "auth_user";
	$where = "perms LIKE '%$perms%'";
	if ($result = mysql_db_query($GLOBALS["db_name"], "SELECT $columns FROM $tables WHERE $where")) {
	    while ($row = mysql_fetch_array($result)) {
			mail($row["email_usr"],"[".$GLOBALS["sys_name"]."] ".$subj,$message,"From: ".$GLOBALS["ml_fromaddr"]."\nReply-To: ".$GLOBALS["ml_replyaddr"]."\nX-Mailer: PHP");
		}
		mysql_free_result($result);
	}
}

?>
