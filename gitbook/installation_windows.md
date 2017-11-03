
# Installation von C++ unter Windows

## Schritt 1: MinGW installieren

Zuerst installieren wir den C++-Compiler **MinGW**.

1. Lade die Installationsdatei für MinGW für Windows von [www.mingw.org/category/wiki/download](http://www.mingw.org/category/wiki/download) herunter
2. Starte die Installationsdatei
3. Wähle in der Paketauswahl die Pakete **base** und **gcc** an.
4. Wähle im Menü `Apply Changes` aus, um die Pakete zu installieren.

![Paketauswahl](gitbook/bilder_installation/mingw_packages.png)

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


## Optional: Pfad auf MinGW setzen

Damit Du den Compiler `g++` auf  überall her starten können, musst Du die sogenannte **Pfadvariable** setzen. Windows sucht nach zu startenden Programmen in den im Pfad angegebenen Verzeichnissen. Und so geht es (*unter Windows 10 ist es vermutlich schon wieder anders :-(*):

1. Öffne die *Systemsteuerung*
2. Öffne dort die Kategorie *System*
3. Wähle dort den Abschnitt *Erweiterte Systemeinstellungen* oder *Erweitert*
4. Drücke den Knopf *Umgebungsvariablen*
5. Erstelle eine neue Umgebungsvariable *PATH* mit dem Wert *`C:\MinGW\bin`* . Falls *PATH* bereits definiert ist, kannst Du über **ein Semikolon** weitere Verzeichnisse anhängen, also `was_schon_da_war;C:\MinGW/bin`
6. Schliesse den Dialog und die Systemsteuerung wieder. **Erst dann werden die Änderungen wirksam**.

![Pfadvariable](gitbook/bilder_installation/environment_vars.png)

#### Überprüfung

Öffne eine Windows-Konsole (führe das Programm `cmd` aus). Tippe ohne das Verzeichnis zu wechseln `g++` ein. Wenn die gleiche Fehlermeldung (*`fatal error`*) wie oben erscheint, hat es funktioniert. 

