
# Teil 1: Grundlagen C++

## 1. Mein erstes Programm in C++

### Aufgabe 1.1

* Starte den Computer.
* Öffne eine Konsole unter Windows (`cmd`).
* Gehe mit `cd` zum Verzeichnis mit den Kursmaterialien.
* Wechsle in den Ordner `hello_world`.
* Starte das Skript `build.bat`.
* Starte das neu entstandene Programm `hello.exe`.
* **Was passiert?**

### Aufgabe 1.2

* Öffne das Programm `hello_world.cpp` in einem Texteditor (z.B. Notepad++).
* Erkläre was das Programm tut.

### Aufgabe 1.3

* Erkennst Du Unterschiede zwischen diesem und einem gewöhnlichen C-Programm?

### Aufgabe 1.4

* Öffne das Skript `build.bat` in einem Texteditor.
* Erkläre was das Skript tut.

## 2. Datentypen

Für die folgenden Aufgaben kann das Material unter [www.cpp-tutor.de](http://www.cpp-tutor.de) nützlich sein.

### Aufgabe 2.1

* Schreibe ein neues Programm, in dem Du drei Variablen mit den Typen `int`, `double` und `char` definierst.
* Befülle alle drei Variablen mit Inhalt.

### Aufgabe 2.2

Recherchiere nach anderen einfachen Datentypen in C++. 
Befüllt gemeinsam die folgende Tabelle.

| Datentyp | Bedeutung |
|----------|-----------|
| int      | ganze Zahlen |
| char     |              |
| bool     |              |
| float    |              |
| double   |              |


## 3. Ein- und Ausgabe

### Aufgabe 3.1

* Gib die Werte der drei obigen Variablen auf dem Bildschirm aus.

## 4. Operatoren

### Aufgabe 4.1

Ermittle, was die folgenden Operatoren in einem Programm tun:

* `1 + 2;`
* `3 * 4;`
* `7 % 2;`
* `x = 8; x++;`
* `true && (true || false) && !false;`

## 5. Kontrollfluß

### Aufgabe 5.1

Schreibe eine Schleife, die die Zahlen von 1 bis 10 auf dem Bildschirm ausgibt.


## 6. Datenstrukturen

### Aufgabe 6.1

Erstelle ein array (Feld) mit Quadratzahlen `[1, 4, 9, 16, ...]`.

### Aufgabe 6.2

Lass den Benutzer die Anzahl der Quadratzahlen eingeben



# Was ist OOP?


## 7. Ein einfaches objektorientiertes Programm

### Aufgabe 7.1

* Führe das Programm `rect.cpp` aus. 
* Klärt gemeinsam was der Quelltext tut.

### Aufgabe 7.2

Klärt gemeinsam folgende Begriffe:

* Klasse
* Instanz
* Objektinstanzierung
* Variablendefinition
* Eigenschaft
* Methode

### Aufgabe 7.3

* Welche Vor- und Nachteile hat objektorientierte Programmierung.

## 8. Installieren der Bibliothek SDL

Für einen Großteil des Kurses verwenden wir die Bibliothek **SDL** mit dem Compiler MinGW C++.
Bevor wir mit den Übungen fortfahren können, müssen wir die Bibliothek installieren. Die Kurzanleitung an dieser Stelle basiert auf dem Tutorial von *Lazyfoo* [http://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/mingw/index.php](http://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/mingw/index.php).

1. Öffne eine Konsole mit `cmd`.
2. Stelle sicher daß **MinGW** installiert ist (`g++` eingeben).
3. Erstelle einen Ordner `mingw_dev_libs`.
4. Entpacke die Datei `SDL2_devel..`
5. Kopiere den Inhalt des Unterordners `i686...32` nach `mingw_dev_libs`
6. Kopiere die `.dll`-Dateien aus `bin/` dorthin wo das Programm läuft.
7. Verfahre genauso mit SDL_image (`https://www.libsdl.org/projects/SDL_image/`)


## 9. Ein Beispielprogamm mit SDL compilieren

### Aufgabe 9.1

* Gehe in den Ordner `hello_sdl`. 
* Prüfe die Pfadangaben in `build.bat` - müssen auf `mingw_dev_libs` zeigen.
* Compiliere das dort liegende Programm mit Hilfe des Skripts `build.bat`
* Führe das compilierte Programm aus. Es sollte ein **unbewegtes** Bild erscheinen.

### Aufgabe 9.2

* Öffne das Skript `build.bat`. Was ist anders im Vergleich zum Skript aus der ersten Aufgabe?

### Aufgabe 9.3

* Wofür sind die ganzen Dateien im Verzeichnis `hello_sdl` gut?

### Aufgabe 9.4

* Erkläre den Programmcode von `hello_sdl.cpp`.


## 10. Ein Spiel compilieren

### Aufgabe 10.1

* Compiliere das Programm im Ordner `maze`.
* Führe das Programm aus.

### Aufgabe 10.2

* Sammelt gemeinsam Ideen, wie das Spiel verbessert werden könnte. Daraus werden wir uns einige Aufgaben für diese Woche suchen.

### Aufgabe 10.3

* Erkläre den Programmcode von `maze.cpp`.

## 11. Das Spiel objektorientiert machen

### Aufgabe 11.1

* Verpacke das Spiel `maze` komplett in eine Klasse `Maze`.
* Stelle sicher, daß das Programm nach wie vor funktioniert.

### Aufgabe 11.2

* Lagere die Prozeduren `fenster_initialisieren`, `kacheln_laden` und `blit_tile` in eine separate Klasse `Bildschirm` aus.
* Stelle sicher, daß das Programm nach wie vor funktioniert.

### Aufgabe 11.3

* Kannst Du *zwei* Instanzen von `Bildschirm` erzeugen?

## 12. Klausuraufgaben

* Beantwortet gemeinsam die *IHK-Klausurfragen* für Tag 1.

## 13. Extraaufgaben

### Aufgabe 13.1

* Gibt es eine Einstellung, mit der die DLL-Dateien in ein anderes Verzeichnis gelegt werden können?

### Aufgabe 13.2

* Versuche die Programme mit Eclipse zu compilieren.

