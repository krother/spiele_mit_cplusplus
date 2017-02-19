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

class Biene: public Tier {
  public:
      bool honig;
      Biene(bool h) : Tier("Biene", 6) {
           honig = h;
      }

      void summen() {
          cout << "bsss ... bsss ... bsss" << endl;
      }

      virtual void ausgeben() {
          Tier::ausgeben();
          if (honig) {
              cout << "Honig geladen!" << endl;
          }
      }
};


int main() {
  Hund rex("Rex");
  Biene maja(true);

  rex.ausgeben();
  rex.bellen();
  maja.ausgeben();
  maja.summen();

}




