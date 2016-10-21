//
// http://www.cpp-tutor.de/cpp/le14/ableitung.html
// 
#include <iostream>
using namespace std;


class Tier: {

  protected: int alter;
  public: int beine;
  protected: string geraeusch;

  public: void laut_geben() {cout << geraeusch << endl;}

};


class Hund: public Tier {
  public: string name;
  public: Hund(string n) {
    Tier();
    alter = 3;
    name = n;
    beine = 4;
    geraeusch = "Wuff";
  }
  public: void alter_sagen() {cout << alter << endl;}
};

class Biene: public Tier {
  private: string farbe;
  public: Biene(string farbe) {
    beine = 6;
    geraeusch = "bsss";
  }
  public: string get_geraeusch() {
    return geraeusch;
  }
};

int main() {
  Hund rex("Rex");
  Biene maja("gelb-braun-gestreift");

  maja.laut_geben();
  rex.laut_geben();
  rex.name_sagen();

  cout << maja.beine << endl;
  cout << maja.get_geraeusch() << endl;
}




