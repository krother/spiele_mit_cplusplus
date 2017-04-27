
# Variablen

Variablen sind *"Behälter"* für Daten in einem Programm. Du kannst darin Daten ablegen, und sie später im Programm mehrmals verwenden. 

### Variablen definieren

Bei der ersten Verwendung musst Du eine Variable **definieren**. Das bedeutet, dem C++-Compiler müssen mehrere Dinge mitgeteilt werden:

1. Wie die Variable heißt
2. Welchen Datentyp sie hat.
3. Welchen Startwert sie hat (optional)

Dabei steht der Datentyp immer links, der Name rechts daneben. Es folgt ein Gleichheitszeichen und dann der Startwert.

Die Definition einer *ganzzahligen Variable* (Typ `int`) sieht so aus:

    int jahr = 2017;

Eine Folge von 10 Buchstaben hat den Typ `char[10]`. Dabei steht die `[10]` rechts neben dem Namen:

    char name[10] = "Peter";

Manche Datentypen sind in Erweiterungsmodulen definiert. Zum Beispiel enthält die Grafikbibliothek SDL zahlreiche Datentypen für Fenster und Grafikelemente:

    SDL_Window *win;

### Inhalt von Variablen ausgeben

Ist eine Variable erst einmal definiert, können wir sie anstelle ihres Wertes verwenden. Oft möchte man den Wert einfach nur ausgeben:

    cout << jahr << endl;

Oder man führt eine Berechnung mit dem Wert durch:

    cout << jahr + 1 << endl;

### Inhalt von Variablen verändern

Interessant werden Variablen dadurch, daß Du ihren Inhalt jederzeit verändern darfst. Zum Beispiel überschreibt die folgende Zeile den zuvor gespeicherten Wert:

    jahr = 2016;

Du darfst das Überschreiben auch mit einer Rechnung kombinieren:

    jahr = jahr + 1
    cout << jahr << endl;
