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

security_page_access("app_edi");

$bx = new box("general","95%");

if (!isset($name)) {
	app_previous_form();
} else {
  	if (empty($name)) {
    		$be->box_full($t->translate("Error"), $t->translate("Parameter missing: Application Name"));
  	} else {
		if (isset($submit) && !empty($submit)) {
			if (empty($version)) $be->box_full($t->translate("Error"), $t->translate("Parameter missing: Version Number"));
			else app_insert();
		} else {
			if (isset($preview)) app_preview();
			app_form();
		}
	}
}

require("footer2.inc");
?>