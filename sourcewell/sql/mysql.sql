# Database sourcewell
# phpMyAdmin MySQL-Dump
# http://phpwizard.net/phpMyAdmin/
#
# SourceWell Version 1.0.10
#	     Lutz Henckel <lutz.henckel@fokus.gmd.de>
#	     Gregorio Robles <grex@scouts-es.org>
#
# For more information about the database structure
# have a look at the SourceWell documentation
#
# Database: sourcewell

USE sourcewell;

# --------------------------------------------------------
#
# Table structure for table 'active_sessions'
#

DROP TABLE IF EXISTS active_sessions;
CREATE TABLE active_sessions (
   sid varchar(32) NOT NULL,
   name varchar(32) NOT NULL,
   val text,
   changed varchar(14) NOT NULL,
   PRIMARY KEY (name, sid),
   KEY changed (changed)
);

# --------------------------------------------------------
#
# Table structure for table 'auth_user'
#

DROP TABLE IF EXISTS auth_user;
CREATE TABLE auth_user (
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
);

#
# Dumping data for table 'auth_user'
#

INSERT INTO auth_user VALUES ( 'c8a174e0bdda2011ff798b20f219adc5',
'oldfish', 'oldfish', 'Change Username and Password!', 'admin@your.system', '20010417103000', '20010417103000', 'user,editor,admin');
INSERT INTO auth_user VALUES ( '9608a4062d05bad564b3b8fe6aaac481', 'anonymous', 'anonymous', 'Anonymous User', 'nobody@nowhere.com',  '20010417104500', '20010417104500', 'anonymous');


# --------------------------------------------------------
#
# Table structure for table 'categories'
#

DROP TABLE IF EXISTS categories;
CREATE TABLE categories (
   section varchar(64) NOT NULL,
   category varchar(64) NOT NULL
);

#
# Dumping data for table 'categories'
#

