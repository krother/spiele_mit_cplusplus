#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    // Zufallsgenerator mit Uhr initialisieren
    srand(time(NULL));            
 
    int wuerfel[5] = {1, 2, 3, 4, 5};
    char buchstaben[5] = {'A', 'B', 'C', 'D', 'E'};
    int versuche = 10;
    bool gewonnen = false;

    while (!gewonnen && versuche > 0) {
        cout << endl << "Versuche übrig: " << versuche << endl;

        // Neu würfeln und Würfel ausgeben
        for (int i=0; i<5; i++) {
        	if (buchstaben[i] != 'x') {
                wuerfel[i] = rand() % 6 + 1;
        	}
            cout << buchstaben[i] << " : " << wuerfel[i] << endl;
        }

        if (wuerfel[0] == wuerfel[1] && wuerfel[0] == wuerfel[2] 
        	&& wuerfel[0] == wuerfel[3] && wuerfel[0] == wuerfel[4]) {
        	gewonnen = true;
        }
        else {    	
	        // Eingabe
	        char eingabe[10];
	        do {
	            cout << "Würfel zum Sperren auswählen oder x zum Weiterwürfeln: ";
	            cin >> eingabe;
	            for (int i=0; i<5; i++) {
	            	if (buchstaben[i] != 'x' && buchstaben[i] == eingabe[0]) {
	            		buchstaben[i] = 'x'; // Sperren
	            	}
	            }
	        } 
	        while (eingabe[0] != 'x');
        }

        versuche--;
    }
    if (gewonnen) {
    	cout << "Gewonnen!!!" << endl;
    }

    return 0;
}
