
#include <iostream>
using namespace std;

void ausgeben(int zahl) {
	cout << "----------" << endl;
	cout << "JETZT KOMMT DIE ZAHL: " << zahl << endl;
	cout << "----------" << endl << endl;
}


int kleinster(int a, int b, int c) {
    if (a < b && a < c) { return a; }
    if (b < c) { return b; }
    return c;
}


int main() {

    // Funktion ohne Rückgabewert
	ausgeben(33);
	ausgeben(77);

    // Funktion mit Rückgabewert
    cout << kleinster(3, 5, 8) << endl;

    int ergebnis = kleinster(33, 5, 88);
    cout << ergebnis << endl;

    int a;
    a = kleinster(333, 555, 88);
    cout << a << endl;

	return 0;
}
