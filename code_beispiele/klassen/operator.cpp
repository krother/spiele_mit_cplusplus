
//
// Ueberladen von Methoden
// 
// http://www.cpp-tutor.de/cpp/le12/ueberladen.html
//
#include <iostream>
using namespace std;


class PlusZweiZahl {
 
  private: int zahl;
  public: PlusZweiZahl(int i) {zahl = i;}

  int operator + (PlusZweiZahl wert) {
    return zahl + 2 + wert.zahl;
  }
  int operator * (PlusZweiZahl wert) {
    return zahl * 2 * wert.zahl;
  }
  string operator || (PlusZweiZahl wert) {
    return "Der oder-Operator ist ueberbewertet.";
  }
};

int main() {

  PlusZweiZahl a(7);
  PlusZweiZahl b(3);
  
  cout << a + b << endl;
  cout << a * b << endl;
  cout << (a || b) << endl;
}

