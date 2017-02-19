#include <iostream>
using namespace std;


struct Raum {
    char *name;
    char *beschreibung;
    int tueren[4];
};


int main() {

  Raum kueche = {name: "Küche",
                 beschreibung: "Du bist in der Küche. Dein Mitbewohner hat schon wieder nicht abgewaschen.", 
                 tueren: {1, -1, -1, -1}
                };
  
  Raum bad    = {name: "Bad", 
                 beschreibung: "Du bist im Badezimmer. Im Spiegel sieht jemand ganz schön gut aus.",
                 tueren: {0, -1, -1, -1}
                };
  
  Raum haus[2] = {kueche, bad};


  Raum aufenthaltsort = kueche;

  cout << "Dein Aufenthaltsort: " << aufenthaltsort.name << endl;
  cout << aufenthaltsort.beschreibung << endl << endl;
  cout << "Türen führen in folgende Räume:" << endl;
  for (int i=0; i<4; i++) {
      int tuer = aufenthaltsort.tueren[i];
      if (tuer != -1) {
      	  cout << haus[tuer].name << endl;
      }
  }

}

