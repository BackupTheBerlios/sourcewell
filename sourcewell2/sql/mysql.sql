# +----------------------------------------------------------------------+
# |        SourceWell 2 - The GPL Software Announcement System           |
# +----------------------------------------------------------------------+
# |      Copyright (c) 2001-2002 BerliOS, FOKUS Fraunhofer Institut      |
# +----------------------------------------------------------------------+
# | This program is free software. You can redistribute it and/or modify |
# | it under the terms of the GNU General Public License as published by |
# | the Free Software Foundation; either version 2 or later of the GPL.  |
# +----------------------------------------------------------------------+
# | Authors: Gregorio Robles <grex@scouts-es.org>                        |
# |          Lutz Henckel <lutz.henckel@fokus.fhg.de>                    |
# +----------------------------------------------------------------------+
#
# $Id: mysql.sql,v 1.2 2002/05/07 16:46:10 grex Exp $

# Database sourcewell2
#
# For more information about the database structure
# have a look at the SourceWell2 documentation

USE sourcewell2;

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
   cat_id int(8) NOT NULL,
   category varchar(64) NOT NULL
);

#
# Dumping data for table 'categories'
#

INSERT INTO categories VALUES ( '1', 'Development Status :: 1 - Planning (disabled category)');
INSERT INTO categories VALUES ( '2', 'Development Status :: 2 - Pre-Alpha');
INSERT INTO categories VALUES ( '3', 'Development Status :: 3 - Alpha');
INSERT INTO categories VALUES ( '4', 'Development Status :: 4 - Beta');
INSERT INTO categories VALUES ( '5', 'Development Status :: 5 - Production/Stable');
INSERT INTO categories VALUES ( '6', 'Development Status :: 6 - Mature');
INSERT INTO categories VALUES ( '7', 'Environment :: Console (Framebuffer Based)');
INSERT INTO categories VALUES ( '8', 'Environment :: Console (svgalib Based)');
INSERT INTO categories VALUES ( '9', 'Environment :: Console (Text Based)');
INSERT INTO categories VALUES ( '10', 'Environment :: Console (Text Based) :: Curses');
INSERT INTO categories VALUES ( '11', 'Environment :: Console (Text Based) :: Newt');
INSERT INTO categories VALUES ( '12', 'Environment :: MacOS X');
INSERT INTO categories VALUES ( '13', 'Environment :: MacOS X :: Aqua');
INSERT INTO categories VALUES ( '14', 'Environment :: MacOS X :: Carbon');
INSERT INTO categories VALUES ( '15', 'Environment :: MacOS X :: Cocoa');
INSERT INTO categories VALUES ( '16', 'Environment :: No Input/Output (Daemon)');
INSERT INTO categories VALUES ( '17', 'Environment :: Other Environment');
INSERT INTO categories VALUES ( '18', 'Environment :: Plugins');
INSERT INTO categories VALUES ( '19', 'Environment :: Win32 (MS Windows)');
INSERT INTO categories VALUES ( '20', 'Environment :: X11 Applications');
INSERT INTO categories VALUES ( '21', 'Environment :: X11 Applications :: Gnome');
INSERT INTO categories VALUES ( '22', 'Environment :: X11 Applications :: GTK');
INSERT INTO categories VALUES ( '23', 'Environment :: X11 Applications :: KDE');
INSERT INTO categories VALUES ( '24', 'Environment :: X11 Applications :: Qt');
INSERT INTO categories VALUES ( '25', 'Environment :: Web Environment');
INSERT INTO categories VALUES ( '26', 'Intended Audience :: Developers');
INSERT INTO categories VALUES ( '27', 'Intended Audience :: End Users/Desktop');
INSERT INTO categories VALUES ( '28', 'Intended Audience :: Other Audience');
INSERT INTO categories VALUES ( '29', 'Intended Audience :: Quality Engineers');
INSERT INTO categories VALUES ( '30', 'Intended Audience :: System Administrators');
INSERT INTO categories VALUES ( '31', 'License :: Aladdin Free Public License (AFPL)');
INSERT INTO categories VALUES ( '32', 'License :: Eiffel Forum License (EFL)');
INSERT INTO categories VALUES ( '33', 'License :: Free For Educational Use');
INSERT INTO categories VALUES ( '34', 'License :: Free for non-commercial use');
INSERT INTO categories VALUES ( '35', 'License :: Free To Use But Restricted');
INSERT INTO categories VALUES ( '36', 'License :: Freely Distributable');
INSERT INTO categories VALUES ( '37', 'License :: Freeware');
INSERT INTO categories VALUES ( '38', 'License :: Netscape Public License (NPL)');
INSERT INTO categories VALUES ( '39', 'License :: Nokia Open Source License (NOKOS)');
INSERT INTO categories VALUES ( '40', 'License :: OSI Approved');
INSERT INTO categories VALUES ( '41', 'License :: OSI Approved :: Artistic License');
INSERT INTO categories VALUES ( '42', 'License :: OSI Approved :: BSD License');
INSERT INTO categories VALUES ( '43', 'License :: OSI Approved :: Common Public License');
INSERT INTO categories VALUES ( '44', 'License :: OSI Approved :: GNAT Modified GPL (GMGPL)');
INSERT INTO categories VALUES ( '45', 'License :: OSI Approved :: GNU Free Documentation License (FDL)');
INSERT INTO categories VALUES ( '46', 'License :: OSI Approved :: GNU General Public License (GPL)');
INSERT INTO categories VALUES ( '47', 'License :: OSI Approved :: GNU Lesser General Public License (LGPL)');
INSERT INTO categories VALUES ( '48', 'License :: OSI Approved :: IBM Public License');
INSERT INTO categories VALUES ( '49', 'License :: OSI Approved :: MIT/X Consortium License');
INSERT INTO categories VALUES ( '50', 'License :: OSI Approved :: MITRE Collaborative Virtual Workspace License (CVW)');
INSERT INTO categories VALUES ( '51', 'License :: OSI Approved :: Mozilla Public License (MPL)');
INSERT INTO categories VALUES ( '52', 'License :: OSI Approved :: Perl License');
INSERT INTO categories VALUES ( '53', 'License :: OSI Approved :: Python License');
INSERT INTO categories VALUES ( '54', 'License :: OSI Approved :: Q Public License (QPL)');
INSERT INTO categories VALUES ( '55', 'License :: OSI Approved :: Ricoh Source Code Public License');
INSERT INTO categories VALUES ( '56', 'License :: OSI Approved :: SUN Public License');
INSERT INTO categories VALUES ( '57', 'License :: OSI Approved :: W3C License');
INSERT INTO categories VALUES ( '58', 'License :: OSI Approved :: zlib/libpng License');
INSERT INTO categories VALUES ( '59', 'License :: Other/Proprietary License');
INSERT INTO categories VALUES ( '60', 'License :: Other/Proprietary License with Free Trial');
INSERT INTO categories VALUES ( '61', 'License :: Other/Proprietary License with Source');
INSERT INTO categories VALUES ( '62', 'License :: Public Domain');
INSERT INTO categories VALUES ( '63', 'License :: Shareware');
INSERT INTO categories VALUES ( '64', 'License :: SUN Binary Code License');
INSERT INTO categories VALUES ( '65', 'License :: SUN Community Source License');
INSERT INTO categories VALUES ( '66', 'License :: The Apache License');
INSERT INTO categories VALUES ( '67', 'License :: The Clarified Artistic License');
INSERT INTO categories VALUES ( '68', 'License :: The Latex Project Public License (LPPL)');
INSERT INTO categories VALUES ( '69', 'License :: The Open Content License');
INSERT INTO categories VALUES ( '70', 'License :: The PHP License');
INSERT INTO categories VALUES ( '71', 'License :: Voxel Public License (VPL)');
INSERT INTO categories VALUES ( '72', 'License :: Zope Public License (ZPL)');
INSERT INTO categories VALUES ( '73', 'Operating System :: BeOS');
INSERT INTO categories VALUES ( '74', 'Operating System :: MacOS');
INSERT INTO categories VALUES ( '75', 'Operating System :: MacOS X');
INSERT INTO categories VALUES ( '76', 'Operating System :: Microsoft');
INSERT INTO categories VALUES ( '77', 'Operating System :: Microsoft :: MS-DOS');
INSERT INTO categories VALUES ( '78', 'Operating System :: Microsoft :: Windows');
INSERT INTO categories VALUES ( '79', 'Operating System :: Microsoft :: Windows :: Windows 3.1 or Earlier');
INSERT INTO categories VALUES ( '80', 'Operating System :: Microsoft :: Windows :: Windows 95/98/2000');
INSERT INTO categories VALUES ( '81', 'Operating System :: Microsoft :: Windows :: Windows CE');
INSERT INTO categories VALUES ( '82', 'Operating System :: Microsoft :: Windows :: Windows NT/2000');
INSERT INTO categories VALUES ( '83', 'Operating System :: OS Independent');
INSERT INTO categories VALUES ( '84', 'Operating System :: OS/2');
INSERT INTO categories VALUES ( '85', 'Operating System :: Other OS');
INSERT INTO categories VALUES ( '86', 'Operating System :: PalmOS');
INSERT INTO categories VALUES ( '87', 'Operating System :: POSIX');
INSERT INTO categories VALUES ( '88', 'Operating System :: POSIX :: AIX');
INSERT INTO categories VALUES ( '89', 'Operating System :: POSIX :: BSD');
INSERT INTO categories VALUES ( '90', 'Operating System :: POSIX :: BSD :: BSD/OS');
INSERT INTO categories VALUES ( '91', 'Operating System :: POSIX :: BSD :: FreeBSD');
INSERT INTO categories VALUES ( '92', 'Operating System :: POSIX :: BSD :: NetBSD');
INSERT INTO categories VALUES ( '93', 'Operating System :: POSIX :: BSD :: OpenBSD');
INSERT INTO categories VALUES ( '94', 'Operating System :: POSIX :: GNU Hurd');
INSERT INTO categories VALUES ( '95', 'Operating System :: POSIX :: HP-UX');
INSERT INTO categories VALUES ( '96', 'Operating System :: POSIX :: IRIX');
INSERT INTO categories VALUES ( '97', 'Operating System :: POSIX :: Linux');
INSERT INTO categories VALUES ( '98', 'Operating System :: POSIX :: Other');
INSERT INTO categories VALUES ( '99', 'Operating System :: POSIX :: SCO');
INSERT INTO categories VALUES ( '100', 'Operating System :: POSIX :: SunOS/Solaris');
INSERT INTO categories VALUES ( '101', 'Operating System :: Unix');
INSERT INTO categories VALUES ( '102', 'Programming Language :: Ada');
INSERT INTO categories VALUES ( '103', 'Programming Language :: APL');
INSERT INTO categories VALUES ( '104', 'Programming Language :: ASP');
INSERT INTO categories VALUES ( '105', 'Programming Language :: Assembly');
INSERT INTO categories VALUES ( '106', 'Programming Language :: Awk');
INSERT INTO categories VALUES ( '107', 'Programming Language :: Basic');
INSERT INTO categories VALUES ( '108', 'Programming Language :: C');
INSERT INTO categories VALUES ( '109', 'Programming Language :: C#');
INSERT INTO categories VALUES ( '110', 'Programming Language :: C++');
INSERT INTO categories VALUES ( '111', 'Programming Language :: Cold Fusion');
INSERT INTO categories VALUES ( '112', 'Programming Language :: Delphi');
INSERT INTO categories VALUES ( '113', 'Programming Language :: Dylan');
INSERT INTO categories VALUES ( '114', 'Programming Language :: Eiffel');
INSERT INTO categories VALUES ( '115', 'Programming Language :: Emacs-Lisp');
INSERT INTO categories VALUES ( '116', 'Programming Language :: Erlang');
INSERT INTO categories VALUES ( '117', 'Programming Language :: Euler');
INSERT INTO categories VALUES ( '118', 'Programming Language :: Euphoria');
INSERT INTO categories VALUES ( '119', 'Programming Language :: Forth');
INSERT INTO categories VALUES ( '120', 'Programming Language :: Fortran');
INSERT INTO categories VALUES ( '121', 'Programming Language :: Haskell');
INSERT INTO categories VALUES ( '122', 'Programming Language :: Java');
INSERT INTO categories VALUES ( '123', 'Programming Language :: JavaScript');
INSERT INTO categories VALUES ( '124', 'Programming Language :: Lisp');
INSERT INTO categories VALUES ( '125', 'Programming Language :: Logo');
INSERT INTO categories VALUES ( '126', 'Programming Language :: ML');
INSERT INTO categories VALUES ( '127', 'Programming Language :: Modula');
INSERT INTO categories VALUES ( '128', 'Programming Language :: Object Pascal');
INSERT INTO categories VALUES ( '129', 'Programming Language :: Objective C');
INSERT INTO categories VALUES ( '130', 'Programming Language :: Other');
INSERT INTO categories VALUES ( '131', 'Programming Language :: Other Scripting Engines');
INSERT INTO categories VALUES ( '132', 'Programming Language :: Pascal');
INSERT INTO categories VALUES ( '133', 'Programming Language :: Perl');
INSERT INTO categories VALUES ( '134', 'Programming Language :: PHP');
INSERT INTO categories VALUES ( '135', 'Programming Language :: PL/SQL');
INSERT INTO categories VALUES ( '136', 'Programming Language :: Pliant');
INSERT INTO categories VALUES ( '137', 'Programming Language :: PROGRESS');
INSERT INTO categories VALUES ( '138', 'Programming Language :: Prolog');
INSERT INTO categories VALUES ( '139', 'Programming Language :: Python');
INSERT INTO categories VALUES ( '140', 'Programming Language :: Rexx');
INSERT INTO categories VALUES ( '141', 'Programming Language :: Ruby');
INSERT INTO categories VALUES ( '142', 'Programming Language :: Scheme');
INSERT INTO categories VALUES ( '143', 'Programming Language :: Simula');
INSERT INTO categories VALUES ( '144', 'Programming Language :: Smalltalk');
INSERT INTO categories VALUES ( '145', 'Programming Language :: SQL');
INSERT INTO categories VALUES ( '146', 'Programming Language :: Tcl');
INSERT INTO categories VALUES ( '147', 'Programming Language :: Unix Shell');
INSERT INTO categories VALUES ( '148', 'Programming Language :: Visual Basic');
INSERT INTO categories VALUES ( '149', 'Programming Language :: XBasic');
INSERT INTO categories VALUES ( '150', 'Programming Language :: Zope');
INSERT INTO categories VALUES ( '151', 'Topic :: Adaptive Technologies');
INSERT INTO categories VALUES ( '152', 'Topic :: Artistic Software');
INSERT INTO categories VALUES ( '153', 'Topic :: Communications');
INSERT INTO categories VALUES ( '154', 'Topic :: Communications :: BBS');
INSERT INTO categories VALUES ( '155', 'Topic :: Communications :: Chat');
INSERT INTO categories VALUES ( '156', 'Topic :: Communications :: Chat :: AOL Instant Messenger');
INSERT INTO categories VALUES ( '157', 'Topic :: Communications :: Chat :: ICQ');
INSERT INTO categories VALUES ( '158', 'Topic :: Communications :: Chat :: Internet Relay Chat');
INSERT INTO categories VALUES ( '159', 'Topic :: Communications :: Chat :: Unix Talk');
INSERT INTO categories VALUES ( '160', 'Topic :: Communications :: Conferencing');
INSERT INTO categories VALUES ( '161', 'Topic :: Communications :: Email');
INSERT INTO categories VALUES ( '162', 'Topic :: Communications :: Email :: Address Book');
INSERT INTO categories VALUES ( '163', 'Topic :: Communications :: Email :: Email Clients (MUA)');
INSERT INTO categories VALUES ( '164', 'Topic :: Communications :: Email :: Filters');
INSERT INTO categories VALUES ( '165', 'Topic :: Communications :: Email :: Mail Transport Agents');
INSERT INTO categories VALUES ( '166', 'Topic :: Communications :: Email :: Mailing List Servers');
INSERT INTO categories VALUES ( '167', 'Topic :: Communications :: Email :: Post-Office');
INSERT INTO categories VALUES ( '168', 'Topic :: Communications :: Email :: Post-Office :: IMAP');
INSERT INTO categories VALUES ( '169', 'Topic :: Communications :: Email :: Post-Office :: POP3');
INSERT INTO categories VALUES ( '170', 'Topic :: Communications :: Fax');
INSERT INTO categories VALUES ( '171', 'Topic :: Communications :: FIDO');
INSERT INTO categories VALUES ( '172', 'Topic :: Communications :: File Sharing');
INSERT INTO categories VALUES ( '173', 'Topic :: Communications :: File Sharing :: Napster');
INSERT INTO categories VALUES ( '174', 'Topic :: Communications :: Ham Radio');
INSERT INTO categories VALUES ( '175', 'Topic :: Communications :: Internet Phone');
INSERT INTO categories VALUES ( '176', 'Topic :: Communications :: Telephony');
INSERT INTO categories VALUES ( '177', 'Topic :: Communications :: Usenet News');
INSERT INTO categories VALUES ( '178', 'Topic :: Database');
INSERT INTO categories VALUES ( '179', 'Topic :: Database :: Database Engines/Servers');
INSERT INTO categories VALUES ( '180', 'Topic :: Database :: Front-Ends');
INSERT INTO categories VALUES ( '181', 'Topic :: Desktop Environment');
INSERT INTO categories VALUES ( '182', 'Topic :: Desktop Environment :: File Managers');
INSERT INTO categories VALUES ( '183', 'Topic :: Desktop Environment :: Fonts');
INSERT INTO categories VALUES ( '184', 'Topic :: Desktop Environment :: Gnome');
INSERT INTO categories VALUES ( '185', 'Topic :: Desktop Environment :: GNUstep');
INSERT INTO categories VALUES ( '186', 'Topic :: Desktop Environment :: K Desktop Environment (KDE)');
INSERT INTO categories VALUES ( '187', 'Topic :: Desktop Environment :: K Desktop Environment (KDE) :: Themes');
INSERT INTO categories VALUES ( '188', 'Topic :: Desktop Environment :: Screen Savers');
INSERT INTO categories VALUES ( '189', 'Topic :: Desktop Environment :: Window Managers');
INSERT INTO categories VALUES ( '190', 'Topic :: Desktop Environment :: Window Managers :: Applets');
INSERT INTO categories VALUES ( '191', 'Topic :: Desktop Environment :: Window Managers :: Enlightenment');
INSERT INTO categories VALUES ( '192', 'Topic :: Desktop Environment :: Window Managers :: Enlightenment :: Epplets');
INSERT INTO categories VALUES ( '193', 'Topic :: Desktop Environment :: Window Managers :: Enlightenment :: Themes');
INSERT INTO categories VALUES ( '194', 'Topic :: Desktop Environment :: Window Managers :: Window Maker');
INSERT INTO categories VALUES ( '195', 'Topic :: Desktop Environment :: Window Managers :: Window Maker :: Applets');
INSERT INTO categories VALUES ( '196', 'Topic :: Documentation');
INSERT INTO categories VALUES ( '197', 'Topic :: Education');
INSERT INTO categories VALUES ( '198', 'Topic :: Education :: Computer Aided Instruction (CAI)');
INSERT INTO categories VALUES ( '199', 'Topic :: Education :: Testing');
INSERT INTO categories VALUES ( '200', 'Topic :: Games/Entertainment');
INSERT INTO categories VALUES ( '201', 'Topic :: Games/Entertainment :: Arcade');
INSERT INTO categories VALUES ( '202', 'Topic :: Games/Entertainment :: First Person Shooters');
INSERT INTO categories VALUES ( '203', 'Topic :: Games/Entertainment :: Fortune Cookies');
INSERT INTO categories VALUES ( '204', 'Topic :: Games/Entertainment :: Multi-User Dungeons (MUD)');
INSERT INTO categories VALUES ( '205', 'Topic :: Games/Entertainment :: Puzzle Games');
INSERT INTO categories VALUES ( '206', 'Topic :: Games/Entertainment :: Real Time Strategy');
INSERT INTO categories VALUES ( '207', 'Topic :: Games/Entertainment :: Role-Playing');
INSERT INTO categories VALUES ( '208', 'Topic :: Games/Entertainment :: Simulation');
INSERT INTO categories VALUES ( '209', 'Topic :: Games/Entertainment :: Turn Based Strategy');
INSERT INTO categories VALUES ( '210', 'Topic :: Home Automation');
INSERT INTO categories VALUES ( '211', 'Topic :: Internet');
INSERT INTO categories VALUES ( '212', 'Topic :: Internet :: WWW/HTTP :: Dynamic Content');
INSERT INTO categories VALUES ( '213', 'Topic :: Internet :: File Transfer Protocol (FTP)');
INSERT INTO categories VALUES ( '214', 'Topic :: Internet :: Finger');
INSERT INTO categories VALUES ( '215', 'Topic :: Internet :: Log Analysis');
INSERT INTO categories VALUES ( '216', 'Topic :: Internet :: Name Service (DNS)');
INSERT INTO categories VALUES ( '217', 'Topic :: Internet :: Proxy Servers');
INSERT INTO categories VALUES ( '218', 'Topic :: Internet :: WWW/HTTP');
INSERT INTO categories VALUES ( '219', 'Topic :: Internet :: WWW/HTTP :: Browsers');
INSERT INTO categories VALUES ( '220', 'Topic :: Internet :: WWW/HTTP :: Dynamic Content :: CGI Tools/Libraries');
INSERT INTO categories VALUES ( '221', 'Topic :: Internet :: WWW/HTTP :: Dynamic Content :: Message Boards');
INSERT INTO categories VALUES ( '222', 'Topic :: Internet :: WWW/HTTP :: Dynamic Content :: News/Diary');
INSERT INTO categories VALUES ( '223', 'Topic :: Internet :: WWW/HTTP :: Dynamic Content :: Page Counters');
INSERT INTO categories VALUES ( '224', 'Topic :: Internet :: WWW/HTTP :: HTTP Servers');
INSERT INTO categories VALUES ( '225', 'Topic :: Internet :: WWW/HTTP :: Indexing/Search');
INSERT INTO categories VALUES ( '226', 'Topic :: Internet :: WWW/HTTP :: Site Management');
INSERT INTO categories VALUES ( '227', 'Topic :: Internet :: WWW/HTTP :: Site Management :: Link Checking');
INSERT INTO categories VALUES ( '228', 'Topic :: Internet :: Z39.50');
INSERT INTO categories VALUES ( '229', 'Topic :: Multimedia');
INSERT INTO categories VALUES ( '230', 'Topic :: Multimedia :: Graphics');
INSERT INTO categories VALUES ( '231', 'Topic :: Multimedia :: Graphics :: 3D Modeling');
INSERT INTO categories VALUES ( '232', 'Topic :: Multimedia :: Graphics :: 3D Rendering');
INSERT INTO categories VALUES ( '233', 'Topic :: Multimedia :: Graphics :: Capture');
INSERT INTO categories VALUES ( '234', 'Topic :: Multimedia :: Graphics :: Capture :: Digital Camera');
INSERT INTO categories VALUES ( '235', 'Topic :: Multimedia :: Graphics :: Capture :: Scanners');
INSERT INTO categories VALUES ( '236', 'Topic :: Multimedia :: Graphics :: Capture :: Screen Capture');
INSERT INTO categories VALUES ( '237', 'Topic :: Multimedia :: Graphics :: Editors');
INSERT INTO categories VALUES ( '238', 'Topic :: Multimedia :: Graphics :: Editors :: Raster-Based');
INSERT INTO categories VALUES ( '239', 'Topic :: Multimedia :: Graphics :: Editors :: Vector-Based');
INSERT INTO categories VALUES ( '240', 'Topic :: Multimedia :: Graphics :: Graphics Conversion');
INSERT INTO categories VALUES ( '241', 'Topic :: Multimedia :: Graphics :: Presentation');
INSERT INTO categories VALUES ( '242', 'Topic :: Multimedia :: Graphics :: Viewers');
INSERT INTO categories VALUES ( '243', 'Topic :: Multimedia :: Sound/Audio');
INSERT INTO categories VALUES ( '244', 'Topic :: Multimedia :: Sound/Audio :: Analysis');
INSERT INTO categories VALUES ( '245', 'Topic :: Multimedia :: Sound/Audio :: Capture/Recording');
INSERT INTO categories VALUES ( '246', 'Topic :: Multimedia :: Sound/Audio :: CD Audio');
INSERT INTO categories VALUES ( '247', 'Topic :: Multimedia :: Sound/Audio :: CD Audio :: CD Playing');
INSERT INTO categories VALUES ( '248', 'Topic :: Multimedia :: Sound/Audio :: CD Audio :: CD Ripping');
INSERT INTO categories VALUES ( '249', 'Topic :: Multimedia :: Sound/Audio :: CD Audio :: CD Writing');
INSERT INTO categories VALUES ( '250', 'Topic :: Multimedia :: Sound/Audio :: Conversion');
INSERT INTO categories VALUES ( '251', 'Topic :: Multimedia :: Sound/Audio :: Editors');
INSERT INTO categories VALUES ( '252', 'Topic :: Multimedia :: Sound/Audio :: MIDI');
INSERT INTO categories VALUES ( '253', 'Topic :: Multimedia :: Sound/Audio :: Mixers');
INSERT INTO categories VALUES ( '254', 'Topic :: Multimedia :: Sound/Audio :: Players');
INSERT INTO categories VALUES ( '255', 'Topic :: Multimedia :: Sound/Audio :: Players :: MP3');
INSERT INTO categories VALUES ( '256', 'Topic :: Multimedia :: Sound/Audio :: Sound Synthesis');
INSERT INTO categories VALUES ( '257', 'Topic :: Multimedia :: Sound/Audio :: Speech');
INSERT INTO categories VALUES ( '258', 'Topic :: Multimedia :: Video');
INSERT INTO categories VALUES ( '259', 'Topic :: Multimedia :: Video :: Capture');
INSERT INTO categories VALUES ( '260', 'Topic :: Multimedia :: Video :: Conversion');
INSERT INTO categories VALUES ( '261', 'Topic :: Multimedia :: Video :: Display');
INSERT INTO categories VALUES ( '262', 'Topic :: Multimedia :: Video :: Non-Linear Editor');
INSERT INTO categories VALUES ( '263', 'Topic :: Office/Business');
INSERT INTO categories VALUES ( '264', 'Topic :: Office/Business :: Financial');
INSERT INTO categories VALUES ( '265', 'Topic :: Office/Business :: Financial :: Accounting');
INSERT INTO categories VALUES ( '266', 'Topic :: Office/Business :: Financial :: Investment');
INSERT INTO categories VALUES ( '267', 'Topic :: Office/Business :: Financial :: Point-Of-Sale');
INSERT INTO categories VALUES ( '268', 'Topic :: Office/Business :: Financial :: Spreadsheet');
INSERT INTO categories VALUES ( '269', 'Topic :: Office/Business :: Groupware');
INSERT INTO categories VALUES ( '270', 'Topic :: Office/Business :: News/Diary');
INSERT INTO categories VALUES ( '271', 'Topic :: Office/Business :: Office Suites');
INSERT INTO categories VALUES ( '272', 'Topic :: Office/Business :: Scheduling');
INSERT INTO categories VALUES ( '273', 'Topic :: Other/Nonlisted Topic');
INSERT INTO categories VALUES ( '274', 'Topic :: Printing');
INSERT INTO categories VALUES ( '275', 'Topic :: Religion');
INSERT INTO categories VALUES ( '276', 'Topic :: Scientific/Engineering');
INSERT INTO categories VALUES ( '277', 'Topic :: Scientific/Engineering :: Artificial Intelligence');
INSERT INTO categories VALUES ( '278', 'Topic :: Scientific/Engineering :: Astronomy');
INSERT INTO categories VALUES ( '279', 'Topic :: Scientific/Engineering :: Bioinformatics');
INSERT INTO categories VALUES ( '280', 'Topic :: Scientific/Engineering :: Chemistry');
INSERT INTO categories VALUES ( '281', 'Topic :: Scientific/Engineering :: Electronic Design Automation (EDA)');
INSERT INTO categories VALUES ( '282', 'Topic :: Scientific/Engineering :: Image Recognition');
INSERT INTO categories VALUES ( '283', 'Topic :: Scientific/Engineering :: Mathematics');
INSERT INTO categories VALUES ( '284', 'Topic :: Scientific/Engineering :: Medical Science Apps.');
INSERT INTO categories VALUES ( '285', 'Topic :: Scientific/Engineering :: Visualization');
INSERT INTO categories VALUES ( '286', 'Topic :: Security');
INSERT INTO categories VALUES ( '287', 'Topic :: Security :: Cryptography');
INSERT INTO categories VALUES ( '288', 'Topic :: Software Development');
INSERT INTO categories VALUES ( '289', 'Topic :: Software Development :: Assemblers');
INSERT INTO categories VALUES ( '290', 'Topic :: Software Development :: Bug Tracking');
INSERT INTO categories VALUES ( '291', 'Topic :: Software Development :: Build Tools');
INSERT INTO categories VALUES ( '292', 'Topic :: Software Development :: Code Generators');
INSERT INTO categories VALUES ( '293', 'Topic :: Software Development :: Compilers');
INSERT INTO categories VALUES ( '294', 'Topic :: Software Development :: Debuggers');
INSERT INTO categories VALUES ( '295', 'Topic :: Software Development :: Disassemblers');
INSERT INTO categories VALUES ( '296', 'Topic :: Software Development :: Documentation');
INSERT INTO categories VALUES ( '297', 'Topic :: Software Development :: Embedded Systems');
INSERT INTO categories VALUES ( '298', 'Topic :: Software Development :: Interpreters');
INSERT INTO categories VALUES ( '299', 'Topic :: Software Development :: Libraries');
INSERT INTO categories VALUES ( '300', 'Topic :: Software Development :: Libraries :: Application Frameworks');
INSERT INTO categories VALUES ( '301', 'Topic :: Software Development :: Libraries :: Java Libraries');
INSERT INTO categories VALUES ( '302', 'Topic :: Software Development :: Libraries :: Perl Modules');
INSERT INTO categories VALUES ( '303', 'Topic :: Software Development :: Libraries :: PHP Classes');
INSERT INTO categories VALUES ( '304', 'Topic :: Software Development :: Libraries :: Pike Modules');
INSERT INTO categories VALUES ( '305', 'Topic :: Software Development :: Libraries :: Python Modules');
INSERT INTO categories VALUES ( '306', 'Topic :: Software Development :: Libraries :: Tcl Extensions');
INSERT INTO categories VALUES ( '307', 'Topic :: Software Development :: Object Brokering');
INSERT INTO categories VALUES ( '308', 'Topic :: Software Development :: Object Brokering :: CORBA');
INSERT INTO categories VALUES ( '309', 'Topic :: Software Development :: Pre-processors');
INSERT INTO categories VALUES ( '310', 'Topic :: Software Development :: Quality Assurance');
INSERT INTO categories VALUES ( '311', 'Topic :: Software Development :: Testing');
INSERT INTO categories VALUES ( '312', 'Topic :: Software Development :: Testing :: Traffic Generation');
INSERT INTO categories VALUES ( '313', 'Topic :: Software Development :: User Interfaces');
INSERT INTO categories VALUES ( '314', 'Topic :: Software Development :: Version Control');
INSERT INTO categories VALUES ( '315', 'Topic :: Software Development :: Version Control :: CVS');
INSERT INTO categories VALUES ( '316', 'Topic :: Software Development :: Version Control :: RCS');
INSERT INTO categories VALUES ( '317', 'Topic :: Software Development :: Version Control :: SCCS');
INSERT INTO categories VALUES ( '318', 'Topic :: Software Development :: Widget Sets');
INSERT INTO categories VALUES ( '319', 'Topic :: System');
INSERT INTO categories VALUES ( '320', 'Topic :: System :: Archiving');
INSERT INTO categories VALUES ( '321', 'Topic :: System :: Archiving :: Backup');
INSERT INTO categories VALUES ( '322', 'Topic :: System :: Archiving :: Compression');
INSERT INTO categories VALUES ( '323', 'Topic :: System :: Archiving :: Mirroring');
INSERT INTO categories VALUES ( '324', 'Topic :: System :: Archiving :: Packaging');
INSERT INTO categories VALUES ( '325', 'Topic :: System :: Benchmark');
INSERT INTO categories VALUES ( '326', 'Topic :: System :: Boot');
INSERT INTO categories VALUES ( '327', 'Topic :: System :: Boot :: Init');
INSERT INTO categories VALUES ( '328', 'Topic :: System :: Clustering/Distributed Networks');
INSERT INTO categories VALUES ( '329', 'Topic :: System :: Console Fonts');
INSERT INTO categories VALUES ( '330', 'Topic :: System :: Emulators');
INSERT INTO categories VALUES ( '331', 'Topic :: System :: Filesystems');
INSERT INTO categories VALUES ( '332', 'Topic :: System :: Hardware');
INSERT INTO categories VALUES ( '333', 'Topic :: System :: Installation/Setup');
INSERT INTO categories VALUES ( '334', 'Topic :: System :: Logging');
INSERT INTO categories VALUES ( '335', 'Topic :: System :: Monitoring');
INSERT INTO categories VALUES ( '336', 'Topic :: System :: Networking');
INSERT INTO categories VALUES ( '337', 'Topic :: System :: Networking :: Firewalls');
INSERT INTO categories VALUES ( '338', 'Topic :: System :: Networking :: Monitoring');
INSERT INTO categories VALUES ( '339', 'Topic :: System :: Networking :: Monitoring :: Hardware Watchdog');
INSERT INTO categories VALUES ( '340', 'Topic :: System :: Networking :: Time Synchronization');
INSERT INTO categories VALUES ( '341', 'Topic :: System :: Operating System');
INSERT INTO categories VALUES ( '342', 'Topic :: System :: Operating System Kernels');
INSERT INTO categories VALUES ( '343', 'Topic :: System :: Operating System Kernels :: BSD');
INSERT INTO categories VALUES ( '344', 'Topic :: System :: Operating System Kernels :: GNU Hurd');
INSERT INTO categories VALUES ( '345', 'Topic :: System :: Operating System Kernels :: Linux');
INSERT INTO categories VALUES ( '346', 'Topic :: System :: Power (UPS)');
INSERT INTO categories VALUES ( '347', 'Topic :: System :: Recovery Tools');
INSERT INTO categories VALUES ( '348', 'Topic :: System :: Shells');
INSERT INTO categories VALUES ( '349', 'Topic :: System :: Software Distribution');
INSERT INTO categories VALUES ( '350', 'Topic :: System :: Software Distribution Tools');
INSERT INTO categories VALUES ( '351', 'Topic :: System :: Systems Administration');
INSERT INTO categories VALUES ( '352', 'Topic :: Terminals');
INSERT INTO categories VALUES ( '353', 'Topic :: Terminals :: Serial');
INSERT INTO categories VALUES ( '354', 'Topic :: Terminals :: Telnet');
INSERT INTO categories VALUES ( '355', 'Topic :: Terminals :: Terminal Emulators/X Terminals');
INSERT INTO categories VALUES ( '356', 'Topic :: Text Editors');
INSERT INTO categories VALUES ( '357', 'Topic :: Text Editors :: Documentation');
INSERT INTO categories VALUES ( '358', 'Topic :: Text Editors :: Emacs');
INSERT INTO categories VALUES ( '359', 'Topic :: Text Editors :: Integrated Development Environments (IDE)');
INSERT INTO categories VALUES ( '360', 'Topic :: Text Editors :: Word Processors');
INSERT INTO categories VALUES ( '361', 'Topic :: Text Processing');
INSERT INTO categories VALUES ( '362', 'Topic :: Text Processing :: Filters');
INSERT INTO categories VALUES ( '363', 'Topic :: Text Processing :: Fonts');
INSERT INTO categories VALUES ( '364', 'Topic :: Text Processing :: General');
INSERT INTO categories VALUES ( '365', 'Topic :: Text Processing :: Indexing');
INSERT INTO categories VALUES ( '366', 'Topic :: Text Processing :: Linguistic');
INSERT INTO categories VALUES ( '367', 'Topic :: Text Processing :: Markup');
INSERT INTO categories VALUES ( '368', 'Topic :: Text Processing :: Markup :: HTML');
INSERT INTO categories VALUES ( '369', 'Topic :: Text Processing :: Markup :: LaTeX');
INSERT INTO categories VALUES ( '370', 'Topic :: Text Processing :: Markup :: SGML');
INSERT INTO categories VALUES ( '371', 'Topic :: Text Processing :: Markup :: VRML');
INSERT INTO categories VALUES ( '372', 'Topic :: Text Processing :: Markup :: XML');
INSERT INTO categories VALUES ( '373', 'Topic :: Utilities');

