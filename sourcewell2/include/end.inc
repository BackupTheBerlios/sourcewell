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
<?php
#
# the last we do is shut down the logger
#
//$l = new Logger;
//$l->close();

/* PHPLib session maintainance function */
page_close();
?>