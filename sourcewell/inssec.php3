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
# This file inserts a section
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
  if (isset($section) && !empty($section)) {
    $db = new DB_SourceWell;

			      // Look if section is already in table
    $columns = "*";
    $tables = "categories";
    $where = "section='$section'";

    if (!$result = mysql_db_query($db_name, "SELECT $columns FROM $tables WHERE $where")) {
      mysql_die();

    } else {

      if ($row = mysql_fetch_array($result)) {
				// We look if the section already is in our database
        if  (isset($new_section)) {
			       // If section in database and a new name is given, then rename

          $result_del = mysql_db_query($db_name, "SELECT appid,modification FROM software WHERE section='$section'");

				// All the affected apps are treated as deleted
				// BUT they are assigned to the new category!!!!
	  while ($row_del = mysql_fetch_array($result_del)) {
            $modification = $row_del["modification"];
	    mysql_db_query($db_name, "UPDATE software SET status='M',section='$new_section',modification='$modification' WHERE appid='$appid'");
          }

          if (!$result = mysql_db_query($db_name, "UPDATE categories SET section='$new_section' WHERE section='$section'")) {
            mysql_die();
          } else {
 	    $bx->box_full($t->translate("Administration"),$t->translate("Section $section has been renamed to $new_section affecting ".mysql_num_rows($result_del)." applications"));
          }
          mysql_free_result($result_del); 
	}

        if (isset($del_section)) {
				// Section database and we want to delete it

	  if (!strcmp($del_section,"warning")) {
				// You've got another chance before it's deleted ;-)

				// We inform the administrator how many categories and
				// apps will be affected by this deletion

	    $result = mysql_db_query($GLOBALS["db_name"],"SELECT COUNT(*) FROM categories WHERE section='$section'");
	    $row = mysql_fetch_row($result);
            $number_of_cats = $row[0];
            mysql_free_result($result);

	    $result1 = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE section='$section' AND (status='A' OR status='P')");
	    $row1 = mysql_fetch_row($result1);
            $number_of_apps = $row1[0];
            mysql_free_result($result1);

  	    $be->box_full($t->translate("Warning!"), $t->translate("If you press another time the Delete-button you will delete the $number_of_cats categories and $number_of_apps applications that are actually in the $section section"));

 	    $bx->box_begin();
	    $bx->box_title($t->translate("Delete Section"));
	    $bx->box_body_begin();
	    echo "<form action=\"$PHP_SELF\" method=\"POST\">\n";
	    echo "<table border=0 cellspacing=0 cellpadding=3>\n";
            echo "<tr><td align=right>".$t->translate("Section").":</td><td>\n";
            echo $section;
	    echo "</td></tr>\n";
	    echo "<tr><td>&nbsp;</td>\n";
	    echo "<input type=\"hidden\" name=\"section\" value=\"$section\">\n";
            echo "<input type=\"hidden\" name=\"del_section\" value=\"too_late\">\n";
	    echo "<td><input type=\"submit\" value=\"".$t->translate("Delete")."\">";
	    echo "</td></tr>\n";
	    echo "</form>\n";
	    echo "</table>\n";
	    $bx->box_body_end();
	    $bx->box_end();

	  } else {
				// Ok, let's go for it and delete!

            $result_del = mysql_db_query($db_name, "SELECT name,modification FROM software WHERE section='$section'");
				// All the affected apps are treated as deleted
	    while ($row_del = mysql_fetch_array($result_del)) {
              $modification = $row_del["modification"];
              mysql_db_query($db_name, "UPDATE software SET status='M',modification='$modification' WHERE section='$section'");
            }
            mysql_free_result($result_del);

            if (!$result4 = mysql_db_query($db_name, "DELETE from categories WHERE section='$section'")) {
              mysql_die();
            } else {
  	      $bx->box_full($t->translate("Administration"), $t->translate("Deletion succesfully completed."));
	    }
	  }
        }

	if (!isset($del_section) && !isset($new_section)) {
		        	// It's already in our database, but the user wants to admin
				// it. We don't mind ;-) It's like inserting only a category
	 inssec("no");
        }

      } else {
		        	// If section is not in table, insert it
	inssec("yes");
      }
    }
  } else {
				// Section = blank line
				// We asume the admin wants to insert a category
				// in an already existing section!
    inssec("no");

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
