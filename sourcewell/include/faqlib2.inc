<?php

######################################################################
# SourceWell 2
# ================================================
#
# Copyright (c) 2001 by
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
#
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

function faq_form() {
  global $sess, $bx, $t, $question, $answer, $faqid, $modification;

  $bx->box_begin();
  $bx->box_title($t->translate("Form for Frequently Asked Questions"));
  $bx->box_body_begin();
  $bx->box_columns_begin(2);

  htmlp_form_action("PHP_SELF",array());
  if ($modification != 1) htmlp_form_hidden("create",2);
  else {
	htmlp_form_hidden("change",2);
	htmlp_form_hidden("faqid",$faqid);
  }

  $bx->box_column("right","40%","","<b>".$t->translate("Question").":</b> ");
  $bx->box_column("left","60%","",html_textarea("question",40,4,"virtual",1024,$question));

  $bx->box_next_row_of_columns();

  $bx->box_column("right","40%","","<b>".$t->translate("Answer").":</b> ");
  $bx->box_column("left","60%","",html_textarea("answer",40,7,"virtual",1024,$answer));

  $bx->box_next_row_of_columns();

  $bx->box_column("right","40%","","&nbsp;");
  $bx->box_column("left","60%","",html_form_submit($t->translate("Preview"),"preview").html_form_submit($t->translate("Submit"),"Submit"));

  htmlp_form_end();

  $bx->box_columns_end();
  $bx->box_body_end();
  $bx->box_end();
}


function faq_show($faqid) {
  global $question, $answer;

  $db_local = new DB_SourceWell;

  $db_local->query("SELECT * FROM faq WHERE faqid='$faqid'");
  $db_local->next_record();

  $question = $db_local->f("question");
  $answer = $db_local->f("answer");

  faq_preview();

}

function faq_preview() {
  global $sess, $t, $bx, $question, $answer;

  $bx->box_begin();
  $bx->box_title("<B>".$t->translate("Question")."</B>: ".$question);
  $bx->box_body_begin();
  echo "<B>".$t->translate("Answer")."</B>: ".$answer."\n";
  $bx->box_body_end();
  $bx->box_end();
}


function faq_modification($faqid) {
  global $sess, $db, $t, $bx, $question, $answer, $modification;

	$db->query("SELECT * FROM faq WHERE faqid='$faqid'");
	$db->next_record();

	$question = $db->f("question");
  	$answer = $db->f("answer");
	$modification = 1;

  	faq_form();
}

function faq_insert ($question,$answer,$language) {
  global $db,$bx,$t;

  $db->query("INSERT faq SET question='$question',answer='$answer',language='$language'");

				// We show what we've inserted
  $bx->box_full($t->translate("Frequently Asked Questions Administration"),$t->translate("The following FAQ has been inserted"));
  $bx->box_full($t->translate("Question").": ".$question,"<b>".$t->translate("Answer").":</b> ".$answer);

}

function faq_modify ($faqid,$question,$answer) {
  global $db,$bx,$t;

  $db->query("UPDATE faq SET question='$question',answer='$answer' WHERE faqid='$faqid'");
  if ($db->affected_rows() < 1) {
	$be->box_full($t->translate("Error"), $t->translate("Database Error"));
  } else {
	$bx->box_full($t->translate("Frequently Asked Questions Administration"),$t->translate("The following FAQ has been modified"));
       	faq_show($faqid);
  }
}


function faq_administration($language) {
  global $t,$db,$bx;

  $db->query("SELECT * FROM faq WHERE language='$language'");

  $bx->box_begin();
  $bx->box_title($t->translate("Frequently Asked Questions Administration"));
  $bx->box_body_begin();
  $bx->box_columns_begin(2);

  htmlp_form_action("PHP_SELF",array());
  htmlp_form_hidden("create",1);
  $bx->box_column("left","80%","","<b>".$t->translate("Enter a New Frequently Asked Question")."</b> ");
  $bx->box_column("right","20%","",html_form_submit($t->translate("Insert"),"insert"));
  htmlp_form_end();

  $bx->box_columns_end();
  $bx->box_body_end();

  $i = 1;
  while($db->next_record()) {
      $i++;  
      $bx->box_title($t->translate("Question").": ".$db->f("question"));
      $bx->box_body_begin();
      $bx->box_columns_begin(2);

      htmlp_form_action("PHP_SELF",array());
      htmlp_form_hidden("change_or_delete",1);

      htmlp_form_hidden("faqid",$db->f("faqid"));
      $bx->box_column("left","80%","","<b>".$t->translate("Answer").":</b> ".$db->f("answer"));
      $bx->box_column("right","20%","",html_form_submit($t->translate("Change"),"change").html_form_submit($t->translate("Delete"),"delete"));
      htmlp_form_end();

      $bx->box_columns_end();
      $bx->box_body_end();
  }

  $bx->box_end();
}


function faq_are_you_sure_to_delete($faqid) {
  global $db, $bx, $t;

  faq_show($faqid);
  $bx->box_begin();
  $bx->box_title($t->translate("Do you really want to delete this FAQ? There is no way for undeletion."));
  $bx->box_body_begin();
  $bx->box_columns_begin(2);

  $bx->box_column("left","40%","","&nbsp;");
  $bx->box_column_start("left","60%","");
  htmlp_form_action("PHP_SELF",array());
  htmlp_form_hidden("faqid",$faqid);
  htmlp_form_hidden("delete",2);
  htmlp_form_submit($t->translate("Yes, Delete"),"");
  htmlp_form_end();
  $bx->box_column_finish();


  $bx->box_next_row_of_columns();

  $bx->box_column("left","40%","","&nbsp;");
  $bx->box_column_start("left","60%","");
  htmlp_form_action("PHP_SELF",array());
  htmlp_form_hidden("faqid",$faqid);
  htmlp_form_hidden("change",1);
  htmlp_form_submit($t->translate("No, Just Modify"),"");
  htmlp_form_end();
  $bx->box_column_finish();

  $bx->box_columns_end();
  $bx->box_body_end();
  $bx->box_end();
}

function faq_delete($faqid) {
  global $db, $be, $bx, $t;

  $db->query("DELETE FROM faq WHERE faqid='$faqid'");

  if ($db->affected_rows() == 0) {
	$be->box_full($t->translate("Error"), $t->translate("Database Error"));
  } else { 
      	$bx->box_full($t->translate("Frequently Asked Questions Administration"),$t->translate("The FAQ has been deleted"));
  }
}
?>