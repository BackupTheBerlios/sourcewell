<?php

##
# In order to use this script, you have to copy it into the 
# SourceWell root directory and the run it with a php command line
# or access it through your web browser.
##

######################################################################
# SourceWell 2
# ================================================
#
# This script should be used to change from the SourceWell database
# 1.0.13 version to its 1.0.14 version
# please, see mysql-1.0.13-to-mysql-1.0.14.sql for further details
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

$db = new DB_SourceWell;
$db2 = new DB_SourceWell;

$set[] = "license ='The GNU General Public License (GPL)'";
$where[] = "license ='GPL'";

$set[] = "license ='The GNU Library or \"Lesser\" Public License (LGPL)'";
$where[] = "license ='LGPL'";

$set[] = "license ='The BSD license'";
$where[] = "license ='BSD type'";

$set[] = "license ='The MIT license'";
$where[] = "license ='MIT'";

$set[] = "license ='The Artistic license'";
$where[] = "license ='Artistic License'";

$set[] = "license ='The Qt Public License (QPL)'";
$where[] = "license ='Q Public License (QPL)'";

$set[] = "license ='The IBM Public License'";
$where[] = "license ='IBM Public License'";

$set[] = "license ='The zlib/libpng license'";
$where[] = "license ='Zlib License'";

$set[] = "license ='The Apache Software License'";
$where[] = "license ='Apache style'";

$set[] = "license ='The Mozilla Public License 1.1 (MPL 1.1)'";
$where[] = "license ='Mozilla Public License (MPL)'";

$set[] = "license ='The Jabber Open Source License'";
$where[] = "license ='Jabber Open Source License'";

$set[] = "license ='The Sleepycat License'";
$where[] = "license ='Berkeley Database License'";

$set[] = "license ='The Sun Public License'";
$where[] = "license ='Sun Public License'";

$set[] = "license ='The Eiffel Forum License'";
$where[] = "license ='Eiffel Forum Freeware License'";

$set[] = "license ='The W3C License'";
$where[] = "license ='W3C Software'";

$set[] = "license ='The BSD license'";
$where[] = "license ='FreeBSD'";

$set[] = "license ='The BSD license'";
$where[] = "license ='OpenBSD'";

$set[] = "license ='The MIT license'";
$where[] = "license ='X11 License'";

# NOT OS
 
$set[] = "license ='Freely Distributable'";
$where[] = "license ='freely distributable'";

# $set[] = "license ='Freeware'$where[] = "license ='Freeware'";

$set[] = "license ='Free for non-commercial use'";
$where[] = "license ='free for non-commercial use'";

$set[] = "license ='OSI Approved (Open Source)'";
$where[] = "license ='Open Source'";

$set[] = "license ='Free To Use But Restricted'";
$where[] = "license ='free to use but restricted'";

# $set[] = "license ='Public Domain'$where[] = "license ='Public Domain'";

$set[] = "license ='Other/Proprietary License'";
$where[] = "license ='commercial'";

# $set[] = "license ='Shareware'$where[] = "license ='Shareware'";

$set[] = "license ='The PHP License'";
$where[] = "license ='PHP License'";

$set[] = "license ='The SUN Community Source License'";
$where[] = "license ='Sun Community Source License'";

$set[] = "license ='The Zope Public License (ZPL)'";
$where[] = "license ='Zope Public License (ZPL)'";

$set[] = "license ='The Clarified Artistic License'";
$where[] = "license ='Clarified Artistic License'";

$set[] = "license ='The Netscape Public License (NPL)'";
$where[] = "license ='Netscape Public License (NPL)'";

$set[] = "license ='The Latex Project Public License (LPPL)'";
$where[] = "license ='LaTeXProject Public License'";

$set[] = "license ='The Aladdin Free Public License (AFPL)'";
$where[] = "license ='Artifex Public License'";

$set[] = "license ='The Arphic Public License'";
$where[] = "license ='Arphic Public License'";

$set[] = "license ='The Cryptix General License'";
$where[] = "license ='Cryptix General License'";

# $set[] = "license ='Free Trail'$where[] = "license ='Free Trail'";

$set[] = "license ='The FreeType License'";
$where[] = "license ='FreeType License'";

$set[] = "license ='The Interbase Public License'";
$where[] = "license ='Interbase Public License'";

$set[] = "license ='The Open Compatibility License'";
$where[] = "license ='Open Compability License'";

$set[] = "license ='The Phorum License'";
$where[] = "license ='Phorum'";

$set[] = "license ='The Plan 9 Open Source License'";
$where[] = "license ='Plan 9 Open Source License'";

$set[] = "license ='Source-available Commercial'";
$where[] = "license ='source-available commercial'";

# $set[] = "license ='UCL/LBL'$where[] = "license ='UCL/LBL'";

$set[] = "license ='Other/Proprietary License'";
$where[] = "license ='Other'";

## -----------------------   -------------------------- -----------------------
## Table Software
## Take the licenses updates and
##        $set = "license =''$where = "license =''; (just change licenses with software and delete url='...')
## GPL & Artistic <---

for ($i=0; $i < sizeof($set); $i++) {
    $where2 = $where[$i];
    $set2 = $set[$i];

    $db->query("SELECT * FROM software WHERE $where2");
    while ($db->next_record()) {
        $db2->query("UPDATE software SET $set2, modification='".$db->f("modification")."' WHERE appid='".$db->f("appid")."'");
        print "UPDATE software SET $set2, modification='".$db->f("modification")."' WHERE appid='".$db->f("appid")."'<br>";
    }
}



?>