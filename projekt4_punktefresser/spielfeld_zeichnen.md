
# Spielfeld zeichnen

## Aufgabe 1

Für das Spielfeld brauchen wir eine neue Art von Daten: **verschachtelte Arrays**. Im Programm `schachbrett.cpp` findest Du ein **verschachteltes Array** oder **zweidimensionales Array**.

Ergänze das Programm durch zwei `for`-Schleifen, so daß das gesamte Schachbrett im Textfenster ausgegeben wird.


## Aufgabe 2

Nun kümmern wir uns um das grafische Spielfeld. Wir werden das Spielfeld in einem zweidimensionalen Array ablegen. 
Verknüpfe das verschachtelte Array aus dem vorigen Programm mit der Grafikbibliothek SDL, so daß das *"Schachbrett"* mit Kachel-Grafik in einem Grafikfenster gezeichnet wird.

Der Einfachheit halber stellen wir jedes Spielelement als ein Zeichen dar. Hier verwenden wir folgende Legende:

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

## Aufgabe 3

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


## Aufgabe 4

Wenn das Spielfeld zu sehen ist, können wir uns um die Position der Spielfigur kümmern.

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


## Aufgabe 5

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


## Aufgabe 6

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
