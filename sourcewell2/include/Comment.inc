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
// $Id: Comment.inc,v 1.1 2002/03/08 17:11:03 grex Exp $

/**
 * Requires table.inc, html.inc and lib.inc
 * should use PHPLib's database abstraction class
 */

class Comment {

    var $id;              // id del contenido comentado
    var $number;          // número de comentario sobre ese contenido
    var $parent;          // comentario padre (0 si es el primero) en caso de respuesta

    function Comment() {

        $title = new TextField('Title', 'title', '', 1);
        $title->setIsTitle();
        $body = new TextAreaField('Body', 'body', '', 1);
        $body->showType('B');
        $identificador = new HiddenField('identificador', 'id', $id, 1);
        $padre = new HiddenField('Comentario Padre', 'parent', $parent, 0);

        $fields[] = $title;
        $fields[] = $body;
        $fields[] = $identificador;
        $fields[] = $padre;

    }

    function CommentAdd() {
      /* fields */
      /* insertion */
      /* show */
    }

    function CommentShow() {

    }

    function CommentTree() {

    }

}

?>