<?php

######################################################################
# SourceWell2: Software Announcement & Retrieval System
# ================================================
#
# Copyright (c) 2001 by
#                Lutz Henckel (lutz.henckel@fokus.gmd.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This file is usefull for administrating (registered) users
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

require("header2.inc");

security_page_access("admuser");

$bx = new box("general","96%");

// Check if there was a submission
  while (is_array($HTTP_POST_VARS) && list($key, $val) = each($HTTP_POST_VARS)) {
    switch ($key) {
      case "create": // Create a new user
	if (empty($username) || empty($password) || empty($email_usr)) { // Do we have all necessary data?
	  $be->box_full($t->translate("Error"), $t->translate("Please enter")." <B>".$t->translate("Username")."</B>, <B>".$t->translate("Password")."</B> ".$t->translate("and")." <B>".$t->translate("E-Mail")."</B>!");
	  break;
	}
         /* Does the user already exist?
	    NOTE: This should be a transaction, but it isn't... */
	$db->query("select * from auth_user where username='$username'");
	if ($db->nf()>0) {
	  $be->box_full($t->translate("Error"), $t->translate("User")." <B>$username</B> ".$t->translate("already exists").".");
	  break;
	}

         /* Does an anonymous user already exist?
	    NOTE: This should also be a transaction, but it isn't... */
	$db->query("select * from auth_user where perms='anonymous'");
	if ($db->num_rows()>0 && ereg("anonymous",implode($perms,","))) {
	  $be->box_full($t->translate("Error"), $t->translate("There can only be one anonymous user in the system").".");
	  break;
	}

         /* Does the anonymous user have other permissions? */
        if (ereg("anonymous",implode($perms,",")) && (ereg("user_pending",implode($perms,",")) || ereg("user",implode($perms,",")) || ereg("editor",implode($perms,",")) || ereg("admin",implode($perms,",")) || ereg("user_pending",implode($perms,",")))) {
	  $be->box_full($t->translate("Error"), $t->translate("The anonymous permission is incompatible with another type of permission").".");
	  break;
	}
			// Create a uid and insert the user...
	$u_id=md5(uniqid($hash_secret));
	$permlist = addslashes(implode($perms,","));
	$modification_usr = "NOW()";
	$creation_usr = "NOW()";
	$query = "INSERT INTO auth_user VALUES('$u_id','$username','$password','$realname','$email_usr',$modification_usr,$creation_usr,'$permlist')";
	$db->query($query);
	if ($db->affected_rows() == 0) {
	  $be->box_full($t->translate("Error"), "<b>".$t->translate("Database Access failed").":</b> $query");
	  break;
	}
	$bx->box_full($t->translate("User Creation"), $t->translate("User")." \"$username\" ".$t->translate("created").".<BR>");
	break;

      case "u_edit": // Change user parameters
	if (empty($username) || empty($password) || empty($email_usr)) { // Do we have all necessary data?
	  $be->box_full($t->translate("Error"), $t->translate("Please enter")." <B>".$t->translate("Username")."</B>, <B>".$t->translate("Password")."</B> ".$t->translate("and")." <B>".$t->translate("E-Mail")."</B>!");
	  break;
	}
			  // Handles all user contributions to the system
			  // so that we don't loose them when changing username
        if ($username != $old_username) {
	  $query = "update software set user='$username',status='M' where user='$old_username'";
	  $db->query($query);
	  $query = "update history set user_his ='$username' where user_his='$old_username'";
	  $db->query($query);
	  $query = "update comments set user_cmt='$username' where user_cmt='$old_username'";
	  $db->query($query);
        }
			// Update user information.
	$permlist = addslashes(implode($perms,","));
	$query = "update auth_user set username='$username', password='$password', realname='$realname', email_usr='$email_usr', modification_usr=NOW(), perms='$permlist' where user_id='$u_id'";
	$db->query($query);
	if ($db->affected_rows() == 0) {
	  $be->box_full($t->translate("Error"), $t->translate("User Change failed").":<br>$query");
	  break;
	}
	$bx->box_full($t->translate("User Change"), $t->translate("User")." <b>$username</b> ".$t->translate("is changed").".<br>");
	break;

      case "u_kill":
			// we change the users contributions to anonymous
			// if the anonymous user exists in the system
        $db->query("SELECT username FROM auth_user WHERE perms='anonymous'");
        $db->next_record();
        $anonymous = $db->f("username");
        $query = "UPDATE software SET user='$anonymous',status='M' WHERE user='$old_username'";
        $db->query($query);
        $query = "UPDATE history SET user_his ='$anonymous' WHERE user_his='$old_username'";
	$db->query($query);
	$query = "UPDATE comments SET user_cmt='$anonymous' WHERE user_cmt='$old_username'";
	$db->query($query);

			// Delete that user.
	$query = "delete from auth_user where user_id='$u_id' and username='$username'";
	$db->query($query);
	if ($db->affected_rows() == 0) {
	  $be->box_full($t->translate("Error"), $t->translate("User Deletion failed").":<br>$query");
	  break;
	}
	$bx->box_full($t->translate("User Deletion"), $t->translate("User")." <b>$username</b> ".$t->translate("has been deleted"));
	break;

      default:
	break;
    }
  }

