
# Installation von C++ unter Windows

## Schritt 1: MinGW installieren

Zuerst installieren wir den C++-Compiler **MinGW**.

1. Lade die Installationsdatei für MinGW für Windows von [www.mingw.org/category/wiki/download](http://www.mingw.org/category/wiki/download) herunter
2. Starte die Installationsdatei
3. Wähle in der Paketauswahl die Pakete **base** und **gcc** an (siehe Abbildung)

#### Überprüfung

Öffne eine Windows-Konsole (führe das Programm `cmd` aus). Wechsle in das MinGW Verzeichnis mit

    cd C:\MinGW\bin

Führe das Programm `g++` aus. Wenn Du die folgende Fehlermeldung siehst, hat alles funktioniert.

    g++: fatal error: no input files
    compilation terminated.

**Gratuliere!** Damit hast Du theoretisch alles was Du benötigst. Allerdings werden wir noch ein paar weiter Programme installieren, um uns die Arbeit bequemer zu machen.


## Schritt 2: Pfad auf MinGW setzen

Damit wir den Compiler `g++` von überall her starten können, müssen wir die sogenannte **Pfadvariable** setzen. Windows sucht nach zu startenden Programmen in den im Pfad angegebenen Verzeichnissen.

1. Öffne die *Systemsteuerung*
2. Öffne dort die Kategorie *System*
3. Wähle dort den Abschnitt *Erweiterte Systemeinstellungen* oder *Erweitert*
4. Drücke den Knopf *Umgebungsvariablen*
5. Erstelle eine neue Umgebungsvariable *PATH* mit dem Wert *`C:\MinGW\bin`* . Falls *PATH* bereits definiert ist, kannst Du über einen Doppelpunkt weitere Verzeichnisse anhängen, also `was_schon_da_war:C:\MinGW/bin`
6. Schliesse den Dialog und die Systemsteuerung wieder. **Erst dann werden die Änderungen wirksam.

SIEHE BILD

#### Überprüfung

Öffne eine Windows-Konsole (führe das Programm `cmd` aus). Tippe ohne das Verzeichnis zu wechseln `g++` ein. Wenn die gleiche Fehlermeldung (*`fatal error`*) wie oben erscheint, hat es funktioniert. 

#### Erste Hilfe

Falls das Setzen der Umgebungsvariable aus irgendwelchen Gründen nicht funktioniert, kannst Du Dir immer noch helfen, indem Du den Compiler jedes Mal (z.B. in einem Build-Skript) mit `C:\MinGW\bin\g++` statt nur `g++` aufrufst.

## Schritt 3: Eclipse installieren

**Eclipse** ist eine komfortablere Entwicklungsumgebung zum Schreiben von C++-Programmen. Allerdings ist die Einarbeitung auch deutlich länger als mit einem Texteditor. Eclipse ist in der Programmiersprache **Java** geschrieben, die wir ebenfalls installieren müssen.

1. Lade das **JDK** herunter (**nicht** JRE), siehe [www.java.com](http://www.java.com)
2. Lade **Eclipse Neon** von [www.eclipse.org](http://www.eclipse.org) herunter
3. Installiere das JDK.
4. Installiere Eclipse. Wähle im Installationsprogramm die Option **Eclipse für C++**

#### Überprüfung

Erstelle in Eclipse ein **"C++ Hello World Project"** für MinGW. Kompiliere das Programm mit dem Knopf **build** und führe es aus. Wenn du eine Nachricht im Ausgabefenster siehst, hat alles funktioniert. 

#### Erste Hilfe

Falls die Option *"Eclipse für C++"* bei Schritt 4 nicht erscheint, suche im Internet nach **Eclipse CDT**.


## Schritt 4: SDL konfigurieren

In diesem Schritt werden wir SDL-Programme unter Eclipse zum Laufen bringen.

