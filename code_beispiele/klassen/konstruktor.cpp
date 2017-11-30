//
// Beispiel für einen Konstruktor
// (spezielle Methode zum Erzeugen eines
//  Objekts einer Klasse,
//  ideal zum Setzen von Eigenschaften)
// 
#include <iostream>
using namespace std;


class Tier {

  private:
    string name;
    int beine;

  public: 
    Tier(string, int b);
    void ausgeben();
};


Tier::Tier(string n, int b) {
    name = n;
    beine = b;
}

void Tier::ausgeben() {
    cout << name << "(" << beine << " Beine)" << endl;
}

int main() {
  Tier hund("Hund", 4);
  Tier biene("Biene", 6);

  biene.ausgeben();
  hund.ausgeben();
}

