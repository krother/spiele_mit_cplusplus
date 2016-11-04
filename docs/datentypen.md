
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

