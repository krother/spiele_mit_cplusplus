#ifndef _kisten_schieben_hpp_
#define _kisten_schieben_hpp_

#include <vector>
#include <cstddef>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <fstream>

using namespace std;

void spielfigur_zeichnen(int, int , int , int , int , int , int , int , SDL_Surface *, SDL_Surface *);
void menue_auswaehlen(SDL_Surface *, SDL_Surface *, SDL_Window *);
void kiste_zeichnen(int, int, SDL_Surface *, SDL_Surface *);


void schild_zeichnen(int, string, SDL_Surface*, SDL_Surface *, SDL_Surface *, SDL_Window *);
const int DURCHGESPIELT = 134;
const int START_LEVEL = 261;
const int GESCHAFFT = 5;
const int BREITE = 22;


const int mitte_x = 258;
const int mitte_y = 75;


using Spielfeld_Vektor = vector<vector<char> >;

bool bewegung(const int, const int, const int, const int, Spielfeld_Vektor);
bool schieben(const int, const int, const int, const int, Spielfeld_Vektor);
bool geschafft(Spielfeld_Vektor);

bool zum_hauptmenue(SDL_Surface *, SDL_Surface *, SDL_Surface *, SDL_Surface *, SDL_Window *);

void spielfeld_zeichnen(Spielfeld_Vektor, const int, const int, SDL_Surface *, SDL_Surface *, SDL_Surface *);
		
bool Level_spielen(Spielfeld_Vektor, const int, const int, const int, const int, string, SDL_Surface *, SDL_Surface *, SDL_Surface *, SDL_Surface *, SDL_Surface *, SDL_Window *);

#endif