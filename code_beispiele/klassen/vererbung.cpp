//
// Vererbung
// (mehrere Unterklassen mit jeweils unterschiedlichen Eigenschaften)
// 
// http://www.cpp-tutor.de/cpp/le14/ableitung.html
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
      virtual void ausgeben() {
        cout << name << "(" << beine << " Beine)" << endl;
      }

};


class Hund: public Tier {
  public: 
      Hund(string n) : Tier(n, 4) {}

      void bellen() {
          cout << "Wuff" << endl;
      }
};


int main() {

  Hund rex("Rex");

  rex.ausgeben();
  rex.bellen();

}


