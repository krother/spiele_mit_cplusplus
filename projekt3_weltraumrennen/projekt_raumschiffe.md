
# Projekt: "Raumschiffe"

### 3.1 Programm ausführen

Führe das Programm `rechteck.cpp` aus.

### 3.2 Implementiere eine Raumschiff-Klasse

Erstelle eine neue Klasse mit folgenden Eigenschaften:

* `x` - die x-Position des Raumschiffs.
* `y` - die y-Position des Raumschiffs.
* `speed` - die Geschwindigkeit des Raumschiffs.

Gib der Klasse folgende zwei Funktionen (Methoden):

* `bewegen()` - verändert die Position des Raumschiffs entsprechend der Geschwindigkeit.
* `zeichnen(SDLSrface *bild, SDLSurface *surf)` - zeichnet das Raumschiff vom Bild `bild` auuf `surf` an der aktuellen Position.


## 4. Raumschiffrennen

Schreibe ein Programm mit folgenden Eigenschaften:

* Drei Raumschiffe sind auf dem Bildschirm zu sehen.
* Die drei Raumschiffe bewegen sich mit unterschiedlichen Geschwindigkeiten.
* Verwende das Programm `weltraum.cpp` als Vorlage. 
* Verwende die Raumschiff-Klasse.


## 5. Zusatzaufgaben

### 5.1 Sterne

Implementiere den Sternenhintergrund aus dem früheren Raumschiffprogramm.

### 5.2 Vektor

Speichere alle Raumschiffe in einem Vektor, so daß sich deren Anzahl leichter verändern läßt.

Erhöhe die Anzahl der Raumschiffe auf 10.

### 5.3 Zufallsgeschwindigkeit

Gib den Raumschiffen zufällige Geschwindigkeiten.

### 5.4 Bewegungspfade

Gib jedem Raumschiff eine Eigenschaft `pfad`, welche mehrere Schritte enthält. Der Pfad soll vom Typ `string` sein. Ein `OOO` bedeutet *"drei Mal nach oben", ein `LRL` bedeutet links-rechts-links.

Lasse die Raumschiffe sich entsprechend ihrer Pfade bewegen.

