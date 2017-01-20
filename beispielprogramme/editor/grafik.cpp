/*
 * grafik.cpp
 *
 *  Created on: 06.01.2017
 *      Author: sahel_dozent_bk7
 */

#include <SDL.h>
#include <SDL_image.h>
#include <grafik.h>

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



