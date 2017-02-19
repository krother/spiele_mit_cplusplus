#include <SDL.h>
#include <SDL_image.h>

void sterne_zeichnen(int spalte, SDL_Surface *png, SDL_Surface *surf) {
	SDL_Rect source = {x: 0, y: 0, w: 800, h:600};
	SDL_Rect destination = {x: spalte, y: 0, w: 800, h:600};
	SDL_BlitSurface(png, &source, surf, &destination);
}

void schiff_zeichnen(int x, int y, SDL_Surface *raumschiff, SDL_Surface *surf) {
	SDL_Rect source = {x: 0, y: 96, w: 32, h:32};
	SDL_Rect destination = {x: x, y: y, w: 800, h:600};
	SDL_BlitSurface(raumschiff, &source, surf, &destination);
}


int main(int, char**) {
	// 1. SDL initialisieren [OK]
    SDL_Init(SDL_INIT_VIDEO);
	
    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);
	
    IMG_Init( IMG_INIT_PNG );
	
    SDL_Surface *hintergrund = IMG_Load("background.png");
    SDL_Surface *s1 = IMG_Load("stars1.png");
    SDL_Surface *s2 = IMG_Load("stars2.png");
    SDL_Surface *s3 = IMG_Load("stars3.png");
    SDL_Surface *raumschiffe = IMG_Load("raumschiffe.png");
	
	// 2. x = 0 (Spalte fuer den Ausschnitt)
	int spalte1 = 0;
	int spalte2 = 0;
	int spalte3 = 0;
	
	// Raumschiff-Position
	int raumx = 700;
	int raumy = 100;

    // Raumschiff-Geschwindigkeit
	int geschwx = 0;
	int geschwy = 0;

	
	// 6. Schleife (100x), zurueck zu 3.
	for (int i=0; i<2000; i++) {
    	SDL_BlitSurface(hintergrund, NULL, surf, NULL);
		
		// 3. Bild an Stelle x kopieren [OK]
		sterne_zeichnen(spalte1, s1, surf);
		sterne_zeichnen(spalte1-800, s1, surf);

		sterne_zeichnen(spalte2, s2, surf);
		sterne_zeichnen(spalte2-800, s2, surf);

		sterne_zeichnen(spalte3, s3, surf);
		sterne_zeichnen(spalte3-800, s3, surf);
		
		schiff_zeichnen(raumx, raumy, raumschiffe, surf);
		
		// 4. x um 1 verschieben [OK]
		spalte1 += 4; // spalte1 = spalte1 +4
		if (spalte1 >= 800) {
			spalte1 = 0;
		}
		spalte2 += 2; // spalte1 = spalte1 +4
		if (spalte2 >= 800) {
			spalte2 = 0;
		}
		spalte3 += 1; // spalte1 = spalte1 +4
		if (spalte3 >= 800) {
			spalte3 = 0;
		}
		
        SDL_Event e;
		int taste;
		if (SDL_PollEvent( &e )	!= 0 ) { 
            if( e.type == SDL_KEYDOWN ) { 
                taste = e.key.keysym.sym;
				if (taste == SDLK_UP) {
					geschwy -= 1;
				}
				else if (taste == SDLK_DOWN) {
					geschwy += 1;
				}
				else if (taste == SDLK_LEFT) {
					geschwx -= 1;
				}
				else if (taste == SDLK_RIGHT) {
					geschwx += 1;
				}
			}
		}

		// Raumschiff-Position verändern
		raumx += geschwx;
		raumy += geschwy;

		// Stoppen am Spielfeldrand
		if (raumx > 768) {raumx = 768;}
		if (raumx < 0) {raumx = 0;}
		if (raumy > 568) {raumy = 568;}
		if (raumy < 0) {raumy = 0;}

		// 5. Fenster aktualisieren [OK]
		SDL_UpdateWindowSurface(win);
		//SDL_Delay(20);
    }

	return 0;
}
