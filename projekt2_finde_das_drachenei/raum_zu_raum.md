
# Von Raum zu Raum

Auf der Suche nach dem Drachenei passiert der Spieler unterschiedliche Landschaften. In unserem Adventure behandeln wir diese als abgegrenzte *"Räume"*. Im ersten Programm soll der Spieler/die Spielerin sich zwischen den Räumen hin- und herbewegen können. 

Wir setzen die erste Spielversion vollständig textbasiert um.

### Anforderungen

* Die Spielwelt besteht aus mindestens vier 'Räumen'
* Zu jedem Raum wird eine Beschreibung ausgegeben.
* Der Spieler/Die Spielerin gibt über die Tastatur ein, ob in den Raum nach links oder rechts gewechselt werden soll.
* Wird der letzte Raum erreicht, endet das Spiel mit einer Erfolgsmeldung.

### Beispielausgabe

    Du befindest Dich in Deiner Heimatstadt.
    Ein kleine Handelsstadt am Rande der Wüste.

    Wohin möchtest Du gehen ( W / O )? w


    Du gehst nach Westen.

    Du befindest Dich in der Wüste. Die Sonne brennt unbarmherzig.

    Wohin möchtest Du gehen ( W / O )? w


    Du gehst nach Westen.

    Auf einer verborgenen Lichtung entdeckst Du das Drachenei.

    Deine Suche war erfolgreich!    


### Infomaterialien

* Arrays
* Beispielprogramm `print.cpp`


### Für Fortgeschrittene

* Implementiere eine Klasse `Raum`. 
* `Raum` besitzt ein öffentliches Attribut `beschreibung` vom Typ String.
* `Raum` besitzt eine öffentliche Methode `void ausgabe()`.
* Die Räume im Spiel befinden sich in einem Vektor vom Typ String. 

bereite Dich darauf vor, den anderen Kursteilnehmern an einem einfachen Codebeispiel eines der folgenden Themen innerhalb von 7 Minuten zu erklären:

* was eine Funktion ist.
* was eine Klasse ist.
* was der Unterschied zwischen einem Array und einem Vektor ist
