<?php
/* vim: set expandtab tabstop=4 shiftwidth=4: */
// +----------------------------------------------------------------------+
// |        SourceWell 2 - The GPL Software Announcement System�����������|
// +----------------------------------------------------------------------+
// |      Copyright (c) 2001-2002 BerliOS, FOKUS Fraunhofer Institut �����|
// +----------------------------------------------------------------------+
// | This program is free software. You can redistribute it and/or modify�|
// | it under the terms of the GNU General Public License as published by�|
// |�the Free Software Foundation; either version 2 or later of the GPL. �|
// +----------------------------------------------------------------------+
// | Authors: Gregorio Robles <grex@scouts-es.org>������������������������|
// |����������Lutz Henckel <lutz.henckel@fokus.fhg.de>��������������������|
// |          Carlos Mart�n Ugalde <carlos@scouts-es.org> ����������������|
// +----------------------------------------------------------------------+
//
// $Id: config.inc,v 1.51 2002/05/10 23:13:14 grex Exp $

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

$config_path_lib = 'include/';
$config_path_html = 'include/';
$config_path_TableClass = 'include/';
$config_path_FieldClasses = 'include/';
$config_path_Classes = 'include/';
$config_path_translations = 'include/';
$config_path_design = 'include/';
$config_path_images = 'images/';

/**
 * This function enables to add included files with some intelligence
 * given a file to include, it includes the correct file
 *
 * TODO: make the use of this function easier
 * TODO: for example using the above constants
 * TODO: so that the user does not need to edit this function
 *
 * @param  string    $include      Library/class to be included
 *                                 (without extension)
 *
 * @global boolean   $_FIELD_CLASS_INCLUDED    If the parent class has already been included
 * @global string    $_INC_PATH                Path to the include directory
 * @access public
 */
function config_inc($include)
{
    global $_FIELD_CLASS_INCLUDED, $_INC_PATH;

    /* default extensions */
    $class_extension = '.inc';
    $library_extension = '.inc';
    $include_extension = '.inc';

    /* let's work a little less */
    /* we group the different classes together */
    $include_switch = $include;

    /* if it contains Field, then this class belongs to the Field class */
    if (ereg('Field', $include)) {
        if (!$_FIELD_CLASS_INCLUDED) {
            /* we only add the parent class once */
            include($_INC_PATH.'/Field'.$class_extension);
            $_FIELD_CLASS_INCLUDED = 1;
        }
        $include_switch = 'Field';
    }
    switch($include_switch) {
    case 'Field':
        include($_INC_PATH.$include.$class_extension);
        break;
    case 'Session':
        include($_INC_PATH.$include.$class_extension);
        break;
    case 'Table':
        include($_INC_PATH.$include.$class_extension);
        break;
    case 'html':
        include($_INC_PATH.$include.$library_extension);
        break;
    case 'FormShow':
    case 'TabularShow':
    case 'Summary':
        /* Show parent class included */
        include($_INC_PATH.'/Show'.$class_extension);
        /* there's no break! ;-) */
    case 'Comment':
    case 'Form':
    case 'Insertion':
    case 'Update':
    case 'Preview':
        include($_INC_PATH.$include.$class_extension);
        break;
    case 'lib':
    case 'search':
    case 'security':
        include($_INC_PATH.$include.$library_extension);
        break;
    case 'end':
    case 'navigation':
    case 'images':
        include($_INC_PATH.$include.$include_extension);
        break;
    case 'footer':
    case 'header';
        include($_INC_PATH.$include.$include_extension);
        break;
    default:
        print("Error. Non existing file $include included at config_inc in config.inc");
    }
}

/**
 * General System Configuration
 *
 * This file contains all the constants with the general system
 * parameters, basically tied to visualization (colors, fonts, etc.)
 */

/**
 * System
 *
 * config_sys_name  string      Name of your SourceWell system
 * config_sys_title string      
 * config_sys_url   string 	URL of your SourceWell system
 */

$config_sys_name = 'SourceWell';
$config_sys_title = 'Open Source Software Announcement &amp; Retrieval';
$config_sys_url = 'http://sourcewell.berlios.de/sourcewell2/';

