// Aufgabe 5.1: Zahlen von 1 bis 10 ausgeben

#include <iostream>
using namespace std;

int main() {

  int quadrat;
  
  for (int i = 1; i < 11; i++) {
    quadrat = i * i;
    cout << quadrat << endl;
  }
  return 0;
}
