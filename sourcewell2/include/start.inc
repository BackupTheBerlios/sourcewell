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
// |          Lutz Henckel <lutz.henckel@fokus.fhg.de>                    |
// |          Carlos Martín Ugalde <carlos@scouts-es.org>                 |
// +----------------------------------------------------------------------+
//
// $Id: start.inc,v 1.53 2002/05/10 18:47:55 grex Exp $

global $login;
global $logout;

if (!isset($login)) {
    page_open(array('sess' => 'SourceWell_Session'));
    if (isset($auth) && !empty($auth->auth['perm'])) {
 	    page_close();
 	    page_open(array('sess' => 'SourceWell_Session',
  	                    'auth' => 'SourceWell_Auth',
	                    'perm' => 'SourceWell_Perm'));
    } elseif (isset($auth)) {
        $auth->logout();
    } else {
        /* TODO */
    }
} else {
page_open(array('sess' => 'SourceWell_Session',
                'auth' => 'SourceWell_Auth',
                'perm' => 'SourceWell_Perm'));
}

// Disabling cache
header('Cache-Control: no-cache, must-revalidate');     // HTTP/1.1
header('Pragma: no-cache'); 				// HTTP/1.0

$_INC_PATH = '/home/groups/sourcewell/htdocs/sourcewell2/include/';

require($_INC_PATH.'config.inc');
config_inc('lib');
config_inc('html');
config_inc('Table');

//setlocale('LC_TIME', 'es_ES');
//config_inc('Lang');
//config_inc('Translation');
//$t = new Translation($la);
//$$config_database_variable = new DB_SourceWell;

$db = new DB_SourceWell;

$table = new Table();
$table_error = new Table('error', '80%');

config_inc('header');
?>
