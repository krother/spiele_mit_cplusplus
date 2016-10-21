
#include <iostream>
using namespace std;

// Hier kommt eine Klassendeklaration
class Pferd {

   public: float hoehe;
   public: void reiten(string); // Deklaration einer Methode
   
           // Deklaration und Implementierung in einem
           // 'inline'-Schreibweise
           void pflege() {
              cout << "buersten" << endl;
           }

   public: Pferd(); // Deklaration von 3 Konstruktoren
           Pferd(float);  
           Pferd(int);
};

Pferd::Pferd() {hoehe = 1.2;}
Pferd::Pferd(float h) {hoehe = h;}
Pferd::Pferd(int i) {hoehe = (float)i;}

void Pferd::reiten(string ziel) { // Implementierung einer Methode
  // code der etwas macht
}


int main() {
  Pferd tom; // Deklaration einer Variable
  int a;     // auch eine Deklaration

}




