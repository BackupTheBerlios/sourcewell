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
// $Id: MultipleSelectField.inc,v 1.2 2002/03/09 01:43:59 grex Exp $

/**
 * Requires Table.inc and html.inc
 */

/**
 * MultipleSelectfield
 * This class represents a selection (multiple-option) box
 *
 * @author Gregorio Robles <grex@scouts-es.org>
 * @package Field
 * @access public
 * @see Form, Preview, Show, Summary
 */

class MultipleSelectField extends MultipleOptionField {

    /**
     * Number of options that are shown
     * @var  int         its default value is 6 unless its number is smaller
     */
    var $size;

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

    function MultipleSelectField($description, $name, $default = '', $values = '', $notNull = 0)
    {
        /* Parent class constructor */
        $this->MultipleOptionField($description, $name, $default, $values, $notNull);

        $this->$size = count($this->values);
        if ($this->size > 6) {
            $this->size = 6;
        }
    }

    /**
     * Gets the size
     *
     * @return int        value of the size attribute
     * @access public
     */
 
    function getSize()
    {
        return $this->size;
    }

    /**
     * Sets the size
     *
     * @access public
     */

    function setSize($size)
    {
        $this->size = $size;
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
        $table->table_column_start('67%', '', 'left');
        $name = $this->name.'[]';
        htmlp_form_select($name, 1, $this->size);

        while (list(, $value) = each($this->values)) {
            $selected = $this->_inArray ($value, $this->default);
            htmlp_form_select_option($value, $selected, $value);
        }
        htmlp_form_select_end();
        $table->table_column_finish();
        $table->table_nextRowWithColumns();

        $table->table_colspan('<font size=-1><b>Multiple selections</b>:\n<br> press the <b>CONTROL</b> (PC) or the <b>SHIFT</b> (Mac) key while choosing multiple options with the mouse.</font>');

        $table->table_nextRowWithColumns();
    }
}
?>