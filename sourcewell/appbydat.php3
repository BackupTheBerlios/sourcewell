<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ================================================
#
# Copyright (c) 2001 by
#                Lutz Henckel (lutz.henckel@fokus.gmd.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This files gives the apps by date <--- deprecated: now Index!!!
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

page_open(array("sess" => "SourceWell_Session"));
if (isset($auth) && !empty($auth->auth["perm"])) {
  page_close();
  page_open(array("sess" => "SourceWell_Session",
                  "auth" => "SourceWell_Auth",
                  "perm" => "SourceWell_Perm"));
}

require "header.inc";

if (!isset($lang)) {
     $lang = "English";
}
?>

<!-- content -->
<td WIDTH="99%">
<p>&nbsp;

<?php
if (!$db = mysql_pconnect($db_host, $db_name, $db_password)) {
    mysql_die();
} else {
    $columns = "*";
    $tables = "software,counter,auth_user";
    $where = "DATE_FORMAT(software.modification,'%Y-%m-%d')=DATE_SUB(CURRENT_DATE,INTERVAL \"$day\" DAY) AND software.appid=counter.appid AND software.user=auth_user.username AND software.status='A'";
    $order = "software.modification DESC limit 10";
    if (!$result = mysql_db_query($db_name,"SELECT $columns FROM $tables WHERE $where ORDER BY $order"))
    {
        mysql_die();
    } else {
        while($row = mysql_fetch_array($result)) {
            appdat($row);
        }
        mysql_free_result($result);
    }
}
?>
<!-- end content -->

<?php
require("footer.inc");
?>
