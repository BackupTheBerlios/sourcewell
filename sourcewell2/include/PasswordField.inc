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
// $Id: PasswordField.inc,v 1.2 2002/03/09 01:43:59 grex Exp $

/**
 * Requires Table.inc and html.inc
 */

/**
 * PasswordField class
 * This class represents a password field (char, varchar and that kind of fields in database)
 *
 * @author Gregorio Robles <grex@scouts-es.org>
 * @package Field
 * @access public
 */

class PasswordField extends TextField {

    /**
     * Constructor
     *
     * @param   string  $description     description of the field
     * @param   string  $name            name of the field
     * @param   string  $default         default value
     * @param   string  $notNull         if the field has to be filled out or not
     * @access  public
     */

    function PasswordField($description, $name, $default = '', $notNull = 0)
    {
        /* Parent class constructor */
        $this->TextField($description, $name, $default, $notNull);
    }

    /**
     * Prints the form for this field (in table)
     *
     * @access public
     */

    function fieldForm()
    {
        global $table;

        $table->table_column('<b>'.$this->description.': </b>'.$this->_specifyNotNull(), '33%', '', 'right');
        $table->table_column(html_form_PassWordField($this->name, $this->length, $this->maxlength, $this->default), '67%', '', 'left');
        $table->table_nextRowWithColumns();
    }

    /**
     * Shows the content of the field (in a table)
     * Replaces characters with * so that it does not display the password
     *
     * @return bolean       checks if fields labeled as NotNull are non-empty
     * @access public
     */

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