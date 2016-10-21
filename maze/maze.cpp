#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "spielfeld.h"
#include "kachel.h"
#include "figur.h"
//#include "klapptuer.h"
using namespace std;


const int LEERTASTE = 32;


Uint32 tuer_auf(Uint32, void*);
Uint32 tuer_zu(Uint32, void*);


Uint32 tuer_auf( Uint32 interval, void *param ) {
  printf("Tür ist auf\n");
  spielfeld[4][4] = '.';
  int *p = NULL;
  SDL_AddTimer( 1000, tuer_zu, p);
  return 0;
}


Uint32 tuer_zu( Uint32 interval, void *param ) {
  printf("Tür ist zu\n");
  spielfeld[4][4] = '#';
  int *p = NULL;
  SDL_AddTimer( 1000, tuer_auf, p);
  return 0;
}



class Spieler: public Figur {
  public: Kachel aussehen;
  public: void taste_auswerten(SDL_Event, char[7][7]);
          void aussehen_ermitteln();
          
};


class Geist: public Figur {
  public: void zufallsbewegung(char[7][7]);
};

void Geist::zufallsbewegung(char spielfeld[7][7]) {
  int r = rand() % 4;
  switch( r ) { 
          case 1: richtung = eOBEN; break; 
          case 2: richtung = eUNTEN; break; 
          case 3: richtung = eLINKS; break; 
          case 0: richtung = eRECHTS; break;
          default: return;
  }
  bewegen(spielfeld);
}



class Spiel {
  public: bool rattenschwanz;
          SDL_Window *win;
  private: void blit_tile(SDL_Surface*, SDL_Surface*, Kachel, int, int);
  public: SDL_Surface* kacheln_laden(SDL_Surface*);
          void event_loop(SDL_Window*, SDL_Surface*, SDL_Surface*);
          void feld_fuellen(SDL_Surface*, SDL_Surface*);
          Spiel(short, short, short, short);
};


Spiel::Spiel(short x, short y, short breite, short hoehe) {
    // SDL starten und Fenster erzeugen
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0){
        cout << "SDL_Init Error: " << SDL_GetError() << endl;
    }
    win = SDL_CreateWindow("Hello World!", x, y, breite, hoehe, SDL_WINDOW_SHOWN);

    if (win == 0) {
      cout << "window failed"; 
    }
}


// Laden des Bildes mit Spielelementen
SDL_Surface* Spiel::kacheln_laden(SDL_Surface *surf) {
    int imgFlags = IMG_INIT_PNG; 
    if( !( IMG_Init( imgFlags ) & imgFlags ) ) { 
        cout << "SDL_image could not initialize! SDL_image Error:" << IMG_GetError() << endl; 
        return NULL;
    }

    SDL_Surface *xpm = IMG_Load("tiles.png");
    if (xpm == NULL){
        cout << "SDL Image Loading Error: " << SDL_GetError() << endl;
        return NULL;
    }
    SDL_Surface *img = SDL_ConvertSurface( xpm, surf->format, 0 );
    return img;
}


void Spiel::blit_tile(SDL_Surface *img, SDL_Surface *surf, Kachel kachel, int dx, int dy) {
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

    SDL_BlitSurface(img, &srcrect, surf, &dstrect);
}

void Spieler::taste_auswerten(SDL_Event e, char spielfeld[7][7]) {
  switch( e.key.keysym.sym ) { 
          case SDLK_UP: richtung = eOBEN; break; 
          case SDLK_DOWN: richtung = eUNTEN; break; 
          case SDLK_LEFT: richtung = eLINKS; break; 
          case SDLK_RIGHT: richtung = eRECHTS; break;
          default: return;
  }
  bewegen(spielfeld);
}


void Spieler::aussehen_ermitteln() {
  switch(richtung) { 
          case eOBEN: aussehen = kFresserHoch; break;
          case eUNTEN: aussehen = kFresserRunter; break;
          case eLINKS: aussehen = kFresserLinks; break;
          case eRECHTS: aussehen = kFresserRechts; break;
  }
}



void Spiel::event_loop(SDL_Window *win, SDL_Surface *surf, SDL_Surface *img) {
    bool quit = false;
    SDL_Event e; 
    Spieler spieler1;
    spieler1.position_setzen(1, 1);
    Geist geist;
    geist.position_setzen(5,5);

    int *p = NULL;
    SDL_AddTimer( 1000, tuer_auf, p);

    blit_tile(img, surf, kFresserRechts, spieler1.x, spieler1.y);
    blit_tile(img, surf, kGeist, geist.x, geist.y);
    SDL_UpdateWindowSurface(win);
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) { 
            //User requests quit 
            if( e.type == SDL_QUIT ) { 
                quit = true;
            }
            //User presses a key 
            else if( e.type == SDL_KEYDOWN ) { 
                if (rattenschwanz) {
                  blit_tile(img, surf, kRattenschwanz, spieler1.x, spieler1.y);
                }
                else {
                  blit_tile(img, surf, kBoden, spieler1.x, spieler1.y);
                }
                spieler1.taste_auswerten(e, spielfeld);
                if ( e.key.keysym.sym == LEERTASTE) { 
                    quit = true;
                }
                // Spieler zeichnen
                spieler1.aussehen_ermitteln();
                blit_tile(img, surf, spieler1.aussehen, spieler1.x, spieler1.y);
                // Geist zeichnen
                blit_tile(img, surf, kBoden, geist.x, geist.y);
                geist.zufallsbewegung(spielfeld);
                blit_tile(img, surf, kGeist, geist.x, geist.y);
                // Klapptuer zeichnen
                if (spielfeld[4][4] == '.') { 
                  blit_tile(img, surf, kBoden, 4, 4);
                }
                else { 
                  blit_tile(img, surf, kWand, 4, 4);
                }
            }
        }
        SDL_UpdateWindowSurface(win);
    }  
}



void Spiel::feld_fuellen(SDL_Surface *img, SDL_Surface *surf) {
    // Feld fuellen
    for (int x=0; x<7; x++) {
        for (int y=0; y<7; y++) {
            if (spielfeld[y][x] == '#') {
                blit_tile(img, surf, kWand, x, y);
            }
            else if (spielfeld[y][x] == '.') {
                blit_tile(img, surf, kBoden, x, y);
            }
            else if (spielfeld[y][x] == '*') {
                blit_tile(img, surf, kPunkt, x, y);
            }
        }
    }
}

int main(int, char**){
    srand(time(NULL));

    Spiel spiel(100, 100, 640, 480);

    SDL_Surface *surf = SDL_GetWindowSurface(spiel.win);
    SDL_Surface *img = spiel.kacheln_laden(surf);

    // Nachricht ausgeben
    //SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
    //         "Fenstertitel", "Hello World.", NULL);

    spiel.rattenschwanz = false;
 
    spiel.feld_fuellen(img, surf);
    spiel.event_loop(spiel.win, surf, img); 
	SDL_DestroyWindow(spiel.win);

 	SDL_Quit();
	
	return 0;
}





