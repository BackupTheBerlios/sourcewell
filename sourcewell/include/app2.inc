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

function app_show($appid) {
  global $db, $sess, $name, $type, $version, $sec_and_cat, $license, $homepage, $download, $changelog, $rpm, $deb, $tgz, $cvs, $screenshots, $mailarch, $developer, $description, $email, $depend, $urgency, $username, $preview;
  global $app_cnt, $homepage_cnt, $download_cnt, $changelog_cnt, $rpm_cnt, $deb_cnt, $tgz_cnt, $cvs_cnt, $screenshots_cnt, $mailarch_cnt, $sum_cnt;

  $db->query(select_everything_for_an_app($appid));
  if ($db->num_rows() == 0) print "no app with that appid or app pending";
  else {
	$db->next_record();

	$name = $db->f("name");
	$type = $db->f("type");
	$version = $db->f("version");
	$sec_and_cat = $db->f("section")."/".$db->f("category");
	$license = $db->f("license");
	$homepage = $db->f("homepage");
	$download = $db->f("download");
	$changelog = $db->f("changelog");
	$rpm = $db->f("rpm");
	$deb = $db->f("deb");
		$tgz = $db->f("tgz");
	$cvs = $db->f("cvs");
	$screenshots = $db->f("screenshots");
	$mailarch = $db->f("mailarch");
	$developer = $db->f("developer");
	$description = $db->f("description");
	$email	 = $db->f("email");
	$depend = $db->f("depend");
	$urgency = $db->f("urgency");
	$username = $db->f("user");
	// Counters
	$app_cnt = $db->f("app_cnt");
	$homepage_cnt = $db->f("homepage_cnt");
	$download_cnt = $db->f("download_cnt");
	$changelog_cnt = $db->f("changelog_cnt");
	$rpm_cnt = $db->f("rpm_cnt");
	$deb_cnt = $db->f("deb_cnt");
	$tgz_cnt = $db->f("tgz_cnt");
	$cvs_cnt = $db->f("cvs_cnt");
	$screenshots_cnt = $db->f("screenshots_cnt");
	$mailarch_cnt = $db->f("mailarch_cnt");
	$sum_cnt = $db->f("sum_cnt");


	if ($preview == 0 && $db->f("status") != "A") {
		_app_status($db->f("status"),$name);
	} else {
		$preview = 0;
		app_preview();
	}
  }
}

