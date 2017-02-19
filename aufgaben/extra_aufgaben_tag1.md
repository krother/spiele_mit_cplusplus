# C++ Aufgaben - Tag 1

### Aufgabe E1

Setze ein `//` vor eine beliebige Zeile. Compiliere das Programm. Was passiert?


### Aufgabe E2

Schreibe folgendes Spiel in C++

    Rate die Zahl!
    ==============

    Gib eine Zahl ein: 5

    Die gesuchte Zahl ist *kleiner*

    Gib eine Zahl ein: 3

    Die gesuchte Zahl ist *groesser*

    Gib eine Zahl ein: 4

    TREFFER!!!    


Folgende Zeilen könnten hilfreich sein:

   int a = 10;
   do {
     cout << a << endl;
     a = a -1;
   } while (a != 0);


### Aufgabe E3

Compiliere das Programm manuell von der Kommandozeile:

* Starte eine Windows-Konsole (*Ausführen* -> `cmd`).
* Zeige mit `dir` den Inhalt des aktuellen Verzeichnisses an.
* Wechsle mit `cd <Verzeichnisname` das Verzeichnis.
* Wechsle in das Verzeichnis mit Deinem Programm.
* Gib ein `g++ hallo.cpp -o hallo`
* Starte `hallo.exe`


### Aufgabe E4

Installiere SDL entsprechend dem Dokument `SDL_installieren.pdf`.


