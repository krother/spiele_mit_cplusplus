
# Bewegung der Figur

## Aufgabe 1

Die Figur soll an Wänden stoppen

Prüfe jeweils vor der Bewegung, ob an der neuen Position eine Wand auf dem Spielfeld liegt. Falls ja, führe keine Bewegung aus.


## Aufgabe 2

Speichere die Blickrichtung der Spielfigur in einer Variable (z.B. 1 für oben, 2 für unten use.). Ändere diese Variable, sobald der Spieler eine Pfeiltaste drückt. Zeige unterschiedliche Kacheln für die Spielfigur je nach Blickrichtung an.

## Aufgabe 3

Lagere das Spielfeld in eine eigene Datei `spielfeld.h` aus.

* Betrachte das Beispiel im Ordner `Header`.
* Compiliere das Programm und führe es aus. **Du mußt das Verzeichnis mit den Header-Dateien unter der Option `-I` im Skript `build.bat` aufführen.**
* Verschiebe die Definition des Spielfelds in eine neue Datei `spielfeld.h`
* Binde diese Datei mit `#include <spielfeld.h>` in Dein Programm ein.
* Compiliere das Programm und führe es aus.
