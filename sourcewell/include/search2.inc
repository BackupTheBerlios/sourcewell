<?php

######################################################################
# SourceWell 2
# ================================================
#
# Copyright (c) 2001 by
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
#
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

function search_for_section($search)
{
    global $db, $bx;

    $db->query("SELECT DISTINCT(section) FROM categories WHERE section='$search'");
    if ($db->num_rows() > 0) {
        $db->next_record();
        $bx->box_strip("<center><b>See also Section ".html_link("categories.php3",array(section => $db->f("section")),$db->f("section"))."</b></center>");
    }
}

function search_for_categories($search)
{
    global $db, $bx;

    $db->query("SELECT * FROM categories WHERE category='$search'");
    if ($db->num_rows() > 0) {

        while($db->next_record()) {
            $bx->box_strip("<center><b>See also Category ".html_link("appbycat.php3",array(section => $db->f("section"), category => $db->f("category")),$db->f("section")."/".$db->f("category"))."</b></center>");
        }
    }
}

function search_for_exact_match($search)
{
    global $db, $bx, $array_with_already;

    $db->query("SELECT * FROM software,counter WHERE software.appid=counter.appid AND software.status='A' AND software.name='$search'");
    if ($db->num_rows() > 0) {
        $bx->box_strip("<center><b>Exact match</b></center>");

        while ($db->next_record()) {
            $array_with_already[] = $db->f("name");
            app_show_summary($db->f("appid"),$search);
	    return 1;
        }
    } else {
        return 0;
    }
}

// FIXME: three conditions:
// FIXME: LIKE '$search %' for starting word
// FIXME: LIKE ' % $search %' for a condition in the middle
// FIXME: LIKE '% $search' for the last word

function search_for_partial_match_single_word($search, $count)
{
    global $db;

    $db->query("SELECT * FROM software WHERE status='A' AND (name LIKE '% $search%' OR name LIKE '$search %' OR name LIKE '$search %') ORDER BY modification DESC");
    if ($db->num_rows() > 0) {
        return _showIt(&$db,"Matches a single word in the name",$count, $search);
    } else {
        return 0;
    }
}

function search_for_partial_match($search, $count)
{
    global $db;

    $db->query("SELECT * FROM software WHERE status='A' AND name LIKE '%$search%' ORDER BY modification DESC");
    if ($db->num_rows() > 0) {
        return _showIt(&$db,"Partial match in the name",$count, $search);
    } else {
        return 0;
    }
}

function search_for_match_in_description ($search, $count)
{
    global $db;

    $db->query("SELECT * FROM software WHERE status='A' AND description LIKE '% $search %' ORDER BY modification DESC");
    if ($db->num_rows() > 0) {
        return _showIt(&$db,"Exact match in the description",$count, $search);
    } else {
        return 0;
    }
}

function search_for_partial_match_in_description ($search, $count)
{
    global $db;

    $db->query("SELECT appid FROM software WHERE status='A' AND description LIKE '%$search%' ORDER BY modification DESC");
    if ($db->num_rows() > 0) {
        return _showIt(&$db,"Partial match in the description",$count, $search);
    } else {
        return 0;
    }
}

function search_nothing_found($count)
{
    global $bx;

    if ($count == 0) {
        $bx->box_full(_("Search"),_("No Application found"));
    }
}

function _showIt($db, $message, $count, $search)
{
    global $array_with_already, $bx;

    $j = 0;
    while ($db->next_record() && $i < (10 - $count)) {
        if (!_inArray($array_with_already,$db->f("name"))) {
            if ($j==0) {
                $bx->box_strip("<center><b>".$message."</b></center>");
            }
            app_show_summary($db->f("appid"), $search);
            $array_with_already[] = $db->f("name");
            $i++;
            $j++;
        }
    }
    return $db->num_rows();
}

function _inArray($array, $value)
{
    for ($i=0; $i < sizeof($array)+1; $i++) {
        if ($array[$i] == $value) {
            return 1;
        }
    }
}
?>