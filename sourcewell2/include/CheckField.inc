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
// $Id: CheckField.inc,v 1.2 2002/03/09 01:43:59 grex Exp $

/**
 * Requires Table.inc and html.inc
 */

/**
 * CheckField class
 * This class represents an array of check buttons
 *
 * @author Gregorio Robles <grex@scouts-es.org>
 * @package Field
 * @access public
 */

class CheckField extends MultipleOptionField {

    /**
     * Constructor
     *
     * @param   string  $description     description of the field
     * @param   string  $name            name of the field
     * @param   string  $default         default value
     * @param   string  $values          array (of strings) with the different possibilities
     * @param   string  $notNull         if the field has to be filled out or not
     * @access  public
     */

    function CheckField($description, $name, $default = '', $values = '', $notNull = 0) 
    {
        /* Parent class constructor */
        $this->MultipleOptionField($description, $name, $default, $values, $notNull);
    }

    /**
     * Prints the form for this field (in table)
     *
     * TODO: the number of possibities in one row
     *       could be an attribute of this class (@see RadioField)
     *
     * @access public
     */
 
    function fieldForm()
    {
        global $table;

        $table->table_colspan ('<b>'.$this->description.'</b>'.$this->_specifyNotNull());
        $table->table_nextRowWithColumns();

        while (list(, $value) = each($this->values)) {
            $table->table_column($value, '33%', '', 'right');
            $selected = $this->_inArray ($value, $this->default);
            $name = $this->name.'[]'; 
            $table->table_column(html_form_checkBox($name, $value, $selected), '67%', '', 'left');
            $table->table_nextRowWithColumns();
        }
    }
}
?>