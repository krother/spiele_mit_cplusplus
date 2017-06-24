#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


/*
   Sternenhimmel
*/
class Sterne {
    public:
      SDL_Surface *bild;
      int position;

      Sterne(SDL_Surface *sternbild) {
          bild = sternbild;
          position = 0;
      }

      void bewegen(int geschwindigkeit) {
          position -= geschwindigkeit;
          if (position <= -800) {
              position += 800;
          }
      }

      void zeichnen(SDL_Surface *surf) {
        SDL_Rect source = {x: 0, y: 0, w:800, h:600};
        SDL_Rect dest = {x: position, y: 0, w:800, h:600};
        SDL_BlitSurface(bild, &source, surf, &dest);
        dest = {x: position+800, y: 0, w:800, h:600};
        SDL_BlitSurface(bild, &source, surf, &dest);
      }
};


/*
   Oberklasse für Spielerschiff, Gegner und Boni
*/
class Flugobjekt {
  private:
    SDL_Surface *bild;
  protected:
    int kachelx;
    int kachely;
    int animationsbilder;
  public:
    int posx = 0;
    int posy = 0;

    Flugobjekt(SDL_Surface *_bild, int startx, int starty) {
        bild = _bild;
        posx = startx;
        posy = starty;
        kachelx = 0;
        kachely = 0;
        animationsbilder = 0;
    }

    // Platzhalter
    virtual void bewegen() {}

    void zeichnen(SDL_Surface *surf) {
        SDL_Rect source = {x: kachelx, y: kachely, w:32, h:32};
        SDL_Rect dest = {x: posx, y: posy, w:32, h:32};
        SDL_BlitSurface(bild, &source, surf, &dest);
    }

    void animation() {
        kachely += 32;
        if (kachely >= 32 * animationsbilder) {
            kachely = 0;
        }
    }

    bool kollision(Flugobjekt obj) {
        SDL_Rect schiff = {x: posx+4, y: posy+8, w:24, h:16};
        SDL_Rect flugobj = {x: obj.posx+4, y: obj.posy+4, w:24, h:24};
        return SDL_HasIntersection(&schiff, &flugobj);
    }
};

/*
   Spieler
*/
class Raumschiff: public Flugobjekt {
    public:
        int vecx = 0;
        int vecy = 0;

    // Konstruktor
    Raumschiff(SDL_Surface *_bild, int startx, int starty): Flugobjekt(_bild, startx, starty) {
        kachelx = 0;
        kachely = 160;
    }

    // bewegt Raumschiff entsprechend Geschwindigkeit
    virtual void bewegen() {
        posx += vecx;
        posy += vecy;
        if (posx < 0) {
            posx = 0;
            vecx = 0;
        }
        if (posx > 770) {
            posx = 770;
            vecx = 0;
        }
        if (posy < 0) {
            posy = 0;
            vecy = 0;
        }
        if (posy > 570) {
            posy = 570;
            vecy = 0;
        }
    }

    // Bewegungen
    void oben() { 
        vecy -= 3;
    }

    void unten() { 
        vecy += 3;
    }

    void links() { 
        vecx -= 3;
    }

    void rechts() { 
        vecx += 3;
    }
};


/*
   Gegner - bewegt sich im Zick-Zack
*/
class Blitzy: public Flugobjekt {
  private:
    int xvec;
    int yvec;
  public: 
    Blitzy(SDL_Surface *_bild, int startx, int starty): Flugobjekt(_bild, startx, starty) {
      xvec = -3;
      yvec = -6;
      animationsbilder = 4;
    }

    virtual void bewegen() {
        posx += xvec;
        posy += yvec;
        if (posy > 550 || posy < 30) { yvec *= -1; } // Richtung wechseln
        if (posx < -32) { posx = 850; } // wieder rechts erscheinen
        animation();
    }
};

