<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ================================================
#
# Copyright (c) 2001 by
#                Lutz Henckel (lutz.henckel@fokus.gmd.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# Statistics of the System
# some code (or some idea) has been taken from PHP-Nuke (http://php-nuke.org)
# which also lies under the GPL
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

page_open(array("sess" => "SourceWell_Session"));
if (isset($auth) && !empty($auth->auth["perm"])) {
  page_close();
  page_open(array("sess" => "SourceWell_Session",
                  "auth" => "SourceWell_Auth",
                  "perm" => "SourceWell_Perm"));
}

require("header.inc");
require("statslib.inc");

$bx = new box("95%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("80%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php

// $iter is a variable for printing the Top Statistics in steps of 10 apps
if (!isset($iter)) $iter=0;
$iter*=10;

$bx->box_begin();
$bx->box_title($t->translate("$sys_name Statistics"));
$bx->box_body_begin();

echo "<table border=0 width=100% cellspacing=0>\n";
echo "<tr><td><center><a href=\"stats.php3?option=general\">".$t->translate("General $sys_name Statistics")."</a></center></td>\n";
echo "<td><center><a href=\"stats.php3?option=apps\">".$t->translate("Apps by Importance")."</a></center></td></tr>\n";
echo "<tr><td><center><a href=\"stats.php3?option=hits\">".$t->translate("Apps by Hits")."</a></center></td>\n";
echo "<td><center><a href=\"stats.php3?option=homepage\">".$t->translate("Apps by Homepage Visits")."<tr></a></center></td></tr>\n";
echo "<tr><td><center><a href=\"stats.php3?option=download\">".$t->translate("Apps by Downloads")."</a></center></td>\n";
echo "<td><center><a href=\"stats.php3?option=rpm\">".$t->translate("Top downloaded RPM Packages")."</a></center></td></tr>\n";
echo "<tr><td><center><a href=\"stats.php3?option=deb\">".$t->translate("Top downloaded Debian Packages")."</a></center></td>\n";
echo "<td><center><a href=\"stats.php3?option=tgz\">".$t->translate("Top downloaded Slackware Packages")."</a></center></td></tr>\n";
echo "</td></tr>\n";
echo "<tr><td><center><a href=\"stats.php3?option=urgency\">".$t->translate("Apps and Downloads by Urgency")."</a></center></td>\n";
echo "<td><center><a href=\"stats.php3?option=version_type\">".$t->translate("Apps and Downloads by Version Types")."</a></center></td></tr>\n";
echo "<tr><td><center><a href=\"stats.php3?option=sections\">".$t->translate("Apps and Importance by Sections")."</a></center></td>\n";
echo "<td><center><a href=\"stats.php3?option=categories\">".$t->translate("Apps by Categories")."</a></center></td></tr>\n";
echo "<tr><td><center><a href=\"stats.php3?option=version_number\">".$t->translate("Apps by Version Numbers")."</a></center></td>\n";
echo "<td><center><a href=\"stats.php3?option=format\">".$t->translate("Apps and Downloads by Package Formats")."</a></center></td></tr>\n";
echo "<tr><td><center><a href=\"stats.php3?option=importance_license\">".$t->translate("Importance by Licenses")."</a></center></td>\n";
echo "<td><center><a href=\"stats.php3?option=importance_email\">".$t->translate("Importance by Email Domains")."</a></center></td></tr>\n";
echo "<tr><td><center><a href=\"stats.php3?option=email\">".$t->translate("Apps by Email Domains")."</a></center></td>\n";
echo "<td><center><a href=\"stats.php3?option=email_section\">".$t->translate("Apps by Sections and Email Domains")."</a></center></td></tr>\n";
echo "<tr><td><center><a href=\"stats.php3?option=licenses\">".$t->translate("Apps by Licenses")."</a></center></td>\n";
echo "<td><center><a href=\"stats.php3?option=email_license\">".$t->translate("Apps by Licenses and Email Domains")."</a></center></td><tr>\n";
echo "</table>\n";

$bx->box_body_end();
$bx->box_end();


if (isset($option)) {
 $db = new DB_SourceWell;

// We need to know the total number of apps for certain stats

$result_total = mysql_db_query($db_name,"SELECT COUNT(*) FROM software");
  $row_total = mysql_fetch_row($result_total);
  $numiter = ($row_total[0]/10);
  mysql_free_result($result_total);

  switch($option) {

// General stats

    case "general":

	$bx->box_begin();
	$bx->box_title($t->translate("General $sys_name Statistics"));
	$bx->box_body_begin();

    echo "<CENTER><table border=0 width=90% align=center cellspacing=0>\n";

    // Total number of apps
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software");
       echo "<tr><td width=85%>&nbsp;".$t->translate("Number of Applications in $sys_name")."</td>\n";
       $row = mysql_fetch_row($result);
       echo "<td width=20% align=right>".$row[0]."</td></tr>\n";
       mysql_free_result($result);
       $total = $row[0];

    // Total number of insertions or modifications
      echo "<tr><td>&nbsp;</td><td>&nbsp;</td></tr>\n";
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM history");
       echo "<tr><td width=85%>&nbsp;".$t->translate("Total Number of Insertions and Modifications")."</td>\n";
       $row = mysql_fetch_row($result);
       echo "<td width=20% align=right>".$row[0]."</td></tr>\n";
       mysql_free_result($result);

    // Number of inserted or modified Apps during the last week
    $day=7;
    $where = "DATE_FORMAT(software.modification,'%Y-%m-%d')>=DATE_SUB(CURRENT_DATE,INTERVAL \"$day\" DAY) AND software.status='A'";
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE $where");
       echo "<tr><td width=85%>&nbsp;".$t->translate("Number of Insertions and Modifications during the last week")."</td>\n";
       $row = mysql_fetch_row($result);
       echo "<td width=20% align=right>".$row[0]."</td></tr>\n";
       mysql_free_result($result);

    // Total number of pending apps 
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE status='P'");
       echo "<tr><td width=85%>&nbsp;".$t->translate("Number of pending Applications")."</td>\n";
       $row = mysql_fetch_row($result);
       echo "<td width=20% align=right>".$row[0]."</td></tr>\n";
       mysql_free_result($result);

    // Number of authorised users
      echo "<tr><td>&nbsp;</td><td>&nbsp;</td></tr>\n";
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM auth_user");
       echo "<tr><td width=85%>&nbsp;".$t->translate("Number of $sys_name authorised Users")."</td>\n";
       $row = mysql_fetch_row($result);
       echo "<td width=20% align=right>".$row[0]."</td></tr>\n";
       mysql_free_result($result);

    // Total number of comments
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM comments");
       echo "<tr><td width=85%>&nbsp;".$t->translate("Number of Comments on Applications")."</td>\n";
       $row = mysql_fetch_row($result);
       echo "<td width=20% align=right>".$row[0]."</td></tr>\n";
       mysql_free_result($result);

    // Total number of Licenses
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM licenses");
       echo "<tr><td width=85%>&nbsp;".$t->translate("Number of Licenses listed in $sys_name")."</td>\n";
       $row = mysql_fetch_row($result);
       $row[0]-=1; 				// We don't add the license type "Other"
       echo "<td width=20% align=right>".$row[0]."</td></tr>\n";
       mysql_free_result($result);

    // Total number of SourceWell sections
    $result = mysql_db_query($db_name,"SELECT DISTINCT section FROM categories");
       echo "<tr><td width=85%>&nbsp;".$t->translate("Number of $sys_name Sections")."</td>\n";
       $row = mysql_affected_rows();
       echo "<td width=20% align=right>".$row."</td></tr>\n";

    // Total number of SourceWell categories
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM categories");
       echo "<tr><td width=85%>&nbsp;".$t->translate("Number of $sys_name Categories")."</td>\n";
       $row = mysql_fetch_row($result);
       echo "<td width=20% align=right>".$row[0]."</td></tr>\n";
       mysql_free_result($result);

    // Total number of Hits
    echo "<tr><td>&nbsp;</td><td>&nbsp;</td></tr>\n";
    $result = mysql_db_query($db_name,"SELECT SUM(app_cnt) FROM counter");
       echo "<tr><td width=85%>&nbsp;".$t->translate("Total Number of Hits on Applications")."</td>\n";
       $row = mysql_fetch_row($result);
       echo "<td width=20% align=right>".$row[0]."</td></tr>\n";
       mysql_free_result($result);

    // Total number of redirected Homepages
    $result = mysql_db_query($db_name,"SELECT SUM(homepage_cnt) FROM counter");
       echo "<tr><td width=85%>&nbsp;".$t->translate("Number of redirected Homepages")."</td>\n";
       $row = mysql_fetch_row($result);
       echo "<td width=20% align=right>".$row[0]."</td></tr>\n";
       mysql_free_result($result);

    // Total number of Downloads
    $result = mysql_db_query($db_name,"SELECT SUM(download_cnt+rpm_cnt+deb_cnt+tgz_cnt) AS sum_cnt FROM counter");
       echo "<tr><td width=85%>&nbsp;".$t->translate("Number of Downloads")."</td>\n";
       $row = mysql_fetch_row($result);
       echo "<td width=20% align=right>".$row[0]."</td></tr>\n";
       mysql_free_result($result);

    // Total number of redirected Changelogs
    $result = mysql_db_query($db_name,"SELECT SUM(changelog_cnt) FROM counter");
       echo "<tr><td width=85%>&nbsp;".$t->translate("Number of redirected Changelogs")."</td>\n";
       $row = mysql_fetch_row($result);
       echo "<td width=20% align=right>".$row[0]."</td></tr>\n";
       mysql_free_result($result);

    // Total number of redirected CVSs
    $result = mysql_db_query($db_name,"SELECT SUM(cvs_cnt) FROM counter");
       echo "<tr><td width=85%>&nbsp;".$t->translate("Number of redirected CVSs")."</td>\n";
       $row = mysql_fetch_row($result);
       echo "<td width=20% align=right>".$row[0]."</td></tr>\n";
//       mysql_free_result($result);
// The last one doesn't need to free memory as it is done at the end of this page

    // Total number of redirected ScreenShots
    $result = mysql_db_query($db_name,"SELECT SUM(screenshots_cnt) FROM counter");
       echo "<tr><td width=85%>&nbsp;".$t->translate("Number of redirected Screenshots")."</td>\n";
       $row = mysql_fetch_row($result);
       echo "<td width=20% align=right>".$row[0]."</td></tr>\n";
       mysql_free_result($result);

    // Total number of redirected Mailing List Archives
    $result = mysql_db_query($db_name,"SELECT SUM(mailarch_cnt) FROM counter");
       echo "<tr><td width=85%>&nbsp;".$t->translate("Number of redirected Mailing Lists Archives")."</td>\n";
       $row = mysql_fetch_row($result);
       echo "<td width=20% align=right>".$row[0]."</td></tr>\n";
//       mysql_free_result($result);
// The last one doesn't need to free memory as it is done at the end of this page

     // SourceWell Version
        echo "<tr><td>&nbsp;</td><td>&nbsp;</td></tr>\n";
	echo "<tr><td width=85%>&nbsp;".$t->translate("$sys_name Version")."</td>\n";
       $row = mysql_fetch_row($result);
       echo "<td width=20% align=right>".$SourceWell_Version."</td></tr>\n";

    echo "</td></tr>\n";
    echo "</table></CENTER>\n";
	$bx->box_body_end();
	$bx->box_end();

    break;


    // Top Apps
    case "apps":
    $columns = "*,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt";
    $tables = "software,counter";
    $where = "software.appid=counter.appid AND software.status='A' GROUP BY software.appid";
    $order = "sum_cnt DESC LIMIT ".$iter.",10";

    if (!$result = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where ORDER BY $order")) {
        mysql_die();
    } else {
        $var = "sum_cnt";
	$message = "Applications listed by their Importance";
	stats($result,$var,$message,$iter);

        $url = "stats.php3?option=apps&";
        show_more ($iter,$numiter,$url);
    }

    break;

// Top Downloaded Apps
    case "download":
    $columns = "*";
    $tables = "software,counter";
    $where = "software.appid=counter.appid AND software.status='A'";
    $order = "counter.download_cnt DESC LIMIT ".$iter.",10";

    if (!$result = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where ORDER BY $order")) {
        mysql_die();
    } else {
        $var = "download_cnt";
	$message = "Applications listed by Number of Tarball-Downloads";
	stats($result,$var,$message,$iter);

        $url = "stats.php3?option=download&";
        show_more ($iter,$numiter,$url);
    }

    break;

// Top Apps by Hits
    case "hits":
    $columns = "*";
    $tables = "software,counter";
    $where = "software.appid=counter.appid AND software.status='A'";
    $order = "counter.app_cnt DESC limit ".$iter.",10";

    if (!$result = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where ORDER BY $order")) {
        mysql_die();
    } else {
        $var = "app_cnt";
	$message = "Applications listed by Number of Hits";
	stats($result,$var,$message,$iter);

        $url = "stats.php3?option=hits&";
        show_more ($iter,$numiter,$url);
    }
    break;


// Top App Homepages visited
    case "homepage":
    $columns = "*";
    $tables = "software,counter";
    $where = "software.appid=counter.appid AND software.status='A'";
    $order = "counter.homepage_cnt DESC limit ".$iter.",10";

    if (!$result = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where ORDER BY $order")) {
        mysql_die();
    } else {
        $var = "homepage_cnt";
	$message = "Applications listed by Homepage Visits";
	stats($result,$var,$message,$iter);

        $url = "stats.php3?option=homepage&";
        show_more ($iter,$numiter,$url);
    }
    break;


// Top Downloaded RPMs / DEBs / SLCs
// The same (with its parameters) could be done for DEBs, TGZs, etc
    case "rpm":
    case "deb":
    case "tgz":
    $var = $option;
    $option_save = $option;
    $columns = "*";
    $tables = "software,counter";
    $where = "software.appid=counter.appid AND software.status='A'";
    $order = "counter.".$option."_cnt DESC limit ".$iter.",10";

    if (!$result = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where ORDER BY $order")) {
        mysql_die();
    } else {
        $var = $option."_cnt";
        switch ($option) {
           case "rpm": $option="Red Hat Packages"; break;
           case "deb": $option="Debian Packages"; break;
           case "tgz": $option="Slackware Packages"; break;
        }
	$message = "Top downloaded ".$option;
	stats($result,$var,$message,$iter);

        $url = "stats.php3?option=$option_save&";
        show_more ($iter,$numiter,$url);
    }
    break;

// Sections
    case "sections":

    // Total number of apps
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software");
       $row = mysql_fetch_row($result);
       $total = $row[0];

    stats_title($t->translate("Applications listed by Sections"));
    $columns = "section";
    $tables = "categories";
    if (!$result = mysql_db_query($db_name,"SELECT DISTINCT $columns FROM $tables")) {
        mysql_die();
    } else {

        while($row = mysql_fetch_array($result)) {
            $columns = "COUNT(*)";
            $tables = "software";
            $where = "section='".$row["section"]."' AND status='A'";
            $num = "0";
            if ($resultn = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where")) {
                $rown = mysql_fetch_row($resultn);
	        $num = $rown[0];
                mysql_free_result($resultn);
            }
	    $url = "categories.php3?section=".rawurlencode($row["section"])."";
	    stats_display_alt($row["section"],$num,$url,$total);
        }
    }

    stats_end();
    mysql_free_result($result);

    // Total number of importance
    $columns = "SUM(app_cnt+homepage_cnt+changelog_cnt+download_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt";
    $result = mysql_db_query($db_name,"SELECT $columns FROM counter");
    $row = mysql_fetch_row($result);
    $total = $row[0];

    stats_title($t->translate("Application Importance listed by Sections"));
    $columns = "section";
    $tables = "categories";
    if (!$result = mysql_db_query($db_name,"SELECT DISTINCT $columns FROM $tables")) {
        mysql_die();
    } else {

        while($row = mysql_fetch_array($result)) {
            $columns = "SUM(app_cnt+homepage_cnt+changelog_cnt+download_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt";
            $tables = "software,counter";
            $where = "section='".$row["section"]."' AND status='A' AND software.appid = counter.appid";
            $num = "";
            if ($resultn = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where")) {
                $rown = mysql_fetch_row($resultn);
	        $num = $rown[0];
                mysql_free_result($resultn);
            }
	    $url = "categories.php3?section=".rawurlencode($row["section"])."";
	    stats_display_alt($row["section"],$num,$url,$total);
        }
    }

    stats_end();
    break;


// Categories
    case "categories":

    // Total number of apps
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software");
       $row = mysql_fetch_row($result);
       $total = $row[0];

    stats_title($t->translate("Applications listed by Categories"));

    $columns = "section";
    $tables = "categories";
    if (!$result = mysql_db_query($db_name,"SELECT DISTINCT $columns FROM $tables")) {
        mysql_die();
    } else {
        while($row = mysql_fetch_array($result)) {
        stats_subtitle($t->translate("Section")." ".$row["section"]);
        $columns = "category";
        $tables = "categories";
        $where = "section = '".$row["section"]."'";
        $order = "category ASC";
        if (!$result2 = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where ORDER BY $order")) {
            mysql_die();
        } else {
            while($row2 = mysql_fetch_array($result2)) {
                $columns = "COUNT(*)";
                $tables = "software";
                $where = "section='".$row["section"]."' AND category='".$row2["category"]."' AND status='A'";
                $num = "";
                if ($resultn = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where")) {
                    $rown = mysql_fetch_row($resultn);
		    $num = $rown[0];
                    mysql_free_result($resultn);
                }

	    $url = "appbycat.php3?section=".$row["section"]."&category=".rawurlencode($row2["category"])."";
	    stats_display_alt($row2["category"],$num,$url,$total);

//              echo "$num <a href=\"appbycat.php3?section=".$row["section"]."&category=".rawurlencode($row2["category"])."\">".$row2["category"]."</a><br>\n";
            }
         }
         }
    stats_end();
    }
    break;


// Licenses
    case "licenses":

    // Total number of apps
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software");
       $row = mysql_fetch_row($result);
       $total = $row[0];

    stats_title($t->translate("Applications listed by Licenses"));

    $columns = "license";
    $tables = "licenses";
    if (!$result = mysql_db_query($db_name,"SELECT $columns FROM $tables ORDER BY $columns")) {
        mysql_die();
    } else {
       while($row = mysql_fetch_array($result)) {
            $columns = "COUNT(*)";
            $tables = "software";
            $where = "license='".$row["license"]."' AND status='A'";
            $num = "";
            if ($resultn = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where")) {
                $rown = mysql_fetch_row($resultn);
	        $num = $rown[0];
                mysql_free_result($resultn);
            }

            $result_license = mysql_db_query($db_name,"SELECT * FROM licenses WHERE license='".$row["license"]."'");
            $row_license = mysql_fetch_array($result_license);
	    $url = $row_license["url"];
            mysql_free_result($result_license);

	    stats_display_alt($row["license"],$num,$url,$total);
        }
    }
    stats_end();
    break;

// Licenses
    case "licenses_alt":

    stats_title($t->translate("Alt Apps By Licenses"));
    $columns = "license";
    $tables = "licenses";
    if (!$result = mysql_db_query($db_name,"SELECT $columns FROM $tables")) {
        mysql_die();
    } else {

        while($row = mysql_fetch_array($result)) {
            $columns = "COUNT(*)";
            $tables = "software";
            $where = "license='".$row["license"]."' AND status='A'";
            $num = "";
            if ($resultn = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where")) {
                $rown = mysql_fetch_row($resultn);
	        $num = $rown[0];
                mysql_free_result($resultn);
            }

            $result_license = mysql_db_query($db_name,"SELECT * FROM licenses WHERE license='".$row["license"]."'");
            $row_license = mysql_fetch_array($result_license);
	    $url = $row_license["url"];
            mysql_free_result($result_license);

            stats_display($row["license"],$num,$url);
        }
    }

    stats_end();
    break;


// Format (tarball / rpm / deb / tgz)
    case "format":

    // Total number of apps
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software");
    $row = mysql_fetch_row($result);
    mysql_free_result($result);
    $total = $row[0]*1.1;
    $url = "0"; 		// No URL in function stats_display_alt

    stats_title($t->translate("Availability of downloadable Packet Formats"));

    // TarBalls
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE software.download !=''");
            $row = mysql_fetch_row($result);
            mysql_free_result($result);
	    $num = $row[0];
	    stats_display_alt($t->translate("Tarballs"),$num,$url,$total);


    // RPMs
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE software.rpm !=''");
            $row = mysql_fetch_row($result);
            mysql_free_result($result);
	    $num = $row[0];
	    stats_display_alt($t->translate("Red Hat Packages")." (rpm)",$num,$url,$total);

    // DEBs
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE software.deb !=''");
            $row = mysql_fetch_row($result);
            mysql_free_result($result);
	    $num = $row[0];
	    stats_display_alt($t->translate("Debian Packages")." (deb)",$num,$url,$total);


    // Slackware Packages
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE software.tgz !=''");
            $row = mysql_fetch_row($result);
//            mysql_free_result($result);
// We don't need to free memory as it is the last one
// memory is freed at the end
	    $num = $row[0];
	    stats_display_alt($t->translate("Slackware Packages")." (tgz)",$num,$url,$total);

    stats_end();


    // More stats by Format

    // Total number of downloads
    $columns = "SUM(download_cnt+rpm_cnt+deb_cnt+tgz_cnt) AS sum_cnt";
    $result = mysql_db_query($db_name,"SELECT $columns FROM counter");
    $row = mysql_fetch_row($result);
    $total = $row[0];
    $url = "0"; 		// No URL in function stats_display_alt

    stats_title($t->translate("Downloads listed by Packet Formats"));

    // TarBalls
    $result = mysql_db_query($db_name,"SELECT SUM(download_cnt) FROM counter");
            $row = mysql_fetch_row($result);
            mysql_free_result($result);
	    $num = $row[0];
	    stats_display_alt($t->translate("Tarballs"),$num,$url,$total);

    // RPMs
    $result = mysql_db_query($db_name,"SELECT SUM(rpm_cnt) FROM counter");
            $row = mysql_fetch_row($result);
            mysql_free_result($result);
	    $num = $row[0];
	    stats_display_alt($t->translate("Red Hat Packages")." (rpm)",$num,$url,$total);

    // DEBs
    $result = mysql_db_query($db_name,"SELECT SUM(deb_cnt) FROM counter");
            $row = mysql_fetch_row($result);
            mysql_free_result($result);
	    $num = $row[0];
	    stats_display_alt($t->translate("Debian Packages")." (deb)",$num,$url,$total);

    // tgzs
    $result = mysql_db_query($db_name,"SELECT SUM(tgz_cnt) FROM counter");
            $row = mysql_fetch_row($result);
//            mysql_free_result($result);
// We don't need to free memory as it is the last one
// memory is freed at the end
	    $num = $row[0];
	    stats_display_alt($t->translate("Slackware Packages")." (tgz)",$num,$url,$total);

    stats_end();
    break;

// Urgency
    case "urgency":

    // Total number of apps
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software");
    $row = mysql_fetch_row($result);
    mysql_free_result($result);
    $total = $row[0];
    $url = "0"; 		// No URL in function stats_display_alt

    stats_title($t->translate("Applications listed by Urgency"));

    // High
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE software.urgency ='3'");
            $row = mysql_fetch_row($result);
            mysql_free_result($result);
	    $num = $row[0];
	    stats_display_alt($t->translate("High Urgency"),$num,$url,$total);

    // Medium
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE software.urgency ='2'");
            $row = mysql_fetch_row($result);
            mysql_free_result($result);
	    $num = $row[0];
	    stats_display_alt($t->translate("Medium Urgency"),$num,$url,$total);

    // Low
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE software.urgency ='1'");
            $row = mysql_fetch_row($result);
            mysql_free_result($result);
	    $num = $row[0];
	    stats_display_alt($t->translate("Low Urgency"),$num,$url,$total);

    stats_end();

    //
    // We look how the download of this apps looks like
    //

    // Total number of downloads
    $columns = "SUM(download_cnt+rpm_cnt+deb_cnt+tgz_cnt) AS sum_cnt";
    $result = mysql_db_query($db_name,"SELECT $columns FROM counter");
    $row = mysql_fetch_row($result);
    $total = $row[0];
    $url = "0"; 		// No URL in function stats_display_alt

    stats_title($t->translate("Downloads listed by Urgency"));

    // High
    $columns = "SUM(download_cnt+rpm_cnt+deb_cnt+tgz_cnt) AS sum_cnt";
    $result = mysql_db_query($db_name,"SELECT $columns FROM software,counter WHERE software.urgency ='3' AND software.appid = counter.appid");
            $row = mysql_fetch_row($result);
            mysql_free_result($result);
	    $num = $row[0];
	    stats_display_alt($t->translate("High Urgency"),$num,$url,$total);

    // Medium
    $columns = "SUM(download_cnt+rpm_cnt+deb_cnt+tgz_cnt) AS sum_cnt";
    $result = mysql_db_query($db_name,"SELECT $columns FROM software,counter WHERE software.urgency ='2' AND software.appid = counter.appid");
            $row = mysql_fetch_row($result);
            mysql_free_result($result);
	    $num = $row[0];
	    stats_display_alt($t->translate("Medium Urgency"),$num,$url,$total);

    // Low
    $columns = "SUM(download_cnt+rpm_cnt+deb_cnt+tgz_cnt) AS sum_cnt";
    $result = mysql_db_query($db_name,"SELECT $columns FROM software,counter WHERE software.urgency ='1' AND software.appid = counter.appid");
            $row = mysql_fetch_row($result);
//            mysql_free_result($result);
// We don't need to free memory as it is the last one
// memory is freed at the end
	    $num = $row[0];
	    stats_display_alt($t->translate("Low Urgency"),$num,$url,$total);

    stats_end();

    break;


// Type (Stable / Development)
    case "version_type":

    // Total number of apps
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software");
    $row = mysql_fetch_row($result);
    mysql_free_result($result);
    $total = $row[0];
    $url = "0"; 		// No URL in function stats_display_alt

    stats_title($t->translate("Applications listed by Version Type"));

    // Stable
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE software.type ='S'");
            $row = mysql_fetch_row($result);
            mysql_free_result($result);
	    $num = $row[0];
	    stats_display_alt($t->translate("Stable Version"),$num,$url,$total);

    // Development
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE software.type ='D'");
            $row = mysql_fetch_row($result);
            mysql_free_result($result);
	    $num = $row[0];
	    stats_display_alt($t->translate("Development Version"),$num,$url,$total);

    stats_end();
    //
    // We look how the download of this apps looks like
    //

    // Total number of downloads
    $columns = "SUM(download_cnt+rpm_cnt+deb_cnt+tgz_cnt) AS sum_cnt";
    $result = mysql_db_query($db_name,"SELECT $columns FROM counter");
    $row = mysql_fetch_row($result);
    $total = $row[0];
    $url = "0"; 		// No URL in function stats_display_alt

    stats_title($t->translate("Downloads listed by Version Type"));

    // Stable
    $columns = "SUM(download_cnt+rpm_cnt+deb_cnt+tgz_cnt) AS sum_cnt";
    $result = mysql_db_query($db_name,"SELECT $columns FROM software,counter WHERE software.type ='S' AND software.appid = counter.appid");
            $row = mysql_fetch_row($result);
            mysql_free_result($result);
	    $num = $row[0];
	    stats_display_alt($t->translate("Stable Version"),$num,$url,$total);

    // Development
    $result = mysql_db_query($db_name,"SELECT $columns FROM software,counter WHERE software.type ='D' and software.appid = counter.appid");
            $row = mysql_fetch_row($result);
//            mysql_free_result($result);
// We don't need to free memory as it is the last one
// memory is freed at the end
	    $num = $row[0];
	    stats_display_alt($t->translate("Development Version"),$num,$url,$total);

    stats_end();

    break;


// Importance by License
    case "importance_license":

    // Total number of importance
    $columns = "SUM(app_cnt+homepage_cnt+changelog_cnt+download_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt";
    $result = mysql_db_query($db_name,"SELECT $columns FROM counter");
    $row = mysql_fetch_row($result);
    $total = $row[0];

    stats_title($t->translate("Application Importance listed by Licenses"));

    $columns = "license";
    $tables = "licenses";
    if (!$result = mysql_db_query($db_name,"SELECT $columns FROM $tables ORDER BY license")) {
        mysql_die();
    } else {
       while($row = mysql_fetch_array($result)) {
            $columns = "SUM(app_cnt+homepage_cnt+changelog_cnt+download_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt";
            $tables = "software,counter";
            $where = "license='".$row["license"]."' AND status='A' AND software.appid=counter.appid";
            $num = "";
            if ($resultn = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where")) {
                $rown = mysql_fetch_row($resultn);
	        $num = $rown[0];
                mysql_free_result($resultn);
            }

            $result_license = mysql_db_query($db_name,"SELECT * FROM licenses WHERE license='".$row["license"]."'");
            $row_license = mysql_fetch_array($result_license);
	    $url = $row_license["url"];
            mysql_free_result($result_license);

	    if (!isset($num)) $num = 0;
	    stats_display_alt($row["license"],$num,$url,$total);
        }
    }
    stats_end();
    break;

// Apps by Email from Developer
    case "importance_email":

    // Total number of importance
    $columns = "SUM(app_cnt+homepage_cnt+changelog_cnt+download_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt";
    $result = mysql_db_query($db_name,"SELECT $columns FROM counter");
    $row = mysql_fetch_row($result);
    $total = $row[0];

    $url = "0"; 		// No URL in function stats_display_alt
    stats_title($t->translate("Application Importance listed by Developer's Email Domains"));
 
   for($i=1;$i<sizeof($domain_country);$i++) {
      $num = 0;
      $like = "'%.".$domain_country[$i][0]."'";
      if (!$resultn = mysql_db_query($db_name,"Select * from software WHERE software.status='A' AND email LIKE $like")) {
        mysql_die();
      } else {
          while($rown = mysql_fetch_array($resultn)) {
             $where = $rown["appid"]."=counter.appid";
             $columns = "SUM(app_cnt+homepage_cnt+changelog_cnt+download_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt";

             $result2 = mysql_db_query($db_name,"SELECT $columns FROM counter WHERE $where");
             $row2 = mysql_fetch_row($result2);
             mysql_free_result($result2);
             $num = $num + $row2[0]; 
          }
      
          if (100 * $num/$total > $MinimumAppsByEmail) stats_display_alt($domain_country[$i][1],$num,$url,$total); 
      }
   }  
   stats_end(); 
   break;


// Apps by Email from Developer
    case "email":

    // Total number of apps
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software");
       $row = mysql_fetch_row($result);
       $total = $row[0];

    $url = "0"; 		// No URL in function stats_display_alt
    stats_title($t->translate("Applications listed by Developer's Email Domain"));
 
   for($i=1;$i<sizeof($domain_country);$i++) {
    $like = "'%.".$domain_country[$i][0]."'";
    if ($resultn = mysql_db_query($db_name,"Select COUNT(*) from software WHERE email LIKE $like")) {
        $num = "";
        $rown = mysql_fetch_row($resultn);
        $num = $rown[0];
        mysql_free_result($resultn);
       
        if (100 * $num/$total > $MinimumAppsByEmail) stats_display_alt($domain_country[$i][1],$num,$url,$total);
     }
    }  
    stats_end();
    break;

// Sections by Email from Developer
    case "email_section":

    $url = "0"; 		// No URL in function stats_display_alt
    stats_title($t->translate("Applications listed by Sections and Developer's Email Domain"));
 
    $columns = "section";
    $tables = "categories";
    if (!$result = mysql_db_query($db_name,"SELECT DISTINCT $columns FROM $tables")) {
        mysql_die();
    } else {
        while($row = mysql_fetch_array($result)) {
        stats_subtitle($t->translate("Section")." ".$row["section"]);
        $where = "section = '".$row["section"]."'";

        // Total number of apps in the Section
        $result2 = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE $where");
         $row2 = mysql_fetch_row($result2);
         $total = $row2[0];
          mysql_free_result($result2);

        for($i=1;$i<sizeof($domain_country);$i++) {
           $like = "'%.".$domain_country[$i][0]."'";
           if ($resultn = mysql_db_query($db_name,"Select COUNT(*) FROM software WHERE $where AND email LIKE $like")) {
              $num = "";
              $rown = mysql_fetch_row($resultn);
              $num = $rown[0];
              mysql_free_result($resultn);

	      $epsilon = 0.0001;    // to avoid having division by zero       
              if (100 * $num/($total+$epsilon) > $MinimumSeccByEmail) stats_display_alt($domain_country[$i][1],$num,$url,$total);
            }
         }
      } 
    }  
    stats_end();
    break;

// Licenses by Email from Developer
    case "email_license":

    $url = "0"; 		// No URL in function stats_display_alt
    stats_title($t->translate("Applications listed by Licenses and Developer's Email Domain"));
 
    $columns = "license";
    $tables = "licenses";
    if (!$result = mysql_db_query($db_name,"SELECT $columns FROM $tables")) {
        mysql_die();
    } else {
        while($row = mysql_fetch_array($result)) {
//        stats_subtitle($t->translate("License")." ".$row["license"]);
        $where = "license = '".$row["license"]."'";

        // Total number of apps with that License
        $result2 = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE $where");
         $row2 = mysql_fetch_row($result2);
         $total = $row2[0];
          mysql_free_result($result2);
        if ($total > $Minimum_apps_in_license) {
          stats_subtitle($row["license"]);
          for($i=1;$i<sizeof($domain_country);$i++) {
             $like = "'%.".$domain_country[$i][0]."'";
             if ($resultn = mysql_db_query($db_name,"Select COUNT(*) FROM software WHERE $where AND email LIKE $like")) {
                $num = "";
                $rown = mysql_fetch_row($resultn);
                $num = $rown[0];
                mysql_free_result($resultn);
       
                if (100 * $num/$total > $MinimumLicByEmail) stats_display_alt($domain_country[$i][1],$num,$url,$total);
              }
           }
        }
      } 
    }  
    stats_end();
    break;

// Version Number by Apps
    case "version_number":

    // Total number of apps
    $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM software");
       $row = mysql_fetch_row($result);
       $total = $row[0];

    $url = "0"; 		// No URL in function stats_display_alt
    stats_title($t->translate("Applications listed by Version Numbers"));
 
   for($i=0;$i<30;$i++) {
    $like = "'".$i.".%'";
    if ($resultn = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE version LIKE $like")) {
        $num = "";
        $rown = mysql_fetch_row($resultn);
        $num = $rown[0];
        mysql_free_result($resultn);
       
        if (100 * $num/$total > 0) stats_display_alt($t->translate("Version Number").": ".$i.".x",$num,$url,$total);
     }
    }  
    stats_end();
    break;

// Ending...
  }
 
       mysql_free_result($result);
}


?>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>
