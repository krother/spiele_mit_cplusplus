
# Programmierwerkzeuge

## Der Compiler

Das wichtigste Werkzeug zum Programmieren mit C++ ist der Compiler. Der Compiler ist ein Programm, welches den **C++-Quelltext** in eine ausführbare **Binärdatei** übersetzt. 

Es gibt eine Anzahl unterschiedlicher C++-Compiler (*"Dialekte"*), die sich in Einzelheiten unterscheiden. Bekannte Compiler sind:

* MinGW
* GCC
* Visual Studio


## Eclipse

**Eclipse** ist eine **Entwicklungsumgebung**, eine grafische Oberfläche zum Programmieren mit C++. Eclipse enthält einen *Texteditor*, ruft den *Compiler* auf und führt fertige *Programme* in einer *Konsole* aus. 

Einige Dinge sind bei der Arbeit mit Eclipse zu beachten:

* Bevor Du ein Programm schreiben kannst, mußt Du ein Projekt anlegen.
* Jedes Projekt enthält genau ein *Hauptprogramm*, also eine ausführbare Datei.
* Innerhalb eines Projekts dürfen sich die Namen von Funktionen (z.B. `main()`) nicht wiederholen.
* Nicht beendete Programme blockieren die Compilierung, sie lassen sich über einen der Knöpfe im Konsolenfenster rechts unten einzeln beenden.
* Wenn nichts mehr hilft: *Ausschalten und wieder Einschalten*

## Die Kommandozeile

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


## MinGW

Der Compiler läßt sich auch direkt über die Kommandozeile aufrufen. Ein einfacher Aufruf zum Compilieren des Programms `hallo.cpp` sieht folgendermaßen aus:

    g++ hallo.cpp -o hallo

Der Schalter `-o` sagt dem Compiler, daß die Ausgabe in die Datei `hallo.exe` geschrieben werden soll.


## Notepad++

Bitte versuche **auf keinen Fall** mit dem normalen Windows-Notepad in C++ zu programmieren. Installiere Dir lieber einen anständigen Editor. **Notepad++** ist ein solcher, und obendrein kostenlos.


## Batch-Dateien

Dateien mit Kommandozeilenbefehlen sind nützlich, damit Du lange Befehle nicht immer wieder neu eintippen mußt. Unter Windows nennt man diese **Batch-Dateien**. Du erkennst sie mit der Endung `.bat` .

Du kannst Batch-Dateien mit einem Texteditor selbst erstellen. Über einen Doppelklick kannst Du sie ausführen, siehst dann aber eventuelle Fehlermeldungen nicht. Durch Eingabe von `dateiname.bat` in der Kommandozeile kannst Du sie ebenfalls ausführen.

## Pseudocode

Bevor man anfängt zu programmieren, hilft es oft, das Problem in einzelne Schritte zu zerlegen. Aufgeschrieben nennt man diese oft **Pseudocode**. Pseudocode erleichtert das Programmieren oft erheblich, weil er hilft, das Problem zu erfassen.

Der Pseudocode für ein Zahlenrate-Spiel könnte folgendermaßen aussehen:

1. Der Computer denkt sich eine Zufallszahl aus
2. Der Spieler gibt eine geratene Zahl ein
3. Ist die Zahl zu groß, gibt das Programm einen entsprechenden Hinweis
4. Ist die Zahl zu klein, gibt das Programm einen entsprechenden Hinweis
5. Hat der Spieler die Zahl geraten, wird das Programm beendet
6. Ansonsten zurück zu Schritt 2
