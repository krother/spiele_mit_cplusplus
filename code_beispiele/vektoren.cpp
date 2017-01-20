#include <vector>
#include <cstddef>
#include <iostream>
using namespace std;

// zu kompilieren mit:
// g++ vektoren.cpp -std=c++11

int main() {
	//
	// Beispiel für Vektoren - arrays mit flexibler Länge
	//

	// einfacher Vektor vom Typ integer
	vector<int> liste {{1, 2, 3, 5, 7}};

    for (unsigned int i=0; i < liste.size(); i++) {
        cout << liste[i] << endl;
    }

    //
    // verschachtelte Vektoren
    //
	using Tabellen_Typ = vector<vector<int>>; // eigenen Typ definieren

	Tabellen_Typ tabelle = {{
		{{1, 2, 3}},
		{{4, 5, 6}},
		{{7, 8, 9}}
	}};

    // ganzen verschachtelten Vektor ausgeben
    for (unsigned int i=0; i < tabelle.size(); i++) {
        for (unsigned int j=0; j < tabelle[i].size(); j++) {
            cout << tabelle[i][j];
        }
        cout << endl;
    }

}