<?php
/* vim: set expandtab tabstop=4 shiftwidth=4: */
// +----------------------------------------------------------------------+
// |        SourceWell 2 - The GPL Software Announcement System           |
// +----------------------------------------------------------------------+
// |      Copyright (c) 2001-2002 BerliOS, FOKUS Fraunhofer Institut      |
// +----------------------------------------------------------------------+
// | This program is free software. You can redistribute it and/or modify |
// | it under the terms of the GNU General Public License as published by |
// | the Free Software Foundation; either version 2 or later of the GPL.  |
// +----------------------------------------------------------------------+
// | Authors: Gregorio Robles <grex@scouts-es.org>                        |
// +----------------------------------------------------------------------+
//
// $Id: footer.inc,v 1.8 2002/05/09 20:44:44 grex Exp $

/* Configuration parameters are set as global */
/* their values can be found at config.inc */
global $config_navstrip_bgcolor;
global $config_navstrip_font_color;
global $config_org_url;
global $config_org_name;
global $config_sys_url;
global $config_nav_bgcolor;

global $PHP_SELF;

/**
 * WISH: here we could have some functions that
 * do some advertising of BerliOS
 */

?>
<br>
  <p align="right">
    <a href="http://validator.w3.org/check/referer">
    <img border="0"
         src="http://www.w3.org/Icons/valid-html40"
         alt="Valid HTML 4.0!" height="31" width="88"></a>
    <a href="http://jigsaw.w3.org/css-validator?uri=<?php echo $config_sys_url.'/'.$PHP_SELF;?>">
    <img style="border:0;width:88px;height:31px"
         src="http://jigsaw.w3.org/css-validator/images/vcss"
         alt="Valid CSS!"></a>
  </p>
</td>
</tr>
</table>

<!-- footer -->
<table border="0" cellspacing="0" cellpadding="2" width="100%" 
bgcolor="<?php echo $config_navstrip_bgcolor;?>">
<tr>
<td width="15%">&nbsp;</td>
<td align="center" width="70%"><span class="titlebar">
<font color="<?php echo $config_navstrip_font_color;?>">Copyright
&copy; 2001,2002 <a href="<?php echo $config_org_url;?>" class="maintitlebar" 
target="_blank"><?php echo $config_org_name;?></a>.</font></span></td>
<td width="15%" align="right"><span class="titlebar">
<a href="<?php echo $config_sys_url;?>html" target="_blank"><font 
color="<?php echo $config_nav_bgcolor;?>">
<?php echo _('System Credits');?></font></a>&nbsp;</span></td>
</tr>
</table>
<!-- end footer -->

</body>
</html>