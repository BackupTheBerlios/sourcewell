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
// $Id: MultipleOptionField.inc,v 1.1 2002/03/08 17:11:01 grex Exp $

/**
 * Requires table.inc and html.inc
 * Inherits from SelectField.inc
 */

class MultipleOptionField extends SelectField {

    function MultipleOptionField($description, $name, $default = '', $values = '', $notNull = 0)
    {
        /* Parent class constructor */
        $this->SelectField($description, $name, $default, $values, $notNull);
    }
 
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

   function fieldHidden()
   {
        while (is_array($this->default) && list(, $value) = each($this->default)) {
            $name = $this->name.'[]';
            htmlp_form_hidden($name, $value);
	}
   }

   /**
    * These methods should help with the database interaction
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