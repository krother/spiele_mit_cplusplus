#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

int main() {
    // Zufallszahl erzeugen
    int zahl = rand() % 100 + 1;

    cout << "Ich habe mir eine Zahl ausgedacht." << endl;
    cout << "Rate die Zahl." << endl;

    char eingabe[10];
    int geraten;

    cout << endl << "Bitte gib eine Zahl ein (1-100): ";
    cin >> eingabe;
    geraten = atoi(eingabe); // Umwandlung in Integer
    
    // Prüfen
    if (zahl > geraten) {
        cout << "Die Zahl ist zu klein." << endl;
    }
    if (zahl < geraten) {
        cout << "Die Zahl ist zu gross." << endl;
    }
    if (zahl == geraten) {
        cout << "Treffer!" << endl;
    }
    return 0;
}

