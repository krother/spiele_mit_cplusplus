
# Textausgabe mit print

Die Funktion `printf` ist eine bequeme Alternative zu `cout`. Um sie zu verwenden, sind eigentlich nur zwei Zeilen notwendig:

Erstens, ein `#include` am Anfang des Programms:

    #include <stdio.h>

Zweitens, der Aufruf von `printf` mit einem Text:

    printf("Hallo, so geht Textausgabe\n");

Es ist auch möglich Zahlen mit `printf` auszugeben. Dazu fügt man Platzhalter in den Text ein:

    printf("Hallo, so geht die Ausgabe von Zahlen z.B. %i\n", 100);

Folgende Platzhalter sind möglich:

* `%i` als Platzhalter für einen `int`
* `%f` als Platzhalter für einen `float`
* `%s` als Platzhalter für einen `string`

#### ACHTUNG:

Der Zeilenumbruch (`\n`) am Ende der Zeile ist **unbedingt erforderlich**, sonst wird nichts ausgegeben.

**Anmerkung:** Ich habe d1as Vorgehen mit `printf` unter Windows (Eclipse und Konsole) und Linux erfolgreich ausprobiert, nicht aber auf den neueren Rechnern der ZEDAT.
