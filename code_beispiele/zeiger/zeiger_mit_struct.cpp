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

struct Spielfigur {
	string name;
	int hitpoints;
};

void ausgeben(Spielfigur *figur) {
	cout << figur->name << ", ";
	cout << figur->hitpoints << "HP" << endl;
}


int main() {

    Spielfigur spieler1 = {name: "Erik", hitpoints:100};
    Spielfigur spieler2 = {name: "Ronja", hitpoints:150};

    ausgeben(&spieler1);
    ausgeben(&spieler2);
	return 0;
}
