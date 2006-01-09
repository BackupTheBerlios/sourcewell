<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ===================================================================
#
# Copyright (c) 2001-2004 by
#                Lutz Henckel (lutz.henckel@fokus.fraunhofer.de) and
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

function appfull($query) {
  global $bx, $t, $sess, $db;

  $db->query($query);
  $db->next_record();
  $bx->box_begin();
  $bx->box_title($db->f("name")." ".$db->f("version")." (".typestr($db->f("type")).")");
  $bx->box_body_begin();
  $timestamp = mktimestamp($db->f("modification"));
  echo "<b class=\"small\">".$t->translate("by")." <a href=\"mailto:".mailtoencode($db->f("email_usr"))."\">".$db->f("user")."</a> - ".timestr($timestamp)."</b>\n";
  echo "<p>".$db->f("description")."\n";
  echo "<table border=0 cellspacing=1 cellpadding=3 width=100% bgcolor=".$GLOBALS["th_box_body_bgcolor"].">\n";

  $db_homepage = $db->f("homepage");
  if (!empty($db_homepage)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("Homepage").":</b></td><td><a href=\"redirect.php?id=".$db->f("appid")."&type=homepage_cnt&url=".urlencode($db->f("homepage"))."\" target=_blank>".$db->f("homepage")."</a> (".$db->f("homepage_cnt")." ".$t->translate("hits").")</td></tr>\n";
  }

  $db_download = $db->f("download");
  if (!empty($db_download)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("Download").":</b></td><td width=75%><a href=\"redirect.php?id=".$db->f("appid")."&type=download_cnt&url=".urlencode($db->f("download"))."\" target=_blank>".$db->f("download")."</a> (".$db->f("download_cnt")." ".$t->translate("hits").")</td></tr>\n";
  }

  $db_changelog = $db->f("changelog");
  if (!empty($db_changelog)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("Changelog").":</b></td><td><a href=\"redirect.php?id=".$db->f("appid")."&type=changelog_cnt&url=".urlencode($db->f("changelog"))."\" target=_blank>".$db->f("changelog")."</a> (".$db->f("changelog_cnt")." ".$t->translate("hits").")</td></tr>\n";
  }

  $db_rpm = $db->f("rpm");
  if (!empty($db_rpm)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("RPM Package").":</b></td><td><a href=\"redirect.php?id=".$db->f("appid")."&type=rpm_cnt&url=".urlencode($db->f("rpm"))."\" target=_blank>".$db->f("rpm")."</a> (".$db->f("rpm_cnt")." ".$t->translate("hits").")</td></tr>\n";
    }

  $db_deb = $db->f("deb");
  if (!empty($db_deb)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("Debian Package").":</b></td><td><a href=\"redirect.php?id=".$db->f("appid")."&type=deb_cnt&url=".urlencode($db->f("deb"))."\" target=_blank>".$db->f("deb")."</a> (".$db->f("deb_cnt")." ".$t->translate("hits").")</td></tr>\n";
  }

  $db_tgz = $db->f("tgz");
  if (!empty($db_tgz)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("Slackware Package").":</b></td><td><a href=\"redirect.php?id=".$db->f("appid")."&type=tgz_cnt&url=".urlencode($db->f("tgz"))."\" target=_blank>".$db->f("tgz")."</a> (".$db->f("tgz_cnt")." ".$t->translate("hits").")</td></tr>\n";
  }

  $db_cvs = $db->f("cvs");
  if (!empty($db_cvs)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("SCM Tree").":</b></td><td><a href=\"redirect.php?id=".$db->f("appid")."&type=cvs_cnt&url=".urlencode($db->f("cvs"))."\" target=_blank>".$db->f("cvs")."</a> (".$db->f("cvs_cnt")." ".$t->translate("hits").")</td></tr>\n";
  }

  $db_screenshots = $db->f("screenshots");
  if (!empty($db_screenshots)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("Screenshots").":</b></td><td><a href=\"redirect.php?id=".$db->f("appid")."&type=screenshots_cnt&url=".urlencode($db->f("screenshots"))."\" target=_blank>".$db->f("screenshots")."</a> (".$db->f("screenshots_cnt")." ".$t->translate("hits").")</td></tr>\n";
  }

  $db_mailarch = $db->f("mailarch");
  if (!empty($db_mailarch)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("Mailing List Archive").":</b></td><td><a href=\"redirect.php?id=".$db->f("appid")."&type=mailarch_cnt&url=".urlencode($db->f("mailarch"))."\" target=_blank>".$db->f("mailarch")."</a> (".$db->f("mailarch_cnt")." ".$t->translate("hits").")</td></tr>\n";
  }

  echo "<tr valign=top><td align=right><b>".$t->translate("Type").":</b></td>\n";
  echo "<td>".typestr($db->f("type"))."</td>\n";
  echo "</tr>\n";
  echo "<tr valign=top><td align=right><b>".$t->translate("Version").":</b></td><td>".$db->f("version")."</td></tr>\n";
  echo "<tr valign=top><td align=right><b>".$t->translate("Author").":</b></td><td>";
  echo $db->f("developer");

  $db_email = $db->f("email");
  if (!empty($db_email)) echo " &lt;<a href=\"mailto:".mailtoencode($db->f("email"))."\">".ereg_replace("@"," at ",htmlentities($db->f("email")))."</a>&gt;";
  echo "</td></tr>\n";

  $db2 = new DB_SourceWell;
  $db2->query("SELECT * FROM licenses WHERE license='".$db->f("license")."'");
  $db2->next_record();
  echo "<tr valign=top><td align=right><b>".$t->translate("License").":</b></td><td><a href=\"".$db2->f("url")."\" target=_blank>".$db->f("license")."</a>&nbsp;</td></tr>\n";

  echo "<tr valign=top><td align=right><b>".$t->translate("Section/Category").":</b></td><td><a href=\"".$sess->url("appbycat.php").$sess->add_query(array("section" => $db->f("section"), "category" => $db->f("category")))."\">".$db->f("section")."/".$db->f("category")."</a></td></tr>\n";

  $db_depend = $db->f("depend");
  if (!empty($db_depend)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("Depends on").":</b></td><td>".$db->f("depend")."</td></tr>\n";
  }

  $db_urgency = $db->f("urgency");
  if ($db_urgency == 0)	$db_urgency = 2;
    echo "<tr valign=top><td align=right><b>".$t->translate("Urgency").":</b></td><td>".$t->translate(urgency($db_urgency))."</td></tr>\n";
    echo "<tr><td align=right><b>".$t->translate("Application ID").":</b></td><td><a href=\"".$sess->url("appbyid.php").$sess->add_query(array("id" => $db->f("appid")))."\">".$db->f("appid")."</a> (".$db->f("app_cnt")." ".$t->translate("hits").")</td></tr>\n";

    $db_status = $db->f("status");
    switch ($db_status) {
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

    $db2->query("SELECT * FROM history WHERE appid=".$db->f("appid")." ORDER BY creation_his DESC LIMIT 20");
    $i = 0;
    while ($db2->next_record()) {
      $timestamp = mktimestamp($db2->f("creation_his"));      
      if ($i == 0) {
        echo "<tr valign=top><td align=right valign=top><b>".$t->translate("Announcements").":</b></td><td>";
      } else {
        echo "<br>";
      }
      echo $db2->f("version_his")." ".$t->translate("by")." ".$db2->f("user_his")." ".$t->translate("on")." ".timestr($timestamp)."\n";
      $i += 1;
    }

    $db2->query("SELECT * FROM software WHERE developer='".addslashes($db->f("developer"))."' AND appid!='".$db->f("appid")."' AND status='A'");

    $i = 0;
    while ($db2->next_record()) {
      if ($i == 0) {
        echo "<tr valign=top><td align=right valign=top><b>".$t->translate("Others by Author").":</b></td><td>";
      } else {
        echo "<br>";
      }
      echo "<a href=\"".$sess->url("appbyid.php").$sess->add_query(array("id" => $db2->f("appid")))."\">".$db2->f("name")." ".$db2->f("version")."</a> (".typestr($db2->f("type")).")\n";
      $i++;
    }
    echo "</td></tr></table>\n";
    $bx->box_body_end();
    $bx->box_title_begin();
    echo "<b><a href=\"".$sess->url("updapp.php").$sess->add_query(array("id" => $db->f("appid")))."\" class=\"small\"><img src=\"images/recycled.png\" border=0 alt=\"".$t->translate("Update")."\">&nbsp;".$t->translate("Update")."</a>&nbsp;&nbsp;<a href=\"".$sess->url("cmtapp.php").$sess->add_query(array("id" => $db->f("appid")))."\" class=\"small\"><img src=\"images/txt.png\" border=0 alt=\"".$t->translate("Comment")."\">&nbsp;".$t->translate("Comment")."</a></b>\n";
   $bx->box_title_end();
   $bx->box_end();
}

#
# apppend: Shows information stored about a pending app
#

function apppend($query) {
  global $bx, $t, $sess, $db;

  $db->query($query);
  $db->next_record();
  $bx->box_begin();
  $bx->box_title($db->f("name")." ".$db->f("version")." (".typestr($db->f("type")).")");
  $bx->box_body_begin();
  $timestamp = mktimestamp($db->f("modification"));
  echo "<b class=\"small\">".$t->translate("by")." <a href=\"mailto:".mailtoencode($db->f("email_usr"))."\">".$db->f("user")."</a> - ".timestr($timestamp)."</b>\n";
  echo "<p>".$db->f("description")."\n";
  echo "<table border=0 cellspacing=1 cellpadding=3 width=100% bgcolor=".$GLOBALS["th_box_body_bgcolor"].">\n";

  $db_homepage = $db->f("homepage");
  if (!empty($db_homepage)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("Homepage").":</b></td><td><a href=\"redirect.php?id=".$db->f("appid")."&type=homepage_cnt&url=".urlencode($db->f("homepage"))."\" target=_blank>".$db->f("homepage")."</a> (".$db->f("homepage_cnt")." ".$t->translate("hits").")</td></tr>\n";
  }

  $db_download = $db->f("download");
  if (!empty($db_download)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("Download").":</b></td><td width=75%><a href=\"redirect.php?id=".$db->f("appid")."&type=download_cnt&url=".urlencode($db->f("download"))."\" target=_blank>".$db->f("download")."</a> (".$db->f("download_cnt")." ".$t->translate("hits").")</td></tr>\n";
  }

  $db_changelog = $db->f("changelog");
  if (!empty($db_changelog)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("Changelog").":</b></td><td><a href=\"redirect.php?id=".$db->f("appid")."&type=changelog_cnt&url=".urlencode($db->f("changelog"))."\" target=_blank>".$db->f("changelog")."</a> (".$db->f("changelog_cnt")." ".$t->translate("hits").")</td></tr>\n";
  }

  $db_rpm = $db->f("rpm");
  if (!empty($db_rpm)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("RPM Package").":</b></td><td><a href=\"redirect.php?id=".$db->f("appid")."&type=rpm_cnt&url=".urlencode($db->f("rpm"))."\" target=_blank>".$db->f("rpm")."</a> (".$db->f("rpm_cnt")." ".$t->translate("hits").")</td></tr>\n";
    }

  $db_deb = $db->f("deb");
  if (!empty($db_deb)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("Debian Package").":</b></td><td><a href=\"redirect.php?id=".$db->f("appid")."&type=deb_cnt&url=".urlencode($db->f("deb"))."\" target=_blank>".$db->f("deb")."</a> (".$db->f("deb_cnt")." ".$t->translate("hits").")</td></tr>\n";
  }

  $db_tgz = $db->f("tgz");
  if (!empty($db_tgz)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("Slackware Package").":</b></td><td><a href=\"redirect.php?id=".$db->f("appid")."&type=tgz_cnt&url=".urlencode($db->f("tgz"))."\" target=_blank>".$db->f("tgz")."</a> (".$db->f("tgz_cnt")." ".$t->translate("hits").")</td></tr>\n";
  }

  $db_cvs = $db->f("cvs");
  if (!empty($db_cvs)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("SCM Tree").":</b></td><td><a href=\"redirect.php?id=".$db->f("appid")."&type=cvs_cnt&url=".urlencode($db->f("cvs"))."\" target=_blank>".$db->f("cvs")."</a> (".$db->f("cvs_cnt")." ".$t->translate("hits").")</td></tr>\n";
  }

  $db_screenshots = $db->f("screenshots");
  if (!empty($db_screenshots)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("Screenshots").":</b></td><td><a href=\"redirect.php?id=".$db->f("appid")."&type=screenshots_cnt&url=".urlencode($db->f("screenshots"))."\" target=_blank>".$db->f("screenshots")."</a> (".$db->f("screenshots_cnt")." ".$t->translate("hits").")</td></tr>\n";
  }

  $db_mailarch = $db->f("mailarch");
  if (!empty($db_mailarch)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("Mailing List Archive").":</b></td><td><a href=\"redirect.php?id=".$db->f("appid")."&type=mailarch_cnt&url=".urlencode($db->f("mailarch"))."\" target=_blank>".$db->f("mailarch")."</a> (".$db->f("mailarch_cnt")." ".$t->translate("hits").")</td></tr>\n";
  }

  echo "<tr valign=top><td align=right><b>".$t->translate("Type").":</b></td>\n";
  echo "<td>".typestr($db->f("type"))."</td>\n";
  echo "</tr>\n";
  echo "<tr valign=top><td align=right><b>".$t->translate("Version").":</b></td><td>".$db->f("version")."</td></tr>\n";
  echo "<tr valign=top><td align=right><b>".$t->translate("Author").":</b></td><td>";
  echo $db->f("developer");

  $db_email = $db->f("email");
  if (!empty($db_email)) echo " &lt;<a href=\"mailto:".mailtoencode($db->f("email"))."\">".ereg_replace("@"," at ",htmlentities($db->f("email")))."</a>&gt;";
  echo "</td></tr>\n";

  $db2 = new DB_SourceWell;
  $db2->query("SELECT * FROM licenses WHERE license='".$db->f("license")."'");
  $db2->next_record();
  echo "<tr valign=top><td align=right><b>".$t->translate("License").":</b></td><td><a href=\"".$db2->f("url")."\" target=_blank>".$db->f("license")."</a>&nbsp;</td></tr>\n";

  echo "<tr valign=top><td align=right><b>".$t->translate("Section/Category").":</b></td><td><a href=\"".$sess->url("appbycat.php").$sess->add_query(array("section" => $db->f("section"), "category" => $db->f("category")))."\">".$db->f("section")."/".$db->f("category")."</a></td></tr>\n";

  $db_depend = $db->f("depend");
  if (!empty($db_depend)) {
    echo "<tr valign=top><td align=right><b>".$t->translate("Depends on").":</b></td><td>".$db->f("depend")."</td></tr>\n";
  }

  $db_urgency = $db->f("urgency");
  if ($db_urgency == 0)	$db_urgency = 2;
  echo "<tr valign=top><td align=right><b>".$t->translate("Urgency").":</b></td><td>".$t->translate(urgency($db_urgency))."</td></tr>\n";
  echo "<tr><td align=right><b>".$t->translate("Application ID").":</b></td><td><a href=\"".$sess->url("appbyid.php").$sess->add_query(array("id" => $db->f("appid")))."\">".$db->f("appid")."</a> (".$db->f("app_cnt")." ".$t->translate("hits").")</td></tr>\n";

  $db_status = $db->f("status");
  switch ($db_status) {
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

  echo "</table>\n";
  $bx->box_body_end();
  $bx->box_title_begin();
  echo "<b><a href=\"".$sess->url("revapp.php").$sess->add_query(array("idx" => $db->f("idx")))."\" class=\"small\"><img src=\"images/recycled.png\" border=0 alt=\"".$t->translate("Update")."\">&nbsp;".$t->translate("Update")."</a>\n";
  $bx->box_title_end();
  $bx->box_end();
}

#
# appcat: shows the apps from a certain category
# title puts the name of the category as title of the table
# iter allows to show the apps in steps of x apps each time
#

function appcat($query,$title,$iter) {
  global $bx,$t,$db,$sess;

  $bx->box_begin();
  $bx->box_title($t->translate($title));
  $bx->box_body_begin();
  echo "<table border=0 align=center cellspacing=0 cellpadding=3 width=100%>\n";
  $i = $iter;
  $db->query($query);
  while($db->next_record()) {
    echo "<tr><td align=right valign=top width=4%><b>$i</b></td><td width=96%><b><a href=\"".$sess->url("appbyid.php").$sess->add_query(array("id" => $db->f("appid")))."\">".$db->f("name")." ".$db->f("version")."</a> (".typestr($db->f("type")).")</b>\n";
    echo "<br>".$db->f("description")."\n";
    echo "<br><b>".$t->translate("Importance").":</b> ".$db->f("sum_cnt");
    $db_urgency = $db->f("urgency");
    if ($db_urgency == 0) $db_urgency = 2;
    echo "; <b>".$t->translate("Urgency").":</b> ".$t->translate(urgency($db_urgency))."\n";
    $timeupd = mktimestamp($db->f("modification"));
    $timecre = mktimestamp($db->f("creation"));
    if (strcmp($timeupd, $timecre)) {
    echo "<br><b>".$t->translate("Updated").":</b> ".timestr($timeupd)."\n";
		}
    $timecre = mktimestamp($db->f("creation"));
    echo "<br><b>".$t->translate("Created").":</b> ".timestr($timecre)."</td>\n";
    $i++;
  }
  echo "</tr></table>\n";
  $bx->box_body_end();
  $bx->box_end();
}

## appdat($query):
##
## Display Application data

function appdat($query) {
  global $bx,$db,$sess;
  $db->query($query);
  while ($db->next_record()) {
    appd();
    $bx->box_end();
  }
}


## appupdate($query):
##
## Display Application data and Update Link

function appupdate($query) {
  global $perm, $bx, $t, $sess, $db;

  $db->query($query);
  while ($db->next_record()) {
    appd();

    $bx->box_title_begin();
    echo "<table width=100% border=0 cellspacing=0 cellpadding=3><tr valign=bottom>\n";

    $db_status = $db->f("status");
    switch ($db_status) {
      case 'P':
        echo "<td width=40%><b><a href=\"".$sess->url("revapp.php").$sess->add_query(array("idx" => $db->f("idx")))."\"<img src=\"images/recycled.png\" border=0 alt=\"".$t->translate("Review")."\">&nbsp;Review</a></b></td>\n";
        echo "<td width=60% align=right border=0><b>".$t->translate("Waiting for Review by an Editor")."</b>\n";
        break;
      case 'D':
        echo "<td width=40%><b><a href=\"".$sess->url("updapp.php").$sess->add_query(array("id" => $db->f("appid")))."\"><img src=\"images/recycled.png\" border=0 alt=\"".$t->translate("Update")."\">&nbsp;Update</a></b></td>\n";
        echo "<td width=60% align=right border=0><b>".$t->translate("Is deleted")."</b>\n";
        break;
      case 'M':
        echo "<td width=40%><b><a href=\"".$sess->url("updapp.php").$sess->add_query(array("id" => $db->f("appid")))."\"><img src=\"images/recycled.png\" border=0 alt=\"".$t->translate("Review")."\">&nbsp;Update</a></b></td>\n";
        echo "<td width=60% align=right border=0><b>".$t->translate("Is modified")."</b>\n";
        break;
      default:
        echo "<td width=100%><b><a href=\"".$sess->url("updapp.php").$sess->add_query(array("id" => $db->f("appid")))."\"><img src=\"images/recycled.png\" border=0 alt=\"".$t->translate("Update")."\">&nbsp;Update</a></b>\n";
        break;
    }
    echo "</td></tr></table>\n";
    $bx->box_title_end();
    $bx->box_end();
  }
}


## appd():
##
## Common support for functions appdat and appupdate

function appd() {
  global $bx,$t,$sess,$db;

  $bx->box_begin();
  $bx->box_title_begin();
  echo "<table border=0 cellspacing=0 cellpadding=0 width=100%>\n";
  echo "<tr valign=bottom>";
  echo "<td width=30%><b><a href=\"".$sess->url("appbyid.php").$sess->add_query(array("id" => $db->f("appid")))."\">".$db->f("name")." ".$db->f("version")."</a> (".typestr($db->f("type")).")</b></td>\n";
  echo "<td width=70% align=right>\n";

  $db_sum_cnt = $db->f("sum_cnt");
  if (isset($db_sum_cnt)) {
    echo "<img src=\"images/importance.png\" alt=\"".$t->translate("Importance")."\"><b>(".$db->f("sum_cnt").")</b>\n";
  }

  $db_urgency = $db->f("urgency");
  if ($db_urgency == 0)	$db_urgency = 2;
  echo "&nbsp;";
  for ($i = 1; $i < $db_urgency; $i++) {
    echo "<img src=\"images/bell.png\" alt=\"".$t->translate("Urgency").":".$t->translate(urgency($db_urgency))."\">";
  }

  $db_homepage = $db->f("homepage");
  if (!empty($db_homepage)) {
    echo "&nbsp;&nbsp;<a href=\"redirect.php?id=".$db->f("appid")."&type=homepage_cnt&url=".urlencode($db->f("homepage"))."\" target=_blank><img src=\"images/html.png\" border=0 alt=\"".$t->translate("Homepage")."\"></a>\n";
  }

  $db_download = $db->f("download");
  if (!empty($db_download)) {
    echo "&nbsp;&nbsp;<a href=\"redirect.php?id=".$db->f("appid")."&type=download_cnt&url=".urlencode($db->f("download"))."\" target=_blank><img src=\"images/binary2.png\" border=0 alt=\"".$t->translate("Download")."\"></a>\n";
  }

  $db_changelog = $db->f("changelog");
  if (!empty($db_changelog)) {
  echo "&nbsp;&nbsp;<a href=\"redirect.php?id=".$db->f("appid")."&type=changelog_cnt&url=".urlencode($db->f("changelog"))."\" target=_blank><img src=\"images/info.png\" border=0 alt=\"".$t->translate("Changelog")."\"></a>\n";
  }

  $db2 = new DB_SourceWell;
  $db2->query("SELECT COUNT(*) FROM comments WHERE appid='".$db->f("appid")."'");
  $db2->next_record();
  $db2_count = $db2->f("COUNT(*)");
  if ($db2_count <= 0) {
        $num = "";
    } else {
        $num = "<b>[".$db2_count."]</b>";
    }
    echo "&nbsp;&nbsp;<a href=\"".$sess->url("cmtapp.php").$sess->add_query(array("id" => $db->f("appid")))."\"><img src=\"images/txt.png\" border=0 alt=\"".$t->translate("Comments")."\"></a> $num</a>\n";

  echo "&nbsp;&nbsp;<a href=\"".$sess->url("appbycat.php").$sess->add_query(array("section" => $db->f("section"), "category" => $db->f("category")))."\"><b>".$db->f("section")."/".$db->f("category")."</b></a>\n";
  echo "</td></tr>\n";
  echo "</table>\n";
  $bx->box_title_end();
  $bx->box_body_begin();
  $timestamp = mktimestamp($db->f("modification"));
  echo "<b class=\"small\">".$t->translate("by")." <a href=\"mailto:".mailtoencode($db->f("email_usr"))."\">".$db->f("user")."</a> - ".timestr($timestamp)."</b>\n";
  echo "<p>".$db->f("description")."\n";
  $bx->box_body_end();
}


## appday($start):
##
## Display marginal Application data

function appday($start) {
  global $bx, $db, $sess;

  $where = "DATE_FORMAT(software.modification,'%Y-%m-%d')=\"$start\" AND software.status='A'";
  $db->query("SELECT appid,name,version FROM software WHERE $where ORDER BY software.modification DESC");

  if ($db->num_rows() > 0) {
    $bx->box_begin();
    $bx->box_title_begin();
    $time = mktime(0,0,0,substr($start,5,2),substr($start,8,2),substr($start,0,4));
    $start_content = strftime("%Y-%m-%d", $time);
    echo "<center><b><a href=\"".$sess->self_url().$sess->add_query(array("start" => $start_content, "days" => "1"))."\">".strftime("%A, %e. %b", $time)."</b></center></a>";

    $bx->box_title_end();
    $bx->box_body_begin();

    while($db->next_record()) {
	  echo "<div class=newsind>&#149;&nbsp;";
      echo "<a href=\"".$sess->url("appbyid.php").$sess->add_query(array("id" => $db->f("appid")))."\">".$db->f("name")." ".$db->f("version")."</a></div>\n";
    }
    $bx->box_body_end();
    $bx->box_end();
    return 1;
  } else {
    return 0;
  }
}


function updform($query,$url) {
  global $bx, $perm, $t, $db, $sess;

  $db->query($query);
  $db->next_record();

  $bx->box_begin();
  $bx->box_title($t->translate("Update Application"));
  $bx->box_body_begin();
  echo "<form action=\"".$sess->url("$url")."\" method=\"POST\">\n";
  echo "<table border=0 align=center cellspacing=0 cellpadding=3 width=100%>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Application Name")." (128):</td><td width=70%><b>".$db->f("name")."</b></td></tr>\n";
  echo "<input type=\"hidden\" name=\"name\" value=\"".htmlentities($db->f("name"),ENT_COMPAT)."\">\n";
  echo "<tr><td align=right width=30%>".$t->translate("Type").":</td><td width=70%>\n";
  echo typestr($db->f("type"))."</td></tr>\n";
  echo "<input type=\"hidden\" name=\"type\" value=\"".$db->f("type")."\">\n";
  echo "<tr><td align=right width=30%>".$t->translate("Version")." (64):</td><td width=70%><input type=\"TEXT\" name=\"version\" size=40 maxlength=64 value=\"".htmlentities($db->f("version"),ENT_COMPAT)."\"></td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Section/Category").":</td><td width=70%>\n";
  echo "<select name=\"seccat\">\n";
  seccat($db->f("section"),$db->f("category"));
  echo "</select></td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("License").":</td><td width=70%>\n";
  echo "<select name=\"license\">\n";
  license($db->f("license"));
  echo "</select></td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Homepage")." (255):</td><td width=70%><input type=\"TEXT\" name=\"homepage\" size=40 maxlength=255 value=\"".$db->f("homepage")."\">&nbsp;[<a href=\"".$db->f("homepage")."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Download")." (255):</td><td width=70%><input type=\"TEXT\" name=\"download\" size=40 maxlength=255 value=\"".$db->f("download")."\">&nbsp;[<a href=\"".$db->f("download")."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Changelog")." (255):</td><td width=70%><input type=\"TEXT\" name=\"changelog\" size=40 maxlength=255 value=\"".$db->f("changelog")."\">&nbsp;[<a href=\"".$db->f("changelog")."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("RPM Package")." (255):</td><td width=70%><input type=\"TEXT\" name=\"rpm\" size=40 maxlength=255 value=\"".$db->f("rpm")."\">&nbsp;[<a href=\"".$db->f("rpm")."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Debian Package")." (255):</td><td width=70%><input type=\"TEXT\" name=\"deb\" size=40 maxlength=255 value=\"".$db->f("deb")."\">&nbsp;[<a href=\"".$db->f("deb")."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Slackware Package")." (255):</td><td width=70%><input type=\"TEXT\" name=\"tgz\" size=40 maxlength=255 value=\"".$db->f("tgz")."\">&nbsp;[<a href=\"".$db->f("tgz")."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("SCM Tree")." (255):</td><td width=70%><input type=\"TEXT\" name=\"cvs\" size=40 maxlength=255 value=\"".$db->f("cvs")."\">&nbsp;[<a href=\"".$db->f("cvs")."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Screenshots")." (255):</td><td width=70%><input type=\"TEXT\" name=\"screenshots\" size=40 maxlength=255 value=\"".$db->f("screenshots")."\">&nbsp;[<a href=\"".$db->f("screenshots")."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Mailing List Archive")." (255):</td><td width=70%><input type=\"TEXT\" name=\"mailarch\" size=40 maxlength=255 value=\"".$db->f("mailarch")."\">&nbsp;[<a href=\"".$db->f("mailarch")."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Description")." (*):</td><td width=70%><textarea cols=40 rows=7 name=\"description\" wrap=\"virtual\" maxlength=255>".$db->f("description")."</textarea></td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Author")." (64):</td><td width=70%><input type=\"TEXT\" name=\"developer\" size=40 maxlength=64 value=\"".htmlentities($db->f("developer"),ENT_COMPAT)."\"></td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("E-Mail")." (128):</td><td width=70%><input type=\"TEXT\" name=\"email\" size=40 maxlength=128 value=\"".$db->f("email")."\">&nbsp;[<a href=\"mailto:".mailtoencode($db->f("email"))."\" target=\"_blank\">".$t->translate("Check")."</a>]</td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Depends on")." (128):</td><td width=70%><input type=\"TEXT\" name=\"depend\" size=40 maxlength=128 value=\"".$db->f("depend")."\"></td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Urgency").":</td><td width=70%>\n";
  echo "<select name=\"urgency\">\n";
  echo "<option value=1";

  $db_urgency = $db->f("urgency");
  if ($db_urgency == 1) echo " selected";
  echo ">".$t->translate("low")."\n";
  echo "<option value=2";

  if ($db_urgency == 2 || $db_urgency == 0) echo " selected";
  echo ">".$t->translate("medium")."\n";
  echo "<option value=3";

  if ($db_urgency == 3) echo " selected";
  echo ">".$t->translate("high")."\n";
  echo "</select></td></tr>\n";

  if ($perm->have_perm("editor")) {
    echo "<tr><td align=right width=30%>".$t->translate("Status").":</td><td width=70%>\n";
    switch ($db->f("status")) {
      case 'A':
        echo $t->translate("active")."\n";
        break;
      case 'P':
        echo $t->translate("pending")."\n";
        break;
      case 'D':
        echo $t->translate("deleted")."\n";
        break;
      case 'M':
        echo $t->translate("modified")."\n";
    }
    echo "</td></tr>\n";

    echo "<tr><td align=right width=30%>".$t->translate("Action").":</td><td width=70%>\n";
    echo "<select name=\"action\">\n";

    $db_status = $db->f("status");
    if ($db_status == 'P') {
      echo "<option value=\"review\"";
      echo ">".$t->translate("Review")."\n";
    } else {
      echo "<option value=\"update\"";
      echo ">".$t->translate("Update")."\n";
    }
    if ($db_status == 'D' || $db_status == 'M') {
      echo "<option value=\"undelete\"";
      echo ">".$t->translate("Undelete")."\n";
    } else {
      echo "<option value=\"delete\"";
      echo ">".$t->translate("Delete")."\n";
      if ($db_status == 'A') {
        echo "<option value=\"delete_version\"";
        echo ">".$t->translate("Delete Version")."\n";
      }
    }
    echo "</select></td></tr>\n";
    echo "<tr><td align=right width=30%>&nbsp;</td><td width=70%><input type=\"Submit\" value=\"".$t->translate("Go")."\"></td></tr>\n";
  } else {
    echo "<input type=\"hidden\" name=\"action\" value=\"update\">\n";
    echo "<tr><td align=right width=30%>&nbsp;</td><td width=70%><input type=\"Submit\" value=\"".$t->translate("Update")."\"></td></tr>\n";
  }

  echo "<input type=\"hidden\" name=\"idx\" value=\"".$db->f("idx")."\">\n";
  echo "<input type=\"hidden\" name=\"id\" value=\"".$db->f("appid")."\">\n";
  echo "<input type=\"hidden\" name=\"user\" value=\"".$db->f("user")."\">\n";
  echo "<input type=\"hidden\" name=\"creation\" value=\"".$db->f("creation")."\">\n";
  echo "<input type=\"hidden\" name=\"modification\" value=\"".$db->f("modification")."\">\n";
  echo "</form>\n";
  echo "</td></tr>\n";
  echo "</table>\n";
  $bx->box_body_end();
  $bx->box_end();
}


