
# Datentypen

## Integer

Der Datentyp **Integer** (`int`) bezeichnet ganze Zahlen.

Eine Integer-Variable definieren:

    int a;

Eine Integer-Variable definieren und einen Wert zuweisen:

    int a = 7;

Mit Integer-Zahlen rechnen:

    a = a + 3;
    a = a - 4;
    a = a * 5;
    a = a / 6;


## Buchstaben

Der Datentyp **`char`** bezeichnet Buchstaben.

Eine einzelne Buchstaben-Variable definieren und einen Wert zuweisen:

    char c = "A";

Eine Folge von 10 Buchstaben definieren:

    char c[10];


## Boolean

Der Datentyp **Boolean** bezeichnet Wahrheitswerte. 
Eine Boolean-Variable kann nur zwei Werte annehmen: 
`true` und `false`.

Eine **Boolean**-Variable definieren und einen Wert zuweisen:

    bool fertig = false;

## Arrays

Ein Array ist eine Folge von Elementen des gleichen Typs. Die Länge wird bei der Definition der Variable durch eckige Klammern angezeigt.

    int zahlen[5] = {1, 2, 3, 4, 5};

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

## Strings

Der Datentyp `string` ist eine Kette von Buchstaben und anderen Zeichen. Strings werden mit Anführungszeichen definiert:

    string text = "abcdef";

Sie lassen sich mit `cout` ausgeben wie der Typ `char`:

    cout << text << endl;

Strings verfügen über Funktionen, mit denen sie sich analysieren und verändern lassen:


    cout << text.at(4) << endl;
    cout << text.substr(2, 4) << endl;
    cout << text.length() << endl;


Weitere Funktionen und Details siehe unter [www.cplusplus.com/reference/string/string/](http://www.cplusplus.com/reference/string/string/) 

## enums

*kommt noch*

