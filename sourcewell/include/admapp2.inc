<?php

######################################################################
# SourceWell 2
# ================================================
#
# Copyright (c) 2001 by
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
#
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

function admapp_top_bar() {
	global $bx, $t;

	$bx->box_begin("");
	$bx->box_title($t->translate("Application administration"));
	$bx->box_body_begin("top");
	$bx->box_columns_begin(3);

	$number_pending = admapp_count_apps_with_status("P");

	$bx->box_column("right","40%","",html_form_action("PHP_SELF",array("" => "", "status" => "P")).html_form_submit("Pending ($number_pending)","Pending").html_form_end());

	$number = admapp_count_apps_with_status("M");

	$bx->box_column("center","20%","",html_form_action("PHP_SELF",array("status" => "M")).html_form_submit("Modified ($number)","Modified").html_form_end());

	$number = admapp_count_apps_with_status("D");

	$bx->box_column("left","40%","",html_form_action("PHP_SELF",array("status" => "D")).html_form_submit("Deleted ($number)","Deleted").html_form_end());

	$bx->box_columns_end();
	$bx->box_body_end();
	$bx->box_end();

	return $number_pending;
}


function admapp_count_apps_with_status($status) {
	global $db;

	$db->query("SELECT COUNT(*) FROM software WHERE status='$status'");
	$db->next_record();
	$count = $db->f("COUNT(*)");

	$db->query("SELECT COUNT(*) FROM temp WHERE status='$status'");
	$db->next_record();	

	$count += $db->f("COUNT(*)");

	return $count;

}


function lib_show_app_shortly($appid,$status) {
  global $db, $bx, $sess;

  if ($appid != "" && empty($status)) $where =  "appid='$appid'";
  elseif ($appid != "" && $status != "") $where = "appid = '$appid' AND status='$status'";
  elseif ($appid == "" && $status != "") $where = "status = '$status'";
  else print "error!!!!!!!!!!!!!!!!!!!!!!!!!!";

  $i = 1;
  while($i<3) {
	if ($i == 1) $table = "software";
	elseif ($i == 2) $table = "temp";

	$db->query("SELECT * FROM $table WHERE $where");
  	if ($db->num_rows() == 0) echo "";
  	else {
	   while ($db->next_record()) {

		$bx->box_begin();
		app_header($db->f("appid"),$db->f("name"),$db->f("version"),$db->f("type"),$db->f("urgency"),$db->f("homepage"),$db->f("download"),$db->f("changelog"),$db->f("section"),$db->f("category"),$db->f("status"));
		$bx->box_body_begin();
  		$timestamp = time($db->f("modification"));
		echo "<b>by ";
		lib_pnick($db->f("user"));
    		echo " - ".timestr($timestamp)."</b><p>\n";
		$db->p("description");
		$bx->box_body_end();
		app_footer($db->f("appid"));
		$bx->box_end();
	   }
	}
	$i++;
  }
}
?>