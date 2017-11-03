
# Variablen

Variablen sind *"Behälter"* für Daten in einem Programm. Du kannst darin Daten ablegen, und sie später im Programm mehrmals verwenden. 


### Variablen deklarieren

Bei der ersten Verwendung musst Du eine Variable **deklarieren**. Das bedeutet, dem C++-Compiler muss mitgeteilt werden:

1. Wie die Variable heißt
2. Welchen Datentyp sie hat.

Die Deklaration einer Integer-Variable (*ganze Zahl*) mit dem Namen `a` sähe folgendermaßen aus:

    int a;

#### Achtung:

Jede Variable darf **nur einmal pro Codeabschnitt** (Funktion, Datei) deklariert werden!

### Startwert

Bei der Deklaration darf man einen Startwert für die Variable festlegen. Dies ist optional. Dabei steht der Datentyp immer links, der Name rechts daneben:

    int jahr = 2017;

Eine Folge von 10 Buchstaben hat den Typ `char[10]`. Dabei steht die `[10]` rechts neben dem Namen:

    char name[10] = "Peter";

Manche Datentypen sind in Erweiterungsmodulen definiert. Zum Beispiel enthält die Grafikbibliothek SDL zahlreiche Datentypen für Fenster und Grafikelemente:

    SDL_Window *win;

Die Schreibweise ist eigentlich zu der einer Integer-Variable identisch. Weil dabei aber andere Wörter (die eigens definierten Datentypen) und manchmal auch Sonderzeichen (Sternchen, spitze Klammern) vorkommen, erkennt man das nicht immer gleich.

### Inhalt einer Variablen ausgeben

Ist eine Variable erst einmal definiert, können wir sie anstelle ihres Wertes verwenden. Oft möchte man den Wert einfach nur ausgeben:

    cout << jahr << endl;

Oder man führt eine Berechnung mit dem Wert durch:

    cout << jahr + 1 << endl;

### Inhalt einer Variablen verändern

Interessant werden Variablen dadurch, daß Du ihren Inhalt jederzeit verändern darfst. Zum Beispiel überschreibt die folgende Zeile den zuvor gespeicherten Wert:

    jahr = 2016;

Du darfst das Überschreiben auch mit einer Rechnung kombinieren:

    jahr = jahr + 1
    cout << jahr << endl;
