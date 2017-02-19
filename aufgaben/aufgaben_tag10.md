
# Aufgaben Tag 10

## 1. Strings

### 1.1 Programm ausführen

Führe das Programm `string.cpp` aus. Erkläre den Code.

### 1.2 Die Dokumentation verwenden

Lies in der Dokumentation unter [www.cplusplus.com/reference/string/string/](http://www.cplusplus.com/reference/string/string/) nach, welche weiteren Funktionen es gibt.

Probiere 2 davon aus.


## 2. Vektoren

### 2.1 Programm ausführen

Führe das Programm `vektoren.cpp` aus. Erkläre den Code.

### 2.2 Element aus einem Vektor löschen.

Finde heraus, wie Du das letzte Element eines Vektors löschen kannst. Implementiere dies in einem Programm und gib den entsprechenden Vektor aus.

Siehe [www.cplusplus.com/reference/vector/vector/](http://www.cplusplus.com/reference/vector/vector/) 


## 3. Klassen

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

