
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cstddef>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;


class Raumschiff {
    // 
    // allgemeine Raumschiff-Klasse
    //
    protected:
        int kachelx = 0;
        int kachely = 0;
    public:
        int posx = 0;
        int posy = 0;
        int geschwindigkeitx = 0;
        int geschwindigkeity = 0;
        bool explodiert = false;

    // Konstruktor
    Raumschiff(int x, int y) {
        posx = x;
        posy = y;
    }
    // bewegt Raumschiff entsprechend Geschwindigkeit
    virtual void bewegen() {
        posx += geschwindigkeitx;
        posy += geschwindigkeity;
        if (posx < 0) {
            posx = 0;
            geschwindigkeitx = 0;
        }
        if (posx > 770) {
            posx = 770;
            geschwindigkeitx = 0;
        }
        if (posy < 0) {
            posy = 0;
            geschwindigkeity = 0;
        }
        if (posy > 570) {
            posy = 570;
            geschwindigkeity = 0;
        }
    }

    // zeichnet schiff
    virtual void zeichnen(SDL_Surface *schiffe, SDL_Surface *surf) {
        SDL_Rect source = {x: kachelx, y: kachely, w:32, h:32};
        SDL_Rect dest = {x: posx, y: posy, w:32, h:32};
        SDL_BlitSurface(schiffe, &source, surf, &dest);
    }

    // prueft ob Schiff sich mit zweitem Schiff überschneidet
    bool kollision(Raumschiff *schiff) {
      SDL_Rect a = {x: posx + 8, y:posy + 8, w:16, h:16};
      SDL_Rect b = {x: schiff->posx + 8, y:schiff->posy + 8, w:16, h:16};
      if (SDL_HasIntersection(&a, &b)) {
          return true;
      }
      return false;
    }
};


class ZufallsSchiff: public Raumschiff {
    // abgeleitete Klasse, Schiff das sich zufällig bewegt
    public : 
      // Konstruktor
      ZufallsSchiff(int x, int y) : Raumschiff(x, y) {kachely = 0;};
      // Bewegung zufällig und mit Gravitation zur Mitte
      void bewegen() {
        int rx = 1 - (rand() % 3);
        int ry = 1 - (rand() % 3);
        geschwindigkeitx += rx - ((posx-400) / 150);
        geschwindigkeity += ry - ((posy-300) / 150);
        Raumschiff::bewegen(); // geerbte Methode aufrufen!
      }
};


class SpielerSchiff: public Raumschiff {
    // abgeleitete Klasse: Schiff das Spieler steuern kann

    public : 
      // Konstruktor: setzt anderes Bild
      SpielerSchiff(int x, int y) : Raumschiff(x, y) {kachely = 160;};

      void oben() { 
        geschwindigkeity -= 1;
      }

      void unten() { 
        geschwindigkeity += 1;
      }

      void links() { 
        geschwindigkeitx -= 1;
      }

      void rechts() { 
        geschwindigkeitx += 1;
      }
};

// erzeugt Vektor mit Zufallsschiffen
vector<Raumschiff*> schiffe_erzeugen(int anzahl) {
    vector<Raumschiff*> schiffe;
    for (int i=0; i<anzahl; i++) {
        Raumschiff *schiff = new ZufallsSchiff(500, i*50 + 50);
        schiffe.push_back(schiff);
    }
    return schiffe;
}


// Abbruch und Tastaturbefehle abhandeln
bool events_behandeln(SpielerSchiff *spieler) {  
    SDL_Event e;
    if ( SDL_PollEvent( &e ) != 0 ) { 
        if( e.type == SDL_QUIT ) {
            return true;
        }
        if( e.type == SDL_KEYDOWN ) { 
            switch (e.key.keysym.sym) {
                case SDLK_UP: spieler->oben();break;
                case SDLK_DOWN: spieler->unten();break;
                case SDLK_LEFT: spieler->links();break;
                case SDLK_RIGHT: spieler->rechts();break;
            }
        }
    }
    return false;
}


// schaltet kollidierte Zufallsschiffe ab
void kollisionen_pruefen(vector<Raumschiff*> schiffe, Raumschiff spieler) {
    for (unsigned int j=0; j<schiffe.size(); j++) {
        if (schiffe[j]->kollision(&spieler)) {
            schiffe[j]->explodiert = true;
        }
    }  
}

// bewegt alle Zufallsschiffe
void schiffe_bewegen(vector<Raumschiff*> schiffe) {
    for (unsigned int j=0; j<schiffe.size(); j++) {
        if (!schiffe[j]->explodiert) {
            schiffe[j]->bewegen();
        }
    }
}

// zeichnet alle Zufallsschiffe
void zeichnen(vector<Raumschiff*> schiffe, Raumschiff spieler, SDL_Surface *raumschiffe, SDL_Surface *surf) {
    for (unsigned int j=0; j<schiffe.size(); j++) {
        if (!schiffe[j]->explodiert) {
            schiffe[j]->zeichnen(raumschiffe, surf);
        }
    }
    spieler.zeichnen(raumschiffe, surf);  
}

// prüft ob noch Schiffe einzusammeln
bool alle_schiffe_gesammelt(vector<Raumschiff*> schiffe) {
    for (unsigned int i=0; i<schiffe.size(); i++) {
        if (!schiffe[i]->explodiert) { return false; }
    }
    return true;
}


int main(int, char**) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *win = SDL_CreateWindow("Raumschiffrennen", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);

    // Bilder laden
    IMG_Init( IMG_INIT_PNG );
    SDL_Surface *hintergrund = IMG_Load("background.png");
    SDL_Surface *raumschiffe = IMG_Load("raumschiffe.png");

    // Leerer Vektor für Raumschiffe
    vector<Raumschiff*> schiffe = schiffe_erzeugen(10);
    SpielerSchiff spieler = SpielerSchiff(50, 285);

    bool ende = false;
    while (!ende) {
        // Hauptschleife
        ende = events_behandeln(&spieler);
        schiffe_bewegen(schiffe);
        spieler.bewegen();
        kollisionen_pruefen(schiffe, spieler);
        
        SDL_BlitSurface(hintergrund, NULL, surf, NULL);
        zeichnen(schiffe, spieler, raumschiffe, surf);
        SDL_UpdateWindowSurface(win);
        SDL_Delay(20);

        if (alle_schiffe_gesammelt(schiffe)) {
            ende = true;
        }
    }

  return 0;
  }
