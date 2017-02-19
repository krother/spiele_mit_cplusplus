#include <SDL.h>
#include <SDL_image.h>

int main() {
	
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 300, 300, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);

    IMG_Init( IMG_INIT_PNG );    
    SDL_Surface *png = IMG_Load("tiles.png");
    
    SDL_BlitSurface(png, NULL, surf, NULL);
    SDL_UpdateWindowSurface(win);

    SDL_Delay(2000);
}
