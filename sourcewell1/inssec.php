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
# This file inserts a section
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
if (($config_perm_admsec != "all") && (!isset($perm) || !$perm->have_perm($config_perm_admsec))) {
  $be->box_full($t->translate("Error"), $t->translate("Access denied"));
} else {
  if (isset($section) && !empty($section)) {
			      // Look if section is already in table
    $db->query("SELECT * FROM categories WHERE section='$section'");

    if ($db->num_rows() > 0) {
      $db->next_record();
				// We look if the section already is in our database
      if (isset($new_section)) {
			       // If section in database and a new name is given, then rename

        $db->query("SELECT appid,modification FROM software WHERE section='$section'");
			     // All the affected apps are treated as modified
			     // AND are assigned to the new category!!!!
        while($db->next_record()) {
          $db_rename = new DB_SourceWell;
          $modification = $db->f("modification");
          $appid = $db->f("appid");
	  $db_rename->query("UPDATE software SET status='M',section='$new_section',modification='$modification' WHERE appid='$appid'");
        }
        $affected_apps = $db->num_rows();

        $db->query("UPDATE categories SET section='$new_section' WHERE section='$section'");
        if ($db->affected_rows() > 0) {
 	  $bx->box_full($t->translate("Administration"),$t->translate("Section")." $section ".$t->translate("has been renamed to")." $new_section ".$t->translate("affecting")." $affected_apps ".$t->translate("applications"));
        }      
      }

      if (isset($del_section)) {
				// Section database and we want to delete it

        if (!strcmp($del_section,"warning")) {
			// You've got another chance before it's deleted ;-)
			// We inform the administrator how many categories and
			// apps will be affected by this deletion

          $db->query("SELECT COUNT(*) FROM categories WHERE section='$section'");
          $db->next_record();
          $number_of_cats = $db->f("COUNT(*)");

          $db->query("SELECT COUNT(*) FROM software WHERE section='$section' AND (status='A' OR status='P')");
          $db->next_record();
          $number_of_apps = $db->f("COUNT(*)");

          $be->box_full($t->translate("Warning!"), $t->translate("If you press another time the Delete-button you will delete the")." $number_of_cats ".$t->translate("categories and")."  $number_of_apps ".$t->translate("applications that are actually in the")." $section ".$t->translate("section"));

 	  $bx->box_begin();
	  $bx->box_title($t->translate("Delete Section"));
	  $bx->box_body_begin();
	  echo "<form action=\"".$sess->self_url()."\" method=\"POST\">\n";
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
          $db->query("SELECT name,modification FROM software WHERE section='$section'");
				// All the affected apps are treated as deleted

          while ($db->next_record()) {
            $modification = $db->f("modification");
            $db2 = new DB_SourceWell;
            $db2->query("UPDATE software SET status='M',modification='$modification' WHERE section='$section'");
          }            

          $db->query("DELETE from categories WHERE section='$section'");
          if ($db->affected_rows() > 0) {
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
  } else {
			// Section = blank line
			// We asume the admin wants to insert a category
			// in an already existing section!
    inssec("no");
  }
}

?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
