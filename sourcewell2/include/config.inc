<?php

/* vim: set expandtab tabstop=4 shiftwidth=4: */
// +----------------------------------------------------------------------+
// |        SourceWell 2 - The GPL Software Announcement System           |
// +----------------------------------------------------------------------+
// |      Copyright (c) 2001-2002 BerliOS, FOKUS Fraunhofer Institut      |
// +----------------------------------------------------------------------+
// | This program is free software. You can redistribute it and/or modify |
// | it under the terms of the GNU General Public License as published by |
// | the Free Software Foundation; either version 2 or later of the GPL.  |
// +----------------------------------------------------------------------+
// | Authors: Gregorio Robles <grex@scouts-es.org>                        |
// |          Lutz Henckel <lutz.henckel@fokus.fhg.de>                    |
// |          Carlos Martín Ugalde <carlos@scouts-es.org>                 |
// +----------------------------------------------------------------------+
//
// $Id: config.inc,v 1.1 2002/03/08 17:10:58 grex Exp $

/**
 * General System Configuration
 *
 * This file contains all the constants with the general system
 * parameters, basically tied to visualization (colors, fonts, etc.)
 */

/**
 * Themes
 *
 * Background color configuration, font, etc.
 */

$config_body_bgcolor = '#FFFFFF';
$config_font_family = 'verdana,arial,helvetica,sans-serif';
$config_tt_font_family = 'courier,sans-serif';
$config_font_color = '#333333';
$config_hover_font_color = '#FF0000';

$config_nav_bgcolor = '#FFCC33';
$config_navstrip_bgcolor = '#000000';
$config_nav_font_color = '#333333';
$config_navstrip_font_color = '#FFFFFF';


/**
 * Configurable properties for general and error table
 *											     
 * Controls the table padding. It should have units (pt/em/%..)
 * Background color for the strip that contains the title
 * Background color for the box that contains the dta
 * Text align for the title (left/right/justify)
 * Text align for the content
 * Text color for the title
 * Text color for the content
 */

/* General table */

$config_table_general_filling = '3pt';
$config_table_general_title_bgcolor = '#CCCCCC';
$config_table_general_body_bgcolor = '';
$config_table_general_title_align = 'left';
$config_table_general_body_align = 'left';
$config_table_general_title_font_color = '#000000';
$config_table_general_body_font_color = '#333333';

/* Error Table */

$config_table_error_filling = '3pt';
$config_table_error_title_bgcolor = '#CCCCCC';
$config_table_error_body_bgcolor = '#FFFFFF';
$config_table_error_title_align = 'left';
$config_table_error_body_align = 'left';
$config_table_error_title_font_color = '#000000';
$config_table_error_body_font_color = '#FF2020';

/**
 * E-mail advice
 * 
 * sys_name		System name
 * ml_notify		To be notified, ml_notify apps have to be inserted
 * ml_fromaddr		Email address in the From field
 * ml_replyaddr		Return Email address
 */

$sys_name = 'SourceWell';
$ml_notify = '1';
$ml_fromaddr = 'noreply@berlios.de';
$ml_replyaddr = 'noreply@berlios.de';

/**
 * PHPLIB
 *
 * Hash secret neede required by PHPLib
 */

$hash_secret = 'KaiserinAugusta';


/**
 * SourceWell 2 Version
 */

$config_SourceWell_Version = '2.0alpha1';

?>
