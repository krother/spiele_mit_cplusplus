// 'Hello World!' program 

#include <iostream>
using namespace std;

int main() {
  string name;
  cout << "Bitte gib Deinen Namen ein: ";
  cin >> name;
  string out = "Hallo " + name;
  cout << out << endl;
  return 0;
}
