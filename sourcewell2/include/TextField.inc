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
// $Id: TextField.inc,v 1.1 2002/03/08 17:11:00 grex Exp $

/**
 * Requires table.inc and html.inc
 * Inherits from Field.inc
 */

/**
 * This class represents a Text field
 */

class TextField extends Field {

    var $length; 		// TextField length in the form
                                // by default its value is 32
    var $maxlength;	       // maximum length of the field (from the database)
                                // by default its value is 128
    var $isTitle;    // '1' if this field contains the title (for showing or previewing)
			// by default its value is 0

    function TextField($description, $name, $default = '', $notNull = 0)
    {
        /* Parent class constructor */
        $this->Field($description, $name, $default, $notNull);
        $this->length = 32;
        $this->maxlength = 128;
        $this->isTitle = 0;
    }

    function getLength()
    {
        return $this->length;
    }

    function setLength ($length)
    {
        $this->length = $length;
    }

    function getMaxLength()
    {
        return $this->maxlength;
    }

    function setMaxLength($maxlength)
    {
        $this->maxlength = $maxlength;
    }

    function setIsTitle($mode = 1)
    {
        $this->isTitle = $mode;
    }

    function getIsTitle()
    {
        return $this->isTitle;
    }

    function fieldForm()
    {
        global $table;

        $table->table_column('<b>'.$this->description.': <b>'.$this->_specifyNotNull(), '33%', '', 'right');
        $table->table_column(html_form_textField($this->name, $this->default, $this->length, $this->maxlength), '67%', '', 'left');
        $table->table_nextRowWithColumns();
    }

    function fieldShow()
    {
       global $table;

       if (!$this->isTitle && $this->default) {
            $table->table_column('<b>'.$this->description.': <b>', '33%', '', 'right');
            $table->table_column($this->default, '67%', '', 'left');
            $table->table_nextRowWithColumns();
            return 1;
       } elseif ($this->notNull && !$this->default) {
            $table->table_column('<b>'.$this->description.': <b>', '33%', '', 'right');
            $table->table_column('<font color=red><b>Requires to be filled out</b></font>', '67%','', 'left');
            $table->table_nextRowWithColumns();
            return 0;
       } else {
	   return 1;
       }
   }
}

?>