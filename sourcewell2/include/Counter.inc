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
// $Id: Counter.inc,v 1.2 2002/03/09 15:10:29 grex Exp $

/**
 * Uses PHPLib's database abstraction class
 */

/**
 * Class Counter
 * Counts the number of accesses to a certain content
 *
 * It needs a database backend with two tables
 *     * counter (which will have the different types of things to count)
 *     * check_counter (which will contain the IP addresses of the visitors)
 * 
 * @author Gregorio Robles <grex@scouts-es.org>
 * @access public
 * @see PHPLib
 */
 */

class Counter {

    /**
     * Identifier of the content to count
     * @var  id
     */
    var $id;
    /**
     * Type of the content to count
     * @var  string
     */
    var $type;
    /**
     * IP address of the visitor
     * @var  string
     */
    var $ipAddress;

    /**
     * Constructor
     *
     * @param   int     $id           Identifier of the content to count
     * @param   string  $type         Type of the content to count
     * @access  public
     */

    function Counter($id, $type='')
    {
        $this->id = $id;
        $this->type = $type;
        $this->ipAddress = $GLOBALS['REMOTE_ADDR'];

        $this->_counterDeleteOlder();
        if ($this->_counterCheck()) {
  	    $this->_counterAdd();
        }
    }

    /**
     * Deletes older entries than today in the check_counter table
     *
     * @access  private
     * @see PHPLib
     */

    function _counterDeleteOlder()
    {
        global $db;

        $today = date("Y-m-d");
        $db->query("DELETE FROM comprobar_contador WHERE DATE_FORMAT(creation_cnt,'%Y-%m-%d') != '$today'");
    }

    /**
     * Checks if that visitor has not visited that content already
     *
     * @access  private
     * @see PHPLib
     */

    function _counterCheck()
    {
        global $db;

        $today = date("Y-m-d");
        $db->query("SELECT * FROM comprobar_contador WHERE id='".$this->id."' AND cnt_tipo='".$this->type."' AND direccion_ip='".$this->ipAddress."'");

        if ($db->num_rows() > 0) {
	    return 0;
        } else {
	  $db->query("INSERT INTO comprobar_contador (id, cnt_tipo, direccion_ip, creation_cnt) VALUES ('".$this->id."', '".$this->type."','".$this->ipAddress."','".date("d-m-Y H:i:s", time())."')");
  	    return 1;
        }
    }

    /**
     * Adds to its specific type on more visit
     *
     * @access  private
     * @see PHPLib
     */

    function _counterAdd()
    {
        global $db;

        $db->query("SELECT * FROM contador WHERE proid='".$this->id."'");
        $db->next_record();
        $counter = $db->f($this->type) +1;
        $db->query("UPDATE contador SET ".$this->type."='$counter' WHERE id='".$this->id."'");
    }
}
?>