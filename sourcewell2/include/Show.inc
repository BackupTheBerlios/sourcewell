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
// $Id: Show.inc,v 1.3 2002/03/10 01:30:20 grex Exp $

/*
 * Show class
 * This should be an abstract class from which others should inherit
 * but actually it has been converted in the class that generates
 * the database interactions when showing contents
 *
 * Hence, the Show class will take the data from the database
 * and its children will be the ones who show it
 *
 * @author Gregorio Robles <grex@scouts-es.org>
 * @package Show
 * @access public
 */

/*
 * Inernal information:
 * SQL Syntax:
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

    /**
     * Array with the database tables that have contents that will be shown
     * @var  array
     */
    var $tables;
    /**
     * Array with the foreign keys (and that will appear in the SQL WHERE clause)
     * @var  array
     */
    var $foreign_keys;
    /**
     * Array with other conditions that will appear in the SQL WHERE clause
     * @var  array
     */
    var $conditions;
    /**
     * ORDERED BY...
     * @var  string
     */
    var $order;
    /**
     * LIMIT
     * @var  string
     */
    var $limit;
    /**
     * Status of the content
     *      'A' = active
     *      'P' = pending
     *      'D' = Deleted
     *      'M' = Modified
     *      '' = any status
     * @var  char
     */
    var $status;

    /**
     * Constructor
     *
     * @param   array   $tables    array with the database tables that contain the content
     * @access  public
     */

    function Show ($tables = '')
    {
        $this->tables[] = $tables;
        $this->foreign_keys = '';
        $this->conditions = '';
        $this->order = '';
        $this->limit = '';
        $this->status = '';
    }

    /**
     * Add a database table
     * 
     * @param    string     $table      Database table to add
     * @access public
     */

    function addTable($table)
    {
        $this->tables[] = $table;
    }

    /**
     * Add an array with database tables
     * 
     * @param    array     $tables      Array of database tables to add
     * @access public
     */

    function addTableArray($tables)
    {
        while (list(, $value) = each($tables)) {
	    $this->addTable($value);
        }
    }

    /**
     * Add Foreign Key
     * 
     * @param    string     $table1      Database table for the first key
     * @param    string     $table2      Database table for the second key
     * @param    string     $key1        key name
     * @param    string     $key2        Required if the key has a different name in table2
     * @access public
     */

    function addForeignKey ($table1, $table2, $key1, $key2='')
    {
        if (!$key2) {
	    $key2 = $key1;
        }
        $this->foreign_keys[] = $table1.".".$key1."=".$table2.".".$key2;
    }

    /**
     * Additional conditions to WHERE
     * 
     * @param    string     $field       Database field
     * @param    string     $value       Value that has to be satisfied
     * @param    string     $type        sort of comparison ( '=', '<', '>' or '!=')
     * @access public
     */

    function addCondition($field, $value, $type = '=')
    {
        $this->conditions[] = $field.$type."'".$value."'";
    }

    /**
     * Set the ORDER BY clause in the SQL query
     * 
     * @param    string     $order       ordered by it
     * @access public
     */

    function setOrder($order)
    {
        $this->order = $order;
    }

    /**
     * Get the ORDER BY clause in the SQL query
     * 
     * @return    string     $order       ordered by it
     * @access public
     */

    function getOrder()
    {
        return $this->order;
    }

    /**
     * Set the LIMIT clause in the SQL query
     * 
     * @param    string     $limit       Limits
     * @access public
     */

    function setLimit($limit)
    {
        $this->limit = $limit;
    }

    /**
     * Get the LIMIT clause in the SQL query
     * 
     * @return    string     $limit       Limits
     * @access public
     */

    function getLimit()
    {
        return $this->limit;
    }

    /**
     * Set the status of the contents
     * 
     * @param    char      $status       status of the content
     * @access public
     * @see status
     */

    function setStatus($status='A')
    {
        $this->status = $status;
    }

    /**
     * Set the specified status
     * 
     * @param    char      $status       status of the content
     * @access public
     * @see status
     */

    function getStatus()
    {
        return $this->status;
    }

    /**
     * Abstract method
     *
     * @param    array      $FieldObjectArray    array of Field (and children) objects
     * @access private
     * @see Field
     */

    function printShow($FieldObjectArray)
    {
        die('Abstract method in the Show Class');
    }

    /**
     * Generates the SQL query
     * Calls all subsequent _generate* functions in this class
     *
     * @param    array      $FieldObjectArray    array of Field (and children) objects
     * @access private
     */

    function _generateQuery($FieldObjectArray)
    {

        return $this->_generateSelect(&$FieldObjectArray).
               $this->_generateFrom().
  	       $this->_generateWhere().
	       $this->_generateOrder().
               $this->_generateLimit();

   }

    /**
     * Generates the SQL query part related to SELECT
     *
     * @param    array      $FieldObjectArray    array of Field (and children) objects
     * @access private
     * see _generateQuery($FieldObjectArray)
     */

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

    /**
     * Generates the SQL query part related to FROM
     *
     * @access private
     * see _generateQuery($FieldObjectArray)
     */

    function _generateFrom()
    {
        $tables = $this->_transformArrayIntoString ($this->tables, ', ');

        return " FROM ".$tables;
    }

    /**
     * Generates the SQL query part related to WHERE
     *
     * @access private
     * see _generateQuery($FieldObjectArray)
     */

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

    /**
     * Generates the SQL query part related to WHERE
     *
     * @access private
     * see _generateQuery($FieldObjectArray)
     */

    function _generateOrder()
    {
        if ($this->order != '') {
  	    return " ORDER BY ".$this->order;
        }
    }

    /**
     * Generates the SQL query part related to WHERE
     *
     * @access private
     * see _generateQuery($FieldObjectArray)
     */

    function _generateLimit()
    {
        if ($this->limit != '') {
  	    return " LIMIT ".$this->limit;
        }
    }

    /**
     * This method just transforms an array into a string
     * separating the values by the separator
     *
     * @param   array     $array      Input Array
     * @param   string    $separator  Separating string that is going to be put between
     *                                array values
     * @return  string                String with the array values separated by $separator
     * @access private
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

    /**
     * Runs through all the fields in the array of objects
     * and looks if any is specified as title
     *
     * @param    array      $FieldObjectArray    array of Field (and children) objects
     * @retunr   string                          Content of the title
     * @access private
     * see Field
     */

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