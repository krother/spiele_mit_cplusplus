#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
using namespace std;

void drawText(SDL_Surface* screen, char *message) {
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("LucidaSansDemiBold.ttf", 40);
	SDL_Color White = {255, 255, 255};
	SDL_Surface* surf = TTF_RenderText_Solid(font, message, White);
	SDL_BlitSurface(surf, NULL, screen, NULL);
	TTF_CloseFont(font);
}


int main() {
    SDL_Init(SDL_INIT_VIDEO|IMG_INIT_PNG);
    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 600, 300, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);

    char *text = 'Hallo SDL';
    drawText(surf, text);

    SDL_UpdateWindowSurface(win);
    SDL_Delay(2000);
	return 0;
}
