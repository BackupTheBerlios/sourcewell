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
# This file contains the verification procedure when registering
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

$db->query("SELECT perms,username FROM auth_user WHERE  user_id='$confirm_hash'");
$db->next_record();

if ($db->f("perms") == "user") {
       $msg = $t->translate("Your account is active. Please login");
       $bx->box_full($t->translate("Your account has already been verified"), "");
} else {
    $db->query("UPDATE auth_user SET perms='user' WHERE user_id='$confirm_hash'");

    if ($db->affected_rows() == 0) {
        $be->box_full($t->translate("Error"), $t->translate("Verification of Registration failed"));
    } else {
        $msg = $t->translate("Your account is now activated. Please login").".";
        $bx->box_full($t->translate("Verification of Registration"), $msg);
    }
}

?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
