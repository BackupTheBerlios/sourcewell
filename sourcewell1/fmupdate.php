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
	echo "<p><b>Automatic Software Update</b>";
	echo "<br>(<a href=\"http://freshmeat.net/backend/oneweek.html\">http://freshmeat.net/backend/oneweek.html</a>)\n";
	$string = "";
	$fcontents = file("http://freshmeat.net/backend/oneweek.html");
	while (list(, $line) = each($fcontents)) {
    	$string .= trim($line);
	}
	$items = explode("</tr>",$string);
	while(list(, $val) = each($items)) {
//		echo "<br>val: $val\n";
		if (ereg("<tr><td><a href=\"(.*)\">(.*)</a></td><td><a href=.*>(.*)</a></td><td><a href=.*>(.*)</a></td><td>(.*)</td><td>(.*)</td>", $val, $regs)) {
			echo "<p>Name: <a href=\"$regs[1]\" target=\"_new\">$regs[2]</a>\n";
			echo "<br>Type: $regs[3]\n";
			echo "<br>Version: $regs[4]\n";
			echo "<br>License: $regs[5]\n";
			echo "<br>Description: $regs[6]\n";

			switch ($regs[3]) {
			case "Default":
				$type = "S";
				if (strstr($regs[4], "a")) $type = "D";
				if (strstr($regs[4], "alpha")) $type = "D";
				if (strstr($regs[4], "Alpha")) $type = "D";
				if (strstr($regs[4], "ALPHA")) $type = "D";
				if (strstr($regs[4], "b")) $type = "D";
				if (strstr($regs[4], "beta")) $type = "D";
				if (strstr($regs[4], "Beta")) $type = "D";
				if (strstr($regs[4], "BETA")) $type = "D";
				if (strstr($regs[4], "rc")) $type = "D";
				if (strstr($regs[4], "RC")) $type = "D";
				if (strstr($regs[4], "pr")) $type = "D";
				if (strstr($regs[4], "PR")) $type = "D";
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
			$query .= "'".addslashes($regs[2])."'";
			$query .= " AND type='$type'";
			$db->query($query);
  			if ($db->next_record()) {
				if ($regs[4] > $db->f("version")) {

					// Update software with new version
					$query = "UPDATE software SET version='$regs[4]',user='helix' WHERE appid='".$db->f("appid")."'";
					$db->query($query);
					echo "<p>Update: ".$db->f("name")."; Type: ".$type."; Old Version: ".$db->f("version")."; New Version: ".$regs[4]."\n";
					echo "<br>$query\n";

					// Insert new history entry for new version
					$query = "INSERT history SET appid='".$db->f("appid")."',user_his='helix',version_his='$regs[4]',creation_his=NOW()";
					echo "<br>$query\n";
					$db->query($query);

					// Send notification by email to editors
					if ($ml_notify) {
						$message = "automatic update application ".$db->f("name")." ".$regs[4]." (".typestr($type).") by helix";
						mailuser("editor", "Automatic update application", $message);
					}
				}
			} else {
				$set = "name='".addslashes($regs[2])."'";
				$set .= ",type='$type'"
					.",version='$regs[4]'"
					.",section=''"
					.",category=''"
					.",license='$regs[5]'"
					.",homepage='$regs[1]'"
					.",developer=''";
				$set .= ",description='".addslashes($regs[2])."'";
				$set .= ",modification=NOW()"
					.",creation=NOW()"
					.",email=''"
					.",depend=''"
					.",user='".$auth->auth["uname"]."';";
				$query = "INSERT pending SET $set";
				echo "<br>$query\n";
				$db->query($query);
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
