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
// $Id: config.inc,v 1.2 2002/03/15 15:14:24 grex Exp $

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
 * Database configuration
 * config_host               string    database server host
 * config_database_name      string    name of the database
 * config_database_user      string    database user name
 * config_database_password  string    password to access database
 * config_database_variable  string    variable that will be used in the 
 *                                     classes. It will have a global scope
 *                                     so its name should be chosen so that
 *                                     there are no collisions.
 *                                     Any name starting with _DB_ will be ok.
 */

$config_host               = 'localhost';
$config_database_name      = 'sourcewell2';
$config_database_user      = 'operator';
$config_database_password  = 'password';
$config_database_variable  = '_DB_';

/**
 * Directory configuration
 *
 * Following variables give the actual location of
 * the different classes and libraries
 *
 * $config_path_extension:  file extensions 
 * if there is one with a different extension, you should change
 * it in the lib_config() function in lib.inc
 * TODO: find a way to make this easier
 * 
 * $config_lib_lib:
 * $config_html_lib:
 * $config_TableClass:      path to Table.inc
 * $config_FieldClasses:    path to the *Field, Show (and children), Preview etc. classes
 * $config_OtherClasses:    path to the rest of classes
 * $config_translations:    path to the translation included files
 * $config_design_lib:      path to header, footer, etc. etc.
 *
 */

$config_path_extension = 'inc.php';

$config_path_lib = 'include/';
$config_path_html = 'include/';
$config_path_TableClass = 'include/';
$config_path_FieldClasses = 'include/';
$config_path_Classes = 'include/';
$config_path_translations = 'include/';
$config_path_design = 'include/';


/*
 * Include directories
 *
 * $class    string     Name of the class or library that should be included
 *
 * The $class parameter does not need to have the file extension (.inc) or (.inc.php)
 *
 * if you want to include Table.inc, just call
 * lib_include('Table');
 */

function lib_include($class)
{
    switch($class) {
    case ereg('Field',$class):
    case ereg('Show',$class):
    case 'Preview':
       include($config_path_Classes.$config_path_extension);
       break;
    case 'Table':
      include($config_path_TableClass.$config_path_extension);
    case 'lib':
        include($config_path_lib.$config_path_extension);
        break;
    case 'html':
        include($config_path_html.$config_path_extension);
        break;
    case 'security':
        include($config_path_security.$config_path_extension);
        break;
    case 'header':
    case 'footer':
    case 'menubar':
    case 'top_strip':
    case 'top_title':
        include($config_path_design.$config_path_extension);
        break;
    case 'translation':
    case 'lang':
        include($config_path_translations.$config_path_extension);
        break;
    default:
      die('error. See configuration file');
    }
}

/**
 * PHPLIB
 *
 * config_PHPLib_installed:  boolean         1 if yes, 0 if not
 * 
 * $config_hash_secret: string        Hash secret neede required by PHPLib
 * it is obviously only required if PHPLib is installed
 */

$config_PHPLib_installed = 1;
$config_hash_secret = 'KaiserinAugusta';

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
 * Width of the columns shown in the Field, Show, etc. classes
 *
 * Note that both values should sum up 100%
 */

$config_LeftColumnWidth = '33%':
$config_RightColumnWidth = '67%';

/**
 * E-mail advice
 * 
 * sys_name		System name
 * ml_notify		To be notified, ml_notify apps have to be inserted
 * ml_fromaddr		Email address in the From field
 * ml_replyaddr		Return Email address
 */

$config_sys_name = 'SourceWell';
$config_ml_notify = '1';
$config_ml_fromaddr = 'noreply@berlios.de';
$config__replyaddr = 'noreply@berlios.de';

/**
 * SourceWell 2 Version
 */

$config_SourceWell_Version = '2.0alpha1';

?>