/**
 * Header image
 *
 * config_sys_logo_image   string  Image of your System (should be in the images directory)
 * config_sys_url_image    string  URL the image of your system points to
 * config_sys_logo_alt	   string  Alternative text for your site's image
 * config_sys_logo_width   int     Width of the image of your site
 * config_sys_logo_heigth  int     Height of the image of your site
 */

$config_sys_logo_image = $config_path_images.'berliOS_logo.png';
$config_sys_url_image = 'http://www.berlios.de/';
$config_sys_logo_alt = 'BerliOS';
$config_sys_logo_width = 238;
$config_sys_logo_heigth = 61;

/**
 * Organisation Config
 * (this can be sometimes the same as the one of the system)
 *
 * org_name	    string    Name of your Organisation
 * org_url	    string    URL of your Organisation
 * org_logo_image   string    Image of your Organisation
 * org_logo_alt	    string    Alternative text for the image of your Organisation
 * org_logo_width   int       Width of the image of your Organisation
 * org_logo_heigth  int       Height of the image of your Organisation
 */

$config_org_name = 'FOKUS';
$config_org_url = 'http://www.fokus.fhg.de/';
$config_org_logo_image = $config_path_images.'logo_fokus.png';
$config_org_logo_alt = $org_name;
$config_org_logo_width = 60;
$config_org_logo_heigth = 60;

/**
 * Page Layout
 *
 * config_show_appsperpage    int   maximum number of applications shown each time
 * config_show_numberofdays   int   maximum number of days show at the right side
 */

$config_show_appsperpage = 15;
$config_show_numberofdays = 4; 


/**
 * General configurations
 *
 * config_topStrip:             boolean      if a Top Strip is wanted or not
 * config_Footer:               boolean      if a Footer is wanted or not
 * config_addNetscapePanel:     boolean      if Netscape6 panels is available
 */

$config_topStrip = 1;
$config_Footer = 1;
$config_addNetscapePanel = 1;

/**
 * Top Strip
 * 
 * You can change (add, delete, modify) the top strip
 * as you wish as long as you mantain this syntax:
 * (don't forget that the last one hasn't got a comma!)
 */

$config_TopStripArray = array (
	'Home'	        => $config_sys_url_image.'index.php.en',
	'About us'	=> $config_sys_url_image.'about/index.php.en',
	'Partners'	=> $config_sys_url_image.'partners/index.php.en',
	'Contact'	=> $config_sys_url_image.'contact/index.php.en'
);

/**
 * HTML Metainformation
 * 
 *
 *
 */

$config_meta_author = 'BerliOS';
$config_meta_description = 'SourceWell is a Free Software/Open Source Software announcement system';
$config_meta_keywords = 'Free Software, Open Source, Freshmeat, GPL, Applications, BerliOS';

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
$config_navstrip_bgcolor = '#7B7B7B';
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
 * Navigation bar links
 *
 * TODO: explain how this can be configured 
 *
 * for further information see Navigation.inc for the Navigation class
 */

include('Navigation.inc');

/* Normal navigation bar */
$config_nav_bar_array[] = new Navigation('Recent Apps', 'index');
$temp = new Navigation('Q&amp;A', 'faq');
$temp->additionalBR();
$config_nav_bar_array[] = $temp;
$temp = new Navigation('Login', 'login');
$temp->showIfAuth(0);
$config_nav_bar_array[] = $temp;
$temp = new Navigation('Logout', 'logout');
$temp->showIfAuth(1);
$config_nav_bar_array[] = $temp;
$temp = new Navigation('New User', 'register');
$temp->showIfAuth(0);
$config_nav_bar_array[] = $temp;
$temp = new Navigation('Forgot Password?', 'remind');
$temp->showIfAuth(0);
$temp->additionalBR();
$config_nav_bar_array[] = $temp;
$temp = new Navigation('Change User', 'changeuser');
$temp->showIfAuth(1);
$temp->additionalBR();
$config_nav_bar_array[] = $temp;
$temp = new Navigation('Users', 'users');
$temp->setPermisions('editor');
$config_nav_bar_array[] = $temp;
$config_nav_bar_array[] = new Navigation('Apps Index', 'categories');
$config_nav_bar_array[] = new Navigation('New App', 'app_edi');
$temp = new Navigation('Update Apps', 'appbyuser');
$temp->showIfAuth(1);
$config_nav_bar_array[] = $temp;
$temp = new Navigation('Pending Apps', 'admapp');
$temp->setPermisions('editor');
$temp->setStatistics('projects', $where = "status='P'");
$config_nav_bar_array[] = $temp;
$temp = new Navigation('Deleted Apps', 'admapp');
$temp->setPermisions('editor');
$temp->setStatistics('projects', $where = "status='D'");
$config_nav_bar_array[] = $temp;
$temp = new Navigation('Modified Apps', 'admapp');
$temp->setPermisions('editor');
$temp->setStatistics('projects', $where = "status='M'");
$config_nav_bar_array[] = $temp;
$temp = new Navigation('Developers', 'developers');
$temp->setPermisions('editor');
$config_nav_bar_array[] = $temp;
$temp = new Navigation('Licenses', 'licenses');
$temp->additionalBR();
$config_nav_bar_array[] = $temp;
$config_nav_bar_array[] = new Navigation('Statistics', 'stats');
$config_nav_bar_array[] = new Navigation('Newsletter', 'newsletter');
$config_nav_bar_array[] = new Navigation('RDF Backend', 'rdf');


