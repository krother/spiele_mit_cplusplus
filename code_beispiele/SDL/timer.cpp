#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
using namespace std;

int zaehler = 0;

Uint32 callback( Uint32 interval, void *param ) {
  //Print callback message 
  zaehler++;
  printf( "Aufruf Nr. %i\n", zaehler); 
  int *p = NULL;
  SDL_AddTimer( 100, callback, p);
  return 0;
}


int main(int, char **) {
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

  int *p = NULL;
  SDL_TimerID timerID = SDL_AddTimer( 2000, callback, p);

  printf("Timer gestartet: %i\n", timerID);
  SDL_Delay(5000);
}

