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
'oldfish', 'oldfish', 'Change Username and Password!', 'admin@your.system', '20010401162518', '20010401162518', 'user,editor,admin');


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

INSERT INTO categories VALUES ( 'Console', 'CD Writing');
INSERT INTO categories VALUES ( 'Console', 'Databases');
INSERT INTO categories VALUES ( 'Console', 'Editors');
INSERT INTO categories VALUES ( 'Console', 'File & Disk Management');
INSERT INTO categories VALUES ( 'Console', 'Graphics');
INSERT INTO categories VALUES ( 'Console', 'Utilities');
INSERT INTO categories VALUES ( 'Console', 'Miscellaneous');
INSERT INTO categories VALUES ( 'Development', 'Application & Software Development');
INSERT INTO categories VALUES ( 'Development', 'Languages');
INSERT INTO categories VALUES ( 'Development', 'Libraries & Classes');
INSERT INTO categories VALUES ( 'Development', 'Miscellaneous');
INSERT INTO categories VALUES ( 'Development', 'Utilities');
INSERT INTO categories VALUES ( 'GNOME', 'Applications');
INSERT INTO categories VALUES ( 'GNOME', 'Core');
INSERT INTO categories VALUES ( 'GNOME', 'CD Writing');
INSERT INTO categories VALUES ( 'GNOME', 'Development');
INSERT INTO categories VALUES ( 'GNOME', 'Games');
INSERT INTO categories VALUES ( 'GNOME', 'Graphics');
INSERT INTO categories VALUES ( 'GNOME', 'Miscellaneous');
INSERT INTO categories VALUES ( 'GNOME', 'Networking');
INSERT INTO categories VALUES ( 'GNOME', 'Multimedia');
INSERT INTO categories VALUES ( 'GNOME', 'System Utilities');
INSERT INTO categories VALUES ( 'GNOME', 'Utilities');
INSERT INTO categories VALUES ( 'KDE', 'Applications');
INSERT INTO categories VALUES ( 'KDE', 'Core');
INSERT INTO categories VALUES ( 'KDE', 'CD Writing');
INSERT INTO categories VALUES ( 'KDE', 'Development');
INSERT INTO categories VALUES ( 'KDE', 'Games');
INSERT INTO categories VALUES ( 'KDE', 'Graphics');
INSERT INTO categories VALUES ( 'KDE', 'Miscellaneous');
INSERT INTO categories VALUES ( 'KDE', 'Multimedia');
INSERT INTO categories VALUES ( 'KDE', 'Networking');
INSERT INTO categories VALUES ( 'KDE', 'System Utilities');
INSERT INTO categories VALUES ( 'KDE', 'Utilities');
INSERT INTO categories VALUES ( 'Kernel', 'Linux Ports');
INSERT INTO categories VALUES ( 'Kernel', 'Sources');
INSERT INTO categories VALUES ( 'Networking', 'Administration');
INSERT INTO categories VALUES ( 'Networking', 'E-Mail');
INSERT INTO categories VALUES ( 'Networking', 'Fax');
INSERT INTO categories VALUES ( 'Networking', 'File Transfer');
INSERT INTO categories VALUES ( 'Networking', 'HTML Tool');
INSERT INTO categories VALUES ( 'Networking', 'Miscellaneous');
INSERT INTO categories VALUES ( 'Networking', 'News');
INSERT INTO categories VALUES ( 'Networking', 'PHP');
INSERT INTO categories VALUES ( 'Networking', 'Servers');
INSERT INTO categories VALUES ( 'Networking', 'SMS & WAP');
INSERT INTO categories VALUES ( 'Networking', 'Web Browser');
INSERT INTO categories VALUES ( 'Networking', 'Web Development');
INSERT INTO categories VALUES ( 'X11', 'CD Writing');
INSERT INTO categories VALUES ( 'X11', 'Databases');
INSERT INTO categories VALUES ( 'X11', 'Desktop, File & Disk Managers');
INSERT INTO categories VALUES ( 'X11', 'Editors');
INSERT INTO categories VALUES ( 'X11', 'Games');
INSERT INTO categories VALUES ( 'X11', 'Graphics');
INSERT INTO categories VALUES ( 'X11', 'Multimedia');
INSERT INTO categories VALUES ( 'X11', 'Personal Desktop Tools');
INSERT INTO categories VALUES ( 'X11', 'Server');
INSERT INTO categories VALUES ( 'X11', 'System Utilities');
INSERT INTO categories VALUES ( 'X11', 'Miscellaneous');
INSERT INTO categories VALUES ( 'X11', 'Window Manager');

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

