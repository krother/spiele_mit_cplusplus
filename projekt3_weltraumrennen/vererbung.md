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
