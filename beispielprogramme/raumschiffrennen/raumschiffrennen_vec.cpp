// classes example
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cstddef>

#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Raumschiff {
    private:
	  unsigned int kurs_position = 0;
	  int schritte = 0;
    protected:
	  string kurs = "RRRRRRRRRRRRRRRRRR";
    public:
	  string name;
      int posx = 0;
      int posy = 0;
      int geschwindigkeit = 0;

      Raumschiff(string n, int x, int y, string k) {
          name = n;
          posx = x;
          posy = y;
          kurs = k;
      }
      virtual void kurs_setzen(string neuer_kurs) {
    	  kurs = neuer_kurs;
      }
      virtual void schneller(int beschleunigung) {
          geschwindigkeit += beschleunigung;
      }
      virtual void langsamer() {
    	  geschwindigkeit--;
      }
      virtual void bewegen() {
    	  // je nachdem welcher Buchstabe im Kurs
    	  // an der Stelle kurs_position steht,
    	  // verändere die Position posx / posy
    	  char richtung;
    	  richtung = kurs[kurs_position];
    	  switch (richtung) {
    	      case 'R': posx += geschwindigkeit; break;
    	      case 'L': posx -= geschwindigkeit; break;
    	      case 'O': posy -= geschwindigkeit; break;
    	      case 'U': posy += geschwindigkeit; break;
    	      default: break;
    	  }
          // Bewegungszähler hochsetzen
          schritte++;
          if (schritte == 32) {
            // ein Buchstabe aus dem Kurs fertig abgearbeitet
        	  kurs_position++;
        	  schritte = 0;
        	  if (kurs_position == kurs.length()) {
        		  kurs_position = 0;
        	  }
          }

      }
      virtual void ausgabe(SDL_Surface *bild, SDL_Surface *surf) {
    	  SDL_Rect source = {x: 0, y: 160, w:32, h:32};
    	  SDL_Rect dest = {x: posx, y: posy, w:32, h:32};
    	  SDL_BlitSurface(bild, &source, surf, &dest);
      }
};

class SchnellesSchiff: public Raumschiff {

public:
	SchnellesSchiff(string n, int y, string k):
		Raumschiff(n, 0, y, k) {};
	virtual void schneller(int beschleunigung) {
		// 3 Mal schneller als normales Raumschiff
		geschwindigkeit += 3*beschleunigung;
	}
};


class Apollo: public Raumschiff {
	public:
	 Apollo(string n, int x, int y, string k): Raumschiff(n,x,y,k) {
          name = n;
          posx = x;
          posy = y;
          kurs = k;
      }
		void ausgabe(SDL_Surface *bild, SDL_Surface *surf){
			SDL_Rect source = {x: 0, y: 32, w:32, h:32};
			SDL_Rect dest = {x: posx, y: posy, w:32, h:32};
			SDL_BlitSurface(bild, &source, surf, &dest);
		}
};

int main(int, char**) {
		// SDL initialisieren
	    SDL_Init(SDL_INIT_VIDEO);

	    SDL_Window *win = SDL_CreateWindow("Raumschiffrennen", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
	    SDL_Surface *surf = SDL_GetWindowSurface(win);

	    // Bilder laden
	    IMG_Init( IMG_INIT_PNG );
	    SDL_Surface *hintergrund = IMG_Load("background.png");
	    SDL_Surface *raumschiffe = IMG_Load("raumschiffe.png");

      // Leerer Vektor für Raumschiffe
      vector<Raumschiff*> schiffe;

      Raumschiff *neues_schiff = new SchnellesSchiff("Nostromo", 64, "RURURORU");
      neues_schiff->schneller(1);
      schiffe.push_back(neues_schiff);

      neues_schiff = new Raumschiff("Enterprise", 0, 96, "RRRRROLLORURULLL");
      neues_schiff->schneller(1);
      schiffe.push_back(neues_schiff);

      neues_schiff = new Apollo("Voyager", 0, 128, "R");
      neues_schiff->schneller(1);
      schiffe.push_back(neues_schiff);

      neues_schiff = new Raumschiff("Enterprise", 0, 96, "RRRRROLLORURULLL");
      neues_schiff->schneller(2);
      schiffe.push_back(neues_schiff);
      
      neues_schiff = new Raumschiff("Voyager", 0, 128, "R");
      neues_schiff->schneller(3);
      schiffe.push_back(neues_schiff);

      neues_schiff = new Raumschiff("Millenium Falcon", 0, 192, "RURRURRROOOLLLLLLU");
      neues_schiff->schneller(3);
      schiffe.push_back(neues_schiff);

      neues_schiff = new Raumschiff("TIE", 0, 256, "OORRUULL");
      neues_schiff->schneller(3);
      schiffe.push_back(neues_schiff);

  for (int i=0; i<500; i++) {
	  SDL_BlitSurface(hintergrund, NULL, surf, NULL);

	  // Schiffe bewegen
	  for (unsigned int j=0; j<schiffe.size(); j++) {
   	      schiffe[j]->bewegen();
   	      schiffe[j]->ausgabe(raumschiffe, surf);
	  }
	  SDL_UpdateWindowSurface(win);
	  SDL_Delay(10);
  }

  return 0;
}
