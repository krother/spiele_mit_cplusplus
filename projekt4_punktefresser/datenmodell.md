
# Ein Datenmodell erstellen

Überlegt, welche **Klassen** und andere **Datenstrukturen** Ihr für das Spiel benötigt.

Zeichnet ein **Datenmodell**, das alle **Klassen** und deren **Attribute** mit den jeweiligen Datentypen enthält.

#### Beispiel für eine Klasse:

| **Spielfigur** |
|----------------|
| x: int         |
| y: int         |
| bild: SDL_Surface* |
| punkte_gefressen: int |

Spannend wird es, wenn Ihr Abhängigkeiten zwischen zwei Klassen habt, z.B. *"eine Spielfigur enthält bis zu drei Objekte der Klasse 'Gegenstand'"*, beispielsweise in der Funktion `main()`:

| **main** |
|----------|
| spieler: Spielfigur |
| geister: Geist[0..3]   |

Diese Abhängigkeiten könnt Ihr gerne mit einzeichnen.

Zu diesem Zeitpunkt müßt Ihr noch nicht über Funktionen/Methoden nachdenken.


Diskutiert Euer Datenmodell und verändert es gegebenenfalls, bevor Ihr irgend etwas programmiert.
