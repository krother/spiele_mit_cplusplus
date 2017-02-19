
# Events in SDL

**Schwierigkeit: SCHWER**

Die Bibliothek SDL verwendet einen anderen Mechanismus, um Tastatureingaben schnell zu verarbeiten.
Dieser basiert auf sogenannten **Events**. 

### Aufgabe 1

Erstelle eine `build.bat`-Datei, um das Programm `sdl_events.cpp` zu compilieren. Du kannst die Datei aus der Aufgabe *"SDL Installieren"* als Vorlage verwenden.

### Aufgabe 2

Führe das Programm aus. Klicke auf das Fenster und drücke einige Tasten auf der Tastatur.

### Aufgabe 3

Schreibe ein Programm, bei dem Du eine Figur auf dem Bildschirm über die Pfeiltasten steuerst.

#### Hinweis:

Wenn Du die Grafik im Bildschirmfenster veränderst, mußt Du jedes Mal `SDL_UpdateWindowSurface(win);` aufrufen, damit die Änderungen dargestellt werden.

