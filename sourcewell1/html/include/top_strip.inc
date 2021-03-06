<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ================================================
#
# Copyright (c) 2002-2004 by
#                Lutz Henckel (lutz.henckel@fokus.fraunhofer.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This file shows a strip at the top of the page
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

?>

<!-- top strip -->
<table BORDER=0 CELLSPACING=0 CELLPADDING=2 WIDTH="100%" BGCOLOR="<?php echo $th_navstrip_bgcolor;?>">
<tr>
<td width=45%><span class=maintitlebar>
<?php
$i = 0;
while (list($title, $url) = each($ts_array)) {
	if ($i > 0)
		echo "\n | ";
	echo "<b><a href=\"$url\" class=\"maintitlebar\">$title</a></b>";
	$i++;
};
echo "\n</span></td><td width=55% align=right>\n";
echo "<B><FONT COLOR=\"".$th_nav_bgcolor."\">The SourceWell Project Page</b></FONT>";
?>

</td>
</tr>

</table>
<!-- end top strip -->