/* Administration options */
$temp = new Navigation('Users', 'admuser');
$temp->setPermisions('admin');
$temp->setStatistics('auth_user');
$config_adm_bar_array[] = $temp;
$temp = new Navigation('Sections', 'admsec');
$temp->setPermisions('admin');
/* TODO: has to be refined */
$temp->setStatistics('categories');
$config_adm_bar_array[] = $temp;
$temp = new Navigation('Categories', 'admcat');
$temp->setPermisions('admin');
$temp->setStatistics('categories');
$config_adm_bar_array[] = $temp;
$temp = new Navigation('Licenses', 'admlicens');
$temp->setStatistics('licenses');
$temp->setPermisions('admin');
$config_adm_bar_array[] = $temp;
$temp = new Navigation('Comments', 'admcomments');
$temp->setStatistics('comments');
$temp->setPermisions('admin');
$config_adm_bar_array[] = $temp;
$temp = new Navigation('Q&amp;A', 'admfaq');
$temp->setStatistics('faq');
$temp->setPermisions('admin');
$config_adm_bar_array[] = $temp;
$temp = new Navigation('Check Date', 'admdate');
$temp->setPermisions('admin');
$config_adm_bar_array[] = $temp;
$temp = new Navigation('Daily Newsletter', 'nladm');
$temp->setPermisions('admin');
$config_adm_bar_array[] = $temp;
$temp = new Navigation('Weekly Newsletter', 'nladm');

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

######################################################################
# Languages
#
# List of languages supported by your website
# You can add/delete/modify as long as you mantain the syntax
# New languages are always wellcome. Contact with the authors!
#
######################################################################

// WISH: this should obtain the list of languages from the *-lang.inc
// WISH: files in the include directory. But this might be too expensive
// WISH: since this file is read in for each page .... further: it might
// WISH: be possible to do this and store the results in an environmental
// WISH: variable, ofcourse updating the variable once set would be a problem
$config_la_array[] = 'English';
$config_la_array[] = 'German';
$config_la_array[] = 'Spanish';

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
$config_table_general_body_bgcolor = '#FFFFFF';
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

$config_LeftColumnWidth = '33%';
$config_RightColumnWidth = '67%';

/**
 * E-mail advice - Monitoring
 * 
 * ml_notify		To be notified, ml_notify apps have to be inserted
 * ml_fromaddr		Email address in the From field
 */

$config_ml_notify = '1';
$config_ml_fromAddr = 'noreply@berlios.de';
$config_ml_replyAddr = 'noreply@berlios.de';

/**
 * Mailing list support
 *
 * ml_list boolean      if there should be mailing lists or not
 * TODO: configuration should be easier!
 * ml_replyaddr		Return Email address
 * ml_*NewsReqAddr      Request Address for subscribing to a mailing list
 *
 */

$config_ml_list = 1;
$config_ml_DailyNewsReqAddr = '';
$config_ml_weeklyNewsReqAddr = '';

/**
 * SourceWell 2 Version
 */

$config_SourceWell_Version = '2.0alpha1';

?>