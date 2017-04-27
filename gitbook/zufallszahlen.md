
# Zufallszahlen

Um Zufallszahlen zu erzeugen, benötigen wir die Bibliothek `<stdlib.h>`

## Zufallszahlen erzeugen

Mit der Funktion `rand()` lassen sich Pseudo-Zufallszahlen erzeugen.

    #include <stdlib.h>

    int zufall = rand();

Computer können grundsätzlich keinen echten Zufall erzeugen. Die Zahl ist daher bei jedem Programmstart die gleiche.

## Ganze Zahlen

Mit `rand()` erhälst Du sehr große Zufallszahlen. Über den Modulo-Operator (`%`) kannst Du den Wertebereich der Zahlen festlegen. Um beispielsweise Zahlen zwischen 0 und 9 zu erhalten:

    int zufall = rand() % 10;

**Modulo** bezeichnet den Rest bei einer Division.

## Der Seed-Wert

Mit `srand(zahl)` läßt sich ein Startwert (oder *Seed-Wert*) für den Zufallszahlengenerator festlegen. Folgender Code ergibt zwei unterschiedliche Folgen von Zufallszahlen:

    srand(1);
    cout << rand();
    cout << rand();


## Echte Zufallszahlen

Nimmt man als Startwert die Uhrzeit des Computers (Mikrosekunden), kommt man echten Zufallszahlen schon sehr nahe:

    #include <time.h>

    srand(time(NULL));
    int zufall = rand() % 10;
