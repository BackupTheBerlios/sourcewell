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
# This file proceeds search of applications by their name
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

require("header2.inc");
//require("app2.inc");

security_page_access("appsearch");

$bx = new box("general","96%");


      // When there's a search for a blank line, we look for "xxxxxxxx"
if (!isset($search) || $search=="") {
  $search = "xxxxxxxx";
}

// $iter is a variable for printing the Top Statistics in steps of 10 apps
if (!isset($iter)) $iter=0;
else $iter*=10;

// FIXME: apps that appear in superior matches should not be repeated
// TODO: does it make sense to show so much information? 
// WISH: have a navigation bar with the different options

// 1a Section
$db->query("SELECT DISTINCT(section) FROM categories WHERE section='$search'");
if ($db->num_rows() > 0) {
        $db->next_record();
        $bx->box_strip("See also Section ".html_link("categories.php3",array(section => $db->f("section")),$db->f("section")));
}

// 1b Category
$db->query("SELECT * FROM categories WHERE category='$search'");
if ($db->num_rows() > 0) {
    while($db->next_record()) {
        $bx->box_strip("See also Category ".html_link("appbycat.php3",array(section => $db->f("section"), category => $db->f("category")),$db->f("section")."/".$db->f("category")));
    }
}

// 2. Exact match
$query = "SELECT * FROM software,counter WHERE software.appid=counter.appid AND software.status='A' AND software.name='$search'";
$db->query($query);
if ($db->num_rows() > 0) {
    $bx->box_strip("Exact match");
    appdat($query);
}


// 3. Search parameters for the apps
// TODO: there are no such parameters yet

// 4a Partial Match in the name (single word match)
// FIXME: three conditions:
// FIXME: LIKE '$search %' for starting word
// FIXME: LIKE ' % $search %' for a condition in the middle
// FIXME: LIKE '% $search' for the last word
$query = "SELECT COUNT(*) FROM software,counter WHERE software.appid=counter.appid AND software.status='A' AND software.name LIKE '% $search%'";
$db->query($query);
$db->next_record();
if ($db->f("COUNT(*)") > 0) {
    $bx->box_strip("Matches a single word in the name");
    $numiter = (($db->f("COUNT(*)")-1)/10);
    $order = lib_sort_by_order($by);
    lib_sort_box("search",$search);

    $query="SELECT *,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt FROM software,counter,auth_user WHERE software.appid=counter.appid AND software.user=auth_user.username AND software.status='A' AND software.name LIKE '% $search%' GROUP BY software.appid $order LIMIT $iter,10";
    appdat($query);
}
// If there are more than numiter apps, then a link to show more apps is given

if ($numiter > 1) {
  $urlquery = array("search" => ($search), "by" => $by);
  show_more ($iter,$numiter,"appsearch.php3",$urlquery);
}

// 4b Partial Match in the name
$query = "SELECT COUNT(*) FROM software,counter WHERE software.appid=counter.appid AND software.status='A' AND software.name LIKE '%$search%'";
$db->query($query);
$db->next_record();
if ($db->f("COUNT(*)") > 0) {
    $bx->box_strip("Partial match in the name");
    $numiter = (($db->f("COUNT(*)")-1)/10);
    $order = lib_sort_by_order($by);
    lib_sort_box("search",$search);

    $query="SELECT *,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt FROM software,counter,auth_user WHERE software.appid=counter.appid AND software.user=auth_user.username AND software.status='A' AND software.name LIKE '%$search%' GROUP BY software.appid $order LIMIT $iter,10";
    appdat($query);
}
// If there are more than numiter apps, then a link to show more apps is given

if ($numiter > 1) {
  $urlquery = array("search" => ($search), "by" => $by);
  show_more ($iter,$numiter,"appsearch.php3",$urlquery);
}

// 5. Global match in the despcription
// FIXME: three conditions:
// FIXME: LIKE '$search %' for starting word
// FIXME: LIKE ' % $search %' for a condition in the middle
// FIXME: LIKE '% $search' for the last word
$query = "SELECT *,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt  FROM software,counter WHERE software.appid=counter.appid AND software.status='A' AND software.description LIKE '% $search %' GROUP BY software.appid";
$db->query($query);
if ($db->num_rows() > 0) {
    $bx->box_strip("Exact match in the description");
    appdat($query);
}

// 6. Partial Match in the description
$query = "SELECT *,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt  FROM software,counter WHERE software.appid=counter.appid AND software.status='A' AND software.description LIKE '%$search%' GROUP BY software.appid";
$db->query($query);
if ($db->num_rows() > 0) {
    $bx->box_strip("Partial match in the description");
    appdat($query);
}


// FIXME: if nothing is found:
//  $bx->box_full($t->translate("Search"),$t->translate("No Application found"));
// FIXME: Search in Google, Freshmeat, developer.berlios, sourceforge, savannah, icewalk

require("footer2.inc");
?>