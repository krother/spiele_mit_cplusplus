
# Fenster mit SDL erzeugen

Um *irgend etwas* mit SDL zu tun, musst Du auf jeden Fall ein Fenster erzeugen.

Das folgende Codebeispiel zeigt ein minimales SDL-Programm. Es öffnet ein Fenster und schließt es wieder:

    #include <SDL.h>

    int main(int a, char **b) {
        SDL_Init(SDL_INIT_VIDEO);
        SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 300, 300, SDL_WINDOW_SHOWN);
        SDL_Delay(2000);
        return 0;
    }


Die Parameter von `main` sind etwas anders als sonst (manchmal funktioniert einfach nur `main()`).

Die Parameter der Funktion `SDL_CreateWindow` sind: *Fenstertitel, Fensterposition x und y, Fenstergröße x und y*
