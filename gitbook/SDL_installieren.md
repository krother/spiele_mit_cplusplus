
# SDL installieren

Für einen Großteil des Kurses verwenden wir die Bibliothek **SDL** mit dem Compiler MinGW C++.
Bevor wir mit den Übungen fortfahren können, müssen wir die Bibliothek installieren. Diese Kurzanleitung basiert auf dem Tutorial von *Lazyfoo* [http://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/mingw/index.php](http://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/mingw/index.php).

1. Öffne eine Konsole mit `cmd`.
2. Stelle sicher daß **MinGW** installiert ist (`g++` eingeben).
3. Erstelle einen Ordner `mingw_dev_libs`.
4. Entpacke die Datei `SDL2_devel..`
5. Kopiere den Inhalt des Unterordners `i686...32` nach `mingw_dev_libs`
6. Kopiere die `.dll`-Dateien aus `bin/` dorthin wo das Programm läuft.
7. Verfahre genauso mit SDL_image (`https://www.libsdl.org/projects/SDL_image/`)


*(getestet unter MinGW C++)*

## SDL2 unter Mac installieren

Es gibt eine sehr schöne Anleitung von LazyFoo zum Installieren von SDL2 unter dem Mac-Editor **xcode**: [http://lazyfoo.net/tutorials/SDL/01_hello_SDL/mac/xcode/index.php](http://lazyfoo.net/tutorials/SDL/01_hello_SDL/mac/xcode/index.php)
