
# Compilieren auf der Kommandozeile

Wir können ein C++-Programm auch ohne Code::Blocks compilieren. Wir rufen dazu den Compiler direkt von der **Kommandozeile** aus.

## Pfad auf MinGW setzen (einmalig)

Damit Du den Compiler `g++` auf  überall her starten können, musst Du die sogenannte **Pfadvariable** setzen. Windows sucht nach zu startenden Programmen in den im Pfad angegebenen Verzeichnissen. Und so geht es (*unter Windows 10 ist es vermutlich schon wieder anders :-(*):

1. Öffne die *Systemsteuerung*
2. Öffne dort die Kategorie *System*
3. Wähle dort den Abschnitt *Erweiterte Systemeinstellungen* oder *Erweitert*
4. Drücke den Knopf *Umgebungsvariablen*
5. Erstelle eine neue Umgebungsvariable *PATH* mit dem Wert *`C:\MinGW\bin`* . Falls *PATH* bereits definiert ist, kannst Du über **ein Semikolon** weitere Verzeichnisse anhängen, also `was_schon_da_war;C:\MinGW/bin`
6. Schliesse den Dialog und die Systemsteuerung wieder. **Erst dann werden die Änderungen wirksam**.

![Pfadvariable](bilder_installation/environment_vars.png)

#### Überprüfung

Öffne eine Windows-Konsole (führe das Programm `cmd` aus). Tippe ohne das Verzeichnis zu wechseln `g++` ein. Wenn die gleiche Fehlermeldung (*`fatal error`*) wie oben erscheint, hat es funktioniert. 


## Compilieren unter Windows

1. Finde den Quelltext eines funktionierenden C++-Programms, z.B. `hello.cpp`.

2. Klicke im Dateimanager in die Adreßzeile. Merke oder kopiere Dir den dort sichtbaren **Pfad**.

2. Öffne eine Windows-Konsole, indem Du im Startmenü den Befehl `cmd` eingibst. Es öffnet sich eine schwarze Textkonsole.

3. Gib den Befehl `dir` ein. Du solltest eine Liste von Dateien und Verzeichnissen sehen.

4. Nun werden wir in das Verzeichnis mit Deinem C++-Quelltext wechseln. Gib zuerst `C:` oder `D:` ein, je nachdem womit der Pfad zur Datei beginnt.

5. Mit `cd <verzeichnisname>` kannst Du in der Konsole das Verzeichnis wechseln. Mit `cd ..` wechselst Du in die nächsthöhere Ebene. Verwende `dir` und `cd`, um in Deine C++-Datei zu finden.

6. Rufe den Compiler auf, indem Du eingibst:

    g++ hallo.cpp -o hallo.exe

Der Schalter `-o` sagt dem Compiler, dass die Ausgabe in die Datei `hallo.exe` geschrieben werden soll.

7. Welche Datei ist entstanden?

8. Rufe die Datei auf, indem Du in der Konsole `dateiname.exe` eingibst. 


## Compilieren unter Linux und Mac

Grundsätzlich funktioniert das Kompilieren genauso, außer daß:

1. Suche nach **Terminal** um eine Konsole zu öffnen
2. Es gibt beim `cd`-Befehl keine Verzeichnisse mit `C:` usw.
3. Der Befehl `dir` heißt `ls`
4. Um ein compiliertes Programm auszuführen mußt Du eingeben z.B.:

    ./hello.exe

Oder wenn Du keinen Namen der Ausgabedatei angibst:

    ./a.out
