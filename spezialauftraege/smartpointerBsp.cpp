//============================================================================
// Name        : bsp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <memory>
using namespace std;


int main( ) {

	int beispielNummer = 1;

	// BeispielText
	string text = "BeispielText!" ;
	switch(beispielNummer)

	{
	// einfacher Pointer
	case 1 : {


		// speichert SpeicherAdresse der Variablen text in normalerPointer
			string*	normalerPointer= &text;

			// Ausgabe
		cout << "Die Speicheradresse der Variablen ist:  " << normalerPointer << endl ;
		cout << "Der Wert der Variablen ist:  " << *normalerPointer << endl ;

		// löscht den Pointer, damit der Speicher wieder frei ist.
		delete normalerPointer;


	}
	// smartPointer
	case 2 : {
		shared_ptr <string> smartPointer ( new string("bla"));
		shared_ptr <string> nochEinSmartPointer ( new string);

		cout << "Die Speicheradresse der Variablen smartPointer ist:  " << smartPointer << endl ;
		cout << "Der Wert der Variablen smartPointer ist:  " << *smartPointer << endl ;

		nochEinSmartPointer= smartPointer;

		cout << "Die Speicheradresse der Variablen nochEinSmartPointer ist:  " << nochEinSmartPointer << endl ;
			cout << "Der Wert der Variablen nochEinSmartPointer ist:  " << *nochEinSmartPointer << endl ;



	}

	





	}
	return 0;
}
