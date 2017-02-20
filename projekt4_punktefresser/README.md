
# Früchte Sammeln

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

Nun compilieren wir das Programm:

* Öffne die Kommandozeile mit `cmd`
* Wechsle auf das Laufwerk `d:`
* Wechsle mit Hilfe von `cd` und `dir` in das Verzeichnis mit Deinem Programm. 
* Führe `build.bat` aus.
* Stelle sicher, daß das Programm ohne Fehler compiliert.

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


### Schritt 4: Eine Kachel zeichnen

Um statt dem gesamten Bild nur einen Ausschnitt zu zeichnen, müssen wir zwei Rechtecke definieren -- eines für den zu kopierenden Bereich, eines für den Zielbereich. Zunächst *deklarieren* wir zwei Variablen, die wir dafür verwenden möchten. Füge zum Programm hinzu:

    SDL_Rect source;
    SDL_Rect dest;

Diese Rechtecke füllen wir nun mit den x/y-Koordinaten sowie Breite und Höhe. Zum Beispiel könnten wir eine Banane in die linke obere Ecke des Bildschirms zeichnen:

    source = {x: 0, y: 64, w:32, h:32};
    dest = {x: 0, y: 0, w:32, h:32};

Ersetze den Aufruf von `SDL_BlitSurface` durch:

    SDL_BlitSurface(fruechte, &source, surf, &dest);

Achte darauf, daß Du den Aufruf von `SDL_UpdateWindowSurface` nicht löschst.

Compiliere das Programm erneut, um sicher zu stellen, daß keine Fehler enthalten sind. 


### Schritt 5: Spielfeld anlegen

Nun kümmern wir uns um das Spielfeld. Wir werden das Spielfeld in einem zweidimensionalen Array ablegen. Der Einfachheit halber stellen wir jedes Spielelement als ein Zeichen dar. Hier verwenden wir folgende Legende:

| Zeichen | Bedeutung |
|---------|-----------|
| #       | Wand      |
| _       | Boden     |
| b       | Banane    |
| *       | Ausgang |

Der Programmcode für das Array sieht folendermaßen aus:

	char spielfeld[8][8] = {
		{'#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', 'b', '_', '_', '_', '_', 'b', '#'},
		{'#', '_', '#', '#', '_', '#', '_', '#'},
		{'#', '_', '_', '_', '_', '#', '_', '#'},
		{'#', '_', '#', '_', '_', '_', '_', '#'},
		{'#', '_', '#', '_', '#', '#', '_', '#'},
		{'#', 'b', '_', '_', '_', '_', 'b', '#'},
		{'#', '#', '#', '#', '*', '#', '#', '#'}
	};

Füge den Programmcode ein und compiliere das Programm erneut. Es ist immer keine Veränderung zu sehen.

### Schritt 6: Das Spielfeld zeichnen

Nun müssen wir das Spielfeld zeichnen. Dazu brauchen wir eine doppelte `for`-Schleife, da wir jede Zeile und darin jede Spalte durchlaufen müssen. *Innerhalb* der Schleife rufen wir wie zuvor `SDL_BlitSurface` auf.

Zunächst zeichnen wir einfach nur 8x8 Bananen. Dazu müssen wir die Zielposition in `dest`verändern. Füge folgenden Code **vor** `SDL_UpdateWindowSurface` hinzu:

    for(int x=0; x<8; x++) {
        for(int y=0; y<8; y++) {
            source = {x: 0, y: 64, w:32, h:32};
            dest = {x: x*32, y: y*32, w:32, h:32};
            SDL_BlitSurface(fruechte, &source, surf, &dest);
        }
    }

Compiliere das Programm und führe es aus. Wir sollten eine Bananenlandschaft sehen.

Nun müssen wir wiederum *innerhalb der Schleife* entscheiden, welche Kachel in `source`dargestellt werden soll. Dazu schauen wir, welches Symbol an der Stelle x/y im Spielfeld steht. Füge folgende Zeile zur Schleife hinzu:

    char kachel = spielfeld[y][x];

Je nachdem welchen Wert `kachel` hat, müssen wir die Werte im Rechteck `source` unterschiedlich setzen. Füge hinzu:

    if (kachel == '#') {
        source = {x: 0, y: 0, w:32, h:32};
    }
    else if (kachel == '_') {
        source = {x: 0, y: 32, w:32, h:32};
    }

Erweitere diese Folge durch Code für die anderen Kacheln.

**Stelle sicher, daß der Aufruf von `SDL_BlitSurface` nach der `if..else` Konstruktion erfolgt.

Compiliere das Programm und stelle sicher daß es funktioniert.


### Schritt 7: Position der Spielfigur

Lege am Anfang des Programms die Position der Spielfigur in einer eigenen Variable fest:

    int figur_x = 3;
    int figur_y = 3;

Füge Anweisungen zum Zeichnen der Spielfigur hinzu:

