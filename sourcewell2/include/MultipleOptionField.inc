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
// $Id: MultipleOptionField.inc,v 1.2 2002/03/09 01:43:59 grex Exp $

/**
 * Requires Table.inc and html.inc
 */

/**
 * MultipleOptionField class
 * This class represents a field where multiple options can be selected
 * It is a class that inherits from SelectField
 * and that serves as parent class for MultipleSelectField and CheckField
 *
 * @author Gregorio Robles <grex@scouts-es.org>
 * @package Field
 * @access private
 */

class MultipleOptionField extends SelectField {

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

    function MultipleOptionField($description, $name, $default = '', $values = '', $notNull = 0)
    {
        /* Parent class constructor */
        $this->SelectField($description, $name, $default, $values, $notNull);
    }
 
    /**
     * Shows the content of the field (in a table)
     *
     * FIXME: @return bolean       checks if fields labeled as NotNull are non-empty
     *   ---> has to be implemented
     * @access public
     */

    function fieldShow()
    {
        global $table;

        if ($this->default) {
            $table->table_column('<b>'.$this->description.': <b>', '33%','', 'right');
            while (is_array($this->default) && list(, $value) = each($this->default)) {
                $selected_values .= $value.", ";
            }
            $selected_values = ereg_replace(', $', '', $selected_values);

            $table->table_column($selected_values, '67%','', 'left');
            $table->table_nextRowWithColumns();
        }
    }

    /**
     * Passes the value of the field as hidden
     * (this is interesting for Preview)
     *
     * @see Preview
     * @access public
     */

    function fieldHidden()
    {
        while (is_array($this->default) && list(, $value) = each($this->default)) {
            $name = $this->name.'[]';
            htmlp_form_hidden($name, $value);
	}
    }

    /**
     * Functions that help with the database insertion
     *
     * @return string/int    value of the name of the field
     * @access public
     */

    function getAttribute()
    {
        $i = 0;
        while (is_array($this->default) && list(, $value) = each($this->default)) {
	    $i++;
            $return .= $this->name.$i.', ';
        }
        /* we remove the last comma */
        $return = substr($return, 0, -2);
        return $return;
    }

    /**
     * Gets the default value of the field
     * The default value depends on the situation:
     *    in Form: it can be assigned manually by the programmer
     *    in Preview: it can be put from the value in HTTP_POST_VARS
     *    in Show: it is the value stored in the database
     *
     * @return string/int    value of the default value of the field
     * @access public
     */

    function getValue()
    {
        reset($this->default);
        while (is_array($this->default) && list(, $value) = each($this->default)) {
            $return .= $value.', ';
        }
        /* we remove the last comma */
        $return = substr($return, 0, -2);
        return $return;
    }
}

?>