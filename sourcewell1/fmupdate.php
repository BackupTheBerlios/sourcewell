<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ====================================================
#
# Copyright (c) 2001-2002 by
#                Lutz Henckel (lutz.henckel@fokus.gmd.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# (explanation) 
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

require("./include/prepend.php3");

page_open(array("sess" => "SourceWell_Session",
                "auth" => "SourceWell_Auth",
                "perm" => "SourceWell_Perm"));

require "./include/header.inc";
require("./include/cmtlib.inc");

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
if (!$perm->have_perm("editor")) {
	$be->box_full($t->translate("Error"), $t->translate("Access denied"));
} else {
	echo "<p><b>Automatic Software Update</b>\n";
	$string = "";
	$fcontents = file("http://freshmeat.net/backend/oneweek.html");
	while (list(, $line) = each($fcontents)) {
    	$string .= trim($line);
	}
	$items = explode("</tr>",$string);
	while(list(, $val) = each($items)) {
//		echo "<br>val: $val\n";
		if (ereg("<tr><td><a href=.*>(.*)</a></td><td><a href=.*>(.*)</a></td><td><a href=.*>(.*)</a></td><td>(.*)</td><td>(.*)</td>", $val, $regs)) {
			echo "<p>Name: $regs[1]\n";
			echo "<br>Type: $regs[2]\n";
			echo "<br>Version: $regs[3]\n";
			echo "<br>License: $regs[4]\n";
			echo "<br>Description: $regs[5]\n";

			switch ($regs[2]) {
			case "Default":
				$type = "S";
				if (strstr($regs[3], "a")) $type = "D";
				if (strstr($regs[3], "alpha")) $type = "D";
				if (strstr($regs[3], "Alpha")) $type = "D";
				if (strstr($regs[3], "ALPHA")) $type = "D";
				if (strstr($regs[3], "b")) $type = "D";
				if (strstr($regs[3], "beta")) $type = "D";
				if (strstr($regs[3], "Beta")) $type = "D";
				if (strstr($regs[3], "BETA")) $type = "D";
				if (strstr($regs[3], "rc")) $type = "D";
				if (strstr($regs[3], "RC")) $type = "D";
				if (strstr($regs[3], "pr")) $type = "D";
				if (strstr($regs[3], "PR")) $type = "D";
				break;
			case "Stable":
				$type = "S";
				break;
			case "Development":
			case "Unstable":
				$type = "D";
				break;
			Default:
				$type = "D";
				break;
			}
			// Look if application is already in table
			$query = "SELECT * FROM software WHERE name=";
			if (ereg("\"", $regs[1]))
				$query .= "'".$regs[1]."'";
			else
				$query .= "\"".$regs[1]."\"";
			$query .= " AND type=\"$type\"";
			$db->query($query);
  			if ($db->next_record()) {
				if ($regs[3] > $db->f("version")) {

					// Update software with new version
					$query = "UPDATE software SET version=\"$regs[3]\",user=\"helix\" WHERE appid=\"".$db->f("appid")."\"";
					$db->query($query);
					echo "<p>Update: ".$db->f("name")."; Type: ".$type."; Old Version: ".$db->f("version")."; New Version: ".$regs[3]."\n";
					echo "<br>$query\n";

					// Insert new history entry for new version
					$query = "INSERT history SET appid=\"".$db->f("appid")."\",user_his=\"helix\",version_his=\"$regs[3]\",creation_his=NOW()";
					echo "<br>$query\n";
					$db->query($query);

					// Send notification by email to editors
					if ($ml_notify) {
						$message = "automatic update application ".$db->f("name")." ".$regs[3]." (".typestr($type).") by helix";
						mailuser("editor", "Automatic update application", $message);
					}
				}
			}
		}
		echo "<hr>\n";
	}
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
