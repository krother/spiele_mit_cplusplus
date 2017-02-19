#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main() {

    cout << "Filmvorschlags-Generator" << endl;
    cout << "Wie viele Hauptdarsteller sollen vorkommen?" << endl;
    cout << "Bitte gib eine Zahl ein." << endl;

    char eingabe[10];
    cin >> eingabe;
    int zahl = atoi(eingabe);

    cout << endl << "Ich schlage Dir folgenden Film vor: ";

    switch (zahl) {

    	case 1: cout << "Kevin allein zu Haus" << endl; break;
    	case 2: cout << "Romeo und Julia" << endl; break;
    	case 3: cout << "Die Drei Musketiere" << endl; break;
    	case 4: cout << "Beatles, die Doku" << endl; break;
    	case 7: cout << "Die Sieben Samurai" << endl; break;
    	case 137: cout << "Game of Thrones" << endl; break;

    	default: cout << "Frühstück bei Tiffany. Geht immer." << endl; break;
    }
}
