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

security_page_access("remindme");

$bx = new box("general","");


$db->query("SELECT * FROM auth_user WHERE username='$username' AND email_usr='$email_usr'");
if ($db->num_rows() > 0) {
  $db->next_record();

  $message = $t->translate("Your Username and Password for $sys_name is").":\n\n"
  ."        ".$t->translate("User").": ".$db->f("username")."\n"
  ."        ".$t->translate("Password").": ".$db->f("password")."\n\n"
  .$t->translate("Please keep this e-mail for further reference").".\n\n"
  .$t->translate(" -- the $sys_name crew")."\n";

  mail($email_usr, "[$sys_name] ".$t->translate("Remind me"), $message,
  "From: $ml_newsfromaddr\nReply-To: $ml_newsreplyaddr\nX-Mailer: PHP");
  $bx->box_full($t->translate("Remind me"), $t->translate("You will get your Password by e-mail in a couple of minutes"));
} else {
  $be->box_full($t->translate("Error"), $t->translate("Either your Username or E-Mail Address is unknown").".<br>".$t->translate("Please try again")."!");
}

require("footer2.inc");
?>