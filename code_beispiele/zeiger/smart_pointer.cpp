/*
Shared-pointer - ein SmartPointer, der Referenzen mitzählt.
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <memory>
using namespace std;

// zu compilieren mit der Option --std=c++11

int main() {

	shared_ptr<string> energie1 = make_shared<string>("Atomenergie");
	shared_ptr<string> energie2 = make_shared<string>("Braunkohle");

	cout << "Die Speicheradresse der Variablen energie1 ist:  " << energie1 << endl ;
	cout << "Der Wert der Variablen energie1 ist:  " << *energie1 << endl ;

    // SmartPointer lassen sich gut kopieren
	energie2 = energie1;

	// unsichtbar: C++ merkt, dass Braunkohle nicht mehr gebraucht wird,
	//             wird im Hintergrund automatisch entsorgt.

	cout << "Die Speicheradresse der Variablen energie2 ist:  " << energie2 << endl ;
	cout << "Der Wert der Variablen energie2 ist:  " << *energie2 << endl;

	// jetzt ändern wir den Wert
	energie1 = make_shared<string>("Solarpower");
	cout << endl << "Der Wert der Variablen energie1 ist:  " << *energie1 << endl ;
	cout << "Der Wert der Variablen energie2 ist:  " << *energie2 << endl;

	return 0;
}
