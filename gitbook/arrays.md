
# Arrays und Vektoren

## Arrays

Ein Array ist eine Folge von Elementen des gleichen Typs. Die Länge wird bei der Definition der Variable durch eckige Klammern angezeigt.

    int zahlen[5] = {1, 4, 9, 16, 25};

### Zuweisung von Elementen

Der Inhalt eines Arrays läßt sich über eine **Zuweisung** ändern. Dazu muß man in eckigen Klammern den **Index** des zu ändernden Elements angeben:

    zahlen[3] = 77;

Beachte, daß der Index bei `0` beginnt. Der höchste erlaubte Index im Beispielarray `zahlen` ist also `4`.

### Verwenden von Elementen

Über den Index können wir auch einzelne Elemente ansprechen, um sie auszugeben oder damit zu rechnen:

    cout << zahlen[4] << endl;
    int ergebnis = zahlen[2] + 7;

### Arrays in Schleifen

Eine typische Programmstruktur ist, *alle* Elemente eines Arrays in einer `for`-Schleife zu verwenden, z.B. um sie auszugeben:

    for (int i=0; i<5; i++) {
        cout << zahlen[i] << endl;
    }

### Mehrdimensionale Arrays

Es ist möglich, *mehrdimensionale Arrays* zu erzeugen:

   int tabelle[4][4];

Auf die Werte wird widerum mit eckigen Klammern zugegriffen, wobei das erste Element den Index 0 trägt:

   cout << tabelle[2][3] << endl;

## Vektoren

Vektoren sind Listen mit einem *Datentyp* und *variabler Länge*. Vektoren lassen sich mit doppelten geschweiften Klammern definieren:

    vector<int> liste {{1, 2, 3, 5, 7}};

Über die Funktion `size()` läßt sich die Anzahl der Elemente eines Vektors bestimmen:

    for (unsigned int i=0; i < liste.size(); i++) {
        cout << liste[i] << endl;
    }

Mit der Funktion `push_back(element)` lassen sich Elemente am Ende des Vektors anhängen:
 
    liste.push_back(13);

Weitere Funktionen und Details siehe unter [www.cplusplus.com/reference/vector/vector/](http://www.cplusplus.com/reference/vector/vector/) 

