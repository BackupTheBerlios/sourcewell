<?php

######################################################################
# The HTML Library por PHP3 and PHPLib
# ===================================================================
#
# Copyright (c) 2001 by
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# The PHP3 and PHPLib HTML library
# (you will find some examples at the end of this document)
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

// falta mirar si es local o global !!!
// funciona si no tiene addquery?

function html_link($address, $query, $text) {
	global $sess;

	if (!isset($query) || empty($query)) $output = "<a href=\"".$sess->url($address)."\">".$text."</a>";
	else $output = "<a href=\"".$sess->url($address).$sess->add_query($query)."\">".$text."</a>";

	return($output);
}

function html_redirect($appid,$type,$url,$text) {

  $return = "<a href=\"redirect.php3?id=".$appid."&type=".$type."&url=".$url."\" target=_blank>".$text."</a>";

  return($return);
}

function html_anchor($name) {

	$output = "<a name=\"".$name."\"></a>\n";

	return($output);
}


function html_image($file, $border, $width, $height, $alternate) {

	$output = "<img src=\"images/".$file."\" border=\"".$border."\" width=\"".$width."\" height=\"".$height."\" alt=\"".$alternate."\">";

	return($output);
}

function html_form_action($file, $query) {
	global $sess;

        if ($file == "PHP_SELF") $output = "<form action=\"".$sess->self_url().$sess->add_query($query)."\" method=\"POST\">";

	else $output = "<form action=\"".$sess->url($file).$sess->add_query($query)."\" method=\"POST\">";

	return($output);
}
	
function html_form_hidden($name, $value) {

	$output = "<input type=\"hidden\" name=\"".$name."\" value=\"".$value."\">";

	return($output);
}

function html_select($name) {

	$output = "<select name=\"".$name."\">\n";

	return($output);
}

function html_select_option($value,$selected,$text) {

	$output = "<option ";
	if ($selected) $output .= "selected ";
	$output .= "value=\"".$value."\">".$text."\n";

	return($output);
}

function html_select_end() {

	$output = "</select>\n";

	return($output);
}

function html_input_text($name, $size, $maxlength, $value) {

	$output = "<input type=\"text\" name=\"".$name."\" size=\"".$size."\" maxlength=\"".$maxlength."\" value=\"".$value."\">";

	return($output);
}

function html_input_password($name, $size, $maxlength, $value) {

	$output = "<input type=\"password\" name=\"".$name."\" size=\"".$size."\" maxlength=\"".$maxlength."\" value=\"".$value."\">";

	return($output);
}

function html_form_submit($value,$name) {

	$output = "<input type=\"submit\" value=\"".$value."\" name=\"".$name."\">";

	return($output);
}

function html_checkbox($name,$value,$checked) {

	$output = "<input type=\"checkbox\" name=\"".$name."\" value=\"".$value."\"";
	if ($checked) $output .= " checked ";
	$output .= ">";

	return($output);

}

function html_radio($name,$value,$checked) {

	$output = "<input type=\"radio\" name=\"".$name."\" value=\"".$value."\"";
	if ($checked) $output .= " checked ";
	$output .= ">";

	return($output);
}

function html_textarea($name,$columns,$rows,$wrap,$maxlength,$value) {

	$output = "<textarea cols=\"".$columns."\" rows=\"".$rows."\" name=\"".$name."\" wrap=\"".$wrap."\" maxlength=\"".$maxlength."\">".$value."</textarea>";

	return($output);
}

function html_form_end() {

	$output = "</form>";

	return($output);
}

##########################################################
#
# Examples for html.inc - The PHP and PHPlib HTML library
#
# by Gregorio Robles <grex@scouts-es.org>
#
######
#
# function html_link($address, $query, $text)
# 
# <a href=\"".$sess->url("updapp.php3").$sess->add_query(array("id" => $db->f("proid")))."\">Some string</a>
#
# html_link("updapp.php3",array("id"=> $db->f("proid")), "some string");
#
######
#
# function html_image($file, $border, $width, $height, $alternate)
#
# <img src=\"images/recycled.png\" border=\"0\" width=\"\" heigth=\"\" alt=\""._("Update")."\">
#
# html_mage("recycled.png",0,"","",_("Update"));
#
#####
#
# function html_form_action($file, $type)
#
# <form action=\"".$sess->url("update.php3")."\" method=\"POST\">
#
# html_form_action("update.php3","POST")
#
#####
#
# function html_form_hidden($name, $value)
#
# <input type=\"hidden\" name=\"type\" value\"".$db->f("type")."\">
#
# html_form_hidden("type",$db->f("type"));
#
####
#
# function html_select($name)
#
# <select name=\"seccat\">
#
# html_select("seccat");
#
####
#
# function html_select_option($value,$selected,$text)
#
# <option selected value=\"\">some string
#
# html_select_option("",1,"some string");
#
####
# 
# function html_select_end()
#
# </select>
#
# html_select_end();
#
####
#
# function html_input_text($name, $size, $maxlength, $value)
#
# <input type=\"text\" name=\"homepage\" size=\"40\" maxlength=\"255\" value=\"".$db->f("homepage")."\">
# 
# html_input_text("homepage",40,255,$db->f("homepage"));
#
####
#
# function html_form_submit($value,$name)
#
# <input type=\"submit\" value=\""._("Update")."\" name=\"\">
#
# html_input_submit(_("Update"),"");
#
##########################################################


function htmlp_link($address, $query, $text) {
	print html_link($address, $query, $text);
}


function htmlp_redirect($appid,$type,$url,$text) {
	print html_redirect($appid,$type,$url,$text);
}

function htmlp_anchor($name) {
	print html_anchor($name);
}

function htmlp_image($file, $border, $width, $height, $alternate) {
	print html_image($file, $border, $width, $height, $alternate);
}

function htmlp_form_action($file, $query) {
	print html_form_action($file, $query);
}
	
function htmlp_form_hidden($name, $value) {
	print html_form_hidden($name, $value);
}

function htmlp_select($name) {
	print html_select($name);
}

function htmlp_select_option($value,$selected,$text) {
	print html_select_option($value,$selected,$text);
}

function htmlp_select_end() {
	print html_select_end();
}

function htmlp_input_text($name, $size, $maxlength, $value) {
	print htmlp_input_text($name, $size, $maxlength, $value);
}


function htmlp_textarea($name,$columns,$rows,$wrap,$maxlength,$value) {
	print html_textarea($name,$columns,$rows,$wrap,$maxlength,$value);
}

function htmlp_form_submit($value,$name) {
	print html_form_submit($value,$name);
}

function htmlp_checkbox($name,$value,$checked) {
	print html_checkbox($name,$value,$checked);
}

function htmlp_radio($name,$value,$checked) {
	print html_radio($name,$value,$checked);
}

function htmlp_form_end() {
	print html_form_end();
}

?>