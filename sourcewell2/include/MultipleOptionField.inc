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
// $Id: MultipleOptionField.inc,v 1.3 2002/05/09 17:01:58 grex Exp $

/**
 * Requires table.inc and html.inc
 * Inherits from Field.inc
 */

/**
 * This class represents a hidden field in a form
 * (usually text (char, varchar, etc.) field in the database)
 *
 * @author Gregorio Robles <grex@scouts-es.org>
 * @package Field
 * @access public
 */

class HiddenField extends Field {

    /**
     * If the hidden field has to be displayed in Form, Preview and Show classes
     *
     * @var boolean            default 0
     */
    var $display;

    /**
     * Constructor
     *
     * @param   string  $description     description of the field
     * @param   string  $name            name of the field
     * @param   string  $default         default value
     * @param   string  $notNull         if the field has to be filled out or not
     * @access  public
     */

    function HiddenField($description, $name, $default = '', $notNull = 0)
    {
        /* Parent class constructor */
        $this->Field($description, $name, $default, $notNull);
        $this->display = 0;
    }

    /**
     * Sets the value of the display attribute
     * (interesting for the Preview, Show and other classes)
     *
     * @access public
     */

    function setDisplay($status = 1)
    {
        $this->display = $status;
    }  

    /**
     * Prints the form for this field (in table)
     *
     * @access public
     */

    function fieldForm()
    {
        htmlp_form_hidden($this->name, $this->default);

        if($this->display) {
  	     global $table;
             $table->table_column('<b>'.$this->description.': <b>', '33%', '', 'right');
             $table->table_column($this->default, '67%', '', 'left');
             $table->table_nextRowWithColumns();
        }
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
    
        if (!$this->default && $this->notNull) {
             $table->table_column('<b>'.$this->description.': </b>', '33%', '', 'right');
             $table->table_column('<font color=red><b>Requires to be filled out</b></font>','67%', '', 'left');
             $table->table_nextRowWithColumns();
             return 0;
        } elseif($this->display) {
             $table->table_column('<b>'.$this->description.': </b>', '33%', '', 'right');
             $table->table_column($this->default, '67%', '', 'left');
             $table->table_nextRowWithColumns();
        }
        return 1;
    }
}
?>