# --------------------------------------------------------
#
# Table structure for table 'comments'
#

DROP TABLE IF EXISTS comments;
CREATE TABLE comments (
   comment_id bigint(20) unsigned DEFAULT '0' NOT NULL,
   id bigint(20) unsigned DEFAULT '0' NOT NULL,
   user varchar(16) NOT NULL,
   status char(1) NOT NULL,
   subject varchar(128) NOT NULL,
   text blob NOT NULL,
   creation timestamp(14),
   UNIQUE cmt_id (comment_id)
);

#
# Dumping data for table 'comments'
#

INSERT INTO comments VALUES ('1', '1', 'anonymous', 'A', 'We use SourceWell successfully!', 'You can visit our web site at <A HREF="http://sourcewell.berlios.de">http://sourcewell.berlios.de</a> where we have been using the SourceWell system succesfully for more than three months yet. You will find more than 900 inserted applications and 2000 releases announced in our system. A closer look a at it will let you see how far you can go with it!', '20010522133952');


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
   branch_id bigint(20) DEFAULT '0' NOT NULL,
   user varchar(16) NOT NULL,
   creation timestamp(14),
   version varchar(16) NOT NULL,
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
INSERT INTO history VALUES ( '9', '1', 'anonymous', '20011215203421', '1.0.11');
INSERT INTO history VALUES ( '10', '1', 'anonymous', '20011221192343', '1.0.12');
INSERT INTO history VALUES ( '11', '1', 'anonymous', '20011226230000', '1.0.13');

