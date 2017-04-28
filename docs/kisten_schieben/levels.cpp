#include <levels.hpp>
#include <vector>
#include <cstddef>
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;


void kiste_zeichnen(int x, int y, SDL_Surface *png, SDL_Surface *surf) {
			SDL_Rect source = { 207, 534, 43, 43 };
			SDL_Rect dest = { x, y, 43, 43 };
			SDL_BlitSurface(png, &source, surf, &dest);
}
			
void spielfigur_zeichnen(int sx, int sy, int sw, int sh, int dx, int dy, int positionx, int positiony, SDL_Surface *bild, SDL_Surface *surf) {
	SDL_Rect source = { sx, sy, sw, sh };
	SDL_Rect dest = { dx * 43 + positionx, dy * 43 + positiony, 43, 43 };
	SDL_BlitSurface(bild, &source, surf, &dest);
}

bool zum_hauptmenue(SDL_Surface *felder, SDL_Surface *schilder, SDL_Surface *schriftbild, SDL_Surface *surf, SDL_Window *win){

	//Mini-Menü, wenn man während eines Levels Escape drückt. Wenn man zum Hauptmenü zurückkehrt, muss man
	//wieder bei Level 1 anfangen; drückt man auf Abbrechen, kann man da weiter machen, wo man aufgehört hat.

	bool ende = false;
	int taste;
	SDL_Event e;
	
	int kiste_posx = 310;
	int kiste_posy = 260;

	while (!ende) {

		if (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_KEYDOWN) {
				taste = e.key.keysym.sym;

				if (taste == SDLK_RIGHT) {
					kiste_posx = 420;
				}
				else if (taste == SDLK_LEFT) {
					kiste_posx = 310;
				}

				if (taste == SDLK_RETURN && kiste_posx == 310) {
					return false;
				}
				else if (taste == SDLK_RETURN && kiste_posx == 420) {
					return true;
				}
			}
		
		}
			SDL_Rect source = { 5, 390, 280, 122 };
			SDL_Rect dest = { 290, 197, 280, 122 };
			SDL_BlitSurface(schilder, &source, surf, &dest);
		
			kiste_zeichnen(kiste_posx, kiste_posy, felder, surf);
		
			SDL_UpdateWindowSurface(win);
	
	}
}

bool bewegung(int figur_y, int figur_x, int ziel_y, int ziel_x, Spielfeld_Vektor aktuelleMap) {

	if (aktuelleMap[figur_y + ziel_y][figur_x + ziel_x] == 'A' || aktuelleMap[figur_y + ziel_y][figur_x + ziel_x] == 'B') {
		return false;
	}
	else if (aktuelleMap[figur_y + ziel_y][figur_x + ziel_x] == 'K' || aktuelleMap[figur_y + ziel_y][figur_x + ziel_x] == 'L') {
		if (aktuelleMap[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] == 'K' || aktuelleMap[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] == 'L' || aktuelleMap[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] == 'A' || aktuelleMap[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] == 'B') {
			return false;
		}
	}
	else {
		return true;
	}
};

bool schieben(int figur_y, int figur_x, int ziel_y, int ziel_x, Spielfeld_Vektor aktuelleMap) {
	if (aktuelleMap[figur_y + ziel_y][figur_x + ziel_x] == 'K' && aktuelleMap[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] == 'F') {
		return true;
	}
	if (aktuelleMap[figur_y + ziel_y][figur_x + ziel_x] == 'K' && aktuelleMap[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] == 'X') {
		return true;
	}
	if (aktuelleMap[figur_y + ziel_y][figur_x + ziel_x] == 'L' && aktuelleMap[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] == 'F') {
		return true;
	}
	if (aktuelleMap[figur_y + ziel_y][figur_x + ziel_x] == 'L' && aktuelleMap[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] == 'X') {
		return true;
	}
	else {
		return false;
	}
};

