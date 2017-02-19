
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;



int main(int, char**) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);
    SDL_Surface *hintergrund = IMG_Load("background.png");
	IMG_Init( IMG_INIT_PNG );
	SDL_Surface *f = IMG_Load("fruit.png");

	int taste;
	bool ende = false;
	SDL_Rect frucht;
	SDL_Rect ziel;

	while(ende == false){
		SDL_Event e;
		if (SDL_PollEvent(&e) != 0) {
			if(e.type == SDL_KEYDOWN){
				taste = e.key.keysym.sym;
				ende = true;
			}
			else if (e.type == SDL_MOUSEMOTION) {
				printf("%i %i\r\n", e.motion.x, e.motion.y);
				SDL_BlitSurface(hintergrund, NULL, surf, NULL);
				frucht = {x:0, y:32, w:32, h:32};
				ziel = {x:e.motion.x, y:e.motion.y, w:32, h:32};
				SDL_BlitSurface(f, &frucht, surf, &ziel);
				SDL_UpdateWindowSurface(win);
			}
		}
	}
	return 0;
}
