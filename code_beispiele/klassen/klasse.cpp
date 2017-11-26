// classes example
#include <iostream>
#include <string>
using namespace std;


class Raumschiff {
    string name;
    int x, y;
    public: 
      void taufe(string);
      void setze_position(int, int);
      void ausgabe();
};


void Raumschiff::taufe(string n) {
    name = n;
}

void Raumschiff::setze_position(int ax, int ay) {
    x = ax;
    y = ay;
}

void Raumschiff::ausgabe() {
   cout << "Das Schiff " << name;
   cout << " befindet sich bei (" << x << "/" << y << ")" << endl;
}

int main() {
  Raumschiff schiff1;
  Raumschiff schiff2;

  schiff1.taufe("Nostromo");
  schiff2.taufe("Excalibur");
  schiff1.setze_position(0, 0);
  schiff2.setze_position(17, 5);

  schiff1.ausgabe();
  schiff2.ausgabe();

  return 0;
}

