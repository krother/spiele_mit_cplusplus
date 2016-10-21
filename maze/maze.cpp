#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

const int LEERTASTE = 32;

// SDL starten und Fenster erzeugen
SDL_Window* fenster_initialisieren() {    
    //First we need to start up SDL, and make sure it went ok
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


void blit_tile(SDL_Surface *img, SDL_Surface *surf, int x, int y, int dx, int dy) {
    SDL_Rect srcrect;
    SDL_Rect dstrect;

    srcrect.x = x * 32;
    srcrect.y = y * 32;
    srcrect.w = 32;
    srcrect.h = 32;
    dstrect.x = dx * 32;
    dstrect.y = dy * 32;
    dstrect.w = 32;
    dstrect.h = 32;

    SDL_BlitSurface(img, &srcrect, surf, &dstrect);
}


void event_loop(SDL_Window *win, SDL_Surface *surf, SDL_Surface *img) {
    bool quit = false;
    SDL_Event e; 
    int x = 4;
    int y = 4;

    blit_tile(img, surf, 3, 0, x, y);
    SDL_UpdateWindowSurface(win);
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) { 
            //User requests quit 
            if( e.type == SDL_QUIT ) { 
                quit = true;
            }
            //User presses a key 
            else if( e.type == SDL_KEYDOWN ) { 
                blit_tile(img, surf, 5, 1, x, y);
                //std::cout << e.key.keysym.sym;
                switch( e.key.keysym.sym ) { 
                    case SDLK_UP: y -= 1; break; 
                    case SDLK_DOWN: y += 1; break; 
                    case SDLK_LEFT: x -= 1; break; 
                    case SDLK_RIGHT: x += 1; break; 
                    case LEERTASTE: quit = true; break; 
                    default: std::cout << "nix\n"; break; 
                }
                blit_tile(img, surf, 3, 0, x, y);
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
            blit_tile(img, surf, 0, 1, i, j);
        }
    }

    event_loop(win, surf, img); 
	
	SDL_DestroyWindow(win);
	SDL_Quit();
	
	return 0;
}
