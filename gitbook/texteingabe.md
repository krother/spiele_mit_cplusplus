
# Texteingabe

Zum Eingeben von Text lassen sich Streams einsetzen. Der Eingabe-Stream `cin` verwendet dazu den Operator `>>` (die Richtung ist im Vergleich zu `cout` umgekehrt).

Das folgende Beispiel liest bis zu 10 Zeichen ein und speichert diese in einer Variable:

    #include <iostream>

    char eingabe[10];
    cin >> eingabe;

Die Eingabe muß mit `Enter` abgeschlossen werden.

### Zahlen eingeben

Das Eingeben von Zahlen funktioniert grundsätzlich genauso, nur das wir diesmal in eine Integer-Variable einlesen:

    #include <iostream>

	int zahl;
	cin >> zahl;

### Zahlen oder Text einlsesen

Etwas komplizierter wird es, wenn wir die Tastatureingabe sowohl als Text als auch als Zahl benötigen. Dann müssen wir Text einlesen, den wir bei Bedarf in eine Zahl umwandeln. Dazu dient die Funktion `atoi())`:

    #include <string>
    #include <stdlib.h>
    #include <stdio.h>

    char eingabe[10];
    cin >> eingabe;
    int zahl = atoi(eingabe);
