
# Aufgaben Tag 6

## Ziel

Ein Spiel zu schreiben, bei dem Du ein Raumschiff über die Pfeiltasten auf dem Bildschirm bewegst.

![Raumschiff](raumschiff.png)

## 1. Sterne darstellen

### 1.1 Sternenhimmel

Bringe das Programm `Weltraum/weltraum.cpp` zum Laufen (Du benötigst die SDL-Bibliotheken und das build-Skript aus den vorangegangenen Übungen).

### 1.2 Bewegung

Schreibe eine Schleife, welche das Sternbild von rechts nach links bewegt.

### 1.3 Mehr Sterne

Stelle auch die anderen beiden Sternbilder (`stars2.png` und `stars3.png`) dar. 

### 1.4 Parallax-Effekt

Sorge dafür, daß sich die drei Sternbilder mit unterschiedlichen Geschwindigkeiten bewegen. Gib der Eben mit den kleinsten Sternen die langsamste Geschwindigkeit.

### 1.5 Funktion

Lagere das Zeichnen der Bilder in eine Funktion aus, um den Code zu verkürzen.


## 2. Das Raumschiff

### 2.1 Zeichnen

Zeichne ein Raumschiff-Bild aus der Datei `raumschiffe.png` vor dem Sternenhimmel.

### 2.2 Position

Speichere die Position des Raumschiffs in einer Variablen

### 2.3 Tastaturereignisse

Führe das Programm im Verzeichnis `Events` aus. Ermittle die Codes für verschiedene Tasten.

In SDL lassen die Pfeiltasten sich auch schreiben als `SDL_UP`, `SDL_DOWN` usw.

### 2.4 Bewegung

Sorge dafür, daß sich das Raumschiff mit *Pfeil oben* nach oben bewegt. Setze danach auch die übrigen Pfeiltasten um.

### 2.5 Switch

Betrachte das Beispiel im Ordner `Switch`. Verwende `switch`, um das Beispiel

### 2.6 Beschleunigung

Ändere das Programm, so daß die Pfeiltasten die *Geschwindigkeit* des Raumschiffs ändern.


## 3. Textausgabe in SDL

### 3.1 SDL-ttf installieren

* Entpacke die include- und .dll-Dateien der Bibliothek **SDL2_ttf**.
* Kopiere die inlcude-Dateien zu den übrigen SDL-Bibliotheken.
* füge im Skript `build.bat` die Option `-lSDL2_ttf` hinzu.

### 3.2 Text auf den Bildschirm schreiben

Compiliere das Programm `text.cpp` und führe es aus.


## 4. Klassen

### 4.1 Eine Klasse verwenden

Führe das Programm im Ordner `Klassen` aus und verstehe was es tut.

### 4.2 Eine Klasse entwickeln

Entwerfe eine Klasse für das Raumschiff und baue sie in das bestehende Programm ein.


