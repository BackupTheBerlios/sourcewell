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
# This file sends the daily/weekly newsletters with the announcements
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
###################################################################### 

require("config.inc");
require("lib.inc");

$db = new DB_SourceWell;

if (!isset($period)) $period = "daily";
if ($msg = nlmsg($period)) {
  switch ($period) {
    case "weekly":
      $subj = "$sys_name weekly newsletter for ".date("l dS of F Y");
      mail($ml_weeklynewstoaddr, $subj, $msg,
      "From: $ml_newsfromaddr\nReply-To: $ml_newsreplyaddr\nX-Mailer: PHP");
      echo "$sys_name weekly newsletter sent at ".date("l dS of F Y H:i:s")."\n";
      break;
    case "daily":
    default:
      $subj = "$sys_name daily newsletter for ".date("l dS of F Y");
      mail($ml_newstoaddr, $subj, $msg,
      "From: $ml_newsfromaddr\nReply-To: $ml_newsreplyaddr\nX-Mailer: PHP");
      echo "$sys_name daily newsletter sent at ".date("l dS of F Y H:i:s")."\n";
      break;
  }
} else {
  echo "No application at ".date("l dS of F Y H:i:s")."\n";
}
?>
