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
# This file inserts a new license
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

page_open(array("sess" => "SourceWell_Session",
                "auth" => "SourceWell_Auth",
                "perm" => "SourceWell_Perm"));

require("header.inc");

$bx = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
if ($perm->have_perm("admin")) {

  if (isset($license) && !empty($license)) {
    $db = new DB_SourceWell;
			      // Look if License is already in table
    $columns = "*";
    $tables = "licenses";
    $where = "license='$license'";

    if (!$result = mysql_db_query($db_name, "SELECT $columns FROM $tables WHERE $where")) {
      mysql_die();

    } else {

      if ($row = mysql_fetch_array($result)) {

        if (isset($new_license)) {
			       // If license in database and a new name is given, then rename
          if (!empty($new_license)) {
            $result_del = mysql_db_query($db_name, "SELECT appid,modification FROM software WHERE license = '$license'");

				// All the affected apps are treated as modified
				// BUT they are assigned to the new license!!!!
	    while ($row_del = mysql_fetch_array($result_del)) {
               $modification = $row_del["modification"];
	       mysql_db_query($db_name, "UPDATE software SET status='M',license='$new_license',modification='$modification' WHERE appid='$appid'");
            }

            if (!$result = mysql_db_query($db_name, "UPDATE licenses SET license='$new_license' WHERE license='$license'")) {
              mysql_die();
            } else {
 	      $bx->box_full($t->translate("Administration"),$t->translate("License $license has been renamed to $new_license affecting ".mysql_num_rows($result_del)." applications"));
            }
            mysql_free_result($result_del);
          } else {
				// License is a blank line
            $be->box_full($t->translate("Error"), $t->translate("License name not specified"));
          }
	}

        if  (isset($new_url)) {
	             // If license in database and a new url is given, then go for it
          if (!empty($new_url)) {
            if (!$result = mysql_db_query($db_name, "UPDATE licenses SET url='$new_url' WHERE license='$license'")) {
              mysql_die();
            } else {
 	      $bx->box_full($t->translate("Administration"),$t->translate("License $license has a new URL: $new_url"));
            }
          } else {
				// URL is a blank line
            $be->box_full($t->translate("Error"), $t->translate("New URL not specified"));
          }
	}

        if (isset($del_license)) {
				// License in database and we want to delete it

	  if (!strcmp($del_license,"warning")) {
				// You've got another chance before it's deleted ;-)

				// We inform the administrator how many
				// apps will be affected by this deletion

	    $result1 = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE license='$license'");
	    $row1 = mysql_fetch_row($result1);
            $number_of_apps = $row1[0];
            mysql_free_result($result1);

    	    $be->box_full($t->translate("Warning!"), $t->translate("If you press another time the Delete-button you will alter $number_of_apps applications that have actually license $license"));

 	    $bx->box_begin();
	    $bx->box_title($t->translate("Delete License"));
	    $bx->box_body_begin();
            echo "<form action=\"$PHP_SELF\" method=\"POST\">\n";
	    echo "<table border=0 cellspacing=0 cellpadding=3>\n";
            echo "<tr><td align=right>".$t->translate("License").":</td><td>\n";
            echo $license;
	    echo "</td></tr>\n";
	    echo "<tr><td>&nbsp;</td>\n";
	    echo "<input type=\"hidden\" name=\"license\" value=\"$license\">\n";
            echo "<input type=\"hidden\" name=\"del_license\" value=\"too_late\">\n";
	    echo "<td><input type=\"submit\" value=\"".$t->translate("Delete")."\">";
	    echo "</td></tr>\n";
	    echo "</form>\n";
	    echo "</table>\n";
	    $bx->box_body_end();
	    $bx->box_end();
          } else {
            if (!$result = mysql_db_query($db_name, "UPDATE software SET license='Other' WHERE license='$license'")) {
              mysql_die();
            } else {
              if (!$result = mysql_db_query($db_name, "DELETE from licenses WHERE license='$license'")) {
                mysql_die();
              } else {
  	        $bx->box_full($t->translate("Administration"), $t->translate("Deletion succesfully completed"));
              }
	    }
          } 
	} else {
          if (empty($new_license) && empty($new_url) && empty($del_license)) { 
		          	// It's already in our database
				// but no rename and no deletion and no new url... ->error
            $be->box_full($t->translate("Error"), $t->translate("That license already exists!"));
          }
        }
      } else {
	        	// If license is not in table, insert it
        if (!empty($url_lic)) {
          if (!$result = mysql_db_query($db_name, "INSERT INTO licenses VALUES 
('$license','$url_lic')")) {
            mysql_die();
          } else {
            $bx->box_full($t->translate("Administration"),$t->translate("License $license with URL $url_lic has been added succesfully to the database"));
          }
        } else {
				// URL is a blank line
          $be->box_full($t->translate("Error"), $t->translate("License URL not specified"));
        }
      }
    }
  } else {
				// License is a blank line or isn't set
    $be->box_full($t->translate("Error"), $t->translate("License not specified"));
  }
} else {
	$be->box_full($t->translate("Error"), $t->translate("Access denied").".");
}

?>
<!-- end content -->

<?php
require("footer.inc");
page_close();
?>
