#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

const int LEERTASTE = 32;

// SDL starten und Fenster erzeugen
SDL_Window* fenster_initialisieren() {    
    // SDL Starten
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return NULL;
    }
    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

    if (win == 0) {
      std::cout << "window failed"; 
      return NULL;
    }
    return win;
}


// Laden des Bildes mit Spielelementen
SDL_Surface* kacheln_laden(SDL_Surface *surf) {
    int imgFlags = IMG_INIT_PNG; 
    if( !( IMG_Init( imgFlags ) & imgFlags ) ) { 
        //printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() ); 
        return NULL;
    }

    SDL_Surface *xpm = IMG_Load("tiles.xpm");
    if (xpm == NULL){
        std::cout << "SDL Image Loading Error: " << SDL_GetError() << std::endl;
        return NULL;
    }
    SDL_Surface *img = SDL_ConvertSurface( xpm, surf->format, 0 );
    return img;
}


void blit(SDL_Surface *img, SDL_Surface *surf, int x, int y, int dx, int dy) {
    SDL_Rect source{x: x*32, y: y*32, w:32, h:32};
    SDL_Rect destination{x: dx*32, y: dy*32, w:32, h:32};
    SDL_BlitSurface(img, &source, surf, &destination);
}


void event_loop(SDL_Window *win, SDL_Surface *surf, SDL_Surface *img) {
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
                    case LEERTASTE: quit = true; break; 
                    default: std::cout << "nix\n"; break; 
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
    SDL_Surface *img = kacheln_laden(surf);

    // Feld fuellen
    for (int i=0; i<20; i++) {
        for (int j=0; j<15; j++) {
            blit(img, surf, 0, 1, i, j);
        }
    }

    event_loop(win, surf, img); 
	
	SDL_DestroyWindow(win);
	SDL_Quit();
	
	return 0;
}
