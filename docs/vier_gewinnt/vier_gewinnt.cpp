/*
 * 4Gewinnt.cpp
 *
 *  Created on: 10.04.2017
 *      Author: Nikola & Natalja
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

// spielfeld_zeichnen
void spielfeld_zeichnen(int spalte, SDL_Surface *png, SDL_Surface *surf) {
	  SDL_Rect source = {x: 0, y: 64, w: 32, h: 32};
	  SDL_Rect destination = {x: spalte, y: 0, w: 32, h: 32};
	  SDL_BlitSurface(png, &source, surf, &destination);
	  }

//  stein_zeichnen

// x - Spalte  0 .. 6
// y - Reihe   0 .. 5

// 1. Variablen Definition & Source (Aussehen) der Steine wird definiert --> 2 verschiedene

void stein_zeichnen (int x, int y, char stein, SDL_Surface *stone, SDL_Surface *surf) {


SDL_Rect source;

switch (stein) {
    case 'X': source = {x: 0, y: 0, w:44, h:44}; break; //Feuer Spielstein
    case 'O': source = {x: 0, y: 44, w:44, h:44}; break; //Blitz Spielstein
    }

// 2. Dest (Ort im Spielfeld) der Steine wird übersetzt --> x = Spalte, y = Zeile

        SDL_Rect dest;

// x-Wert (Spalte 0-6) wird in Ort im Bild (Pixel) übersetzt, Rückgabewert aus tastatureingabe {0...6}

        dest.x = 0;
        // KR: hier ginge auch statt switch:
        // rect_dest = x * 44;
        switch (x) {
            case 0: dest.x = 0; break;
            case 1: dest.x = 44; break;
            case 2: dest.x = 88; break;
            case 3: dest.x = 132; break;
            case 4: dest.x = 176; break;
            case 5: dest.x = 220; break;
            case 6: dest.x = 264; break;
        }

// y-Wert (Zeile 0-5) wird in Ort im Bild (Pixel) übersetzt, Rückgabewert aus zeile_ermitteln {0...5}

        dest.y = y;
        switch (y) {
            case 0: dest.y = 0; break;
            case 1: dest.y = 44; break;
            case 2: dest.y = 88; break;
            case 3: dest.y = 132; break;
            case 4: dest.y = 176; break;
            case 5: dest.y = 220; break;
        }
        dest.y += 19;

        dest.h = 44;
        dest.w = 44;


        SDL_BlitSurface(stone, &source, surf, &dest);

}

// zeile_ermitteln
int zeile_ermitteln(const char spielfeld[6][7], int spalte)
{
  for(int i = 5; i >= 0; i--)
  {
    if(spielfeld[i][spalte] == ' ')
    return i;
  }
  return -1;
}

// spalte_voll
bool spalte_voll(const char spielfeld[6][7], int spalte)
{
    if(spielfeld[0][spalte] != ' ')
      return true;
    else
      return false;
}

 // tastatureingabe
int tastatureingabe(const char spielfeld[6][7])
{
  bool voll = true;
  int spalte;
  do
  {
    do
    {
      printf("Bitte waehlen Sie eine Spalte von 1 bis 7.\n");
      std::cin >> spalte;
    } while(spalte > 7 || spalte < 1);

    if(spalte_voll(spielfeld, spalte-1))
        printf("Diese Spalte ist voll.\n");
    else
        voll = false;
    } while(voll);

  return spalte-1;
}

// spielfeld_check
bool spielfeld_check(int x, int y, char spielfeld [6][7]) {
  // x - Spalte  0 .. 6
  // y - Reihe   0 .. 5
 int iy;
 int ix;
 int i;
// welcher Stein wurde grade eingeworfen
    char stein = spielfeld[y][x];

// 1. pruefen ob Reihe 4 gleiche enthaelt [HORIZONTAL]
    int horizontal = 1;

    // Suche vom Ausgangspunkt nach rechts
    i = x + 1; // i ist die zu pruefende Spalte
    while (i <= 6) {
        if (spielfeld[y][i] == stein) {
            horizontal++;
            i++;
        }
        else break; // nichts mehr gefunden - beenden
    }

     // Suche vom Ausgangspunkt nach links
    i = x - 1; // i ist die zu pruefende Spalte
    while (i >= 0) {
        if (spielfeld[y][i] == stein) {
            horizontal++;
            i--;
        }
        else break; // nichts mehr gefunden - beenden
    }
cout << "hori: " << horizontal << endl;
if(horizontal >= 4)return true;

// 2. pruefen ob Spalte 4 gleiche enthaelt [VERTIKAL]
    int vertical = 1;

    // Suche vom Ausgangspunkt nach oben
    i = y + 1; // i ist die zu pruefende Reihe
    while (i <= 5) {
        if (spielfeld[i][x] == stein) {
            vertical++;
            i++;
        }
        else break; // nichts mehr gefunden - beenden
    }

    // Suche vom Ausgangspunkt nach unten
    i = y - 1; // i ist die zu pruefende Reihe
    while (i >= 0) {
        if (spielfeld[i][x] == stein) {
            vertical++;
            i--;
        }
        else break; // nichts mehr gefunden - beenden
    }
    cout << "vert: " << vertical << endl;
   if(vertical >= 4)return true;

// 3. pruefen ob diagonal1 (\) 4 gleiche enthaelt [DIAGONAL1]
    int diagonal1 = 1;


   // Suche vom Ausgangspunkt nach diagonal1 nach oben : (\)
    iy = y + 1; // iy ist die zu pruefende Reihe
    ix = x -1 ; // ix ist die zu pruefende Spalte
    while (iy <= 5 && ix >=0) {
        if (spielfeld[iy][ix] == stein) {
            diagonal1++;
            ix--;
            iy++;
        }
        else break; // nichts mehr gefunden - beenden
    }


    // Suche vom Ausgangspunkt nach diagonal1 nach unten : (\)
    iy = y - 1; // iy ist die zu pruefende Reihe
    ix = x + 1 ; // ix ist die zu pruefende Spalte
    while (iy >= 0 && ix <= 6) {
        if (spielfeld[iy][ix] == stein) {
            diagonal1++;
            ix++;
            iy--;
        }
        else break; // nichts mehr gefunden - beenden
    }
if(diagonal1 >= 4)return true;

// 4. pruefen ob diagonal2 (/) 4 gleiche enthaelt [DIAGONAL2]
    int diagonal2 = 1;

  // Suche vom Ausgangspunkt nach diagonal2 nach oben : (/)
    iy = y + 1; // iy ist die zu pruefende Reihe
    ix = x + 1 ; // ix ist die zu pruefende Spalte
    while (iy <= 5 && ix <= 6) {
        if (spielfeld[iy][ix] == stein) {
            diagonal2++;
            ix++;
            iy++;
        }
        else break; // nichts mehr gefunden - beenden
    }


    // Suche vom Ausgangspunkt nach diagonal2 nach unten : (/)
    iy = y - 1; // iy ist die zu pruefende Reihe
    ix = x - 1 ; // ix ist die zu pruefende Spalte
    while (iy >= 0 && ix >= 0) {
        if (spielfeld[iy][ix] == stein) {
            diagonal2++;
            ix--;
            iy--;
        }
        else break; // nichts mehr gefunden - beenden
    }
    if(diagonal2 >= 4)return true;
    return false;
}

// stein_setzen
bool stein_setzen(int counter, char spielfeld [6][7], SDL_Surface *stone, SDL_Surface *surf) {

char stein; // Ort des geworfenen Steins: Zusammensetzung aus x & y

// 1. int_tastatureingabe aufrufen -> Spaltennr = int x

    // int tastatureingabe(spielfeld)--> return x (Spalte: 0-6)
    int x = tastatureingabe(spielfeld); // Spaltennr des neuen Steins


// 2. int_zeile_ermitteln aufrufen -> Zeilennr = int y

    // int zeile_ermitteln(spielfeld, x) --> return y (Zeile: 0-5)
    int y = zeile_ermitteln(spielfeld, x); // Zeilennr des neuen Steins


// 3. Modulo von Counter gebildet

    if (counter %2 != 0) { // Stein von Spieler1 (Feuer, ungerade Spielzüge) = X
        stein = 'X';
    }
    else if (counter %2 == 0) { // Stein von Spieler2 (Blitz, gerade Spielzüge) = O
        stein = 'O';
    }

// 4. Stein wird intern auf Spielfeld gespeichert

    spielfeld[y][x] = stein; // gesetzter Stein intern speichern

// 5. Anzeigen der Bilder mit BlitSurface o.ä.
    stein_zeichnen(x, y, stein, stone, surf);

// 6. bool spielfeld_check aufrufen --> geht Spiel noch weiter?

    bool gewonnen = spielfeld_check(x, y, spielfeld);

    return gewonnen; // gewonnen == 'true' oder 'false' als rückgabewert
}

// play
void play(SDL_Surface *spielfeld, SDL_Surface *stone, SDL_Surface *surf, SDL_Window *win)
{
  SDL_Event e;
  SDL_BlitSurface(spielfeld, NULL, surf, NULL);

  //SDL_Flip(surf);

  const int reihen = 6;
  const int spalten = 7;
  char feld[reihen][spalten];
  for(int reihe = 0; reihe < reihen; reihe++)
  {
    for(int spalte = 0; spalte < spalten; spalte++)
    {
      feld[reihe][spalte] = ' ';
    }
  }

  int counter = 1;
  bool gewonnen = false;

  while(counter < 43)
  {
    gewonnen = stein_setzen(counter, feld, stone, surf);
    //SDL_Flip(surf);
    SDL_PollEvent( &e );
    SDL_UpdateWindowSurface(win);
    counter++;
    if(gewonnen)
    {
      std::cout << "Gratuliere, Du hast gewonnen!" << std::endl;
      return;
    }
  }
  std::cout << "Unentschieden!" << std::endl;
}

// main
int main(int args, char *argv[]) {
  // Spielregeln von 4-Gewinnt werden erklaert
    printf("******************************\n"
           "Willkommen zum 4-Gewinnt Spiel!\n"
           "******************************\n"
           "Bevor der Spass beginnt solst Du hier noch eine kurze Spielanleitung bekommen.\n"
           "Dein Konkurrent und Du werfen abwechselnd eure Steine auf das Spielfeld,\n"
           "welches man sich senkrecht stehend vorstellen muss. Ein Stein kann nur auf\n"
           "den Boden (erster in Spalte) oder auf einen anderen Stein gelegt werden.\n"
           "Wer als erster 4 seiner Steine waagerecht, senkrecht oder diagonal verbinden kann,\n"
           "hat gewonnen.\n");

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *win = SDL_CreateWindow("4Gewinnt", 100, 100, 310, 280, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);
    SDL_Surface *spielfeld = IMG_Load("spielfeld.png");
    SDL_Surface *stone = IMG_Load("stone.png");

    IMG_Init( IMG_INIT_PNG );

    play(spielfeld, stone, surf, win);

    SDL_FreeSurface(spielfeld);
    SDL_FreeSurface(stone);
    SDL_Quit();

    return 0;
}




