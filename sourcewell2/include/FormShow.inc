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
// $Id: FormShow.inc,v 1.2 2002/03/10 01:30:20 grex Exp $

/**
 * Requires table.inc and lib.inc
 * uses PHPLib database abstraction!
 */

/*
 * FormShow class
 * Displays contents from database like the form
 *
 * +------------------------------------------------+
 * | Title (usually also a content)                 |
 * +------------------------------------------------+
 * | +--------------------++----------------------+ |
 * | | Description        ||  Content             | |
 * | +--------------------++----------------------+ |
 * | | Description        ||  Content             | |
 * | +--------------------++----------------------+ |
 * | | Description        ||  Content             | |
 * | +--------------------++----------------------+ |
 * +------------------------------------------------+
 *
 *
 * @author Gregorio Robles <grex@scouts-es.org>
 * @package Show
 * @access public
 */

class FormShow extends Show {

    /**
     * Label with the title
     * if it is left blank, it will see if a field has been specified as title
     * @var  string
     */
    var $title;
    /**
     * Allows to reflect 1:N relationships
     * @var  string
     */
    var $several;

    /**
     * Constructor
     *
     * @param   array   $tables    array with the database tables that contain the content
     * @access  public
     */

    function FormShow ($tables = '')
    {
        /* Parent class constructor */ 
        $this->Show($tables);

	/* FIXME: how are we going to implement this? */
        $this->several= '';
    }

    /**
     * Set the title
     * this will disable setting a database content as title
     * 
     * @param    string      $title       Title of the Table
     * @access public
     */

    function setTitle($title)
    {
        $this->title = $title;
    }

    /**
     * Prints the content
     *
     * @param    array      $FieldObjectArray    array of Field (and children) objects
     * @access public
     * @see Show
     * @see PHPLib
     */

    function printShow($FieldObjectArray)
    {
        global $db, $table;

        $query = $this->_generateQuery(&$FieldObjectArray);

        print "\n\n<!-- Database query: ".$query." -->\n";
        $db->query($query);
        $db->next_record();
        if ($db->num_rows() == 0) {
            print "Error in Class FormShow. method printShow().";
        }

        if (!$this->title) {
            $this->title = $this->_getTitle(&$FieldObjectArray);
        }
        $table->table_begin("This table contains ".$this->title);
        $table->table_title($this->title);

        /* Body */

        $table->table_body_begin("top");

        print "\tpor <b>".$db->f("user")."</b> - <b>".lib_date_long($db->f("creation"))."<b><br>&nbsp;\n";

        reset($FieldObjectArray);

        $table->table_columns_begin();

        while (list(, $value) = each($FieldObjectArray)) {
            // Polimorfism 
  	    $value->setShow();
            $value->fieldShow();
        }

        $table->table_columns_end();
	print "<center><font size=-1>FIXME: Modify | Comment | etc.</font></center>";
        $table->table_body_end();
        $table->table_end();

    }
}
?>