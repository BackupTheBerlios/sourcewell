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


function lib_nick($nick) {
	return "<b>".$nick."</b>";
//	html_link("mailto:nomail@noplace.no","",$nick);
}

function lib_pnick($nick) {
	print lib_nick($nick);
}

#
# Shows an error when the database access fails
#

function mysql_die() {
    global $t,$be;
	if (isset($be)) {
        $be->box_full(_("Database Access failed"), mysql_errno()." : ".mysql_error());
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
# appcat: shows the apps from a certain category
# title puts the name of the category as title of the table
# iter allows to show the apps in steps of x apps each time
#

function appcat($query,$title,$iter) {
  global $bx,$t,$db,$sess;

  $bx->box_begin();
  $bx->box_title(_($title));
  $bx->box_body_begin();
  echo "<table border=0 align=center cellspacing=0 cellpadding=3 width=100%>\n";
  $i = $iter;
  $db->query($query);
  while($db->next_record()) {
    echo "<tr><td align=right valign=top width=4%><b>$i</b></td><td width=96%><b><a href=\"".$sess->url("appbyid.php3").$sess->add_query(array("id" => $db->f("appid")))."\">".$db->f("name")." ".$db->f("version")."</a> (".typestr($db->f("type")).")</b>\n";
    echo "<br>".$db->f("description")."\n";
    echo "<br><b>"._("Importance").":</b> ".$db->f("sum_cnt");
    $db_urgency = $db->f("urgency");
    if ($db_urgency == 0) $db_urgency = 2;
    echo "; <b>"._("Urgency").":</b> "._(urgency($db_urgency))."\n";
    $timeupd = mktimestamp($db->f("modification"));
    $timecre = mktimestamp($db->f("creation"));
    if (strcmp($timeupd, $timecre)) {
    echo "<br><b>"._("Updated").":</b> ".timestr($timeupd)."\n";
		}
    $timecre = mktimestamp($db->f("creation"));
    echo "<br><b>"._("Created").":</b> ".timestr($timecre)."</td>\n";
    $i++;
  }
  echo "</tr></table>\n";
  $bx->box_body_end();
  $bx->box_end();
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
    $time = mktime(0,0,0,substr($start,5,2),substr($start,8,2),substr($start,0,4));
    $start_content = strftime("%Y-%m-%d", $time);
    $bx->box_title(html_link("PHP_SELF",array("start" => $start_content, "days" => "1"),strftime("%A, %e . %b", $time)));
    $bx->box_body_begin();

    while($db->next_record()) {
      print "<li>";
      htmlp_link("app.php3", array("appid" => $db->f("appid")), $db->f("name")." ".$db->f("version"));
      print "</li>\n";
    }
    $bx->box_body_end();
    $bx->box_end();
    return 1;
  } else {
    return 0;
  }
}


function inssec($string) {
  global $sess, $bx, $t;
  $bx->box_begin();
  $bx->box_title(_("Insert a Category"));
  $bx->box_body_begin();
  echo "<table border=0 align=center cellspacing=0 cellpadding=3 width=100%>\n";
  echo "<form action=\"".$sess->url("inscat.php3")."\" method=\"POST\">\n";

  if ($string == "yes") {
		// Inserting Sections and/or Categories
    echo "<tr><td align=right>"._("Section").":</td><td><b>".$GLOBALS["section"]."</b></td></tr>\n";
    echo "<input type=\"hidden\" name=\"section\" value=\"".$GLOBALS["section"]."\">\n";

  } else {
    echo "<tr><td align=right>"._("Section").":</td><td>\n";
    echo "<select name=\"section\">\n";
    sec($GLOBALS["section"]);     // We select the first one to avoid having a blank line
    echo "</select></td></tr>\n";
  }

  echo "<tr><td align=right>"._("Category")." (64):</td><td><input type=\"TEXT\" name=\"category\" size=40 maxlength=64></td></tr>\n";
  echo "<tr><td align=right>&nbsp;</td><td><input type=\"Submit\" value=\""._("Insert")."\"></td></tr>\n";
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
  lib_urgency($int);
}

function lib_urgency($int) {
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

function lib_sort_box($name,$value) {
  global $bx, $t, $sess;

  $sort = "<center><b>"._("sorted by").": "
  ."<a href=\"".$sess->self_url().$sess->add_query(array($name => $value, "by" => "Date"))."\">"._("Date")."</a>"
  ." | <a href=\"".$sess->self_url().$sess->add_query(array($name => $value, "by" => "Importance"))."\">"._("Importance")."</a>"
  ." | <a href=\"".$sess->self_url().$sess->add_query(array($name => $value, "by" => "Urgency"))."\">"._("Urgency")."</a>"
  ." | <a href=\"".$sess->self_url().$sess->add_query(array($name => $value, "by" => "Name"))."\">"._("Name")."</a></b></center>\n";
  $bx->box_strip($sort);
}

function lib_sort_by_order($by) {
// returns the "ORDER BY" parameter for a SQL statement

  switch ($by) {
    case "Importance":
      return " ORDER BY sum_cnt DESC";
      break;			
    case "Urgency":
      return " ORDER BY software.urgency DESC";
      break;			
    case "Name":
      return " ORDER BY software.name ASC";
      break;			
    case "Date":
    default:
      $by = "Date";
      return " ORDER BY software.modification DESC";
      break;
  }
}

## show_more($iter,$maxiter,$url,$urlquery)
##
## shows 10 apps of the current iteraction $iter
## until it reaches the maximum number of iteractions $maxiter
## $url is the name of the page (*.php3)
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
		$str = _("Stable");
	if ($type == "D")
		$str = _("Development");
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
	$msg .= "CVS Tree     : ".$db->f("cvs")."\n";
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
    $msg .= $GLOBALS["sys_name"]."   : ".$GLOBALS["sys_url"]."appbyid.php3?id=".$db->f("appid")."\n";
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

function _($phrase) {
    $tmp = translate_real($phrase);
    return($tmp);
}

function is_not_set_or_empty( $val ) {
    return ( !isset( $val ) || empty( $val ) );
}

function is_set_and_not_empty( $val ) {
    // this is not the same as !is_not_set_or_empty($val) because
    // a value can be set and empty, and is_not_set_or_empty would
    // return false
    return ( isset( $val ) && !empty( $val ) );
}
?>