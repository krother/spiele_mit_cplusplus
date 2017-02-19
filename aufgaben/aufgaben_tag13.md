
# Tag 13

### Aufgabe 1

Führe das Programm `Text/text.cpp` aus. Erscheint der Text auf dem Bildschirm?

### Aufgabe 2

Was ist der ASCII-Code?

### Aufgabe 3

Schreibe eine Funktion `text_schreiben(str, SDL_Surface*, SDL_Surface*)`, die einen Text auf den Bildschirm schreibt. 

### Aufgabe 4

Plaziere die neue Funktion in einem eigenen Modul mit entsprechender Header-Datei.

### Aufgabe 5

Schreibe eine Klasse `Text` mit folgenden Methoden:

* ein Konstruktor Text(SDL_Surface*, SDL_Surface*)
* eine Methode text_schreiben(string)

### Aufgabe 6

Programmiere eine Laufschrift.

### Aufgabe 7

Führe das Programm `Texture/texture.cpp` aus.

Was für Unterschiede gibt es zwischen Grafik mit Textures und herkömmlichen SDL-Grafiken?

### Aufgabe 8

Betrachte das Beispiel `tiere.cpp`. Wie werden unterschiedliche Objekte in einem Vektor abgelegt?

### Aufgabe 9

Ändere das Raumschiffprogramm (Tag 12) so, daß alle Raumschifftypen in einem Vektor Platz haben.

### Aufgabe 10

Wenn ein Raumschiff mit einem anderen kollidiert, soll es verschwinden.
Verwende die Kollisionsabfrage in SDL:

	SDL_Rect a = {x: 10, y:10, w:10, h:10};
	SDL_Rect b = {x: 20, y:20, w:10, h:10};

    if (SDL_HasIntersection(&a, &b)) {
    	cout << "BOOM" << endl;
    }

### Aufgabe 11

Recherchiere **Stärken** und **Einsatzgebiete** einer anderen