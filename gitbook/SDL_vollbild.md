
# Vollbildmodus unter SDL

Programme unter SDL im Vollbildmodus zu schreiben ist problematisch. 
Ein Grund ist, daß die Fenster unter verschiedenen Betriebssystemen sehr unterschiedlich funktionieren.

Es gibt mehrere Ansätze, mit denen man sich behelfen kann:

## Rahmen abschalten

Für ein gegebenes SDL-Fenster `win` kann man den Rahmen abschalten. Die Methode funktioniert leicht und zuverlässig:

    SDL_SetWindowBordered( win, SDL_FALSE );


## Fenster maximieren

Es gibt eine Funktion, die ein SDL-Fenster vergrößert. Funktioniert aber nicht unter Linux:

    SDL_MaximizeWindow(win);


## Fenstergröße ermitteln und anpassen

Es wird aus einem Fenster die Größe des Displays ermittelt und ein neues, maximal großes Fenster erzeugt:

    SDL_Rect curBounds;
    SDL_GetWindowPosition( win, &curBounds.x, &curBounds.y );
    SDL_GetWindowSize( win, &curBounds.w, &curBounds.h );

    int idx = SDL_GetWindowDisplayIndex( win );
    SDL_Rect bounds;
    SDL_GetDisplayBounds( idx, &bounds );
    
    win = SDL_CreateWindow("Fruechte", bounds.x, bounds.y, bounds.w, bounds.h, SDL_WINDOW_SHOWN);    
    SDL_SetWindowBordered( win, SDL_FALSE );
    SDL_Surface *surf = SDL_GetWindowSurface(win);

Das kommt einem Vollbildmodus zumindest schon recht nahe.


## Echter Vollbildmodus

Die Zeile, um den Vollbildmodus zu aktivieren ist:

    SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN);

auch

    SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN_DESKTOP);

Unter Linux funktioniert diese Zeile jedoch definitiv gar nicht. Eine Diskussion zum Thema findet sich unter [http://stackoverflow.com/questions/19431170/fullscreen-modes-in-ubuntu-sdl-opengl](http://stackoverflow.com/questions/19431170/fullscreen-modes-in-ubuntu-sdl-opengl).

