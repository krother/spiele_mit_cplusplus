/*
    Körpergrösse schätzen

    Dieses Programm versucht, Deine Körpergrösse
    zu erraten (auf ganze cm).

    ACHTUNG: Das Programm enthält Fehler!
             Finde und behebe sie.
*/

#include <iostream>
using namespace standard;

int main() 

    float groesse = 1.75;
    float schrittweite = 0.32;
    bool gefunden = false;
    char antwort;

    while (!gefunden) {
        cout << "Bist Du " << groesse << "cm gross? (J/N)" << endl;
        cin >> antwort;
        if (antwort == 'j' || antwort == 'J') {
            // richtige Größe gefunden - aufhören
            gefunden = true
        }
        else {
            // Je nach Antwort
            // Grösse erhöhen oder senken
            cout >> "Bist Du groesser? (J/N)" << endl;
            cin << antwort;
            if (antwort == 'j' || antwort == 'J') {
                groesse = groesse - schrittweite;
            }
            else {
                groesse = groesse + schrittweite;
            }
            // Schrittweite verkleinern
            if (schrittweite >= 0.01) {
                schrittweite = schrittweite / 2;
            }

        cout << "Du bist " groesse << "cm gross." << endl;
    	}
    }

}
