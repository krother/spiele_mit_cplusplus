/*

Chaotischer Code vor dem Refaktorisieren

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
    //
    // Teil 1: Sachen initialisieren
    //

    int position = 0;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *win = SDL_CreateWindow("Finde das Drachenei", 400, 200, 800, 500, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);

    SDL_Init(IMG_INIT_PNG);
    SDL_Surface *sumpf = IMG_Load("sumpf.png");
    
    SDL_Surface *wueste = IMG_Load("wueste.png");
    SDL_Surface *eis = IMG_Load("berge.png");
    bool zustand_kiste = false;
    
    SDL_Surface *turm = IMG_Load("turm.png");
    bool moench1 = false;

    SDL_Surface *drachenei = IMG_Load("drachenei.png");

    bool ende = false;
    bool moench2 = false;

    // Hauptschleife
    while (!ende) {

        SDL_Event e;
        int taste;
        if (SDL_PollEvent(&e) != 0) {
            //
            // Teil 2: Events auswerten
            //
            if (e.type == SDL_KEYDOWN) {
                taste = e.key.keysym.sym;

                if (taste == SDLK_RIGHT && position < 4) {
                    position++;
                }
                if (taste == SDLK_LEFT && position > 0) {
                    position = position - 1;
                }
                if (taste == SDLK_UP) {
                    if (position == 2) {
                        zustand_kiste = true;
                    }
                }
                if ((SDLK_UP == taste) && (3 == position) && !moench2) {
                    moench1 = true;
                }


                if ((taste == SDLK_DOWN) && (position == 3) && moench1 && zustand_kiste) {
                    moench1 = false;
                    moench2 = true;
                }
                if ((SDLK_UP == taste) && (position == 4) && moench2 && !ende) {
                    ende = true;
                }
            }
        }
        
        //
        // Teil 3: Grafik malen
        //
        SDL_Surface *stein = IMG_Load("stein.png");
        if (position == 1) {
            SDL_BlitSurface(eis, NULL, surf, NULL);
            SDL_UpdateWindowSurface(win);
        }
        else if (position == 2) {
            SDL_BlitSurface(wueste, NULL, surf, NULL);
            SDL_UpdateWindowSurface(win);
        }
        else if (position == 4) {
            SDL_BlitSurface(drachenei, NULL, surf, NULL);
            SDL_UpdateWindowSurface(win);
        }
        if (position == 2) {
            if (zustand_kiste) {
                SDL_Surface *kiste_offen = IMG_Load("kiste_offen.png");
                SDL_BlitSurface(kiste_offen, NULL, surf, NULL);
            }
            else {
                SDL_Surface *kiste = IMG_Load("kiste_geschlossen.png");
                SDL_BlitSurface(kiste, NULL, surf, NULL);
            }
            SDL_UpdateWindowSurface(win);
        }
        if (position > 2 && position < 4) {
            SDL_BlitSurface(turm, NULL, surf, NULL);
            SDL_UpdateWindowSurface(win);
        }
        if (moench1 && (position == 3)) {
            SDL_BlitSurface(turm, NULL, surf, NULL);
            SDL_Surface *monk = IMG_Load("magier.png");
            SDL_BlitSurface(monk, NULL, surf, NULL);
            SDL_UpdateWindowSurface(win);
        }
        if (zustand_kiste && !moench2) {
            SDL_Surface *rolle = IMG_Load("rolle.png");
            SDL_BlitSurface(rolle, NULL, surf, NULL);
            SDL_UpdateWindowSurface(win);
        }
        if (position == 0) {
            SDL_BlitSurface(sumpf, NULL, surf, NULL);
            SDL_UpdateWindowSurface(win);
        }
        if (moench2) {
            SDL_BlitSurface(stein, NULL, surf, NULL);
        }
            SDL_UpdateWindowSurface(win);

        SDL_Delay(100);
    }

    // Spielende
    SDL_Surface *drachenei_aktiv = IMG_Load("drachenei_aktiv.png");
    SDL_BlitSurface(drachenei_aktiv, NULL, surf, NULL);
    SDL_UpdateWindowSurface(win);


    SDL_Delay(2000);

    return 0;
}
