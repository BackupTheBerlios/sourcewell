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
// $Id: MailingList.inc,v 1.1 2002/03/08 17:11:03 grex Exp $

/**
 * Requires table.inc, html.inc and lib.inc
 * Uses PHPLib's database abstraction class
 */

class MailingList {

    var $seccion;

    function MailingList($seccion) {

        $this->seccion = $seccion;
    }

    /* Form for subscribing a mailing list */
    /* (this is really a database insertion) */

    function subscribe() {

    }

    function unsubscribe() {

    }

    function send() {

    }
}


?>