* die Spielfigur muß **nach** dem Spielfeld gezeichnet werden
* die Spielfigur muß **vor** dem Aufruf von `SDL_UpdateWindowSurface` gezeichnet werden
* Du mußt die Rechtecke `source` und `dest` mit Werten belegen
* Du mußt auch `SDL_BlitSurface` aufrufen.
* Verwende `figur_x * 32` und `figur_y * 32`, um die Position der Figur auf dem Bildschirm in `dest` zu berechnen.

Compiliere das Programm und stelle sicher daß eine Spielfigur zu sehen ist.


### Schritt 8: Tastatureingabe

Wir möchten nun, daß sich die Figur bewegt. Dazu müssen wir Ereignisse von der Tastatur abfragen.

Da das Programm nicht weiß wann es aufhören soll, müssen wir eine Abbruchbedingung angeben. Dazu verwenden wir eine `while`-Schleife, die beendet wird, sobald eine Taste gedrückt wird.

Ändere das Programm, indem Du folgenden Code hinzufügst. Ersetze die Kommentare durch die entsprechenden Codesegmente:

    // bis hier ist das Laden der Grafik
    // und das Spielfeld-Array
    // und die Startposition der Spielfigur

    SDL_Event e;
    bool ende = false;

    while (!ende) {

      if ( SDL_PollEvent( &e ) != 0 ) { 
        if( e.type == SDL_KEYDOWN ) { 

        	ende = true;

        }

        // hier kommt die Doppelschleife zum Zeichnen des Spielfelds hin
        // und das Zeichnen der Spielfigur
      }
    }

    // hier kommt nur noch das return 0

Compiliere das Programm und führe es aus.


### Schritt 9: Pfeiltasten abfragen

Mit den Events in SDL können wir einzelne Tasten unterscheiden. Jede Taste hat eine Zahl, z.B. die Leertaste ist Nr. 32. Für die Pfeiltasten gibt es Abkürzungen, z.B. `SDLK_UP`. Wir werden nun das Programm so verändern, daß sich bei den Pfeilen die Position der Spielfigur ändert, und die Leertaste das Spiel beendet. 

Schreibe:

    ..
    if( e.type == SDL_KEYDOWN ) { 
        int taste = e.key.keysym.sym;
        if (taste == 32) {
        	ende = true;
        }
        else if (taste == SDLK_UP) {
            figur_y -= 1;
        }
        ..

Füge die anderen Richtungen hinzu. Compiliere das Programm und stelle sicher daß es funktioniert.

### Schritt 10: An Wänden stoppen

Prüfe jeweils vor der Bewegung, ob an der neuen Position eine Wand auf dem Spielfeld liegt. Falls ja, führe keine Bewegung aus.

### Schritt 11: Funktion zum Zeichnen einer Kachel

Lagere das Zeichnen der Kachel in eine Funktion aus (Beispiel vom Dozenten). 

Das Programm soll dadurch übersichtlicher werden.

## Extraaufgaben

### A) Schwarzer Hintergrund

Verwende die Datei `background.png` aus dem Weltraumspiel, um einen schwarzen Hintergrund zu zeichnen. An welcher Stelle im Programm muß der entsprechende Aufruf von `SDL_BlitSurface` erfolgen?

### B) Switch

Die Folge von mehreren `if.. else` Konstruktionen ist nicht besonders elegant. Die `switch`-Anweisung stellt eine Alternative dazu dar.

* Schaue Dir das Beispiel im Ordner `Switch` an.
* Compiliere das Programm und führe es aus.
* Ersetze die `if.. else` Konstruktion im Früchtespiel durch eine `switch-Anweisung
* Compiliere das Programm und führe es aus.


### C) Text

Gib die Anzahl gefressener Früchte auf dem Bildschirm aus.

* Betrachte die Beispiele im Ordner `TextSchreiben`
* Lade die Bibliothek **SDL2_ttf** für MinGW herunter
* Entpacke sie. 
* Kopiere die `.dll`-Dateien in Dein Programmverzeichnis.
* Kopiere die Dateien aus dem **include**-Verzeichnis nach `mingw_dev_libs/include`
* Compiliere das Programm und führe es aus.

### D) Blickrichtung

Speichere die Blickrichtung der Spielfigur in einer Variable (z.B. 1 für oben, 2 für unten use.). Ändere diese Variable, sobald der Spieler eine Pfeiltaste drückt. Zeige unterschiedliche Kacheln für die Spielfigur je nach Blickrichtung an.

### E) Header

Lagere das Spielfeld in eine eigene Datei `spielfeld.h` aus.

* Betrachte das Beispiel im Ordner `Header`.
* Compiliere das Programm und führe es aus. **Du mußt das Verzeichnis mit den Header-Dateien unter der Option `-I` im Skript `build.bat` aufführen.**
* Verschiebe die Definition des Spielfelds in eine neue Datei `spielfeld.h`
* Binde diese Datei mit `#include <spielfeld.h>` in Dein Programm ein.
* Compiliere das Programm und führe es aus.


# C++ - Tag 2

## Tagesziel

Ein Level für ein Spiel mit kachelbasierter Grafik auf dem Bildschirm darstellen.

![ein kachelbasiertes Spiel](06_projektskizze/bilder/fruit.png)
