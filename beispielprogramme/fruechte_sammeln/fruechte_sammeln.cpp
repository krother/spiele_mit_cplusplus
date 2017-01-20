#include <SDL.h>
#include <SDL_image.h>


void kachel_zeichnen(int x, int y, char kachel, SDL_Surface *fruechte, SDL_Surface *surf) {
	// zeichnet eine Kachel
    SDL_Rect source;
    switch (kachel) {
    	case '#': source = {x: 0, y: 0, w:32, h:32}; break;
    	case '_': source = {x: 0, y: 32, w:32, h:32}; break;
    	case 'b': source = {x: 0, y: 64, w:32, h:32}; break;
    	case '*': source = {x: 32, y: 0, w:32, h:32}; break;
    }
    SDL_Rect dest = {x: x*32, y: y*32, w:32, h:32};
    SDL_BlitSurface(fruechte, &source, surf, &dest);
}


void spielfigur_zeichnen(int x, int y, SDL_Surface *fruechte, SDL_Surface *surf) {
	// zeichnet die Spielfigur
    SDL_Rect source = {x: 96, y: 0, w:32, h:32};
    SDL_Rect dest = {x: x*32, y: y*32, w:32, h:32};
    SDL_BlitSurface(fruechte, &source, surf, &dest);
}


void spielfeld_zeichnen(char spielfeld[8][8], SDL_Surface *fruechte, SDL_Surface *surf) {
	// zeichnet das ganze Spielfeld
    for(int x=0; x<8; x++) {
        for(int y=0; y<8; y++) {
		    char kachel = spielfeld[y][x];
		    kachel_zeichnen(x, y, kachel, fruechte, surf);
        }
    }
}


int main(int, char**) {
	// SDL initialisieren
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *win = SDL_CreateWindow("Fruechte", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);

    // Bilder laden
    IMG_Init( IMG_INIT_PNG );
    SDL_Surface *hintergrund = IMG_Load("background.png");
    SDL_Surface *fruechte = IMG_Load("fruit.png");

    // Spielfeld festlegen
	char spielfeld[8][8] = {
		{'#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', 'b', '_', '_', '_', '_', 'b', '#'},
		{'#', '_', '#', '#', 'b', '#', '_', '#'},
		{'#', '_', 'b', '_', '_', '#', '_', '#'},
		{'#', '_', '#', '_', '_', 'b', '_', '#'},
		{'#', '_', '#', 'b', '#', '#', '_', '#'},
		{'#', 'b', '_', '_', '_', '_', '*', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#'}
	};

    // Startposition der Spielfigur
    int figur_x = 3;
    int figur_y = 3;

    // Hilfsvariablen für die Bewegung
    int x_neu;
    int y_neu;
    char neues_feld;

    // Hauptschleife im Spiel
    SDL_Event e;
    bool ende = false;
    while (!ende) {

        // Tastatureingabe behandeln
        if ( SDL_PollEvent( &e ) != 0 ) { 
            if( e.type == SDL_KEYDOWN ) { 
            	x_neu = figur_x;
            	y_neu = figur_y;
            	switch (e.key.keysym.sym) {
            		case 32: ende = true; break;
            		case SDLK_UP: y_neu -= 1; break;
            		case SDLK_DOWN: y_neu += 1; break;
            		case SDLK_LEFT: x_neu -= 1; break;
            		case SDLK_RIGHT: x_neu += 1; break;
            	}

                // prüfen ob neues Feld begehbar
                neues_feld = spielfeld[y_neu][x_neu];
                if (neues_feld == '_' || neues_feld == 'b') {
                	figur_x = x_neu;
                	figur_y = y_neu;
                	spielfeld[y_neu][x_neu] = '_';
                }

                // in den Ausgang gelaufen
                else if (neues_feld == '*') {
                	ende = true;
                }
            }

        // alles zeichnen
        SDL_BlitSurface(hintergrund, NULL, surf, NULL);
        spielfeld_zeichnen(spielfeld, fruechte, surf);
        spielfigur_zeichnen(figur_x, figur_y, fruechte, surf);

        SDL_UpdateWindowSurface(win);
        }
    }

    // Ende des Programms
    return 0;
}