function insform() {
  global $sess, $bx, $t;

  $bx->box_begin();
  $bx->box_title($t->translate("Insert Application"));
  $bx->box_body_begin();
  echo "<table border=0 align=center cellspacing=0 cellpadding=3>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Application Name")." (128):</td><td width=70%><b>".stripslashes($GLOBALS["name"])."</b></td></tr>\n";
  echo "<form action=\"".$sess->url("insert.php")."\" method=\"POST\">\n";
  echo "<input type=\"hidden\" name=\"name\" value=\"".htmlentities(stripslashes($GLOBALS["name"]),ENT_COMPAT)."\">\n";
  echo "<tr><td align=right width=30%>".$t->translate("Type").":</td><td width=70%>\n";
  echo typestr($GLOBALS["type"])."</td></tr>\n";
  echo "<input type=\"hidden\" name=\"type\" value=\"".$GLOBALS["type"]."\">\n";
  echo "<tr><td align=right width=30%>".$t->translate("Version")." (64):</td><td width=70%><input type=\"TEXT\" name=\"version\" size=40 maxlength=64></td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Section/Category").":</td><td width=70%>\n";
  echo "<select name=\"seccat\">\n";
  seccat("","");
  echo "</select></td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("License").":</td><td width=70%>\n";
  echo "<select name=\"license\">\n";
  license("GPL");
  echo "</select></td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Homepage")." (255):</td><td width=70%><input type=\"TEXT\" name=\"homepage\" size=40 maxlength=255></td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Download")." (255):</td><td width=70%><input type=\"TEXT\" name=\"download\" size=40 maxlength=255></td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Changelog")." (255):</td><td width=70%><input type=\"TEXT\" name=\"changelog\" size=40 maxlength=255></td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("RPM Package")." (255):</td><td width=70%><input type=\"TEXT\" name=\"rpm\" size=40 maxlength=255></td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Debian Package")." (255):</td><td width=70%><input type=\"TEXT\" name=\"deb\" size=40 maxlength=255></td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("Slackware Package")." (255):</td><td width=70%><input type=\"TEXT\" name=\"tgz\" size=40 maxlength=255></td></tr>\n";
  echo "<tr><td align=right width=30%>".$t->translate("SCM Tree")." (255):</td><td width=70%><input type=\"TEXT\" name=\"cvs\" size=40 maxlength=255></td></tr>\n";
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
  global $sess, $bx, $t;
  $bx->box_begin();
  $bx->box_title($t->translate("Insert a Category"));
  $bx->box_body_begin();
  echo "<table border=0 align=center cellspacing=0 cellpadding=3 width=100%>\n";
  echo "<form action=\"".$sess->url("inscat.php")."\" method=\"POST\">\n";

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
//  seccat($selected_sec, $selected_cat)
//  Displays the different section/category pairs as a select form 
//  $selected_sec is the SELECTED section
//  $selected_cat is the SELECTED category

