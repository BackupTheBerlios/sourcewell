<?php
require("./include/config.inc");
$fsn = "12px";
$fss = "11px";
$h1 = "16px";
$h2 = "14px";
$h3 = "12px";
$h4 = "10px";
$h5 = "8px";
$h6 = "8px";
?>
BODY { background-color: #FFFFFF }

OL,UL,P,BODY,TD,TR,TH,FORM,TEXTAREA,INPUT { font-family: <?php echo $th_font_family; ?>; font-size:<?php echo $fsn; ?>; color: <?php echo $th_font_color; ?> }

H1 { font-size: <?php echo $h1; ?>; font-family: <?php echo $th_font_family; ?> }
H2 { font-size: <?php echo $h2; ?>; font-family: <?php echo $th_font_family; ?> }
H3 { font-size: <?php echo $h3; ?>; font-family: <?php echo $th_font_family; ?> }
H4 { font-size: <?php echo $h4; ?>; font-family: <?php echo $th_font_family; ?> }
H5 { font-size: <?php echo $h5; ?>; font-family: <?php echo $th_font_family; ?> }
H6 { font-size: <?php echo $h6; ?>; font-family: <?php echo $th_font_family; ?> }

PRE,TT { font-family: <?php echo $th_tt_font_family; ?> }

.maintitlebar { color: <?php echo $th_navstrip_font_color; ?> }
A.maintitlebar { color: <?php echo $th_navstrip_font_color; ?> }
A.maintitlebar:visited { color: <?php echo $th_navstrip_font_color; ?> }

.menus { color: <?php echo $th_nav_font_color; ?>; text-decoration: none }
.menus:visited { color: <?php echo $th_font_color; ?>; text-decoration: none }
.menus:hover { text-decoration:underline; }

A:link { text-decoration:none }
A:visited { text-decoration:none }
A:active { text-decoration:none }
A:hover { text-decoration:underline; }

.title { font-family: <?php echo $th_font_family; ?>; font-size: <?php echo $h2; ?>; }

.small { font-family: <?php echo $th_font_family; ?>; font-size: <?php echo $fss; ?>; }

A.small:link { text-decoration:none; font-size: <?php echo $fss; ?> }
A.small:visited { text-decoration:none; font-size: <?php echo $fss; ?> }
A.small:active { text-decoration:none; font-size: <?php echo $fss; ?> }
A.small:hover { text-decoration:underline; font-size: <?php echo $fss; ?> }

.titlebar { text-decoration:none; color: <?php echo $th_navstrip_font_color; ?>; font-family: <?php echo $th_font_family; ?>; font-size: <?php echo $fsn; ?>; font-weight: bold }
