
# Text in SDL

## Die Bibliothek SDL_ttf

Mit der SDL-Erweiterung [SDL_ttf](https://www.libsdl.org/projects/SDL_ttf/) lassen sich **True Type Fonts** laden und darstellen.

Dazu musst Du die Bibliothek herunterladen, installieren (wie SDL_image) und in den *Build Options* die Option `-lSDL_ttf` hinzufügen.

## Includes

Folgende zwei Includes sind sinnvoll:

    #include <string>
    #include <SDL_ttf.h>

## Schriften laden

Um eine Schrift zu verwenden, benötigst Du eine **.ttf-Datei**. Die Initialisierung ist nicht schwer; Du lädst die Schrift in einen Zeiger vom Typ `TTF_Font`.

    TTF_Init();
    TTF_Font *font;
    font = TTF_OpenFont("LucidaSansDemiBold.ttf", 36);

Dabei steht die `36` für die Schriftgröße in Punkten.


## Text zu Oberflächen rendern

Texte liegen meist als Strings vor. Du musst aus diese in ein Bild verwandeln. Dazu gibt es die Funktion `TTF_RenderText_Solid`:

    string text = "Hello World!";    
	SDL_Color black = {0, 0, 0};

    SDL_Surface* tsurf = TTF_RenderText_Solid(font, text.c_str(), farbe);

Die Variable `tsurf` enthält den fertigen Text als Grafikelement, ähnlich den geladenen Bildern.

## Farben

Du kannst unterschiedliche Farben ausprobieren:

    SDL_Color red = {255, 0, 0};
    SDL_Color green = {0, 255, 0};
    SDL_Color blue = {0, 0, 255};
    SDL_Color white = {255, 255, 255};


## Abschluß

Die gerenderte Schrift musst Du wie ein Bild per `SDL_BlitSurface` zeichnen. Dazu besorgen wir uns die Breite und Höhe der gerenderten Grafik:

    int breite = tsurf->w;
    int hoehe = tsurf->h;
    SDL_Rect pos = {x, y, breite, hoehe};

    SDL_BlitSurface(tsurf, NULL, surf, &pos);

Und nach dem Blitten aller Bildelemente aktualisieren wir das Bildschirmfenster:

    SDL_UpdateWindowSurface(win);

Wenn Du sehr oft Text renderst, solltest Du den Speicherplatz nach jeder Benutzung von `tsurf` wieder freigeben:

    SDL_FreeSurface(tsurf);


Eine genaue Anleitung findet sich auch bei [Lazy Foo](http://lazyfoo.net/tutorials/SDL/16_true_type_fonts/index.php).
