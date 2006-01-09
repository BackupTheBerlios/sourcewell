<?php

######################################################################
# SourceWell: Software Announcement & Retrieval System
# ================================================
#
# Copyright (c) 2001-2004 by
#                Lutz Henckel (lutz.henckel@fokus.fraunhofer.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceWell: http://sourcewell.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# File with the main italian translation
# translated by Sandro Tosi <matrixhasu@gmail.com>
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

switch($phrase) {

// Top strip
     case "Home": $tmp = "Pagina Principale"; break;
     case "About us": $tmp = "Informazioni su di noi"; break;
     case "Partners": $tmp = "Partner"; break;
     case "Contact": $tmp = "Contatti"; break;

     case "Logged in": $tmp = "Login Effettuato"; break;
     case "Expires": $tmp = "Sessione scaduta"; break;
     case "Not Logged in": $tmp = "Login Non Effettuato"; break;

// Top title
     case "Open Source Software Announcement &amp; Retrieval":  $tmp = "Annunci e Richiami a Software Open Source"; break;

// Menue bar
     case "Recent Apps": $tmp = "Applicazioni Recenti"; break;
     case "Q&amp;A": $tmp = "FAQ"; break;
     case "Login": $tmp = "Login"; break;
     case "Logout": $tmp = "Esci"; break;
     case "New User": $tmp = "Nuovo Utente"; break;
     case "Forgot Password": $tmp = "Password Dimenticata"; break;
     case "Change User": $tmp = "Cambia Utente"; break;
     case "Users": $tmp = "Utenti"; break;

     case "Apps Index": $tmp = "Indice delle Applicazioni"; break;
     case "New Apps": $tmp = "Nuove Applicazioni"; break;
     case "Update Apps": $tmp = "Aggiorna Applicazioni"; break;
     case "Pending Apps": $tmp = "Applicazioni Pendenti";break;
     case "Deleted Apps": $tmp = "Applicazioni Cancellate";break;
     case "Modified Apps": $tmp = "Applicazioni Modificate";break;

     case "Backend": $tmp = "Backend"; break;
     case "Statistics": $tmp = "Statistiche"; break;

     case "Administration": $tmp = "Amministrazione"; break;
     case "Sections": $tmp = "Sezioni"; break;
     case "Categories": $tmp = "Categorie"; break;
     case "Authors": $tmp = "Autori"; break;
     case "Licenses": $tmp = "Licenze"; break;
     case "Check Date": $tmp = "Controlla la Data"; break;

     case "Search": $tmp = "Ricerca"; break;
     case "Language": $tmp = "Lingua"; break;
     case "Go": $tmp = "Vai"; break;

// Languages
	 case "English": $tmp = "Inglese"; break;
	 case "German": $tmp = "Tedesco"; break;
	 case "Spanish": $tmp = "Spagnolo"; break;
	 case "Italian": $tmp = "Italiano"; break;

// sorted by
	 case "sorted by": $tmp = "ordinato per"; break;
	 case "Date": $tmp = "Data"; break;
	 case "Importance": $tmp = "Importanza"; break;
	 case "Urgency": $tmp = "Urgenza"; break;
	 case "Name": $tmp = "Nome"; break;

// FAQ
     case "Frequently Asked Questions": $tmp = "Domande Poste di Frequente"; break;
     case "Question": $tmp = "Domanda"; break;
     case "Answer": $tmp = "Risposta"; break;

// Apps update
     case "Comment": $tmp = "Commenta"; break;
     case "Review": $tmp = "Revisiona"; break;
     case "Update": $tmp = "Aggiorna"; break;
     case "Delete": $tmp = "Cancella"; break;
     case "Undelete": $tmp = "Revoca Cancellazione"; break;

// Apps not yet reviewed
     case "Waiting for Review by an Editor": $tmp = "In attesa di Revisione da parte di un Editore"; break;

// Apps by identifier
     case "Application": $tmp = "Applicazione"; break;
     case "Others by Author": $tmp = "Altri per Autore"; break;
     case "has not yet been reviewed by a $GLOBALS[sys_name] Editor.<br> Please, be patient. It will be surely done in the next time.": $tmp = "non è stata ancora revisionata da un Editore $GLOBALS[sys_name]. <br> Sii paziente. Sarà sicuramente fatto per la prossima volta."; break;
     case "is modified": $tmp = "è modificata"; break;
     case "is deleted": $tmp = "è cancellata"; break;

// User registration
     case "Register as a new User": $tmp = "Registrati come nuovo Utente"; break;
     case "Username": $tmp = "Nome Utente"; break;
     case "Password": $tmp = "Password"; break;
     case "Confirm Password": $tmp = "Conferma la Password"; break;
     case "Realname": $tmp = "Nome Reale"; break;
     case "Register": $tmp = "Registrati"; break;
     case "User Registration": $tmp = "Registrazione degli Utenti"; break;
     case "Congratulations": $tmp = "Congratulazioni"; break;
     case "You have registered on $GLOBALS[sys_name]": $tmp = "Ti sei registrato su $GLOBALS[sys_name]"; break;
     case "Your new username is": $tmp = "Il tuo nuovo nome utente è"; break;
     case "You are now being sent a confirmation email to verify your email address": $tmp = "Ti è stata appena inviata una mail di conferma per verificare il tuo indirizzo email"; break;
     case "Visiting the link sent to you in this email will activate your account": $tmp = "Visita il link che ti è stato inviato in questa email per attivare il tuo account"; break;
     case "Thank you for registering on the $GLOBALS[sys_name] Site. In order": $tmp = "Grazie per esserti registrato sul sito $GLOBALS[sys_name]. Per"; break;
     case "to complete your registration, visit the following URL": $tmp = "completare la tua registrazione, visita il seguente indirizzo"; break;
     case "Enjoy the site": $tmp = "Divertiti su questo sito"; break;
     case " -- the $GLOBALS[sys_name] crew": $tmp = " -- il team di $GLOBALS[sys_name]"; break;
     case "Verification of Registration": $tmp = "Verifica della Registrazione"; break;
     case "Your account is now activated. Please login": $tmp = "Il tuo account è adesso attivo. Effettua login"; break;

// Forget password / Remind me
     case "Register as a new User": $tmp = "Registrati come un Nuovo Utente"; break;
     case "Remind me": $tmp = "Ricordati di me"; break;
     case "Your Username and Password for $GLOBALS[sys_name] is": $tmp = "Il tuo nome utente e la password per $GLOBALS[sys_name] sono"; break;
     case "Please keep this e-mail for further reference": $tmp = "Si consiglia di tenere questa email per future necessità"; break;
     case "You will get your Password by e-mail in a couple of minutes": $tmp = "Riceverai la tua password per email in un paio di minuti"; break;

// Change User Parameters
     case "Change User Parameters": $tmp = "Cambia i Parametri Utente"; break;
     case "Remind me": $tmp = "Ricordati di me"; break;
     case "Modification": $tmp = "Modifica"; break;
     case "Creation": $tmp = "Creazione"; break;
     case "Permission": $tmp = "Permessi"; break;
     case "Change": $tmp = "Cambia"; break;
     case "Password and/or E-Mail Address of": $tmp = "Password e/o indirizzo email di"; break;
     case "is changed": $tmp = "è cambiata"; break;

// Apps by category
     case "Homepage": $tmp = "Homepage"; break;
     case "Download": $tmp = "Scarica"; break;
     case "Changelog": $tmp = "Changelog"; break;
     case "Comments": $tmp = "Commenti"; break;
     case "Type": $tmp = "Tipo"; break;
     case "Updated": $tmp = "Aggiornato"; break;
     case "Created": $tmp = "Creato"; break;
     case "Stable": $tmp = "Stabile"; break;
     case "Development": $tmp = "In Sviluppo"; break;
     case "License": $tmp = "Licenza"; break;

// New Apps
     case "New Application": $tmp = "Nuova Applicazione"; break;
     case "Application Name": $tmp = "Nome dell'Applicazione"; break;
     case "Insert": $tmp = "Inserisci"; break;

// Insert Apps
     case "Insert Application": $tmp = "Inserisci Applicazione"; break;
     case "Version": $tmp = "Versione"; break;
     case "Section/Category": $tmp = "Sezione/Categoria"; break;
     case "RPM Package": $tmp = "Pacchetto RPM"; break;
     case "Debian Package": $tmp = "Pacchetto Debian"; break;
     case "Slackware Package": $tmp = "Pacchetto Slackware"; break;
     case "SCM Tree": $tmp = "Albero SCM"; break;
     case "Screenshots": $tmp = "Immagini d'esempio (screenshot)"; break;
     case "Mailing List Archive": $tmp = "Archivio della Mailing List"; break;
     case "Description": $tmp = "Descrizione"; break;
     case "Author": $tmp = "Autore"; break;
     case "Depends on": $tmp = "Dipendente da"; break;
	 case "low": $tmp = "bassa"; break;
	 case "medium": $tmp = "media"; break;
	 case "high": $tmp = "alta"; break;

// Update Apps
     case "Update Application": $tmp = "Aggiorna Applicazione"; break;
     case "Application ID": $tmp = "ID Applicazione"; break;
     case "Announcements": $tmp = "Annunci"; break;
     case "active": $tmp = "attiva"; break;
     case "pending": $tmp = "pendente"; break;
     case "deleted": $tmp = "cancellata"; break;
     case "Check": $tmp = "Controlla"; break;

// Comment
     case "Your Comment about": $tmp = "Il tuo Commento a riguardo"; break;
     case "Subject": $tmp = "Soggetto"; break;
     case "Comment": $tmp = "Commento"; break;
     case "Send": $tmp = "Invia"; break;

// Login
     case "$GLOBALS[sys_name] Login": $tmp = "$GLOBALS[sys_name] Login"; break;
     case "Welcome to $GLOBALS[sys_name]": $tmp = "Benvenuto su $GLOBALS[sys_name]"; break;
     case "You are logged in as": $tmp = "Sei ora collegato come"; break;
     case "with": $tmp = "con"; break;
     case "permission": $tmp = "permessi"; break;
     case "Your authentication is valid until": $tmp = "La tua autenticazione è valida fino a"; break;

// Logout
     case "You have been logged in as": $tmp = "Sei stato collegato come"; break;
     case "Your authentication was valid until": $tmp = "La tua autenticazione è valida fino a"; break;
     case "This is all over now. You have been logged out": $tmp = "Ora è tutto passato. Ti sei scollegato"; break;

// User admin
     case "Action": $tmp = "Azione"; break;
     case "Delete": $tmp = "Cancella"; break;
     case "Create User": $tmp = "Crea un Utente"; break;
     case "User Creation": $tmp = "Creazione di un Utente"; break;
     case "created": $tmp = "creato"; break;
     case "User Change": $tmp = "Cambia Utente"; break;
     case "User Deletion": $tmp = "Cancellazione di un Utente"; break;
     case "is deleted": $tmp = "è cancellato"; break;

// Section admin
     case "Section Administration": $tmp = "Amministrazione delle Sezioni"; break;
     case "Insert a Section": $tmp = "Inserisci una Sezione"; break;
     case "Rename a Section": $tmp = "Rinomina una Sezione"; break;
     case "Delete a Section": $tmp = "Cancella una Sezione"; break;
     case "New Section": $tmp = "Nuova Sezione"; break;
     case "New Section Name": $tmp = "Nuovo Nome ad una Sezione"; break;
     case "Section": $tmp = "Sezione"; break;
     case "Rename": $tmp = "Rinomina"; break;

// Category admin
     case "Category Administration": $tmp = "Amministrazione delle Categorie"; break;
     case "Insert a Category": $tmp = "Inserisci una Categoria"; break;
     case "Rename a Category": $tmp = "Rinomina una Categoria"; break;
     case "Delete a Category": $tmp = "Cancella una categoria"; break;
     case "New Category": $tmp = "Nuova Categoria"; break;
     case "New Category Name": $tmp = "Nuovo Nome ad una Categoria"; break;
     case "Category": $tmp = "Categoria"; break;

// License admin
     case "License Administration": $tmp = "Amministrazione delle Licenze"; break;
     case "Insert a License": $tmp = "Inserisci una Licenza"; break;
     case "Rename a License": $tmp = "Rinomina una Licenza"; break;
     case "Change a License URL": $tmp = "Cambia l'indirizzo di una Licenza"; break;
     case "Delete a License": $tmp = "Cancella una Licenza"; break;
     case "New License": $tmp = "Nuova Licenza"; break;
     case "License URL": $tmp = "Indirizzo della Licenza"; break;
     case "New License Name": $tmp = "Nuovo Nome ad una Licenza"; break;
     case "New License URL": $tmp = "Nuovo Indirizzo ad una Licenza"; break;
     case "License": $tmp = "Licenza"; break;

// Announcements
    case "by": $tmp = "da"; break;
    case "on": $tmp = "su"; break;
    case "hits": $tmp = "contatti"; break;

// Time-based Navigation
    case "Day": $tmp = "Giorno"; break;
    case "Today": $tmp = "Oggi"; break;
    case "Week": $tmp = "Settimana"; break;

// Search
    case "No Application found": $tmp = "Nessuna Applicazione trovata"; break;

// Apps by user
     case "Apps of User": $tmp = "Applicazioni dell'Utente"; break;
     case "No Apps of User exist": $tmp = "Non esiste nessuna Applicazione dell'Utente"; break;

// Pending Apps
     case "No pending Apps exist": $tmp = "Non esistono Applicazioni pendenti"; break;

// Deleted or modified apps
     case "Is deleted": $tmp = "è cancellata"; break;
     case "Is modified": $tmp = "è modificata"; break;
     case "No deleted Apps exist": $tmp = "Non esistono Applicazioni cancellate"; break;
     case "No modified Apps exist": $tmp = "Non esistono Applicazioni modificate"; break;

// Users
    case "No": $tmp = "No"; break;
    case "All": $tmp = "Tutte"; break;

// Developers
    case "Names": $tmp = "Nomi"; break;
    case "Unknown": $tmp = "Sconosciuto"; break;

// Licences
     case "Apps": $tmp = "Applicazioni"; break;

// Check Date
     case "All dates are consistent": $tmp = "Tutte le date sono consistenti"; break;

// Newsletter
     case "Subscribe Newsletter": $tmp = "Iscriviti alla Newsletter"; break;
     case "Subscribe": $tmp = "Iscriviti"; break;
     case "Send newsletter": $tmp = "Invia Newsletter"; break;
     case "Newsletter was sent at ": $tmp = "La newsletter è stata inviata a "; break;
     case "You have subscribed to $GLOBALS[sys_name] Newsletter": $tmp = "Ti sei iscritto alla Newsletter di $GLOBALS[sys_name]"; break;
     case "Daily Newsletter": $tmp = "Newsletter Giornaliera"; break;
     case "Weekly Newsletter": $tmp = "Newsletter Settimanale"; break;
     case "daily": $tmp = "giornaliera"; break;
     case "weekly": $tmp = "settimanale"; break;

// Statistics
	 case "$GLOBALS[sys_name] Statistics": $tmp = "Statistiche per $GLOBALS[sys_name]"; break;
	 case "General $GLOBALS[sys_name] Statistics": $tmp = "Statistiche Generali per $GLOBALS[sys_name]"; break;
	 case "Apps by Importance": $tmp = "Applicazioni per Importanza"; break;
	 case "Apps by Hits": $tmp = "Applicazioni per Contatti"; break;
	 case "Apps by Homepage Visits": $tmp = "Applicazioni per Visite alla Homepage"; break;
	 case "Apps by Downloads": $tmp = "Applicazioni per Download"; break;
	 case "Top downloaded RPM Packages": $tmp = "Pacchetti RPM Maggiormente Scaricati"; break;
	 case "Top downloaded Debian Packages": $tmp = "Pacchetti Debian Maggiormente Scaricati"; break;
	 case "Top downloaded Slackware Packages": $tmp = "Pacchetti Slackware Maggiormente Scaricati"; break;
	 case "Apps and Downloads by Urgency": $tmp = "Applicazioni e Download per Urgenza"; break;
	 case "Apps and Downloads by Version Types": $tmp = "Applicazioni e Download per Tipo di Versione"; break;
	 case "Apps and Importance by Sections": $tmp = "Applicazioni ed Importanza per Sezioni"; break;
	 case "Apps by Categories": $tmp = "Applicazioni Per Categoria"; break;
	 case "Apps by Version Numbers": $tmp = "Applicazioni per Numero di Versione"; break;
	 case "Apps and Downloads by Package Formats": $tmp = "Applicazioni e Download per Formati di Pacchetto"; break;
	 case "Importance by Licenses": $tmp = "Importanza per Licenze"; break;
	 case "Importance by Email Domains": $tmp = "Importanza per Domini Email"; break;
	 case "Apps by Email Domains": $tmp = "Applicazioni per Domini Email"; break;
	 case "Apps by Sections and Email Domains": $tmp = "Applicazioni per Sezioni e Domini Email"; break;
	 case "Apps by Licenses": $tmp = "Applicazioni per licenze"; break;
	 case "Apps by Licenses and Email Domains": $tmp = "Applicazioni per Licenze e Domini Email"; break;

// General Statistics
	 case "Number of Applications in $GLOBALS[sys_name]": $tmp = "Numero di Applicazioni in $GLOBALS[sys_name]"; break;
	 case "Total Number of Insertions and Modifications": $tmp = "Numero Totale di Inserimenti e Modifiche"; break;
	 case "Number of Insertions and Modifications during the last week": $tmp = "Numero di Inserimenti e Modifiche nell'ultima settimana"; break;
	 case "Number of pending Applications": $tmp = "Numero di Applicazioni Pendenti"; break;
	 case "Number of $GLOBALS[sys_name] authorised Users": $tmp = "Numero di Utenti Autorizzati per $GLOBALS[sys_name]"; break;
	 case "Number of Comments on Applications": $tmp = "Numero di Commenti sulle Applicazioni"; break;
	 case "Number of Licenses listed in $GLOBALS[sys_name]": $tmp = "Numero di Licenze elencate in $GLOBALS[sys_name]"; break;
	 case "Number of $GLOBALS[sys_name] Sections": $tmp = "Numero di Sezioni in $GLOBALS[sys_name]"; break;
	 case "Number of $GLOBALS[sys_name] Categories": $tmp = "Numero di Categorie in $GLOBALS[sys_name]"; break;
	 case "Number of Hits on Applications": $tmp = "Numero di Contatti sulle Applicazioni"; break;
	 case "Number of redirected Homepages": $tmp = "Numero di Homepage redirette"; break;
	 case "Number of Downloads": $tmp = "Numero di Download"; break;
	 case "Number of redirected Changelogs": $tmp = "Numero di Changelog rediretti"; break;
	 case "Number of redirected SCMs": $tmp = "Numero di SCM rediretti"; break;
	 case "Number of redirected Screenshots": $tmp = "Numero di Screenshot rediretti"; break;
	 case "Number of redirected Mailing Lists Archives": $tmp = "Numero di Archivi di Mailing List rediretti"; break;
	 case "SourceWell Version": $tmp = "Versione di SourceWell"; break;

	 case "High Urgency": $tmp = "Urgenza Alta"; break;
	 case "Medium Urgency": $tmp = "Urgenza Media"; break;
	 case "Low Urgency": $tmp = "Urgenza Bassa"; break;
	 case "Stable Version": $tmp = "Versione Stabile"; break;
	 case "Development Version": $tmp = "Versione di Sviluppo"; break;
	 case "Version Number": $tmp = "Numero di Versione"; break;
	 case "Tarballs": $tmp = "Archivi tar"; break;
	 case "RPM Packages": $tmp = "Pacchetti RPM"; break;
	 case "Debian Packages": $tmp = "Pacchetti Debian"; break;
	 case "Slackware Packages": $tmp = "Pacchetti Slackware"; break;
	 case "Applications listed by their Importance": $tmp = "Applicazioni elencate per la loro importanza"; break;
	 case "Applications listed by Number of Tarball-Downloads": $tmp = "Applicazioni elencate per il Numero di Download di Archivi tar"; break;
	 case "Applications listed by Number of Hits": $tmp = "Applicazioni elencate per Numero di Contatti"; break;
	 case "Applications listed by Homepage Visits": $tmp = "Applicazioni elencate per Visite alle Homepage"; break;
	 case "Top downloaded RPM Packages": $tmp = "Pacchetti RPM Maggiormente Scaricati"; break;
	 case "Top downloaded Debian Packages": $tmp = "Pacchetti Debian Maggiormente Scaricati"; break;
	 case "Top downloaded Slackware Packages": $tmp = "Pacchetti Slackware Maggiormente Scaricati"; break;
	 case "Application Importance listed by Sections": $tmp = "Importanza dell'Applicazione elencata per Sezioni"; break;
	 case "Applications listed by Sections": $tmp = "Applicazioni elencate per Sezioni"; break;
	 case "Applications listed by Categories": $tmp = "Applicazioni elencate per Categorie"; break;
	 case "Applications listed by Licenses": $tmp = "Applicazioni elencate per Licenze"; break;
	 case "Availability of downloadable Packet Formats": $tmp = "Disponibilità dei Formati di Pacchetto scaricabili"; break;
	 case "Downloads listed by Packet Formats": $tmp = "Scaricamenti elencati per Formati di Pacchetto"; break;
	 case "Applications listed by Urgency": $tmp = "Applicazioni elencate per Urgenza"; break;
	 case "Downloads listed by Urgency": $tmp = "Scaricamenti elencati per Urgenza"; break;
	 case "Applications listed by Version Numbers": $tmp = "Applicazioni elencate per Numeri di Versione"; break;
	 case "Applications listed by Licenses": $tmp = "Applicazioni elencate per Licenze"; break;
	 case "Applications listed by Version Type": $tmp = "Applicazione elencate per Tipo di Versione"; break;
	 case "Downloads listed by Version Type": $tmp = "Scaricamenti elencati per Tipo di Versione"; break;
	 case "Application Importance listed by Licenses": $tmp = "Importanza dell'Applicazione elencata per Licenze"; break;
	 case "Application Importance listed by Developer's Email Domains": $tmp = "Importanza dell'Applicazione elencata per Domini Email dello Sviluppatore"; break;
	 case "Applications listed by Developer's Email Domain": $tmp = "Applicazioni elencate per Domini Email dello Sviluppatore"; break;
	 case "Applications listed by Sections and Developer's Email Domain": $tmp = "Applicazioni elencate per Sezioni e Domini Email dello Sviluppatore"; break;
	 case "Applications listed by Licenses and Developer's Email Domain": $tmp = "Applicazioni elencate per Licenze e Domini Email dello Sviluppatore"; break;

// Errors
     case "Access denied": $tmp = "Accesso Negato"; break;
     case "Error": $tmp = "Errore"; break;
     case "does not exist": $tmp = "non esiste"; break;
     case "Change User Parameters failed": $tmp = "Cambiamento dei Parametri Utente fallito"; break;
     case "No Application ID specified": $tmp = "Nessun ID di Applicazione specificato"; break;
     case "No Application Name specified": $tmp = "Nessun Nome di Applicazione specificato"; break;
     case "Please select": $tmp = "Selezionare"; break;
     case "Parameter missing": $tmp = "Parametro mancante"; break;
     case "and": $tmp = "e"; break;
     case "User": $tmp = "Utente"; break;
     case "already exists": $tmp = "già esistente"; break;
     case "Please select a different Username": $tmp = "Selezionare un diverso Nome Utente"; break;
     case "Please enter": $tmp = "Inserire"; break;
     case "Either your Username or E-Mail Address is unknown": $tmp = "Il tuo Nome Utente o la tua Email ci sono sconosciuti"; break;
     case "Please try again": $tmp = "Si prega di riprovare"; break;
     case "If you are not yet a registered User, please select": $tmp = "Non sei ancora un Utente registrato, si prega di selezionare"; break;
     case "Verification of Registration failed": $tmp = "Verifica della Registrazione fallita"; break;
     case "User Change failed": $tmp = "Cambio di Utente fallito"; break;
     case "Registration of new User failed": $tmp = "Registrazione di un nuovo utente fallita"; break;
     case "Database Access failed": $tmp = "Accesso al database fallito"; break;
     case "User Deletion failed": $tmp = "Cancellazione dell'Utente fallita"; break;
     case "No more Apps for this day": $tmp = "Nessun'altra Applicazione per questo giorno"; break;
     case "Either your Username or Password are invalid": $tmp = "Il tuo Nome Utente o la tua Password sono invalidi"; break;
     case "The passwords are not identical": $tmp = "Le password non sono identiche"; break;
     case "Please try again": $tmp = "Si prega di riprovare"; break;
     case "License description is not available": $tmp = "Descrizione della Licenza non disponibile"; break;

// New Translations for SourceWell 1.1

// stats.php
    case "Number of Insertions and Modifications in the last day": $tmp = "Numero di Inserimenti e Modifiche nell'ultimo giorno"; break;
    case "Number of today's visitors": $tmp = "Numero di visitatori odierni"; break;
    case "Today": $tmp = "Oggi"; break;
    case "Version Number":  $tmp = "Numero di Versione"; break;
    case "High Urgency": $tmp = "Urgenza Alta"; break;
    case "Medium Urgency": $tmp = "Urgenza Media"; break;
    case "Low Urgency": $tmp = "Urgenza Bassa"; break;

// admuser.php
    case "User Administration": $tmp = "Amministrazione degli Utenti"; break;
    case "There can only be one anonymous user in the system": $tmp = "Ci può essere soltanto un utente anonimo nel sistema"; break;
    case "The anonymous permission is incompatible with another type of permission": $tmp = "I permessi per l'anonimo sono incompatibili con un altro tipo di permessi"; break;

// inscat.php and inssec.php
    case "Former category": $tmp = "Categoria precedente"; break;
    case "in Section": $tmp = "nella Sezione"; break;
    case "has been renamed to": $tmp = "è stata rinominata in"; break;
    case "affecting": $tmp = "coinvolgendo"; break;
    case "applications": $tmp = "applicazioni"; break;
    case "already exists!": $tmp = "già esistente!"; break;
    case "Category not specified": $tmp = "Categoria non specificata"; break;
    case "This is the unique category of the section. For deleting it, you should delete the whole section.": $tmp = "Questa è l'unica categoria della sezione. Per cancellarla, si dovrebbe cancellare l'intera sezione."; break;
    case "If you press another time the Delete-button you will delete": $tmp = "Premendo un'altra volta il bottone Cancella verrà cancellata"; break;
    case "applications that are actually in the": $tmp = "applicazioni che sono attualmente nella"; break;
    case "category": $tmp = "categoria"; break;
    case "Delete Category": $tmp = "Cancella Categoria"; break;
    case "Delete": $tmp = "Cancella"; break;
    case "Deletion succesfully completed.": $tmp = "Cancellazione completata con successo"; break;
    case "Deletion succesfully completed affecting": $tmp = "Cancellazione completata con successo coinvolgendo"; break;
    case "applications": $tmp = "applicazioni"; break;
    case "has been added succesfully to the database": $tmp = "è stata inserita con successo nel database"; break;
    case "Category not specified": $tmp = "Categoria non specificata"; break;
    case "Warning!": $tmp = "Avviso!"; break;
    case "If you press another time the Delete-button you will delete the": $tmp = "Premendo un'altra volta il bottone Cancella verranno cancellate le"; break;
    case "categories and": $tmp = "categorie e"; break;
    case "applications that are actually in the": $tmp = "applicazioni che sono attualmente nella"; break;
    case "section": $tmp = "sezione"; break;
    case "Delete Section": $tmp = "Cancella Sezione"; break;

// inslic.php

    case "License name not specified": $tmp = "Il nome della licenza non è stato indicato"; break;
    case "has a new URL:": $tmp = "ha un nuovo indirizzo"; break;
    case "New URL not specified": $tmp = "Nuovo indirizzo non specificato"; break;
    case "If you press another time the Delete-button you will alter": $tmp = "Premendo un'altra volta il bottone Cancella verranno alterate"; break;
    case "applications that have actually license": $tmp = "applicazioni che hanno attualmente la licenza"; break;
    case "That license already exists!": $tmp = "Quella licenza esiste già!"; break;
    case "with URL": $tmp = "con indirizzo"; break;
    case "has been added succesfully to the database": $tmp = "è stata aggiunta con successo al database"; break;
    case "License URL not specified": $tmp = "Indirizzo della licenza non specificato"; break;
    case "License not specified": $tmp = "Licenza non specificata"; break;
    case "Delete License": $tmp = "Cancella Licenza"; break;

// admcomment.php and comment.php
    case "Posted on": $tmp = "Inviato il"; break;
    case "Modify": $tmp = "Modifica"; break;
    case "Comment about": $tmp = "Commenta"; break;
    case "Delete this comment? (please, think there's no way for undoing comment deletion)": $tmp = "Cancellare questo commento? (si noti che non c'è modo di recuperare questo commento dopo che è stato cancellato)"; break;
    case "Yes, Delete": $tmp = "Sì, Cancella"; break;
    case "No, Just Modify": $tmp = "No, Modifica Soltanto"; break;
    case "Comment Deleted": $tmp = "Commento Cancellato"; break;
    case "Selected Comment was deleted": $tmp = "Il commento selezionato è stato cancellato"; break;

// admfaq.php and insfaq.php

    case "Enter a New Frequently Asked Question": $tmp = "Inserisci una Nuova FAQ"; break;
    case "Frequently Asked Questions Administration": $tmp = "Amministrazione delle FAQ"; break;
    case "Delete this faq? (please, think there's no way for undoing comment deletion)": $tmp = "Cancella questa FAQ? (si noti che non c'è modo di recuperare questa FAQ dopo che è stata cancellata)"; break;
    case "Create": $tmp = "Crea"; break;
    case "FAQ Deleted": $tmp = "FAQ Cancellata"; break;
    case "FAQ Administration": $tmp = "Amministrazione delle FAQ"; break;
    case "The following FAQ has been modified": $tmp = "La seguente FAQ è stata modificata"; break;
    case "The following FAQ has been inserted in this language": $tmp = "La seguente FAQ è stata inserita in questo linguaggio"; break;

// admdate.php
    case "Modification date": $tmp = "Data di modifica"; break;
    case "History date": $tmp = "Storia"; break;

// nladm.php
    case "The Mailing Lists are not enabled": $tmp = "Le Mailing List non sono attivate"; break;
    case "daily newsletter for": $tmp = "newsletter giornaliera per"; break;
    case "weekly newsletter for": $tmp = "newsletter settimanale per"; break;
    case "Newsletter was sent at ": $tmp = "Newsletter inviata a"; break;
    case "Send newsletter": $tmp = "Invia newsletter"; break;

// footer.inc
    case "System Credits": $tmp = "Crediti di Sistema"; break;

// login.php3
    case "Anonymous login": $tmp = "Login Anonimo"; break;
    case "If you are not registered and/or you do not want to, you can login as an anonymous user by entering": $tmp = "Se non sei registrato e/o non vuoi esserlo, puoi fare login come utente anonimo inserendo"; break;
    case "as user name and": $tmp = "come nome utente e"; break;
    case "as password.": $tmp = "come password"; break;

// configure.php


// If no translation available, keep the original phrase
// Please, translation of this is not needed!
     default: $tmp = "$phrase"; break;
}
?>
