#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h> 

using namespace std;

const int LEERTASTE = 32;

// SDL starten und Fenster erzeugen
int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 300, 300, SDL_WINDOW_SHOWN);
    SDL_Event e;

    int taste = 0; 
    while(taste != LEERTASTE) {
        while( SDL_PollEvent( &e ) != 0 ) { 
            // Benutzer drueckt eine Taste BEI ANGEKLICKTEM FENSTER
            if( e.type == SDL_KEYDOWN ) { 
                taste = e.key.keysym.sym;
                printf("%i\n", taste); // cout funktioniert mit SDL nicht
            }
        }
        SDL_UpdateWindowSurface(win);
    }

	SDL_Quit();	
	return 0;
}
