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
require("faqlib2.inc");

security_page_access("admfaq");

$bx = new box("general","96%");

if (isset($change_or_delete)) {
	if (isset($change)) $change = 1;
	else $delete = 1;
}

/*
// Debugging information
// depending on the state of these variables, the script evolves differently
//
// Every action has two steps (step 1 and step 2)
// Step 2 usually inserts the user decision (creation, change or deletion) into the datbase

print "<br>faqid".$faqid;       --> id of the faq we are dealing with (if set)
print "<br>create".$create;		--> we are creating a new fuq (step 1 or step 2)
print "<br>change".$change;		--> we are changing an already existing faq (step 1 or step 2)
print "<br>delete".$delete;		--> we are deleting a faq (step 1 or 2)
print "<br>preview".$preview;	--> in step2, but do not insert it into database yet... lets have first a look at it
*/


	// Nothing has been done => show administration menu

if(!isset($create) && !isset($change) && !isset($delete)) {
	faq_administration($la);
} else {
 	print "<p align=right>";
	htmlp_link("admfaq.php3",array(),$t->translate("Q&A Administration main page"));
}

	// An action has been commited

switch($create) {
	case '1':
		faq_form();
		break;
	case '2':
		if (isset($preview)) {
			faq_preview();
			faq_form();
		} else {
			faq_insert($question,$answer,$la);
		}
		break;
}

switch($change) {
	case '1':
		faq_modification($faqid);
		break;
	case '2':
		if (isset($preview)) {
			$modification = 1;
			faq_preview();
			faq_form();
		} else {
			faq_modify ($faqid,$question,$answer);
      		}
		break;
}


switch($delete) {
	case '1':
		faq_are_you_sure_to_delete($faqid);
		break;
	case '2':
		faq_delete($faqid);
		break;
} 


require("footer2.inc");
?>
