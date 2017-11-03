
# Grafiken anzeigen

### Die Bibliothek SDL_image

`SDL_image` ist eine Erweiterung für SDL, mit der auch `.png`-Dateien eingelesen werden können (sonst gehen auf Windows nur `.bmp`-Bilder).

`SDL_image` benötigt ein eigenes `include`:

    #include <SDL_image.h>


### Ein Bild laden

Ein Bild namens `fruechte.png` kannst Du folgendermaßen laden:

    IMG_Init( IMG_INIT_PNG );    
    SDL_Surface *png = IMG_Load("fruechte.png");
    

### Ein ganzes Bild kopieren

Um das Bild aus dem vorigen Beispiel dann auch darzustellen, reicht eine Zeile:

    SDL_BlitSurface(png, NULL, surf, NULL);

### Einen rechteckigen Bildbereich kopieren

Die Funktion `SDL_BlitSurface` kopiert einen rechteckingen Bereich aus einem Bild in den Bildschirmspeicher. Über die zwei Rechtecke (hier beide als `struct`) können wir den zu kopierenden Ausschnitt festlegen, sowie das Zielrechteck im Bildschirmspeicher.

    SDL_Rect source{x: 0, y: 0, w:400, h:100};
    SDL_Rect destination{x: 50, y: 50, w:200, h:200};
    SDL_BlitSurface(img, &source, surf, &destination);

### Das Fenster aktualisieren

Jedes Mal, wenn wir in ein Fenster gezeichnet haben, müssen wir das Fenster aktualisieren. Sonst sehen wir nichts: 

    SDL_UpdateWindowSurface(win);
