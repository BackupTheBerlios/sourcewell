<?php
/* vim: set expandtab tabstop=4 shiftwidth=4: */
// +----------------------------------------------------------------------+
// |        SourceWell 2 - The GPL Software Announcement System           |
// +----------------------------------------------------------------------+
// |      Copyright (c) 2001-2002 BerliOS, FOKUS Fraunhofer Institut      |
// +----------------------------------------------------------------------+
// | This program is free software. You can redistribute it and/or modify |
// | it under the terms of the GNU General Public License as published by |
// | the Free Software Foundation; either version 2 or later of the GPL.  |
// +----------------------------------------------------------------------+
// | Authors: Gregorio Robles <grex@scouts-es.org>                        |
// |          Lutz Henckel <lutz.henckel@fokus.fhg.de>                    |
// +----------------------------------------------------------------------+
//
// $Id: logout.php,v 1.1 2002/05/10 10:36:05 grex Exp $

/* TODO: has to be implemented */
/* Special status for the logout page (menubar, etc.) */
$logout = 1;

require('start.inc');

$msg = ( _('You have been logged in as')
         .' <b>'.$auth->auth['uname'].'</b> '._('with').' <b>'
         .$auth->auth['perm'].'</b> '._('permision').'.<br>'
         ._('Your authentication was valid until').' <b>'
         .timestr($auth->auth['exp'])
         .'</b>.<p>'
         ._('This is all over now. You have been logged out').'.';

$table->table_full(_('Logout'), $msg);

$auth->logout();
config_inc('end');
?>
