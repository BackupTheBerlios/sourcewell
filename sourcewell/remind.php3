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

security_page_access("remind");

$bx = new box("general","");

$bx->box_begin();
$bx->box_title($t->translate("Forgot Password"));
$bx->box_body_begin();
$bx->box_columns_begin(2);

htmlp_form_action("remindme.php3",array());

$bx->box_column("right","40%","","<b>".$t->translate("Username").":</b> ");
$bx->box_column("left","60%","",html_input_text("username",20,32,""));

$bx->box_next_row_of_columns();

$bx->box_column("right","40%","","<b>".$t->translate("E-Mail").":</b> ");
$bx->box_column("left","60%","",html_input_text("email_usr",20,32,""));

$bx->box_next_row_of_columns();

$bx->box_column("right","40%","","");
$bx->box_column("left","60%","",html_form_submit($t->translate("Remind me"),"remind"));

$bx->box_columns_end();
$bx->box_body_end();
$bx->box_end();

require("footer2.inc");
?>
