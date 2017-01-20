
# Einen Editor schreiben

## Die Aufgabe

Entwickle einen Editor, in dem Du mit Hilfe der Maus grafische Elemente plazieren kannst

## Teilschritte

### 1. Vorbereitung

Verwende das Programm `mauszeiger.cpp` als Ausgangspunkt.

### 2. Variablen

Folgende Variablen wirst Du für die Mausposition und das Spielfeld benötigen

    int mausx;
    int mausy;
    int spielfeld[10][10];


### 3. Spielfeld zeichnen

Binde Code zum Zeichnen des Spielfeldes aus einem früheren Programm ein. Speichere das Programm als zweidimensionales Array.

Lege eine Funktion an, mit der Du das Zeichnen des Spielfeldes leicht aufrufen kannst.

### 4. Maus am Raster orientieren

Sobald sich die Maus bewegt, berechne aus der Mausposition die X und Y-Koordinate auf dem Spielfeld (von 0-9). 
Zeige die Position an, indem Du an der berechneten Stelle eine Kachel zeichnest.

**Hinweis**: verwende printf um die berechneten Koordinaten anzuzeigen.

**Optional**: zeichne einen Rahmen mit transparentem Inneren als eigene Bilddatei.

### 5. Blöcke setzen

Setze bei Tastendruck eine Banane auf die berechnete Position, so daß sich das Spielfeld verändert.

**Optional**: verwende verschiedene Tasten, um Wände, Korridore etc. zu setzen.


### 6. fertiges Spielfeld ausgeben

Bei Druck auf `x` soll das komplette Spielfeld auf der Konsole ausgebeben werden.


### 7. Spielfeld in einer Datei speichern

Bei Druck auf `x` soll das komplette Spielfeld in einer Datei gespeichert werden. Recherchiere selbst, wie das Speichern in einer Textdatei in C++ funktioniert (Dozent hat Buch dabei).

