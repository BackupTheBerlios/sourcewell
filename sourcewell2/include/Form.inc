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
// $Id: Form.inc,v 1.6 2002/05/09 17:07:03 grex Exp $

/**
 * Requires table.inc
 */

/*
 * Form class
 * Displays a form as this
 *
 * +------------------------------------------------+
 * | Title                                          |
 * +------------------------------------------------+
 * | +----------------++--------------------------+ |
 * | | Description1   ||                          | |
 * | +----------------++--------------------------+ |
 * | | Description2   ||                          | |
 * | +----------------++--------------------------+ |
 * | | Description3   ||                          | |
 * | +----------------++--------------------------+ |
 * +------------------------------------------------+
 *
 *
 * @author Gregorio Robles <grex@scouts-es.org>
 * @access public
 * @see Field
 */

class Form {

    /**
     * Header of the table with the form 
     * @var  string
     */
    var $title;
    /**
     * Target file where the form input will be processed
     * @var  string
     */
    var $target;
    /**
     * Label for the insertion button
     * Should not be modified until you exactly know what you're doing!
     * @var  string
     */
    var $insertButton; 
    /**
     * Label for the preview button
     * @var  string
     */
    var $previewButton;
    /**
     * Status: 0 the first time (by default)
     *           or when a required (NotNull) field has to be filled out
     *         1 the second time (already previewed and required fields filled out)
     * @var  boolean
     */ 
    var $preview;

    /**
     * Constructor
     *
     * @param   string     $title      Header of the table with the form
     * @param   string     $target     Target file where the form input will be processed 
     * @access  public
     */

    function Form ($title = 'Form', $target = 'PHP_SELF')
    {
        $this->title = $title;
        $this->target = $target;
        $this->insertButton = 'Insert';    // It is better to do not touch this value
        $this->previewButton = 'Preview';
        $this->preview = 0;
    }

    /**
     * Get Preview Status
     * 
     * @returns    boolean     1 if the form can be submitted
     * @access public
     */
    function getPreview()
    {
        return $this->preview;
    }

    /**
     * Set preview status
     * 
     * @params    boolean     1 if the form can be submitted
     * @access public
     */

    function setPreview($preview = '1')
    {
        $this->preview = $preview;
    }

    /**
     * Get Preview Button Label
     * 
     * @returns    string      Preview Button Label
     * @access public
     */

    function getPreviewButton()
    {
        return $this->previewButton;
    }

    /**
     * Sets Preview Button Label
     * 
     * @param    string      Preview Button Label
     * @access public
     */

    function setPreviewButton($label = 'Preview')
    {
        $this->previewButton = $label;
    }

    /** 
     * Calls the form function for every object and returns them in a table
     *
     * @param   array   $objects    Array with all the Field objects in the form
     * @see Field
     * @access public
     */

    function FormFields ($objects)
    {
        global $table;

        reset($objects);

        $table->table_begin('This table contains a form: '.$this->title);
        $table->table_title($this->title);
        $table->table_body_begin('top');
        htmlp_form_action($this->target, array());
        $table->table_columns_begin();

        while (list(, $value) = each($objects)) {
            // Polimorfism
            $value->fieldForm();
        }

        if ($this->preview) {
            $this->end_array(array($this->previewButton,$this->insertButton));
        } else {
            $this->end($this->previewButton);
        }
    }

    /** 
     * Ends the form with one or more buttons
     *
     * @param   string     $button        Label of the button
     * @param   boolean    $multiple      If there are several buttons
     * @access public
     */

    function end($button, $multiple = '0')
    {
        if (!$multiple) {
            $this->_end_columns();
        }
        htmlp_form_submit($button, $button);
        if (!$multiple) {
            $this->_finishing();
        }
    }

    /** 
     * Ends the form with several buttons
     *
     * @param   array     $button_array       Array of buttons
     * @access public
     */

    function end_array($array_button)
    {
        $this->_end_columns();
        while (list(, $button) = each($array_button)) {
            $this->end($button, 1);
        }
	$this->_finishing();
    }

    /** 
     * Finishes Columns
     *
     * @access private
     */

    function _end_columns()
    {
        global $table;

        $table->table_column('&nbsp;', '33%');
        $table->table_column_start('67%', '', 'left');
    }

    /** 
     * Handles the table finishing after putting the buttons
     *
     * @access private
     */

    function _finishing ()
    {
        global $table;

        $table->table_column_finish();
        htmlp_form_end();
        $table->table_columns_end();
        $table->table_body_end();
        $table->table_end();
    }

    /** 
     * When previewing, it is interesting to pass all fields as hidden
     * and put an insertion button in the Preview box
     *
     * @param   array   $objects    Array with all the Field objects in the form
     * @param   boolean $allFieldsFilledOut    If true all required fields have been filled out
     * @see Field, Preview
     * @access public
     */

    function PassAllFieldsAsHidden($objects, $allFieldsFilledOut) {

        if ($allFieldsFilledOut) {
            htmlp_form_action($this->target, array());
            reset($objects);
            while (list(, $value) = each($objects)) {
                // Polimorfism 
                $value->fieldHidden();
            }

            $this->end($this->insertButton);
            $this->setPreview();
        } else {
	    $this->_finishing();
        }
    }
}
?>