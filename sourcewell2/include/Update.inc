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
// $Id: Update.inc,v 1.1 2002/03/08 17:11:02 grex Exp $


/* FIXME: status and temporary database!
 */

class Update extends Insertion {

    var $where;     // array with the WHERE values

    function Update($table)
    {
        /* Parent class constructor */
        $this->Insertion($table);
        $this->begin = 'UPDATE ';
    }

    function setWhere($name, $value)
    {
        $this->where[] = $name." ='".$value."'";
    }

    function generateValues()
    {
        global $auth;

        while (is_array($this->attributes) && list(, $attr_current) = each($this->attributes)) {
	  /* FIXME: error, error */
	  /* it takes only the first attribute and assigns it all the values */
          /* array_shift  */
          /* array_unshift */
          /* could be a solution... but we've got to keep order! */
            while (is_array($this->values) && list(, $value_current) = each($this->values)) {
                $query .= $attr_current."=".$value_current.", ";
            }
        }
        /* PHPLib dependence */
	//        $value .= " user='".$auth->auth["uname"]."' ";
        /* FIXME: by now it's ok this way */
        $query .= " user='FIXME', ";
        $query .= " modification = '".date("d-m-Y H:i:s", time())."' ";

        return $query;
    }

    function generateWhere ()
    {
        if (!is_array($this->where)) {
  	    die('No Where clause in generateWhere method in class Update');
        } else {
            while (list(, $where_value) = each($this->where)) {
                $where_values .= $where_value." AND ";
            }
            /* substr so that the last AND is remoed */
            $where_values = substr($where_values, 0, -4);
            $query = ' WHERE '.$where_values;
        }

        return $query;
    }
}

?>