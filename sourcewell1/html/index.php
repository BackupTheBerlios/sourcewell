<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ====================================================
#
# Copyright (c) 2001-2003 by
#                Lutz Henckel (lutz.henckel@fokus.fraunhofer.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# The SourceWell Project Page
#
# It also shows the number of apps in each one
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
###################################################################### 

require("./include/header.inc");

?>

<!-- content -->

<P><H2>SourceWell</H2>

<P><b>Latest Stable Version: 1.1.1</B>
<br><b>BerliOS SourceWell (<a href="http://sourcewell.berlios.de">http://sourcewell.berlios.de</a>): 1.1.1</b>

<p><b>Demo site</b>: <a href="http://sourcewell.berlios.de">BerliOS SourceWell</a> with <b>more than 2000 applications</b>!

<P>SourceWell is a highly configurable software announcement and retrieval system entirely written in <a href="http://www.php.net/">PHP</a> and is based upon a <a href="http://www.mysql.com/">MySQL</a> database. It includes user authentication and authorization system (anonymous/user/editor/admin), sessions with and without cookies, high configurability, multilangual support, ease of administration, RDF-type document backend, advanced statistics, announcing mailing lists, application indexing by sections, installation support  and many other useful features.

<P>SourceWell depends on the <a href="http://phplib.sourceforge.net/">PHPLib</a> library (version 7.2d). Only if you want to have diary and weekly mailing lists with the announcements, you should also have Mailman installed in your box.

<P>You can see a fully working example of the SourceWell system at BerliOS
SourceWell by visiting <A HREF="http://sourcewell.berlios.de">http://sourcewell.berlios.de</A>. A close look at it will show you what
you can do with SourceWell. BerliOS SourceWell has at this moment more
than 2000 applications inserted and has been the main reason why we have
made this software.

<P>SourceWell can be easily translated into different
languages. If you see that SourceWell does not have support in your
language, you're gladly invited to <A HREF="translating.php">help us with the
internationalization</A> of SourceWell by sending us your translation.

<P>You can download the latest version of SourceWell (sources and documentation) at:
<A HREF="http://developer.berlios.de/projects/sourcewell">http://developer.berlios.de/projects/sourcewell</A>


<P>BerliOS SourceWell is part of the BerliOS project at FOKUS. Please, have
a look at <A HREF="http://www.berlios.de">http://www.berlios.de</A> for further information.

<P>SourceWell Features:
<UL>
<LI>Different type of users (nonauthorized users, anonymous user, users, editors and administrators) with different functions
<LI>Session management with and without cookies (beta)
<LI>based upon MySQL database
<LI>Advanced configurability from a single file
<LI>Simple, intuitive use of the system
<LI>Documentation for further development and/or adjustment
<LI>Comments on applications
<LI>Through-the-web reviewing and application administration for editors
<LI>Through-the-web administration of applications, comments and licenses
<LI>system FAQ and through-the-web administration of it
<LI>Dynamic order of applications by date (default), importance, urgency or
by alphabetical order
<LI>"true" software counter for apps download, homepage redirections, etc.
<LI>Multilingual support
<LI>Anonymous users can introduce apps and comments
<LI>The administrator can easily administrate whether there are anonymous users allowed or not
<LI>Dynamic permission configuration
<LI>Stable and development branches for applications
<LI>XML Backend (RDF-document format)
<LI>Daily and Weekly automatic Newsletters
<LI>Version history of the applications
<LI>Links between apps from the same author
<LI>"intelligent" application validation for editors
<LI>EMail advice for editors when apps are inserted or updated
<LI>EMail advice for administrators when new users register
<LI>Graphical statistics (a lot of them!)
<LI>Test page (very helpfull when installing the system and something goes wrong)
<LI>Web browser independence
<LI>Cache avoidance
</UL>

<P>&nbsp;

<!-- end content -->

<?php
require("./include/footer.inc");
?>
