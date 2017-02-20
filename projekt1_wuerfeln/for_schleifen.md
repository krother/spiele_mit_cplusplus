
## 1.4 Zahlenraten mit mehreren Versuchen

Mit nur einem Versuch schlagen 5 von 6 Rateversuchen fehl. Das ist auf die Dauer frustrierend. 
Interessanter wird es, wenn der Spieler die Möglichkeit hat, sein Ergebnis zu verbessern. Mit mehreren Versuchen können wir sogar Zahlen zwischen 1 und 100 erraten.

### Anforderungen:

* Das Programm *"erwürfelt"* eine Zahl zwischen 1 und 100.
* Die Zahl wird **nicht** ausgegeben.
* Der Spieler gibt eine Zahl ein.
* Das Programm sagt, ob die geratene Zahl zu groß, zu klein oder ein Treffer ist.
* Der Spieler erhält neue Rateversuche, bis die richtige Zahl getroffen wurde.

### Beispielausgabe:

    Ich habe mir eine Zahl ausgedacht.
    Rate die Zahl.

    Bitte gib eine Zahl ein (1-100): 33
    Die Zahl ist zu gross.

    Bitte gib eine Zahl ein (1-100): 22
    Die Zahl ist zu gross.

    Bitte gib eine Zahl ein (1-100): 11
    Die Zahl ist zu klein.

    Bitte gib eine Zahl ein (1-100): 17
    Die Zahl ist zu gross.

    Bitte gib eine Zahl ein (1-100): 14
    Die Zahl ist zu gross.

    Bitte gib eine Zahl ein (1-100): 12
    Die Zahl ist zu klein.

    Bitte gib eine Zahl ein (1-100): 13
    Treffer!


## Schleifen mit for

In dieser Aufgabe werden wir uns die `for`-Anweisung genauer anschauen, mit der wir einen oder mehrere Befehle wiederholt ausführen können.


### Aufgabe 1

Was tut das folgende Programm?

    for (int i=1; i<43; i++) {
        cout << i << endl;
    }


### Aufgabe 2

Welche Vorteile hat dieses Programm gegenüber folgendem Ansatz?

    cout << 1 << endl;
    cout << 2 << endl;
    cout << 3 << endl;
    cout << 4 << endl;
    ..
    cout << 42 << endl;


### Aufgabe 3

Schreibe eine Schleife mit `for`, welche folgende Quadratzahlen produziert:

    1
    4
    9
    16
    25
    36
    49


### Aufgabe 4

Erkläre den Unterschied zwischen den folgenden zwei Programmen:

    int summe = 0;
    for (i=0; i<10;i++) {
        summe = summe + i;
    }
    cout << summe << endl;

und

    int summe = 0;
    for (i=0; i<10;i++) {
        summe = summe + i;
        cout << summe << endl;
    }


### Aufgabe 5

Schreibe eine `for`-Schleife, die Quadratzahlen in einer Zeile ausgibt:

    1 4 9 16 25 36 49 64 81


### Aufgabe 6

Schreibe eine `for`-Schleife, die den folgende Ausgabe produziert:

    000111222333444555666777888999


### Aufgabe 7

In folgendem Programm sind vier typische Fehler versteckt. Finde und behebe sie.

    #include <iostream>
    using namespace std;
    
    // Das Programm soll von 20 bis 1 zählen
    // und alle ungeraden Zahlen ausgeben.
    
    int main() {
    
        for (int i=20;i>0;i--) {
            if (i % 2 == 0) {
                cout << i % 2 << endl
            }
        }


### Aufgabe 8

Erkläre das folgende Programm?

    #include <iostream>
    using namespace std;
    
    int main() {
    
        int zahl;
        for (int i=0;i<10;i++) {
            for (int j=0;j<10;j++) {
                zahl = i*10 + j;
                if (zahl % 7 == 0) {
                    cout << "#" << zahl << "# ";
                }
                else {
                    cout << " " << zahl << "  ";
                }
            }
            cout << endl;
        }
    }   

### Aufgabe 9

Schreibe das oben beschriebene Spiel, bei dem sich der Computer eine Zufallszahl zwischen 1 und 100 *"ausdenkt"*. Der Spieler hat wie zuvor *mehrere* Versuche, die Zahl zu erraten.
