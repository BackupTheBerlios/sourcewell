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
// $Id: SelectField.inc,v 1.1 2002/03/08 17:11:00 grex Exp $

/**
 * Requires table.inc and html.inc
 * Inherits from Field.inc
 */

class SelectField extends Field {

    var $values;		// Array with values that can be selected

    function SelectField($description, $name, $default = '', $values = '', $notNull = 0)
    {
        /* Parent class constructor */
        $this->Field($description, $name, $default, $notNull);
        $this->values = $values;
    }

    function addValue($value)
    {
        $this->values[] = $value;
    }

    /* Checks if $value is in the array */

    function _inArray($needle, $haystack)
    { 
        for ($i=0; $i < count($haystack); $i++) {
	    if ($haystack[$i] == $needle) {	
		return true;
	    }
        }
        return false;
    }

    /* Checks if $value is the default value */

    function _isValueTheDefaultOne ($value, $default)
    {
        if ($value == $default) {
            return 1;
        } else {
            return 0;
        }
    }

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