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
// $Id: changeuser.php,v 1.4 2002/05/10 18:59:20 grex Exp $

require('start.inc');
/* TODO: add monitoring class / library */
//config_inc('monitorlib');

// Check if there was a submission
while (is_array($HTTP_POST_VARS) 
       && list($key, $val) = each($HTTP_POST_VARS)) {
    switch ($key) {
    case 'u_edit': // Change user parameters
        if($auth->auth['uid'] == $u_id) { // user changes his own account
            $password = trim($password);
            $cpassword = trim($cpassword);
            $realname = trim($realname);
            $email_usr = trim($email_usr);

            if (strcmp($password,$cpassword)) { // password are identical?
            	$table_error->table_full(_('Error'), 
                              _('The passwords are not identical')
                              .'. '._('Please try again').'!');
            	break;
            }

            $query = ("UPDATE auth_user SET password='$password', "
                      ."realname='$realname', email_usr='$email_usr', "
                      ."modification_usr=NOW() WHERE user_id='$u_id'");
            $db->query($query);

            if ($db->affected_rows() == 0) {
                $table_error->table_full(_('Error'), 
                              _('Change User Parameters failed')
                              .":<br>$query");
                break;
            }

            $table->table_full(_('Change User Parameters'), 
                          _('Password and/or E-Mail Address of')
                          .' <b>'. $auth->auth['uname'] .'</b> '
                          ._('is changed').'.');
            if ($ml_notify) {
                $message  = _('Username').': '.$auth->auth['uname'].'\n';
                $message .= _('Realname').": $realname\n";
                $message .= _('E-Mail').":   $email_usr\n";

                mailuser('admin', 
                         _('User parameters has changed'), 
                         $message);
            }
        } else {
            $table_error->table_full(_('Error'), 
                          _('Access denied'));
        }
        break;
    default:
        break;
    }
}

$table->table_begin();
$table->table_title(_('Change User Parameters'));
$table->table_body_begin();
htmlp_form_action();
$table->table_columns_begin();

$db->query("SELECT * FROM auth_user WHERE username='".$auth->auth["uname"]."'");
$db->next_record();

$table->table_column('<b>'._('Username').':</b>', '50%', '', 'right');
$table->table_column(html_form_textField('username', $db->f('username'), 20, 32), '50%', '', 'left');

$table->table_nextRowWithColumns();

$table->table_column('<b>'._('Password').':</b>', '50%', '', 'right');
$table->table_column(html_form_PassWordField('password', 20, 32, $db->f('password')), '50%', '', 'left');

$table->table_nextRowWithColumns();

$table->table_column('<b>'._('Confirm Password').':</b>', '50%', '', 'right');
$table->table_column(html_form_PassWordField('cpassword', 20, 32, $db->f('password')), '50%', '', 'left');

$table->table_nextRowWithColumns();

$table->table_column('<b>'._('Real Name').':</b>', '50%', '', 'right');
$table->table_column(html_form_textField('realname', $db->f('realname'), 20, 64), '50%', '', 'left');

$table->table_nextRowWithColumns();

$table->table_column('<b>'._('E-mail').':</b>', '50%', '', 'right');
$table->table_column(html_form_textField('email_usr', $db->f('email_usr'), 20, 128), '50%', '', 'left');

$table->table_nextRowWithColumns();

$table->table_column('<b>'._('Creation').':</b>', '50%', '', 'right');
$table->table_column(lib_date_long($db->f('creation_usr')), '50%', '', 'left');

$table->table_nextRowWithColumns();

$table->table_column('<b>'._('Last Modification').':</b>', '50%', '', 'right');
$table->table_column(lib_date_long($db->f('modification_usr')), '50%', '', 'left');

$table->table_nextRowWithColumns();

$table->table_column('<b>'._('Permisions').':</b>', '50%', '', 'right');
$table->table_column($db->f('perm'), '50%', '', 'left');

$table->table_nextRowWithColumns();

$table->table_colspan(html_form_submit(_('Change'), 'u_edit'), 2, '', 'center');

$table->table_columns_end();
htmlp_form_hidden('u_id', $db->f('user_id'));
htmlp_form_end();
$table->table_body_end();
$table->table_end();

config_inc('end');
?>
