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
// |          Lutz Henckel <lutz.henckel@fokus.fhg.de>                    |
// +----------------------------------------------------------------------+
//
// $Id: rdf.php,v 1.1 2002/05/10 18:32:45 grex Exp $

header("Content-Type: text/plain");

// Disabling cache
header("Cache-Control: no-cache, must-revalidate");     // HTTP/1.1
header("Pragma: no-cache");                             // HTTP/1.0

require "config.inc";
require "lib.inc";

echo "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n";
echo "<!DOCTYPE rss PUBLIC \"-//Netscape Communications//DTD RSS 0.91//EN\"\n";
echo "           \"http://my.netscape.com/publish/formats/rss-0.91.dtd\">\n";
echo "<rss version=\"0.91\">\n";

echo "  <channel>\n";
echo "    <title>".$config_sys_name."</title>\n";
echo "    <link>".$config_sys_url."</link>\n";
echo "    <description>".$config_sys_name." - ".$config_sys_title."</description>\n";
echo "    <language>en-us</language>\n";

echo "  <image>\n";
echo "    <title>".$config_sys_name."</title>\n";
echo "    <url>".$config_sys_url.$config_sys_logo_image."</url>\n";
echo "    <link>".$config_sys_url."</link>\n";
echo "    <description>".$config_sys_name." - ".$config_sys_title."</description>\n";
echo "    <width>66</width>\n";
echo "    <height>73</height>\n";
echo "  </image>\n";

$db = new DB_SourceWell;
$db->query("SELECT * FROM software,counter,auth_user WHERE software.appid=counter.appid AND software.user=auth_user.username AND software.status='A' ORDER BY software.modification DESC limit 10");

$i=0;
while($db->next_record()) {
    echo "  <item>\n";
    echo "    <title>".$db->f("name")." ".$db->f("version")."</title>\n";
    echo "    <link>".$config_sys_url."app.php?id=".$db->f("id")."</link>\n";
    echo "    <description>".$db->f("description")."</description>\n";
    echo "  </item>\n";
    $i++;
} 
echo "  </channel>\n";
echo "</rss>\n";
?>
