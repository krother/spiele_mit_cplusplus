
# Beispiele zu SDL

### SDL initialisieren

    #include <SDL.h>
    #include <SDL_image.h>

    int main() {
        SDL_Init(SDL_INIT_VIDEO);
        SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 300, 300, SDL_WINDOW_SHOWN);
    }



### ganzes Bild kopieren
   
    SDL_BlitSurface(img, NULL, surf, NULL);

### rechteckigen Bildbereich kopieren

    SDL_Rect source{x: x*32, y: y*32, w:32, h:32};
    SDL_Rect destination{x: dx*32, y: dy*32, w:32, h:32};
    SDL_BlitSurface(img, &source, surf, &destination);


### Zwei Sekunden warten

    SDL_Delay(2000);

### Box mit Nachricht anzeigen

	SDL_ShowSimpleMessageBox(0, "Hello", "Hello World", win);
    
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
             "Fenstertitel", "Hello World.", NULL);
