//
// Das Schluesselwort 'static'
// 
// http://www.cpp-tutor.de/cpp/le10/statische_member.html
//
#include <iostream>
using namespace std;


class Zaehler {
 
  public: static int instanzen;
  public: void noch_einer() {instanzen++;}

};

int Zaehler::instanzen = 0;
  
int main() {
  
  Zaehler eins;
  Zaehler zwei;
  Zaehler drei;
  
  eins.noch_einer();
  eins.noch_einer();
  zwei.noch_einer();
  drei.noch_einer();

  cout << Zaehler::instanzen << endl;  
}





