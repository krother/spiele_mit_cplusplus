
# Code::Blocks unter Windows installieren

## Schritt 1: Den Compiler MinGW installieren

Zuerst installieren wir den C++-Compiler **MinGW**.

1. Lade die Installationsdatei für MinGW für Windows von [www.mingw.org/category/wiki/download](http://www.mingw.org/category/wiki/download) herunter
2. Starte die Installationsdatei
3. Wähle in der Paketauswahl die Pakete **base** und **gcc** an.
4. Wähle im Menü `Apply Changes` aus, um die Pakete zu installieren.

![Paketauswahl](bilder_installation/mingw_packages.png)

#### Überprüfung

Öffne eine Windows-Konsole (führe das Programm `cmd` aus). Wechsle in das MinGW Verzeichnis mit

    cd C:\MinGW\bin

Führe das Programm `g++` aus. Wenn Du die folgende Fehlermeldung siehst, hat alles funktioniert.

    g++: fatal error: no input files
    compilation terminated.


## Schritt 2: Code::Blocks installieren

Unter [www.codeblocks.org/](http://www.codeblocks.org/) findest Du im Abschnitt **Downloads** die Entwicklungsumgebung für Dein Betriebssystem. 

1. Schaue unter **"Download the binary release"**.
2. Wähle unter Windows `codeblocks-16.01mingw-setup.exe`
3. Installiere das Programm mit den Optionen `base` und `gcc`.

**Anmerkung:** Ich vermute, dass die Installation von MinGW mit dieser Installation überhaupt nicht nötig ist. Habe es aber nicht ausprobiert.

