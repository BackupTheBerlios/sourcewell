<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ====================================================
#
# Copyright (c) 2001-2004 by
#                Lutz Henckel (lutz.henckel@fokus.fraunhofer.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# Registration form for users
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################  

require("./include/prepend.php3");

page_open(array("sess" => "SourceWell_Session"));
if (isset($auth) && !empty($auth->auth["perm"])) {
  page_close();
  page_open(array("sess" => "SourceWell_Session",
                  "auth" => "SourceWell_Auth",
                  "perm" => "SourceWell_Perm"));
}

require("./include/header.inc");

$bx = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php

###
### Submit Handler
###

## Get a database connection
$db = new DB_SourceWell;

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
        list($email_usr, $rest) = split("\n", $email_usr, 2);
	$email_usr = trim($email_usr);
        if (empty($username) || empty($password)  || empty($cpassword) || empty($email_usr)) { // Do we have all necessary data?
            $be->box_full($t->translate("Error"), $t->translate("Please enter")." <b>".$t->translate("Username")."</b>, <b>".$t->translate("Password")."</b> ".$t->translate("and")." <b>".$t->translate("E-Mail")."</b>!");
            break;
        }
        if (strlen($rest) > 0) {
          $be->box_full($t->translate("Error"), $t->translate("Invalid email address").".");
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
                  ."https:".$sys_url."verify.php?confirm_hash=$u_id\n\n"
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
	$bx->box_body_begin()
?>
<table border=0 cellspacing=0 cellpadding=3>
<tr>
<form method="post" action="<?php $sess->pself_url() ?>">
<td align=right><?php echo $t->translate("Username") ?>:</td><td><input type="text" name="username" size=20 maxlength=32 value=""></td>
</tr>
<tr valign=middle align=left>
<td align=right><?php echo $t->translate("Password") ?>:</td><td><input type="password" name="password" size=20 maxlength=32 value=""></td>
</tr>
<tr valign=middle align=left>
<td align=right><?php echo $t->translate("Confirm Password") ?>:</td><td><input type="password" name="cpassword" size=20 maxlength=32 value=""></td>
</tr>
<tr valign=middle align=left>
<td align=right><?php echo $t->translate("Realname") ?>:</td><td><input type="text" name="realname" size=20 maxlength=64 value=""></td>
</tr>
<tr valign=middle align=left>
<td align=right><?php echo $t->translate("E-Mail") ?>:</td><td><input type="text" name="email_usr" size=20 maxlength=128 value=""></td>
</tr>
<tr valign=middle align=left>
<td></td>
<td>
<?php
echo "<input type=\"submit\" name=\"register\" value=\"".$t->translate("Register")."\">";
?>
</td>
</tr>
</form>
</table>
<?php
	$bx->box_body_end();
	$bx->box_end();
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
        list($email_usr, $rest) = split("\n", $email_usr, 2);
?>
