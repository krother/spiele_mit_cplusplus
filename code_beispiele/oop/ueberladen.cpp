
//
// Ueberladen von Methoden
// 
// http://www.cpp-tutor.de/cpp/le12/ueberl_member.html
//
#include <iostream>
using namespace std;


class Addierer {
 
  public: int addiere(int a, int b) {return a + b;}
  public: int addiere(int a, int b, int c) {return a + b + c;}
  public: int addiere(int a, int b, int c, int d) {return a + b + c + d;}
  public: string addiere(string a, string b) {return a + ' ' + b;}
};

int main() {

  Addierer a;
  
  cout << a.addiere(1, 2) << endl;
  cout << a.addiere(1, 2, 3) << endl;
  cout << a.addiere(1, 2, 3, 4) << endl;
  cout << a.addiere("unsere", "Katze") << endl;
}

