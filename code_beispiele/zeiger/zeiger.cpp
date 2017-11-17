#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <memory>
using namespace std;


int main( ) {

	string text = "BeispielText!" ;

	// speichert SpeicherAdresse der Variablen text
	string*	zeiger = &text;

	// Ausgabe
	cout << "Die Speicheradresse der Variablen ist:  " << zeiger << endl ;
	cout << "Der Wert der Variablen ist:  " << *zeiger << endl ;

	}