INSERT INTO categories VALUES ( 'Console', 'Backup');
INSERT INTO categories VALUES ( 'Console', 'Databases');
INSERT INTO categories VALUES ( 'Console', 'Document Processing');
INSERT INTO categories VALUES ( 'Console', 'Editors');
INSERT INTO categories VALUES ( 'Console', 'Emulators');
INSERT INTO categories VALUES ( 'Console', 'File & Disk Management');
INSERT INTO categories VALUES ( 'Networking', 'Mirroring');
INSERT INTO categories VALUES ( 'Console', 'Games');
INSERT INTO categories VALUES ( 'Console', 'Kernel Drivers & Modules');
INSERT INTO categories VALUES ( 'Console', 'Multimedia');
INSERT INTO categories VALUES ( 'Console', 'Personal Tools');
INSERT INTO categories VALUES ( 'Console', 'Science & Mathematic');
INSERT INTO categories VALUES ( 'Console', 'Shells');
INSERT INTO categories VALUES ( 'Console', 'Utilities');
INSERT INTO categories VALUES ( 'Console', 'Miscellaneous');
INSERT INTO categories VALUES ( 'Development', 'Application & Software Development');
INSERT INTO categories VALUES ( 'Development', 'Libraries & Classes');
INSERT INTO categories VALUES ( 'Development', 'Translator');
INSERT INTO categories VALUES ( 'Development', 'Debugging');
INSERT INTO categories VALUES ( 'Kernel', 'Sources');
INSERT INTO categories VALUES ( 'Kernel', 'Linux Ports');
INSERT INTO categories VALUES ( 'Networking', 'Chat');
INSERT INTO categories VALUES ( 'Networking', 'Clients');
INSERT INTO categories VALUES ( 'Networking', 'Cluster');
INSERT INTO categories VALUES ( 'Networking', 'Cooperative Work');
INSERT INTO categories VALUES ( 'Networking', 'Directory');
INSERT INTO categories VALUES ( 'Networking', 'E-Commerce & E-Business');
INSERT INTO categories VALUES ( 'Networking', 'E-Mail');
INSERT INTO categories VALUES ( 'Networking', 'Fax');
INSERT INTO categories VALUES ( 'Networking', 'File Transfer');
INSERT INTO categories VALUES ( 'Networking', 'Financial');
INSERT INTO categories VALUES ( 'Networking', 'Conferencing');
INSERT INTO categories VALUES ( 'Networking', 'Administration');
INSERT INTO categories VALUES ( 'Networking', 'Remote Login');
INSERT INTO categories VALUES ( 'Networking', 'SMS & WAP');
INSERT INTO categories VALUES ( 'Networking', 'News');
INSERT INTO categories VALUES ( 'Networking', 'Web Browser');
INSERT INTO categories VALUES ( 'Networking', 'Web Server');
INSERT INTO categories VALUES ( 'Networking', 'CGI');
INSERT INTO categories VALUES ( 'Networking', 'HTML Tool');
INSERT INTO categories VALUES ( 'Console', 'Sound');
INSERT INTO categories VALUES ( 'Networking', 'Miscellaneous');
INSERT INTO categories VALUES ( 'Networking', 'Sound');
INSERT INTO categories VALUES ( 'Networking', 'Monitoring');
INSERT INTO categories VALUES ( 'Networking', 'Web Browser Plug-ins');
INSERT INTO categories VALUES ( 'Networking', 'Search Engine');
INSERT INTO categories VALUES ( 'X11', 'Graphics');
INSERT INTO categories VALUES ( 'KDE', 'Core');
INSERT INTO categories VALUES ( 'X11', 'GUI Builder');
INSERT INTO categories VALUES ( 'X11', 'Server');
INSERT INTO categories VALUES ( 'X11', 'Backup');
INSERT INTO categories VALUES ( 'X11', 'Databases');
INSERT INTO categories VALUES ( 'X11', 'Desktop, File & Disk Managers');
INSERT INTO categories VALUES ( 'X11', 'Document Processing');
INSERT INTO categories VALUES ( 'X11', 'Editors');
INSERT INTO categories VALUES ( 'X11', 'Financial');
INSERT INTO categories VALUES ( 'X11', 'Games');
INSERT INTO categories VALUES ( 'X11', 'Multimedia');
INSERT INTO categories VALUES ( 'X11', 'Personal Desktop Tools');
INSERT INTO categories VALUES ( 'X11', 'Science & Mathematic');
INSERT INTO categories VALUES ( 'X11', 'System Utilities');
INSERT INTO categories VALUES ( 'X11', 'Miscellaneous');
INSERT INTO categories VALUES ( 'X11', 'Window Manager');
INSERT INTO categories VALUES ( 'X11', 'Image Processing');
INSERT INTO categories VALUES ( 'Development', 'Compiler');
INSERT INTO categories VALUES ( 'Development', 'Interpreter');
INSERT INTO categories VALUES ( 'Development', 'Documentation');
INSERT INTO categories VALUES ( 'Console', 'Image Processing');
INSERT INTO categories VALUES ( 'Console', 'Graphics');
INSERT INTO categories VALUES ( 'Kernel', 'Patches');
INSERT INTO categories VALUES ( 'Kernel', 'Documentation');
INSERT INTO categories VALUES ( 'Networking', 'Video');
INSERT INTO categories VALUES ( 'Networking', 'Proxy Server');
INSERT INTO categories VALUES ( 'Development', 'IDE');
INSERT INTO categories VALUES ( 'KDE', 'Miscellaneous');
INSERT INTO categories VALUES ( 'GNOME', 'Desktop');
INSERT INTO categories VALUES ( 'Networking', 'XML Tool');
INSERT INTO categories VALUES ( 'X11', 'Sound');
INSERT INTO categories VALUES ( 'X11', 'Video');
INSERT INTO categories VALUES ( 'KDE', 'Development');
INSERT INTO categories VALUES ( 'KDE', 'Desktop');
INSERT INTO categories VALUES ( 'KDE', 'Games');
INSERT INTO categories VALUES ( 'KDE', 'Graphics');
INSERT INTO categories VALUES ( 'KDE', 'Chat');
INSERT INTO categories VALUES ( 'KDE', 'Sound');
INSERT INTO categories VALUES ( 'KDE', 'Video');
INSERT INTO categories VALUES ( 'KDE', 'Multimedia');
INSERT INTO categories VALUES ( 'KDE', 'Networking');
INSERT INTO categories VALUES ( 'KDE', 'System Utilities');
INSERT INTO categories VALUES ( 'KDE', 'Utilities');
INSERT INTO categories VALUES ( 'KDE', 'Applications');
INSERT INTO categories VALUES ( 'GNOME', 'Applications');
INSERT INTO categories VALUES ( 'GNOME', 'Core');
INSERT INTO categories VALUES ( 'GNOME', 'Development');
INSERT INTO categories VALUES ( 'GNOME', 'Games');
INSERT INTO categories VALUES ( 'GNOME', 'Graphics');
INSERT INTO categories VALUES ( 'GNOME', 'Miscellaneous');
INSERT INTO categories VALUES ( 'GNOME', 'Networking');
INSERT INTO categories VALUES ( 'GNOME', 'Multimedia');
INSERT INTO categories VALUES ( 'GNOME', 'Sound');
INSERT INTO categories VALUES ( 'GNOME', 'Video');
INSERT INTO categories VALUES ( 'GNOME', 'System Utilities');
INSERT INTO categories VALUES ( 'GNOME', 'Utilities');
INSERT INTO categories VALUES ( 'Console', 'Video');
INSERT INTO categories VALUES ( 'Development', 'Miscellaneous');
INSERT INTO categories VALUES ( 'Development', 'Utilities');
INSERT INTO categories VALUES ( 'Networking', 'Servers');
INSERT INTO categories VALUES ( 'Networking', 'PHP');
INSERT INTO categories VALUES ( 'X11', 'System');
INSERT INTO categories VALUES ( 'X11', 'Emulators');
INSERT INTO categories VALUES ( 'Networking', 'Web Development');
INSERT INTO categories VALUES ( 'Development', 'Revision Control');
INSERT INTO categories VALUES ( 'Console', 'Operating Systems');
INSERT INTO categories VALUES ( 'Console', 'CD Writing');
INSERT INTO categories VALUES ( 'X11', 'CD Writing');
INSERT INTO categories VALUES ( 'KDE', 'CD Writing');
INSERT INTO categories VALUES ( 'GNOME', 'CD Writing');
INSERT INTO categories VALUES ( 'KDE', 'Office');
INSERT INTO categories VALUES ( 'Development', 'Languages');
INSERT INTO categories VALUES ( 'Console', 'Security');
INSERT INTO categories VALUES ( 'Networking', 'Firewall and Security');
INSERT INTO categories VALUES ( 'Development', 'Database');
INSERT INTO categories VALUES ( 'Networking', 'Log Analyzers');
INSERT INTO categories VALUES ( 'GNOME', 'Databases');
INSERT INTO categories VALUES ( 'KDE', 'Databases');
INSERT INTO categories VALUES ( 'X11', 'Java');
INSERT INTO categories VALUES ( 'Networking', 'Middleware');