# --------------------------------------------------------
#
# Table structure for table 'licenses'
#

DROP TABLE IF EXISTS licenses;
CREATE TABLE licenses (
   license varchar(64) NOT NULL,
   url varchar(255) NOT NULL
);

INSERT INTO licenses SET license='The GNU General Public License (GPL)', url='licenses/gpl.html';
INSERT INTO licenses SET license='The GNU Library or "Lesser" Public License (LGPL)', url='licenses/lgpl.html';
INSERT INTO licenses SET license='The BSD license', url='licenses/bsd.html';
INSERT INTO licenses SET license='The MIT license', url='licenses/mit.html';
INSERT INTO licenses SET license='The Artistic license', url='licenses/artistic.html';
INSERT INTO licenses SET license='The Mozilla Public License v. 1.0 (MPL)', url='licenses/mpl10.html';
INSERT INTO licenses SET license='The Qt Public License (QPL)', url='licenses/qpl.html';
INSERT INTO licenses SET license='The IBM Public License', url='licenses/ibmpl.html';
INSERT INTO licenses SET license='The MITRE Collaborative Virtual Workspace License (CVW License)', url='licenses/cvwl.html';
INSERT INTO licenses SET license='The Ricoh Source Code Public License', url='licenses/rscpl.html';
INSERT INTO licenses SET license='The Python license (CNRI Python License)', url='licenses/cnripl.html';
INSERT INTO licenses SET license='The Python Software Foundation License', url='licenses/psfl.html';
INSERT INTO licenses SET license='The zlib/libpng license', url='licenses/zlib.html';
INSERT INTO licenses SET license='The Apache Software License', url='licenses/apache.html';
INSERT INTO licenses SET license='The Vovida Software License v. 1.0', url='licenses/vsl.html';
INSERT INTO licenses SET license='The Sun Industry Standards Source License (SISSL)', url='licenses/sissl.html';
INSERT INTO licenses SET license='The Intel Open Source License', url='licenses/iosl.html';
INSERT INTO licenses SET license='The Mozilla Public License 1.1 (MPL 1.1)', url='licenses/mpl11.html';
INSERT INTO licenses SET license='The Jabber Open Source License', url='licenses/josl.html';
INSERT INTO licenses SET license='The Nokia Open Source License', url='licenses/nosl.html';
INSERT INTO licenses SET license='The Sleepycat License', url='licenses/sl.html';
INSERT INTO licenses SET license='The Nethack General Public License', url='licenses/ngpl.html';
INSERT INTO licenses SET license='The Common Public License', url='licenses/cpl.html';
INSERT INTO licenses SET license='The Apple Public Source License', url='licenses/apsl.html';
INSERT INTO licenses SET license='The X.Net License', url='licenses/xnl.html';
INSERT INTO licenses SET license='The Sun Public License', url='licenses/spl.html';
INSERT INTO licenses SET license='The Eiffel Forum License', url='licenses/efl.html';
INSERT INTO licenses SET license='The W3C License', url='licenses/w3cl.html';
INSERT INTO licenses SET license='The Motosoto License', url='licenses/ml.html';
INSERT INTO licenses SET license='The Open Group Test Suite License', url='licenses/ogtsl.html';

