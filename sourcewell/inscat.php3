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
# This file inserts a category
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

  if (isset($sec_and_cat)) {
    $pieces = explode("/", $sec_and_cat);
    $section = $pieces[0];
    $category = $pieces[1];    
  }

  if (isset($section) && !empty($section) && isset($category) && !empty($category)) {
    $db = new DB_SourceWell;

			      // Look if Section/Category is already in table
    $columns = "*";
    $tables = "categories";
    $where = "section='$section' AND category='$category'";

    if (!$result = mysql_db_query($db_name, "SELECT $columns FROM $tables WHERE $where")) {
      mysql_die();
    } else {
      if ($row = mysql_fetch_array($result)) {
        if (isset($new_category)) {
		       // If sec/cat pair in database and a new name is given, then rename
          if (!empty($new_category)) {
            $result_del = mysql_db_query($db_name, "SELECT name,modification FROM software WHERE category = '$category' AND section='$section'");

				// All the affected apps are treated as modified
				// BUT they are assigned to the new category!!!!
	    while ($row_del = mysql_fetch_array($result_del)) {
              $modification = $row_del["modification"];
	      mysql_db_query($db_name, "UPDATE software SET status='M',category='$new_category',modification='$modification' WHERE section='$section' AND category='$category'");
            }
            mysql_free_result($result_del);

            if (!$result = mysql_db_query($db_name, "UPDATE categories SET category='$new_category' WHERE section='$section' AND category='$category'")) {
              mysql_die();
            } else {
	      $bx->box_full($t->translate("Administration"),$t->translate("Category $category in Section $section has been renamed to $new_category affecting ".mysql_affected_rows($result)." applications"));
            }
          } else {
				// Category is a blank line
            $be->box_full($t->translate("Error"), $t->translate("Category not specified"));
          }
	}
        if (isset($del_category)) {
				// Sec/cat pair in database and we want to delete it
          if (!strcmp($del_category,"warning")) {
				// You've got another chance before it's deleted ;-)

				// If this is the last category of a section
				// we don't delete it
				// --> the admin should delete the whole section!
            $result = mysql_db_query($db_name,"SELECT COUNT(*) FROM categories WHERE section='$section'");
	    $row = mysql_fetch_row($result);
            $number_of_cats = $row[0];
            mysql_free_result($result);

	    if ($number_of_cats == 1) {
    	      $be->box_full($t->translate("Error"), $t->translate("This is the unique category of the section. For deleting it, you should delete the whole section."));
            } else {

				// We inform the administrator how many
				// apps will be affected by this deletion

	      $result1 = mysql_db_query($db_name,"SELECT COUNT(*) FROM software WHERE section='$section' AND category='$category' AND (status='A' OR status='P')");
	      $row1 = mysql_fetch_row($result1);
              $number_of_apps = $row1[0];
              mysql_free_result($result1);

    	      $be->box_full($t->translate("Warning!"), $t->translate("If you press another time the Delete-button you will delete $number_of_apps applications that are actually in the $section/$category category"));

 	      $bx->box_begin();
	      $bx->box_title($t->translate("Delete Category"));
	      $bx->box_body_begin();
	      echo "<form action=\"$PHP_SELF\" method=\"POST\">\n";
	      echo "<table border=0 cellspacing=0 cellpadding=3>\n";
              echo "<tr><td align=right>".$t->translate("Category").":</td><td>\n";
              echo $sec_and_cat;
	      echo "</td></tr>\n";
	      echo "<tr><td>&nbsp;</td>\n";
	      echo "<input type=\"hidden\" name=\"sec_and_cat\" value=\"$sec_and_cat\">\n";
              echo "<input type=\"hidden\" name=\"del_category\" value=\"too_late\">\n";
	      echo "<td><input type=\"submit\" value=\"".$t->translate("Delete")."\">";
	      echo "</td></tr>\n";
	      echo "</form>\n";
	      echo "</table>\n";
	      $bx->box_body_end();
	      $bx->box_end();
            }
	  } else {
            $result_del = mysql_db_query($db_name, "SELECT appid,modification FROM software WHERE category = '$category' and section='$section'");
				// All the affected apps are treated as modified
	    while ($row_del = mysql_fetch_array($result_del)) {
              $modification = $row_del["modification"];
              mysql_db_query($db_name, "UPDATE software SET status='M',modification='$modification' WHERE appid='$appid'");
            }

            if (!$result = mysql_db_query($db_name, "DELETE from categories WHERE section='$section' AND category='$category'")) {
              mysql_die();
            } else {
  	      $bx->box_full($t->translate("Administration"), $t->translate("Deletion succesfully completed affecting ".mysql_num_rows($result_del)." applications"));
            }
            mysql_free_result($result_del);
	  }
        }
	if (!isset($del_category) && !isset($new_category)) {
		        	// It's already in our database
				// but no rename and no deletion... ->error
          $be->box_full($t->translate("Error"), $t->translate("Category $section/$category already exists!"));
        }
      } else {
		        	// If section is not in table, insert it
        if (!$result = mysql_db_query($db_name, "INSERT INTO categories VALUES 
('$section','$category')")) {
          mysql_die();
        } else {
          $bx->box_full($t->translate("Administration"),$t->translate("Category $section/$category has been added succesfully to the database"));
        }
      }
    }
  } else {
				// Category (or section) is a blank line or isn't set
    $be->box_full($t->translate("Error"), $t->translate("Category not specified"));
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