function seccat($selected_sec, $selected_cat) {
  global $db;

  $db_local = new DB_SourceWell;
  $db_local->query("SELECT * FROM categories ORDER BY section,category ASC");
  while ($db_local->next_record()) {
    $db_section = $db_local->f("section");
    $db_category = $db_local->f("category");
    echo "<option";
    if ($db_section == $selected_sec && $db_category == $selected_cat) echo " selected";
    echo ">".$db_local->f("section")."/".$db_local->f("category")."\n";
  }  
}

// 
//  sec($selected)
//  Displays the different sections as a select form 
//  $selected ist the SELECTED section
// 

function sec($selected) {
  global $db;

  $db_local = new DB_SourceWell;
  $db_local->query("SELECT DISTINCT section FROM categories ORDER BY section ASC");
  while($db_local->next_record()) {
    echo "<option";
    $db_section = $db_local->f("section");
    if ($db_section == $selected) echo " selected";
    echo ">". $db_local->f("section")."\n";
  }
}

// 
//  license ($selected)
//  Displays the different licenses as a select form 
//  $selected ist the SELECTED license
// 

function license($selected) {
  global $db;

  $db_local = new DB_SourceWell;
  $db_local->query("SELECT * FROM licenses ORDER BY license ASC");
  while ($db_local->next_record()) {
    $db_license = $db_local->f("license");
    echo "<option";
    if ($db_license == $selected) echo " selected";
    echo ">".$db_license."\n";
  }
}