#NOT OS

INSERT INTO licenses SET license='OSI Approved (Open Source)', url='licenses/licnotavailable.html';
INSERT INTO licenses SET license='Public Domain', url='licenses/pd.html' WHERE license='Public Domain';
INSERT INTO licenses SET license='The GNU Free Documentation License (FDL)', url='licenses/fdl.html';
INSERT INTO licenses SET license='The PHP License', url='licenses/phpl.html' WHERE license='PHP License';
INSERT INTO licenses SET license='The OpenLDAP Public License', url='licenses/oldapl.html';
INSERT INTO licenses SET license='The SUN Community Source License', url='licenses/scl.html';
INSERT INTO licenses SET license='The Zope Public License (ZPL)', url='licenses/zpl.html';
INSERT INTO licenses SET license='The Clarified Artistic License', url='licenses/cal.html';
INSERT INTO licenses SET license='The Voxel Public License (VPL)', url='licenses/vpl.html';
INSERT INTO licenses SET license='The Netscape Public License (NPL)', url='licenses/npl10.html';
INSERT INTO licenses SET license='The SUN Binary Code License', url='licenses/sbcl.html';
INSERT INTO licenses SET license='The Latex Project Public License (LPPL)', url='licenses/lppl.html';
INSERT INTO licenses SET license='The Open Content License', url='licenses/opcl.html';
INSERT INTO licenses SET license='The Open Public License', url='licenses/opl.html';
INSERT INTO licenses SET license='The Open Publication License', url='licenses/opul.html';
INSERT INTO licenses SET license='The Open Public License', url='licenses/opl.html';
INSERT INTO licenses SET license='The Aladdin Free Public License (AFPL)', url='licenses/afpl.html';
INSERT INTO licenses SET license='The Arphic Public License', url='licenses/apl.html' WHERE license='Arphic Public License';
INSERT INTO licenses SET license='The Cryptix General License', url='licenses/cgl.html' WHERE license='Cryptix General License';
INSERT INTO licenses SET license='The FreeType License', url='licenses/ftl.html' WHERE license='FreeType License';
INSERT INTO licenses SET license='The Interbase Public License', url='licenses/ipl.html' WHERE license='Interbase Public License';
INSERT INTO licenses SET license='The Phorum License', url='licenses/pl.html' WHERE license='Phorum';
INSERT INTO licenses SET license='The Plan 9 Open Source License', url='licenses/p9osl.html';

