
#include <iostream>
using namespace std;

// benötigt zum compilieren --std=c++11

int main() {

    // Funktion in einer Variable speichern
    auto max = [](int a, int b) { return a < b ? b : a; };
   
    cout << max(7, 8) << endl;

    // definieren und gleich aufrufen
    cout << [](int a, int b) { return a < b ? b : a; }(33, 22) << endl;

    // Erfassungsliste [] kopiert lokale Variablen
    int x = 7;
    auto mehrfach = [x](int a){ return a*x; };

    cout << mehrfach(3) << endl;
    x = 5;
    cout << mehrfach(3) << endl;
}
