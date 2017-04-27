
# Erste Schritte mit SDL

### Ein Fenster erzeugen

    #include <SDL.h>
    #include <SDL_image.h>

    int main() {
        SDL_Init(SDL_INIT_VIDEO);
        SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 300, 300, SDL_WINDOW_SHOWN);
    }


### Ein Bild laden

Um ein Bild namens `fruechte.png` zu laden:

    IMG_Init( IMG_INIT_PNG );    
    SDL_Surface *png = IMG_Load("fruechte.png");
    

### Ein ganzes Bild kopieren
   
    SDL_BlitSurface(img, NULL, surf, NULL);

### Einen rechteckigen Bildbereich kopieren

    SDL_Rect source{x: x*32, y: y*32, w:32, h:32};
    SDL_Rect destination{x: dx*32, y: dy*32, w:32, h:32};
    SDL_BlitSurface(img, &source, surf, &destination);

### Das Fenster aktualisieren

Immer nachdem wir in das Fenster gezeichnet haben, müssen wir das Fenster aktualisieren. Sonst sehen wir nichts: 

    SDL_UpdateWindowSurface(win);

### Zwei Sekunden warten

    SDL_Delay(2000);
