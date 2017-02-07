#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    // Zufallsgenerator mit Uhr initialisieren
    srand(time(NULL));            
 
    int wuerfel[3] = {1, 2, 3};
    int versuche = 10;

    while (versuche > 0) {
        cout << endl << "Versuche übrig: " << versuche << endl;

        // Neu würfeln und Würfel ausgeben
        for (int i=0; i<3; i++) {
        	wuerfel[i] = rand() % 6 + 1;
        	cout << wuerfel[i] << " ";
        }
        cout << endl;

	    // Eingabe
	    char eingabe[10];
	    cout << "x zum Weiterwürfeln oder andere Taste zum Beenden: ";
	    cin >> eingabe;
        if (eingabe[0] != 'x') {
            versuche = 0;
        }
        versuche--;
    }
    int summe = wuerfel[0] + wuerfel[1] + wuerfel[2];
    cout << endl << "Dein Endergebnis: " << summe << endl;

    return 0;
}
