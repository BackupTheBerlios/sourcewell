<?php

/* vim: set expandtab tabstop=4 shiftwidth=4: */
// +----------------------------------------------------------------------+
// |        SourceWell 2 - The GPL Software Announcement System           |
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
// $Id: html.inc,v 1.1 2002/03/08 17:10:58 grex Exp $

/**
 * HTML library for PHP (and PHPLib)
 *
 * This library allows to obtain clean PHP code without much HTML
 * It has been thought to work with PHPLib whithout problem
 * 
 * The only two functions that have PHPLib characteristics are:
 *      html_link
 *      html_form_action
 *
 * For any function we will have two types
 *	One that returns a string (html_*)
 *	another one that prints a string (htmlp_*)
 */

function html_link($text, $target = 'PHP_SELF', $query = '', $cssClass = '')
{
    global $sess;

    if ($target == 'PHP_SELF') {
        if (is_array($query) && !isset($query) || empty($query)) {
            $output = '<a href="'.$sess->self_url().'" class="'.$cssClass.'">'.$text.'</a>';
        } else {
            $output = '<a href="'.$sess->self_url().$sess->add_query($query).'" class="'.$cssClass.'">'.$text.'</a>';
        }
    } else {
        if (is_array($query) && !isset($query) || empty($query)) {
            $output = '<a href="'.$sess->url($target).'" class="'.$cssClass.'">'.$text.'</a>';
        } else {
            $output = '<a href="'.$sess->url($target).$sess->add_query($query).'" class="'.$cssClass.'">'.$text.'</a>';
        }
    }
    return($output);
}

function htmlp_link($target, $query = '', $text, $cssClass = '')
{
    print html_link($target, $query, $text, $cssClass);
}

function html_anchor($name)
{
    $output = '<a name="'.$name.'"></a>'."\n";
    return($output);
}

function htmlp_anchor($name)
{
    print html_anchor($name);
}

function html_image($file, $width= '', $height= '', $description= '', $border ='0')
{
    if (!isset($width) || empty($width)) {
	if (!isset($height) || empty($height)) {
	    $output = '<img src="'.$file.'" borderr="'.$border.'" alt="'.$description.'">';
	} else {
	    $output = '<img src="'.$file.'" borderr="'.$border.'" height="'.$height.'" alt="'.$description.'">';
        }
    } else {
        if (!isset($height) || empty($height)) {
	    $output = '<img src="'.$file.'" borderr="'.$border.'" width="'.$width.'" alt="'.$description.'">';
        } else {
	    $output = '<img src="'.$file.'" borderr="'.$border.'" width="'.$width.'" height="'.$height.'" alt="'.$description.'">';
	}
    }
    return($output);
}

function htmlp_image($file, $width = '', $height = '', $description = '', $border = '')
{
    print html_image($file, $width, $height, $description, $border);
}

function html_form_action($target = 'PHP_SELF', $query = '')
{
    global $sess;

    /* 4 different cases
     * a) Target PHP_SELF and a given query
     * b) Target PHP_SELF, query not given
     * c) Other target, given query
     * d) Other target, query not given
     */

    if ($target == 'PHP_SELF') {
        if (is_array($query)) {
           $output = "\n".'<form action="'.$sess->self_url().$sess->add_query($query).'" method="post">';
        } else {
           $output = "\n".'<form action="'.$sess->self_url().'" method="post">';
        }
    } else {
        if (is_array($query)) {
           $output = "\n".'<form action="'.$sess->url($target).$sess->add_query($query).'" method="post">';
        } else {
           $output = "\n".'<form action="'.$sess->url($target).'" method="post">';
        }
    }         
    return($output);
}

function htmlp_form_action($file = 'PHP_SELF', $query = '')
{
    print html_form_action($file, $query);
}
	
function html_form_hidden($name, $value)
{
    $output = "\n".'   <input type="hidden" name="'.$name.'" value="'.$value.'">';
    return($output);
}

function htmlp_form_hidden($name, $value)
{
    print html_form_hidden($name, $value);
}