INSERT INTO comments VALUES ( '1', 'oldfish', 'We use SourceWell successfully', 'You can visit our web site at <A
HREF="http://sourcewell.berlios.de">http://sourcewell.berlios.de</a>
where we have been using the SourceWell system succesfully for more
than three months yet. There are now more than 750 applications
announced in our system. A look a at it will let you see how far you
can go with it!', '20010402162952');


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

INSERT INTO history VALUES ( '1', '1', 'oldfish', '20010402121122', '1.0');

# --------------------------------------------------------
#
# Table structure for table 'licenses'
#

DROP TABLE IF EXISTS licenses;
CREATE TABLE licenses (
   license varchar(64) NOT NULL,
   url varchar(255) NOT NULL
);

#
# Dumping data for table 'licenses'
#

INSERT INTO licenses VALUES ( 'Apache style', 'http://www.apache.org/docs-2.0/LICENSE');
INSERT INTO licenses VALUES ( 'BSD type', 'http://www.freebsd.org/copyright/license.html');
INSERT INTO licenses VALUES ( 'commercial', 'http://sourcewell.berlios.de/licnotavailable.php3');
INSERT INTO licenses VALUES ( 'free for non-commercial use', 'http://sourcewell.berlios.de/licnotavailable.php3');
INSERT INTO licenses VALUES ( 'Free Trail', 'http://sourcewell.berlios.de/licnotavailable.php3');
INSERT INTO licenses VALUES ( 'freely distributable', 'http://sourcewell.berlios.de/licnotavailable.php3');
INSERT INTO licenses VALUES ( 'Freeware', 'http://sourcewell.berlios.de/licnotavailable.php3');
INSERT INTO licenses VALUES ( 'GPL', 'http://www.gnu.org/copyleft/gpl.html');
INSERT INTO licenses VALUES ( 'LGPL', 'http://www.gnu.org/copyleft/lesser.html');
INSERT INTO licenses VALUES ( 'MIT', 'http://sourcewell.berlios.de/licnotavailable.php3');
INSERT INTO licenses VALUES ( 'MPL', 'http://www.mozilla.org/MPL/');
INSERT INTO licenses VALUES ( 'Open Source', 'http://www.opensource.org/osd.html');
INSERT INTO licenses VALUES ( 'Public Domain', 'http://www.eiffel-forum.org/license/index.htm#pd');
INSERT INTO licenses VALUES ( 'FreeBSD', 'http://www.freebsd.org/copyright/freebsd-license.html');
INSERT INTO licenses VALUES ( 'OpenBSD', 'http://www.openbsd.org/policy.html');
INSERT INTO licenses VALUES ( 'Other', 'http://sourcewell.berlios.de/licnotavailable.php3');
INSERT INTO licenses VALUES ( 'Artistic License', 'http://www.perl.com/language/misc/Artistic.html');
INSERT INTO licenses VALUES ( 'PHP License', 'http://www.php.net/license.html');
INSERT INTO licenses VALUES ( 'free to use but restricted', 'http://sourcewell.berlios.de/licnotavailable.php3');
INSERT INTO licenses VALUES ( 'X11 License', 'http://www.x.org/terms.htm');
INSERT INTO licenses VALUES ( 'Zope Public License', 'http://www.zope.com/Resources/ZPL');
INSERT INTO licenses VALUES ( 'IBM Public License', 'http://oss.software.ibm.com/developerworks/opensource/license10.html');
INSERT INTO licenses VALUES ( 'Shareware', 'http://sourcewell.berlios.de/licnotavailable.php3');

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

INSERT INTO software VALUES ( '1', 'SourceWell', 'S', '1.0',
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
'lutz.henckel@fokus.gmd.de', 'PHP3, MySQL, PHPLib, (Mailman)', 'oldfish', 'A', '2');