# URL/explanation Needed

INSERT INTO licenses SET license='The Open Compatibility License', url='licenses/licnotavailable.html';
INSERT INTO licenses SET license='The GNAT Modified GPL (GMGPL)', url='licenses/licnotavailable.html';
INSERT INTO licenses SET license='The Free For Educational Use', url='licenses/licnotavailable.html';
INSERT INTO licenses SET license='Source-available Commercial', url='licenses/licnotavailable.html';
INSERT INTO licenses SET license='Free Trail', url='licenses/licnotavailable.html';
INSERT INTO licenses SET license='Freely Distributable', url='licenses/freely_distributable.html';
INSERT INTO licenses SET license='Freeware', url='licenses/licnotavailable.html' WHERE license='Freeware';
INSERT INTO licenses SET license='Free for non-commercial use', url='licenses/licnotavailable.html';
INSERT INTO licenses SET license='Free To Use But Restricted', url='licenses/licnotavailable.html';
INSERT INTO licenses SET license='Other/Proprietary License', url='licenses/licnotavailable.html';
INSERT INTO licenses SET license='Shareware', url='licenses/licnotavailable.html';
INSERT INTO licenses SET license='Unknown', url='licenses/licnotavailable.html';

# --------------------------------------------------------
#
# Table structure for table 'projects'
#