function app_preview() {
  global $t, $bx, $auth, $sess, $appid, $name, $type, $version, $sec_and_cat, $license, $homepage, $download, $changelog, $rpm, $deb, $tgz, $cvs, $screenshots, $mailarch, $developer, $description, $email, $depend, $urgency, $username, $validation, $preview;

	// FIXME: error
	// $appid is not set after having inserted an app and it comes from app_show()
	// the problem is that $appid is set in the app_show() and a global variable here!!!!
	// what is wrong?

	$bx->box_begin();
	if ($preview) $bx->box_title(_("Preview"));
	$bx->box_title($name." ".$version." ("._(typestr($type)).")");
	$bx->box_body_begin();
   	$timestamp = time();
	echo "<b>by ";
	if (!isset($username)) lib_pnick($auth->auth["uname"]);
	else lib_pnick($username);
    	echo " - ".timestr($timestamp)."</b><p>\n";

	print $description."<br>";

	$bx->box_columns_begin(2);

	if ($homepage) {
	  	$bx->box_column ("right","30%","","<b>"._("Homepage").":</b> ");
	  	$bx->box_column ("left","70%","",html_redirect($appid,"homepage_cnt",$homepage,$homepage)._app_show_count("homepage"));
	} else {
	  	$bx->box_column ("right","30%","","&nbsp;");
	  	$bx->box_column ("left","70%","","&nbsp;");
	}

	if ($download) {
	  	$bx->box_next_row_of_columns();
	  	$bx->box_column ("right","30%","","<b>"._("Donwload").":</b> ");
	  	$bx->box_column ("left","70%","",html_redirect($appid,"download_cnt",$download,$download)._app_show_count("download"));
	}

	if ($changelog) {
	  	$bx->box_next_row_of_columns();
	  	$bx->box_column ("right","30%","","<b>"._("Changelog").":</b> ");
	  	$bx->box_column ("left","70%","",html_redirect($appid,"changelog_cnt",$changelog,$changelog)._app_show_count("changelog"));
	}

	if ($rpm) {
	  	$bx->box_next_row_of_columns();
	  	$bx->box_column ("right","30%","","<b>"._("Red Hat Package").":</b> ");
	  	$bx->box_column ("left","70%","",html_redirect($appid,"rpm_cnt",$rpm,$rpm)._app_show_count("rpm"));
	}

	if ($deb) {
	  	$bx->box_next_row_of_columns();
	  	$bx->box_column ("right","30%","","<b>"._("Debian Package").":</b> ");
	  	$bx->box_column ("left","70%","",html_redirect($appid,"deb_cnt",$deb,$deb)._app_show_count("deb"));
	}

	if ($tgz) {
	  	$bx->box_next_row_of_columns();
	  	$bx->box_column ("right","30%","","<b>"._("Slackware Package").":</b> ");
	  	$bx->box_column ("left","70%","",html_redirect($appid,"tgz_cnt",$tgz,$tgz)._app_show_count("tgz"));
	}


	if ($cvs) {
	  	$bx->box_next_row_of_columns();
	  	$bx->box_column ("right","30%","","<b>"._("CVS Tree").":</b> ");
	  	$bx->box_column ("left","70%","",html_redirect($appid,"cvs_cnt",$cvs,$cvs)._app_show_count("cvs"));
	}

	if ($screenshots) {
	  	$bx->box_next_row_of_columns();
	  	$bx->box_column ("right","30%","","<b>"._("Screenshots").":</b> ");
	  	$bx->box_column ("left","70%","",html_redirect($appid,"screenshots_cnt",$screenshots,$screenshots)._app_show_count("screenshots"));
	}

	if ($mailarch) {
	  	$bx->box_next_row_of_columns();
	  	$bx->box_column ("right","30%","","<b>"._("Mailing List Archives").":</b> ");
	  	$bx->box_column ("left","70%","",html_redirect($appid,"mailarch_cnt",$mailarch,$mailarch)._app_show_count("mailarch"));
	}

	if ($developer) {
	  	$bx->box_next_row_of_columns();
	  	$bx->box_column ("right","30%","","<b>"._("Author").":</b> ");
	  	$bx->box_column ("left","70%","",$developer." &lt;".html_link("mailto:".ereg_replace("@"," at ",htmlentities($email)),array(),ereg_replace("@"," at ",htmlentities($email)))."&gt;");
	}

	$bx->box_next_row_of_columns();

	_app_split_sec_and_cat ($sec_and_cat);
	$bx->box_column ("right","30%","","<b>"._("Section/Category").":</b> ");
	$bx->box_column ("left","70%","",html_link("appbycat.php3",array("section" => $GLOBALS["section"], "category" => $GLOBALS["category"]),$sec_and_cat));

	$bx->box_next_row_of_columns();

  	$bx->box_column ("right","30%","","<b>"._("License").":</b> ");
  	$bx->box_column ("left","70%","",html_link("appbylic.php3",array("license" => $license),$license));

	if ($depend) {
	  	$bx->box_next_row_of_columns();
	  	$bx->box_column ("right","30%","","<b>"._("Dependencies").":</b> ");
	  	$bx->box_column ("left","70%","",$depend);
	}

  	$bx->box_next_row_of_columns();

	$bx->box_column ("right","30%","","<b>"._("Urgency").":</b> ");
	$bx->box_column ("left","70%","",lib_urgency($urgency));

  	if ($preview) { 
		if (($validation) && security_data_access("permision_for_validating_apps")) {
	 	 	$bx->box_next_row_of_columns();
	 	 	$bx->box_column ("right","30%","","<b>"._("Validation").":</b> ");
	 	 	$bx->box_column ("left","70%","",$validation);
		}

		$bx->box_next_row_of_columns();

		htmlp_form_action("PHP_SELF",array("appid" => $appid));
		htmlp_form_hidden("name",$name);
		htmlp_form_hidden("type",$type);
		htmlp_form_hidden("version",$version);
		htmlp_form_hidden("sec_and_cat",$sec_and_cat);
		htmlp_form_hidden("license",$license);
		htmlp_form_hidden("homepage",$homepage);
		htmlp_form_hidden("download",$download);
		htmlp_form_hidden("changelog",$changelog);
		htmlp_form_hidden("rpm",$rpm);
		htmlp_form_hidden("deb",$deb);
		htmlp_form_hidden("tgz",$tgz);
		htmlp_form_hidden("cvs",$cvs);
		htmlp_form_hidden("screenshots",$screenshots);
		htmlp_form_hidden("mailarch",$mailarch);
		htmlp_form_hidden("developer",$developer);
		htmlp_form_hidden("description",$description);
		htmlp_form_hidden("email",$email);
		htmlp_form_hidden("depend",$depend);
		htmlp_form_hidden("urgency",$urgency);
		htmlp_form_hidden("validation",$validation);
	  	$bx->box_column ("right","40%","","&nbsp;");
	  	$bx->box_column ("left","60%","",html_form_submit("Submit","submit"));
		htmlp_form_end();
		$bx->box_columns_end();
	} else {
		$bx->box_next_row_of_columns();
	  	$bx->box_column ("right","30%","","<b>"._("Application ID").":</b> ");
 	 	$bx->box_column ("left","70%","",html_link("app.php3",array("appid" => $appid),$appid)._app_show_count("sum"));

		$bx->box_next_row_of_columns();
	  	$bx->box_column ("right","30%","","<b>"._("Announcements").":</b> ");
 	 	$bx->box_column ("left","70%","",_app_announcements($appid));

		$bx->box_columns_end();

		app_footer($appid);

		// FIXME: show comments on this application!
	}

    	$bx->box_body_end();
    	$bx->box_end();
}

