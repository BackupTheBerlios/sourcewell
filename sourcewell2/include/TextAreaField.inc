<?php
/* vim: set expandtab tabstop=4 shiftwidth=4: */
// +----------------------------------------------------------------------+
// |        SourceWell 2 - The GPL Software Announcement System           |
// +----------------------------------------------------------------------+
// |      Copyright (c) 2001-2002 BerliOS, FOKUS Fraunhofer Institut      |
// +----------------------------------------------------------------------+
// | This program is free software. You can redistribute it and/or modify |
// | it under the terms of the GNU General Public License as published by |
// | the Free Software Foundation; either version 2 or later of the GPL.  |
// +----------------------------------------------------------------------+
// | Authors: Gregorio Robles <grex@scouts-es.org>                        |
// +----------------------------------------------------------------------+
//
// $Id: TextAreaField.inc,v 1.5 2002/03/18 11:40:29 grex Exp $

/**
 * Requires Table.inc and html.inc
 */

/**
 * This class represents a text area (blob in the database)
 *
 * @author Gregorio Robles <grex@scouts-es.org>
 * @package Field
 * @access public
 */

class TextAreaField extends Field {

    /**
     * Number of rows
     * @var  int         default 7
     */
    var $rows;
    /**
     * Number of columns
     * @var  int         default 40
     */
    var $columns;
    /**
     * How the content is shown
     *
     *    type A: (description + content)        Type B: (only content)
     *    _________________________________      ___________________________
     *    | Description || Content.....   |      | Content.............    |
     *    ---------------------------------      ---------------------------
     *
     * @var  char         default A
     */
    var $showType;

    /**
     * Constructor
     *
     * @param   string  $description     description of the field
     * @param   string  $name            name of the field
     * @param   string  $default         default value
     * @param   string  $notNull         if the field has to be filled out or not
     * @access  public
     */

    function TextAreaField($description, $name, $default = '', $notNull = 0)
    {
        /* Parent class constructor */
        $this->Field($description, $name, $default, $notNull);
        $this->rows = 7;
        $this->columns = 40;
        $this->showType = 'A';
    }

    /**
     * Gets number of rows
     *
     * @return int        value of the rows attribute
     * @access public
     */

    function getRows()
    {
        return $this->rows;
    }

    /**
     * Sets number of rows
     *
     * @param    int          $number        number of rows
     * @access public
     */

    function setRows($number)
    {
        $this->rows = $number;
    }

    /**
     * Gets number of columns
     *
     * @return int        value of the columns attribute
     * @access public
     */

    function getColumns()
    {
        return $this->columns;
    }

    /**
     * Sets number of columns
     *
     * @param    int          $number        number of columns
     * @access public
     */

    function setColumns($number)
    {
        $this->columns = $number;
    }

    /**
     * Gets how it will be displayed
     *
     * @return char        value of the showType attribute
     * @access public
     */

    function getShowType()
    {
        return $this->showType;
    }

    /**
     * Sets how it will be displayed
     *
     * @param    char          $showType        'A' or 'B' type
     * @access public
     */

    function setShowType ($showType)
    {
        $this->showType = $showType;
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
        $table->table_column(html_form_textArea($this->name, $this->default, $this->columns, $this->rows), '67%', '', 'left');
        $table->table_nextRowWithColumns();
    }

    /**
     * Shows the content of the field (in a table)
     *
     * @return bolean       checks if fields labeled as NotNull are non-empty
     * @access public
     */

    function fieldShow()
    {
        global $table;

        if ($this->default && $this->showType == 'A') {
            $table->table_column('<b>'.$this->description.': <b>', '33%', '', 'right');
            $table->table_column($this->default, '67%', '', 'left');
            $table->table_nextRowWithColumns();
            return 1;
        } elseif ($this->default && $this->showType == 'B') {
    	    $table->table_colspan($this->default, 2, '', 'left');
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