-- Database sourcewell
-- phpMyAdmin MySQL-Dump
-- http://phpwizard.net/phpMyAdmin/
--
-- SourceWell Version 1.0.8
--	     Lutz Henckel <lutz.henckel@fokus.gmd.de>
--	     Gregorio Robles <grex@scouts-es.org>
--
-- For more information about the database structure
-- have a look at the SourceWell documentation
--
-- Database: sourcewell

CREATE SEQUENCE appid_seq;
CREATE SEQUENCE faqid_seq;
CREATE SEQUENCE idx_his_seq;

-- ******************************************************--
--
-- Table structure for table 'active_sessions'
--

DROP TABLE active_sessions;
CREATE TABLE active_sessions (
   sid varchar(128) NOT NULL,
   name varchar(128) NOT NULL,
   val varchar(128),
   changed varchar(128) NOT NULL,
   PRIMARY KEY (name, sid)
);

-- ******************************************************--
--
-- Table structure for table 'auth_user'
--

DROP TABLE auth_user;
CREATE TABLE auth_user (
   user_id varchar(128) NOT NULL,
   username varchar(128) NOT NULL,
   password varchar(128) NOT NULL,
   realname varchar(128) NOT NULL,
   email_usr varchar(128) NOT NULL,
   modification_usr date,
   creation_usr date,
   perms varchar(128),
   PRIMARY KEY (user_id)
);

--
-- Dumping data for table 'auth_user'
--

INSERT INTO auth_user VALUES ( 'c8a174e0bdda2011ff798b20f219adc5',
'oldfish', 'oldfish', 'Change Username and Password!', 'admin@your.system', '20010417103000', '20010417103000', 'user,editor,admin');
INSERT INTO auth_user VALUES ( '9608a4062d05bad564b3b8fe6aaac481', 'anonymous', 'anonymous', 'Anonymous User', 'nobody@nowhere.com',  '20010417104500', '20010417104500', 'anonymous');


-- ******************************************************--
--
-- Table structure for table 'categories'
--

DROP TABLE categories;
CREATE TABLE categories (
   section varchar(128) NOT NULL,
   category varchar(128) NOT NULL,
   PRIMARY KEY (section,category)
);

--
-- Dumping data for table 'categories'
--

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

-- ******************************************************--
--
-- Table structure for table 'comments'
--

DROP TABLE comments;
CREATE TABLE comments (
   appid int4 DEFAULT '0' NOT NULL,
   user_cmt varchar(128) NOT NULL,
   subject_cmt varchar(128) NOT NULL,
   varchar(128)_cmt varchar(128) NOT NULL,
   creation_cmt date,
   PRIMARY KEY (subject_cmt, creation_cmt)
);

--
-- Dumping data for table 'comments'
--