DROP TABLE IF EXISTS projects;
CREATE TABLE projects (
   id bigint(20) unsigned DEFAULT '0' NOT NULL auto_increment,
   name varchar(128) NOT NULL,
   description blob NOT NULL,
   user varchar(16) NOT NULL,
   status char(1) NOT NULL,
   modification timestamp(14) NOT NULL,
   creation timestamp(14) NOT NULL,

   homepage varchar(255) NOT NULL,
   changelog varchar(255),
   cvs varchar(255),
   doc_tutorial varchar(255),   
   faq varchar(255),
   screenshots varchar(255),
   mailarch varchar(255),
   categories varchar(255),
   source varchar(16),

   UNIQUE proid (id)
);

# --------------------------------------------------------
#
# Table structure for table 'branches'
#

DROP TABLE IF EXISTS branches;
CREATE TABLE branches (
   branch_id bigint(20) unsigned DEFAULT '0' NOT NULL auto_increment,
   id bigint(20) NOT NULL,          # FK from table projects
   name varchar(128) NOT NULL,
   user varchar(16) NOT NULL,
   status char(1) NOT NULL,
   modification timestamp(14) NOT NULL,
   creation timestamp(14) NOT NULL,

   type varchar(24) NOT NULL,          # Stable, development or other
   version varchar(24) NOT NULL,
   license varchar(64),               # if "link" look at other table
   tarball varchar(255),
   bzip2 varchar(255),   
   zip varchar(255),
   rpm varchar(255),
   spm varchar(255),
   deb varchar(255),
   aptget varchar(128),
   alternate_download varchar(255),
   source varchar(16)
);

#
# Dumping data for table ''
#


# --------------------------------------------------------
#
# Table structure for table 'dependencies'
#

DROP TABLE IF EXISTS dependencies;
CREATE TABLE dependencies (
   id bigint(20) NOT NULL,          # FK from table projects
   user varchar(16) NOT NULL,

   depends_on bigint(20) NOT NULL          # id as FK from table projects
);

# --------------------------------------------------------
#
# Table structure for table 'authors'
#

DROP TABLE IF EXISTS authors;
CREATE TABLE authors (
   id bigint(20) NOT NULL,          # FK from table projects
   user varchar(16) NOT NULL,

   author varchar(32) NOT NULL,
   e-mail varchar(64)
);
