/*
 * grafik.h
 *
 *  Created on: 06.01.2017
 *      Author: sahel_dozent_bk7
 */

#ifndef GRAFIK_H_
#define GRAFIK_H_

#include <SDL.h>
#include <SDL_image.h>

void kachel_zeichnen(int x, int y, char kachel, SDL_Surface *fruechte, SDL_Surface *surf);

void spielfigur_zeichnen(int x, int y, SDL_Surface *fruechte, SDL_Surface *surf);


#endif /* GRAFIK_H_ */
