
# Übungen: Schleifen mit for

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