// 
//  lib_select_perm($selected)
//  Displays the permissions as a select form 
//  $selected ist the SELECTED section
// 

function lib_select_perm($selected) {

  echo "<option";
  if ("user" == $selected) echo " selected";
  echo ">user\n";

  echo "<option";
  if ("editor" == $selected) echo " selected";
  echo ">editor\n";

  echo "<option";
  if ("admin" == $selected) echo " selected";
  echo ">admin\n";

  echo "<option";
  if ("all" == $selected) echo " selected";
  echo ">all\n";
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


## show_more($iter,$maxiter,$url,$urlquery)
##
## shows 10 apps of the current iteraction $iter
## until it reaches the maximum number of iteractions $maxiter
## $url is the name of the page (*.php)
## $urlquery contains an array with the paramaters for the new page
##            (everything after the ?)

function show_more($iter,$maxiter,$url,$urlquery) {
  global $sess;

  $iter /=10;
  echo "<table border=0 width=600><tr>";
  echo "<td>&nbsp;</td>\n";
  echo "<td align=right>";

  $maxiter= Floor($maxiter);

  if ($iter > 3) {
    echo "<a href=\"".$sess->url($url).$sess->add_query($urlquery).$sess->add_query(array("iter" => 0))."\">&lt;&lt;</a>\n";
  }

  $number = $iter - 3;
  if ($number < 0) $number = 0;
  if ($iter > 2) {
    echo "<a href=\"".$sess->url($url).$sess->add_query($urlquery).$sess->add_query(array("iter" => $number))."\">&lt;</a>\n";
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
    if ($i != $iter) {
      echo "<a href=\"".$sess->url($url).$sess->add_query($urlquery).$sess->add_query(array("iter" => $i))."\">&nbsp;$number</a>\n";
    }
    else echo "<B>&nbsp;$number</B>\n"; 
   }

  $number = $iter + 5 - $bias;
  if ($number > $maxiter+$bias) $number =$maxiter+$bias;
  if ($iter < $maxiter-4+$bias) {
    echo "<a href=\"".$sess->url($url).$sess->add_query($urlquery).$sess->add_query(array("iter" => $number))."\"> &gt;</a>\n";
  }

  $number = $iter + 10 - $bias;
  if ($number > $maxiter) $number = $maxiter;
  if ($iter < $maxiter-5 +$bias) {
    echo "<a href=\"".$sess->url($url).$sess->add_query($urlquery).$sess->add_query(array("iter" => $number))."\"> &gt;&gt;</a>\n";
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
  global $db;

  $db_local = new DB_SourceWell;
  $db_local->query("SELECT * FROM counter WHERE appid='$id'");

           // If application in table and first access today update counters
  $first = checkcnt($id, $GLOBALS[REMOTE_ADDR], $type);

  $db_local->next_record();
  if ($first == 1) {
    $counter = $db_local->f($type) + 1;
    $db->query("UPDATE counter SET $type='$counter' WHERE appid='$id'");
  }
}

function checkcnt($id, $ipaddr, $type) {
  global $db;

  $ret = 1;

			// Delete all entries from yesterday
  $today = date("Y-m-d");
  $tables = "counter_check";
  $where = "DATE_FORMAT(creation_cnt,'%Y-%m-%d') != '$today'";
  $db->query("DELETE FROM $tables WHERE $where");

  $columns = "*";
  $where = "appid='$id' AND cnt_type='$type' AND ipaddr='$ipaddr'";
  $db->query("SELECT $columns FROM $tables WHERE $where");

  if ($db->num_rows() > 0) {
			// If remote host already accessed the apps link,
			// don´t increase corresponding counter
    $ret = 0;
  } else {
  			  // Include entry for remote host
    $set = "appid='$id',cnt_type='$type',ipaddr='$ipaddr'";
    $db->query("INSERT $tables SET $set");
  }
  return $ret;
}

function nlmsg($period) {
  global $db;

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

  $db->query("SELECT *,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt FROM software, counter, auth_user WHERE $where AND software.appid=counter.appid AND software.user=auth_user.username AND software.status='A' GROUP BY software.appid ORDER BY software.modification DESC"); 

  if ($db->num_rows() <= 0) return 0;

  $msg = $GLOBALS["sys_name"]." $period newsletter for ".date("l, dS of F Y, H:i:s T")."\n";
  $msg .= "Number of announcements: ".$db->num_rows()."\n";
  $msg .= "\n               -----------------------------\n";
  $msg .= "                   Annoucements Headlines\n";
  $msg .= "               -----------------------------\n\n";
	
  $i = 1;
  while($db->next_record()) {
    $msg .= "$i: ".$db->f("name")." ".$db->f("version")." ";
    if ($db->f("type") == 'S') $msg .= "(Stable)\n";
    if ($db->f("type") == 'D') $msg .= "(Development)\n";
    $i++;
  }

  $msg .= "\n               -----------------------------\n";
  $msg .= "                   Annoucements Details\n";
  $msg .= "               -----------------------------\n";

//  @mysql_data_seek($result, 0);
  $db->seek(0);

  $i = 1;
  while ($db->next_record()) {
    $timestamp = mktimestamp($db->f("modification"));
    $msg .= "\nAnnouncement : $i\n";
    $msg .= "Name         : ".$db->f("name")."\n";
    $msg .= "Date         : ".date("l, dS of F Y, H:i:s T", $timestamp)."\n";
    $msg .= "Type         : ";
    if ($db->f("type") == 'S') $msg .= "Stable\n";
    if ($db->f("type") == 'D') $msg .= "Development\n";
    $msg .= "Version      : ".$db->f("version")."\n";
    if ($period == "daily") {
      $msg .= "License      : ".$db->f("license")."\n";
      $msg .= "Section      : ".$db->f("section")."\n";
      $msg .= "Category     : ".$db->f("category")."\n";
      $msg .= "Importance   : ".$db->f("sum_cnt")."\n";
      $msg .= "Urgency      : ".urgency($db->f("urgency"))."\n";
      $db_homepage = $db->f("homepage");
      $db_download = $db->f("download");
      $db_changelog = $db->f("changelog");
      $db_rpm = $db->f("rpm");
      $db_deb = $db->f("deb");
      $db_tgz = $db->f("tgz");
      $db_cvs = $db->f("cvs");
      $db_screenshots = $db->f("screenshots");
      $db_mailarch = $db->f("mailarch");
      $db_email = $db->f("email");
      $db_depend = $db->f("depend");
      if (!empty($db_homepage))
	$msg .= "\nHomepage     : ".$db->f("homepage")."\n";
      if (!empty($db_download))
	$msg .= "Download     : ".$db->f("download")."\n";
      if (!empty($db_changelog))
	$msg .= "Changelog    : ".$db->f("changelog")."\n";
      if (!empty($db_rpm))
	$msg .= "RPM Package  : ".$db->f("rpm")."\n";
      if (!empty($db_deb))
	$msg .= "Deb Package  : ".$db->f("deb")."\n";
      if (!empty($db_tgz))
	$msg .= "tgz Package  : ".$db->f("tgz")."\n";
      if (!empty($db_cvs))
	$msg .= "SCM Tree     : ".$db->f("cvs")."\n";
      if (!empty($db_screenshots))
	$msg .= "Screenshots  : ".$db->f("screenshots")."\n";
      if (!empty($db_mailarch))
	$msg .= "Mailing List Archive : ".$db->f("mailarch")."\n";
      $msg .= "\nDescription : \n".wrap($db->f("description"))."\n";
      $msg .= "\nAuthor       : ".$db->f("developer")."\n";
      if (!empty($db_email))
	$msg .= "Email        : ".$db->f("email")."\n";
      if (!empty($db_depend))
	$msg .= "Depens on    : ".$db->f("depend")."\n";
      $msg .= "\n";
    }
    $msg .= $GLOBALS["sys_name"]."   : http:".$GLOBALS["sys_url"]."appbyid.php?id=".$db->f("appid")."\n";
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
  $msg .= "\nand follow the instructions there."
  ."\n\n - ".$GLOBALS["sys_name"]." crew";

  return $msg;
}

function mailuser($perms, $subj, $message) {
  global $t, $db;
  $db->query("SELECT email_usr FROM auth_user WHERE perms LIKE '%$perms%'");
  while($db->next_record()) {
    mail($db->f("email_usr"),"[".$GLOBALS["sys_name"]."] ".$subj,$message,"From: ".$GLOBALS["ml_fromaddr"]."\nReply-To: ".$GLOBALS["ml_replyaddr"]."\nX-Mailer: PHP");
  }
}

function mailtoencode($str) {
  $ret = "";
  $arr = unpack("C*", $str);
  foreach ($arr as $char)
    $ret .= sprintf("%%%X", $char);
  return $ret;
}
?>
