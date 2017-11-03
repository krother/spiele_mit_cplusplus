
// überladene Funktionen

#include <iostream>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int max(int a, int b, int c) {
    return max(a, max(b, c));
}

int max(int a, int b, int c, int d) {
    return max(a, max(b, max(c, d)));
}

int main() {

	cout << max(3, 4) << endl;
	cout << max(33, 4, 5) << endl;
	cout << max(3, 4, 5, 66) << endl;

}