# --------------------------------------------------------
#
# Table structure for table 'comments'
#

DROP TABLE IF EXISTS comments;
CREATE TABLE comments (
   appid bigint(20) unsigned DEFAULT '0' NOT NULL,
   user_cmt varchar(16) NOT NULL,
   subject_cmt varchar(128) NOT NULL,
   text_cmt blob NOT NULL,
   creation_cmt timestamp(14)
);

#
# Dumping data for table 'comments'
#

INSERT INTO comments VALUES ( '1', 'anonymous', 'We use SourceWell successfully!', 'You can visit our web site at <A HREF="http://sourcewell.berlios.de">http://sourcewell.berlios.de</a> where we have been using the SourceWell system succesfully for more than three months yet. You will find more than 900 inserted applications and 2000 releases announced in our system. A closer look a at it will let you see how far you can go with it!', '20010522133952');


# --------------------------------------------------------
#
# Table structure for table 'counter'
#

DROP TABLE IF EXISTS counter;
CREATE TABLE counter (
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
   UNIQUE appsid (appid)
);

#
# Dumping data for table 'counter'
#

INSERT INTO counter VALUES ( '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');
INSERT INTO counter VALUES ( '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');

# --------------------------------------------------------
#
# Table structure for table 'counter_check'
#

DROP TABLE IF EXISTS counter_check;
CREATE TABLE counter_check (
   appid bigint(20) unsigned DEFAULT '0' NOT NULL,
   cnt_type varchar(20) NOT NULL,
   ipaddr varchar(15) DEFAULT '127.000.000.001' NOT NULL,
   creation_cnt timestamp(14)
);

