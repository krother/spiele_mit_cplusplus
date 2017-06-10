/*

Beispiel: Sternenhimmel mit Klasse

*/
#include <SDL.h>
#include <SDL_image.h>


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
		// SDL initialisieren
	    SDL_Init(SDL_INIT_VIDEO);

	    SDL_Window *win = SDL_CreateWindow("Sternenhimmel", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
	    SDL_Surface *surf = SDL_GetWindowSurface(win);

	    // Bilder laden
	    IMG_Init( IMG_INIT_PNG );
	    SDL_Surface *hintergrund = IMG_Load("background.png");
      SDL_Surface *sterne1 = IMG_Load("stars1.png");
      SDL_Surface *sterne2 = IMG_Load("stars2.png");
	    SDL_Surface *sterne3 = IMG_Load("stars3.png");

      Sterne s1(sterne1);
      Sterne s2(sterne2);
      Sterne s3(sterne3);

  for (int i=0; i<500; i++) {
      s1.bewegen(6);
      s2.bewegen(3);
      s3.bewegen(1);
      SDL_BlitSurface(hintergrund, NULL, surf, NULL);
      s1.zeichnen(surf);
      s2.zeichnen(surf);
      s3.zeichnen(surf);

      SDL_UpdateWindowSurface(win);
	    SDL_Delay(10);
  }


  return 0;
}

