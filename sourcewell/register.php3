<?php

######################################################################
# SourceWell 2
# ================================================
#
#
#
# Copyright (c) 2001 by
#                Gregorio Robles (grex@scouts-es.org) and
#                Lutz Henckel (lutz.henckel@fokus.gmd.de)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

require("header2.inc");

security_page_access("register");

$bx = new box("general","");

// Check if there was a submission
$reg = 0;
while (is_array($HTTP_POST_VARS) 
       && list($key, $val) = each($HTTP_POST_VARS)) {
    switch ($key) {
    case "register": // Register a new user
		$username = trim($username);
		$password = trim($password);
		$cpassword = trim($cpassword);
		$realname = trim($realname);
		$email_usr = trim($email_usr);
        if (empty($username) || empty($password)  || empty($cpassword) || empty($email_usr)) { // Do we have all necessary data?
            $be->box_full($t->translate("Error"), $t->translate("Please enter")." <b>".$t->translate("Username")."</b>, <b>".$t->translate("Password")."</b> ".$t->translate("and")." <b>".$t->translate("E-Mail")."</b>!");
            break;
        }
        if (strcmp($password,$cpassword)) { // password are identical?
            $be->box_full($t->translate("Error"), $t->translate("The passwords are not identical").". ".$t->translate("Please try again")."!");
            break;
        }
        /* Does the user already exist?
           NOTE: This should be a transaction, but it isn't... */
        $db->query("select * from auth_user where username='$username'");
        if ($db->nf()>0) {
            $be->box_full($t->translate("Error"), $t->translate("User")." <B>$username</B> ".$t->translate("already exists")."!<br>".$t->translate("Please select a different Username").".");
            break;
        }
        // Create a uid and insert the user...
        $u_id=md5(uniqid($hash_secret));
        $modification_usr = "NOW()";
        $creation_usr = "NOW()";
        $permlist = "user_pending";
        $query = "insert into auth_user values('$u_id','$username','$password','$realname','$email_usr',$modification_usr,$creation_usr,'$permlist')";
        $db->query($query);
        if ($db->affected_rows() == 0) {
            $be->box_full($t->translate("Error"), $t->translate("Registration of new User failed").":<br> $query");
            break;
        }
        // send mail
        $message = $t->translate("Thank you for registering on the $sys_name Site. In order")."\n"
                  .$t->translate("to complete your registration, visit the following URL").": \n\n"
                  .$sys_url."verify.php3?confirm_hash=$u_id\n\n"
                  .$t->translate("Enjoy the site").".\n\n"
                  .$t->translate(" -- the $sys_name crew")."\n";
        mail($email_usr,"[$sys_name] ".$t->translate("User Registration"),$message,"From: $ml_newsfromaddr\nReply-To: $ml_newsreplyaddr\nX-Mailer: PHP");
        $msg = $t->translate("Congratulations")."! "
              .$t->translate("You have registered on $sys_name")."."
              ."<p>".$t->translate("Your new username is").": <b>$username</b>"
              ."<p>".$t->translate("You are now being sent a confirmation email to verify your email address")."."
              ."<br>".$t->translate("Visiting the link sent to you in this email will activate your account").".";
		if ($ml_notify) {
			$message  = "Username: $username\n";
			$message .= "Realname: $realname\n";
			$message .= "E-Mail:   $email_usr\n";
			mailuser("admin", "New User has registered", $message);
		}
        $bx->box_full($t->translate("User Registration"), $msg);
        $reg = 1;
        break;
    default:
        break;
    }
}

if (!$reg) {
	$bx->box_begin();
	$bx->box_title($t->translate("Register as a new User"));
	$bx->box_body_begin();
	$bx->box_columns_begin(2);

	htmlp_form_action("PHP_SELF",array());

	$bx->box_column("right","40%","","<b>".$t->translate("Username").":</b> ");
	$bx->box_column("left","60%","",html_input_text("username",20,32,""));

	$bx->box_next_row_of_columns();

	$bx->box_column("right","40%","","<b>".$t->translate("Password").":</b> ");
	$bx->box_column("left","60%","",html_input_password("password",20,32,""));

	$bx->box_next_row_of_columns();

	$bx->box_column("right","40%","","<b>".$t->translate("Confirm Password").":</b> ");
	$bx->box_column("left","60%","",html_input_password("cpassword",20,32,""));

	$bx->box_next_row_of_columns();

	$bx->box_column("right","40%","","<b>".$t->translate("Real name").":</b> ");
	$bx->box_column("left","60%","",html_input_text("realname",20,64,""));

	$bx->box_next_row_of_columns();

	$bx->box_column("right","40%","","<b>".$t->translate("E-Mail").":</b> ");
	$bx->box_column("left","60%","",html_input_text("email_usr",20,128,""));

	$bx->box_next_row_of_columns();

	$bx->box_column("right","40%","","");
	$bx->box_column("left","60%","",html_form_submit($t->translate("Register"),"register"));

	htmlp_form_end();

	$bx->box_columns_end();
	$bx->box_body_end();
	$bx->box_end();
}

require("footer2.inc");
?>