
# SDL unter Code::Blocks installieren

Für einen Großteil des Kurses verwenden wir die Bibliothek **SDL**.

Diese Installation folgt dem [fantastischen Tutorial von Lazy Foo](http://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/codeblocks/index.php).

## Schritt 1: SDL herunterladen

Lade die SDL-Bibliothek für Dein Betriebssystem von [libsdl.org](http://libsdl.org/download-2.0.php) herunter. 

Unter Windows benötigen die **Development Libraries für MinGW**.

## Schritt 2: Entpacken

1. Entpacke die Datei mit einem geeigneten Programm (*kann Windows10 das?*).
2. Finde den Unterordner `i686-w64-mingw32` (32 Bit, auch bei neueren Rechnern, weil Meister Foo das auch so tut)
3. Verschiebe diesen Ordner in Dein Lieblingsverzeichnis.
4. Benenne den Ordner in `mingw_dev_libs` um.
5. Wirf den Rest weg.


## Schritt 3: Schauen was drin ist

Das Verzeichnis `mingw_dev_libs` sollte folgende Unterverzeichnisse enthalten:

| Verzeichnis | Inhalt |
|-------------|--------------|
| `bin/`        | eine DLL-Datei |
| `include/`    | Header-Dateien (das "Inhaltsverzeichnis" von SDL) |
| `lib/`        | die vorcompilierte Bibliothek |
| `share/`      | kann weg |


## Schritt 4: Projekt in Code::Blocks erstellen

siehe voriges Kapitel

## Schritt 5: Header-Dateien 

Wir müssen Code::Blocks sagen, wo die Verzeichnisse `include/`- und `lib` sind. Beginnen wir mit `include/`:

1. Rechtsklick auf das Projekt in der Projektleiste
2. Wähle *'Properties'* (ganz unten)
3. Wähle *'Projects Build Options'* (rechts unten)
4. Drücke auf die Karte *'Search directories'*
5. Drücke auf die Karte *'Compiler'*
6. Drücke auf den Knopf *'Add'*.
7. Wähle im Dialog (über den *...*-Knopf) das Verzeichnis `mingw_dev_libs/include/SDL2` 
8. Bestätige die Auswahl

## Schritt 6: Libaries 

Es folgt `lib/`:

1. Schritte 1.-4. wie zuvor
2. Drücke auf die Karte *'Linker'*
3. Drücke auf den Knopf *'Add'*.
4. Wähle im Dialog (über den *...*-Knopf) das Verzeichnis `mingw_dev_libs/lib` 
5. Drücke auf die Karte *'Linker settings'*
6. Trage bei *'Other linker settings'* ein: `-lmingw32 -lSDL2main -lSDL2`

#### Anmerkung: 
Wenn Du auch noch **SDL_Image** installierst (im PNG-Bilder einzulesen), muss dort stehen:

    -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

## Schritt 7: Testen

An dieser Stelle sollte das Programm bereits compilerbar sein, und eine `.exe`-Datei erzeugt werden.

## Schritt 8: DLLs kopieren

Kopiere die `.dll`-Datei aus `bin/` dorthin wo die `.exe`-Datei liegt (meist im *'Debug/'*-Unterverzeichnis des Projekts).

## Schritt 9: Bilder kopieren

Kopiere alle benötigten Bilder in das Verzeichnis, in dem Auch die `.cpp`-Dateien liegen.


## Schritt 10: Fertig!

Führe das Programm aus.


## SDL_Image installieren

Führe die Schritte 1-10 auch für [SDL_image](`https://www.libsdl.org/projects/SDL_image/`) durch.


## TIP

Du musst nicht alle Schritte für jedes neue Projekt durchführen. Das Herunterladen genügt einmal. 

Auch ein Code::Blocks-Projekt sollte sich irgendwie kopieren lassen, so dass Du nicht jedes Mal alles neu einstellen mußt.


*(getestet unter MinGW C++)*


## SDL2 unter Mac installieren

Es gibt eine sehr schöne Anleitung von LazyFoo zum Installieren von SDL2 unter dem Mac-Editor **xcode**: [http://lazyfoo.net/tutorials/SDL/01_hello_SDL/mac/xcode/index.php](http://lazyfoo.net/tutorials/SDL/01_hello_SDL/mac/xcode/index.php)
