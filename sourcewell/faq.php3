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

$bx = new box("general","85%");
$be = new box("error","");

$db->query("SELECT * FROM faq WHERE language='$la'");
if ($db->num_rows() > 0) {
	$msg = "<ol>";
	while($db->next_record()) {
		$msg .= "<li>".html_link("#".$db->f("faqid"),array(),$db->f("question"));
	}
	$msg .= "</ol><br>";

	$bx->box_full($t->translate("Frequently Asked Questions"), $msg);
	$db->seek(0);

	while($db->next_record()) {
		htmlp_anchor($db->f("faqid"));
	  	$bx->box_full($t->translate("Question").": ".$db->f("question"), "<b>".$t->translate("Answer").":</b> ".$db->f("answer"));
	}
} else {
  	$be->box_full($t->translate("Error"), $t->translate("No Frequently Asked Questions exist"));
}

require("footer2.inc");
?>
