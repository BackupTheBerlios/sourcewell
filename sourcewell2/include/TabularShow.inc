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
// $Id: TabularShow.inc,v 1.3 2002/05/15 10:50:32 grex Exp $

/**
 * Requires table.inc
 * Depends on PHPLib's database abstraction classes!
 */

/*
 * FormShow class
 * Displays contents from database in "tabular" form
 *
 * +------------------------------------------------+ 
 * | +-------------++-----------++----------------+ | 
 * | |   Field1    ||   Field2  ||    Field3      | |  Title
 * | +-------------++-----------++----------------+ |             
 * +------------------------------------------------+
 * | +-------------++-----------++----------------+ |
 * | |   Value11   ||  Value12  ||    Value13     | |
 * | |-------------++-----------++----------------| |
 * | |   Value21   ||  Value22  ||    Value23     | |  Values
 * | |-------------++-----------++----------------| |
 * | |   Value31   ||  Value32  ||    Value33     | |
 * | +-------------++-----------++----------------+ |
 * +------------------------------------------------+
 *
 *
 * @author Gregorio Robles <grex@scouts-es.org>
 * @package Show
 * @access public
 */

class TabularShow extends Show {

    /**
     * Constructor
     *
     * @param   array   $tables    array with the database tables that contain the content
     * @access  public
     */

    function TabularShow ($tables = '')
    {
        /* Parent class constructor */ 
        $this->Show($tables);
        $this->setOrder('creation DESC');
        $this->setLimit('10');       
    }

    /**
     * Prints the content
     *
     * @param    array      $FieldObjectArray    array of Field (and children) objects
     * @access public
     * @see Show
     * @see PHPLib
     */

    function printShow ($FieldObjectArray)
    {
        global $db, $table;

        $table->table_begin('This table contains FIXME');

        /* column width (by now, they're all equal) */ 
        /* FIXME: should change in the future */

        $width = 100/(sizeof($this->fields)).'%';

        /* Header of the information table */

        $table->table_title_begin();
        $table->table_columns_begin();

        reset($FieldObjectArray);

        while (list(, $value) = each($FieldObjectArray)) {
            // Polimorfism 
            $table->table_column('<b>'.$value->getAttribute().'</b>', $width);
        }

        $table->table_columns_end();
        $table->table_title_end();

        /* Body */

        $table->table_body_begin('top');
        $table->table_columns_begin();

        $query = $this->_generateQuery(&$FieldObjectArray);

        print "\n\n<!-- Database query: ".$query." -->\n";
        $db->query($query);
        $i = 0;
        while ($db->next_record()) {
            reset($FieldObjectArray);
            if ($i%2) {
	        $bgcolor = 'white';
            } else {
                $bgcolor = '';
            }
            while (list(, $key) = each($FieldObjectArray)) {
                $table->table_column($db->f($key->getAttribute()), $width, $bgcolor);
            }
            $table->table_nextRowWithColumns();
            $i++;
        }

        /* FIXME: One row of columns more than required! */

        $table->table_columns_end();
        $table->table_body_end();
        $table->table_end();
    }
}
?>