#
# Dumping data for table 'counter_check'
#


# --------------------------------------------------------
#
# Table structure for table 'faq'
#

DROP TABLE IF EXISTS faq;
CREATE TABLE faq (
   faqid int(8) unsigned DEFAULT '0' NOT NULL auto_increment,
   language varchar(24) NOT NULL,
   question blob NOT NULL,
   answer blob NOT NULL,
   UNIQUE idx_2 (faqid)
);

#
# Dumping data for table 'faq'
#

INSERT INTO faq VALUES ('1', 'English', 'How to change my Password or E-mail address I am registered with?', 'Select \"<a href="chguser.php3">Change User</a>\" and enter your new parameters.');
INSERT INTO faq VALUES ('2', 'English', 'I have submitted an announcement but it is not shown?', 'All submissions are verified by a system editor. This will take some time, but it is normally done during the same day you have submitted your announcement.');
INSERT INTO faq VALUES ('3', 'English', 'One of the announcements I have submitted is not longer shown when I use \"Update Apps\"?', 'Another user has changed the announcement and is now the new owner. If you like to change it again, browse the \"<a href=categories.php3>Apps Index</a>\" for the announcement and use the update bottom or select \"<a href=insform.php3>New Apps</a>\" and enter the name of the application you like to change.');
INSERT INTO faq VALUES ('4', 'English', 'Why is the system not in my language?', 'This system can be easily translated into different languages. If you see that we do not have support in your language, you\'re gladly invited to help us with the internationalization. Visit <A HREF=\"http://sourcewell.berlios.de/html/translating.php3\">http://sourcewell.berlios.de/html/translating.php3</A>.');
INSERT INTO faq VALUES ('5', 'English', 'How do I remove an announcement out of SourceWell?', 'Send a message by email to <a href=\"mailto:sourcewell-admin@lists.berlios.de\">sourcewell-admin@lists.berlios.de</a> explaining the reason for removing it. Then we will do it for you. Please do not change announcements by deleting some or all information fields.');
INSERT INTO faq VALUES ('6', 'English', 'Do you send a SourceWell newsletter by e-mail?', 'There are two mailing lists available for everyone to subscribe to. The newsletter is sent once a day or once a week containing all software news of the current day or week. To subscribe, send a message by email to <a href=\"mailto:sourcewell-news-request@lists.berlios.de\">sourcewell-news-request@lists.berlios.de</a> (daily) or <a href=\"mailto:sourcewell-weeklynews-request@lists.berlios.de\">sourcewell-weeklynews-request@lists.berlios.de</a> (weekly) with the subject subscribe or visit <a href=\"http://lists.berlios.de/mailman/listinfo/sourcewell-news\">http://lists.berlios.de/mailman/listinfo/sourcewell-news</a> (daily) or <a href=\"http://lists.berlios.de/mailman/listinfo/sourcewell-weeklynews\">http://lists.berlios.de/mailman/listinfo/sourcewell-weeklynews</a> (weekly)');
INSERT INTO faq VALUES ('7', 'English', 'How do I unsubscribe from the SourceWell newsletter mailing lists? ', 'Send a message by email to <a href=\"mailto:sourcewell-news-request@lists.berlios.de\">sourcewell-news-request@lists.berlios.de</a> (daily) or <a href=\"mailto:sourcewell-weeklynews-request@lists.berlios.de\">sourcewell-weeklynews-request@lists.berlios.de</a> (weekly) with unsubscribe <password> as subject or visit <a href=\"http://lists.berlios.de/mailman/listinfo/sourcewell-news\">http://lists.berlios.de/mailman/listinfo/sourcewell-news</a> (daily) or <a href=\"http://lists.berlios.de/mailman/listinfo/sourcewell-weeklynews\">http://lists.berlios.de/mailman/listinfo/sourcewell-weeklynews</a> (weekly) and follow the instructions there.');


