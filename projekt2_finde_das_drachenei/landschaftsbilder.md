
# Landschaftsbilder

Abgesehen von einigen Textadventures aus den 80'er-Jahren sollte ein Adventure stimmungsvolle Bilder bieten. In dieser Aufgabe werden wir zu jedem Raum eine Grafik anzeigen. Dazu verwenden wir die Bibliothek SDL.

Zum Glück müssen wir die Bilder nicht selbst zeichnen, zum Projekt gehört eine Menge frei verwendbares Bildmaterial von [www.opengameart.org](https://opengameart.org).

## Anforderungen

* Die Navigation funktioniert wie im textbasierten Programm.
* Zu jedem Raum wird ein Bild angezeigt.
* verwende die mitgelieferten Landschaftsbilder

## Beispielausgabe

![](bilder/turm.png)

## Infomaterialien

* Codebeispiele SDL


## Schritt für Schritt

### Schritt 1: Ein bestehendes Programm umbauen

Verwende das fertige Projekt aus der ersten Aufgabe **"Von Raum zu Raum"**. Stelle sicher, dass das Programm funktioniert. 


### Schritt 2: SDL installieren

Installiere SDL entsprechend der Anleitung in diesem Skript.

Installiere auch die Erweiterung **SDL_image** entsprechend der **[Anleitung von Lazy Foo](http://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/index.php)**

Füge ganz oben im Programm folgende zwei `include`-Befehle hinzu:

    #include <SDL.h>
    #include <SDL_image.h>

SDL verwendet eine leicht unterschiedliche `main`-Funktion. Ändere die Kopfzeile auf:

    int main(int a, char **b) {
    	...

**Compiliere das Programm erneut und stelle sicher, dass es funktioniert.**


### Schritt 3: Ein Fenster erzeugen

Zuerst erzeugen wir ganz am Anfang von `main` ein Fenster mit den Befehlen:

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init( IMG_INIT_PNG );
    SDL_Window *win = SDL_CreateWindow("Drachenei!", 100, 100, 640, 400, SDL_WINDOW_SHOWN);
    SDL_Surface* surf = SDL_GetWindowSurface(win);

**Compiliere das Programm erneut und stelle sicher, dass es funktioniert.**

**Anmerkungen:**

* Es ist normal, dass das Fenster nach einigen Sekunden grau wird.
* Es kann sein, dass es bei disem Schritt zu Fehlern kommt, falls SDL nicht korrekt installiert ist. 


### Schritt 4: Bilder laden

Nun kannst Du die Bilder laden. Leider sagt uns SDL nicht selbst, ob das Laden eines Bildes geklappt hat. Damit das Programm nicht sehr mühselig zu debuggen ist, müssen wir das selbst herausbekommen. Schreibe Dir dazu eine Funktion `bild_laden` **nach** den includes, aber **vor** der `main`:

    SDL_Surface *bild_laden(const char *dateiname) {
        SDL_Surface *bild = IMG_Load(dateiname);
        if (bild == NULL) {
            cout << "Laden von " << dateiname << " fehlgeschlagen!" << endl;
        }
        return bild;
    }

Diese Funktion versucht, ein Bild zu laden. Wenn das schief geht, enthält `bild` den Wert `NULL`.

Nun müssen wir diese Funktion noch im Hauptprogramm verwenden. Schreibe nach dem Erstellen des Fensters in die `main`:

    SDL_Surface *drachenei = bild_laden("drachenei.png")

Kopiere das Drachenei-Bild in das Projektverzeichnis (im Windows-Explorer).

**Compiliere das Programm erneut und stelle sicher, dass das Bild geladen wird (Du siehst es noch nicht).**


### Schritt 5: Ein Bild anzeigen

Um das Bild auch zu sehen, müssen wir es zuerst auf die Fensteroberfläche kopieren. Schreibe vor der `while`-Schleife ins Programm:

    SDL_BlitSurface(drachenei, NULL, surf, NULL);

Anschließend müssen wir dem Fenster sagen, dass es sich selbst aktualisieren soll:

    SDL_UpdateWindowSurface(win);

**Compiliere das Programm erneut und stelle sicher, dass es funktioniert. Nun solltest Du endlich ein Bild sehen!**


### Schritt 6: Mehr Bilder

Du kannst jetzt selbst versuchen, auch die anderen Bilder zu laden und je nach dem Wert von `position` unterschiedliche Bilder anzeigen. Du kannst dazu mehrere `if`-Anweisungen verwenden:

    if (position == 3) {
        SDL_BlitSurface(drachenei, NULL, surf, NULL);
    }
    ...

Eleganter ist ein Array, das Zeiger auf alle Bilder enthält:

    SDL_Surface *bilder[4] = {wueste, berge, sump, drachenei};

Auf jeden Fall ist das Ergebnis noch nicht so toll, weil das Fenster nach einer Weile immer grau wird. Dies liegt daran, dass wir die **Events** (Mausbewegungen, Tastaturklicks usw.) in diesem Fenster nicht abarbeiten. Darum kümmern wir uns im nächsten Abschnitt.


## Für Fortgeschrittene

Lagere das Initialisieren der Grafik (Fenster öffnen, Bilder laden, zeichnen) in eine eigene Klasse aus. 

Informiere Dich, was das Entwurfsmuster **Singleton** ist (auf [www.sourcemaking.com](www.sourcemaking.com)). Diskutiere, ob das Muster hier sinnvoll einsetzbar ist oder was für Alternativen in Betracht kommen.
