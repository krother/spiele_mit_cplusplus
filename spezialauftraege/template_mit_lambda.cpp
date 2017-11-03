

#include <iostream>
using namespace std;

// benötigt zum compilieren --std=c++11

template<typename Funktion>
int suchen(int a[8], Funktion lambda) {
	int x = a[0];
	for (int i=1; i<8; i++) {
		x = lambda(x, a[i]);
	}
	return x;
}

int main() {

    auto min = [](int a, int b) { return a < b ? a : b; };
    auto max = [](int a, int b) { return a > b ? a : b; };
   
    int zahlen[8] = {11, 4, 19, 77, 3, 7, 20, 10};

    cout << "MIN: " << suchen(zahlen, min) << endl;
    cout << "MAX: " << suchen(zahlen, max) << endl;
}
