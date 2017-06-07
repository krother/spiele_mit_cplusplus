
## Das Raumschiff

### Ziel

Zeichne ein Raumschiff, das Du mit den Pfeiltasten bewegen kannst.

### Anforderungen

* Die Pfeiltasten bewegen das Raumschiff nach links, rechts, oben und unten
* Im Hintergrund ist ein Sternenhimmel zu sehen.

### Materialien

* Events mit SDL
* `switch`-Anweisung
* Klassen
* Beispielprogramm `rechteck.cpp`

### Hinweise

Für das Raumschiff sind folgende Teile erforderlich:

#### Variablen / Attribute:

* Ein Bild mit dem zu zeichnenden Raumschiff
* Die x- und y-Position auf dem Bildschirm

#### Funktionen / Methoden:

* Das Raumschiff an der aktuellen Position zeichnen
* Die Position entsprechend einer Taste verändern

#### Klassendefinition

Eine entsprechende Klassendefinition könnte folgendermaßen aussehen:

class Raumschiff {
    public:
        int x;
        int y;

        void zeichnen(SDLSurface *bild, SDLSurface *surf)
        void bewegen(int richtung);	
};



### Für Fortgeschrittene

* Der Sternenhimmel bewegt sich
* Das Raumschiff darf den Bildschirm nicht verlassen
* Implementiere das Rausmschiff als Klasse mit privaten und öffentlichen Teilen.
* Ändere das Programm, so daß die Pfeiltasten die *Geschwindigkeit* des Raumschiffs ändern.
