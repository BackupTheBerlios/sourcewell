<?php

######################################################################
# SourceWell 2
# ================================================
#
#
#
# Copyright (c) 2001 by
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

$select_app_from_temp = "SELECT * FROM temp WHERE appid='$appid'";

$select_app_from_software = "SELECT * FROM software WHERE appid='$appid'";

$select_apps_by_name_and_type = "SELECT * FROM software WHERE name='$name' AND type='$type'";

$delete_app_from_temp = "DELETE FROM temp WHERE appid='$appid'";

$select_history = "SELECT * FROM history WHERE appid='$appid' ORDER BY creation_his DESC";

$select_license = "SELECT * FROM licenses ORDER BY license ASC";

$select_section_and_category = "SELECT * FROM categories ORDER BY section,category ASC";

$count_comments_on_app = "SELECT COUNT(*) FROM comments WHERE appid='$appid'";


function select_everything_for_an_app($appid) {
	return "SELECT *,SUM(app_cnt+homepage_cnt+download_cnt+changelog_cnt+rpm_cnt+deb_cnt+tgz_cnt+cvs_cnt+screenshots_cnt+mailarch_cnt) AS sum_cnt FROM software,counter WHERE software.appid='$appid' AND software.appid=counter.appid GROUP BY software.appid";
}

function insert_app_in_software($section,$category,$status) {
	global $auth;
	global $name, $type, $version, $license, $homepage, $download, $changelog, $rpm, $deb, $tgz, $cvs, $screenshot, $mailarch, $developer, $description, $email, $depend, $urgency;

	return "INSERT software SET name='$name', type='$type', version='$version', license='$license', section='$section', category='$category', homepage='$homepage', download='$download', changelog='$changelog', rpm='$rpm', deb='$deb', tgz='$tgz', cvs='$cvs', screenshots='$screenshots', mailarch='$mailarch', developer='$developer', description='$description', email='$email', depend='$depend', urgency='$urgency', user='".$auth->auth["uname"]."', status='$status', creation=NOW()";
}

$select_appid_by_name_and_type = "SELECT appid FROM software WHERE name='$name' AND type='$type'";

function update_app_in_software($section,$category,$user,$status) {
	global $auth;
	global $name, $type, $version, $license, $homepage, $download, $changelog, $rpm, $deb, $tgz, $cvs, $screenshot, $mailarch, $developer, $description, $email, $depend, $urgency, $appid;

	return "UPDATE software SET version='$version', license='$license', section='$section', category='$category', homepage='$homepage', download='$download', changelog='$changelog', rpm='$rpm', deb='$deb', tgz='$tgz', cvs='$cvs', screenshots='$screenshots', mailarch='$mailarch', developer='$developer', description='$description', email='$email', depend='$depend', urgency='$urgency', user='$user', status='$status' WHERE appid='$appid'";
}

function insert_app_in_temp($section,$category,$status) {
	global $auth;
	global $appid, $name, $type, $version, $license, $homepage, $download, $changelog, $rpm, $deb, $tgz, $cvs, $screenshot, $mailarch, $developer, $description, $email, $depend, $urgency;

	return "INSERT INTO temp SET appid='$appid', name='$name', type='$type', version='$version', license='$license', section='$section', category='$category', homepage='$homepage', download='$download', changelog='$changelog', rpm='$rpm', deb='$deb', tgz='$tgz', cvs='$cvs', screenshots='$screenshots', mailarch='$mailarch', developer='$developer', description='$description', email='$email', depend='$depend', urgency='$urgency', user='".$auth->auth["uname"]."', status='$status'";
}

function update_app_in_temp($section,$category,$status) {
	global $auth;
	global $name, $type, $version, $license, $homepage, $download, $changelog, $rpm, $deb, $tgz, $cvs, $screenshot, $mailarch, $developer, $description, $email, $depend, $urgency, $appid;

	return "UPDATE temp SET type='$type', version='$version', license='$license', section='$section', category='$category', homepage='$homepage', download='$download', changelog='$changelog', rpm='$rpm', deb='$deb', tgz='$tgz', cvs='$cvs', screenshots='$screenshots', mailarch='$mailarch', developer='$developer', description='$description', email='$email', depend='$depend', urgency='$urgency', user='".$auth->auth["uname"]."', status='$status' WHERE appid='$appid'";
}

function insert_history($appid,$user,$version,$creation = "") {
        if ($creation == "") {
            $creation = "creation_his=NOW()";
        } else {
            $creation= "creation_his='$creation'";
        }
	return "INSERT history SET appid='$appid',user_his='".$user."', version_his='$version', ".$creation;
}

function insert_counter($appid) {
	return "INSERT counter SET appid='$appid'";
}

function select_types_and_versions_for_an_app($name)
{
    return "SELECT type,version,appid FROM software WHERE name='$name' AND status='A'";
}

?>