INSERT INTO comments VALUES ( '1', 'oldfish', 'We use SourceWell successfully!', 'You can visit our web site at <A
HREF="http://sourcewell.berlios.de">http://sourcewell.berlios.de</a>
where we have been using the SourceWell system succesfully for more
than three months yet. You will find more than 800 applications
announced in our system. A closer look a at it will let you see how far you
can go with it!', '20010417133952');


-- ******************************************************--
--
-- Table structure for table 'counter'
--

DROP TABLE counter;
CREATE TABLE counter (
   appid int4 DEFAULT '0' NOT NULL,
   app_cnt int4 DEFAULT '0' NOT NULL,
   homepage_cnt int4 DEFAULT '0' NOT NULL,
   download_cnt int4 DEFAULT '0' NOT NULL,
   changelog_cnt int4 DEFAULT '0' NOT NULL,
   rpm_cnt int4 DEFAULT '0' NOT NULL,
   deb_cnt int4 DEFAULT '0' NOT NULL,
   tgz_cnt int4 DEFAULT '0' NOT NULL,
   cvs_cnt int4 DEFAULT '0' NOT NULL,
   screenshots_cnt int4 DEFAULT '0' NOT NULL,
   mailarch_cnt int4 DEFAULT '0' NOT NULL,
   UNIQUE appsid (appid)
);

--
-- Dumping data for table 'counter'
--

INSERT INTO counter VALUES ( '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');

-- ******************************************************--
--
-- Table structure for table 'counter_check'
--

DROP TABLE counter_check;
CREATE TABLE counter_check (
   appid int4 DEFAULT '0' NOT NULL,
   cnt_type varchar(128) NOT NULL,
   ipaddr varchar(128) DEFAULT '127.000.000.001' NOT NULL,
   creation_cnt date
);

--
-- Dumping data for table 'counter_check'
--


-- ******************************************************--
--
-- Table structure for table 'faq'
--

DROP TABLE faq;
CREATE TABLE faq (
   faqid int4 DEFAULT nextval('faqid_seq',
   question varchar(128) NOT NULL,
   answer varchar(128) NOT NULL,
   PRIMARY KEY (faqid)
);

--
-- Dumping data for table 'faq'
--

INSERT INTO faq VALUES ('1', 'How to change my Password or E-mail address I am registered with?', 'Select \"<a href="chguser.php3">Change User</a>\" and enter your new parameters.');
INSERT INTO faq VALUES ('2', 'I have submitted an announcement but it is not shown?', 'All submissions are verified by a system editor. This will take some time, but it is normally done during the same day you have submitted your announcement.');
INSERT INTO faq VALUES ('3', 'One of the announcements I have submitted is not longer shown when I use \"Update Apps\"?', 'Another user has changed the announcement and is now the new owner. If you like to change it again, browse the \"<a href=categories.php3>Apps Index</a>\" for the announcement and use the update bottom or select \"<a href=insform.php3>New Apps</a>\" and enter the name of the application you like to change.');
INSERT INTO faq VALUES ('4', 'Why is the system not in my language?', 'This system can be easily translated into different languages. If you see that we do not have support in your language, you\'re gladly invited to help us with the internationalization. Visit <A HREF=\"http://sourcewell.berlios.de/html/translating.php3\">http://sourcewell.berlios.de/html/translating.php3</A>.');

-- ******************************************************--
--
-- Table structure for table 'history'
--

DROP TABLE history;
CREATE TABLE history (
   idx_his int4 DEFAULT nextval('idx_his_seq'),
   appid int4 DEFAULT '0' NOT NULL,
   user_his varchar(128) NOT NULL,
   creation_his date,
   version_his varchar(128) NOT NULL,
   PRIMARY KEY (idx_his)
);

--
-- Dumping data for table 'history'
--

INSERT INTO history VALUES ( '1', '1', 'oldfish', '20010403151520', '1.0');
INSERT INTO history VALUES ( '2', '1', 'oldfish', '20010417121122', '1.0a = 1.0.5');
INSERT INTO history VALUES ( '3', '1', 'oldfish', '20010420173045', '1.0.6');
INSERT INTO history VALUES ( '4', '1', 'oldfish', '20010423162534', '1.0.7');
INSERT INTO history VALUES ( '5', '1', 'oldfish', '20010425181410', '1.0.8');

-- ******************************************************--
--
-- Table structure for table 'licenses'
--

DROP TABLE licenses;
CREATE TABLE licenses (
   license varchar(128) NOT NULL,
   url varchar(128) NOT NULL,
   PRIMARY KEY ( license )
);

--
-- Dumping data for table 'licenses'
--

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
INSERT INTO licenses VALUES ( 'Public Domain', 'http://www.eiffel-forum.org/license/index.htm--pd');
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

-- ******************************************************--
--
-- Table structure for table 'software'
--

DROP TABLE software;
CREATE TABLE software (
   appid int4 DEFAULT nextval('appid_seq'),
   name varchar(128) NOT NULL,
   type char(1) NOT NULL,
   version varchar(128) NOT NULL,
   section varchar(128) NOT NULL,
   category varchar(128) NOT NULL,
   license varchar(128) NOT NULL,
   homepage varchar(128) NOT NULL,
   download varchar(128),
   changelog varchar(128),
   rpm varchar(128),
   deb varchar(128),
   tgz varchar(128),
   cvs varchar(128),
   screenshots varchar(128),
   mailarch varchar(128),
   developer varchar(128) NOT NULL,
   description varchar(128) NOT NULL,
   modification date,
   creation date,
   email tex NOT NULL,
   depend varchar(128) NOT NULL,
   user varchar(128) NOT NULL,
   status char(1) NOT NULL,
   urgency int(11) DEFAULT '2' NOT NULL,
   PRIMARY KEY (appid)
);

--
-- Dumping data for table 'software'


INSERT INTO software VALUES ( '1', 'SourceWell', 'D', '1.0.8', 'Networking', 'PHP', 'GPL', 'http://sourcewell.berlios.de/html/', 'http://developer.berlios.de/project/filelist.php?group_id=23', 'http://sourcewell.berlios.de/doc/CHANGELOG', '', '', '', 'http://cvs.berlios.de/cgi-bin/cvsweb.cgi/?cvsroot=sourcewell', 'http://sourcewell.berlios.de', 'http://lists.berlios.de/pipermail/sourcewell-support/', 'Lutz Henckel & Gregorio Robles', 'SourceWell is a highly configurable, well documented software announcement and retrieval system entirely writen in PHP3 and database independent. It includes user authentication and autherization system (anonymous/user/editor/admin), sessions with and without cookies, high configurability, multilangual support, ease of administration, RDF-type document backend, advanced statistics, announcing mailing lists, application indexing by sections and many other useful features.', '20010425181410', '20010403163452', 'sourcewell-support@lists.berlios.de', 'PHP3, PHPLib, database, (Mailman)', 'oldfish', 'A', '3');
