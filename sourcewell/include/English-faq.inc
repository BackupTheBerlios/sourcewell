<?php

$qa = array (

	"How to change my Password or E-mail address I am registered with?" =>
		"Select \"<a href=chguser.php3>".$t->translate("Change User")."</a>\" and enter your new parameters. ",

	"I have submitted an announcement but it is not shown?" =>
		"All submissions are verified by a $sys_name editor. "
    	."This will take some time, but it is normally done during the same "
		."day you have submitted your announcement.",

	"One of the announcements I have submitted is not longer shown when I use \"".$t->translate("Update Apps")."\"?" =>
		"Another user has changed the announcement and is now the new owner. "
    	."If you like to change it again, "
		."browse the \"<a href=categories.php3>".$t->translate("Apps Index")."</a>\" for the announcement and use the update bottom "
		."or select \"<a href=insform.php3>".$t->translate("New Apps")."</a>\" and enter the name of the application you like to change.",

	"How to remove an announcement out of $sys_name?" =>
		"Send a message by email to "
		."<a href=mailto:$ml_newsadmaddr>$ml_newsadmaddr</a> "
		."explaining the reason for removing it. Then we will do it for you. "
		."Please don't change announcements by deleting some or all information fields.",

		"Why is $sys_name not in my language?" =>
		     "$sys_name can be easily translated "
		     ."into different languages. If you see that "
		     ."$sys_name does not have support in your "
		     ."language, you're gladly invited to help us with "
		     ."the internationalization. Visit "
		     ."<A HREF=\"http://sourcewell.berlios.de/html/translating.php3\">http://sourcewell.berlios.de/html/translating.php3</A>",


	"Do you send a $sys_name newsletter by e-mail?" =>
		"There are two mailing lists available for everyone to subscribe to. "
    	."The newsletter is sent once a day or once a week containing all software news "
		."of the current day or week. To subscribe, send a message by email to "
		."<a href=mailto:$ml_newsreqaddr?subject=subscribe>$ml_newsreqaddr (daily)</a> "
		."or <a href=mailto:$ml_weeklynewsreqaddr?subject=subscribe>$ml_weeklynewsreqaddr (weekly)</a>"
		." with the subject <tt>subscribe</tt> or visit "
		."<a href=$ml_listurl target=_blank>$ml_listurl (daily)</a> "
		."or <a href=$ml_weeklylisturl target=_blank>$ml_weeklylisturl (weekly)</a>",


	"How to unsubscribe from the $sys_name newsletter mailing lists?" =>
		"Send a message by email to "
		."<a href=mailto:$ml_newsreqaddr?subject=".rawurlencode("unsubscribe <password>").">$ml_newsreqaddr (daily)</a> "
		."or <a href=mailto:$ml_weeklynewsreqaddr?subject=".rawurlencode("unsubscribe <password>").">$ml_weeklynewsreqaddr (weekly)</a>"
		." with <tt>unsubscribe &lt;password&gt;</tt> as subject or visit "
		."<a href=$ml_listurl target=_blank>$ml_listurl (daily)</a> "
		."or <a href=$ml_weeklylisturl target=_blank>$ml_weeklylisturl (weekly)</a> "
		."and follow the instructions there."

);
?>
