<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ================================================
#
# Copyright (c) 2001 by
#                Lutz Henckel (lutz.henckel@fokus.gmd.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This file can be used for installing SourceWell
#
# The main idea and some code have been taken from
# Helge Orthmann otter@otterware.de
# whose program SearchIt also lies under the GPL
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################  

page_open(array("sess" => "SourceWell_Session"));
if (isset($auth) && !empty($auth->auth["perm"])) {
  page_close();
  page_open(array("sess" => "SourceWell_Session",
                  "auth" => "SourceWell_Auth",
                  "perm" => "SourceWell_Perm"));
}

require("header.inc");


?>

<!-- content -->
<Center><h3>Installing MySQL Database for SourceWell (alpha)</h3></CENTER>
<?
$name = basename ($PHP_SELF);
if($install == "1"){
  error_reporting (4);
  if(isset($host) && isset($operator) && isset($password)){
    $link = mysql_pconnect ("$host", "$operator", "$password") or die ("<Center>Could not connect to database!</CENTER>\n<CENTER><a href=\"$name\">$name</a></CENTER>");
    if (mysql_select_db ("sourcewell2")){
      print "<Center>Database <B><I>sourcewell</I></B> already exists!</CENTER>\n";
    } else {
      if(mysql_create_db ("sourcewell2")){
        print "<CENTER align=center>Database <B><I>sourcewell</I></B> created!</CENTER>\n";
        mysql_select_db ("$database");
      }
      else{
        print "<Center>Error: Database <B><I>sourcewell</I></B> could not be created!</CENTER>\n";
        exit;
      }
    }


#
# The MySQL database imports SourceWell's database structure
#                            and some example entries
#
# Database sourcewell
# phpMyAdmin MySQL-Dump
# http://phpwizard.net/phpMyAdmin/
#
# SourceWell Version 1.0
#	     Lutz Henckel <lutz.henckel@fokus.gmd.de>
#	     Gregorio Robles <grex@scouts-es.org>
#
# For more information about the database structure
# have a look at the SourceWell documentation
#
# Database: sourcewell

mysql_query("USE sourcewell2");

# --------------------------------------------------------
#
# Table structure for table 'active_sessions'
#

mysql_query("CREATE TABLE active_sessions (
   sid varchar(32) NOT NULL,
   name varchar(32) NOT NULL,
   val text,
   changed varchar(14) NOT NULL,
   PRIMARY KEY (name, sid),
   KEY changed (changed)
)");

# --------------------------------------------------------
#
# Table structure for table 'auth_user'
#

mysql_query("CREATE TABLE auth_user (
   user_id varchar(32) NOT NULL,
   username varchar(32) NOT NULL,
   password varchar(32) NOT NULL,
   realname varchar(64) NOT NULL,
   email_usr varchar(128) NOT NULL,
   modification_usr timestamp(14),
   creation_usr timestamp(14),
   perms varchar(255),
   PRIMARY KEY (user_id),
   UNIQUE k_username (username)
)");

#
# Dumping data for table 'auth_user'
#

mysql_query("INSERT INTO auth_user VALUES ( 'c8a174e0bdda2011ff798b20f219adc5',
'oldfish', 'oldfish', 'Change Username and Password!', 'admin@your.system', '20010401162518', '20010401162518', 'user,editor,admin')");


# --------------------------------------------------------
#
# Table structure for table 'categories'
#

mysql_query("CREATE TABLE categories (
   section varchar(64) NOT NULL,
   category varchar(64) NOT NULL)");


#
# Dumping data for table 'categories'
#

mysql_query("INSERT INTO categories VALUES ( 'Console', 'CD Writing')");
mysql_query("INSERT INTO categories VALUES ( 'Console', 'Databases')");
mysql_query("INSERT INTO categories VALUES ( 'Console', 'Editors')");
mysql_query("INSERT INTO categories VALUES ( 'Console', 'File & Disk Management')");
mysql_query("INSERT INTO categories VALUES ( 'Console', 'Graphics')");
mysql_query("INSERT INTO categories VALUES ( 'Console', 'Utilities')");
mysql_query("INSERT INTO categories VALUES ( 'Console', 'Miscellaneous')");
mysql_query("INSERT INTO categories VALUES ( 'Development', 'Application & Software Development')");
mysql_query("INSERT INTO categories VALUES ( 'Development', 'Languages')");
mysql_query("INSERT INTO categories VALUES ( 'Development', 'Libraries & Classes')");
mysql_query("INSERT INTO categories VALUES ( 'Development', 'Miscellaneous')");
mysql_query("INSERT INTO categories VALUES ( 'Development', 'Utilities')");
mysql_query("INSERT INTO categories VALUES ( 'GNOME', 'Applications')");
mysql_query("INSERT INTO categories VALUES ( 'GNOME', 'Core')");
mysql_query("INSERT INTO categories VALUES ( 'GNOME', 'CD Writing')");
mysql_query("INSERT INTO categories VALUES ( 'GNOME', 'Development')");
mysql_query("INSERT INTO categories VALUES ( 'GNOME', 'Games')");
mysql_query("INSERT INTO categories VALUES ( 'GNOME', 'Graphics')");
mysql_query("INSERT INTO categories VALUES ( 'GNOME', 'Miscellaneous')");
mysql_query("INSERT INTO categories VALUES ( 'GNOME', 'Networking')");
mysql_query("INSERT INTO categories VALUES ( 'GNOME', 'Multimedia')");
mysql_query("INSERT INTO categories VALUES ( 'GNOME', 'System Utilities')");
mysql_query("INSERT INTO categories VALUES ( 'GNOME', 'Utilities')");
mysql_query("INSERT INTO categories VALUES ( 'KDE', 'Applications')");
mysql_query("INSERT INTO categories VALUES ( 'KDE', 'Core')");
mysql_query("INSERT INTO categories VALUES ( 'KDE', 'CD Writing')");
mysql_query("INSERT INTO categories VALUES ( 'KDE', 'Development')");
mysql_query("INSERT INTO categories VALUES ( 'KDE', 'Games')");
mysql_query("INSERT INTO categories VALUES ( 'KDE', 'Graphics')");
mysql_query("INSERT INTO categories VALUES ( 'KDE', 'Miscellaneous')");
mysql_query("INSERT INTO categories VALUES ( 'KDE', 'Multimedia')");
mysql_query("INSERT INTO categories VALUES ( 'KDE', 'Networking')");
mysql_query("INSERT INTO categories VALUES ( 'KDE', 'System Utilities')");
mysql_query("INSERT INTO categories VALUES ( 'KDE', 'Utilities')");
mysql_query("INSERT INTO categories VALUES ( 'Kernel', 'Linux Ports')");
mysql_query("INSERT INTO categories VALUES ( 'Kernel', 'Sources')");
mysql_query("INSERT INTO categories VALUES ( 'Networking', 'Administration')");
mysql_query("INSERT INTO categories VALUES ( 'Networking', 'E-Mail')");
mysql_query("INSERT INTO categories VALUES ( 'Networking', 'Fax')");
mysql_query("INSERT INTO categories VALUES ( 'Networking', 'File Transfer')");
mysql_query("INSERT INTO categories VALUES ( 'Networking', 'HTML Tool')");
mysql_query("INSERT INTO categories VALUES ( 'Networking', 'Miscellaneous')");
mysql_query("INSERT INTO categories VALUES ( 'Networking', 'News')");
mysql_query("INSERT INTO categories VALUES ( 'Networking', 'PHP')");
mysql_query("INSERT INTO categories VALUES ( 'Networking', 'Servers')");
mysql_query("INSERT INTO categories VALUES ( 'Networking', 'SMS & WAP')");
mysql_query("INSERT INTO categories VALUES ( 'Networking', 'Web Browser')");
mysql_query("INSERT INTO categories VALUES ( 'Networking', 'Web Development')");
mysql_query("INSERT INTO categories VALUES ( 'X11', 'CD Writing')");
mysql_query("INSERT INTO categories VALUES ( 'X11', 'Databases')");
mysql_query("INSERT INTO categories VALUES ( 'X11', 'Desktop, File & Disk Managers')");
mysql_query("INSERT INTO categories VALUES ( 'X11', 'Editors')");
mysql_query("INSERT INTO categories VALUES ( 'X11', 'Games')");
mysql_query("INSERT INTO categories VALUES ( 'X11', 'Graphics')");
mysql_query("INSERT INTO categories VALUES ( 'X11', 'Multimedia')");
mysql_query("INSERT INTO categories VALUES ( 'X11', 'Personal Desktop Tools')");
mysql_query("INSERT INTO categories VALUES ( 'X11', 'Server')");
mysql_query("INSERT INTO categories VALUES ( 'X11', 'System Utilities')");
mysql_query("INSERT INTO categories VALUES ( 'X11', 'Miscellaneous')");
mysql_query("INSERT INTO categories VALUES ( 'X11', 'Window Manager')");

# --------------------------------------------------------
#
# Table structure for table 'comments'
#

mysql_query("CREATE TABLE comments (
   appid bigint(20) unsigned DEFAULT '0' NOT NULL,
   user_cmt varchar(16) NOT NULL,
   subject_cmt varchar(128) NOT NULL,
   text_cmt blob NOT NULL,
   creation_cmt timestamp(14))");

#
# Dumping data for table 'comments'
#

mysql_query("INSERT INTO comments VALUES ( '1', 'oldfish', 'We use SourceWell successfully', 'You can visit our web site at <A
HREF=\"http://sourcewell.berlios.de\">http://sourcewell.berlios.de</a>
where we have been using the SourceWell system succesfully for more
than three months yet. There are now more than 750 applications
announced in our system. A look a at it will let you see how far you
can go with it!', '20010402162952')");

# --------------------------------------------------------
#
# Table structure for table 'counter'
#

mysql_query("CREATE TABLE counter (
   appid bigint(20) unsigned DEFAULT '0' NOT NULL,
   app_cnt int(11) DEFAULT '0' NOT NULL,
   homepage_cnt int(11) DEFAULT '0' NOT NULL,
   download_cnt int(11) DEFAULT '0' NOT NULL,
   changelog_cnt int(11) DEFAULT '0' NOT NULL,
   rpm_cnt int(11) DEFAULT '0' NOT NULL,
   deb_cnt int(11) DEFAULT '0' NOT NULL,
   tgz_cnt int(11) DEFAULT '0' NOT NULL,
   cvs_cnt int(11) DEFAULT '0' NOT NULL,
   screenshots_cnt int(11) DEFAULT '0' NOT NULL,
   mailarch_cnt int(11) DEFAULT '0' NOT NULL,
   UNIQUE appsid (appid))");

#
# Dumping data for table 'counter'
#

mysql_query("INSERT INTO counter VALUES ( '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0')");

# --------------------------------------------------------
#
# Table structure for table 'counter_check'
#

mysql_query("CREATE TABLE counter_check (
   appid bigint(20) unsigned DEFAULT '0' NOT NULL,
   cnt_type varchar(20) NOT NULL,
   ipaddr varchar(15) DEFAULT '127.000.000.001' NOT NULL,
   creation_cnt timestamp(14)
)");

# --------------------------------------------------------
#
# Table structure for table 'history'
#

mysql_query("CREATE TABLE history (
   idx_his bigint(20) DEFAULT '0' NOT NULL auto_increment,
   appid bigint(20) DEFAULT '0' NOT NULL,
   user_his varchar(16) NOT NULL,
   creation_his timestamp(14),
   version_his varchar(16) NOT NULL,
   UNIQUE idx_2 (idx_his)
)");

#
# Dumping data for table 'history'
#

mysql_query("INSERT INTO history VALUES ( '1', '1', 'oldfish', '20010402121122', '1.0')");

# --------------------------------------------------------
#
# Table structure for table 'licenses'
#

mysql_query("CREATE TABLE licenses (
   license varchar(64) NOT NULL,
   url varchar(255) NOT NULL
)");

#
# Dumping data for table 'licenses'
#

mysql_query("INSERT INTO licenses VALUES ( 'Apache style', 'http://www.apache.org/docs-2.0/LICENSE')");
mysql_query("INSERT INTO licenses VALUES ( 'BSD type', 'http://www.freebsd.org/copyright/license.html')");
mysql_query("INSERT INTO licenses VALUES ( 'commercial', 'http://sourcewell.berlios.de/licnotavailable.php3')");
mysql_query("INSERT INTO licenses VALUES ( 'free for non-commercial use', 'http://sourcewell.berlios.de/licnotavailable.php3')");
mysql_query("INSERT INTO licenses VALUES ( 'Free Trail', 'http://sourcewell.berlios.de/licnotavailable.php3')");
mysql_query("INSERT INTO licenses VALUES ( 'freely distributable', 'http://sourcewell.berlios.de/licnotavailable.php3')");
mysql_query("INSERT INTO licenses VALUES ( 'Freeware', 'http://sourcewell.berlios.de/licnotavailable.php3')");
mysql_query("INSERT INTO licenses VALUES ( 'GPL', 'http://www.gnu.org/copyleft/gpl.html')");
mysql_query("INSERT INTO licenses VALUES ( 'LGPL', 'http://www.gnu.org/copyleft/lesser.html')");
mysql_query("INSERT INTO licenses VALUES ( 'MIT', 'http://sourcewell.berlios.de/licnotavailable.php3')");
mysql_query("INSERT INTO licenses VALUES ( 'MPL', 'http://www.mozilla.org/MPL/')");
mysql_query("INSERT INTO licenses VALUES ( 'Open Source', 'http://www.opensource.org/osd.html')");
mysql_query("INSERT INTO licenses VALUES ( 'Public Domain', 'http://www.eiffel-forum.org/license/index.htm#pd')");
mysql_query("INSERT INTO licenses VALUES ( 'FreeBSD', 'http://www.freebsd.org/copyright/freebsd-license.html')");
mysql_query("INSERT INTO licenses VALUES ( 'OpenBSD', 'http://www.openbsd.org/policy.html')");
mysql_query("INSERT INTO licenses VALUES ( 'Other', 'http://sourcewell.berlios.de/licnotavailable.php3')");
mysql_query("INSERT INTO licenses VALUES ( 'Artistic License', 'http://www.perl.com/language/misc/Artistic.html')");
mysql_query("INSERT INTO licenses VALUES ( 'PHP License', 'http://www.php.net/license.html')");
mysql_query("INSERT INTO licenses VALUES ( 'free to use but restricted', 'http://sourcewell.berlios.de/licnotavailable.php3')");
mysql_query("INSERT INTO licenses VALUES ( 'X11 License', 'http://www.x.org/terms.htm')");
mysql_query("INSERT INTO licenses VALUES ( 'Zope Public License', 'http://www.zope.com/Resources/ZPL')");
mysql_query("INSERT INTO licenses VALUES ( 'IBM Public License', 'http://oss.software.ibm.com/developerworks/opensource/license10.html')");
mysql_query("INSERT INTO licenses VALUES ( 'Shareware', 'http://sourcewell.berlios.de/licnotavailable.php3')");

# --------------------------------------------------------
#
# Table structure for table 'software'
#

mysql_query("CREATE TABLE software (
   appid bigint(20) unsigned DEFAULT '0' NOT NULL auto_increment,
   name varchar(128) NOT NULL,
   type char(1) NOT NULL,
   version varchar(16) NOT NULL,
   section varchar(64) NOT NULL,
   category varchar(64) NOT NULL,
   license varchar(64) NOT NULL,
   homepage varchar(255) NOT NULL,
   download varchar(255),
   changelog varchar(255),
   rpm varchar(255),
   deb varchar(255),
   tgz varchar(255),
   cvs varchar(255),
   screenshots varchar(255),
   mailarch varchar(255),
   developer varchar(64) NOT NULL,
   description blob NOT NULL,
   modification timestamp(14),
   creation timestamp(14),
   email varchar(128) NOT NULL,
   depend varchar(128) NOT NULL,
   user varchar(16) NOT NULL,
   status char(1) NOT NULL,
   urgency int(11) DEFAULT '2' NOT NULL,
   UNIQUE appid (appid)
)");

#
# Dumping data for table 'software'
#

mysql_query("INSERT INTO software VALUES ( '1', 'SourceWell', 'S', '1.0',
'Networking', 'PHP', 'GPL',
'http://developer.berlios.de/project/?group_id=23',
'http://developer.berlios.de/project/filelist.php?group_id=23', '',
'', '', '', 'http://developer.berlios.de/cvs/?group_id=23', 'http://sourcewell.berlios.de', '',
'Lutz Henckel & Gregorio Robles', 'SourceWell is a highly configurable
software announcement and retrieval system written entirely in PHP3 
using a MySQL database. It includes application indexing by sections,
multiple languages, user authentication and
autherization system (user/editor/admin) by means of PHPLib, XML-Backend, advanced statistics and many other
useful features. For advanced features (diary and weekly mailing lists with the announcements) Mailman is also required.', '20010402121122', '20010402121122',
'lutz.henckel@fokus.gmd.de', 'PHP3, MySQL, PHPLib, (Mailman)','oldfish', 'A', '2')");

print "<Center>Tables for SourceWell created!</center>\n";


#
# We make the local2.inc file with the database configuration 
#

$fp = fopen ("include/local2.inc", "w"); 
fputs($fp, "<?php
/*
 * Session Management for PHP3
 *
 * Copyright (c) 1998-2000 NetUSE AG
 *                    Boris Erdmann, Kristian Koehntopp
 *
 * \$Id: install.php3,v 1.1 2001/05/20 14:21:01 grex Exp $
 *
 */ 

######################################################################
# SourceWell Database Configuration
#
# For using SourceWell, you only have to fill in the appropriate
# parameters that fit your database
#
# The default (and recommended) configuration is the one with
# \"sourcewell\" as the database name. Do better not change it ;-)
#
######################################################################

class DB_SourceWell extends DB_Sql {
  var \$Host     = \"$host\";
  var \$Database = \"sourcewell\";
  var \$User     = \"$operator\";
  var \$Password = \"$password\";
}

/*********************************************************************/
/* If you've finished configuring the Database, you can login as an  */
/* administrator. To do so, just launch your web browser pointing to */
/* http://yourdomain.com/login.php3 and login as the default admin   */
/* with user,editor,admin permissions.                               */
/*                                                                   */
/* At the prompt use the following ID to login (case sensitive):     */
/*                                                                   */
/*         Username: oldfish                                         */
/*         Password: oldfish                                         */
/*                                                                   */
/* Vert important:                                                   */
/* Be sure of inmediately changing the login & password by clicking  */
/* on User Admin. You'll notice this is quite easy to do ;-)         */
/*								     */
/*               Thanks for having chosen SourceWell                 */
/*********************************************************************/


######################################################################
# SourceWell Advanced Database Configuration
#
# If you've chosen \"sourcewell\" as your database name, you don't
# need to worry about the rest of the file ;-)
#
# If you've chosen another database name, you'll have to change this
# file and config.inc in the pint \"Database Name Config\".
######################################################################

class SourceWell_CT_Sql extends CT_Sql {
  var \$database_class = \"DB_SourceWell\";   ## Which database to connect...
  var \$database_table = \"active_sessions\"; ## and find our session data in this table.
}

class SourceWell_Session extends Session {
  var \$classname = \"SourceWell_Session\";

  var \$cookiename     = \"\";                ## defaults to classname
  var \$magic          = \"Hocuspocus\";      ## ID seed
  var \$mode           = \"cookie\";          ## We propagate session IDs with cookies
#  var \$mode = \"get\";
  var \$fallback_mode  = \"get\";
  var \$lifetime       = 0;                 ## 0 = do session cookies, else minutes
  var \$that_class     = \"SourceWell_CT_Sql\"; ## name of data storage container
  var \$gc_probability = 5;  
}

class SourceWell_User extends User {
  var \$classname = \"SourceWell_User\";

  var \$magic          = \"Abracadabra\";     ## ID seed
  var \$that_class     = \"SourceWell_CT_Sql\"; ## data storage container
}

class SourceWell_Auth extends Auth {
  var \$classname      = \"SourceWell_Auth\";

  var \$lifetime       =  15;

  var \$database_class = \"DB_SourceWell\";
  var \$database_table = \"auth_user\";
  
  function auth_loginform() {
    global \$sess;
    global \$_PHPLIB;

    include(\"loginform.ihtml\");
  }
  
  function auth_validatelogin() {
    global \$username, \$password;

    if(isset(\$username)) {
      \$this->auth[\"uname\"]=\$username;        ## This provides access for \"loginform.ihtml\"
    }
    
    
    \$uid = false;
    
    \$this->db->query(sprintf(\"select user_id, perms \".
                             \"        from %s \".
                             \"       where username = '%s' \".
                             \"         and password = '%s'\",
                          \$this->database_table,
                          addslashes(\$username),
                          addslashes(\$password)));

    while(\$this->db->next_record()) {
      \$uid = \$this->db->f(\"user_id\");
      \$this->auth[\"perm\"] = \$this->db->f(\"perms\");
    }
    return \$uid;
  }
}

class SourceWell_Default_Auth extends SourceWell_Auth {
  var \$classname = \"SourceWell_Default_Auth\";
  
  var \$nobody    = true;
}

class SourceWell_Challenge_Auth extends Auth {
  var \$classname      = \"SourceWell_Challenge_Auth\";

  var \$lifetime       =  1;

  var \$magic          = \"Simsalabim\";  ## Challenge seed
  var \$database_class = \"DB_SourceWell\";
  var \$database_table = \"auth_user\";

  function auth_loginform() {
    global \$sess;
    global \$challenge;
    global \$_PHPLIB;
    
    \$challenge = md5(uniqid(\$this->magic));
    \$sess->register(\"challenge\");
    
    include(\$_PHPLIB[\"libdir\"] . \"crloginform.ihtml\");
  }
  
  function auth_validatelogin() {
    global \$username, \$password, \$challenge, \$response;

    if(isset(\$username)) {
      \$this->auth[\"uname\"]=\$username;        ## This provides access for \"loginform.ihtml\"
    }
    \$this->db->query(sprintf(\"select user_id,perms,password \".
                \"from %s where username = '%s'\",
                          \$this->database_table,
                          addslashes(\$username)));

    while(\$this->db->next_record()) {
      \$uid   = \$this->db->f(\"user_id\");
      \$perm  = \$this->db->f(\"perms\");
      \$pass  = \$this->db->f(\"password\");
    }
    \$exspected_response = md5(\"\$username:\$pass:\$challenge\");

    ## True when JS is disabled
    if (\$response == \"\") {
      if (\$password != \$pass) {
        return false;
      } else {
        \$this->auth[\"perm\"] = \$perm;
        return \$uid;
      }
    }
    
    ## Response is set, JS is enabled
    if (\$exspected_response != \$response) {
      return false;
    } else {
      \$this->auth[\"perm\"] = \$perm;
      return \$uid;
    }
  }
}

##
## SourceWell_Challenge_Crypt_Auth: Keep passwords in md5 hashes rather 
##                           than cleartext in database
## Author: Jim Zajkowski <jim@jimz.com>

class SourceWell_Challenge_Crypt_Auth extends Auth {
  var \$classname      = \"SourceWell_Challenge_Crypt_Auth\";

  var \$lifetime       =  1;

  var \$magic          = \"Frobozzica\";  ## Challenge seed
  var \$database_class = \"DB_SourceWell\";
  var \$database_table = \"auth_user_md5\";

  function auth_loginform() {
    global \$sess;
    global \$challenge;
    
    \$challenge = md5(uniqid(\$this->magic));
    \$sess->register(\"challenge\");
    
    include(\"crcloginform.ihtml\");
  }
  
  function auth_validatelogin() {
    global \$username, \$password, \$challenge, \$response;

    \$this->auth[\"uname\"]=\$username;        ## This provides access for \"loginform.ihtml\"
    
    \$this->db->query(sprintf(\"select user_id,perms,password \".
                \"from %s where username = '%s'\",
                          \$this->database_table,
                          addslashes(\$username)));

    while(\$this->db->next_record()) {
      \$uid   = \$this->db->f(\"user_id\");
      \$perm  = \$this->db->f(\"perms\");
      \$pass  = \$this->db->f(\"password\");   ## Password is stored as a md5 hash
    }
    \$exspected_response = md5(\"\$username:\$pass:\$challenge\");

    ## True when JS is disabled
    if (\$response == \"\") {
      if (md5(\$password) != \$pass) {       ## md5 hash for non-JavaScript browsers
        return false;
      } else {
        \$this->auth[\"perm\"] = \$perm;
        return \$uid;
      }
    }
    
    ## Response is set, JS is enabled
    if (\$exspected_response != \$response) {
      return false;
    } else {
      \$this->auth[\"perm\"] = \$perm;
      return \$uid;
    }
  }
}

class SourceWell_Perm extends Perm {
  var \$classname = \"SourceWell_Perm\";
  
  var \$permissions = array(
                            \"user_pending\" => 1,
                            \"user\"       => 2,
                            \"editor\"     => 4,
                            \"supervisor\" => 8,
                            \"admin\"      => 16
                          );

  function perm_invalid(\$does_have, \$must_have) {
    global \$perm, \$auth, \$sess;
    global \$_PHPLIB;
    
    include(\$_PHPLIB[\"libdir\"] . \"perminvalid.ihtml\");
  }
}

?>");

      fclose($fp);
      if(fopen("include/local2.inc", "r") != "false"){print "<center>All done! Remove now $name!</center>\n";
      echo "You can enter now <A HREF=\"index.php3\">your SouceWell system</A>!\n";
      }else{print "<center>Error: local2.inc could not be created!</center>\n";}
/*    }else{print "<center>Error: Tables could not be created!</center>\n";}
    mysql_close ($link);
*/  } 
  else{
    print "<Center>Please fill out all forms!</CENTER>\n";
    print "<Center><a href=\"$name\">$name</a></center>";
  }
} else{
  print "<form action=\"$name?install=1\" method=\"post\">\n";
  print "<CENTER><table border=0 width=88%>\n<tr>\n";
  print "  <td width=35%><B>MySQL Server:</B></td>\n  <td width=70%><input type=text name=host value=localhost size=37></td>\n </tr>\n <tr>\n";
  print "  <td width=35%><B>MySQL operator:</B></td>\n  <td width=70%><input type=text name=operator size=37></td>\n </tr>\n <tr>\n";
  print "  <td width=35%><B>MySQL operator password:</B></td>\n  <td width=70%><input type=password name=password size=37></td>\n </tr>\n <tr>\n";
  print "  <td colspan=2 align=right><input type=SUBMIT VALUE=Install></form></td>\n </tr>\n</table></CENTER>\n";
}
?>

<!-- end content -->

<?php
require("footer.inc");
@page_close();
?>

