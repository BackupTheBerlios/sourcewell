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
// $Id: RadioField.inc,v 1.1 2002/03/08 17:11:01 grex Exp $

/**
 * Requires table.inc and html.inc
 * Inherits from SelectField.inc
 */

class RadioField extends SelectField {

    function RadioField($description, $name, $default = '', $values = '', $notNull = 0)
    {
        /* Parent class constructor */
        $this->SelectField($description, $name, $default, $values, $notNull);
    }

    function fieldForm()
    {
        global $table;

	if (count($this->values) < 4) { 

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