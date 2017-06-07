/*

Zwischenergebnis der Refaktorisierung nach einer Stunde

*/
#include <SDL.h>
#include <SDL_image.h>

#define SUMPF 0
#define EISWUESTE 1
#define WUESTE 2
#define TURM 3
#define TAL 4

int main(int a, char* b[]) {
    //
    // Teil 1: Sachen initialisieren
    //
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *win = SDL_CreateWindow("Finde das Drachenei", 400, 200, 800, 500, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);

    SDL_Init(IMG_INIT_PNG);

    // Bilder laden
    SDL_Surface *sumpf = IMG_Load("sumpf.png");
    SDL_Surface *wueste = IMG_Load("wueste.png");
    SDL_Surface *eis = IMG_Load("berge.png");
    SDL_Surface *turm = IMG_Load("turm.png");
    SDL_Surface *stein = IMG_Load("stein.png");
    SDL_Surface *kiste_offen = IMG_Load("kiste_offen.png");
    SDL_Surface *kiste = IMG_Load("kiste_geschlossen.png");
    SDL_Surface *monk = IMG_Load("magier.png");
    SDL_Surface *rolle = IMG_Load("rolle.png");
    SDL_Surface *drachenei_aktiv = IMG_Load("drachenei_aktiv.png");
    SDL_Surface *drachenei = IMG_Load("drachenei.png");

    SDL_Surface *raeume[5] = {sumpf, wueste, eis, turm, drachenei};

    // Zustandsvariablen
    int position = SUMPF;
    bool kiste_geoeffnet = false;
    bool moench_erschienen = false;
    bool moench_zufrieden = false;
    bool ende = false;

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

                switch (taste) {
                case SDLK_RIGHT:
                    if (position < TAL) {
                        position++;
                    }
                    break;
                case SDLK_LEFT:
                    if (position > SUMPF) {
                        position--;
                    }
                    break;
                case SDLK_UP:
                    if (position == WUESTE) {
                       kiste_geoeffnet = true;
                    }
                    if (position == TURM && !moench_zufrieden) {
                       moench_erschienen = true;
                    }
                    if (TAL == position && moench_zufrieden && !ende) {
                        ende = true;
                    }
                    break;
                case SDLK_DOWN:
                    if (position == TURM && moench_erschienen && kiste_geoeffnet) {
                       moench_erschienen = false;
                       moench_zufrieden = true;
                    }
                    break;
                }
            }
        }

        //
        // Teil 3: Grafik malen
        //
        SDL_BlitSurface(raeume[position], NULL, surf, NULL);

        if (position == WUESTE) {
            if (kiste_geoeffnet) {
                SDL_BlitSurface(kiste_offen, NULL, surf, NULL);
            }
            else {
                SDL_BlitSurface(kiste, NULL, surf, NULL);
            }
        }
        if (moench_erschienen && (position == TURM)) {
            SDL_BlitSurface(turm, NULL, surf, NULL);
            SDL_BlitSurface(monk, NULL, surf, NULL);
        }
        if (kiste_geoeffnet && !moench_zufrieden) {
            SDL_BlitSurface(rolle, NULL, surf, NULL);
        }
        if (moench_zufrieden) {
            SDL_BlitSurface(stein, NULL, surf, NULL);
        }

        SDL_UpdateWindowSurface(win);
        SDL_Delay(100);
    }

    // Spielende
    SDL_BlitSurface(drachenei_aktiv, NULL, surf, NULL);
    SDL_UpdateWindowSurface(win);


    SDL_Delay(2000);
    return 0;
}
