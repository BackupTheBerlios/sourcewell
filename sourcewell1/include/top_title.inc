<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ====================================================
#
# Copyright (c) 2001-2004 by
#                Lutz Henckel (lutz.henckel@fokus.fraunhofer.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This file shows a bar with a title at the top of the pages
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

?>

<!-- top title -->
<table border=0 cellspacing=0 cellpadding=0 width="100%" >
<tr valign="top" bgcolor="<?php echo $th_nav_bgcolor;?>">
<td bgcolor="<?php echo $th_body_bgcolor;?>"><a href="<?php echo $sys_url_title;?>"><img src="<?php echo $sys_logo_image;?>" hspace=5 vspace=5 border=0 height=<?php echo $sys_logo_heigth;?> width=<?php echo $sys_logo_width;?> ALT="<?php echo $sys_logo_alt;?>"></a></td>
<td width="10"><img src="images/blank.gif" border="0" height="1" width="10" alt=""></td>
<td valign="middle" width="99%"><font color="<?php echo $th_nav_font_color;?>"><b><font size="+1"><?php echo $sys_name;?></font></b>
<br><?php echo $t->translate($sys_title);?></font></td>

<!-- logo at right -->
<td valign="middle">
<a href="<?php echo $org_url;?>" target="_blank"><img src="<?php echo $org_logo_image;?>" alt="<?php echo $org_logo_alt;?>" hspace=10 border=0 height=<?php echo $org_logo_heigth;?> width=<?php echo $org_logo_width;?> align=right></a></td>
</tr>
<!-- end logo at right -->

<tr>
<td colspan="4" bgcolor="<?php echo $th_navstrip_bgcolor;?>"><img src="images/blank.gif" height="2" width="2" alt=""></td>
</tr>
</table>
<!-- end top title -->
