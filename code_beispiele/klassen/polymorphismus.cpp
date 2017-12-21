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
  Biene maja(true);

  maja.ausgeben();
  maja.summen();

}




