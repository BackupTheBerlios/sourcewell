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
// $Id: TextAreaField.inc,v 1.1 2002/03/08 17:11:00 grex Exp $

/**
 * Requires table.inc and html.inc
 * Inherits from Field.inc
 */

/*
 * Class tha represents a text area
 */

class TextAreaField extends Field {

    var $rows;			// number of rows. By default 7
    var $columns;		// number of columns. By default 40
    var $showType;	// How the content is shown:
			// type 'A':    Description: Content
			// type 'B':    Content
                        // By default: type 'A'

    function TextAreaField($description, $name, $default = '', $notNull = 0)
    {
        /* Parent class constructor */
        $this->Field($description, $name, $default, $notNull);
        $this->rows = 7;
        $this->columns = 40;
        $this->showType = 'A';
    }

    function getRows()
    {
        return $this->rows;
    }

    function setRows($number)
    {
        $this->rows = $number;
    }

    function getColumns()
    {
        return $this->columns;
    }

    function setColumns($number)
    {
        $this->columns = $number;
    }

    function getShowType()
    {
        return $this->showType;
    }

    function setShowType ($showType)
    {
        $this->showType = $showType;
    }

    function fieldForm()
    {
        global $table;

        $table->table_column('<b>'.$this->description.': </b>'.$this->_specifyNotNull(), '33%', '', 'right');
        $table->table_column(html_form_textAreao($this->name, $this->default, $this->columns, $this->rows), '67%', '', 'left');
        $table->table_nextRowWithColumns();
    }

   function fieldShow()
   {
        global $table;

        if ($this->default && $this->showType == 'A') {
            $table->table_column('<b>'.$this->description.': <b>', '33%', '', 'right');
            $table->table_column($this->default, '67%', '', 'left');
            $table->table_nextRowWithColumns();
            return 1;
        } elseif ($this->default && $this->showType == 'B') {
    	    $table->table_colspan($this->default);
            $table->table_nextRowWithColumns();
            return 1;
        } elseif ($this->notNull) {
            $table->table_column('<b>'.$this->description.': <b>', '33%', '', 'right');
            $table->table_column('<font color=red><b>Requires to be filled out</b></font>', '67%', '', 'left');
            $table->table_nextRowWithColumns();
            return 0;
	} else {
	    return 1;
        }
   }
}

?>