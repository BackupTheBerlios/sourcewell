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
// $Id: Form.inc,v 1.1 2002/03/08 17:11:01 grex Exp $

/**
 * Requires table.inc
 */

class Form {

    var $title; 	// Header of the table with the form
    var $target;	// target file where the form input will be processed
    var $insertButton;  // Label for the insertion button
                        // Should not be modified until you exactly know what you're doing!
    var $previewButton; // Label for the preview button
    var $preview;	// Status: 0 the first time (by default)
                        //           or when a required (NotNull) field has to be filled out
                        //         1 the second time (already previewed)

    function Form ($title = 'Form', $target = 'PHP_SELF')
    {
        $this->title = $title;
        $this->target = $target;
        $this->insertButton = 'Insert';    // It is better to do not touch this value
        $this->previewButton = 'Preview';
        $this->preview = 0;
    }

    function getPreview()
    {
        return $this->preview;
    }

    function setPreview($preview = '1')
    {
        $this->preview = $preview;
    }

    function getPreviewButton()
    {
        return $this->previewButton;
    }

    function setPreviewButton($label = 'Preview')
    {
        $this->previewButton = $label;
    }

    /* 
     * This function gets as parameter an array of objects
     * Its task is to call the form function for every object
     */

    function FormFields ($objects)
    {
        global $table;

        reset($objects);

        $table->table_begin('This table contains a form: '.$this->title);
        $table->table_title($this->title);
        $table->table_body_begin('top');
        $table->table_columns_begin();
        htmlp_form_action($this->target, array());

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

    function end_array($array_button)
    {
        $this->_end_columns();
        while (list(, $button) = each($array_button)) {
            $this->end ( $button, 1 );
        }
	$this->_finishing();
    }

    function _end_columns()
    {
        global $table;

        $table->table_column();
        $table->table_column_start('', '', 'left');
    }

    function _finishing ()
    {
        global $table;

        $table->table_column_finish();
        htmlp_form_end();
        $table->table_columns_end();
        $table->table_body_end();
        $table->table_end();
    }

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