bool geschafft(Spielfeld_Vektor aktuelleMap){
	
	int Klebeband_Anzahl = 0;
	
	for (int j = 0; j<aktuelleMap.size(); j++){
		for (int i = 0; i<aktuelleMap[j].size(); i++){
			
			if(aktuelleMap[j][i] == 'X'){
				Klebeband_Anzahl++;
			}
		}
	}
	
	if(Klebeband_Anzahl == 0){
				return true;
	}
}

void zeichen_schreiben(char c, int x, int y, SDL_Surface *bild, SDL_Surface *surf) {

    int charx = c % 16;
    int chary = c / 16;
	SDL_Rect source = {x: 25 * charx + 26, y: chary*50 + 28, w:23, h:35};
	SDL_Rect dest = {x: x, y: y, w:16, h:16};
	SDL_BlitSurface(bild, &source, surf, &dest);
}

void schild_zeichnen(int y, string levelnummer, SDL_Surface *schilder, SDL_Surface *schriftbild, SDL_Surface *surf, SDL_Window *win) {

	bool ende = false;
	int taste;
	SDL_Event e;

	while (!ende) {

		SDL_Rect source = { 5, y, 280, 122 };
		SDL_Rect dest = { 290, 197, 280, 122 };
		SDL_BlitSurface(schilder, &source, surf, &dest);
		
		if(levelnummer != " "){
		for (unsigned int i=0; i<levelnummer.size(); i++) {
        	zeichen_schreiben(levelnummer[i], i*BREITE + 350, 240, schriftbild, surf);	
		}
		}
		
		SDL_UpdateWindowSurface(win);

		
	
		if (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_KEYDOWN) {
				taste = e.key.keysym.sym;
				if (taste == SDLK_RETURN) {
					ende = true;
				}
			}
		}
	
	}
	
}

void spielfeld_zeichnen(Spielfeld_Vektor spielfeld1, int spielfeld_positionx, int spielfeld_positiony, SDL_Surface *felder, SDL_Surface *hintergrund, SDL_Surface *surf) {

	SDL_Rect dest;
	SDL_Rect source;
	SDL_BlitSurface(hintergrund, NULL, surf, NULL);
	
	
	// ganzen verschachtelten Vektor ausgeben
	for (int j = 0; j< spielfeld1.size(); j++) {
		for (int i = 0; i< spielfeld1[j].size(); i++) {
			dest = { i * 43 + spielfeld_positionx, j * 43 + spielfeld_positiony, 43, 43 };

			char kachel = spielfeld1[j][i];

			if (kachel == 'F') {
				source = { 162, 535, 43, 43 }; //feld
			}
			else if (kachel == 'B') {			
				source = { 42, 572,  43, 57 }; //blankobaum
			} 
			else if(kachel == 'A'){
				source = { 0, 572, 43, 57 }; //apfelbaum
			}			
			else if (kachel == 'K') {
				source = { 207, 534, 43, 43 }; //kiste
			}
			else if (kachel == 'X') {
				source = { 253, 535, 43, 43 }; //klebeband
			}
			else if (kachel == 'L') {
				source = { 162, 583, 43, 43 }; // Kiste mit X
			}
			SDL_BlitSurface(felder, &source, surf, &dest);
		}
	}
}

void menue_auswaehlen(SDL_Surface *felder, SDL_Surface *surf, SDL_Window *win) {
	
	SDL_Surface *menue = IMG_Load("menue-hg.png");
	int auswahl = 0;
	int kiste_posx = 36;
	int kiste_posy = 172;
	int taste;
	SDL_Event e;

	while (auswahl != 1 && auswahl != 2) {
		SDL_BlitSurface(menue, NULL, surf, NULL);




		if (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_KEYDOWN) {
				taste = e.key.keysym.sym;

				if (taste == SDLK_DOWN) {
					kiste_posy = 302;
				}
				else if (taste == SDLK_UP) {
					kiste_posy = 172;
				}

				if (taste == SDLK_RETURN && kiste_posy == 172) {
					auswahl = 1;
				}
				else if (taste == SDLK_RETURN && kiste_posy == 302) {
					auswahl = 2;
				}
			}
		}

		if (auswahl == 2) {
			exit(0);
		}
		kiste_zeichnen(kiste_posx, kiste_posy, felder, surf);
		
		SDL_UpdateWindowSurface(win);
	}

}

