/*
 * editor.cpp
 *
 * Editor fuer Kachelbasierte Levels
 *      Author: Kristian Rother
 */

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <grafik.h>
using namespace std;


void spielfeld_zeichnen(char spielfeld[8][8], SDL_Surface *fruechte, SDL_Surface *surf) {
	// zeichnet das ganze Spielfeld
    for(int x=0; x<8; x++) {
        for(int y=0; y<8; y++) {
		    char kachel = spielfeld[y][x];
		    kachel_zeichnen(x, y, kachel, fruechte, surf);
        }
    }
}


int main(int, char**) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);
    SDL_Surface *hintergrund = IMG_Load("background.png");
	IMG_Init( IMG_INIT_PNG );
	SDL_Surface *f = IMG_Load("fruit.png");

    // Spielfeld festlegen
	char spielfeld[8][8] = {
		{'#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', 'b', '_', '_', '_', '_', 'b', '#'},
		{'#', '_', '#', '#', 'b', '#', '_', '#'},
		{'#', '_', 'b', '_', '_', '#', '_', '#'},
		{'#', '_', '#', '_', '_', 'b', '_', '#'},
		{'#', '_', '#', 'b', '#', '#', '_', '#'},
		{'#', 'b', '_', '_', '_', '_', '*', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#'}
	};

	int taste;
	bool ende = false;
	SDL_Rect frucht;
	SDL_Rect ziel;
	int mausx = 0;
	int mausy = 0;
	char kachel = 'b';


	while(ende == false){
		SDL_Event e;
		if (SDL_PollEvent(&e) != 0) {

			if(e.type == SDL_KEYDOWN){
				// Druck auf Tastatur
				// schaltet die zu zeichnende Kachel um
				taste = e.key.keysym.sym;
				printf("taste: %i\n", taste);
				if (taste == 32) { // Leertaste beendet das Programm
					ende = true;
				}
				else if (taste == 97) { // a = Mauer
					kachel = '#';
				}
				else if (taste == 98) { // b = Banane
					kachel = 'b';
				}
				else { // alles andere
					kachel = '_';
				}
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN) {
				// bei Druck auf die Maustaste
				// wird auf das Spielfeld eine neue Kachel geschrieben
				spielfeld[mausy/32][mausx/32] = kachel;
				SDL_BlitSurface(hintergrund, NULL, surf, NULL);
				spielfeld_zeichnen(spielfeld, f, surf);
			}
			else if (e.type == SDL_MOUSEMOTION) {
				// bei Mausbewegung soll die Kachel gezeichnet werden,
				// welche bei Knopfdruck gesetzt werden würde
				mausx = e.motion.x;
				mausy = e.motion.y;
				printf("mausx ist %i und mausy ist %i.\n", mausx, e.motion.y);
				SDL_BlitSurface(hintergrund, NULL, surf, NULL);
				spielfeld_zeichnen(spielfeld, f, surf);
				// Teilen durch 32 ergibt eine Position im Raster
		    	kachel_zeichnen(mausx/32, mausy/32, kachel, f, surf);

		    	// zeichnet eine frei schwebende Kachel am Mauszeiger
				/* 
				frucht = {x:0, y:32, w:32, h:32};
				ziel = {x:mausx, y:mausy, w:32, h:32};
				SDL_BlitSurface(f, &frucht, surf, &ziel);
				*/
			}
		SDL_UpdateWindowSurface(win);
		}
	}
	return 0;
}




