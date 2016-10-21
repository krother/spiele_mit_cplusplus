
//
// new und delete
// 
// http://www.cpp-tutor.de/cpp/le11/new_delete.html
//
#include <iostream>
using namespace std;


void ausgabe(int *array, int laenge) {
  for (int i=0; i<laenge; i++) {
    array[i] = i * 2;
    cout << array[i] << endl;
  } 
}

int main() {

  int *zahlen;
  zahlen = new int[5];
  ausgabe(zahlen, 5);  
  delete zahlen;
  zahlen = NULL; 
  ausgabe(zahlen, 5);  

  cout << endl;

  zahlen = new int[10];
  ausgabe(zahlen, 10);  
  delete zahlen; 

}

