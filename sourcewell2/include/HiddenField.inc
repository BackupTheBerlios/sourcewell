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
// $Id: HiddenField.inc,v 1.1 2002/03/08 17:11:00 grex Exp $

/**
 * Requires table.inc and html.inc
 * Inherits from Field.inc
 */

/**
 * This class represents a hidden field in a form
 * (a text field in the database)
 * inherits from the Field Class
 */

class HiddenField extends Field {

    var $show;        // if 0, the HiddenField will not be displayed
                      // if 1 it will

    function HiddenField($description, $name, $default = '', $notNull = 0)
    {
        /* Llamamos al constructor de la clase padre */
        $this->Field($description, $name, $default, $notNull);
        $this->show = 0;
    }

    function setShow($status = 1)
    {
        $this->show = $status;
    }  

    function fieldForm()
    {
        htmlp_form_hidden($this->name, $this->default);

        if($this->show) {
  	     global $table;
             $table->table_column('<b>'.$this->description.': <b>', '33%', '', 'right');
             $table->table_column($this->default, '67%', '', 'left');
             $table->table_nextRowWithColumns();
        }
    }

    function fieldShow()
    {
        global $table;
    
        if (!$this->default && $this->notNull) {
             $table->table_column('<b>'.$this->description.': <b>', '33%', '', 'right');
             $table->table_column('<font color=red><b>Requires to be filled out</b></font>','67%', '', 'left');
             $table->table_nextRowWithColumns();
             return 0;
        } elseif($this->show) {
             $table->table_column('<b>'.$this->description.': <b>', '33%', '', 'right');
             $table->table_column($this->default, '67%', '', 'left');
             $table->table_nextRowWithColumns();
        }
        return 1;
    }
}

?>