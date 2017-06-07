/*

Musterlösung zum Drachenei-Projekt

*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cstddef>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
using namespace std;

int main(int a, char **b) {

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *win = SDL_CreateWindow("Finde das Drachenei", 400, 200, 800, 500, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);

    SDL_Init(IMG_INIT_PNG);
    
    SDL_Surface *sumpf = IMG_Load("sumpf.png");
    SDL_Surface *wueste = IMG_Load("wueste.png");
    SDL_Surface *eis = IMG_Load("berge.png");
    SDL_Surface *turm = IMG_Load("turm.png");
    SDL_Surface *drachenei = IMG_Load("drachenei.png");
    SDL_Surface *drachenei_aktiv = IMG_Load("drachenei_aktiv.png");
    SDL_Surface *kiste = IMG_Load("kiste_geschlossen.png");
    SDL_Surface *kiste_offen = IMG_Load("kiste_offen.png");
    SDL_Surface *monk = IMG_Load("magier.png");
    SDL_Surface *rolle = IMG_Load("rolle.png");
    SDL_Surface *stein = IMG_Load("stein.png");

    bool ende = false;
    bool chest_open = false;
    bool monk_appears = false;
    bool monk_finished = false;
    SDL_Surface *bilder[5] = {sumpf, eis, wueste, turm, drachenei};
    int position = 0;

    while (!ende) {

        SDL_Event e;
        int taste;
		if (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_KEYDOWN) {
				taste = e.key.keysym.sym;

				if (taste == SDLK_RIGHT && position < 4) {
					position++;
				}
				if (taste == SDLK_LEFT && position > 0) {
					position--;
				}
				if ((taste == SDLK_UP) && (position == 2)) {
					chest_open = true;
				}
				if ((taste == SDLK_UP) && (position == 3) && !monk_finished) {
					monk_appears = true;
				}
				if ((taste == SDLK_DOWN) && (position == 3) && monk_appears && chest_open) {
					monk_appears = false;
					monk_finished = true;
				}
				if ((taste == SDLK_UP) && (position == 4) && monk_finished) {
					ende = true;
				}
			}
		}
    	
        SDL_BlitSurface(bilder[position], NULL, surf, NULL);
        if (position == 2) {
        	if (chest_open) {
                SDL_BlitSurface(kiste_offen, NULL, surf, NULL);
        	}
            else {
                SDL_BlitSurface(kiste, NULL, surf, NULL);
            }
        }
        if (monk_appears && (position == 3)) {
            SDL_BlitSurface(monk, NULL, surf, NULL);
        }
        if (chest_open && !monk_finished) {
            SDL_BlitSurface(rolle, NULL, surf, NULL);
        }
        if (monk_finished) {
            SDL_BlitSurface(stein, NULL, surf, NULL);
        }
        SDL_UpdateWindowSurface(win);
        SDL_Delay(100);
    }
    SDL_BlitSurface(drachenei_aktiv, NULL, surf, NULL);
    SDL_UpdateWindowSurface(win);
    SDL_Delay(2000);

    return 0;
}
