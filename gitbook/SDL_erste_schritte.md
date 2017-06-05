
# Erste Schritte mit SDL

### Ein Fenster erzeugen

Beachte, dass die Deklaration von `main` mit SDL unter Windows anders aussehen muss:

    #include <SDL.h>
    #include <SDL_image.h>

    int main(int a, char **b) {
        SDL_Init(SDL_INIT_VIDEO);
        SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 300, 300, SDL_WINDOW_SHOWN);
        SDL_Delay(2000);
        return 0;
    }


### Ein Bild laden

Um ein Bild namens `fruechte.png` zu laden:

    IMG_Init( IMG_INIT_PNG );    
    SDL_Surface *png = IMG_Load("fruechte.png");
    

### Ein ganzes Bild kopieren

Um das Bild aus dem vorigen Beispiel dann auch darzustellen, reicht eine Zeile:

    SDL_BlitSurface(png, NULL, surf, NULL);

### Einen rechteckigen Bildbereich kopieren

Die Funktion `SDL_BlitSurface` kopiert einen rechteckingen Bereich aus einem Bild in den Bildschirmspeicher. Über die zwei Rechtecke (hier beide als `struct`) können wir den zu kopierenden Ausschnitt festlegen, sowie das Zielrechteck im Bildschirmspeicher.

    SDL_Rect source{x: 0, y: 0, w:400, h:100};
    SDL_Rect destination{x: 50, y: 50, w:200, h:200};
    SDL_BlitSurface(img, &source, surf, &destination);

### Das Fenster aktualisieren

Immer nachdem wir in das Fenster gezeichnet haben, müssen wir das Fenster aktualisieren. Sonst sehen wir nichts: 

    SDL_UpdateWindowSurface(win);

### Zwei Sekunden warten

    SDL_Delay(2000);
