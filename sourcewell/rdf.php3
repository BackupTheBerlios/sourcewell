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
# This is the RDF-type document
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
###################################################################### 

header("Content-Type: text/plain");

require "config.inc";
require "lib.inc";

echo "<?xml version=\"1.0\"?>\n";
echo "\n";
echo "<rdf:RDF\n";
echo "xmlns:rdf=\"http://www.w3.org/1999/02/22-rdf-syntax-ns#\"\n";
echo "xmlns=\"http://my.netscape.com/rdf/simple/0.9/\">\n";
echo "\n";

echo "<channel>\n";
echo "<title>".$sys_name."</title>\n";
echo "<link>".$sys_url."</link>\n";
echo "<description>".$sys_name." - ".$sys_title."</description>\n";
echo "</channel>\n";
echo "\n";

echo "<image>\n";
echo "<title>".$sys_name."</title>\n";
echo "<url>".$sys_url.$sys_logo_image."</url>\n";
echo "<link>".$sys_url."</link>\n";
echo "</image>\n";
echo "\n";

$db = new DB_SourceWell;
$db->query("SELECT * FROM software,counter,auth_user WHERE software.appid=counter.appid AND software.user=auth_user.username AND software.status='A' ORDER BY software.modification DESC limit 10");
$i=0;
while($db->next_record()) {
  echo "<item>\n";
  echo "<title>".$db->f("name")." ".$db->f("version")."</title>\n";
  echo "<link>".$sys_url."appbyid.php3?id=".$db->f("appid")."</link>\n";
  echo "</item>\n";
  echo "\n";
  $i++;
} 

echo "</rdf:RDF>\n";
?>
