<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ================================================
#
# Copyright (c) 2001-2004 by
#                Lutz Henckel (lutz.henckel@fokus.fraunhofer.de) and
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

require("./include/prepend.php3");

page_open(array("sess" => "SourceWell_Session"));
if (isset($auth) && !empty($auth->auth["perm"])) {
  page_close();
  page_open(array("sess" => "SourceWell_Session",
                  "auth" => "SourceWell_Auth",
                  "perm" => "SourceWell_Perm"));
}

require("./include/header.inc");

$bx = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
if (($config_perm_admcat != "all") && (!isset($perm) || !$perm->have_perm($config_perm_admcat))) {
  $be->box_full($t->translate("Error"), $t->translate("Access denied"));
} else {

  if (isset($sec_and_cat)) {
    $pieces = explode("/", $sec_and_cat);
    $section = $pieces[0];
    $category = $pieces[1];    
  }
 
  if (isset($section) && !empty($section) && isset($category) && !empty($category)) {
			      // Look if Section/Category is already in table
    $db->query("SELECT * FROM categories WHERE section='$section' AND category='$category'");
    $db->next_record();

    if ($db->num_rows() > 0) {
      if (isset($new_category)) {
		       // If sec/cat pair in database and a new name is given, then rename
        if (!empty($new_category)) {
          $db->query("SELECT name,modification FROM software WHERE category = '$category' AND section='$section'");
			// All the affected apps are treated as modified
			// BUT they are assigned to the new category!!!!
          while ($db->next_record()) {
            $modification = $db->f("modification");
            $db2 = new DB_SourceWell;
	    $db2->query("UPDATE software SET status='M',category='$new_category',modification='$modification' WHERE section='$section' AND category='$category'");
          }
          $affected_apps =  $db->affected_rows();          

          $db->query("UPDATE categories SET category='$new_category' WHERE section='$section' AND category='$category'");
          $affected_rows =  $db->affected_rows();
          if ($affected_rows == 1) {
	    $bx->box_full($t->translate("Administration"),$t->translate("Former category")." $category ".$t->translate("in Section")." $section ".$t->translate("has been renamed to")." $new_category ".$t->translate("affecting")." $affected_apps  ".$t->translate("applications"));
          }
          if ($affected_rows == 0) {
            $be->box_full($t->translate("Error"), $t->translate("Category")."  $section/$category ".$t->translate("already exists!"));
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
          $db->query("SELECT COUNT(*) FROM categories WHERE section='$section'");
          $db->next_record();
          $number_of_cats = $db->f("COUNT(*)");

	  if ($number_of_cats == 1) {
    	    $be->box_full($t->translate("Error"), $t->translate("This is the unique category of the section. For deleting it, you should delete the whole section."));
          } else {
				// We inform the administrator how many
				// apps will be affected by this deletion
            $db->query("SELECT COUNT(*) FROM software WHERE section='$section' AND category='$category' AND (status='A' OR status='P')");
            $db->next_record();
            $number_of_apps = $db->f("COUNT(*)");

    	    $be->box_full($t->translate("Warning!"), $t->translate("If you press another time the Delete-button you will delete")." $number_of_apps ".$t->translate("applications that are actually in the")." $section/$category ".$t->translate("category"));

 	    $bx->box_begin();
	    $bx->box_title($t->translate("Delete Category"));
	    $bx->box_body_begin();
	    echo "<form action=\"".$sess->self_url()."\" method=\"POST\">\n";
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
          $db->query("SELECT appid,modification FROM software WHERE category = '$category' and section='$section'");
          $affected_apps = $db->affected_rows();
			// All the affected apps are treated as modified
          while($db->next_record()) {
            $modification = $db->f("modification");
            $appid = $db->f("appid");
            $db2 = new DB_SourceWell;
            $db2->query("UPDATE software SET status='M',modification='$modification' WHERE appid='$appid'");
          }

          $db->query("DELETE from categories WHERE section='$section' AND category='$category'");
          if ($db->affected_rows() == 1) {
  	    $bx->box_full($t->translate("Administration"), $t->translate("Deletion succesfully completed affecting")." $affected_apps ".$t->translate("applications"));
          }
	}
      }
      if (!isset($del_category) && !isset($new_category)) {
		        	// It's already in our database
				// but no rename and no deletion... ->error
        $be->box_full($t->translate("Error"), $t->translate("Category")." $section/$category ".$t->translate("already exists!"));
      }
    } else {
		        	// If section is not in table, insert it
      $db->query("INSERT INTO categories VALUES ('$section','$category')");
      if ($db->affected_rows()) {
        $bx->box_full($t->translate("Administration"),$t->translate("Category")." $section/$category ".$t->translate("has been added succesfully to the database"));
      }
    }
  } else {
				// Category (or section) is a blank line or isn't set
    $be->box_full($t->translate("Error"), $t->translate("Category not specified"));
  }
}

?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
