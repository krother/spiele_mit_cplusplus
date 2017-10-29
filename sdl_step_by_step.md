
Ein Minispiel in kleinen Schritten programmieren

## Schritt 1: Ein Fenster erzeugen

Zuerst erzeugen wir ein Grafikfenster mit SDL. Zunächst bereiten wir unsere Programmierumgebung vor. Gehe folgende Schritte durch:

* Erstelle einen neuen Ordner für das Spiel.
* Lege eine neue Datei `fruechte.cpp` an.
* Kopiere den `mingw_dev_libs/`-Ordner aus einem vorigen Projekt in den neuen Ordner.
* Kopiere alle `.dll`-Dateien aus einem vorigen Projekt in den neuen Ordner.
* Kopiere die Datei `build.bat` aus einem vorigen Projekt in den neuen Ordner.
* Editiere `build.bat` und setze `fruechte.cpp` als Name der C-Datei ein.

Nun schreiben wir den SDL-Code für das Fenster. Dazu können wir Code aus einem anderen Programm übernehmen oder neu schreiben. Wichtig ist, daß wir **so wenig wie möglich** schreiben, um die Anzahl möglicher Fehler zu reduzieren.

Das Programm könnte wie folgt aussehen:

    #include <SDL.h>
    #include <SDL_image.h>

    int main(int, char**) {
        SDL_Init(SDL_INIT_VIDEO);

        SDL_Window *win = SDL_CreateWindow("Fruechte", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
        SDL_Surface *surf = SDL_GetWindowSurface(win);

        return 0;
    }

Nun compilieren wir das Programm mit Eclipse.

Es ist noch nichts zu sehen, höchstens ein Fenster das kurz erscheint und wieder verschwindet.

## Schritt 2: Bilder laden

Wir laden als nächstes das Bild für das Spiel in unser Programm.

![Früchte und andere Kacheln](fruit.png)

Füge folgenden Code zum Programm hinzu (in `main` vor dem `return 0`):

    IMG_Init( IMG_INIT_PNG );
    SDL_Surface *fruechte = IMG_Load("fruit.png");

Compiliere das Programm erneut, um sicher zu stellen, daß keine Fehler enthalten sind. 
Du kannst es ausführen, es ist aber immer noch nichts zu sehen.

### Schritt 3: Ein Bild darstellen

Um eines der Bilder auf dem Bildschirm zu zeigen, benötigen wir die Funktion `SDL_BlitSurface`. Füge am Ende des Programms folgenden Code hinzu:

    SDL_BlitSurface(fruechte, NULL, surf, NULL);
    SDL_UpdateWindowSurface(win);

Damit wir auch etwas vom Bild haben, sollte das Programm am Ende etwas warten. Das erreichen wir mit der Zeile:

    SDL_Delay(2000);

Jetzt sehen wir etwas!
