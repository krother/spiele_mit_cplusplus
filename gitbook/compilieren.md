
# Probleme beim Compilieren

Den Compiler startest Du mit dem *Zahnrad-Knopf*.

Wenn alles funktioniert siehst Du eine Meldung, dass eine `.exe`-Datei erzeugt wurde:

    Output file is ../Debug/test.exe with size 27.62 KB
    
Dabei können unterschiedliche Fehler auftreten. Hier sind einige der häufigsten:

### Syntaxfehler

Der C++-Compiler versteht einen Befehl nicht. 

**Symptom:** Fehlermeldung mit Zeilennummer, z.B.:

    error: expected ';' before '}' token

**Lösung:** Code *und* Fehlermeldung genau lesen


### Falsche C++-Datei editiert

**Symptom:** Du änderst das Programm schon zum 3. Mal, aber es ändert sich überhaupt nichts.

**Lösung:** Doppelklick auf die Datei im Projektliste und prüfen, ob eine neue Datei geöffnet wird.


### Doppelte main-Funktion

Wenn Du zwei Programme im gleichen Code::Blocks-Projekt hast, weiß der Compiler nicht, welche `main()`-Funktion er verwenden soll.

**Symptom:** Fehlermeldung

    multiple definition of main

**Lösung:** Verschiebe eines der Programme in ein anderes Projekt oder bennene die `main()` zwischenzeitlich um.


### Header-Datei nicht gefunden

Code::Blocks weiß nicht, wo es eine Programmbibliothek findet.

**Symptom:** Fehlermeldung

   fatal error: SDL.h: No such file or directory

**Lösung:** Pfad in den Projekteinstellungen (*Search Path, Compiler*)überprüfen.


### Bibliothek nicht gefunden

Code::Blocks weiß nicht, wo die compilierte Bibliothek liegt.

**Symptom:** Fehlermeldung

    undefined reference to `SDL_Init`
    error: ld returned 1 exit status

**Lösung:** Pfad in den Projekteinstellungen (*Search Path, Linker*)und *Linker Settings* überprüfen.


### DLLs nicht gefunden

Das Programm kann nicht ausgeführt werden, weil die Windows-DLLs fehlen.

**Symptom:** Das Compilieren ist erfolgreich, aber beim Starten des Programms erscheint eine Windows-Fehlerbox.

**Lösung:** DLL-Dateien (mit SDL mindestens 6) in das Verzeichnis mit der `.exe`-Datei kopieren.


### Bilddateien nicht gefunden

**Symptom:** Das Programm startet, aber es ist nichts zu sehen.

**Lösung:**

* Bilddateien in das Projektverzeichnis kopieren (dort wo die `.cpp`-Dateien liegen).
* Prüfen, ob nach dem Zeichnen `SDL_UpdateWindowSurface()` aufgerufen wurde.
* Probieren, gleich zu Beginn des Programms ein Bild anzuzeigen (bevor kompliziertere Dinge getan werden), da die Ursache auch etwas anderes sein kann.
