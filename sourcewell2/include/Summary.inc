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
// $Id: Summary.inc,v 1.1 2002/03/08 17:11:03 grex Exp $

/**
 * Requires table.inc, html.inc and lib.inc
 * Uses PHPLib's database abstraction layer
 */

/* 
 * This class shows only certain fields from the database
 * this fields are: name, description, user and creation
 */ 

class Summary extends Show {

    var $fields;            // array with the fields that are going to be shown

    function Summary($table, $order = 'creation', $order_value ='') {

        /* Parent class constructor */ 
        $this->Show($table);

        $this->setLimit(10); 
          // Ordenado según {fecha, interés, alfabéticamente}
        $this->setOrder('creacion DESC');
	 // Especifica pormenorizadamente el orden --> conditions!
	//        $this->addCondition('','');

        $name = new TextField('Name', 'name');
        $name->setIsTitle();
	$description = new TextAreaField('Description', 'description');
	$description->setShowType('B');

	$this->fields[] = $name;
	$this->fields[] = $description;

    }

    function printShow() {
        global $db, $table;

        $query = $this->_generateQuery(&$this->fields);
        print "\n\n<!-- Database query: ".$query." -->\n";
        $db->query($query);
        while($db->next_record()) {

            $table->table_begin("Esta table contiene ".$db->f("name"));
            $table->table_title(html_link($db->f("name")),'PHP_SELF',array("id" => $db->f("id")));

            /* Body */

            $table->table_body_begin("top");

            print "\tpor <b>".$db->f("usuario")."</b> - <b>".lib_date_long($db->f("creacion"))."<b><br>&nbsp;\n";

            reset($this->fields);

            $table->table_columns_begin();

            while (list(, $value) = each($this->fields)) {
                // Polimorfism 
  	        $value->setShow();
                $value->fieldShow();
            }

            $table->table_columns_end();
	    print "<center><font size=-1>FIXME: Modificar | Poner un comentario | etc.</font></center>";
            $table->table_body_end();
            $table->table_end();
	}
    }
}

?>