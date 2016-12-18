
# Textausgabe unter SDL

In der Bibliothek SDL funktioniert die Textausgabe über 'cout' nicht. Die Funktion `printf` ist eine mindestens genauso bequeme Alternative. Um sie zu verwenden, sind eigentlich nur zwei Zeilen notwendig:

Erstens, ein `#include` am Anfang des Programms:

    #include <stdio.h>

Zweitens, der Aufruf von `printf` mit einem Text:

    printf("Hallo, so geht Textausgabe\n");

Es ist auch möglich Zahlen mit `printf` auszugeben. Dazu fügt man Platzhalter in den Text ein:

    printf("Hallo, so geht Textausgabe (auch mit Zahlen z.B. %i)\n", 100);

Folgende Platzhalter sind u.a. möglich:

* `%s` als Platzhalter für eine Textvariable
* `%i` als Platzhalter für eine Integer-Zahl
* `%f` als Platzhalter für eine Kommazahl

#### ACHTUNG:

Der Zeilenumbruch (`\n`) am Ende der Zeile ist **unbedingt erforderlich**, sonst wird nichts ausgegeben.

*Anmerkung: Ich habe das Vorgehen mit `printf` unter Windows (Eclipse und Konsole) und Linux erfolgreich ausprobiert, nicht aber auf den Rechnern der ZEDAT.
