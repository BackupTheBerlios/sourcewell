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
# This page enables (authenticated) users to change their parameters
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

require("header2.inc");

security_page_access("chguser");

$bx = new box("general","70%");

if ($perm->have_perm("anonymous")) {
  $be->box_full(_("Error"),_("Access denied"));
} else {

// Check if there was a submission
  while (is_array($HTTP_POST_VARS) 
		  && list($key, $val) = each($HTTP_POST_VARS)) {
    switch ($key) {
      case "u_edit": // Change user parameters
        if($auth->auth["uid"] == $u_id) { // user changes his own account
	  $password = trim($password);
	  $cpassword = trim($cpassword);
	  $realname = trim($realname);
	  $email_usr = trim($email_usr);
          if (strcmp($password,$cpassword)) { // password are identical?
            $be->box_full(_("Error"), _("The passwords are not identical").". "._("Please try again")."!");
            break;
          }
          $query = "UPDATE auth_user SET password='$password', realname='$realname', email_usr='$email_usr', modification_usr=NOW() WHERE user_id='$u_id'";
          $db->query($query);
          if ($db->affected_rows() == 0) {
            $be->box_full(_("Error"), _("Change User Parameters failed").":<br>$query");
             break;
          }
          $bx->box_full(_("Change User Parameters"), _("Password and/or E-Mail Address of")." <b>". $auth->auth["uname"] ."</b> "._("is changed").".");
	  if ($ml_notify) {
	    $message  = "Username: ".$auth->auth["uname"]."\n";
	    $message .= "Realname: $realname\n";
	    $message .= "E-Mail:   $email_usr\n";
	    mailuser("admin", "User parameters has changed", $message);
	  }
        } else {
          $be->box_full(_("Error"), _("Access denied"));
        }
        break;
      default:
        break;
    }
  }

  $db->query("select * from auth_user where username='".$auth->auth["uname"]."'");
  $db->next_record();

  $bx->box_begin();
  $bx->box_title(_("Change User Parameters"));
  $bx->box_body_begin();
  $bx->box_columns_begin(2);

  htmlp_form_action("PHP_SELF",array(),"POST");
  htmlp_form_hidden("u_id",$db->f("user_id"));

  $bx->box_column("right","30%","","<b>"._("Username").":</b>");
  $bx->box_column("left","70%","",$db->f("username"));

  $bx->box_next_row_of_columns();

  $bx->box_column("right","30%","","<b>"._("Password").":</b>");
  $bx->box_column("left","70%","",html_input_password("password", 20, 32, $db->f("password")));

  $bx->box_next_row_of_columns();

  $bx->box_column("right","30%","","<b>"._("Confirm Password").":</b>");
  $bx->box_column("left","70%","",html_input_password("cpassword", 20, 32, $db->f("password")));

  $bx->box_next_row_of_columns();

  $bx->box_column("right","30%","","<b>"._("Realname").":</b>");
  $bx->box_column("left","70%","",html_input_text("realname", 20, 64, $db->f("realname")));

  $bx->box_next_row_of_columns();

  $bx->box_column("right","30%","","<b>"._("E-Mail").":</b>");
  $bx->box_column("left","70%","",html_input_text("email_usr", 20, 128, $db->f("email_usr")));

  $bx->box_next_row_of_columns();

  $bx->box_column("right","30%","","<b>"._("Modification").":</b>");
  $bx->box_column("left","70%","",timestr(mktimestamp($db->f("modification_usr"))));

  $bx->box_next_row_of_columns();

  $bx->box_column("right","30%","","<b>"._("Creation").":</b>");
  $bx->box_column("left","70%","",timestr(mktimestamp($db->f("creation_usr"))));

  $bx->box_next_row_of_columns();

  $bx->box_column("right","30%","","<b>"._("Permissions").":</b>");
  $bx->box_column("left","70%","",$db->f("perms"));

  $bx->box_next_row_of_columns();

  $bx->box_column("right","30%","","");
  $bx->box_column("left","70%","",html_form_submit("Change","u_edit"));

  htmlp_form_end();

  $bx->box_columns_end();
  $bx->box_body_end();
  $bx->box_end();



/*
  echo "<table border=0 align=\"center\" cellspacing=0 cellpadding=3>\n";
  $db->query("select * from auth_user where username='".$auth->auth["uname"]."'");
  while ($db->next_record()) {
?>
<form method="post" action="<?php $sess->pself_url() ?>">
<tr valign=middle align=left>
<td align=right><?php echo "<b>"._("Username") ?>:</td><td><?php $db->p("username") ?></td></tr>
<tr>
<td align=right><?php echo "<b>"._("Password") ?>:</td><td><input type="password" name="password" size=20 maxlength=32 value="<?php $db->p("password") ?>"></td></tr>
<tr>
<td align=right><?php echo "<b>"._("Confirm Password") ?>:</td><td><input type="password" name="cpassword" size=20 maxlength=32 value="<?php $db->p("password") ?>"></td></tr>
<tr>
<td align=right><?php echo "<b>"._("Realname") ?>:</td><td><input type="text" name="realname" size=20 maxlength=64 value="<?php $db->p("realname") ?>"></td></tr>
<tr>
<td align=right><?php echo "<b>"._("E-Mail") ?>:</td><td><input type="text" name="email_usr" size=20 maxlength=128 value="<?php $db->p("email_usr") ?>"></td></tr>
<tr>
<?php
    $time = mktimestamp($db->f("modification_usr"));
?>
<td align=right><?php echo "<b>"._("Modification") ?>:</td><td><?php echo timestr($time); ?></td></tr>
<tr>
<?php
    $time = mktimestamp($db->f("creation_usr"));
?>
<td align=right><?php echo "<b>"._("Creation") ?>:</td><td><?php echo timestr($time); ?></td></tr>
<tr>
<td align=right><?php echo "<b>"._("Permission") ?>:</td><td><?php $db->p("perms") ?></td></tr>
<tr>
<td></td>
<td><input type="hidden" name="u_id"   value="<?php $db->p("user_id") ?>">
<?php
    echo "<input type=\"submit\" name=\"u_edit\" value=\""."<b>"._("Change")."\">";
?>
</td></tr>
</form>
<?php
  }
?>
</table>
<?php
  $bx->box_body_end();
  $bx->box_end();
}
?>
<!-- end content -->

<?php
*/

require("footer2.inc");
?>
