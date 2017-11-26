#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
using namespace std;


SDL_Window* win;
SDL_Surface* surf;
TTF_Font *font;


SDL_Color black = {0, 0, 0};
SDL_Color red = {255, 0, 0};
SDL_Color blue = {0, 0, 255};


void render_text(int x, int y, string text, SDL_Color farbe=black) {
    
    SDL_Surface* tsurf = TTF_RenderText_Solid(font, text.c_str(), farbe);
        
    int breite = tsurf->w;
    int hoehe = tsurf->h;

    SDL_Rect pos = {x, y, breite, hoehe};
    SDL_BlitSurface(tsurf, NULL, surf, &pos);
    SDL_FreeSurface(tsurf);
}


int main(int a, char **b) {
    SDL_Init(SDL_INIT_VIDEO);

    win = SDL_CreateWindow("Hello Text", 100, 100, 600, 400, SDL_WINDOW_SHOWN);
    surf = SDL_GetWindowSurface(win);

    TTF_Init();
    font = TTF_OpenFont("LucidaSansDemiBold.ttf", 36);

    render_text(100, 150, "The quick brown fox", blue);
    render_text(100, 100, "Hello World", red);

    SDL_UpdateWindowSurface(win);
    SDL_Delay(2000);

    return 0;
}
