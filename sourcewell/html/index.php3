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
# The SourceWell Project Page
#
# It also shows the number of apps in each one
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
###################################################################### 

require("header.inc");

?>

<!-- content -->

<P><H2>SourceWell</H2>

<P>SourceWell is an announce and retrieval system for software applications.

<P>It is based in <A HREF="http://www.php.net">PHP3</A> and uses <A HREF="http://www.mysql.com">MySQL</A> as its database system. SourceWell depends on
the <A HREF="http://phplib.netuse.de/">PHPLib library</A> (version 7.2 or
later). Future versions may have database independence, but this is
not yet supported. We are still working on it. Only if you want to have
diary and weekly mailing lists with the announcements, you should also have
Mailman installed in your box.

<P>You can see a fully working example of the SourceWell system at BerliOS
SourceWell by visiting <A HREF="http://sourcewell.berlios.de">http://sourcewell.berlios.de</A>. A close look at it will show you what
you can do with SourceWell. BerliOS SourceWell has at this moment more
than 750 applications inserted and has been the main reason why we have
made this software.

<P>BerliOS SourceWell is part of the BerliOS project at GMD FOKUS. Please, have
a look at <A HREF="http://www.berlios.de">http://www.berlios.de</A> for further information.

<P>SourceWell can be easily translated into different
languages. If you see that SourceWell does not have support in your
language, you're gladly invited to <A HREF="translating.php3">help us with the
internationalization</A> of SourceWell by sending us your translation.

<P>You can download the latest version of SourceWell (sources and documentation) at:
<A HREF="http://developer.berlios.de/projects/sourcewell">http://developer.berlios.de/projects/sourcewell</A>

<P>SourceWell Features:
<UL>
<LI>Different type of users (nonauthorized users, users, editors and
administrators) with different functions
<LI>Advanced configurability from a single file
<LI>Simple, intuitive use of the system
<LI>Session management with and without cookies
<LI>Through-the-web reviewing and application administration for editors
<LI>Through-the-web administration of applications, comments and licenses
<LI>Dynamic order of applications by date (default), importance, urgency or
by alphabetical order
<LI>"true" software counter for apps download, homepage redirections, etc.
<LI>Multilingual support
<LI>Stable and development branches for applications
<LI>XML Backend (RDF-document format)
<LI>Daily and Weekly automatic Newsletters
<LI>Comments on applications
<LI>Version history of the applications
<LI>FAQ
<LI>Links between apps from the same author
<LI>"intelligent" application validation for editors
<LI>EMail advice for editors when apps are inserted or updated
<LI>EMail advice for administrators when new users register
<LI>Graphical statistics
<LI>Web browser independence
<LI>Cache avoidance
<LI>Documentation for further development and/or adjustment
</UL>

<P>&nbsp;

<!-- end content -->

<?php
require("footer.inc");
?>
