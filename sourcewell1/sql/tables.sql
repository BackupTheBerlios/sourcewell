# Host: localhost
# Generation Time: Oct 08, 2002 at 12:13 PM
# Server version: 3.23.52
# PHP Version: 4.2.2
# Database : `sourcewell`
# --------------------------------------------------------

USE sourcewell;

#
# Table structure for table `active_sessions`
#

CREATE TABLE active_sessions (
  sid varchar(32) NOT NULL default '',
  name varchar(32) NOT NULL default '',
  val text,
  changed varchar(14) NOT NULL default '',
  PRIMARY KEY  (name,sid),
  KEY changed (changed)
) TYPE=MyISAM;
# --------------------------------------------------------

#
# Table structure for table `auth_user`
#

CREATE TABLE auth_user (
  user_id varchar(32) NOT NULL default '',
  username varchar(32) NOT NULL default '',
  password varchar(32) NOT NULL default '',
  realname varchar(64) NOT NULL default '',
  email_usr varchar(128) NOT NULL default '',
  modification_usr timestamp(14) NOT NULL,
  creation_usr timestamp(14) NOT NULL,
  perms varchar(255) default NULL,
  PRIMARY KEY  (user_id),
  UNIQUE KEY k_username (username)
) TYPE=MyISAM;
# --------------------------------------------------------

#
# Table structure for table `categories`
#

CREATE TABLE categories (
  section varchar(64) NOT NULL default '',
  category varchar(64) NOT NULL default ''
) TYPE=MyISAM;
# --------------------------------------------------------

#
# Table structure for table `comments`
#

CREATE TABLE comments (
  appid bigint(20) unsigned NOT NULL default '0',
  user_cmt varchar(32) NOT NULL default '',
  subject_cmt varchar(128) NOT NULL default '',
  text_cmt blob NOT NULL,
  creation_cmt timestamp(14) NOT NULL
) TYPE=MyISAM;
# --------------------------------------------------------

#
# Table structure for table `counter`
#

CREATE TABLE counter (
  appid bigint(20) unsigned NOT NULL default '0',
  app_cnt int(11) NOT NULL default '0',
  homepage_cnt int(11) NOT NULL default '0',
  download_cnt int(11) NOT NULL default '0',
  changelog_cnt int(11) NOT NULL default '0',
  rpm_cnt int(11) NOT NULL default '0',
  deb_cnt int(11) NOT NULL default '0',
  tgz_cnt int(11) NOT NULL default '0',
  cvs_cnt int(11) NOT NULL default '0',
  screenshots_cnt int(11) NOT NULL default '0',
  mailarch_cnt int(11) NOT NULL default '0',
  PRIMARY KEY  (appid)
) TYPE=MyISAM;
# --------------------------------------------------------

#
# Table structure for table `counter_check`
#

CREATE TABLE counter_check (
  appid bigint(20) unsigned NOT NULL default '0',
  cnt_type varchar(20) NOT NULL default '',
  ipaddr varchar(15) NOT NULL default '127.000.000.001',
  creation_cnt timestamp(14) NOT NULL
) TYPE=MyISAM;
# --------------------------------------------------------

#
# Table structure for table `faq`
#

CREATE TABLE faq (
  faqid int(8) unsigned NOT NULL auto_increment,
  language varchar(24) NOT NULL default '',
  question blob NOT NULL,
  answer blob NOT NULL,
  PRIMARY KEY  (faqid)
) TYPE=MyISAM;
# --------------------------------------------------------

#
# Table structure for table `history`
#

CREATE TABLE history (
  idx_his bigint(20) NOT NULL auto_increment,
  appid bigint(20) NOT NULL default '0',
  user_his varchar(32) NOT NULL default '',
  creation_his timestamp(14) NOT NULL,
  version_his varchar(64) NOT NULL default '',
  PRIMARY KEY  (idx_his)
) TYPE=MyISAM;
# --------------------------------------------------------

#
# Table structure for table `licenses`
#

CREATE TABLE licenses (
  license varchar(64) NOT NULL default '',
  url varchar(255) NOT NULL default ''
) TYPE=MyISAM;
# --------------------------------------------------------

#
# Table structure for table `pending`
#

CREATE TABLE pending (
  idx bigint(20) NOT NULL auto_increment,
  appid bigint(20) NOT NULL default '0',
  name varchar(128) NOT NULL default '',
  type char(1) NOT NULL default '',
  version varchar(16) NOT NULL default '',
  section varchar(64) NOT NULL default '',
  category varchar(64) NOT NULL default '',
  license varchar(64) NOT NULL default '',
  homepage varchar(255) NOT NULL default '',
  download varchar(255) default NULL,
  changelog varchar(255) default NULL,
  rpm varchar(255) default NULL,
  deb varchar(255) default NULL,
  tgz varchar(255) default NULL,
  cvs varchar(255) default NULL,
  screenshots varchar(255) default NULL,
  mailarch varchar(255) default NULL,
  developer varchar(64) NOT NULL default '',
  description blob NOT NULL,
  modification timestamp(14) NOT NULL,
  creation timestamp(14) NOT NULL,
  email varchar(128) NOT NULL default '',
  depend varchar(128) NOT NULL default '',
  user varchar(32) NOT NULL default '',
  status char(1) NOT NULL default 'P',
  urgency int(11) NOT NULL default '2',
  PRIMARY KEY  (idx)
) TYPE=MyISAM;
# --------------------------------------------------------

#
# Table structure for table `software`
#

CREATE TABLE software (
  appid bigint(20) unsigned NOT NULL auto_increment,
  name varchar(128) NOT NULL default '',
  type char(1) NOT NULL default '',
  version varchar(64) NOT NULL default '',
  section varchar(64) NOT NULL default '',
  category varchar(64) NOT NULL default '',
  license varchar(64) NOT NULL default '',
  homepage varchar(255) NOT NULL default '',
  download varchar(255) default NULL,
  changelog varchar(255) default NULL,
  rpm varchar(255) default NULL,
  deb varchar(255) default NULL,
  tgz varchar(255) default NULL,
  cvs varchar(255) default NULL,
  screenshots varchar(255) default NULL,
  mailarch varchar(255) default NULL,
  developer varchar(64) NOT NULL default '',
  description blob NOT NULL,
  modification timestamp(14) NOT NULL,
  creation timestamp(14) NOT NULL,
  email varchar(128) NOT NULL default '',
  depend varchar(128) NOT NULL default '',
  user varchar(32) NOT NULL default '',
  status char(1) NOT NULL default '',
  urgency int(11) NOT NULL default '2',
  PRIMARY KEY  (appid)
) TYPE=MyISAM;

