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
// $Id: login.php,v 1.8 2002/05/09 23:01:26 grex Exp $

$login = 1;
include('start.inc');

if (isset($perm) && $perm->have_perm('user_pending')) {
    $table_error->table_full(_('Error'), _('Access denied'));
    $auth->logout();
} else {
    $msg = _('You are logged in as').' <b>'.$auth->auth['uname']
           .'</b> '._('with').' '
           .'<b>'.$auth->auth['perm'].'</b> '._('permission').'.'
           .'<br>'._('Your authentication is valid until')
           .' <b>'.lib_date_long($auth->auth['exp']).'</b>';
    $table->table_full(_('Welcome to').' '.$config_sys_name, $msg);
}

config_inc('end');
?>
