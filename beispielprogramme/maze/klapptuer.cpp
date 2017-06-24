#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include "klapptuer.h"
#include "spielfeld.h"
using namespace std;


Uint32 tuer_auf( Uint32 interval, void *param ) {
  printf("Tür ist auf\n");
  spielfeld[4][4] = '.';
  int *p = NULL;
  SDL_AddTimer( 1000, tuer_zu, p);
  return 0;
}


Uint32 tuer_zu( Uint32 interval, void *param ) {
  printf("Tür ist zu\n");
  spielfeld[4][4] = '#';
  int *p = NULL;
  SDL_AddTimer( 1000, tuer_auf, p);
  return 0;
}


