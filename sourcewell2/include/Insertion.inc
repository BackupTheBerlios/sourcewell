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
// |          Lutz Henckel <lutz.henckel@fokus.fhg.de>                    |
// |          Carlos Martín Ugalde <carlos@scouts-es.org>                 |
// +----------------------------------------------------------------------+
//
// $Id: Insertion.inc,v 1.1 2002/03/08 17:11:02 grex Exp $

/**
 * method insertQuery() uses PHPLib classes!
 */

/**
 * FIXME: status (A, P, ...)  pending
 */

class Insertion {

    var $table;
    var $begin;        // beginning of the SQL query
    var $attributes;   // array with the database field names
    var $values;       // array with the values to introduce into the database

    function Insertion($table)
    {
        $this->table = $table;
        $this->begin = 'INSERT INTO ';
    }

    /*
    function setValue ($value)
    {
        $this->values[] = $value;
    }
    */

    function setValues($objects)
    {
        while (list(, $value) = each($objects)) {
            $this->values[] = $value->getSQL();
        }
    }

    /*
     * Takes the form data in the following way
     * name = 'value'
     * so that they can be introduced into teh database
     */

    function getFields($objects)
    {
        while (list(, $value) = each($objects)) {
            // Polimorfism 
            $this->attributes[] = $value->getAttribute();
            $this->values[] = $value->getValue();
        }
    }

    function generateValues ()
    {
        global $auth;

        $query = "(";
        while (is_array($this->values) && list(, $attr_current) = each($this->attributes)) {
  	    $query .= $attr_current.", ";
        }
        $query .= "user, creation) VALUES (";
        while (is_array($this->values) && list(, $value_current) = each($this->values)) {
            $query .= "'".$value_current."', ";
        }
        /* PHPLib dependence */
	//        $value .= " user='".$auth->auth["uname"]."' ";
        $query .= " 'FIXME', '".date("d-m-Y H:i:s", time())."') ";

        return $query;
    }

    function generateQuery($objects)
    {
        $this->getFields(&$objects);
        $query = $this->begin.$this->table.' '.$this->generateValues().$this->generateWhere();
	$id = $this->insertQuery($query);
        return $id;
    }

    /* Insertion does not need a Where clause
     * This should be overriden in the Update class */

    function generateWhere()
    {
        return;
    }

    function insertQuery($query)
    {
        global $BBDD;

	$BBDD->query($query);
        if ($BBDD->affected_rows() == 0) {
            print "<br><b>Database insertion caused error (class Insertion)</b><br>";
        } else {
            print "\n\n<!-- Succesful database insertion:\n".$query."\n-->\n\n";
        }

	/* We get the id of the just inserted content */
        /* this should be a transaction but it isn't */
        $BBDD->query("SELECT id,creacion FROM ".$this->table." ORDER BY creacion DESC");
        $BBDD->next_record();
        return $BBDD->f("id");
    }
}

?>