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
// $Id: Preview.inc,v 1.4 2002/05/07 15:16:00 grex Exp $

/**
 * Class Preview: displays a preview of the form to be inserted
 *
 * TODO: further description
 *
 * @author Gregorio Robles <grex@scouts-es.org>
 * @package Form
 * @access public
 * @see Table.inc and lib.inc
 *
 * TODO: language configurability -> class variable and translation function!
 * TOOD: should be made PHPLib independent
 */

class Preview {
   /**
     * Preview Title
     * @var  string
     */
    var $title;
   /**
     * Previous string to the title
     * @var  string
     */
    var $preTitle;
   /**
     * Is true if all the required fields have been filled out
     * @var  boolean
     */
    var $allFieldsFilledOut;

    /**
     * Constructor
     *
     * @param   string  $title           Preview title
     * @access  public
     */
    function Preview($title='')
    {
        $this->title = $title;
        $this->preTitle = 'Preview: ';
        $this->allFieldsFilledOut = 1; // and afterwards we make an AND with it
    }

    /**
     * Allows to set the string that will be put before the title
     *
     * @param    string       $string      String that will be prepended
     * @access public
     */
    function setPreTitle($string = 'Preview: ')
    {
        $this->preTitle = $string;
    }  

    /**
     * Gets string that will be put before the title
     *
     * @return    string       $string      String that will be prepended
     * @access public
     */
    function getPreTitle($string)
    {
        return $this->preTitle;
    }  

    /**
     * Gets the title out of an array of Field (and children) objects
     *
     * @param     array of objects   $FieldObjectArray    Array with Field (and child) Objects
     * @return    string       $string      String that will be prepended
     * @access private
     */
    function _getTitle($FieldObjectArray)
    {
        reset($FieldObjectArray);

        while (list(, $value) = each($FieldObjectArray)) {
            // Polimorfism 
	    if ($value->getIsTitle()) {
	        return $value->default;
            }
        }
    }

    /**
     * Shows 
     *
     * @param     array of objects   $objects    Array with Field (and child) Objects
     *
     * @global    object      $table      Table object
     * @global    object      $form       Form object
     *                                    (allows to pass all fields as hidden fields)
     * @global    object      $auth       PHPLib authentication object
     *
     * @access private
     * @see PHPLib, Table
     */
    function ShowFields($objects)
    {
        global $table, $form, $auth;

        if (!$this->title) {
            $this->title = $this->_getTitle(&$objects);
        }

        $table->table_begin('This table contains a form preview: '.$this->title);
        $table->table_title($this->preTitle.$this->title);
        $table->table_body_begin('top');
        print "\tby <b>".$auth->auth['uname']."</b> - <b>".lib_date_long(time(), 1)."</b><br>&nbsp;\n";

        $table->table_columns_begin();
        reset($objects);
        while (list(, $value) = each($objects)) {
            // Polimorfism 
            $this->allFieldsFilledOut = $this->allFieldsFilledOut & $value->fieldShow();
        }

	/* Form (all fields are passed as hidden fields) */
        $form->PassAllFieldsAsHidden(&$objects, $this->allFieldsFilledOut);
    }
}

?>