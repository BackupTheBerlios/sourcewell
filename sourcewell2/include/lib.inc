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
// | Authors: Gregorio Robles <grex@scouts-es.org>                        |
// +----------------------------------------------------------------------+
//
// $Id: lib.inc,v 1.3 2002/04/21 22:06:46 grex Exp $

/**
 * Miscellaneous Library
 *
 * FIXME and TODO: There's a lot of work to be done here
 *       --> add functions
 *       --> add documentation
 *       --> refactor functions
 */

/**
 * Returns time in timestamp format 
 *
 * @param   int       $time          TODO
 * @return  int                      Timestamp
 *
 * @access public
 */
function mktimestamp($time)
{
    $timestamp = mktime(substr($time,8,2),substr($time,10,2),
                        substr($time,12,2),substr($time,4,2),
                        substr($time,6,2),substr($time,0,4));
    return $timestamp;
}

#
# returns something like this: monday, 5th November 2001, 19:45:00 CET
# second (optional) parameter is to know if $time is already in timestamp format
#

function lib_date_long($time, $timestamp = 0)
{
    if (!$timestamp) { 
        $time = mktimestamp($time);
    }
    return strftime("%A, %e de %B de %Y, %H:%M:%S %Z", $time);
}

/*
 * returns something like: 16:34 09.11.01
 */

function lib_date_medium($time, $timestamp = 0)
{
    if (!$timestamp) { 
        $time = mktimestamp($time);
    }
    return strftime("%H:%M %d.%m.%y", $time);
}


function lib_date_short($time, $timestamp = 0)
{
    if (!$timestamp) { 
        $time = mktimestamp($time);
    }
    return strftime("%e. %b", $time);
}

## show_more($iter,$maxiter,$url,$urlquery)
##
## shows 10 apps of the current iteraction $iter
## until it reaches the maximum number of iteractions $maxiter
## $url is the name of the page (*.php3)
## $urlquery contains an array with the paramaters for the new page
##            (everything after the ?)

/* DEPRECATED FUNCTION : Funcion en desuso */
/* Should be done through the use of the Summary or Stats calss */
/* I strongly believe this code is rubbish! */

function lib_mostrar_mas($iter,$maxiter,$url,$urlquery) {
  global $sess;

  $iter /=10;
  echo '<table border=0 width=600><tr>';
  echo '<td>&nbsp;</td>\n';
  echo '<td align=right>';

  $maxiter= Floor($maxiter);

  if ($iter > 3) {
    echo "<a href=\"".$sess->url($url).$sess->add_query($urlquery).$sess->add_query(array("iter" => 0))."\">&lt;&lt;</a>\n";
  }

  $number = $iter - 3;
  if ($number < 0) $number = 0;
  if ($iter > 2) {
    echo "<a href=\"".$sess->url($url).$sess->add_query($urlquery).$sess->add_query(array("iter" => $number))."\">&lt;</a>\n";
  }

  switch ($iter) {
    case 0: $bias=0; break;
    case 1: $bias=1; break;
    case ($maxiter-1): if ($iter>3) {$bias=3;} else {$bias=2;} break;
    case ($maxiter): if ($iter>4) {$bias=4;} else {$bias=2;} break;
    default: $bias=2; break;
  }

  for($i=$iter-$bias;$i<$maxiter+1 && $i<($iter+5-$bias);$i++) {
    $number1 = $i*10 +1;
    $number2 = $number1 + 9;
    $number = strval($number1)."-".strval($number2);
    if ($i != $iter) {
      echo "<a href=\"".$sess->url($url).$sess->add_query($urlquery).$sess->add_query(array("iter" => $i))."\">&nbsp;$number</a>\n";
    }
    else echo "<B>&nbsp;$number</B>\n"; 
   }

  $number = $iter + 5 - $bias;
  if ($number > $maxiter+$bias) $number =$maxiter+$bias;
  if ($iter < $maxiter-4+$bias) {
    echo "<a href=\"".$sess->url($url).$sess->add_query($urlquery).$sess->add_query(array("iter" => $number))."\"> &gt;</a>\n";
  }

  $number = $iter + 10 - $bias;
  if ($number > $maxiter) $number = $maxiter;
  if ($iter < $maxiter-5 +$bias) {
    echo "<a href=\"".$sess->url($url).$sess->add_query($urlquery).$sess->add_query(array("iter" => $number))."\"> &gt;&gt;</a>\n";
  }

   echo "</td>\n";
   echo "</tr></table><br>";
}

function _($string)
{
    return $string;
}

/**
 * Our 'die' function
 * Should be called when something anomalous happens
 * It mails the sys admins with the error message
 *
 * @param   string    $error_message    Error message
 * @global  object    $t                Translation object
 * @access public
 */
function lib_die($error_message)
{
    global $t;
    /* WISH: to do not have to include config.inc another time */
    require('config.inc');
    $be = new box('80%',$th_box_frame_color,$th_box_frame_width,
                  $th_box_title_bgcolor,$th_box_title_font_color,
                  $th_box_title_align,$th_box_body_bgcolor,
                  $th_box_error_font_color,$th_box_body_align);

    $be->box_full($t->translate('An error has ocurred'),
		  $error_message
		  .'<p>'
		  .$t->translate('This error is being mailed to the system administrators.'));

    /* Mails the sys admins */
    include('monitorlib.inc');
    mailuser('admin', 'An error has ocurred', $error_message);
}
?>
