
# Datentypen

C++ kennt eine große Zahl von Datentypen. Dies sind die wichtigsten:

| Datentyp | Beschreibung |
|----------|--------------|
| int      | ganze Zahlen |
| float    | Kommazahlen  |
| char     | Buchstaben   |
| string   | Zeichenketten |
| array    | einfache Listen konstanter Größe |
| enum     | Aufzählung |
| struct   | Gruppe mit gemischten Typen |
| Vector   | Listen variabler Größe |


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

