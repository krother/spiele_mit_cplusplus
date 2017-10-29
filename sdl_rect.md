### Schritt 4: Eine Kachel zeichnen

Um statt dem gesamten Bild nur einen Ausschnitt zu zeichnen, müssen wir zwei Rechtecke definieren -- eines für den zu kopierenden Bereich, eines für den Zielbereich. Zunächst *deklarieren* wir zwei Variablen, die wir dafür verwenden möchten. Füge zum Programm hinzu:

    SDL_Rect source;
    SDL_Rect dest;

Diese Rechtecke füllen wir nun mit den x/y-Koordinaten sowie Breite und Höhe. Zum Beispiel könnten wir eine Banane in die linke obere Ecke des Bildschirms zeichnen:

    source = {x: 0, y: 64, w:32, h:32};
    dest = {x: 0, y: 0, w:32, h:32};

Ersetze den Aufruf von `SDL_BlitSurface` durch:

    SDL_BlitSurface(fruechte, &source, surf, &dest);

Achte darauf, daß Du den Aufruf von `SDL_UpdateWindowSurface` nicht löschst.

Compiliere das Programm erneut, um sicher zu stellen, daß keine Fehler enthalten sind. 

