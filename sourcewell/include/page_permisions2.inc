<?php

######################################################################
# Permisions for Page Access
# ===================================================================
#
#
#
# Copyright (c) 2001 by
#                Gregorio Robles (grex@scouts-es.org)
#
#  SourceWell 2: http://sourcewell.berlios.de
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

# Primero vienen los permisos de las diferentes paginas
# En la columna de la izquierda debe aparecer el nombre de la pagina (sin el php3)
# y en la de la derecha, los usuarios que tienen permiso para acceder a la misma

$required_permision = array (
	"app"		=>	"all",
	"app_edi"	=> 	"anonymous",
	"app_mod"	=>	"anonymous",
	"admapp"	=>	"user,editor",
	"register"	=>	"all",
	"login"		=>	"all",
	"register"	=>	"all",
	"remind"	=>	"all",
	"remindme"	=>	"all",
	"faq"		=>	"all",
	"admfaq"	=>	"user,editor,admin",
	"chguser"	=> 	"user",
	"admuser"	=>  "admin"
);

$permision_for_validating_apps = "user,editor";
?>