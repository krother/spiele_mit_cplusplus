#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    // Zufallsgenerator mit Uhr initialisieren
    srand(time(NULL));            

    // Zufallszahl erzeugen und ausgeben
    int zahl = rand() % 6 + 1;
    cout << "Würfelergebnis: " << zahl << endl;

    return 0;
}

