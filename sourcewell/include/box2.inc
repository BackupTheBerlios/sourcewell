<?php

######################################################################
# Box2: The HTML Table class for PHP (Reimplementation)
# ================================================
#
# Copyright (c) 2001 by
#                Gregorio Robles (grex@scouts-es.org) and
#                Lutz Henckel (lutz.henckel@fokus.gmd.de)
#
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This file allows the administrator to insert, rename and delete categories 
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################  

class box {

	var $box_width;
	var $box_frame_color;
	var $box_frame_width;
	var $box_title_bgcolor;
	var $box_title_font_color;
	var $box_title_align;
	var $box_body_bgcolor;
	var $box_body_font_color;
	var $box_body_align;

	function box($box_type = "general", $box_width = "96%") {

		$this->box_width = $box_width;

		switch($box_type) {

			case "general":
				include("config2.inc");
				$this->box_frame_color = $config_box_general_frame_color;
				$this->box_frame_width = $config_box_general_frame_width;
				$this->box_title_bgcolor = $config_box_general_title_color_fondo;
				$this->box_title_font_color = $config_box_general_title_font_color;
				$this->box_title_align = $config_box_general_title_align;
				$this->box_body_bgcolor = $config_box_general_body_color_fondo;
				$this->box_body_font_color = $config_box_general_body_font_color;
				$this->box_body_align = $config_box_general_body_align;
				break;

			case "error":
				include("config2.inc");
				$this->box_frame_color = $config_box_error_frame_color;
				$this->box_frame_width = $config_box_error_frame_width;
				$this->box_title_bgcolor = $config_box_error_title_color_fondo;
				$this->box_title_font_color = $config_box_error_title_font_color;
				$this->box_title_align = $config_box_error_title_align;
				$this->box_body_bgcolor = $config_box_error_body_color_fondo;
				$this->box_body_font_color = $config_box_error_body_font_color;
				$this->box_body_align = $config_box_error_body_align;
				break;
		}
	}
   
	function box_begin() {
		echo "\n<!-- box begin -->\n";
    	echo "<table border=0 cellspacing=0 cellpadding=0 bgcolor=\"$this->box_frame_color\" width=\"$this->box_width\" align=center>\n";
		echo "<tr><td>\n";
		echo "<table border=0 cellspacing=\"$this->box_frame_width\" cellpadding=3 align=\"center\" width=\"100%\">\n";
	}

/*
// These function does the same but without printing tables with borders

	function box_begin() {
		echo "\n<!-- box begin -->\n";
    	echo "<table border=0 cellspacing=0 cellpadding=0 bgcolor=\"$this->box_frame_color\" width=\"$this->box_width\" align=center>\n";
//		echo "<tr><td>\n";
		echo "<tr bgcolor=\"white\"><td>\n";
		echo "<table border=0 cellspacing=\"$this->box_frame_width\" cellpadding=3 align=\"center\" width=\"100%\">\n";
	}
*/
	function box_end() {
		echo "</table>\n";
		echo "</td></tr></table><br>\n";
		echo "<!-- box end -->\n";
	}

	function box_title_begin() {
		echo "<!-- box title begin -->\n";
		echo "<tr bgcolor=\"$this->box_title_bgcolor\"><td align=\"$this->box_title_align\">\n";
	}

	function box_title_end() {
		echo "</td></tr>\n";
		echo "<!-- box title end -->\n";
	}

	function box_title($title) {
		$this->box_title_begin();
		echo "<font color=\"$this->box_title_font_color\"><b>$title</b></font>\n";
		$this->box_title_end();
	}

	function box_body_begin() {
		echo "<!-- box body begin -->\n";
		echo "<tr bgcolor=\"$this->box_body_bgcolor\"><td align=\"$this->box_body_align\"><font color=\"$this->box_body_font_color\">\n";
	}

	function box_body_end() {
		echo "</font></td></tr>\n";
		echo "<!-- box body end -->\n";
	}

	function box_body($text) {
		$this->box_body_begin();
		echo "<font color=\"$this->box_body_font_color\">$text</font>\n";
		$this->box_body_end();
	}

	function box_full($title, $text) {
		$this->box_begin();
		$this->box_title($title);
		$this->box_body($text);
		$this->box_end();
	}

	function box_strip($title) {
		$this->box_begin();
		$this->box_title($title);
		$this->box_end();
	}

	function box_columns_begin($number_of_columns) {
		echo "<!-- table with ".$number_of_columns." columns -->\n";
		echo "<table border=\"0\" cellspacing=\"0\" cellpadding=\"3\" align=\"center\" width=\"100%\" valign=\"top\">\n";
		echo "<tr colspan=\"".$number_of_columns."\">\n";
	}

	function box_column_start($align,$width,$bg_color="#FFFFFF") {
		if (!isset($bg_color) || empty($bg_color)) $bg_color="#FFFFFF";
		echo "<!-- New Column starts -->\n";
		echo "<td align=\"".$align."\" width=\"".$width."\" bgcolor=\"".$bg_color."\">";
	}

	function box_column_finish() {
		echo "</td>\n";
		echo "<!-- Column finishes -->\n";
	}

	function box_columns_end() {
		echo "</tr>\n";
		echo "</table>\n";
		echo "<!-- end table with columns -->\n";
	}		

	function box_column($align,$width,$bgcolor,$text) {
		$this->box_column_start($align,$width,$bgcolor);
		echo $text;
		$this->box_column_finish();
	}

	function box_next_row_of_columns() {
		echo "</tr>\n";
		echo "<!-- next row with several columns -->\n";
		echo "<tr>\n";
	}

	function box_colspan ($number_of_columns,$align,$bgcolor,$text="") {
		echo "<!-- New Column spanned over $number_of_columns columns starts -->\n";
		echo "<td colspan=\"".$number_of_columns."\" align=\"".$align."\" bgcolor=\"".$bgcolor."\">";
		echo $text;
		echo "</td>\n";
		echo "<!-- Column spanned over $number_of_columns columns finished -->\n";
	}

}
?>