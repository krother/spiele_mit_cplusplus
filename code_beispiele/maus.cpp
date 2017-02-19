#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>


int main(int argc, char *argv[])
{
    SDL_Event event;

    /* Initialize the SDL library (starts the event loop) */
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        fprintf(stderr,
                "Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    /* Clean up on exit, exit on window close and interrupt */
    atexit(SDL_Quit);

    /* Ignore key events */
    SDL_EventState(SDL_KEYDOWN, SDL_IGNORE);
    SDL_EventState(SDL_KEYUP, SDL_IGNORE);

    /* The mouse isn't much use unless we have a display for reference */
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

    /* Loop waiting for ESC+Mouse_Button */
    while ( SDL_WaitEvent(&event) >= 0 ) {
        switch (event.type) {
            case SDL_MOUSEMOTION: {
                printf("Mouse moved to (%d,%d)\n",
                    event.motion.x, event.motion.y);
            }
            break;
                    
            case SDL_MOUSEBUTTONDOWN: {
                printf("Mouse button pressed\n");
            }
            break;

            case SDL_QUIT: {
                printf("Quit requested, quitting.\n");
                exit(0);
            }
            break;
        }
    }
    /* This should never happen */
    printf("SDL_WaitEvent error: %s\n", SDL_GetError());
    exit(1);
}
