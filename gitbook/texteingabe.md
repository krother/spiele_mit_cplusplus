
# Texteingabe

Zum Eingeben von Text lassen sich Streams einsetzen. Der Eingabe-Stream `cin` verwendet dazu den Operator `>>` (die Richtung ist im Vergleich zu `cout` umgekehrt).

Das folgende Beispiel liest bis zu 10 Zeichen ein und speichert ihn in einer Variable:

    #include <iostream>

    char eingabe[10];
    cin >> eingabe;

Die Eingabe muß mit `Enter` abgeschlossen werden.

### Zahlen eingeben

Das Eingeben von Zahlen ist etwas komplizierter. Da wir von der Tastatur grundsätzlich Text einlesen, müssen wir diesen in einen anderen **Datentyp** umwandeln. Dazu dient die Funktion `atoi())`:

    #include <string>
    #include <stdlib.h>
    #include <stdio.h>

    char eingabe[10];
    cin >> eingabe;
    int zahl = atoi(eingabe);
