//
// Text in Datei speichern
//
//
// compilieren mit -std=c++11
// (sonst funktioniert stoul nicht)
//
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {

	ifstream eingabe("punkte.txt");
	if (!eingabe.good()) {
		cerr << "Dateifehler!";
		return 1;
	}

	string spieler;
	string punktezeile;
	while (eingabe.good()) {

        getline(eingabe, spieler);
        if (spieler[0] == '#') {
            break;
        }
	    getline(eingabe, punktezeile);
	    int punkte = stoul(punktezeile);
			cout << spieler << " : " << punkte << endl;

	}

}
