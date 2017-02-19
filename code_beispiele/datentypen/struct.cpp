#include <iostream>
using namespace std;

struct Kachel {
   int x;
   int y;
};

int main() {

  // Kachel kachel_ratte = {5, 1};
  Kachel kachel_ratte = {x:5, y:1};

  //kachel_ratte.x = 5;
  //kachel_ratte.y = 1;
 
  cout << kachel_ratte.x << "/" << kachel_ratte.y << endl;

}

