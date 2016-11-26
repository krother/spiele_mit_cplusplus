
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

int main() {
    srand(time(NULL));            // Zufallsgenerator initialisieren
    int zahl = rand() % 100 + 1;  // Zufallszahl per Modulo erzeugen.

    cout << "Ich habe mir eine Zahl ausgedacht." << endl;
    cout << "Rate die Zahl." << endl;

    char eingabe[10];
    int geraten;

    do {
        cout << endl << "Bitte gib eine Zahl ein (1-100): ";
        cin >> eingabe;
        geraten = atoi(eingabe);
        if (zahl > geraten) {
            cout << "Die Zahl ist zu klein." << endl;
        }
        if (zahl < geraten) {
            cout << "Die Zahl ist zu gross." << endl;
        }
    } while (geraten != zahl);
  
    cout << "Treffer!" << endl;
    return 0;
}

