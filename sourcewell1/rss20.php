<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ================================================
#
# Copyright (c) 2001-2006 by
#                Lutz Henckel (lutz.henckel@fokus.fraunhofer.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This is the RSS 2.0 backend
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
###################################################################### 

require "./include/prepend.php3";

header("Content-Type: text/xml");

// Disabling cache
header("Cache-Control: no-cache, must-revalidate");     // HTTP/1.1
header("Pragma: no-cache");                             // HTTP/1.0

require("./include/config.inc");
require("./include/lib.inc");

echo "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n";
echo "<rss version=\"2.0\">\n";

echo "  <channel>\n";
echo "    <title>".$sys_name."</title>\n";
echo "    <link>http:".$sys_url."</link>\n";
echo "    <description>".$sys_name." - ".$sys_title."</description>\n";
echo "    <language>en-us</language>\n";
echo "    <copyright>Copyright 2000-".date("Y")." $org_name</copyright>\n";
echo "    <webMaster>".$_SERVER['SERVER_ADMIN']."</webMaster>\n";
echo "    <lastBuildDate>".gmdate('D, d M Y G:i:s',time())." GMT</lastBuildDate>\n";
echo "    <docs>http://blogs.law.harvard.edu/tech/rss</docs>\n";
echo "    <generator>BerliOS RSS generator</generator>\n";

echo "  <image>\n";
echo "    <title>".$sys_name."</title>\n";
echo "    <url>http:".$sys_logo_small_image."</url>\n";
echo "    <link>http:".$sys_url."</link>\n";
echo "    <description>".$sys_name." - ".$sys_title."</description>\n";
echo "    <width>66</width>\n";
echo "    <height>73</height>\n";
echo "  </image>\n";

$db = new DB_SourceWell;
$db->query("SELECT * FROM software,counter,auth_user WHERE software.appid=counter.appid AND software.user=auth_user.username AND software.status='A' ORDER BY software.modification DESC limit 10");
$i=0;
while($db->next_record()) {
  echo "  <item>\n";
  echo "    <title>".htmlspecialchars($db->f("name"))." ".$db->f("version")."</title>\n";
  echo "    <link>http:".$sys_url."appbyid.php?id=".$db->f("appid")."</link>\n";
  echo "    <description>".wrap(htmlspecialchars($db->f("description")))."</description>\n";
  echo "    <author>".$db->f('email')." (".htmlspecialchars($db->f('developer')).")</author>\n";
  echo "    <pubDate>".gmdate('D, d M Y G:i:s',mktimestamp($db->f("modification")))." GMT</pubDate>\n";
  echo "    <guid>http:".$sys_url."appbyid.php?id=".$db->f("appid")."</guid>\n";
  echo "    <comment>http:".$sys_url."appbyid.php?id=".$db->f("appid")."</comment>\n";
  echo "  </item>\n";
  $i++;
} 

echo "  </channel>\n";
echo "</rss>\n";
?>
