<?php

######################################################################
# SourceWell 2
# ================================================
#
# This script shows the text for the license given as parameter
# If no license is specified a list of licenses is given
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

security_page_access("licenseText");

$bx = new box("general","95%");

if (is_not_set_or_empty ($license)) {

    $db->query("SELECT DISTINCT * FROM licenses ORDER BY license ASC");

    $bx->box_begin();
    $bx->box_title($t->translate("Licenses"));
    $bx->box_body_begin();
    $bx->box_columns_begin(3);

    $bx->box_column("center","","","<b>"._("No")."</b>");
    $bx->box_column("center","","","<b>"._("Apps")."</b>");
    $bx->box_column("left","","","<b>"._("License")."</b>");

    $i = 1;
    while($db->next_record()) {
        $db2 = new DB_SourceWell;
        $db2->query("SELECT COUNT(*) FROM software WHERE license='".$db->f("license")."' AND status='A'");
        $db2->next_record();
        $num = "[".sprintf("%03d",$db2->f("COUNT(*)"))."]";

        $bx->box_next_row_of_columns();
        $bx->box_column("center","","",$i);
        $bx->box_column("center","","",html_link("appbylic.php3",array("license" => $db->f("license")),$num));
# FIXME: The OSI aproved: in front of license should be deleted in the link :-)
        $bx->box_column("left","","",html_link("PHP_SELF",array("license" => $db->f("license")), $db->f("license")));

        $i++;
    }

    $bx->box_columns_end();
    $bx->box_body_end();
    $bx->box_end();

} else {

    $bx->box_begin();
    $bx->box_title($license);
    $bx->box_body_begin();

    $db->query("SELECT url FROM licenses WHERE license='$license'");
    $db->next_record();
    include($db->f("url"));

    $bx->box_body_end();
    $bx->box_end();

}

require("footer2.inc");
?>