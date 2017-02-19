
# C++ Aufgaben - Tag 1

### Ziel

Schreibe ein Spiel in C++ mit folgender Ausgabe:

    Rate die Zahl!
    ==============

    Gib eine Zahl ein: 5
    Die gesuchte Zahl ist *kleiner*

bzw.

    Gib eine Zahl ein: 4
    TREFFER!!!    


### Aufgabe 1: Unser erstes Programm

Starte den Editor **Eclipse**. Starte ein neues Projekt. Gib das folgende Programm ein:

    #include <iostream>
    using namespace std;

    int main() {
      cout << "Hallo" << endl;
      return 0;
    }

Speichere das Programm in der Datei `hallo.cpp`.


### Aufgabe 2: Das Programm starten

* Compiliere das Program mit dem Knopf *"build"*.
* Führe das compilierte Programm mit dem Knopf *"run"* aus.


### Aufgabe 3: Zahlenvariablen

Füge die folgenden Zeilen zum Programm hinzu:

    int zahl;
    zahl = 7;
    zahl = zahl + 3;
    cout << zahl << endl;

Was passiert?


### Aufgabe 4: Text eingeben

Füge die folgenden Zeilen zum Programm hinzu:

    char eingabe[10];
    cin >> eingabe;
    cout << eingabe << endl;

Was passiert?


### Aufgabe 5: Zahlen eingeben

Das Eingeben von Zahlen ist etwas komplizierter. Da von der Tastatur grundsätzlich Text einlesen, müssen wir diesen in einen anderen **Datentyp** umwandeln. Schreibe ein Programm, das eine Zahl einliest und 10 dazu addiert.

Verwende die folgenden Zeilen:

    #include <string>
    #include <stdlib.h>
    #include <stdio.h>

    char eingabe[10];
    cin >> eingabe;
    int zahl = atoi(eingabe);


### Aufgabe 6: Entscheidungen

Was tut der Befehl:

    int a = 5;
    if (a < 10) {
       cout << "kleiner als 10" << endl;
    }


### Aufgabe 7: Zahlenraten

Schreibe ein Spiel, bei dem Du in das Programm eine Geheimzahl zwischen 1 und 10 schreibst. 
Das Spiel soll den Spieler um eine Eingabe bitten und dann sagen ob die geratene Zahl größer, kleiner oder genau gleich ist.

Um die Zahl zu finden, darf man das Programm mehrmals starten.

Compiliere das Programm. Tausche die Plätze mit Deinem/Deiner Nachbar/in und ratet die Zahl.


### Aufgabe 8: Zahlenraten mit Zufallszahlen

Für das Zahlenraten benötigen wir Zufallszahlen. Diese können wir uns wie folgt erzeugen:

    #include <stdlib.h>

    int zufall = rand() % 10 + 1;

Die Funktion `rand()` erzeugt eine zufällige ganze Zahl, die auch sehr groß sein kann. Der Operator `%` (Modulo) ergibt den Rest der Teilung durch 10. 

**Achtung:** *Computer können grundsätzlich keinen echten Zufall erzeugen. Die Zahl ist daher jedes Mal die gleiche. Für unser erstes Zahlenrate-Spiel werden wir uns das zu Nutze machen.*


Schreibe ein Spiel, bei dem sich der Computer eine Zufallszahl zwischen 1 und 100 *"ausdenkt"*. Der Spieler hat wie zuvor *mehrere* Versuche, die Zahl zu erraten.

