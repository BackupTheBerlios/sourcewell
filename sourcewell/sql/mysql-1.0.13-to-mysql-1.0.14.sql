
## INSTRUCTIONS
#
# Insert the following SQL queries directly into your database
# We recommend you to use phpMyAdmin
#
# The run the script (from the command line or from your web-broswer)
# that has been stored as mysql-1.0.13-to-mysql-1.0.14
#
# Copyright Gregorio Robles <grex@scouts-es.org>
#

# OS

UPDATE licenses SET license='The GNU General Public License (GPL)', url='licenses/gpl.html' WHERE license='GPL';
UPDATE licenses SET license='The GNU Library or "Lesser" Public License (LGPL)', url='licenses/lgpl.html' WHERE license='LGPL';
UPDATE licenses SET license='The BSD license', url='licenses/bsd.html' WHERE license='BSD type';
UPDATE licenses SET license='The MIT license', url='licenses/mit.html' WHERE license='MIT';
UPDATE licenses SET license='The Artistic license', url='licenses/artistic.html' WHERE license='Artistic License';
INSERT INTO licenses SET license='The Mozilla Public License v. 1.0 (MPL)', url='licenses/mpl10.html';
UPDATE licenses SET license='The Qt Public License (QPL)', url='licenses/qpl.html' WHERE license='Q Public License (QPL)';
UPDATE licenses SET license='The IBM Public License', url='licenses/ibmpl.html' WHERE license='IBM Public License';
INSERT INTO licenses SET license='The MITRE Collaborative Virtual Workspace License (CVW License)', url='licenses/cvwl.html';
INSERT INTO licenses SET license='The Ricoh Source Code Public License', url='licenses/rscpl.html';
INSERT INTO licenses SET license='The Python license (CNRI Python License)', url='licenses/cnripl.html';
INSERT INTO licenses SET license='The Python Software Foundation License', url='licenses/psfl.html';
UPDATE licenses SET license='The zlib/libpng license', url='licenses/zlib.html' WHERE license='Zlib License';
UPDATE licenses SET license='The Apache Software License', url='licenses/apache.html' WHERE license='Apache style';
INSERT INTO licenses SET license='The Vovida Software License v. 1.0', url='licenses/vsl.html';
INSERT INTO licenses SET license='The Sun Industry Standards Source License (SISSL)', url='licenses/sissl.html';
INSERT INTO licenses SET license='The Intel Open Source License', url='licenses/iosl.html';
UPDATE licenses SET license='The Mozilla Public License 1.1 (MPL 1.1)', url='licenses/mpl11.html' WHERE license='Mozilla Public License (MPL)';
UPDATE licenses SET license='The Jabber Open Source License', url='licenses/josl.html' WHERE license='Jabber Open Source License';
INSERT INTO licenses SET license='The Nokia Open Source License', url='licenses/nosl.html';
UPDATE licenses SET license='The Sleepycat License', url='licenses/sl.html' WHERE license='Berkeley Database License';
INSERT INTO licenses SET license='The Nethack General Public License', url='licenses/ngpl.html';
INSERT INTO licenses SET license='The Common Public License', url='licenses/cpl.html';
INSERT INTO licenses SET license='The Apple Public Source License', url='licenses/apsl.html';
INSERT INTO licenses SET license='The X.Net License', url='licenses/xnl.html';
UPDATE licenses SET license='The Sun Public License', url='licenses/spl.html' WHERE license='Sun Public License';
UPDATE licenses SET license='The Eiffel Forum License', url='licenses/efl.html' WHERE license='Eiffel Forum Freeware License';
UPDATE licenses SET license='The W3C License', url='licenses/w3cl.html' WHERE license='W3C Software';
INSERT INTO licenses SET license='The Motosoto License', url='licenses/ml.html';
INSERT INTO licenses SET license='The Open Group Test Suite License', url='licenses/ogtsl.html';
DELETE FROM licenses WHERE license='FreeBSD';
DELETE FROM licenses WHERE license='OpenBSD';
DELETE FROM licenses WHERE license='X11 License';

# NOT OS
 
