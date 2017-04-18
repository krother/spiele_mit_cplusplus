
# Funktionen

## Die Funktion `main()`

Jedes Programm benötigt eine Funktion `main()` . Hier beginnt die Ausführung des compilierten Programms. Die `main()`-Funktion ist immer nach dem gleichen Schema aufgebaut:

    int main() {

    ..         // eigener Code   

    return 0   // Programm fehlerfrei beendet
    }

## Text in Integers umwandeln

Um Text in Integer-Zahlen umzuwandeln ist eine besondere Funtion nötig: `atoi`. Beispiel:

    #include <string>
    #include <stdlib.h>
    #include <stdio.h>

    char eingabe[10];
    cin >> eingabe;
    int zahl = atoi(eingabe);

## Zufallszahlen erzeugen

Mit der Funktion `rand()` lassen sich Pseudo-Zufallszahlen erzeugen. Über den Modulo-Operator (`%`) läßt sich der Wertebereich der Zahlen bestimmen:

    #include <stdlib.h>

    int zufall = rand() % 10 + 1;

**Achtung:** *Computer können grundsätzlich keinen echten Zufall erzeugen. Die Zahl ist daher jedes Mal die gleiche.*

Mit `srand()` läßt sich ein Startwert für den Zufallszahlengenerator festlegen. Nimmt man als Startwert die Prozessorzeit, kommt man echten Zufallszahlen schon sehr nahe:

    #include <time.h>

    srand(time(NULL));
    int r = rand() % 10;