INSERT INTO faq VALUES ('8', 'German', 'Wie ändere ich mein Passwort oder E-Mail-Adresse?', 'Wählen Sie \"<a href=chguser.php3>Benutzer &auml;ndern</a>\" und geben Sie Ihre neuen Daten ein.');
INSERT INTO faq VALUES ('9', 'German', 'Ich habe eine Ankündigung erstellt, die aber nicht erscheint!', 'Alle Ankündigungen werden von einem System-Editor überprüft. Dies kann einige Zeit dauern, aber erfolgt normalerweise innerhalb des gleichen Tages, an dem Sie Ihre Ankündigung erstellt haben.');
INSERT INTO faq VALUES ('10', 'German', 'Eine Ankündigung, die ich erstellt habe, ist nicht länger sichtbar, wenn ich \"Aktualisiere Anw.\" benutze!', 'Ein anderer Benutzer hat die Ankündigung geändert und ist der neuer Besitzer. Wenn Sie sie erneut ändern wollen, suchen Sie im \"<a href=categories.php3>Anw.-Index</a>\" nach der Ankündigung und nutzen den "Aktualisieren"-Knopf oder wählen \"<a href=insform.php3>Neue Anw.</a>\" und geben den Namen der Anwendung ein, die Sie ändern möchten.');
INSERT INTO faq VALUES ('11', 'German', 'Wie wird eine Ankündigung in SourceWell gelöscht?', 'Senden Sie eine Nachricht per E-Mail an den Administrator und erläutern Sie die Gründe für die Löschung. Wir löschen sie dann für Sie. Bitte ändern Sie die Ankündigung nicht durch Löschen einzelner oder aller Informationsfelder.');
INSERT INTO faq VALUES ('12', 'German', 'Warum ist SourceWell nicht in meiner Sprache?', 'SourceWell kann in andere Sprachen sehr einfach &uuml;bersetzt werden. Wenn Sie sehen, dass SourceWell ihre Sprache nicht unterst&uuml;tzt, dann sind Sie herzlich eingeladen, uns bei der Internationalisation zu helfen. Besuchen Sie <A HREF=\"http://sourcewell.berlios.de/html/translating.php3\">http://sourcewell.berlios.de/html/translating.php3</A>');
INSERT INTO faq VALUES ('13', 'German', 'Gibt es einen SourceWell-Newsletter, der per E-Mail verschickt wird?', 'Es existiert zwei Mailing-Listen, die jeder abonnieren kann. Der Newsletter wird einmal täglich bzw. einmal wöchentlich verschickt und enthält alle Ankündigungen des laufenden Tages bzw. der letzten Woche. Zum Abonnieren senden Sie eine Nachricht per E-Mail an <a href=\"mailto:sourcewell-news-request@lists.berlios.de\">sourcewell-news-request@lists.berlios.de</a> (täglich) oder <a href=\"mailto:sourcewell-weeklynews-request@lists.berlios.de\">sourcewell-weeklynews-request@lists.berlios.de</a> (wöchentlich) mit dem Subjekt subscribe oder besuchen Sie <a href=\"http://lists.berlios.de/mailman/listinfo/sourcewell-news\">http://lists.berlios.de/mailman/listinfo/sourcewell-news</a> (täglich) bzw. <a href=\"http://lists.berlios.de/mailman/listinfo/sourcewell-news\">http://lists.berlios.de/mailman/listinfo/sourcewell-news</a> (wöchentlich). ');
INSERT INTO faq VALUES ('14', 'German', 'Wie bestelle ich den SourceWell-Newsletter ab?', 'Senden Sie eine Nachricht per E-Mail an <a href=\"mailto:sourcewell-news-request@lists.berlios.de\">sourcewell-news-request@lists.berlios.de</a> (täglich) bzw. <a href=\"mailto:sourcewell-weeklynews-request@lists.berlios.de\">sourcewell-weeklynews-request@lists.berlios.de</a> (wöchentlich) mit unsubscribe <password> als Subjekt oder besuchen Sie <a href=\"http://lists.berlios.de/mailman/listinfo/sourcewell-news\">http://lists.berlios.de/mailman/listinfo/sourcewell-news</a> (täglich) bzw. <a href=\"http://lists.berlios.de/mailman/listinfo/sourcewell-weeklynews\">http://lists.berlios.de/mailman/listinfo/sourcewell-weeklynews</a> (wöchentlich) und führen die dort beschriebenen Instruktionen aus.');

