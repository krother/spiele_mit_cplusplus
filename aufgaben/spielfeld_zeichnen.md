
# Ein Spielfeld zeichnen

**Schwierigkeit: MITTEL**

Für das Spielfeld brauchen wir eine neue Art von Datentyp: **Arrays**.

### Aufgabe 1

Compiliere das Programm `array.cpp` und führe es aus. Erkläre den Code.

### Aufgabe 2

Schreibe ein Programm, im welchem Du folgende Zahlen in ein Array schreibst:

    11, 22, 33, 44, 55, 66, 77, 88, 99

Das Programm soll alle Zahlen ausgeben, die durch 3 ohne Rest teilbar sind.

### Aufgabe 3

Im Programm `schachbrett.cpp` findest Du ein **verschachteltes Array** oder **zweidimensionales Array**.

Ergänze das Programm durch zwei `for`-Schleifen, so daß das gesamte Schachbrett im Textfenster ausgegeben wird.


### Aufgabe 4

Verknüpfe das verschachtelte Array mit der Grafikbibliothek SDL, so daß das *"Schachbrett"* mit Kachel-Grafik in einem Grafikfenster gezeichnet wird.

Um einen rechteckigen Bildbereich kopieren benötigst Du unter anderem den Code:

    SDL_Rect source{x: x*32, y: y*32, w:32, h:32};
    SDL_Rect destination{x: dx*32, y: dy*32, w:32, h:32};
    SDL_BlitSurface(img, &source, surf, &destination);

Sowie diverse Kommandos aus dem minimalen SDL-Beispiel.

