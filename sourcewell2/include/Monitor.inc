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
// +----------------------------------------------------------------------+
//
// $Id: Monitor.inc,v 1.1 2002/03/08 17:11:03 grex Exp $

/**
 * Uses PHPLib's database abstraction class
 */

/**
 * The task of this class is to give e-mail advice to editors and
 * administrators when a new content has been introduced or changed
 */

class Monitor {

    var $seccion;
    var $editors;

    function Monitor($seccion) {
        global $db;

        $this->seccion = $seccion;

        /* Se avisa a los editores y administradores de la seccion */
	$db->query("SELECT email FROM auth_user WHERE seccion='$seccion'");
        while ($db->next_record()) {
            $this->editors[] = $db->f("email");
        }

        $this->_sendMail();

    }

    function _sendMail() {

        while (is_array($this->editors) && list(, $correo) = each($this->editors)) {
            mail($correo,"[Scouts-es - ".$this->seccion."] Novedades", $message, "From: ".$GLOBALS["ml_fromaddr"]."\nReply-To: ".$GLOBALS["ml_replyaddr"]."\nX-Mailer: PHP");
        }
    }
}

?>