function app_previous_form() {
  global $bx, $t, $sess;

  $bx->box_begin();
  $bx->box_title(_("New Application"));
  $bx->box_body_begin();
  htmlp_form_action("PHP_SELF",array());

  $bx->box_columns_begin(2);

  $bx->box_column ("right","40%","","<b>"._("Application Name")."</b> (128): ");
  $bx->box_column ("left","60%","",html_input_text("name",40,128,""));

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("Type").":</b> ");
  $bx->box_column ("left","60%","",_app_select_type(""));

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","&nbsp;");
  $bx->box_column ("left","60%","",html_form_submit("Insert","insert"));
  htmlp_form_end();
  $bx->box_columns_end();

  $bx->box_body_end();
  $bx->box_end();

}

function app_form() {
  global $bx, $t, $sess, $appid, $name, $type, $version, $sec_and_cat, $license, $homepage, $download, $changelog, $rpm, $deb, $tgz, $cvs, $screenshots, $mailarch, $developer, $description, $email, $depend, $urgency, $update, $validation;

  $bx->box_begin();
  if ($update) $bx->box_title(_("Update Application"));
  else $bx->box_title("Insert Application");
  $bx->box_body_begin();
  htmlp_form_action("PHP_SELF",array("" => "", "appid" => $appid));

  $bx->box_columns_begin(2);

  $bx->box_column ("right","30%","","<b>"._("Name").":</b> ");
  $bx->box_column ("left","70%","","<b>".$name."</b>");
  htmlp_form_hidden("name",$name);

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","30%","","<b>"._("Type").":</b> ");
  $bx->box_column ("left","70%","",typestr($type));
  htmlp_form_hidden("type",$type);

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("Version")."</b> (16): ");
  $bx->box_column ("left","60%","",html_input_text("version", 16, 16, $version)."&nbsp; (mandatory)");

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("Section/Category").":</b> ");
  $bx->box_column ("left","60%","",_app_select_sec_and_cat($sec_and_cat));


  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("License").":</b> ");
  $bx->box_column ("left","60%","",_app_select_license($license));

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("Homepage")."</b> (255): ");
  $bx->box_column ("left","60%","",html_input_text("homepage", 40, 255, $homepage));

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("Download")."</b> (255): ");
  $bx->box_column ("left","60%","",html_input_text("download", 40, 255, $download));

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("Changelog")."</b> (255): ");
  $bx->box_column ("left","60%","",html_input_text("changelog", 40, 255, $changelog));

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("Screenshots")."</b> (255): ");
  $bx->box_column ("left","60%","",html_input_text("screenshots", 40, 255, $screenshots));

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("RPM Package")."</b> (255): ");
  $bx->box_column ("left","60%","",html_input_text("rpm", 40, 255, $rpm));

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("Debian Package")."</b> (255): ");
  $bx->box_column ("left","60%","",html_input_text("deb", 40, 255, $deb));

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("Slackware Package")."</b> (255): ");
  $bx->box_column ("left","60%","",html_input_text("tgz", 40, 255, $tgz));

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("Mailing List Archives")."</b> (255): ");
  $bx->box_column ("left","60%","",html_input_text("mailarch", 40, 255, $mailarch));

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("CVS Tree")."</b> (255): ");
  $bx->box_column ("left","60%","",html_input_text("cvs", 40, 255, $cvs));

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("Description")."</b> (*): ");
  $bx->box_column ("left","60%","",html_textarea("description",40,7,"virtual",255,$description));

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("Author")."</b> (64): ");
  $bx->box_column ("left","60%","",html_input_text("developer", 40, 64, $developer));

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("Author email")."</b> (128): ");
  $bx->box_column ("left","60%","",html_input_text("email", 40, 128, $email));

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("Depends on")."</b> (128): ");
  $bx->box_column ("left","60%","",html_input_text("depend", 40, 128, $depend));

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","<b>"._("Urgency")."</b> (255): ");
  $bx->box_column ("left","60%","",_app_select_urgency($urgency));

  if (($update || $validation) && security_data_access("permision_for_validating_apps")) {
	$bx->box_next_row_of_columns();
	$bx->box_column ("right","40%","","<b>"._("Validation")."</b> (255): ");
  	$bx->box_column ("left","60%","",_app_select_validation($validation));
  }

  $bx->box_next_row_of_columns();

  $bx->box_column ("right","40%","","&nbsp;");
  $bx->box_column ("left","60%","",html_form_submit("Preview","preview").html_form_submit("Submit","submit"));
  htmlp_form_end();
  $bx->box_columns_end();

  $bx->box_body_end();
  $bx->box_end();
}

