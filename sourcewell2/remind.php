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
// $Id: remind.php,v 1.1 2002/05/10 10:54:28 grex Exp $

require('start.inc');

/* in this variable we keep information whether
 * the form has been filled out yet or not */
$FilledOut = 0;

if (isset($username) || isset($email_usr)) {
    $FilledOut = 1;

    $db->query("SELECT * FROM auth_user WHERE username='$username' AND "
               ."email_usr='$email_usr'");

    if ($db->num_rows() > 0) {
        $db->next_record();

        $message = _('Your Username and Password for').' $sys_name'
                  ._('is').":\n\n"
                  ."\t"._('User').': '.$db->f('username')."\n"
                  ."\t"._('Password').': '.$db->f('password')."\n\n"
                  ._('Please keep this e-mail for further reference').".\n\n"
                  .' -- '._('the').' '.$sys_name.' '._('crew')."\n";

        mail($email_usr, "[$sys_name] "._("Remind me"), $message,
             "From: $ml_newsfromaddr\nReply-To: $ml_newsreplyaddr\nX-Mailer: PHP");

        $table->table_full(_('Remind me'), 
                           _('You will get your Password by e-mail in '
                             .'a couple of minutes').'<p>'
                           ._('Contact the system administrators if something goes wrong.'));
    } else {
        $table_error->table_full(_('Error'), 
                                 _('Either your Username or E-Mail Address '
                                 .'is unknown').'.<br>'
                                 ._('Please try again').'!');
       $FilledOut = 0;
    }
}

if (!$FilledOut) {

    $table->table_begin();
    $table->table_title(_('Forgot Password'));
    $table->table_body_begin();
    htmlp_form_action('remindme.php');
    $table->table_columns_begin();

    $table->table_column(_('Username'), '50%', '', 'right');
    $table->table_column(html_form_textField('username', $username, 20, 32), '50%', '', 'left');

    $table->table_nextRowWithColumns();

    $table->table_column(_('E-mail'), '50%', '', 'right');
    $table->table_column(html_form_textField('email_usr', $email_usr, 20, 64), '50%', '', 'left');

    $table->table_nextRowWithColumns();

    $table->table_colspan(html_form_submit(_('Remind me'), 'remind'), 2, '', 'center');

    $table->table_columns_end();
    htmlp_form_end();
    $table->table_body_end();
    $table->table_end();
}

config_inc('end');
?>
