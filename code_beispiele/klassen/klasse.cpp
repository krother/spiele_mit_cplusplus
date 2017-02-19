// classes example
#include <iostream>
using namespace std;

class Rechteck {
    int breite, hoehe;
    public: void setze_werte(int, int);
    int flaeche() {return breite*hoehe;}
};

void Rechteck::setze_werte(int x, int y) {
  breite = x;
  hoehe = y;
}

int main() {
  Rechteck rect1, rect2;
  rect1.setze_werte(3, 4);
  rect2.setze_werte(5, 6);
  cout << "flaeche: " << rect1.flaeche() << endl;
  cout << "flaeche: " << rect2.flaeche() << endl;
  return 0;
}