INSERT INTO faq VALUES ('15', 'Spanish', '&iquest;C&oacute;mo puedo cambiar mi contrase&ntilde;a o la direcci&oacute;n de correo-e con la que estoy registrado?', 'Seleccione \"<a href=chguser.php3>Modificar Registro</a>\" e introduzca los nuevos par&aacute;metros.');
INSERT INTO faq VALUES ('16', 'Spanish', 'He enviado una notificaci&oacute;n, pero todav&iacute;a no se muestra. &iquest;Por qu&eacute;?', 'Todas las notificaciones han de ser verificadas y validadas por un editor. Esto puede llevar algo de tiempo, pero normalmente se hace el mismo d&iacute;a de la notificaci&oacute;n.');
INSERT INTO faq VALUES ('17', 'Spanish', 'Una de las notificaciones que he enviado no se muestra cuando utilizo \"Actualizar\". &iquest;A qu&eacute; se debe?', 'Otro usuario ha cambiado la notificaci&oacute;n y ha pasado a ser su autor. Si desea cambiarla de nuevo, utilice el \"<a href=categories.php3>&Iacute;ndice</a>\" para ver las notificaciones y, una vez haya encontrado la aplicaci&oacute;n en cuesti&oacute;n, haga click sobre el bot&oacute;n de \"Actualizar\"');
INSERT INTO faq VALUES ('18', 'Spanish', '&iquest;C&oacute;mo puedo borrar una notificaci&oacute;n hecha en SourceWell?', 'Mande un mensaje de correo-e al administrador del sistema explicando la raz&oacute;n para borrarlo. Una vez hecho esto, nosotros lo haremos por usted. Por favor, no cambie las notificaciones borrando alguno o todos los campos de informaci&oacute;n.');
INSERT INTO faq VALUES ('19', 'Spanish', '&iquest;Por qu&eacute; no est&aacute; SourceWell en mi idioma?', 'SourceWell puede ser traducido de una manera bastante sencilla a otros idiomas. Si ve que SourceWell no tiene soporte para su idioma, est&aacute; gratamente invitado a ayudarnos con la internacionalizaci&oacute;n. Visite <A HREF=\"http://sourcewell.berlios.de/html/translating.php3\">http://sourcewell.berlios.de/html/translating.php3</A>.');
INSERT INTO faq VALUES ('20', 'Spanish', '¿SourceWell envía correos-e con las noticias del día?', 'Sí. Existen dos listas de correo-e para todo aquel que quiera suscribirse. Las noticias serán enviadas según la lista de la que se trate una vez al día o una vez a la semana. Para suscribirse mande un mensaje de correo-e a <a href=\"mailto:sourcewell-news-request@lists.berlios.de\">sourcewell-news-request@lists.berlios.de</a> (diaria) o <a href=\"mailto:sourcewell-weeklynews-request@lists.berlios.de\">sourcewell-weeklynews-request@lists.berlios.de</a> (semanal) con el título subscribe o visite <a href=\"http://lists.berlios.de/mailman/listinfo/sourcewell-news\">http://lists.berlios.de/mailman/listinfo/sourcewell-news</a> (diaria) o <a href=\"\http://lists.berlios.de/mailman/listinfo/sourcewell-weeklynews">http://lists.berlios.de/mailman/listinfo/sourcewell-weeklynews</a> (semanal)');
INSERT INTO faq VALUES ('21', 'Spanish', '¿Cómo me puedo dar de baja de la lista de noticas SourceWell?', 'Mande un mensaje de correo-e a <a href=\"mailto:sourcewell-news-request@lists.berlios.de\">sourcewell-news-request@lists.berlios.de</a> (diaria) o <a href=\"mailto:sourcewell-weeklynews-request@lists.berlios.de\">sourcewell-weeklynews-request@lists.berlios.de</a> (semanal) con la palabra unsubscribe <password> en el título o visite <a href=\"http://lists.berlios.de/mailman/listinfo/sourcewell-news\">http://lists.berlios.de/mailman/listinfo/sourcewell-news</a> y proceda según se le indica allí.');

#INSERT INTO faq VALUES ('', '', '', '');

# --------------------------------------------------------
#
# Table structure for table 'history'
#

DROP TABLE IF EXISTS history;
CREATE TABLE history (
   idx_his bigint(20) DEFAULT '0' NOT NULL auto_increment,
   appid bigint(20) DEFAULT '0' NOT NULL,
   user_his varchar(16) NOT NULL,
   creation_his timestamp(14),
   version_his varchar(16) NOT NULL,
   UNIQUE idx_2 (idx_his)
);

