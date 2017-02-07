//
// Beispiel für einen Konstruktor
// (spezielle Methode zum Erzeugen eines
//  Objekts einer Klasse,
//  ideal zum Setzen von Eigenschaften)
// 
#include <iostream>
using namespace std;


class Tier {

  public: 
      string name;
      int beine;

      Tier(string n, int b) {
        name = n;
        beine = b;
      }
      void ausgeben() {
        cout << name << "(" << beine << " Beine)" << endl;
      }

};


int main() {
  Tier hund("Hund", 4);
  Tier biene("Biene", 6);

  biene.ausgeben();
  hund.ausgeben();
}




