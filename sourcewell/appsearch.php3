<?php

######################################################################
# SourceWell2: Software Announcement & Retrieval System
# ================================================
#
# Copyright (c) 2001 by
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This file proceeds search of applications by their name
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

require("header2.inc");
require("search2.inc");
require("app2.inc");

security_page_access("appsearch");

$bx = new box("general","96%");

// When there's a search for a blank line, we look for "xxxxxxxx"
if (!isset($search) || $search=="") {
  $search = "xxxxxxxx";
}

// $iter is a variable for printing the Top Statistics in steps of 10 apps
if (!isset($iter)) $iter=0;
else $iter*=10;

// FIXME: apps that appear in superior matches should not be repeated
// TODO: does it make sense to show so much information? 
// WISH: have a navigation bar with the different options

// 1a Section
search_for_section($search);

// 1b Category
search_for_categories($search);

// 2. Exact match
$count = search_for_exact_match($search);	

// 3. Search parameters for the apps
// TODO: there are no such parameters yet

// 4a Partial Match in the name (single word match)
$count += search_for_partial_match_single_word($search, $count);

// If there are more than numiter apps, then a link to show more apps is given
/*
if ($numiter > 1) {
  $urlquery = array("search" => ($search), "by" => $by);
  show_more ($iter,$numiter,"appsearch.php3",$urlquery);
}
*/

// 4b Partial Match in the name
$count += search_for_partial_match($search, $count);

// 5. Global match in the despcription
$count += search_for_match_in_description ($search, $count);

// 6. Partial Match in the description
$count += search_for_partial_match_in_description ($search, $count);

// FIXME: if nothing is found:
search_nothing_found($count);

// FIXME: Search in Google, Freshmeat, developer.berlios, sourceforge, savannah, icewalk

/*
// Debugging info to know what the array contains
for ($i=0; $i<sizeof($array_with_already)+1; $i++) {
    print $array_with_already[$i]."<br>";
}
*/

require("footer2.inc");
?>