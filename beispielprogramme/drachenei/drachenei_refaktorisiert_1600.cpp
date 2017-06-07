/*

Ergebnis der Refaktorisierung nach dem Zerlegen in Funktionen.

*/
#include <SDL.h>
#include <SDL_image.h>

#define SUMPF 0
#define EISWUESTE 1
#define WUESTE 2
#define TURM 3
#define TAL 4

struct Spielzustand {
    int position;
    bool kiste_geoeffnet;
    bool moench_erschienen;
    bool moench_zufrieden;
    bool ende;
};

Spielzustand bewegung_rechts(Spielzustand z) {
    if (z.position < TAL) {
    	z.position++;
    }
    return z;
}
Spielzustand bewegung_links(Spielzustand z) {
	if (z.position > SUMPF) {
    	z.position--;
    }
    return z;
}

Spielzustand benutzen(Spielzustand z) {
    if (z.position == WUESTE) {
       z.kiste_geoeffnet = true;
    }
    if (z.position == TURM && !z.moench_zufrieden) {
       z.moench_erschienen = true;
    }
    if (TAL == z.position && z.moench_zufrieden && !z.ende) {
        z.ende = true;
    }
    return z;
}

Spielzustand rolle_geben(Spielzustand z){
	if (z.position == TURM && z.moench_erschienen && z.kiste_geoeffnet) {
	    z.moench_erschienen = false;
	    z.moench_zufrieden = true;
    }
    return z;
}


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
    Spielzustand z = {SUMPF, false, false, false, false};

    // Hauptschleife
    while (!z.ende) {

        SDL_Event e;
        int taste;
        if (SDL_PollEvent(&e) != 0) {
            //
            // Teil 2: Events auswerten
            //
            if (e.type == SDL_KEYDOWN) {
                taste = e.key.keysym.sym;

                switch (taste) {
                case SDLK_RIGHT: z = bewegung_rechts(z); break;
                case SDLK_LEFT: z = bewegung_links(z); break;
                case SDLK_UP: z = benutzen(z); break;
                case SDLK_DOWN: z = rolle_geben(z); break;
                }
            }
        }

        //
        // Teil 3: Grafik malen
        //
        SDL_BlitSurface(raeume[z.position], NULL, surf, NULL);

        if (z.position == WUESTE) {
            if (z.kiste_geoeffnet) {
                SDL_BlitSurface(kiste_offen, NULL, surf, NULL);
            }
            else {
                SDL_BlitSurface(kiste, NULL, surf, NULL);
            }
        }
        if (z.moench_erschienen && (z.position == TURM)) {
            SDL_BlitSurface(turm, NULL, surf, NULL);
            SDL_BlitSurface(monk, NULL, surf, NULL);
        }
        if (z.kiste_geoeffnet && !z.moench_zufrieden) {
            SDL_BlitSurface(rolle, NULL, surf, NULL);
        }
        if (z.moench_zufrieden) {
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
