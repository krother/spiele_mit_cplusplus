
# Textausgabe mit Streams

Es gibt mehrere Möglichkeiten, Text in C++ auszugeben.

## Ausgabe mit Streams

Die Bibliothek `iostream` enthält eine einfache Ausgabemethode: Streams. Ein Stream schickt erhaltene Daten an ein Ziel. Das Ziel ist in unserem Fall ein Textfenster. Andere Streams können in Dateien oder einen Rechner im Internet schreiben.

Über die Anweisung `#include` sagst Du C++, daß Du eine bestimmte Bibliothek verwenden möchtest:

    #include <iostream>
    using namespace std;

Der Stream `cout` ist für die Ausgabe zuständig. Du kannst eine Textausgabe mit dem Operator `<<` auslösen:

    cout << "Hallo";

Auch Zahlen lassen sich so ausgeben:

    cout << 3.1415;

Ein Zeilenumbruch läßt sich mit `endl` plazieren:

    cout << endl;

Du kannst auch alle drei Möglichkeiten kombinieren:

    cout << "Hallo" << 3.1415 << endl;
