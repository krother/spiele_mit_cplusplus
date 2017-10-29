
# Programmierwerkzeuge

## Der Compiler

Das wichtigste Werkzeug zum Programmieren mit C++ ist der Compiler. Der Compiler ist ein Programm, welches den **C++-Quelltext** in eine ausführbare **Binärdatei** übersetzt. 
Es gibt unterschiedliche C++-Compiler (*"Dialekte"*), die sich in Einzelheiten unterscheiden.

Außerdem brauchen wir einen **Editor**, ein Programm, in dem wir den C++-Quelltext selbst schreiben können.

In diesem Kurs verwenden wir:

### MinGW

**MinGW** ist eine Implementierung des freien C++-Compilers **GCC** für Windows.

MinGW läßt sich direkt über die Windows-Kommandozeile aufrufen. Der Aufruf zum Compilieren des Programms `hallo.cpp` sieht folgendermaßen aus:

    g++ hallo.cpp -o hallo.exe

Der Schalter `-o` sagt dem Compiler, dass die Ausgabe in die Datei `hallo.exe` geschrieben werden soll.

### Code::Blocks

**Code::Blocks** ist eine **Entwicklungsumgebung**, eine grafische Oberfläche zum Programmieren. Code::Blocks enthält einen *Texteditor*, ruft MinGW als *Compiler* auf und führt fertige *Programme* aus. Code::Blocks läuft unter Windows, Linux und MaxOS.

Einige Dinge sind bei der Arbeit mit Code::Blocks zu beachten:

* Bevor Du ein Programm schreiben kannst, musst Du ein Projekt anlegen.
* Im Projekt musst Du eine Datei mit der Endung `.cpp` anlegen, in die Du den Quelltext schreibst.
* Innerhalb eines Projekts darf es die Funktion `main()` nur einmal geben.


## Andere Werkzeuge.

### Die Kommandozeile

Für viele Programmierer ist die Kommandozeile ein ständiger Begleiter. Unter Windows kannst Du mit der Kommandozeile Verzeichnisse navigieren und Programme ausführen.

Du kannst **die Kommandozeile starten**, indem Du im Windows-Menü `cmd` eingibst.

In der Kommandozeile gibt es u.a. folgende Befehle:

| Befehl | Bedeutung |
|--------|-----------|
| `dir` | Dateien im aktuellen Verzeichnis anzeigen |
| `cd verzeichnisname` | Verzeichnis wechseln |
| `cd ..` | ein Verzeichnis höher wechseln |
| `D:`   | auf die Festplatte D wechseln |
| `a.exe` | das Programm `a.exe` ausführen |
| `b.bat` | das Skript `b.bat` ausführen |


### Notepad++

**Notepad++** ist ein sehr gut ausgestatteter Texteditor für Windows. Er eignet sich zum Editieren von allen möglichen Dateien, auch C++-Quelltext. **Notepad++** ist kostenlos.

Bitte versuche **auf keinen Fall** mit dem normalen Windows-Notepad in C++ zu programmieren. Installiere Dir lieber Notepad++. 

### Atom

**Atom** ist ein sehr mächtiger Texteditor, der ebenfalls kostenlos ist. Die Oberfläche ist recht minimalistisch, es gibt aber viele Kommandos, die sich über Tastaturbefehle erreichen lassen. Für viele Programmierer ist Atom ein praktisches Allzweckwerkzeug.

### git

**git** ist ein System zur Versionskontrolle. git speichert Änderungen im Code und hilft dabei, Änderungen am Projekt zu verfolgen und notfalls auch rückgängig zu machen. Außerdem kann man über die Seite [GitHub](http://github.com) Code mit anderen Programmierern austauschen.

Von allen Hilfsmitteln ist Versionskontrolle das, welches mich am häufigsten gerettet hat. Die meisten Programmierer, die einmal damit angefangen haben, fangen kein ernsthaftes Projekt ohne **git** an. Übrigens wird auch dieses Skript mit git entwickelt. [Hier findest Du die Seite dazu](https://github.com/krother/spiele_mit_cplusplus).

### Batch-Dateien

Dateien mit Kommandozeilenbefehlen sind nützlich, damit Du lange Befehle nicht immer wieder neu eintippen mußt. Unter Windows nennt man diese **Batch-Dateien**. Du erkennst sie mit der Endung `.bat` .

Du kannst Batch-Dateien mit einem Texteditor selbst erstellen. Über einen Doppelklick kannst Du sie ausführen, siehst dann aber eventuelle Fehlermeldungen nicht. Durch Eingabe von `dateiname.bat` in der Kommandozeile kannst Du sie ebenfalls ausführen.


### Eclipse

**Eclipse** ist eine weitere **Entwicklungsumgebung** zum Programmieren mit C++. Eclipse ist deutlich komplexer und richtet sich an professionelle Entwickler, die sehr große Programme schreiben. Für die Projekte im Kurs ist es nicht nötig, aber wer professionelles Interesse am Programmieren hat, sollte davon schon einmal gehört haben.

