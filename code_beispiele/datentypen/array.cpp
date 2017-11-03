
#include <iostream>
using namespace std;

int main() {

    // Deklaration
    int zahlen[5];

    // Werte direkt zuweisen
    zahlen = {2, 3, 5, 8, 13};

    // schreiben über Index
    zahlen[0] = 1;
    zahlen[1] = 4;
    zahlen[2] = 9;
    zahlen[3] = 16;
    zahlen[4] = 25;

    // wieder auslesen;
    for (int i=0; i<5; i++) {
    	cout << zahlen[i] << endl;
    }

}
