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
// |          Carlos Martín Ugalde <carlos@scouts-es.org>                 |
// +----------------------------------------------------------------------+
//
// $Id: TextField.inc,v 1.5 2002/05/09 17:01:59 grex Exp $

/**
 * Requires table.inc and html.inc
 * Inherits from Field.inc
 */

/**
 * TextField class
 * This class represents a Text field (char, varchar and that kind of fields in database)
 *
 * @author Gregorio Robles <grex@scouts-es.org>
 * @package Field
 * @access public
 */

class TextField extends Field {

    /**
     * Field lenght for the form
     * @var  int         default 32
     */
    var $length;
    /**
     * Maximum length of the field (from the database)
     * @var  int          default 128
     */
    var $maxlength;
    /**
     * Whether this field contains the title (for showing or previewing)
     * @var  boolean       default 0
     */
    var $isTitle;

    /**
     * Constructor
     *
     * @param   string  $description     description of the field
     * @param   string  $name            name of the field
     * @param   string  $default         default value
     * @param   string  $notNull         if the field has to be filled out or not
     * @access  public
     */

    function TextField($description, $name, $default = '', $notNull = 0)
    {
        /* Parent class constructor */
        $this->Field($description, $name, $default, $notNull);
        $this->length = 32;
        $this->maxlength = 128;
        $this->isTitle = 0;
    }

    /**
     * Gets the value of the lenght attribute
     *
     * @return int        value of the lenght attribute
     * @access public
     */

    function getLength()
    {
        return $this->length;
    }

    /**
     * Sets the value of the lenght attribute
     *
     * @access public
     */

    function setLength ($length)
    {
        $this->length = $length;
    }

    /**
     * Gets the value of the Maxlenght attribute
     *
     * @return int        value of the Maxlenght attribute
     * @access public
     */

    function getMaxLength()
    {
        return $this->maxlength;
    }

    /**
     * Sets the value of the Maxlenght attribute
     *
     * @access public
     */

    function setMaxLength($maxlength)
    {
        $this->maxlength = $maxlength;
    }

    /**
     * Sets whether the field contains the title or not
     *
     * @access public
     */

    function setIsTitle($mode = 1)
    {
        $this->isTitle = $mode;
    }

    /**
     * Gets whether the field contains the title or not
     *
     * @return boolean      Gets whether the field contains the title or not
     * @access public
     */

    function getIsTitle()
    {
        return $this->isTitle;
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
        $table->table_column(html_form_textField($this->name, $this->default, $this->length, $this->maxlength), '67%', '', 'left');
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

       if (!$this->isTitle && $this->default) {
            $table->table_column('<b>'.$this->description.': <b>', '33%', '', 'right');
            $table->table_column($this->default, '67%', '', 'left');
            $table->table_nextRowWithColumns();
            return 1;
       } elseif ($this->notNull && !$this->default) {
            $table->table_column('<b>'.$this->description.': <b>', '33%', '', 'right');
            $table->table_column('<b style="color: red">Requires to be filled out</b>', '67%','', 'left');
            $table->table_nextRowWithColumns();
            return 0;
       } else {
	   return 1;
       }
   }
}
?>