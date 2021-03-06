<?php
	require("config.inc");
	$ua = "$HTTP_USER_AGENT";
	$fsn = "small";
	$h1 = "large";
	$h2 = "medium";
	$h3 = "small";
	$h4 = "x-small";
	$h5 = "xx-small";
	$h6 = "xx-small";
	if (ereg("MSIE", "$ua")) {
		$fsn = "x-small";
		$h1 = "large";
		$h2 = "medium";
		$h3 = "small";
		$h4 = "x-small";
		$h5 = "xx-small";
		$h6 = "xx-small";
	}
	if (ereg("X11", "$ua")) {
		$fsn = "medium";
                $h1 = "x-large";
                $h2 = "large";
                $h3 = "medium";
                $h4 = "small";
                $h5 = "x-small";
                $h6 = "xx-small";
	}
?>
BODY { background-color: #FFFFFF }

OL,UL,P,BODY,TD,TR,TH,FORM { font-family: <?php echo $th_font_family;?>; font-size:<?php echo $fsn ?>; color: <?php echo $th_font_color;?> }

H1 { font-size: <?php echo $h1; ?>; font-family: <?php echo $th_font_family;?> }
H2 { font-size: <?php echo $h2; ?>; font-family: <?php echo $th_font_family;?> }
H3 { font-size: <?php echo $h3; ?>; font-family: <?php echo $th_font_family;?> }
H4 { font-size: <?php echo $h4; ?>; font-family: <?php echo $th_font_family;?> }
H5 { font-size: <?php echo $h5; ?>; font-family: <?php echo $th_font_family;?> }
H6 { font-size: <?php echo $h6; ?>; font-family: <?php echo $th_font_family;?> }

PRE,TT { font-family: <?php echo $th_tt_font_family;?> }

.maintitlebar { color: <?php echo $th_navstrip_font_color;?> }
A.maintitlebar { color: <?php echo $th_navstrip_font_color;?> }
A.maintitlebar:visited { color: <?php echo $th_navstrip_font_color;?> }

.menus { color: <?php echo $th_nav_font_color;?>; text-decoration: none }
.menus:visited { color: <?php echo $th_font_color;?>; text-decoration: none }
.menus:hover { color: <?php echo $th_font_color;?>; text-decoration:underline }

A:link { text-decoration:none }
A:visited { text-decoration:none }
A:active { text-decoration:none }
A:hover { text-decoration:underline }

.titlebar { text-decoration:none; color:<?php echo $th_navstrip_font_color;?>; font-family: <?php echo $th_font_family;?>; font-size: <?php echo $fsn ?>; font-weight: bold }
