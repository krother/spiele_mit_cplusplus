
# 1.2 Zufallswürfel

Mit dem gezinkten Würfel kommen wir nicht weit. Abgesehen davon daß die Leute schnell mißtrauisch werden, verdirbt man sich auch schnell den Spaß am Spiel. Deswegen brauchen wir einen *ehrlichen* sechsseitigen Würfel.

### Anforderungen:

* Der Würfel fällt auf eine Zahl zwischen 1 und 6.
* Das Würfelergebnis erscheint auf dem Bildschirm.
* Das Programm gibt genau ein Ergebnis aus.
* Es ist möglich, daß bei jedem Programmstart eine andere Zahl erscheint.

### Beispielausgabe:

    Das Würfelergebnis ist: 3


## Variablen und Datentypen

Für die folgenden Aufgaben kann das Material unter [www.cpp-tutor.de](http://www.cpp-tutor.de) nützlich sein.

### Aufgabe 1

Schreibe ein Programm, das die folgenden Zeilen enthält:

    int ergebnis;
    ergebnis = 4;
    cout << ergebnis << endl;
    ergebnis = ergebnis + 2;
    cout << ergebnis << endl;

Mache das Programm funktionsfähig, compiliere es und führe es dann aus.


### Aufgabe 2

Setze ein `//` vor eine der Zeilen im Programm. Compiliere das Programm erneut. Was passiert?


### Aufgabe 3

Recherchiere nach weiteren einfachen Datentypen in C++. 
Befüllt gemeinsam die folgende Tabelle.

| Datentyp | Bedeutung |
|----------|-----------|
| int      | ganze Zahlen |
| long int |              |
| short int |              |
| unsigned int |              |
| char     |              |
| bool     |              |
| float    |              |
| double   |              |


### Aufgabe 4

* Schreibe ein neues Programm, in dem Du drei Variablen mit den Typen `int`, `double` und `char` definierst.
* Befülle alle drei Variablen mit Inhalt.
* Gib die Werte der drei Variablen auf dem Bildschirm aus.


### Aufgabe 5

Ermittle, was die folgenden **Operatoren** in einem Programm tun:

* `1 + 2;`
* `3 * 4;`
* `7 % 2;`
* `x = 8; x++;`
* `true && (true || false) && !false;`


### Aufgabe 6

Schreibe das oben beschriebene Würfelspiel. Für ein Würfelspiel benötigen wir Zufallszahlen. Diese können wir uns wie folgt erzeugen:

    #include <stdlib.h>

    int zufall = rand() % 10 + 1;

Die Funktion `rand()` erzeugt eine zufällige ganze Zahl, die auch sehr groß sein kann. Der Operator `%` (Modulo) ergibt den Rest der Teilung durch 10. 

**Achtung:** *Computer können grundsätzlich keinen echten Zufall erzeugen. Die Zahl ist daher jedes Mal die gleiche. Für unser erstes Zahlenrate-Spiel werden wir uns das zu Nutze machen.*
