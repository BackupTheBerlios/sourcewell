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
// $Id: Field.inc,v 1.5 2002/03/18 11:09:44 grex Exp $

/**
 * Requires Table.inc, html.inc and config.inc
 * requires PHPLib
 *
 * Can be made PHPLib independent by setting the $config_PHPLib_installed
 * configuration variable to 0 in the configuration file
 */

/**
 * Field class
 * Parent class for the different types of form/database fields
 *
 * @author Gregorio Robles <grex@scouts-es.org>
 * @package Field
 * @access private
 * @see Form, Preview, Show, Summary
 */

class Field {

    /**
     * Contains the description of the field
     * @var  string
     */
    var $description;
    /**
     * Contains the name of the field
     * (should be the same as the database field) 
     * @var  string
     */
    var $name;
    /**
     * Default value for the field
     * @var  mixed    string or int depending on the database field
     */
    var $default;
    /**
     * NotNull Field
     * O if the field can be empty (= NULL)
     * 1 if the field has to be filled out (= NOT NULL)
     * @var boolean
     */
    var $notNull;

    /**
     * Constructor
     *
     * @param   string  $description     description of the field
     * @param   string  $name            name of the field
     * @param   string  $default         default value
     * @param   string  $notNull         if the field has to be filled out or not
     * @access  public
     */

    function Field($description, $name, $default = '', $notNull = 0) 
    {
        $this->description = $description;
        $this->name = $name;
        $this->notNull = $notNull;
        
        /* if value in HTTP_POST_VARS exist, that one will become the default one */

        if ($this->_getPostValue()) {
            $this->default = $this->_getPostValue();
        } else {
            $this->default = $default;
        }
    }

    /**
     * Abstract function that
     * should be rewritten by its children
     *
     *  @access private
     */

    function fieldForm()
    {
        die('<font color=red>Should be implemented by a chield of the Field class!</font>\n\n');
    }

    /**
     * Shows the content of the field (in a table)
     * may have to be rewritten by its children
     *
     * @return bolean       checks if fields labeled as NotNull are non-empty
     * @access public
     */

    function fieldShow()
    {
        global $table;
    
        if ($this->default) {
            $table->table_column('<b>'.$this->description.': <b>', $config_LeftColumnWidth, '', 'right');
            $table->table_column($this->default, $config_RightColumnWidth, '', 'left');
            $table->table_nextRowWithColumns();
            return 1;
        } elseif ($this->notNull) {
            $table->table_column('<b>'.$this->description.': <b>', $config_LeftColumnWidth, '', 'right');
            $table->table_column('<font color=red><b>Requires to be filled out</b></font>', $config_RightColumnWidth, '', 'left');
            $table->table_nextRowWithColumns();
            return 0;
        }
        return 1;
    }

    /**
     * Gets the Value of the variable $name passed through a HTTP POST method
     *
     * @return string/int  value of the field passed as POST in the form
     * @access private
     */

    function _getPostValue() {
        return $GLOBALS['HTTP_POST_VARS'][$this->name];
    }

    /**
     * Extracts the field values from database
     * FIXME: should be reimplemented in class MultipleOption
     *
     * @return string/int  value of the field in database
     * @access public
     * @see PHPLib (it can be independent)
     */

    function getFieldFromDB()
    {
        global $$config_database_variable;
        if ($config_PHPLib_installed) {
            return $$$config_database_variable->f($this->name);
	} else {
	  // TODO: with mysql or something like that
	}
    }

    /**
     * Assigns the value in database as the default one
     * (interesting for the Show class)
     *
     * @return string/int    value of the field in database
     * @access public
     * @see Show class
     */

    function setShow()
    {
        $this->default = $this->getFieldFromDB();
    }

    /**
     * Functions that help with the database insertion
     *
     * @return string/int    value of the name of the field
     * @access public
     */

    function getAttribute()
    {
        return $this->name;
    }

    /**
     * Gets the default value of the field
     * The default value depends on the situation:
     *    in Form: it can be assigned manually by the programmer
     *    in Preview: it can be put from the value in HTTP_POST_VARS
     *    in Show: it is the value stored in the database
     *
     * @return string/int    value of the default value of the field
     * @access public
     */

    function getValue()
    {
        return $this->default;
    }

    /**
     * Passes the value of the field as hidden
     * (this is interesting for Preview)
     *
     * @see Preview
     * @access public
     */

    function fieldHidden()
    {
        htmlp_form_hidden($this->name, $this->default);
    }

    /**
     * Specifies in the form visually if the field has to be filled out
     *
     * @return string       label notifying that the field has to be filled out
     * @access private
     */

    function _specifyNotNull()
    {
        if ($this->notNull) {
            return ' <b>(*)</b>';
        }
    }

    /**
     * Returns if the field can be the title
     * (has to be rewritten by the classes that can be Title)
     *
     * @return boolean       this class will always return 0; children have to rewrite it
     * @access public
     */

    function getIsTitle()
    {
        return 0;
    }
}
?>