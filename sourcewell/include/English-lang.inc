<?php

// Ins Englischen muessen wir nicht uebersetzen!
// (es ist ja alles auf English bis jetzt!)
function translate_real($phrase) {
  switch($phrase) {

    // Languages
	 case "English": $tmp = "English"; break;
	 case "German": $tmp = "Deutsch"; break;
	 case "Spanish": $tmp = "Espa&ntilde;ol"; break;
	 case "French": $tmp = "Fran&ccedil;ais"; break;

     default: $tmp = "$phrase"; break;
  }
  return($tmp);
}
?>