function app_modification($appid) {
  global $db, $sess, $name, $type, $version, $sec_and_cat, $license, $homepage, $download, $changelog, $rpm, $deb, $tgz, $cvs, $screenshots, $mailarch, $developer, $description, $email, $depend, $urgency, $update;

  $db->query($GLOBALS[select_app_from_temp]);
  if ($db->num_rows() == 0) { 
	$db->query($GLOBALS[select_app_from_software]);
  }
  if ($db->num_rows() == 0) print "no app with that appid";
  else {
	$db->next_record();

	$name = $db->f("name");
	$type = $db->f("type");
	$version = $db->f("version");
	$sec_and_cat = $db->f("section")."/".$db->f("category");
	$license = $db->f("license");
	$homepage = $db->f("homepage");
	$download = $db->f("download");
	$changelog	 = $db->f("changelog");
	$rpm = $db->f("rpm");
	$deb = $db->f("deb");
	$tgz = $db->f("tgz");
	$cvs = $db->f("cvs");
	$screenshots = $db->f("screenshots");
	$mailarch = $db->f("mailarch");
	$developer = $db->f("developer");
	$description = $db->f("description");
	$email	 = $db->f("email");
	$depend = $db->f("depend");
	$urgency = $db->f("urgency");

	$update = 1;
	app_form();
  }
}

function app_insert() {
  global $t, $perm, $be, $db, $auth, $type, $name, $version, $sec_and_cat, $license, $homepage, $download, $changelog, $rpm, $deb, $tgz, $cvs, $screenshots, $mailarch, $developer, $description, $email, $depend, $urgency, $preview;

if (empty($name) || empty($version)) {
	$be->box_full(_("Error"), _("Parameter missing"));
} else {

  _app_trim_everything();
  _app_split_sec_and_cat ($sec_and_cat);
                      
  $db->query($GLOBALS[select_appid_by_name_and_type]);
  if ($db->num_rows() > 0) {
	     $be->box_full(_("Error"), _("Application")." $name "._("already exists"));
  } else {

     if ($perm->have_perm("editor")) {
       $status = 'A';
     } else {
       $status = 'P';
     }

  	$db->query(insert_app_in_software($GLOBALS["section"],$GLOBALS["category"],$status));

	  // Get appid

 	$db->query($GLOBALS[select_appid_by_name_and_type]);
  	$db->next_record();
	$appid = $db->f("appid");

 	 // New History

  	$db->query(insert_history($appid));

	  // New Counter

  	$db->query(insert_counter($appid));

	   // Mail notification

   	if ($GLOBALS["ml_notify"]) {
       		$msg = "insert application $name $version (".typestr($type).") by ".$auth->auth["uname"].".";
       		mailuser("editor", "insert application", $msg);
   	}

	$preview = 1;
  	app_show($appid);
  }
}
}

