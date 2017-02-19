// classes example
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cstddef>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

const int BREITE = 24;

void zeichen_schreiben(char c, int x, int y, SDL_Surface *bild, SDL_Surface *surf) {

    int charx = c % 16;
    int chary = c / 16;
	SDL_Rect source = {x: 25 * charx + 26, y: chary*50 + 40, w:23, h:23};
	SDL_Rect dest = {x: x, y: y, w:16, h:16};
	SDL_BlitSurface(bild, &source, surf, &dest);
}


int main(int, char**) {
		// SDL initialisieren
	    SDL_Init(SDL_INIT_VIDEO);

	    SDL_Window *win = SDL_CreateWindow("Textausgabe", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
	    SDL_Surface *surf = SDL_GetWindowSurface(win);

	    // Bilder laden
	    IMG_Init( IMG_INIT_PNG );
	    SDL_Surface *hintergrund = IMG_Load("background.png");
	    SDL_Surface *schrift = IMG_Load("ascii-table_24bw.png");
        // ASCII code table 1.1 by Tom Gibara is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License.

        SDL_BlitSurface(hintergrund, NULL, surf, NULL);

        string text = "Hallo Welt!";
        for (unsigned int i=0; i<text.size(); i++) {
        	zeichen_schreiben(text[i], i*BREITE + 32, 32, schrift, surf);
        }
        SDL_UpdateWindowSurface(win);
	    SDL_Delay(3000);
   
  return 0;
}