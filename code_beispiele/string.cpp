/*
Beispiel Strings verwenden

siehe auch: http://www.cplusplus.com/reference/string/string/
*/
#include <iostream>
using namespace std;

int main() {
	
	string text1 = "abcde";
	string text2 = "fghij";

    cout << text1 << endl;

    string text3 = text1 + text2;
    cout << text3 << endl;

    cout << text3.at(4) << endl;

    cout << text3.substr(4, 8) << endl;

    cout << text3.length() << endl;

}