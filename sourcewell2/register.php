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
// $Id: register.php,v 1.3 2002/05/10 10:13:21 grex Exp $

require('start.inc');
/* TODO: add monitoring class / library */
//config_inc('monitorlib');

function _o($string) {
    return $string;
}

// Check if there was a submission
$reg = 0;
while (is_array($HTTP_POST_VARS) 
       && list($key, $val) = each($HTTP_POST_VARS)) {
    switch ($key) {
    case 'register': // Register a new user
		$username = trim($username);
		$password = trim($password);
		$cpassword = trim($cpassword);
		$realname = trim($realname);
		$email_usr = trim($email_usr);
        if (empty($username) || empty($password)  
            || empty($cpassword) || empty($email_usr)) { 
            // Do we have all necessary data?
            $table_error->table_full(_o('Error'), 
                           _o('Please enter').' <b>'
                          ._o('Username').'</b>, <b>'
                          ._o('Password').'</b> '
                          ._o('and').' <b>'
                          ._o('E-Mail').'</b>!');
            break;
        }
        if (strcmp($password,$cpassword)) { // password are identical?
            $table_error->table_full(_o('Error'), 
                           _o('The passwords are not identical')
                           .'. '._o('Please try again').'!');
            break;
        }

        /* Does the user already exist?
           NOTE: This should be a transaction, but it isn't... */
        $db->query("SELECT * FROM auth_user WHERE username='$username'");
        if ($db->nf()>0) {
            $table_error->table_full(_o('Error'), 
                           _o('User')." <B>$username</B> "
                           ._o('already exists').'!<br>'
                           ._o('Please select a different Username')
                           .'.');
            break;
        }
        // Create a uid and insert the user...
        $u_id= md5(uniqid($hash_secret));
        $modification_usr = 'NOW()';
        $creation_usr = 'NOW()';
        $permlist = 'user_pending';
        $query = ("INSERT INTO auth_user VALUES('$u_id','$username',"
                  ."'$password','$realname','$email_usr',$modification_usr,"
                  ."$creation_usr,'$permlist')");
        $db->query($query);
        if ($db->affected_rows() == 0) {
  	    /* TODO: use lib_die('') so that the message gets logged */
            $table_error->table_full(_o('Error'), 
                          _o('Registration of new User failed')
                          .":<br> $query");
            break;
        }
        // send mail
        $message = _o('Thank you for registering on the').' '.$sys_name
                   ._o('Site. In order to complete your registration, visit '
                      .'the following URL').": \n\n"
                   .$sys_url."verify.php?confirm_hash=$u_id\n\n"
                   ._o('Enjoy the site').".\n\n"
                   .' -- '._o('the').' '.$sys_name.' '._o('crew')."\n";

        mail($email_usr,'['.$sys_name.'] '._o('User Registration'),
                 $message, "From: $config_ml_fromAddr\nReply-To: "
                 ."$config_ml_replyAddr\nX-Mailer: PHP");

        $msg = _o('Congratulations').'! '
               ._o('You have registered on ').'$sys_name.<p>'
               ._o('Your new username is').": <b>$username</b><p>"
               ._o('You are now being sent a confirmation '
                  .'email to verify your email address').'.'.'<br>'
               ._o('Visiting the link sent to you in this '
                  .'email will activate your account').'.';

        $table->table_full(_o('User Registration'), $msg);

        if ($config_ml_notify) {
            $message  = _o('Username').": $username\n";
            $message .= _o('Realname').": $realname\n";
            $message .= _o('E-Mail').":   $email_usr\n";
            mailuser('admin', _o('New User has registered'), $message);
        }

        $reg = 1;
        break;
    default:
        break;
    }
}

if (!$reg) {
    $table->table_begin();
    $table->table_title(_o("Register as a new User"));
    $table->table_body_begin();

    htmlp_form_action();
    $table->table_columns_begin();

    $table->table_column(_o('Username'), '50%', '', 'right');
    $table->table_column(html_form_textField('username', $username, 20, 32), '50%', '', 'left');

    $table->table_nextRowWithColumns();

    $table->table_column(_o('Password'), '50%', '', 'right');
    $table->table_column(html_form_PassWordField('password', 20, 32), '50%', '', 'left');

    $table->table_nextRowWithColumns();

    $table->table_column(_o('Confirm Password'), '50%', '', 'right');
    $table->table_column(html_form_PassWordField('cpassword', 20, 32), '50%', '', 'left');

    $table->table_nextRowWithColumns();

    $table->table_column(_o('Real Name'), '50%', '', 'right');
    $table->table_column(html_form_textField('realname', $realname, 20, 64), '50%', '', 'left');

    $table->table_nextRowWithColumns();

    $table->table_column(_o('E-mail'), '50%', '', 'right');
    $table->table_column(html_form_textField('email_usr', $email_usr, 20, 128), '50%', '', 'left');

    $table->table_nextRowWithColumns();

    $table->table_colspan(html_form_submit(_o('Register'), 'register'), 2, '', 'center');

    $table->table_columns_end();
    htmlp_form_end();
    $table->table_body_end();
    $table->table_end();
}

config_inc('end');
?>