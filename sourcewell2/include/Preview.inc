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
// $Id: Preview.inc,v 1.3 2002/04/21 15:20:31 grex Exp $

/**
 * Requires table.inc and lib.inc
 */

class Preview {

    var $title; 		// Preview Title
    var $preTitle;              // Previous string to the title
    var $allFieldsFilledOut;    // 0 if not
                                // 1 otherwise

    function Preview($title='')
    {
        $this->title = $title;
        $this->preTitle = 'Preview: ';
        $this->allFieldsFilledOut = 1; // and afterwards we make an AND with it
    }

    function setPreTitle($string = 'Preview: ')
    {
        $this->preTitle = $string;
    }  

    function getPreTitle($string)
    {
        return $this->preTitle;
    }  

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

	/* Form (all fields are passed as hidden fields */
        $form->PassAllFieldsAsHidden(&$objects, $this->allFieldsFilledOut);
    }
}

?>