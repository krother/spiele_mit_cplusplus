#include <iostream>
using namespace std;

// Beispielprogramm: Schachbrett ausgeben

int main() {

    bool start_weiss = true;         // Farbe des ersten Feldes der Reihe
	bool weiss;                      // Farbe des aktuellen Feldes
	int breite = 8;

    for (int i=0; i<breite; i++) {
        weiss = start_weiss;        
        for (int j=0; j<breite; j++) {
            if (weiss) {
                cout << '.';         // weisses Feld
            } else {
                cout << '#';         // schwarzes Feld
            }
            weiss = !weiss;          // Negationsoperator "!" macht true-> false
                                     // und umgekehrt
        }
        cout << endl;                // Ende der Reihe
        start_weiss = !start_weiss;  // naechste Reihe startet mit anderer Farbe
    }

    return 0;
}
