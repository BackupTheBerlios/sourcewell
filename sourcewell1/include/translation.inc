<?php
 class translation {
     var $tolang;

     function translation($lang = "English") {
          $this->$tolang = $lang;
     }
   
     function translate($phrase) {
      switch ($this->$tolang) {
      case "English":
	    require("./include/English-lang.inc");
        break;
      case "German":
	    require("./include/German-lang.inc");
        break;
      case "Spanish":
	    require("./include/Spanish-lang.inc");
        break;
      case "French":
	    require("./include/French-lang.inc");
        break;
      case "Italian":
            require("./include/Italian-lang.inc");
        break;
      default:
	    require("./include/English-lang.inc");
        break;
      }
	  return($tmp);
     }
 }
?>
