
# 1.3 Zahlenraten mit 1 Versuch

Damit ein Spiel entsteht, benötigen wir Interaktion zwischen dem Spieler und dem Programm.
Darum wird in dieser Aufgabe das Würfelergebnis geheimgehalten. Der Spieler muß das Würfelergebnis *raten*.

### Anforderungen:

* Der Würfel fällt auf eine Zahl zwischen 1 und 6.
* Das Würfelergebnis wird **nicht** ausgegeben.
* Der Spieler gibt eine Zahl ein.
* Das Programm sagt, ob die geratene Zahl zu groß, zu klein oder ein Treffer ist.
* Der Spieler hat *genau einen* Versuch.

### Beispielausgabe:

    Ich habe eine Zahl ausgewürfelt.
    Rate die Zahl.

    Bitte gib eine Zahl ein (1-6): 3
    Die Zahl ist zu klein.


## Entscheidungen

### Aufgabe 1

Was tut die folgende Befehlsfolge?

    int a = 5;
    if (a < 10) {
       cout << "kleiner als 10" << endl;
    }


### Aufgabe 2

Das Eingeben von Zahlen ist etwas komplizierter. Da wir von der Tastatur grundsätzlich Text einlesen, müssen wir diesen in einen anderen **Datentyp** umwandeln. 
Schreibe ein Programm, das eine Zahl einliest und 10 dazu addiert.

Verwende die folgenden Zeilen:

    #include <string>
    #include <stdlib.h>
    #include <stdio.h>

    char eingabe[10];
    cin >> eingabe;
    int zahl = atoi(eingabe);


### Aufgabe 3

Schreibe das oben beschriebene Zahlenratespiel. 
Das Spiel soll den Spieler um eine Eingabe bitten und dann sagen ob die geratene Zahl größer, kleiner oder genau gleich ist.

### Aufgabe 4

Compiliere das Programm. Tausche die Plätze mit Deinem/Deiner Nachbar/in und ratet die Zahl.
