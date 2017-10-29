#include <iostream>
using namespace std;

int main() {

    const string namen[3] = {
	    "Hisham",
	    "Aysha",
	    "Sarah",
    };

    bool name_gefunden = false;

    int position = 0;
    while (!name_gefunden) {
    	cout << "ist Dein Name " << namen[position] << "? (J/N)" << endl;
    	char antwort;
    	cin >> antwort;
    	if (antwort == 'j' || antwort == 'J') {
    		name_gefunden = true;
    	}
    	else {
    		position = position + 1;
    	}
    }

    cout << "Hallo " << namen[position] << "!" << endl;

}