#
# Dumping data for table 'history'
#

INSERT INTO history VALUES ( '1', '1', 'anonymous', '20010403151520', '1.0');
INSERT INTO history VALUES ( '2', '1', 'anonymous', '20010417121122', '1.0a = 1.0.5');
INSERT INTO history VALUES ( '3', '1', 'anonymous', '20010420173045', '1.0.6');
INSERT INTO history VALUES ( '4', '1', 'anonymous', '20010423162534', '1.0.7');
INSERT INTO history VALUES ( '5', '1', 'anonymous', '20010425181410', '1.0.8');
INSERT INTO history VALUES ( '6', '2', 'anonymous', '20010628174629', '0.8');
INSERT INTO history VALUES ( '7', '1', 'anonymous', '20010629170128', '1.0.9');
INSERT INTO history VALUES ( '8', '1', 'anonymous', '20011129183128', '1.0.10');

# --------------------------------------------------------
#
# Table structure for table 'licenses'
#

DROP TABLE IF EXISTS licenses;
CREATE TABLE licenses (
   license varchar(64) NOT NULL,
   url varchar(255) NOT NULL
);

INSERT INTO licenses VALUES ( 'Artifex Public License (AFPL)', 'http://web.mit.edu/ghostscript/www/Public.htm');
INSERT INTO licenses VALUES ( 'Apache style', 'http://www.apache.org/docs-2.0/LICENSE');
INSERT INTO licenses VALUES ( 'Artistic & GPL', 'http://www.perl.com/language/misc/Artistic.html');
INSERT INTO licenses VALUES ( 'BSD type', 'http://www.freebsd.org/copyright/license.html');
INSERT INTO licenses VALUES ( 'commercial', 'licnotavailable.php3');
INSERT INTO licenses VALUES ( 'Eiffel Forum Freeware License', 'http://www.eiffel-forum.org/license/index.htm#efl');
INSERT INTO licenses VALUES ( 'free for non-commercial use', 'licnotavailable.php3');
INSERT INTO licenses VALUES ( 'Free Trail', 'licnotavailable.php3');
INSERT INTO licenses VALUES ( 'freely distributable', 'licnotavailable.php3');
INSERT INTO licenses VALUES ( 'Freeware', 'http://sourcewell.berlios.de/licnotavailable.php3');
INSERT INTO licenses VALUES ( 'GPL', 'http://www.gnu.org/copyleft/gpl.html');
INSERT INTO licenses VALUES ( 'LGPL', 'http://www.gnu.org/copyleft/lesser.html');
INSERT INTO licenses VALUES ( 'MIT', 'licnotavailable.php3');
INSERT INTO licenses VALUES ( 'Mozilla Public License (MPL)', 'http://www.mozilla.org/MPL/');
INSERT INTO licenses VALUES ( 'Open Source', 'http://www.opensource.org/osd.html');
INSERT INTO licenses VALUES ( 'Public Domain', 'http://www.eiffel-forum.org/license/index.htm#pd');
INSERT INTO licenses VALUES ( 'Q Public License (QPL)', 'http://www.trolltech.com/products/download/freelicense/license.html');
INSERT INTO licenses VALUES ( 'Shareware', 'licnotavailable.php3');
INSERT INTO licenses VALUES ( 'source-available commercial', 'licnotavailable.php3');
INSERT INTO licenses VALUES ( 'FreeBSD', 'http://www.freebsd.org/copyright/freebsd-license.html');
INSERT INTO licenses VALUES ( 'OpenBSD', 'http://www.openbsd.org/policy.html');
INSERT INTO licenses VALUES ( 'UCL/LBL', 'licnotavailable.php3');
INSERT INTO licenses VALUES ( 'Other', 'licnotavailable.php3');
INSERT INTO licenses VALUES ( 'Artistic License', 'http://www.perl.com/language/misc/Artistic.html');
INSERT INTO licenses VALUES ( 'PHP License', 'http://www.php.net/license.html');
INSERT INTO licenses VALUES ( 'free to use but restricted', 'licnotavailable.php3');
INSERT INTO licenses VALUES ( 'X11 License', 'http://www.x.org/terms.htm');
INSERT INTO licenses VALUES ( 'Cryptix General License', 'http://www.cryptix.org/docs/license.html');
INSERT INTO licenses VALUES ( 'Zlib License', 'ftp://ftp.freesoftware.com/pub/infozip/zlib/zlib_license.html');
INSERT INTO licenses VALUES ( 'W3C Software', 'http://www.w3.org/Consortium/Legal/copyright-software-19980720');
INSERT INTO licenses VALUES ( 'Berkeley Database License', 'http://www.sleepycat.com/license.net');
INSERT INTO licenses VALUES ( 'Clarified Artistic License', 'http://www.appwatch.com/license/ncftp-3.0.2.txt');
INSERT INTO licenses VALUES ( 'Netscape Public License (NPL)', 'http://www.mozilla.org/MPL/NPL-1.0.html');
INSERT INTO licenses VALUES ( 'Arphic Public License', 'ftp://ftp.gnu.org/non-gnu/chinese-fonts-truetype/LICENSE');
INSERT INTO licenses VALUES ( 'Zope Public License (ZPL)', 'http://www.zope.com/Resources/ZPL');
INSERT INTO licenses VALUES ( 'IBM Public License', 'http://oss.software.ibm.com/developerworks/opensource/license10.html');
INSERT INTO licenses VALUES ( 'Phorum', 'http://phorum.org/license.txt');
INSERT INTO licenses VALUES ( 'Interbase Public License', 'http://www.borland.com/interbase/IPL.html');
INSERT INTO licenses VALUES ( 'Sun Public License', 'http://www.netbeans.org/spl.html');
INSERT INTO licenses VALUES ( 'Jabber Open Source License', 'http://www.jabber.com/license/index.shtml');
INSERT INTO licenses VALUES ( 'Open Compability License', 'http://www.gizmodrome.com/opencompatibilitylicense.htm');
INSERT INTO licenses VALUES ( 'Plan 9 Open Source License', 'http://plan9.bell-labs.com/plan9dist/license.html');
INSERT INTO licenses VALUES ( 'Sun Community Source License', 'http://www.sun.com/981208/scsl/principles.html;$sessionid$RNI1GOQAAB3PHAMTA1LU5YQ');
INSERT INTO licenses VALUES ( 'FreeType License', 'http://v.hbi-stuttgart.de/doku/packages/freetype/license.txt');
INSERT INTO licenses VALUES ( 'LaTeXProject Public License', 'http://www.latex-project.org/lppl.html');

