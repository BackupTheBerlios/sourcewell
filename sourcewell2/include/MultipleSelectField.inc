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
// $Id: MultipleSelectField.inc,v 1.1 2002/03/08 17:11:01 grex Exp $

/**
 * Requires table.inc and html.inc
 * Inherits from MultipleOptionField.inc
 */

class MultipleSelectField extends MultipleOptionField {

    var $size;		// number of options that are shown
			// its default value is 6
			// unless its number is smaller

    function MultipleSelectField($description, $name, $default = '', $values = '', $notNull = 0)
    {
        /* Parent class constructor */
        $this->MultipleOptionField($description, $name, $default, $values, $notNull);

        $this->$size = count($this->values);
        if ($this->size > 6) {
            $this->size = 6;
        }
    }
 
    function getSize()
    {
        return $this->size;
    }

    function setSize($size)
    {
        $this->size = $size;
    }

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