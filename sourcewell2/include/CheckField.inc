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
// $Id: CheckField.inc,v 1.1 2002/03/08 17:11:00 grex Exp $

/**
 * Requires table.inc and html.inc
 * Inherits from MultipleOptionField.inc
 */

class CheckField extends MultipleOptionField {

    function CheckField($description, $name, $default = '', $values = '', $notNull = 0) 
    {
        /* Parent class constructor */
        $this->MultipleOptionField($description, $name, $default, $values, $notNull);
    }
 
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