# --------------------------------------------------------
#
# Table structure for table 'software'
#

DROP TABLE IF EXISTS software;
CREATE TABLE software (
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
);

#
# Dumping data for table 'software'
#


INSERT INTO software VALUES ( '1', 'SourceWell', 'D', '1.0.10', 'Networking', 'PHP', 'GPL', 'http://sourcewell.berlios.de/html/', 'http://developer.berlios.de/project/filelist.php?group_id=23', 'http://sourcewell.berlios.de/doc/CHANGELOG', '', '', '', 'http://cvs.berlios.de/cgi-bin/cvsweb.cgi/?cvsroot=sourcewell', 'http://sourcewell.berlios.de', 'http://lists.berlios.de/pipermail/sourcewell-support/', 'Lutz Henckel & Gregorio Robles', 'SourceWell is a highly configurable, well documented software announcement and retrieval system entirely writen in PHP3 and database independent. It includes user authentication and autherization system (anonymous/user/editor/admin), sessions with and without cookies, high configurability, multilangual support, ease of administration, RDF-type document backend, advanced statistics, announcing mailing lists, application indexing by sections and many other useful features.', '20011129183128', '20010403163452', 'sourcewell-support@lists.berlios.de', 'PHP3, PHPLib, database, (Mailman)', 'anonymous', 'A', '3');


# --------------------------------------------------------
#
# Table structure for table 'software'
#

DROP TABLE IF EXISTS temp;
CREATE TABLE temp (
   appid bigint(20) NOT NULL,  # FK from table software
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
   status char(1) DEFAULT 'P' NOT NULL,
   urgency int(11) DEFAULT '2' NOT NULL
);

#
# Dumping data for table 'temp'
#
