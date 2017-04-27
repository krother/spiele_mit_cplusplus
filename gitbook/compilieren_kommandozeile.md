
# Compilieren auf der Kommandozeile

Wir können ein C++-Programm auch ohne Eclipse compilieren. Das hilft, den Prozeß genauer zu verstehen. Wir rufen dazu den Compiler direkt von der **Kommandozeile** aus.

## Arbeitsschritte

1. Finde den Quelltext eines funktionierenden C++-Programms, z.B. `hello.cpp`.

2. Klicke im Dateimanager in die Adreßzeile. Merke oder kopiere Dir den dort sichtbaren **Pfad**.

2. Öffne eine Windows-Konsole, indem Du im Startmenü den Befehl `cmd` eingibst. Es öffnet sich eine schwarze Textkonsole.

3. Gib den Befehl `dir` ein. Du solltest eine Liste von Dateien und Verzeichnissen sehen.

4. Nun werden wir in das Verzeichnis mit Deinem C++-Quelltext wechseln. Gib zuerst `C:` oder `D:` ein, je nachdem womit der Pfad zur Datei beginnt.

5. Mit `cd <verzeichnisname>` kannst Du in der Konsole das Verzeichnis wechseln. Mit `cd ..` wechselst Du in die nächsthöhere Ebene. Verwende `dir` und `cd`, um in Deine C++-Datei zu finden.

6. Rufe den Compiler auf, indem Du eingibst:

    g++ hello.cpp -o hello.exe

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


## Zusatzaufgabe

Nun werden wir den Prozeß wiederholen, aber uns die Arbeit etwas bequemer machen

1. Lösche die compilierte Datei (`hello.exe`)

2. Starte das Programm `Notepad++`

3. Gib den Aufruf des Compilers (`g++ hello.cpp -o hello`) in eine leere Datei ein

4. Speichere die Datei im gleichen Verzeichnis wie `hello.cpp` unter dem Namen `hello.bat`

5. Klicke `hello.bat` an.

6. Prüfe ob ein ausführbares Programm entstanden ist.