//Bool-Funktion, damit Switch-Case möglich wird.
bool Level_spielen(Spielfeld_Vektor map, const int start_figur_x, const int start_figur_y, const int spielfeld_positionx, const int spielfeld_positiony, string levelnummer, SDL_Surface *hintergrund, SDL_Surface *felder, SDL_Surface *schild, SDL_Surface *schrifttabelle, SDL_Surface *surf, SDL_Window *win) {

	SDL_BlitSurface(hintergrund, NULL, surf, NULL);


	int taste;
	SDL_Event e;

	bool ende = false;
	bool start_figur = true;

	int figur_x = start_figur_x;
	int figur_y = start_figur_y;
	Spielfeld_Vektor Ausgangsposition_Map;
	Ausgangsposition_Map = map;
	int schritte = 0;
	int versuche = 1;
	

	//Anfang While-Schleife Level
	while (!ende) {

		
		int ziel_y = 0;
		int ziel_x = 0;
		

		//Bewegung der Spielfigur
		if (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_KEYDOWN) {
				taste = e.key.keysym.sym;
				if (taste == SDLK_ESCAPE) {
						
					//Mini-Menü, um während des Spiels zum Hauptmenü zurückkehren zu können.
					if(!zum_hauptmenue(felder, schild, schrifttabelle, surf, win)){
					return false;
					}	
				}

				if (taste == SDLK_UP) {

					ziel_y = -1;
					
					if(schieben(figur_y, figur_x, ziel_y, ziel_x, map)){
					
						if(map[figur_y + ziel_y][figur_x + ziel_x] == 'L'){
						map[figur_y + ziel_y][figur_x + ziel_x] = 'X';
						}
						if(map[figur_y + ziel_y][figur_x + ziel_x] == 'K'){
							map[figur_y + ziel_y][figur_x + ziel_x] = 'F';
						}
						
						if(map[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] == 'X'){
						   map[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] = 'L';
						}
						if(map[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] == 'F'){
							map[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] = 'K';
						}
					}

					if (bewegung(figur_y, figur_x, ziel_y, ziel_x, map)) {
						figur_y -= 1;
						schritte++;
					}

				}
				else if (taste == SDLK_DOWN) {

					ziel_y = 1;
					
					if(schieben(figur_y, figur_x, ziel_y, ziel_x, map)){
						
						if(map[figur_y + ziel_y][figur_x + ziel_x] == 'L'){
						map[figur_y + ziel_y][figur_x + ziel_x] = 'X';
						}
						if(map[figur_y + ziel_y][figur_x + ziel_x] == 'K'){
							map[figur_y + ziel_y][figur_x + ziel_x] = 'F';
						}
						
						if(map[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] == 'X'){
						   map[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] = 'L';
						}
						if(map[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] == 'F'){
							map[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] = 'K';
						}
					}

					if (bewegung(figur_y, figur_x, ziel_y, ziel_x, map)) {
						figur_y += 1;
						schritte++;
					}
					
				}
				else if (taste == SDLK_RIGHT) {

					ziel_x = 1;
					
					if(schieben(figur_y, figur_x, ziel_y, ziel_x, map)){
						
						if(map[figur_y + ziel_y][figur_x + ziel_x] == 'L'){
						map[figur_y + ziel_y][figur_x + ziel_x] = 'X';
						}
						if(map[figur_y + ziel_y][figur_x + ziel_x] == 'K'){
							map[figur_y + ziel_y][figur_x + ziel_x] = 'F';
						}
						
						if(map[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] == 'X'){
						   map[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] = 'L';
						}
						if(map[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] == 'F'){
							map[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] = 'K';
						}
					}

					if (bewegung(figur_y, figur_x, ziel_y, ziel_x, map)) {
						figur_x += 1;
						schritte++;
					}

				}
				else if (taste == SDLK_LEFT) {

					ziel_x = -1;
					
					if(schieben(figur_y, figur_x, ziel_y, ziel_x, map)){
						
						if(map[figur_y + ziel_y][figur_x + ziel_x] == 'L'){
						map[figur_y + ziel_y][figur_x + ziel_x] = 'X';
						}
						if(map[figur_y + ziel_y][figur_x + ziel_x] == 'K'){
							map[figur_y + ziel_y][figur_x + ziel_x] = 'F';
						}
						
						if(map[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] == 'X'){
						   map[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] = 'L';
						}
						if(map[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] == 'F'){
							map[figur_y + (ziel_y * 2)][figur_x + (ziel_x * 2)] = 'K';
						}
					}

					if (bewegung(figur_y, figur_x, ziel_y, ziel_x, map)) {
						figur_x -= 1;
						schritte++;
					}
					
				}
				else if (taste == SDLK_SPACE) {
					figur_x = start_figur_x;
					figur_y = start_figur_y;
					map = Ausgangsposition_Map;
					schritte = 0;
					versuche++;
				}
			}

		}

		//Spielfeld zeichnen und aktualisieren
		spielfeld_zeichnen(map, spielfeld_positionx, spielfeld_positiony, felder, hintergrund, surf);

		//Start-Position der Figur
		if (start_figur == true) {

			spielfigur_zeichnen(89, 578, 36, 38, figur_x, figur_y, spielfeld_positionx, spielfeld_positiony, felder, surf);
			if (taste == SDLK_DOWN || taste == SDLK_UP || taste == SDLK_RIGHT || taste == SDLK_LEFT) {
				start_figur = false;
			}
		}

		//Figur guckt in vorgegebene Richtung
		switch (taste) {
		case SDLK_UP: spielfigur_zeichnen(123, 534, 38, 43, figur_x, figur_y, spielfeld_positionx, spielfeld_positiony, felder, surf); break;
		case SDLK_DOWN: spielfigur_zeichnen(85, 534, 38, 43, figur_x, figur_y, spielfeld_positionx, spielfeld_positiony, felder, surf); break;
		case SDLK_RIGHT: spielfigur_zeichnen(0, 534, 43, 38, figur_x, figur_y, spielfeld_positionx, spielfeld_positiony, felder, surf); break;
		case SDLK_LEFT: spielfigur_zeichnen(42, 534, 43, 38, figur_x, figur_y, spielfeld_positionx, spielfeld_positiony, felder, surf); break;
		default: spielfigur_zeichnen(89, 578, 36, 38, figur_x, figur_y, spielfeld_positionx, spielfeld_positiony, felder, surf); break;
		}
		
		//Schritt- und Versuchezähler und Levelnummerierung 
		//If-Befehl, damit im letzten Level keine Schrift angezeigt wird.
		if(levelnummer != "Ende"){
		
		for (unsigned int i=0; i<levelnummer.size(); i++) {
        	zeichen_schreiben(levelnummer[i], i*BREITE + 12, 12, schrifttabelle, surf);	
		}

		string schritte_anzahl;
		stringstream convert;
		convert << schritte;
		schritte_anzahl = convert.str();
		
		string schrittzaehler = "Schritte: " + schritte_anzahl;		
        for (unsigned int i=0; i<schrittzaehler.size(); i++) {
        	zeichen_schreiben(schrittzaehler[i], i*BREITE + 250, 12, schrifttabelle, surf);
		}
		
		string versuche_anzahl;
		stringstream convert1;
		convert1 << versuche;
		versuche_anzahl = convert1.str();
		
		string versuchezaehler = "Versuche: " + versuche_anzahl;		
        for (unsigned int i=0; i<versuchezaehler.size(); i++) {
        	zeichen_schreiben(versuchezaehler[i], i*BREITE + 600, 12, schrifttabelle, surf);
		}
		}
		
		
		if(geschafft(map)){
			schild_zeichnen(GESCHAFFT, " ", schild, schrifttabelle, surf, win);
			return true;
		}
		
		SDL_UpdateWindowSurface(win);

	} //Ende While Level 1
}