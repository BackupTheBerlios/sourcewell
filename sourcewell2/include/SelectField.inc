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
// $Id: SelectField.inc,v 1.2 2002/03/09 01:43:59 grex Exp $

/**
 * Requires table.inc and html.inc
 * Inherits from Field.inc
 */

/**
 * Selectfield
 * This class represents a selection (single-option) box
 *
 * @author Gregorio Robles <grex@scouts-es.org>
 * @package Field
 * @access public
 */

class SelectField extends Field {

    /**
     * Array with values (usually in string format) that can be selected (the options)
     * @var  array
     */
    var $values;

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

    function SelectField($description, $name, $default = '', $values = '', $notNull = 0)
    {
        /* Parent class constructor */
        $this->Field($description, $name, $default, $notNull);
        $this->values = $values;
    }

    /**
     * Adds a new option
     *
     * @param        string/int       $value       option to be added
     * @access public
     */

    function addValue($value)
    {
        $this->values[] = $value;
    }

    /**
     * Checks if an option is in the array
     *
     * @param        string/int       $option       option to be found
     * @param        string/int       $array        array of options
     * @returns boolean
     * @access private
     */

    function _inArray($option, $array)
    { 
        for ($i=0; $i < count($array); $i++) {
	    if ($array[$i] == $option) {	
		return true;
	    }
        }
        return false;
    }

    /**
     * Checks if option is the default one
     *
     * @param        string/int       $value       option to be found
     * @param        string/int       $default     default value
     * @returns boolean
     * @access private
     */

    function _isValueTheDefaultOne($value, $default)
    {
        if ($value == $default) {
            return 1;
        } else {
            return 0;
        }
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
        htmlp_form_select($this->name);
        while (list(, $value) = each($this->values)) {
            $selected = $this->_isValueTheDefaultOne ($value, $this->default);
            htmlp_form_select_option($value, $selected, $value);
        }
        htmlp_form_select_end();
        $table->table_column_finish();
        $table->table_nextRowWithColumns();
    }
}
?>