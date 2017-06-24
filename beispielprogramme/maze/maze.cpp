#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "spielfeld.h"
#include "kachel.h"
#include "figur.h"
#include "sdl_app.h"
//#include "klapptuer.h"
using namespace std;


const int LEERTASTE = 32;


Uint32 tuer_auf(Uint32, void*);
Uint32 tuer_zu(Uint32, void*);


Uint32 tuer_auf( Uint32 interval, void *param ) {
  spielfeld[4][4] = '.';
  int *p = NULL;
  SDL_AddTimer( 1000, tuer_zu, p);
  return 0;
}


Uint32 tuer_zu( Uint32 interval, void *param ) {
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
          SDL_App *app;
          void event_loop();
          void feld_fuellen();
          Spiel(SDL_App*);
};



Spiel::Spiel(SDL_App *a) {
  app = a;
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



void Spiel::event_loop() {
    bool quit = false;
    SDL_Event e; 
    Spieler spieler1;
    spieler1.position_setzen(1, 1);
    Geist geist;
    geist.position_setzen(5,5);

    int *p = NULL;
    SDL_AddTimer(1000, tuer_auf, p);

    app->blit(kFresserRechts, spieler1.x, spieler1.y);
    app->blit(kGeist, geist.x, geist.y);
    SDL_UpdateWindowSurface(app->win);
    
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) { 
            // Benutzer beendet das Programm 
            if( e.type == SDL_QUIT ) { 
                quit = true;
            }
            // Benutzer drueckt eine Taste
            else if( e.type == SDL_KEYDOWN ) { 
                if (rattenschwanz) {
                  app->blit(kRattenschwanz, spieler1.x, spieler1.y);
                }
                else {
                  app->blit(kBoden, spieler1.x, spieler1.y);
                }
                spieler1.taste_auswerten(e, spielfeld);
                if ( e.key.keysym.sym == LEERTASTE) { 
                    quit = true;
                }
            }
        }
        // Spieler zeichnen
        spieler1.aussehen_ermitteln();
        app->blit(spieler1.aussehen, spieler1.x, spieler1.y);
        // Geist zeichnen
        app->blit(kBoden, geist.x, geist.y);
        geist.zufallsbewegung(spielfeld);
        app->blit(kGeist, geist.x, geist.y);
        // Klapptuer zeichnen
        if (spielfeld[4][4] == '.') { 
          app->blit(kBoden, 4, 4);
        }
        else { 
          app->blit(kWand, 4, 4);
        }
        SDL_UpdateWindowSurface(app->win);
        SDL_Delay(200);
    }  
}



void Spiel::feld_fuellen() {
    for (int x=0; x<7; x++) {
        for (int y=0; y<7; y++) {
            if (spielfeld[y][x] == '#') {
                app->blit(kWand, x, y);
            }
            else if (spielfeld[y][x] == '.') {
                app->blit(kBoden, x, y);
            }
            else if (spielfeld[y][x] == '*') {
                app->blit(kPunkt, x, y);
            }
        }
    }
}

int main(int, char**){
    srand(time(NULL));

    SDL_App app(100, 100, 640, 480);
    Spiel spiel(&app);

    spiel.rattenschwanz = false; 
    spiel.feld_fuellen();
    spiel.event_loop();

    app.destroy();
	  return 0;
}





