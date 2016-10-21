// Aufgabe 6.1: Quadratzahlen in einem Feld (array).

#include <iostream>
using namespace std;

int main() {

  int zahl;
  int quadratzahlen[10];
  
  zahl = 1;
  for (int i = 0; i < 10; i++) {
    quadratzahlen[i] = zahl * zahl;
    zahl++;
    cout << quadratzahlen[i] << endl;
  }
  return 0;
}

