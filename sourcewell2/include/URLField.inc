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
// $Id: URLField.inc,v 1.2 2002/03/09 01:43:59 grex Exp $

/**
 * Requires table.inc and html.inc
 * Inherits from TextField
 */

/**
* URLField class
* This class represents a field that contains an URL
* (char, varchar and that kind of fields in database)
*
* @author Gregorio Robles <grex@scouts-es.org>
* @package Field
* @access public
*/

class URLField extends TextField {

    /**
     * Field lenght has a new default value of 40
     * Maximum length has a new default value of 255
     */

    /**
     * Constructor
     *
     * @param   string  $description     description of the field
     * @param   string  $name            name of the field
     * @param   string  $default         default value
     * @param   string  $notNull         if the field has to be filled out or not
     * @access  public
     */

    function URLField($description, $name, $default = '', $notNull = 0)
    {
        /* Parent class constructor */
        $this->Field($description, $name, $default, $notNull);
        $this->setLength = 40;
        $this->setMaxLength = 255;
    }


    /**
     * Shows the content of the field (in a table)
     *
     * @return bolean       checks if fields labeled as NotNull are non-empty
     *                      it also checks that the values start with http:// or ftp://
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
             $table->table_column('<font color=red><b>Requires to be filled out</b></font>', '67%','', 'left');
             $table->table_nextRowWithColumns();
             return 0;
        } elseif ($this->notNull && (!ereg('http://', $this->default) || !ereg('ftp://', $this->default))) {
             $table->table_column('<b>'.$this->description.': <b>', '33%', '', 'right');
             $table->table_column('<font color=red><b>Has to be a valid URL starting with http:// or ftp://</b></font>', '67%','', 'left');
             $table->table_nextRowWithColumns();
             return 0;
        } else {
	    return 1;
        }
    }
}
?>