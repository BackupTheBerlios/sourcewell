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
// $Id: PasswordField.inc,v 1.1 2002/03/08 17:10:59 grex Exp $

/**
 * Requires table.inc and html.inc
 * Inherits from TextField
 */

/*
 * Class that represents a Password Field
 */

class PasswordField extends TextField {

    function PasswordField($description, $name, $default = '', $notNull = 0)
    {
        /* Parent class constructor */
        $this->TextField($description, $name, $default, $notNull);
    }


    function fieldForm()
    {
        global $table;

        $table->table_column('<b>'.$this->description.': </b>'.$this->_specifyNotNull(), '33%', '', 'right');
        $table->table_column(html_form_PassWordField($this->name, $this->length, $this->maxlength, $this->default), '67%', '', 'left');
        $table->table_nextRowWithColumns();
    }

    /* Rewritten function in order to avoid printing the password in clear text */

   function fieldShow()
   {
        global $table;

        if ($this->default) {
            $table->table_column('<b>'.$this->description.': <b>', '33%', '', 'right');
            $table->table_column(ereg_replace('.', '*', $this->default), '67%', '', 'left');
            $table->table_nextRowWithColumns();
            return 1;
        } elseif ($this->notNull) {
            $table->table_column('<b>'.$this->description.': <b>', '33%', '', 'right');
            $table->table_column('<font color=red><b>Requires to be filled out</b></font>', '67%', '', 'left');
            $table->table_nextRowWithColumns();
            return 0;
        }
        return 1;
   }
}

?>