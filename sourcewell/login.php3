<?php

######################################################################
# SourceWell 2
# ===========================================================
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

$login = 1;

page_open(array("sess" => "SourceWell_Session",
                "auth" => "SourceWell_Auth",
                "perm" => "SourceWell_Perm"));

require("header2.inc");

security_page_access("login");

$bx = new box("general","95%");

if ($perm->have_perm("user_pending")) {
  $be->box_full($t->translate("Error"), $t->translate("Access denied"));
  $auth->logout();
} else {
  $msg = $t->translate("You are logged in as")." <b>".$auth->auth["uname"]."</b> ".$t->translate("with")." "
  ."<b>".$auth->auth["perm"]."</b> ".$t->translate("permission")."."
  ."<br>".$t->translate("Your authentication is valid until")." <b>".timestr($auth->auth["exp"])."</b>";

  $bx->box_full($t->translate("Welcome to")." ".$sys_name, $msg);
}

require("footer2.inc");
?>