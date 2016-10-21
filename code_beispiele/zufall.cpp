#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


int main() {

  srand(time(NULL));
  //srand(777);

  for (int i; i < 10; i++) {
    int r = rand() % 10;
    cout << r << endl;
  }
  
}