/* Output user administration forms, including all updated
	information, if we come here after a submission...
*/

$bx->box_begin();
$bx->box_title($t->translate("User Administration"));
$bx->box_body_begin();
$bx->box_columns_begin(8);

$bx->box_column("center","","",$t->translate("Username"));
$bx->box_column("center","","",$t->translate("Password"));
$bx->box_column("center","","",$t->translate("Realname"));
$bx->box_column("center","","",$t->translate("E-Mail"));
$bx->box_column("center","","",$t->translate("Modification"));
$bx->box_column("center","","",$t->translate("Creation"));
$bx->box_column("center","","",$t->translate("Permission"));
$bx->box_column("center","","",$t->translate("Action"));

$bx->box_next_row_of_columns();

// Create a new user

htmlp_form_action("PHP_SELF",array(),"POST");

$bx->box_column("center","","",html_input_text("username", 12, 32, ""));
$bx->box_column("center","","",html_input_password("password", 12, 32, ""));
$bx->box_column("center","","",html_input_text("realname", 12, 32, ""));
$bx->box_column("center","","",html_input_text("email_usr", 12, 32, ""));
$bx->box_column("center","","","");
$bx->box_column("center","","","");
$bx->box_column("center","","",$perm->perm_sel("perms","user"));
$bx->box_column("center","","",html_form_submit($t->translate("Create User"),"create"));
htmlp_form_end();

// Traverse the result set
$db->query("SELECT * FROM auth_user ORDER BY username");
while ($db->next_record()) {

    $bx->box_next_row_of_columns();

    htmlp_form_action("PHP_SELF",array(),"POST");
    htmlp_form_hidden("u_id",$db->f("user_id"));
    htmlp_form_hidden("old_username",$db->f("username"));

    $bx->box_column("center","","",html_input_text("username", 12, 32, $db->f("username")));
    $bx->box_column("center","","",html_input_password("password", 12, 32, $db->f("password")));
    $bx->box_column("center","","",html_input_text("realname", 12, 32, $db->f("realname")));
    $bx->box_column("center","","",html_input_text("email_usr", 12, 32, $db->f("email_usr")));
    $bx->box_column("center","","",timestr_short(mktimestamp($db->f("modification_usr"))));
    $bx->box_column("center","","",timestr_short(mktimestamp($db->f("creation_usr"))));
    $bx->box_column("center","","",$perm->perm_sel("perms",$db->f("perms")));
    $bx->box_column("center","","",html_form_submit($t->translate("Delete"),"u_kill").html_form_submit($t->translate("Change"),"u_edit"));

    htmlp_form_end();
}

$bx->box_columns_end();
$bx->box_body_end();
$bx->box_end();

require("footer2.inc");
?>
