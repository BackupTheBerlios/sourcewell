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
// $Id: Show.inc,v 1.1 2002/03/08 17:10:59 grex Exp $

/*
 * The show class should be an abstract class
 * from which others should inherit
 * but actually it has been converted in the class that generates
 * the database interactions when showing contents
 *
 * Hence, the Show class will take the data from the database
 * and its children will be the ones who show it
 */

/**
 * Syntax:
 *       SELECT [DISTINCT [ON attrN]] expr1 [AS attr1], ...exprN
 *       [INTO [TABLE] class_name]
 *       [FROM from_list]
 *       [WHERE qual]
 *       [GROUP BY group_list]
 *       [HAVING having_clause]
 *       [ORDER BY attr1 [ASC|DESC] [USING op1], ...attrN ]
 *       [UNION [ALL] SELECT ...];     
 *
 * FIXME: pending in the implementation
 * DISTINCT, AS, GROUP BY, HAVING, UNION
 */

class Show {

    var $tables; // array with the database tables
    var $foreign_keys; // array with the foreign keys
    var $conditions;   // other conditions that the sql query has to meet
    var $order; // ordered by...
    var $limit; // limit
    var $status;  // content status
                  // 'A' = active
                  // 'P' = pending
                  // 'D' = Deleted
                  // 'M' = Modified
                  // '' = any status

    function Show ($tables = '')
    {
      /* FIXME: is this going to work if $tables is an array? */
        $this->tables[] = $tables;
        $this->foreign_keys = '';
        $this->conditions = '';
        $this->order = '';
        $this->limit = '';
        $this->status = '';
    }

    function addTable($table)
    {
        $this->tables[] = $table;
    }

    function addTableArray($tables)
    {
        while (list(, $value) = each($tables)) {
	    $this->addTable($value);
        }
    }

    function addForeignKey ($table1, $table2, $key1, $key2='')
    {
        if (!$key2) {
	    $key2 = $key1;
        }
        $this->foreign_keys[] = $table1.".".$key1."=".$table2.".".$key2;
    }

    /**
     * Additional conditions to WHERE
     * the type specifies if its '=', '<', '>' or '!='
     */

    function addCondition($field, $value, $type = '=')
    {
        $this->conditions[] = $field.$type."'".$value."'";
    }

    function setOrder($order)
    {
        $this->order = $order;
    }

    function getOrder()
    {
        return $this->order;
    }

    function setLimit($limit)
    {
        $this->limit = $limit;
    }

    function getLimit()
    {
        return $this->limit;
    }

    function setStatus($status='A')
    {
        $this->status = $status;
    }

    function getStatus()
    {
        return $this->status;
    }

    /**
     * Abstract method
     */

    function printShow($FieldObjectArray)
    {
        die('Abstract method in the Show Class');
    }

    function _generateQuery($FieldObjectArray)
    {

        return $this->_generateSelect(&$FieldObjectArray).
               $this->_generateFrom().
  	       $this->_generateWhere().
	       $this->_generateOrder().
               $this->_generateLimit();

   }

    function _generateSelect($FieldObjectArray)
    {
        reset($FieldObjectArray);

        while (list(, $value) = each($FieldObjectArray)) {
            // Polimorfism 
            $fields_array[] = $value->getAttribute();
        }
        $fields_array[] = 'id';
        $fields_array[] = 'usuario';
        $fields_array[] = 'creacion';

        $fields = $this->_transformArrayIntoString($fields_array, ', ');

        return "SELECT ".$fields;
    }

    function _generateFrom()
    {
        $tables = $this->_transformArrayIntoString ($this->tables, ', ');

        return " FROM ".$tables;
    }

    function _generateWhere()
    {
        $flag_where = 0;

        if (is_array($this->foreign_keys)) {
            $foreign_keys = $this->_transformArrayIntoString ($this->foreign_keys, " AND ");
            $where = " WHERE ".$foreign_keys;
            $flag_where = 1;
        }

        if (is_array($this->conditions)) {
            $conditions = $this->_transformArrayIntoString ($this->conditions, " AND ");
            if ($flag_where) {
                $where .= " AND ".$conditions;
            } else {
  	        $where = " WHERE ".$conditions;
                $flag_where = 1;
            }
        }

        if ($flag_where && $this->status) {
	    $where .= " AND status='".$this->status."'";
	} elseif ($this->status) {
            $where = " WHERE status='".$this->status."'";
	}

        return $where;
    }

    function _generateOrder()
    {
        if ($this->order != '') {
  	    return " ORDER BY ".$this->order;
        }
    }

    function _generateLimit()
    {
        if ($this->limit != '') {
  	    return " LIMIT ".$this->limit;
        }
    }

    /**
     * This method just transforms an array into a string
     * separating the values by the separator
     */

    function _transformArrayIntoString ($array, $separator =',')
    {
        while (list(, $key) = each($array)) {
            $keys .= $key.$separator;
        }

        /* last separator is removed */
        $keys = substr($keys, 0, -strlen($separator));

        return $keys;
    }

    function _getTitle($FieldObjectArray)
    {
        reset($FieldObjectArray);

        while (list(, $value) = each($FieldObjectArray)) {
            // Polimorfism 
	    if ($value->getIsTitle()) {
	        return $value->getFieldFromDB();
            }
        }
    }
}

?>