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
// $Id: Field.inc,v 1.1 2002/03/08 17:10:56 grex Exp $

/**
 * Requires table.inc and html.inc
 * some classes also require lib.inc
 * Should be PHPLib independent
 */

class Field {

    var $description; 	// field description
    var $name;		// field name (should be the same as the database field)
    var $default;	// default value for field
    var $show;          // 0 if the field is shown for preview
                        // 1 if the field is shown (from database) 
    var $notNull;       // 0 if the field can be empty (null)
                        // 1 if the field cannot be empty (null)

    /* Constructor */

    function Field($description, $name, $default = '', $notNull = 0) 
    {
        $this->description = $description;
        $this->name = $name;
        $this->notNull = $notNull;
        
        /* if value in HTTP_POST_VARS exist, that one will become the default one */

        if ($this->_getPostValue($name)) {
            $this->default = $this->_getPostValue($name);
        } else {
            $this->default = $default;
        }
    }

    function _getPostValue($name) {
        return $GLOBALS['HTTP_POST_VARS'][$name];
    }

    /**
     * Function FieldForm is an abstract function that
     * should be rewritten by its children */

   function fieldForm()
   {
       die('<font color=red>Should be implemented by a chield of the Field class!</font>\n\n');
   }

   /**
    * Function FieldShow
    * shows the field
    */

   function fieldShow()
   {
       global $table;
    
       if ($this->default) {
            $table->table_column('<b>'.$this->description.': <b>', '33%', '', 'right');
            $table->table_column($this->default, '67%', '', 'left');
            $table->table_nextRowWithColumns();
            return 1;
       } elseif ($this->notNull) {
            $table->table_column('<b>'.$this->description.': <b>', '33%', '', 'right');
            $table->table_column('<font color=red><b>Requires to be filled out</b></font>', '67%', '', 'left');
            $table->table_nextRowWithColumns();
            return 0;
       }
       return 1;
   }

   /**
    * Function FieldFromDB
    * extracts the field values from database
    * FIXME: should be reimplemented in class MultipleOption
    */

   function getFieldFromDB()
   {
       global $BBDD;

       return $BBDD->f($this->name);
   }

   function setShow()
   {
       $this->default = $this->getFieldFromDB();
   }

   /**
    * Functions that help with the database insertion
    */

   function getAttribute()
   {
       return $this->name;
   }

   function getValue()
   {
       return $this->default;
   }

    /**
     * Function FieldHidden
     * passes the value of the field as hidden
     * this is interesting for preview */

   function fieldHidden()
   {
        htmlp_form_hidden($this->name, $this->default);
   }

   function _specifyNotNull()
   {
       if ($this->notNull) {
           return ' <b>(*)</b>';
       }
   }

   function getIsTitle()
   {
        return 0;
   }
}

?>