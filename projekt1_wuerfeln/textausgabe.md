
# 1.1 Gezinkter Würfel

Die erste Aufgabe ist ein **gezinkter Würfel**, der stets das gleiche Ergebnis anzeigt.
Ein gezinkter Würfel läßt sich leicht programmieren. Unser erstes Programm soll ein Würfelergebnis ausgeben.

### Anforderungen:

* Der Würfel fällt immer auf eine 6.
* Das Würfelergebnis erscheint auf dem Bildschirm.
* Das Programm gibt genau ein Ergebnis aus

### Beispielausgabe:

    Das Würfelergebnis ist: 6


## Mein erstes Programm in C++

### Aufgabe 1

* Öffne einen Texteditor (z.B. Notepad++).
* Erstelle eine neue Datei mit dem Namen `wuerfel.cpp`.
* Gib das folgende Programm ein:

    #include <iostream>
    using namespace std;

    int main() {
      cout << "Du hast eine 6 gewürfelt!" << endl;
      return 0;
    }

### Aufgabe 2

* Öffne eine Konsole unter Windows (`cmd`).
* Gehe mit `cd` zum Verzeichnis mit der neuen Datei.
* Gib ein `g++ wuerfel.cpp`
* Starte das neu entstandene Programm `hello.exe`.
* **Was passiert?**

### Aufgabe 3

* Erzeuge eine neue Datei `build.bat` in einem Texteditor.
* Schreibe den Befehl `g++ wuerfel.cpp` in die Datei.
* Starte das Skript `build.bat` von der Kommandozeile.
* Erkläre was das Skript tut.

### Aufgabe 4

Füge die folgenden Zeilen zum Programm hinzu:

    char eingabe[10];
    cin >> eingabe;
    cout << eingabe << endl;

Führe das Programm aus. Was passiert?

### Aufgabe 5

**Für Fortgeschrittene**

Erkennst Du Unterschiede zwischen diesem und einem gewöhnlichen C-Programm?
