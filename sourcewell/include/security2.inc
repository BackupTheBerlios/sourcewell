<?php

######################################################################
# Access control Library
# ===================================================================

#
# Copyright (c) 2001 by
#                Gregorio Robles (grex@scouts-es.org)
#
# SourceWell 2. http://sourcewell.berlios.de
# http://www.berlios.de
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

function security_page_access($page) {
	global $auth, $be;

	require("page_permisions2.inc");

	if (security_permision_hierarchy($required_permision[$page]) == 0) return 1;
	if (isset($auth) && !empty($auth)) {
		if (security_permision_hierarchy($auth->auth["perm"]) >= security_permision_hierarchy($required_permision[$page])) return 1;
	}

        if (security_permision_hierarchy($required_permision[$page]) > 4) {
            $be->box_full(_("Error").": "._("Access denied"),_("You do not have the appropriate permissions to enter this page"));
        } else {
            $be->box_full(_("Error").": "._("Access denied"),_("You have to Login in order to enter this page").". ".html_link("login.php3",array(),_("Login")));
        }

	require("footer2.inc");
	exit();
	
}

function security_data_access($data_permision) {
	global $auth;

	require("page_permisions2.inc");

	if (empty ($auth) && !isset($auth)) {
		if (security_permision_hierarchy($$data_permision) == 0) return 1;
	}
	if (security_permision_hierarchy($auth->auth["perm"]) >= security_permision_hierarchy($$data_permision)) return 1;
	else return 0;

}

function security_permision_hierarchy($permision_level) {

	switch($permision_level) {
		case "all": 		return 0;
		case "pending":		return 1;
		case "anonymous": 	return 2;
		case "user":		return 4;
		case "user,editor":		return 8;
                case "editor":		return 8;
		case "user,editor,admin":		return 16;
                case "admin":		return 16;
	}
}

?>
