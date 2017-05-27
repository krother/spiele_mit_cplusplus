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

	shared_ptr <string> smartPointer ( new string("bla"));
	shared_ptr <string> nochEinSmartPointer ( new string);

	cout << "Die Speicheradresse der Variablen smartPointer ist:  " << smartPointer << endl ;
	cout << "Der Wert der Variablen smartPointer ist:  " << *smartPointer << endl ;

	nochEinSmartPointer = smartPointer;

	cout << "Die Speicheradresse der Variablen nochEinSmartPointer ist:  " << nochEinSmartPointer << endl ;
	cout << "Der Wert der Variablen nochEinSmartPointer ist:  " << *nochEinSmartPointer << endl;

	return 0;
}