function app_modify($appid) {
  global $db, $auth, $perm, $name, $type, $version, $sec_and_cat, $license, $homepage, $download, $changelog, $rpm, $deb, $tgz, $cvs, $screenshots, $mailarch, $developer, $description, $email, $depend, $urgency, $validation, $preview;

  _app_trim_everything();
  _app_split_sec_and_cat ($sec_and_cat);

//	$db->query("SELECT creation FROM software WHERE appid='$appid'");

// FIXME: Do we have to take creation in order to not modify it?
  if ($perm->have_perm("editor")) {
	if ($validation == "review") $status = 'A';
	elseif ($validation == "delete") $status = 'D';

	$db->query(update_app_in_software($GLOBALS["section"],$GLOBALS["category"],$status));
	$db->query($GLOBALS[delete_app_from_temp]);

    	// New History
	// FIXME - this does not work as expected:
	// If an editor is validating an app (reviewing or deleting it), then no new entry in history has to appear

    	if (!isset($validation)) $db->query("INSERT history SET appid='$appid',user_his='".$auth->auth["uname"]."',creation_his=NOW(),version_his='$version'");

    } else {
      	$status = 'P';

	$db->query($GLOBALS[select_app_from_temp]);
	if ($db->num_rows() == 0) {

		$db->query(insert_app_in_temp($GLOBALS["section"],$GLOBALS["category"],$status));

	} else {

		$db->query(update_app_in_temp($GLOBALS["section"],$GLOBALS["category"],$status));
	}
    }

    // New History

    $db->query(insert_history($appid));


   if ($ml_notify) {
		print "mensaje mandado al editor";
       		$msg = "update application $name $version (".typestr($type).") by ".$auth->auth["uname"].".";
       		mailuser("editor", "update application", $msg);
   }

  $preview = 1;
  app_show($appid);
}

function _app_announcements($appid) { 
    global $t;

    if (isset($appid) && !empty($appid)) {

        $db2 = new DB_SourceWell;
        $db2->query($GLOBALS[select_history]);

        $return ="";
        $i = 0;

        while ($db2->next_record()) {
      	    $timestamp = mktimestamp($db2->f("creation_his"));
      	    $return .= $db2->f("version_his")." "._("by")." ".$db2->f("user_his")." "._("on")." ".timestr($timestamp)."\n";
      	    if (++$i != 0) $return .= "<br>";
       }
       $return .="<br>";
       return($return);
    }
}

function _app_select_type($select) {
    global $t;

    $return = html_select("type");
    if ($select == "S") $selected = 1;
    else $selected = 0;
    $return .= html_select_option("S",$selected,_("Stable"));
    if ($select == "D") $selected = 1;
    else $selected = 0;
    $return .= html_select_option("D",$selected,_("Development"));

    $return .= html_select_end();

    return($return);
}

function _app_select_validation($select) {
    global $t;

    $return = html_select("validation");
    if ($select == "review") $selected = 1;
    else $selected = 0;
    $return .= html_select_option("review",$selected,_("Review"));
    if ($select == "delete") $selected = 1;
    else $selected = 0;
    $return .= html_select_option("delete",$selected,_("Delete"));

    $return .= html_select_end();

    return($return);
}

function _app_trim_everything() {
  global $name, $type, $version, $homepage, $download, $changelog, $rpm, $deb, $tgz, $cvs, $screenshots, $mailarch, $developer, $description, $email, $depend;

    $name = trim($name);
    $type = trim($type);
    $version = trim($version);
    $homepage = trim($homepage);
    $download = trim($download);
    $changelog = trim($changelog);
    $rpm = trim($rpm);
    $deb = trim($deb);
    $tgz = trim($tgz);
    $cvs = trim($cvs);
    $screenshots = trim($screenshots);
    $mailarch = trim($mailarch);
    $developer = trim($developer);
    $description = trim($description);
    $email = trim($email);
    $depend = trim($depend);
}

function _app_select_license($license) {

	$return = html_select("license");
	$db_local = new DB_SourceWell;
	$db_local->query($GLOBALS[select_license]);
	while ($db_local->next_record()) {
		if ($db_local->f("license") == $license) $selected = "selected";
		else $selected = "";
		$return .= html_select_option($db_local->f("license"),$selected,$db_local->f("license"));
	}
	$return .= html_select_end();

	return($return);
}

function _app_select_sec_and_cat($sec_and_cat) {

	$return = html_select("sec_and_cat");
	$db_local = new DB_SourceWell;
	$db_local->query($GLOBALS[select_section_and_category]);
	while ($db_local->next_record()) {
    		if ($db_local->f("section")."/".$db_local->f("category") == $sec_and_cat) $selected = "selected";
		else $selected ="";
		$return .= html_select_option($db_local->f("section")."/".$db_local->f("category"),$selected,$db_local->f("section")."/".$db_local->f("category"));
	}
	$return .= html_select_end();

	return($return);
}

