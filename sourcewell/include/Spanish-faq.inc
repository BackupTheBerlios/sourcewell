<?php

$qa = array (

	"&iquest;C&oacute;mo puedo cambiar mi contrase&ntilde;a o la direcci&oacute;n de correo-e con la que estoy registrado?" =>
		"Seleccione \"<a href=chguser.php3>".$t->translate("Change User")."</a>\" e introduzca los nuevos par&aacute;metros. ",

	"He enviado una notificaci&oacute;n, pero todav&iacute;a no se muestra. &iquest;Por qu&eacute;?" =>
		"Todas las notificaciones han de ser verificadas y validadas por un editor de $sys_name. "
		."Esto puede llevar algo de tiempo, pero normalmente se hace el mismo d&iacute;a de la notificaci&oacute;n.",

	"Una de las notificaciones que he enviado no se muestra cuando utilizo \"".$t->translate("Update Apps")."\" &iquest;A qu&eacute; se debe?" =>
		"Otro usuario ha cambiado la notificaci&oacute;n y ha pasado a ser su autor. "
		."Si desea cambiarla de nuevo, "
		."utilice el \"<a href=categories.php3>".$t->translate("Apps Index")."</a>\" para ver las notificaciones y, una vez haya encontrado la aplicaci&oacute;n en cuesti&oacute;n, haga click sobre el bot&oacute;n de ".$t->translate("Update")." . ",

	"&iquest;C&oacute;mo puedo borrar una notificaci&oacute;n hecha en $sys_name?" =>
		"Mande un mensaje de correo-e a "
		."<a href=mailto:$ml_newsadmaddr>$ml_newsadmaddr</a> "
		."explicando la raz&oacute;n para borrarlo. Una vez hecho esto, nosotros lo haremos por usted. "
		."Por favor, no cambie las notificaciones borrando alguno o todos los campos de informaci&oacute;n. ",

	"&iquest;Por qu&eacute; no est&aacute; $sys_name en mi idioma?" =>
		     "$sys_name puede ser traducido de una manera "
		     ."bastante sencilla a otros idiomas. Si ve que "
		     ."$sys_name no tiene soporte para su idioma, "
		     ."est&aacute; gratamente invitado a ayudarnos "
		     ."con la internacionalizaci&oacute;n. "
		     ."Visite <A HREF=\"http://sourcewell.berlios.de/html/translating.php3\">http://sourcewell.berlios.de/html/translating.php3</A>",

	"&iquest;$sys_name env&iacute;a correos-e con las noticias del d&iacute;a?" =>
		"S&iacute;. Existen dos listas de correo-e para todo aquel que quiera suscribirse. "
		."Las noticias ser&aacute;n enviadas seg&uacute;n la lista de la que se trate una vez al d&iacute;a o una vez a la semana. "
		."Para suscribirse mande un mensaje de correo-e a "
		."<a href=mailto:$ml_newsreqaddr?subject=subscribe>$ml_newsreqaddr (diaria)</a> "
		."o <a href=mailto:$ml_weeklynewsreqaddr?subject=subscribe>$ml_weeklynewsreqaddr (semanal)</a>"
		." con el t&iacute;tulo <tt>subscribe</tt> o visite "
		."<a href=$ml_listurl target=_blank>$ml_listurl (diaria)</a> "
		."o <a href=$ml_weeklylisturl target=_blank>$ml_weeklylisturl (semanal)</a> ",

	"&iquest;C&oacute;mo me puedo dar de baja de la lista de noticas $sys_name?" =>
		"Mande un mensaje de correo-e a "
		."<a href=mailto:$ml_newsreqaddr?subject=".rawurlencode("unsubscribe <password>").">$ml_newsreqaddr (diaria)</a> "
		."o <a href=mailto:$ml_weeklynewsreqaddr?subject=".rawurlencode("unsubscribe <password>").">$ml_weeklynewsreqaddr (semanal)</a>"
		." con la palabra <tt>unsubscribe &lt;password&gt;</tt> en el t&iacute;tulo o visite "
		."<a href=$ml_listurl target=_blank>$ml_listurl</a> "
		." y proceda seg&uacute;n se le indica all&iacute;."

);
?>
