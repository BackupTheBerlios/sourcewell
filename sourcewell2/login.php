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
// $Id: login.php,v 1.11 2002/05/09 23:29:22 grex Exp $

$login = 1;
page_open(array('sess' => 'SourceWell_Session',
                'auth' => 'SourceWell_Auth',
                'perm' => 'SourceWell_Perm'));
require('start.inc');

function _i($string) {
    return $string;
}

if (isset($perm) && $perm->have_perm('user_pending')) {
    $table_error->table_full(_i('Error'), _i('Access denied')
                            ._i('You are a pending user. You need to confirm your registration'));
    $auth->logout();
} else {
    $msg = _i('You are logged in as').' <b>'.$auth->auth['uname']
           .'</b> '._i('with').' '
           .'<b>'.$auth->auth['perm'].'</b> '._i('permission').'.'
           .'<br>'._i('Your authentication is valid until')
           .' <b>'.lib_date_long($auth->auth['exp']).'</b>';
    $table->table_full(_i('Welcome to').' '.$config_sys_name, $msg);
}

config_inc('end');
?>