function _app_select_urgency($select) {
	global $t;

	$return = html_select("urgency");

	if ($select == "1") $selected = "selected";
	else $selected ="";
	$return .= html_select_option("1",$selected,_("low"));

	if ($select == "2" || empty($select)) $selected = "selected";
	else $selected ="";
	$return .= html_select_option("2",$selected,_("medium"));

	if ($select == "3") $selected = "selected";
	else $selected ="";
	$return .= html_select_option("3",$selected,_("high"));

	$return .= html_select_end();

	return($return);
}

function _app_what_status($status) {
    global $t;

    switch ($status) {
      case 'A':
        echo _("active")."\n";
        break;
      case 'P':
        echo _("pending")."\n";
        break;
      case 'D':
        echo _("deleted")."\n";
        break;
      case 'M':
        echo _("modified")."\n";
    }
}

function _app_split_sec_and_cat ($sec_and_cat) {
  global $section, $category;

  $section = trim(strtok($sec_and_cat, "/"));
  $category = trim(strtok("."));

}

function app_footer($appid) {
  global $bx, $t;

  $bx->box_title_begin();

  htmlp_link("app_mod.php3",array("appid" => $appid),html_image("recycled.png",0,"","",_("Update")));
  print "&nbsp; &nbsp;";
  htmlp_link("cmtapp.php3",array("id" => $appid),html_image("txt.png",0,"","",_("Comment")));

  $bx->box_title_end();
}

function app_header($appid,$name,$version,$type,$urgency,$homepage,$download,$changelog,$section,$category,$status) {
  global $bx, $t;

  $sec_and_cat = $section."/".$category;

  switch($status) {
	case 'A': $link = "app.php3"; break;
	default: $link = "app_mod.php3"; break;
  }

  $bx->box_title_begin();
  $bx->box_columns_begin(2);
  $bx->box_column("left","40%",$GLOBALS["th_box_title_bgcolor"],"<b>".html_link($link,array("appid" => $appid),$name." ".$version)." ("._(typestr($type)).")</b>");
  $bx->box_column_start("right","60%",$GLOBALS["th_box_title_bgcolor"]);

  htmlp_image("importance.png",0,"","","importance");

  $db2 = new DB_SourceWell;

  print " <b>(3)</b> ";

  $i=1;
  while ($i < $urgency) {
	htmlp_image("bell.png",0,"","","urgency");
	$i++;
  }

  htmlp_redirect($appid,"homepage_cnt",$homepage, html_image("html.png",0,"","","homepage"));
  print " &nbsp";
  htmlp_redirect($appid,"download_cnt",$download, html_image("binary2.png",0,"","","download"));
  print " &nbsp";
  htmlp_redirect($appid,"changelog_cnt",$changelog, html_image("info.png",0,"","","changelog"));
  print " &nbsp";

  htmlp_link("cmtapp.php3",array("id" => $appid),html_image("txt.png",0,"","",_("Comment")));

  $db2->query($GLOBALS[count_comments_on_app]);
  $db2->next_record();
  if ($db2->f("COUNT(*)") > 0) {
        print "<b>[".$db2->f("COUNT(*)")."]</b>";
  }
  echo " &nbsp;";

  htmlp_link("appbycat.php3",array("section" => $section, "category" => $category),$sec_and_cat);

  $bx->box_columns_end();
  $bx->box_title_end();
}

function _app_show_count($on_what) {
  global $preview, $app_cnt, $homepage_cnt, $download_cnt, $changelog_cnt, $rpm_cnt, $deb_cnt, $tgz_cnt, $cvs_cnt, $screenshots_cnt, $mailarch_cnt, $sum_cnt;

	if (!isset($preview) || empty($preview) || $preview != "Preview") {
		$variable = $on_what."_cnt";
		return " (".$$variable." hits)";
	}

}


function _app_status($status,$name) {
  global $be, $t;

  switch ($status) {
      case "P":
        $be->box_full(_("Error"), _("Application")." <b>".$name."</b> "._("has not yet been reviewed by a $sys_name Editor.<br> Please, be patient. It will be surely done in the next time."));
	break;
      case "M":				
	$be->box_full(_("Error"), _("Application")." <b>".$name."</b> "._("is modified").".");
	break;
      case "D":
 	$be->box_full(_("Error"), _("Application")." <b>".$name."</b> "._("is deleted").".");
	break;
      default:
        $be->box_full(_("Error"), _("Application")." (ID: $id) "._("does not exist").".");
	break;
  }
}
?>