/*
   Stern - bewegt sich und ist animiert
*/
class Bonus: public Flugobjekt {
  public:
    // Konstruktor
    Bonus(SDL_Surface *_bild, int startx, int starty): Flugobjekt(_bild, startx, starty) {
      animationsbilder = 12;
    }

    void zuruecksetzen() {
      posx = 830;                // nach rechts setzen
      posy = rand() % 550 + 10;  // auf zufälliger Höhe
    }

    void bewegen() {
        // Bewegung
        posx -= 5;
        if (posx < -32) {            // am linken Rand
          zuruecksetzen();
        }
        animation();
    }
};


/*
   Metorit - bewegt sich einfach nur schnell
*/
class Meteor: public Flugobjekt {
  public:
    // Konstruktor
    Meteor(SDL_Surface *_bild, int startx, int starty): Flugobjekt(_bild, startx, starty) {
      animationsbilder = 4;
    }

    void bewegen() {
        // es werden vier verschiedene Teile aus dem Bild angezeigt
        // Bewegen
        posx -= 8;
        if (posx < -32) {            // hinter dem linken Rand
          posy = rand() % 550 + 10;  // auf zufälliger Höhe
          posx = 810;                // nach rechts setzen
        }
        animation();
    }
};


/*
   Ereignisse - Abbruch und Tastaturbefehle abhandeln
*/
bool events_behandeln(Raumschiff *spieler) {  
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
                case SDLK_ESCAPE: return true;
            }
        }
    }
    return false;
}

/*
   Hauptprogramm
*/
int main(int, char**) {
    srand(time(NULL));  // Zufallsgenerator für Meteorit und Bonus

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *win = SDL_CreateWindow("Raumschiffrennen", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);

    // Bilder laden
    IMG_Init( IMG_INIT_PNG );
    SDL_Surface *hintergrund = IMG_Load("background.png");
    SDL_Surface *b_raumschiffe = IMG_Load("raumschiffe.png");
    SDL_Surface *b_bonus = IMG_Load("star_large.ppm");
    SDL_Surface *b_blitzy = IMG_Load("blitzy.ppm");
    SDL_Surface *b_meteor = IMG_Load("shot.ppm");
    SDL_Surface *sterne1 = IMG_Load("stars1.png");
    SDL_Surface *sterne2 = IMG_Load("stars2.png");
    SDL_Surface *sterne3 = IMG_Load("stars3.png");

    Sterne s1(sterne1);
    Sterne s2(sterne2);
    Sterne s3(sterne3);

    // Objekte erstellen
    Raumschiff spieler = Raumschiff(b_raumschiffe, 50, 285);
    Bonus bonus = Bonus(b_bonus, 700,100);
    Blitzy blitzy = Blitzy(b_blitzy, 700, 500);
    Meteor meteor = Meteor(b_meteor, 800, 300);

    /*
        Hauptschleife
    */
    int sterne_gesammelt = 0;
    bool ende = false;
    while (!ende) {
        ende = events_behandeln(&spieler);

        // alles bewegen
        spieler.bewegen();
        blitzy.bewegen();
        bonus.bewegen();
        meteor.bewegen();
        s1.bewegen(6);
        s2.bewegen(3);
        s3.bewegen(1);

        // Kollisionsabfrage
        if (spieler.kollision(blitzy) || spieler.kollision(meteor)) { ende = true;}
        if (spieler.kollision(bonus)) { 
            bonus.zuruecksetzen();
            sterne_gesammelt++;
        }
        
        // alles zeichnen
        SDL_BlitSurface(hintergrund, NULL, surf, NULL);
        s1.zeichnen(surf);
        s2.zeichnen(surf);
        s3.zeichnen(surf);
        spieler.zeichnen(surf);
        blitzy.zeichnen(surf);
        bonus.zeichnen(surf);
        meteor.zeichnen(surf);
        SDL_UpdateWindowSurface(win);
        SDL_Delay(20);
    }

  cout << "Sterne gesammelt: " << sterne_gesammelt << endl;
  return 0;
  }
