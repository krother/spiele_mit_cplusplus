#include <iostream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <memory>
using namespace std;


int main( ) {

	string text = "BeispielText!" ;

	// speichert SpeicherAdresse der Variablen text in normalerPointer
	string*	normalerPointer= &text;

	// Ausgabe
	cout << "Die Speicheradresse der Variablen ist:  " << normalerPointer << endl ;
	cout << "Der Wert der Variablen ist:  " << *normalerPointer << endl ;

	// löscht den Pointer, damit der Speicher wieder frei ist.
	delete normalerPointer;

	}
