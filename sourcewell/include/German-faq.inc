<?php

$qa = array (

	"Wie ändere ich mein Passwort oder E-Mail-Adresse?" =>
		"Wählen Sie \"<a href=chguser.php3>".$t->translate("Change User")."</a>\" und geben Sie Ihre neuen Daten ein. ",

	"Ich habe eine Ankündigung erstellt, die aber nicht erscheint!" =>
		"Alle Ankündigungen werden von einem $sys_name-Editor überprüft. "
    	."Dies kann einige Zeit dauern, aber erfolgt normalerweise innerhalb des gleichen Tages, an dem Sie Ihre Ankündigung erstellt haben.",

	"Eine Ankündigung, die ich erstellt habe, ist nicht länger sichtbar, wenn ich \"".$t->translate("Update Apps")."\" benutze!" =>
		"Ein anderer Benutzer hat die Ankündigung geändert und ist der neuer Besitzer. "
    	."Wenn Sie sie erneut ändern wollen, "
		."suchen Sie im \"<a href=categories.php3>".$t->translate("Apps Index")."</a>\" nach der Ankündigung und nutzen den ".$t->translate("Update")."-Knopf "
		."oder wählen \"<a href=insform.php3>".$t->translate("New Apps")."</a>\" und geben den Namen der Anwendung ein, die Sie ändern möchten.",

	"Wie wird eine Ankündigung in $sys_name gelöscht?" =>
		"Senden Sie eine Nachricht per E-Mail an "
		."<a href=mailto:$ml_newsadmaddr>$ml_newsadmaddr</a> "
		."und erläutern Sie die Gründe für die Löschung. Wir löschen sie dann für Sie. "
		."Bitte ändern Sie die Ankündigung nicht durch Löschen einzelner oder aller Informationsfelder.",

	"Gibt es einen $sys_name-Newsletter, der per E-Mail verschickt wird?" =>
		"Es existiert zwei Mailing-Listen, die jeder abonnieren kann. "
    		."Der Newsletter wird einmal täglich bzw. einmal wöchentlich verschickt und enthält alle Ankündigungen "
		."des laufenden Tages bzw. der letzten Woche. Zum Abonnieren senden Sie eine Nachricht per E-Mail an "
		."<a href=mailto:$ml_newsreqaddr?subject=subscribe>$ml_newsreqaddr (täglich)</a> "
		."oder <a href=mailto:$ml_weeklynewsreqaddr?subject=subscribe>$ml_weeklynewsreqaddr (wöchentlich)</a> "
		." mit dem Subjekt <tt>subscribe</tt> oder besuchen Sie "
		."<a href=$ml_listurl target=_blank>$ml_listurl (täglich)</a> "
		."bzw. <a href=$ml_weeklylisturl target=_blank>$ml_listurl (wöchentlich)</a>.",

		"Warum ist $sys_name nicht in meiner Sprache?" =>
		     "$sys_name kann in andere Sprachen sehr einfach "
		     ."&uuml;bersetzt werden. Wenn Sie sehen, dass "
		     ."$sys_name ihre Sprache nicht unterst&uuml;tzt, "
		     ."dann sind Sie herzlich eingeladen, uns bei der "
		     ."Internationalisation zu helfen. Besuchen Sie "
		     ."<A HREF=\"http://sourcewell.berlios.de/html/translating.php3\">http://sourcewell.berlios.de/html/translating.php3</A>",

	"Wie bestelle ich den $sys_name-Newsletter ab?" =>
		"Senden Sie eine Nachricht per E-Mail an "
		."<a href=mailto:$ml_newsreqaddr?subject=".rawurlencode("unsubscribe <password>").">$ml_newsreqaddr (täglich)</a> "
		."bzw. <a href=mailto:$ml_weeklynewsreqaddr?subject=".rawurlencode("unsubscribe <password>").">$ml_weeklynewsreqaddr (wöchentlich)</a> "
		." mit <tt>unsubscribe &lt;password&gt;</tt> als Subjekt oder besuchen Sie "
		."<a href=$ml_listurl target=_blank>$ml_listurl (täglich)</a> "
		."bzw. <a href=$ml_weeklylisturl target=_blank>$ml_weeklylisturl (wöchentlich)</a> "
		."und führen die dort beschriebenen Instruktionen aus."

);
?>
