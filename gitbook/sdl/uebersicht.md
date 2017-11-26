
# Übersicht aller SDL-Funktionen

Hier findest Du Datentypen und Funktionen, die in SDL definiert sind.

## Datentypen

| Datentyp | include | Beschreibung |
|----------|---------|--------------|
| `SDL_Window` | `<SDL.h>` | Ein Bildschirmfenster |
| `SDL_Surface` | `<SDL.h>` | Pixelgrafik, dazu zählt auch die Fensteroberfläche |
| `SDL_Rect` | `<SDL.h>` | Rechteck (x, y, Breite, Höhe) |
| `SDL_Event` | `<SDL.h>` | Ereignis (Tastatur, Maus) |
| `TTF_Font` | `<SDL_ttf.h>` | True Type-Schriftart |

## Funktionen

| Funktion | include | Beschreibung |
|----------|---------|--------------|
| `SDL_Init` | `<SDL.h>` | startet SDL |
| `SDL_CreateWindow` | `<SDL.h>` | erzeugt ein Fenster |
| `SDL_GetWindowSurface` | `<SDL.h>` | gibt die Fensteroberfläche zurück |
| `SDL_LoadBMP` | `<SDL.h>` | lädt eine BMP-Datei |
| `SDL_BlitSurface` | `<SDL.h>` | kopiert von einer Grafik auf eine andere |
| `SDL_UpdateWindowSurface` | `<SDL.h>` | aktualisiert den Fensterinhalt |
| `SDL_PollEvent` | `<SDL.h>` | fragt das nächste Event ab |
| `SDL_HasIntersection` | `<SDL.h>` | prüft, ob sich zwei `SDL_Rect`s überschneiden |
| `SDL_Delay` | `<SDL.h>` | wartet (Millisekunden) |
| `IMG_Init` | `<SDL_image.h>` | initialisiert die Grafikbibliothek |
| `IMG_Load` | `<SDL_image.h>` | lädt ein PNG-Bild |
| `TTF_Init` | `<SDL_ttf.h>` | initialisiert Schriftarten |
| `TTF_OpenFont` | `<SDL_ttf.h>` | lädt eine Schrift |
| `TTF_RenderTextSolid` | `<SDL_ttf.h>` | erzeugt SDL_Surface aus TTF_Font |
