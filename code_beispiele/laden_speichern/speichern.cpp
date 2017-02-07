//
// Text in Datei speichern
//
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {

	ofstream ausgabe("punkte.txt");
	if (!ausgabe.good()) {
		cerr << "Dateifehler!";
		return 1;
	}
	string name;
	
	ausgabe << "Rotkäppchen" << endl << 300 << endl;
	ausgabe << "der Wolf" << endl << 50 << endl;

	ausgabe << "#"; // Endmarkierung

}