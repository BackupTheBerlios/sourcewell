<?php
/* vim: set expandtab tabstop=4 shiftwidth=4: */
// +----------------------------------------------------------------------+
// |        SourceWell 2 - The GPL Software Announcement System           |
// +----------------------------------------------------------------------+
// |      Copyright (c) 2001-2002 BerliOS, FOKUS Fraunhofer Institut      |
// +----------------------------------------------------------------------+
// | This program is free software. You can redistribute it and/or modify |
// | it under the terms of the GNU General Public License as published by |
// | the Free Software Foundation; either version 2 or later of the GPL.  |
// +----------------------------------------------------------------------+
// | Authors: Gregorio Robles <grex@scouts-es.org>                        |
// +----------------------------------------------------------------------+
//
// $Id: search.php,v 1.1 2002/05/10 23:12:50 grex Exp $

require('start.inc');
config_inc('search');
//require('app2.inc');

// When there's a search for a blank line, we look for 'xxxxxxxx'
if (!isset($search) || $search=='') {
  $search = 'xxxxxxxx';
}

// $iter is a variable for printing the Top Statistics in steps of 10 apps
if (!isset($iter)) {
     $iter=0;
} else {
    $iter*=10;
}

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

// 4b Partial Match in the name
$count += search_for_partial_match($search, $count);

// 5. Global match in the despcription
$count += search_for_match_in_description ($search, $count);

// 6. Partial Match in the description
$count += search_for_partial_match_in_description($search, $count);

// TODO: if nothing is found: advanced search
search_nothing_found($count);

// TODO: Search in Google, Freshmeat, developer.berlios, sourceforge, savannah, icewalk

/*
// Debugging info to know what the array contains
for ($i=0; $i<sizeof($array_with_already)+1; $i++) {
    print $array_with_already[$i].'<br>';
}
*/

config_inc('pie');
?>