function html_form_select($name, $multiple = 0, $size = 0)
{
    $output = "\n".'   <select name="'.$name.'" size="'.$size.'"';
    if ($multiple) {
        $output .= ' multiple';
    }
    $output .= ">\n";
    return($output);
}

function htmlp_form_select($name, $multiple = 0, $size = 0)
{
    print html_form_desplegable($name, $multiple, $tamanio);
}
	
function html_form_select_option($value, $selected, $text)
{
    $output = "\n".'      <option ';
    if ($selected) {
        $output .= 'selected ';
    }
    $output .= 'value="'.$value.'">'.$text."\n";
    return($output);
}

function htmlp_form_select_option($value, $selected, $text)
{
    print html_form_select_opcion($value, $selected, $text);
}

function html_form_select_end()
{
    $output = "\n   </select>\n";
    return($output);
}

function htmlp_form_select_end()
{
    print html_form_desplegable_end();
}

function html_form_textField($name, $value, $size = 24, $maxlength = 128)
{
    $output = "\n".'   <input type="text" name="'.$name.'" size="'.$size.'" maxlength="'.$maxlength.'" value="'.$value.'">';
    return($output);
}

function htmlp_form_textField($name, $value, $size= 24, $maxlength = 128)
{
    print html_form_campo_text($name, $value, $maxlength, $maxlength);
}

function html_form_PassWordField($name, $size = 16, $maxlength = 32, $value='')
{
    $output = "\n".'   <input type="password" name="'.$name.'" size="'.$size.'" maxlength="'.$maxlength.'" value="'.$value.'">';
    return($output);
}

function htmlp_form_PassWordField($name, $size = 16, $maxlength = 32, $value='')
{
    print html_form_campo_PassWordField($name, $size, $maxlength, $value);
}

function html_form_submit($value, $name='')
{
    if ($name) {
        $output = "\n".'   <input type="submit" value="'.$value.'"  name="'.$name.'">';
    } else {
        $output = "\n".'   <input type="submit" value="'.$value.'">';        
    }
    return($output);
}

function htmlp_form_submit($value, $name ='')
{
    print html_form_submit($value, $name);
}

function html_form_image($file, $description)
{
    $output = "\n".'   <input type="image" src="'.$file.'" alt="'.$description.'">';
    return($output);
}

function htmlp_form_image($file, $description)
{
    print html_form_image($file, $description);
}

function html_form_reset($value = 'Reset')
{
    $output = "\n".'   <input type="reset" value="'.$value.'">';
    return($output);
}

function htmlp_form_reset($value = 'Reset')
{
    print html_form_reset($value);
}

function html_form_checkBox($name, $value, $selected)
{
    $output = "\n".'   <input type="checkbox" name="'.$name.'" value="'.$value.'"';
    if ($selected) {
        $output .= ' checked ';
    }
    $output .= '>';
    return($output);
}

function htmlp_form_checkBox($name, $value, $selected)
{
    print html_form_checkBox($name, $value, $selected);
}

function html_form_radioButton($name, $value, $selected)
{
    $output = "\n".'   <input type="radio" name="'.$name.'" value="'.$value.'"';
    if ($selected) {
        $output .= ' checked ';
    }
    $output .= '>';
    return($output);
}

function htmlp_form_radioButton($name, $value, $selected)
{
    print html_form_circular($name, $value, $selected);
}

function html_form_textArea($name, $value, $columns = 40, $rows =7)
{
    $output = "\n".'   <textarea name="'.$name.'" cols="'.$columns.'" rows="'.$rows.'" wrap="yes">'.$value.'</textarea>';
    return($output);
}

function htmlp_form_textArea($name, $value, $columns = 40, $rows =7)
{
    print html_form_areatext($name, $value, $columns, $rows);
}

function html_form_end()
{
    $output = "\n</form>";
    return($output);
}

function htmlp_form_end()
{
    print html_form_end();
}

function html_form_file($name)
{
    $output = "\n".'   <input type="file" name="'.$name.'">';
    return($output);
}

function htmlp_form_file($name)
{
    print html_form_file($name);
}

?>