#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include "sdl_app.h"
#include "kachel.h"
using namespace std;


SDL_App::SDL_App(short x, short y, short breite, short hoehe) {
    // SDL starten und Fenster erzeugen
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0){
        printf("SDL_Init Error: \n%s\n", SDL_GetError());
    }
    win = SDL_CreateWindow("Hello World!", x, y, breite, hoehe, SDL_WINDOW_SHOWN);

    if (win == 0) {
      printf("Fenster Initialisierung fehlgeschlagen"); 
    }

    surf = SDL_GetWindowSurface(win);
    kacheln_laden();
}

// Laden des Bildes mit Spielelementen
void SDL_App::kacheln_laden() {
    if( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) ) { 
        printf("SDL_image konnte nicht initialisiert werden: \n%s\n", IMG_GetError());
        return;
    }

    SDL_Surface *png = IMG_Load("tiles.png");
    if (png == NULL){
        printf("Fehler beim Laden von SDL Image: \n%s\n", SDL_GetError());
        return;
    }
    
    kacheln = SDL_ConvertSurface( png, surf->format, 0 );
}


void SDL_App::blit(Kachel kachel, int dx, int dy) {
    SDL_Rect srcrect;
    SDL_Rect dstrect;

    srcrect.x = kachel.x * 32;
    srcrect.y = kachel.y * 32;
    srcrect.w = 32;
    srcrect.h = 32;
    dstrect.x = dx * 32;
    dstrect.y = dy * 32;
    dstrect.w = 32;
    dstrect.h = 32;

    SDL_BlitSurface(kacheln, &srcrect, surf, &dstrect);
    return;
}

void SDL_App::destroy() {

    SDL_DestroyWindow(win);
   	SDL_Quit();
    return;
}
