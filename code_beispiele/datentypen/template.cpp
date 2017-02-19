
#include <iostream>
using namespace std;

template <typename T>
void n_mal_ausgeben(T obj1, char sep, int anzahl) {
	for (int i=0;i < anzahl;i++) {
		cout << obj1 << sep;
	}
	cout << endl;
}


int main() {
    n_mal_ausgeben("##########", '\n', 10);
    n_mal_ausgeben(3, ' ', 5);
    n_mal_ausgeben('A', 'B', 7);

}

