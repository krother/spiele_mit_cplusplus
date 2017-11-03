#include <iostream>
#include <SDL.h>
#include <SDL_image.h>


// SDL starten und Fenster erzeugen
SDL_Window* fenster_initialisieren() {    
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init( IMG_INIT_PNG );
    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    return win;
}


// eine Kachel zeichnen
void blit(SDL_Surface *img, SDL_Surface *surf, int x, int y, int dx, int dy) {
    SDL_Rect source{x: x*32, y: y*32, w:32, h:32};
    SDL_Rect destination{x: dx*32, y: dy*32, w:32, h:32};
    SDL_BlitSurface(img, &source, surf, &destination);
}


void feld_fuellen(SDL_Surface *img, SDL_Surface *surf) {
    // 20x15 Kacheln mit Boden zeichnen
    for (int i=0; i<20; i++) {
        for (int j=0; j<15; j++) {
            blit(img, surf, 0, 1, i, j);
        }
    }
}

void hauptschleife(SDL_Window *win, SDL_Surface *surf, SDL_Surface *img) {
    bool quit = false;
    SDL_Event e; 
    int x = 4;
    int y = 4;

    blit(img, surf, 3, 0, x, y);
    SDL_UpdateWindowSurface(win);
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) { 
            // Benutzer beendet das Spiel
            if( e.type == SDL_QUIT ) { 
                quit = true;
            }
            // Benutzer drueckt eine Taste
            else if( e.type == SDL_KEYDOWN ) { 
                blit(img, surf, 5, 1, x, y);
                switch( e.key.keysym.sym ) { 
                    case SDLK_UP: y -= 1; break; 
                    case SDLK_DOWN: y += 1; break; 
                    case SDLK_LEFT: x -= 1; break; 
                    case SDLK_RIGHT: x += 1; break; 
                    case SDLK_SPACE: 
                    case SDLK_ESCAPE: quit = true; break; 
                }
                blit(img, surf, 3, 0, x, y);
            }
        }
        SDL_UpdateWindowSurface(win);
    }
}


int main(int, char**){
    SDL_Window *win = fenster_initialisieren();
    SDL_Surface *surf = SDL_GetWindowSurface(win);
    SDL_Surface *img = IMG_Load("tiles.png");
    
    feld_fuellen(img, surf);

    hauptschleife(win, surf, img); 
    
    SDL_DestroyWindow(win);
    SDL_Quit();
    
    return 0;
}
