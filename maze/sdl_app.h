#ifndef __sdl_app__
#define __sdl_app__

#include "kachel.h"


class SDL_App {
private: SDL_Surface *kacheln;
  public: SDL_Window *win;
          SDL_Surface *surf;

  public: void blit(Kachel, int, int);
          void kacheln_laden();
          void destroy();
          SDL_App(short, short, short, short);

};

#endif
