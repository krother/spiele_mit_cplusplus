
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

