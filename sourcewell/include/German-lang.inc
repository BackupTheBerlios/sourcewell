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
# File with the main German translation
# translated by Lutz Henckel <lutz.henckel@fokus.gmd.de>
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

switch($phrase) {

// Top strip
     case "Home": $tmp = "Heim"; break;
     case "About us": $tmp = "&Uuml;ber uns"; break;
     case "Partners": $tmp = "Partner"; break;
     case "Contact": $tmp = "Kontakt"; break;

     case "Logged in": $tmp = "Eingeloggt als"; break;
     case "Expires": $tmp = "Endet"; break;
     case "Not Logged in": $tmp = "Nicht eingeloggt"; break;

// Top title
     case "Open Source Software Announcement &amp; Retrieval":  $tmp = "Open Source Software Ank&uuml;ndigung &amp; Recherche"; break;

// Menue bar
     case "Recent Apps": $tmp = "Neueste Anw."; break;
     case "Q&amp;A": $tmp = "F&amp;A"; break;
     case "Login": $tmp = "Einloggen"; break;
     case "Logout": $tmp = "Ausloggen"; break;
     case "New User": $tmp = "Neuer Benutzer"; break;
     case "Forgot Password": $tmp = "Passwort vergessen"; break;
     case "Change User": $tmp = "Benutzer &auml;ndern"; break;
     case "Users": $tmp = "Benutzer"; break;

     case "Apps Index": $tmp = "Anw.-Index"; break;
     case "New Apps": $tmp = "Neue Anw."; break;
     case "Update Apps": $tmp = "Aktualisiere Anw."; break;
     case "Pending Apps": $tmp = "Prüfe Anw.";break;
     case "Deleted Apps": $tmp = "Gelöschte Anw.";break;
     case "Modified Apps": $tmp = "Modifizierte Anw.";break;

     case "Backend": $tmp = "$phrase"; break;
     case "Statistics": $tmp = "Statistiken"; break;

     case "Administration": $tmp = "Administration"; break;
     case "Sections": $tmp = "Sektionen"; break;
     case "Categories": $tmp = "Kategorien"; break;
     case "Authors": $tmp = "Autoren"; break;
     case "Licenses": $tmp = "Lizenzen"; break;
     case "Check Date": $tmp = "Prüfe Datum"; break;

     case "Search": $tmp = "Suche"; break;
     case "Language": $tmp = "Sprache"; break;
     case "Go": $tmp = "Los"; break;

// Languages
	 case "English": $tmp = "Englisch"; break;
	 case "German": $tmp = "Deutsch"; break;
	 case "Spanish": $tmp = "Spanisch"; break;

// sorted by
	 case "sorted by": $tmp = "sortiert nach"; break;
	 case "Date": $tmp = "Datum"; break;
	 case "Importance": $tmp = "Bedeutung"; break;
	 case "Urgency": $tmp = "Dringlichkeit"; break;
	 case "Name": $tmp = "Name"; break;

// FAQ
     case "Frequently Asked Questions": $tmp = "Oft gestellte Fragen"; break;
     case "Question": $tmp = "Frage"; break;
     case "Answer": $tmp = "Antwort"; break;

// Apps update
     case "Comment": $tmp = "Kommentar"; break;
     case "Review": $tmp = "Überprüfen"; break;
     case "Update": $tmp = "Aktualisieren"; break;
     case "Delete": $tmp = "Löschen"; break;
     case "Undelete": $tmp = "Wiederherstellen"; break;

// Apps not yet reviewed
     case "Waiting for Review by an Editor": $tmp = "Wartet auf Überprüfung durch einen Editor"; break;

// Apps by identifier
     case "Application": $tmp = "Anwendung"; break;
     case "Others by Author": $tmp = "Anderes vom Autor"; break;
     case "has not yet been reviewed by a $GLOBALS[sys_name] Editor.<br> Please, be patient. It will be surely done in the next time.": $tmp = "wurde noch nicht von einem $GLOBALS[sys_name] Editor überprüft.<br> Bitte haben Sie noch etwas Geduld. In n&auml;chster Zeit wird dies bestimmt geschehen."; break;
     case "is modified": $tmp = "ist modifiziert"; break;
     case "is deleted": $tmp = "ist gelöscht"; break;

// User registration
     case "Register as a new User": $tmp = "Registrierung als neuer Benutzer"; break;
     case "Username": $tmp = "Benutzername"; break;
     case "Password": $tmp = "Passwort"; break;
     case "Confirm Password": $tmp = "Passwort bestätigen"; break;
     case "Realname": $tmp = "Name"; break;
     case "Register": $tmp = "Registrieren"; break;
     case "User Registration": $tmp = "Benutzerregistrierung"; break;
     case "Congratulations": $tmp = "Gratulation"; break;
     case "You have registered on $GLOBALS[sys_name]": $tmp = "Sie haben sich bei $GLOBALS[sys_name] registriert"; break;
     case "Your new username is": $tmp = "Ihr neuer Benutzername ist"; break;
     case "You are now being sent a confirmation email to verify your email address": $tmp = "Es wurde eine Bestätigung per E-Mail an Sie gesendet, um Ihre E-Mail-Adresse zu überprüfen"; break;
     case "Visiting the link sent to you in this email will activate your account": $tmp = "Wenn Sie die in dieser E-Mail gesendete Seite besuchen wird Ihre Benutzerkennung freigeschaltet"; break;
     case "Thank you for registering on the $GLOBALS[sys_name] Site. In order": $tmp = "Danke für Ihre Registrierung bei $GLOBALS[sys_name]. Um Ihre"; break;
     case "to complete your registration, visit the following URL": $tmp = "Registrierung abzuschließen, besuchen Sie die folgende URL"; break;
     case "Enjoy the site": $tmp = "Wir hoffen, dass Ihnen $GLOBALS[sys_name] gefällt"; break;
     case " -- the $GLOBALS[sys_name] crew": $tmp = " -- die $GLOBALS[sys_name] Crew"; break;
     case "Verification of Registration": $tmp = "Verifikation der Registrierung"; break;
     case "Your account is now activated. Please login": $tmp = "Ihre Benutzerkennung ist jetzt freigeschaltet. Bitte loggen Sie sich ein"; break;

// Forget password / Remind me
     case "Register as a new User": $tmp = "Registrierung als neuer Benutzer"; break;
     case "Remind me": $tmp = "Erinnern"; break;
     case "Your Username and Password for $GLOBALS[sys_name] is": $tmp = "Ihr Benutzername und Passwort für $GLOBALS[sys_name] ist"; break;
     case "Please keep this e-mail for further reference": $tmp = "Bitte bewahren Sie diese E-Mail zur späteren Referenzierung auf"; break;
     case "You will get your Password by e-mail in a couple of minutes": $tmp = "Sie erhalten Ihr Passwort per E-Mail in wenigen Minuten"; break;

// Change User Parameters
     case "Change User Parameters": $tmp = "Änderung der Benutzerdaten"; break;
     case "Remind me": $tmp = "Erinnerung"; break;
     case "Modification": $tmp = "Modifiziert"; break;
     case "Creation": $tmp = "Erzeugt"; break;
     case "Permission": $tmp = "Rechte"; break;
     case "Change": $tmp = "Ändern"; break;
     case "Password and/or E-Mail Address of": $tmp = "Passwort und/oder E-Mail-Adresse von"; break;
     case "is changed": $tmp = "wurden geändert"; break;

// Apps by category
     case "Homepage": $tmp = "Homepage"; break;
     case "Download": $tmp = "Download"; break;
     case "Changelog": $tmp = "Changelog"; break;
     case "Comments": $tmp = "Kommentare"; break;
     case "Type": $tmp = "Typ"; break;
     case "Updated": $tmp = "Aktualisiert"; break;
     case "Created": $tmp = "Erzeugt"; break;
     case "Stable": $tmp = "Stabil"; break;
     case "Development": $tmp = "Entwicklung"; break;
     case "License": $tmp = "Lizenz"; break;

// New Apps
     case "New Application": $tmp = "Neue Anwendung"; break;
     case "Application Name": $tmp = "Anwendungsname"; break;
     case "Insert": $tmp = "Einfügen"; break;

// Insert Apps
     case "Insert Application": $tmp = "Anwendung einfügen"; break;
     case "Version": $tmp = "Version"; break;
     case "Section/Category": $tmp = "Sektion/Kategorie"; break;
     case "Red Hat Package": $tmp = "Red Hat Paket"; break;
     case "Debian Package": $tmp = "Debian Paket"; break;
     case "Slackware Package": $tmp = "Slackware Paket"; break;
     case "CVS Tree": $tmp = "CVS Baum"; break;
     case "Screenshots": $tmp = "Screenshots"; break;
     case "Mailing List Archive": $tmp = "Mailing List Archiv"; break;
     case "Description": $tmp = "Beschreibung"; break;
     case "Author": $tmp = "Autor"; break;
     case "Depends on": $tmp = "Abhängig von"; break;
	 case "low": $tmp = "gering"; break;
	 case "medium": $tmp = "mittel"; break;
	 case "high": $tmp = "hoch"; break;

// Update Apps
     case "Update Application": $tmp = "Anwendung aktualisieren"; break;
     case "Application ID": $tmp = "Anwendungs-ID"; break;
     case "Announcements": $tmp = "Ankündigungen"; break;
     case "active": $tmp = "aktiv"; break;
     case "pending": $tmp = "wartend"; break;
     case "deleted": $tmp = "gelöscht"; break;
     case "Check": $tmp = "Prüfen"; break;

// Comment
     case "Your Comment about": $tmp = "Ihr Kommentar zu"; break;
     case "Subject": $tmp = "Thema"; break;
     case "Comment": $tmp = "Kommentar"; break;
     case "Send": $tmp = "Senden"; break;

// Login
     case "$GLOBALS[sys_name] Login": $tmp = "Bei $GLOBALS[sys_name] Einloggen"; break;
     case "Welcome to $GLOBALS[sys_name]": $tmp = "Willkommen bei $GLOBALS[sys_name]"; break;
     case "You are logged in as": $tmp = "Sie sind eingeloggt als"; break;
     case "with": $tmp = "mit"; break;
     case "permission": $tmp = "Rechten"; break;
     case "Your authentication is valid until": $tmp = "Ihre Authentifizierung ist gültig bis"; break;

// Logout
     case "You have been logged in as": $tmp = "Sie waren eingeloggt als"; break;
     case "Your authentication was valid until": $tmp = "Ihre Authentifizierung war gültig bis"; break;
     case "This is all over now. You have been logged out": $tmp = "Dies ist nun vorbei. Sie haben sich ausgeloggt"; break;

// User admin
     case "Action": $tmp = "Aktion"; break;
     case "Delete": $tmp = "Löschen"; break;
     case "Create User": $tmp = "Benutzer Erzeugen"; break;
     case "User Creation": $tmp = "Benutzer einrichten"; break;
     case "created": $tmp = "eingerichtet"; break;
     case "User Change": $tmp = "Benutzer Ändern"; break;
     case "User Deletion": $tmp = "Benutzer Löschen"; break;
     case "is deleted": $tmp = "wurden gelöscht"; break;

// Section admin
     case "Section Administration": $tmp = "Sektionsadministration"; break;
     case "Insert a Section": $tmp = "Sektion hinzufügen"; break;
     case "Rename a Section": $tmp = "Sektion umbenennen"; break;
     case "Delete a Section": $tmp = "Sektion löschen"; break;
     case "New Section": $tmp = "Neue Sektion"; break;
     case "New Section Name": $tmp = "Neuer Sektionsname"; break;
     case "Section": $tmp = "Sektion"; break;
     case "Rename": $tmp = "Umbenennen"; break;

// Category admin
     case "Category Administration": $tmp = "Kategorieadministration"; break;
     case "Insert a Category": $tmp = "Kategorie hinzufügen"; break;
     case "Rename a Category": $tmp = "Kategorie umbenennen"; break;
     case "Delete a Category": $tmp = "Kategorie löschen"; break;
     case "New Category": $tmp = "Neue Kategorie"; break;
     case "New Category Name": $tmp = "Neuer Kategoriename"; break;
     case "Category": $tmp = "Kategorie"; break;

// License admin
     case "License Administration": $tmp = "Lizenzadministration"; break;
     case "Insert a License": $tmp = "Lizenz hinzufügen"; break;
     case "Rename a License": $tmp = "Lizenz umbenennen"; break;
     case "Change a License URL": $tmp = "Lizenz-URL ändern"; break;
     case "Delete a License": $tmp = "Lizenz löschen"; break;
     case "New License": $tmp = "Neue Lizenz"; break;
     case "License URL": $tmp = "Lizenz-URL"; break;
     case "New License Name": $tmp = "Neuer Lizenzname"; break;
     case "New License URL": $tmp = "Neue Lizenz-URL"; break;
     case "License": $tmp = "Lizenz"; break;

// Announcements
    case "by": $tmp = "von"; break;
    case "on": $tmp = "am"; break;
	case "hits": $tmp = "Zugriffe"; break;

// Time-based Navigation
    case "Day": $tmp = "Tag"; break;
    case "Today": $tmp = "Heute"; break;
    case "Week": $tmp = "Woche"; break;

// Search
    case "No Application found": $tmp = "Keine Anwendung gefunden"; break;

// Apps by user
     case "Apps of User": $tmp = "Anw. des Benutzers"; break;
     case "No Apps of User exist": $tmp = "Es existiert keine Anwendung des Benutzers"; break;

// Pending Apps
     case "No pending Apps exist": $tmp = "Es existiert keine zu überprüfende Anwendung"; break;

// Deleted or modified apps
     case "Is deleted": $tmp = "Ist gelöscht"; break;
     case "Is modified": $tmp = "Ist modifiziert"; break;
     case "No deleted Apps exist": $tmp = "Es existieren keine gelöschten Anwendungen"; break;
     case "No modified Apps exist": $tmp = "Es existieren keine modifizierten Anwendungen"; break;

// Users
    case "No": $tmp = "Nr"; break;
    case "All": $tmp = "Alle"; break;

// Developers
    case "Names": $tmp = "Namen"; break;
    case "Unknown": $tmp = "Unbekannt"; break;

// Licences
     case "Apps": $tmp = "Anw."; break;

// Check Date
     case "All dates are consistent": $tmp = "Alle Daten sind konsistent"; break;

// Newsletter
     case "Subscribe Newsletter": $tmp = "Newsletter abonnieren"; break;
     case "Subscribe": $tmp = "Abonnieren"; break;
     case "Send newsletter": $tmp = "Sende Newsletter"; break;
     case "Newsletter was sent at ": $tmp = "Newsletter wurde gesendet am "; break;
     case "You have subscribed to $GLOBALS[sys_name] Newsletter": $tmp = "Sie haben den $GLOBALS[sys_name] Newsletter abonniert"; break;
     case "Daily Newsletter": $tmp = "Täglicher Newsletter"; break;
     case "Weekly Newsletter": $tmp = "Wöchentlicher Newsletter"; break;
     case "daily": $tmp = "täglich"; break;
     case "weekly": $tmp = "wöchentlich"; break;

// Statistics
	 case "$GLOBALS[sys_name] Statistics": $tmp = "$GLOBALS[sys_name] Statistiken"; break;
	 case "General $GLOBALS[sys_name] Statistics": $tmp = "Generelle $GLOBALS[sys_name] Statistiken"; break;
	 case "Apps by Importance": $tmp = "Anw. nach Bedeutung"; break;
	 case "Apps by Hits": $tmp = "Anw. nach Zugriffen"; break;
	 case "Apps by Homepage Visits": $tmp = "Anw. nach Homepage-Besuchen"; break;
	 case "Apps by Downloads": $tmp = "Anw. nach Downloads"; break;
	 case "Top downloaded RPM Packages": $tmp = "Top der heruntergeladenen RPM-Pakete"; break;
	 case "Top downloaded Debian Packages": $tmp = "Top der heruntergeladenen Debian-Pakete"; break;
	 case "Top downloaded Slackware Packages": $tmp = "Top der heruntergeladenen Slackware-Pakete"; break;
	 case "Apps and Downloads by Urgency": $tmp = "Anw. und Downloads nach Dringlichkeit"; break;
	 case "Apps and Downloads by Version Types": $tmp = "Anw. und Downloads nach Versionstypen"; break;
	 case "Apps and Importance by Sections": $tmp = "Anw. und Bedeutung nach Sektionen"; break;
	 case "Apps by Categories": $tmp = "Anw. nach Kategorien"; break;
	 case "Apps by Version Numbers": $tmp = "Anw. nach Versionsnummern"; break;
	 case "Apps and Downloads by Package Formats": $tmp = "Anw. und Downloads nach Paketformaten"; break;
	 case "Importance by Licenses": $tmp = "Bedeutung nach Lizenzen"; break;
	 case "Importance by Email Domains": $tmp = "Bedeutung nach E-Mail-Domainen"; break;
	 case "Apps by Email Domains": $tmp = "Anw. nach E-Mail-Domainen"; break;
	 case "Apps by Sections and Email Domains": $tmp = "Anw. nach Sektionen und E-Mail-Domainen"; break;
	 case "Apps by Licenses": $tmp = "Anw. nach Lizenzen"; break;
	 case "Apps by Licenses and Email Domains": $tmp = "Anw. nach Lizenzen und E-Mail-Domainen"; break;

// General Statistics
	 case "Number of Applications in $GLOBALS[sys_name]": $tmp = "Anzahl der Anwendungen in $GLOBALS[sys_name]"; break;
	 case "Total Number of Insertions and Modifications": $tmp = "Gesamtzahl der Eintragungen und Modifikationen"; break;
	 case "Number of Insertions and Modifications during the last week": $tmp = "Anzahl der Eintragungen und Modifikationen in der letzen Woche"; break;
	 case "Number of pending Applications": $tmp = "Anzahl der zu prüfenden Anwendungen"; break;
	 case "Number of $GLOBALS[sys_name] authorised Users": $tmp = "Anzahl der bei $GLOBALS[sys_name] registrierten Benutzer"; break;
	 case "Number of Comments on Applications": $tmp = "Anzahl der Kommentare zu Anwendungen"; break;
	 case "Number of Licenses listed in $GLOBALS[sys_name]": $tmp = "Anzahl der Lizenzen in $GLOBALS[sys_name]"; break;
	 case "Number of $GLOBALS[sys_name] Sections": $tmp = "Anzahl der Sektionen in $GLOBALS[sys_name]"; break;
	 case "Number of $GLOBALS[sys_name] Categories": $tmp = "Anzahl der Kategorien in $GLOBALS[sys_name]"; break;
	 case "Total Number of Hits on Applications": $tmp = "Gesamtzahl der Zugriffe auf Anwendungen"; break;
	 case "Number of redirected Homepages": $tmp = "Anzahl der Zugriffe auf Homepages"; break;
	 case "Number of Downloads": $tmp = "Anzahl der Zugriffe auf Downloads"; break;
	 case "Number of redirected Changelogs": $tmp = "Anzahl der Zugriffe auf Changlogs"; break;
	 case "Number of redirected CVSs": $tmp = "Anzahl der Zugriffe auf CVS-Verzeichnisse"; break;
	 case "Number of redirected Screenshots": $tmp = "Anzahl der Zugriffe auf Screenshots"; break;
	 case "Number of redirected Mailing Lists Archives": $tmp = "Anzahl der Zugriffe auf Mailing-Lists-Archive"; break;
	 case "$GLOBALS[sys_name] Version": $tmp = "$GLOBALS[sys_name] Version"; break;

	 case "High Urgency": $tmp = "Hohe Bedeutung"; break;
	 case "Medium Urgency": $tmp = "Mittlere Bedeutung"; break;
	 case "Low Urgency": $tmp = "Geringe Bedeutung"; break;
	 case "Stable Version": $tmp = "Stabile Version"; break;
	 case "Development Version": $tmp = "Entwicklungsversion"; break;
	 case "Version Number": $tmp = "Versionsnummer"; break;
	 case "Tarballs": $tmp = "$phrase"; break;
	 case "Red Hat Packages": $tmp = "Red Hat Pakete"; break;
	 case "Debian Packages": $tmp = "Debian Pakete"; break;
	 case "Slackware Packages": $tmp = "Slackware Pakete"; break;
	 case "Applications listed by their Importance": $tmp = "Anwendungen geordnet nach ihrer Bedeutung"; break;
	 case "Applications listed by Number of Tarball-Downloads": $tmp = "Anwendungen geordnet nach Anzahl der Tarball-Downloads"; break;
	 case "Applications listed by Number of Hits": $tmp = "Anwendungen geordnet nach Anzahl der Zugriffe"; break;
	 case "Applications listed by Homepage Visits": $tmp = "Anwendungen geordnet nach Anzahl der Homepage-Besuche"; break;
	 case "Top downloaded Red Hat Packages": $tmp = "Top der heruntergeladenen RPM-Pakete"; break;
	 case "Top downloaded Debian Packages": $tmp = "Top der heruntergeladenen Debian-Pakete"; break;
	 case "Top downloaded Debian Packages": $tmp = "Top der heruntergeladenen Debian-Pakete"; break;
	 case "Application Importance listed by Sections": $tmp = "Anwendungsbedeutung geordnet nach Sektionen"; break;
	 case "Applications listed by Sections": $tmp = "Anwendungen geordnet nach Sektionen"; break;
	 case "Applications listed by Categories": $tmp = "Anwendungen geordnet nach Kategrien"; break;
	 case "Applications listed by Licenses": $tmp = "Anwendungen geordnet nach Lizenzen"; break;
	 case "Availability of downloadable Packet Formats": $tmp = "Verfügbarkeit von herunterladbaren Paketformaten"; break;
	 case "Downloads listed by Packet Formats": $tmp = "Downloads geordnet nach Paketformaten"; break;
	 case "Applications listed by Urgency": $tmp = "Anwendungen geordnet nach Dringlichkeit"; break;
	 case "Downloads listed by Urgency": $tmp = "Downloads geordnet nach Dringlichkeit"; break;
	 case "Applications listed by Version Numbers": $tmp = "Anwendungen geordnet nach Versionsnummern"; break;
	 case "Applications listed by Licenses": $tmp = "Anwendungen geordnet nach Lizenzen"; break;
	 case "Applications listed by Version Type": $tmp = "Anwendungen geordnet nach Versionstypen"; break;
	 case "Downloads listed by Version Type": $tmp = "Downloads geordnet nach Versionstypen"; break;
	 case "Application Importance listed by Licenses": $tmp = "Anwendungsbedeutung geordnet nach Lizenzen"; break;
	 case "Application Importance listed by Developer's Email Domains": $tmp = "Anwendungsbedeutung geordnet nach E-Mail-Domainen der Entwickler"; break;
	 case "Applications listed by Developer's Email Domain": $tmp = "Anwendungen geordnet nach E-Mail-Domainen der Entwickler"; break;
	 case "Applications listed by Sections and Developer's Email Domain": $tmp = "Anwendungen geordnet nach Sektionen und E-Mail-Domainen der Entwickler"; break;
	 case "Applications listed by Licenses and Developer's Email Domain": $tmp = "Anwendungen geordnet nach Lizenzen und E-Mail-Domainen der Entwickler"; break;

// Errors
     case "Access denied": $tmp = "Zugriff verweigert"; break;
     case "Error": $tmp = "Fehler"; break;
     case "does not exist": $tmp = "existiert nicht"; break;
     case "Change User Parameters failed": $tmp = "Änderung der Benutzerdaten ist fehlgeschlagen"; break;
     case "No Application ID specified": $tmp = "Keine Anwendungs-ID angegeben"; break;
     case "No Application Name specified": $tmp = "Kein Anwendungsname angegeben"; break;
     case "Please select": $tmp = "Bitte wählen Sie"; break;
     case "Parameter missing": $tmp = "Parameter fehlt"; break;
     case "and": $tmp = "und"; break;
     case "User": $tmp = "Benutzer"; break;
     case "already exists": $tmp = "existiert bereits"; break;
     case "Please select a different Username": $tmp = "Bitte wählen Sie einen anderen Benutzernamen"; break;
     case "Please enter": $tmp = "Bitte angeben:"; break;
     case "Either your Username or E-Mail Address is unknown": $tmp = "Entweder Ihr Benutzername oder E-Mail-Adresse ist unbekannt"; break;
     case "Please try again": $tmp = "Bitte versuchen Sie es nochmal"; break;
     case "If you are not yet a registered User, please select": $tmp = "Wenn Sie noch kein registrierter Benutzer sind, wählen Sie bitte"; break;
     case "Verification of Registration failed": $tmp = "Verifikation der Registrierung ist fehlgeschlagen"; break;
     case "User Change failed": $tmp = "Benutzer ändern ist fehlgeschlagen"; break;
     case "Registration of new User failed": $tmp = "Registrierung des neuen Benutzers ist fehlgeschlagen"; break;
     case "Database Access failed": $tmp = "Datenbankzugriff ist fehlgeschlagen"; break;
     case "User Deletion failed": $tmp = "Benutzer Löschen ist fehlgeschlagen"; break;
     case "No more Apps for this day": $tmp = "Keine weiteren Anwendungen für diesen Tag"; break;
     case "Either your Username or Password are invalid": $tmp = "Entweder Ihr Benutzername oder Passwort ist falsch"; break;
     case "The passwords are not identical": $tmp = "Die Passworte sind nicht identisch"; break;
     case "Please try again": $tmp = "Bitte versuchen Sie es nochmal"; break;
     case "License description is not available": $tmp = "Lizenzbeschreibung ist nicht verfügbar"; break;

// If no translation available, keep the original phrase
     default: $tmp = "$phrase"; break;
}
?>
