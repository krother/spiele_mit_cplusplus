
#include <SDL.h>
#include <SDL_image.h>
using namespace std;


class Raumschiff {
    private:
        int kachelx = 0;
        int kachely = 160;
    public:
        int posx = 0;
        int posy = 0;
        int geschwindigkeitx = 0;
        int geschwindigkeity = 0;

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
      void oben() { 
        geschwindigkeity -= 2;
      }

      void unten() { 
        geschwindigkeity += 2;
      }

      void links() { 
        geschwindigkeitx -= 2;
      }

      void rechts() { 
        geschwindigkeitx += 2;
      }
};


// Abbruch und Tastaturbefehle abhandeln
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
            }
        }
    }
    return false;
}



class Sterne {
    public:
      SDL_Surface *bild;
      int position;

      Sterne(SDL_Surface *sternbild) {
          bild = sternbild;
          position = 0;
      }
      void bewegen(int geschwindigkeit) {
          position += geschwindigkeit;
          if (position >= 800) {
              position -= 800;
          }
      }
      void zeichnen(SDL_Surface *surf) {
        SDL_Rect source = {x: 0, y: 0, w:800, h:600};
        SDL_Rect dest = {x: position, y: 0, w:800, h:600};
        SDL_BlitSurface(bild, &source, surf, &dest);
        dest = {x: position-800, y: 0, w:800, h:600};
        SDL_BlitSurface(bild, &source, surf, &dest);
      }
};


int main(int, char**) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *win = SDL_CreateWindow("Raumschiffrennen", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);

    // Bilder laden
    IMG_Init( IMG_INIT_PNG );
    SDL_Surface *hintergrund = IMG_Load("background.png");
    SDL_Surface *raumschiffe = IMG_Load("raumschiffe.png");
    SDL_Surface *sterne1 = IMG_Load("stars1.png");
    SDL_Surface *sterne2 = IMG_Load("stars2.png");
    SDL_Surface *sterne3 = IMG_Load("stars3.png");

    Sterne s1(sterne1);
    Sterne s2(sterne2);
    Sterne s3(sterne3);

    Raumschiff spieler = Raumschiff(50, 285);

    bool ende = false;
    while (!ende) {
        // Hauptschleife
        ende = events_behandeln(&spieler);
        spieler.bewegen();
        s1.bewegen(6);
        s2.bewegen(3);
        s3.bewegen(1);
        
        SDL_BlitSurface(hintergrund, NULL, surf, NULL);
        s1.zeichnen(surf);
        s2.zeichnen(surf);
        s3.zeichnen(surf);
        spieler.zeichnen(raumschiffe, surf);
        SDL_UpdateWindowSurface(win);
        SDL_Delay(20);
    }

  return 0;
  }
