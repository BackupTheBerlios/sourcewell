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
// $Id: FormShow.inc,v 1.1 2002/03/08 17:10:58 grex Exp $

/**
 * Requires table.inc and lib.inc
 * uses PHPLib database abstraction!
 */

class FormShow extends Show {

    var $title;     // String with the title
                    // if it is left blank, it will see if a field has been specified as title
    var $several;  // allows to reflect 1:N relationship

    function FormShow ($tables = '')
    {
        /* Parent class constructor */ 
        $this->Show($tables);

	/* FIXME: how are we going to implement this? */
        $this->several= '';
    }

    function setTitle($title)
    {
        $this->title = $title;
    }

    function printShow($FieldObjectArray)
    {
        global $BBDD, $table;

        $query = $this->_generateQuery(&$FieldObjectArray);

        print "\n\n<!-- Database query: ".$query." -->\n";
        $BBDD->query($query);
        $BBDD->next_record();
        if ($BBDD->num_rows() == 0) {
            print "Error in Class Show. method printShow().";
        }

        if (!$this->title) {
            $this->title = $this->_getTitle(&$FieldObjectArray);
        }
        $table->table_begin("This table contains ".$this->title);
        $table->table_title($this->title);

        /* Body */

        $table->table_body_begin("top");

        print "\tpor <b>".$BBDD->f("user")."</b> - <b>".lib_date_long($BBDD->f("creation"))."<b><br>&nbsp;\n";

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