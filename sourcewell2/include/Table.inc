<?php

/* vim: set expandtab tabstop=4 shiftwidth=4: */
// +----------------------------------------------------------------------+
// |        SourceWell 2 - The GPL Software Announcement System           |
// +----------------------------------------------------------------------+
// |      Copyright (c) 2001-2002 BerliOS, FOKUS Fraunhofer Institut      |
// +----------------------------------------------------------------------+
// | This program is free software. You can redistribute it and/or modify |
// | it under the terms of the GNU General Public License as published by |
// | the Free Software Foundation; either version 2 or later of the GPL.  |
// +----------------------------------------------------------------------+
// | Authors: Lutz Henckel <lutz.henckel@fokus.fhg.de>                    |
// |          Gregorio Robles <grex@scouts-es.org>                        |
// |          Carlos Martín Ugalde <carlos@scouts-es.org>                 |
// +----------------------------------------------------------------------+
//
// $Id: Table.inc,v 1.1 2002/03/08 17:10:57 grex Exp $


/**
 * Class Table: a class for HTML Tables
 *
 * This library contains an object oriented vision of the HTML tables.
 * Its use allows to abstract the PHP from the HTML
 */

class Table {

  /* The Attributes for the Table class are usually visual related */
    
    var $table_width;
    var $table_filling;
    var $table_title_bgcolor;
    var $table_title_font_color;
    var $table_title_align;
    var $table_body_bgcolor;
    var $table_body_font_color;
    var $table_body_align;

    function table($table_type ='general', $table_width='98%')
    {
        $this->table_width = $table_width;

        /* depending on the table, we have different parameters */
        /* if we were Object-oriented purists, this should be done
           with inheritance --> TODO */

        switch ($table_type) {

        case 'general':
            /* FIXME: in php4 this include should be removed */
            /* it should be include_once'd in the header file */
            include('config.inc');
            $this->table_filling = $config_table_general_filling;
            $this->table_title_bgcolor = $config_table_general_title_bgcolor;
            $this->table_title_font_color = $config_table_general_title_font_color;
            $this->table_title_align = $config_table_general_title_align;
            $this->table_body_bgcolor = $config_table_general_body_bgcolor;
            $this->table_body_font_color = $config_table_general_body_font_color;
            $this->table_body_align = $config_table_general_body_align;
            break;

        case 'error':
            /* FIXME: in php4 this include should be removed */
            /* it should be include_once'd in the header file */
            include('config.inc');
            $this->table_filling = $config_table_error_filling;
            $this->table_title_bgcolor = $config_table_error_title_bgcolor;
            $this->table_title_font_color = $config_table_error_title_font_color;
            $this->table_title_align = $config_table_error_title_align;
            $this->table_body_bgcolor = $config_table_error_body_bgcolor;
            $this->table_body_font_color = $config_table_error_body_font_color;
            $this->table_body_align = $config_table_error_body_align;
            break;
        }
        /* Internet Explorer does not work ok when we put the widht
           of the tables to 100%
           If we have a width that is greater than 98% we set it to 98% */

        if (substr($this->table_width,0,strpos($this->table_width, '%')) > 98) {
            $this->table_width = '98%';
        }        
    }
   
    function table_begin($summary = '')
    {
       echo "\n<!-- Table Begins -->\n";
       echo '<table style="border: 0; padding: '.$this->table_filling.'; width: '.$this->table_width.';" align="center">'."\n";
    }

    function table_end()
    {
        echo "</table>\n";
        echo "<!-- Table ends -->\n";
        echo "<br>\n";
    }

    function table_title_begin()
    {
        echo "   <!-- Table title begins -->\n";
        echo "   <tr style=\"background: $this->table_title_bgcolor\">\n";
        echo "      <td style=\"text-align: $this->table_title_align; color: $this->table_title_font_color\">\n";
    }

    function table_title_end()
    {
        echo "      </td>\n";
        echo "   </tr>\n";
        echo "   <!-- Table title ends -->\n";
    }

    function table_title($title)
    {
        $this->table_title_begin();
        echo "      <b>$title</b>\n";
        $this->table_title_end();
    }

    function table_body_begin($valign = 'top')
    {
        echo "   <!-- Table body begins -->\n";
        echo "   <tr style=\"background: $this->table_body_bgcolor\">\n";
        echo "      <td style=\"text-align: $this->table_body_align; color: $this->table_body_font_color\" valign=\"$valign\">\n";
    }

    function table_body_end()
    {
        echo "      </td>\n";
        echo "   </tr>\n";
        echo "   <!-- End Table body -->\n";
    }

    function table_body($text, $valign = 'top')
    {
        $this->table_body_begin($valign);
        echo "    ".$text."\n";
        $this->table_body_end();
    }

    function table_full($title, $text, $valign = 'top', $summary ='')
    {
        $this->table_begin($summary);
        $this->table_title($title);
        $this->table_body($text, $valign);
        $this->table_end();
    }


    function table_columns_begin()
    {
        echo "\n<!-- Table with columns begins -->\n";
        echo "<table style=\"border: 0; padding: $this->table_filling; width: $this->table_width; \" align=\"center\" valign=\"top\">\n";
        echo "   <tr>\n";
    }

    function table_column_start($width = '100%', $bgcolor = '', $align = 'center')
    {
        echo "\n      <!-- New column starts -->\n";
        echo "      <td align=\"$align\" width=\"$width\" bgcolor=\"$bgcolor\" valign=\"top\">\n";
    }

    function table_column_finish()
    {
        echo "      </td>\n";
        echo "      <!-- Column finishes -->\n";
    }

    function table_columns_end()
    {
        echo "   </tr>\n";
        echo "</table>\n";
        echo "<!-- End Table columns -->\n";
    }        

    function table_column($text = '&nbsp;', $width = '100%', $bgcolor = '', $align = 'center')
    {
        $this->table_column_start($width, $bgcolor, $align);
        echo "    ".$text."\n";
        $this->table_column_finish();
    }

    function table_nextRowWithColumns()
    {
        echo "   </tr>\n";
        echo "   <!-- Next row with columns -->\n";
        echo "   <tr>\n";
    }

    function table_colspan ($text = '&nbsp;', $numberOfColumns ='2', $bgcolor = '', $align = 'center')
    {
        echo "      <!-- Column that extends itself over $numberOfColumns columns columns begins -->\n";
        echo "      <td colspan=\"$numberOfColumns\" align=\"$align\" bgcolor=\"$bgcolor\">\n";
        echo "      ".$text."\n";
        echo "      </td>\n";
        echo "      <!-- End of column that extends itself over  $number_of_columns columns columns -->\n";
    }
}

?>
