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
require("app2.inc");

security_page_access("faq");

$bx = new box("general","");
$be = new box("error","");

if (!$ml_list) {
  $be->box_full($t->translate("Error"), $t->translate("The Mailing Lists are not enabled").".");
} else {
				// Check if there was a submission
  $subs = 0;
  while (is_array($HTTP_POST_VARS) && list($key, $val) = each($HTTP_POST_VARS)) {
    switch ($key) {
      case "subscribe":		// subscribe newsletter
        $email_usr = trim($email_usr);
        $password = trim($password);
        $cpassword = trim($cpassword);
        if (empty($email_usr) || empty($password)  || empty($cpassword)) { // Do we have all necessary data?
          $be->box_full($t->translate("Error"), $t->translate("Please enter")." <b>".$t->translate("Username")."</b>, <b>".$t->translate("Password")."</b> ".$t->translate("and")." <b>".$t->translate("E-Mail")."</b>!");
          break;
        }

        if (strcmp($password,$cpassword)) { // password are identical?
          $be->box_full($t->translate("Error"), $t->translate("The passwords are not identical").". ".$t->translate("Please try again")."!");
          break;
        }
					  // send mail
        $message = "";
        if ($period == "daily") {		// Daily Newsletter
	  mail($ml_newsreqaddr,"subscribe $password",$message,"From: $email_usr\nReply-To: $email_usr\nX-Mailer: PHP");
	  $msg = $t->translate("Congratulations")."! "
	  .$t->translate("You have subscribed to $sys_name daily Newsletter")."."
	  ."<p>".$t->translate("You are now being sent a confirmation email to verify your email address").".";
	  $bi->box_full($t->translate("Subscribe daily Newsletter"), $msg);
        } else { // Weekly Newsletter
	  mail($ml_weeklynewsreqaddr,"subscribe $password",$message,"From: $email_usr\nReply-To: $email_usr\nX-Mailer: PHP");
	  $msg = $t->translate("Congratulations")."! "
	  .$t->translate("You have subscribed to $sys_name weekly Newsletter")."."
	  ."<p>".$t->translate("You are now being sent a confirmation email to verify your email address").".";
	  $bi->box_full($t->translate("Subscribe weekly Newsletter"), $msg);
        }
        $subs = 1;
        break;
      default:
        break;
    }
  }

  if (!$subs) {
    $bx->box_begin();
    $bx->box_title($t->translate("Subscribe Newsletter"));
    $bx->box_body_begin();
    $bx->box_columns_begin(2);

    htmlp_form_action("PHP_SELF",array());
        
    $bx->box_column("right","40%","","<b>".$t->translate("E-Mail").":</b> ");
    $bx->box_column("left","60%","",html_input_text("email_usr",20,128,""));

    $bx->box_next_row_of_columns();

    $bx->box_column("right","40%","","<b>".$t->translate("Password").":</b> ");
    $bx->box_column("left","60%","",html_input_password("password",20,32,""));

    $bx->box_next_row_of_columns();

    $bx->box_column("right","40%","","<b>".$t->translate("Confirm Password").":</b> ");
    $bx->box_column("left","60%","",html_input_password("cpassword",20,32,""));

    $bx->box_next_row_of_columns();

    $bx->box_column("right","40%","","<b>".$t->translate("Periodicity").":</b> ");
    $bx->box_column("left","60%","",html_radio("period","daily","").$t->translate("daily")." &nbsp; &nbsp; ".html_radio("period","weekly","yes").$t->translate("weekly"));

    $bx->box_next_row_of_columns();

    $bx->box_column("right","40%","","&nbsp;");
    $bx->box_column("left","60%","",html_form_submit($t->translate("Subscribe"),"subscribe"));

    $bx->box_columns_end();
    $bx->box_body_end();
    $bx->box_end();
  }
}

require("footer2.inc");
?>
