<?php
if ($sess->is_registered("la")) {
   if (isset($lang)) {
      $la = $lang;
   }
} else {
   if (isset($lang)) {
      $la = $lang;
   } else {
      $la = "English";
   }
   $sess->register("la");
}

switch($la) {
   case "English": $locale = "en_EN"; include("English-lang.inc"); break;
   case "German": $locale = "de_DE"; include("German-lang.inc"); break;
   case "Spanish": $locale = "es_ES"; include("Spanish-lang.inc"); break;
   case "French": $locale = "fr_FR"; include("French-lang.inc"); break;
   default: $locale = "en_EN"; include("English-lang.inc"); break;
}

setlocale ("LC_TIME", $locale);
?>