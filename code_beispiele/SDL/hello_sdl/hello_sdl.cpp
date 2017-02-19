#include <iostream>
#include <SDL.h>


int main(int, char**){
	//First we need to start up SDL, and make sure it went ok
	std::cout << SDL_INIT_TIMER;
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

    if (win == 0) {
      std::cout << "window failed";	
      return 1;
    }

	SDL_Surface *bmp = SDL_LoadBMP("maze_run.bmp");
    if (bmp == NULL){
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        return 1;
    }
	SDL_Surface *surface_window = SDL_GetWindowSurface(win);
    SDL_BlitSurface(bmp, NULL, surface_window, NULL);

    SDL_UpdateWindowSurface(win);
	SDL_Delay(2000);
	
	SDL_DestroyWindow(win);
	SDL_Quit();
	
	return 0;
}
