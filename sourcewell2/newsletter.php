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
// $Id: newsletter.php,v 1.1 2002/05/10 18:17:50 grex Exp $

require('start.inc');

if (!$configure_ml_list) {
    $table_error->table_full(_("Error"),
                             _("The Mailing Lists are not enabled").".");
} else {
    /* Check if there was a submission */
    $subs = 0;
    while (is_array($HTTP_POST_VARS) && list($key, $val) = each($HTTP_POST_VARS)) {
        switch ($key) {
        case 'subscribe':		// subscribe newsletter
            $email_usr = trim($email_usr);
            $password = trim($password);
            $cpassword = trim($cpassword);
            if (empty($email_usr) || empty($password)  || empty($cpassword)) { // Do we have all necessary data?
                $table_error->table_full(_('Error'), _('Please enter').' <b>'._('Username').'</b>, <b>'._('Password').'</b> '._('and').' <b>'._('E-Mail').'</b>!');
                break;
            }

            if (strcmp($password,$cpassword)) { // password are identical?
                $table_error->table_full(_('Error'), _('The passwords are not identical').'. '._('Please try again').'!');
                break;
            }
					  // send mail
            $message = '';
            if ($period == 'daily') {		// Daily Newsletter
	        mail($config_ml_dailyNewsreqaddr,"subscribe $password",$message,"From: $email_usr\nReply-To: $email_usr\nX-Mailer: PHP");
	        $msg = _('Congratulations').'! '
	              ._('You have subscribed to $sys_name daily Newsletter').'.'.'<p>'
                      ._('You are now being sent a confirmation email to verify your email address').'.';
	        $table->table_full(_('Subscribe daily Newsletter'), $msg);
            } else { // Weekly Newsletter
	        mail($config_ml_weeklyNewsReqAddr,"subscribe $password",$message,"From: $email_usr\nReply-To: $email_usr\nX-Mailer: PHP");
	        $msg = _('Congratulations').'! '
	               ._('You have subscribed to $sys_name weekly Newsletter').'.'
	               .'<p>'._('You are now being sent a confirmation email to verify your email address').'.';
	        $table->table_full(_('Subscribe weekly Newsletter'), $msg);
            }
            $subs = 1;
            break;
        default:
            break;
        }
    }

    if (!$subs) {
        $table->table_begin();
        $table->table_title(_('Subscribe Newsletter'));
        $table->table_body_begin();
        $table->table_columns_begin(2);
        htmlp_form_action();
        
        $table->table_column('<b>'._('E-Mail').':</b> ', '40%', '', 'right');
        $table->table_column(html_form_textField('email_usr', 20, 128, '') ,'60%', '', 'left');

        $table->table_nexRowWithColumns();

        $table->table_column('<b>'._('Password').':</b> ', '40%', '', 'right');
        $table->table_column(html_form_PassWordField('password', 20), '60%', '', 'left');

        $table->table_nexRowWithColumns();

        $table->table_column('<b>'._('Confirm Password').':</b> ', '40%', '', 'right');
        $table->table_column(html_form_PassWordField('cpassword', 20), '60%', '', 'left');

        $table->table_nexRowWithColumns();

        $table->table_column('<b>'._('Periodicity').':</b> ', '40%', '', 'right');
        $table->table_column(html_form_radioButton('period','daily','')._('daily').' &nbsp; &nbsp; '.html_form_RadioButton('period','weekly','yes')._('weekly'), '60%', '', 'left');

        $table->table_nexRowWithColumns();

        $table->table_colspan(html_form_submit(_('Subscribe'), 'subscribe'), 2, '', 'center');

        $table->table_columns_end();
        $table->table_body_end();
        $table->table_end();
    }
}

require('end');
?>
