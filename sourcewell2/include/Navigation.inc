<?php
/* vim: set expandtab tabstop=4 shiftwidth=4: */
// +----------------------------------------------------------------------+
// |        SourceWell 2 - The GPL Software Announcement System           |
// +----------------------------------------------------------------------+
// |      Copyright (c) 2001-2002 BerliOS, FOKUS Fraunhofer Institut      |
// +----------------------------------------------------------------------+
// | This program is free software. You can redistribute it and/or modify |
// | it under the terms of the GNU General Public License as published by |
// | the Free Software Foundation; either version 2 or later of the GPL.  |
// +----------------------------------------------------------------------+
// | Authors: Lutz Henckel <lutz.henckel@fokus.fhg.de>                    |
// +----------------------------------------------------------------------+
//
// $Id: Navigation.inc,v 1.8 2002/05/09 14:47:36 grex Exp $

/**
 * Class Navigation: a class for links in the navigation bar
 *
 * This library contains an object oriented vision of the links that
 * usually are in the navigation bar.
 * Links can be easily configured in the config.inc file
 *
 * @author Gregorio Robles <grex@scouts-es.org>
 * @package HTML
 * @access public
 * @see HTML, config
 * depends on PHPLib db and auth classes
 * TODO: language configurability -> class variable and translation function
 * TODO: documentation
 */

class Navigation {
   /**
     * 
     * @var  string
     */
    var $string;
   /**
     * 
     * @var  string
     */
    var $link;
   /**
     *
     * @var  string
     */
    var $httpGetArray;
   /**
     * 
     * @var  string
     */
    var $permisions;
   /**
     * 
     * @var  string
     */
    var $statistics;
   /**
     * 
     * @var  string
     */
    var $table;
   /**
     * 
     * @var  string
     */
    var $where;

    /**
     * Constructor
     *
     * @param   string  $string          String that will be shown
     * @param   string  $link            Page that is linked
     * @access  public
     */
    function Navigation($string, $link)
    {
        $this->string = $string;
	$this->link = $link;
	$this->httpGetArray = '';
	$this->permisions = '';
	$this->statistics = 0;
    }

    function setHttpGetArray($array) {
        $this->httpGetArray = $array; 
    }

    function setPermisions($perm) {
        $this->permisions = $perm;
    }

    function setStatistics($table, $where = '') {
        $this->statistics = 1;
        $this->table = $table;
        if ($where) {
            $this->where = " WHERE ".$where;
	} else {
  	    $where = '';
	}
    }

    function countStatistics() {
        global $db;

        $db->query("SELECT COUNT(*) FROM ".$this->table.$this->where);
        $db->next_record();
        return $db->f('COUNT(*)');
    }

    function render() {
        global $auth;

        /* Should not be ==... instead regexp */
        if ($this->permisions == $auth->auth["perm"]) {
  	    $return = '    ';
	    $return .= html_link($this->string, $this->link, $this->httpGetArray, 'menus');
            if ($this->statistics) {
  	        $return .= ' ['.$this->countStatistics().']';
	    }
	    $return .= '<br>';
            $return .= "\n";
        }
        return $return;
    }
}
?>