UPDATE licenses SET license='OSI Approved (Open Source)', url='licenses/licnotavailable.html' WHERE license='Open Source';
UPDATE licenses SET license='Public Domain', url='licenses/pd.html' WHERE license='Public Domain';
INSERT INTO licenses SET license='The GNU Free Documentation License (FDL)', url='licenses/fdl.html';
UPDATE licenses SET license='The PHP License', url='licenses/phpl.html' WHERE license='PHP License';
INSERT INTO licenses SET license='The OpenLDAP Public License', url='licenses/oldapl.html';
UPDATE licenses SET license='The SUN Community Source License', url='licenses/scl.html' WHERE license='Sun Community Source License';
UPDATE licenses SET license='The Zope Public License (ZPL)', url='licenses/zpl.html' WHERE license='Zope Public License (ZPL)';
UPDATE licenses SET license='The Clarified Artistic License', url='licenses/cal.html' WHERE license='Clarified Artistic License';
UPDATE licenses SET license='The Netscape Public License (NPL)', url='licenses/npl10.html' WHERE license='Netscape Public License (NPL)';
INSERT INTO licenses SET license='The SUN Binary Code License', url='licenses/sbcl.html';
UPDATE licenses SET license='The Latex Project Public License (LPPL)', url='licenses/lppl.html' WHERE license='LaTeXProject Public License';
INSERT INTO licenses SET license='The Aladdin Free Public License (AFPL)', url='licenses/afpl.html';
INSERT INTO licenses SET license='The Open Content License', url='licenses/opcl.html';
INSERT INTO licenses SET license='The Voxel Public License (VPL)', url='licenses/voxpl.html';
INSERT INTO licenses SET license='The Open Public License', url='licenses/opl.html';
INSERT INTO licenses SET license='The Open Publication License', url='licenses/opul.html';
UPDATE licenses SET license='The Aladdin Free Public License (AFPL)', url='licenses/afpl.html' WHERE license='Artifex Public License';
UPDATE licenses SET license='The Arphic Public License', url='licenses/apl.html' WHERE license='Arphic Public License';
UPDATE licenses SET license='The Cryptix General License', url='licenses/cgl.html' WHERE license='Cryptix General License';
UPDATE licenses SET license='The FreeType License', url='licenses/ftl.html' WHERE license='FreeType License';
UPDATE licenses SET license='The Interbase Public License', url='licenses/ipl.html' WHERE license='Interbase Public License';
UPDATE licenses SET license='The Phorum License', url='licenses/pl.html' WHERE license='Phorum';
UPDATE licenses SET license='The Plan 9 Open Source License', url='licenses/p9osl.html' WHERE license='Plan 9 Open Source License';

UPDATE licenses SET license='The Open Compatibility License', url='licenses/licnotavailable.html' WHERE license='Open Compability License';
INSERT INTO licenses SET license='The GNAT Modified GPL (GMGPL)', url='licenses/licnotavailable.html';
INSERT INTO licenses SET license='The Free For Educational Use', url='licenses/licnotavailable.html';
UPDATE licenses SET license='Source-available Commercial', url='licenses/licnotavailable.html' WHERE license='source-available commercial';
UPDATE licenses SET license='Free Trail', url='licenses/licnotavailable.html' WHERE license='Free Trail';
UPDATE licenses SET license='Freely Distributable', url='licenses/freely_distributable.html' WHERE license='freely distributable';
UPDATE licenses SET license='Freeware', url='licenses/licnotavailable.html' WHERE license='Freeware';
UPDATE licenses SET license='Free for non-commercial use', url='licenses/licnotavailable.html' WHERE license='free for non-commercial use';
UPDATE licenses SET license='Free To Use But Restricted', url='licenses/licnotavailable.html' WHERE license='free to use but restricted';
UPDATE licenses SET license='Other/Proprietary License', url='licenses/licnotavailable.html' WHERE license='commercial';
UPDATE licenses SET license='Shareware', url='licenses/licnotavailable.html' WHERE license='Shareware';

INSERT INTO licenses SET license='Unknown', url='licenses/licnotavailable.html';
UPDATE licenses SET license='Artistic & GPL', url='licenses/artisticANDgl.html' WHERE license='Artistic & GPL';

DELETE FROM licenses WHERE license='Other';
DELETE FROM licenses WHERE license='UCL/LBL';
DELETE FROM licenses WHERE license='Artifex Public License (AFPL)';


#UPDATE licenses SET license='', url='licenses/licnotavailable.html' WHERE license='';

