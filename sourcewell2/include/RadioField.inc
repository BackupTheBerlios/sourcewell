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
// $Id: RadioField.inc,v 1.2 2002/03/09 01:43:59 grex Exp $

/**
 * Requires Table.inc and html.inc
 */

/**
 * This class represents an array of radio buttons
 *
 * @author Gregorio Robles <grex@scouts-es.org>
 * @package Field
 * @access public
 */

class RadioField extends SelectField {

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

    function RadioField($description, $name, $default = '', $values = '', $notNull = 0)
    {
        /* Parent class constructor */
        $this->SelectField($description, $name, $default, $values, $notNull);
    }

    /**
     * Prints the form for this field (in table)
     * if there are less than 5 possibilities,
     * all of them are printed in the same line
     * otherwise, every option gets a line for itself  
     *
     * TODO: the number of possibities could be an attribute of this class
     *
     * @access public
     */

    function fieldForm()
    {
        global $table;

	if (count($this->values) < 5) { 

 	    /* Less than 5 different choices */

            $table->table_column('<b>'.$this->description.'</b>'.$this->_specifyNotNull(), '33%', '', 'right');
	    $table->table_column_start('67%', '', 'left');

            while (list(, $value) = each($this->values)) {
                $selected = $this->_isValueTheDefaultOne ($value, $this->default);
		print ' &nbsp; ';
                htmlp_form_radioButton($this->name, $value, $selected);
                print ' '.$value.' &nbsp; &nbsp; ';
	    }
            $table->table_column_finish();
            $table->table_nextRowWithColumns();

        } else {

  	    /* More than 5 different choices */

            $table->table_colspan ('<b>'.$this->description.'</b>'.$this->_specifyNotNull());
            $table->table_nextRowWithColumns();

            while (list(, $value) = each($this->values)) {
                $table->table_column($value, '33%','', 'right');
                $selected = $this->_isValueTheDefaultOne ($value, $this->default);
                $table->table_column(html_form_radioButton($this->name, $value, $selected), '67%','', 'left');
                $table->table_nextRowWithColumns();
            }
        }
    }
}

?>