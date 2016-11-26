#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

// Beispielprogramm: Durchs Haus laufen

// eigenen Datetyp fuer Raeume erstellen
struct Raum {
    string name;
    string beschreibung;
    int tueren[4];
};


int main() {

  // Variablen mit dem neuen Datentyp erstellen
  Raum kueche = {name: "Küche",
                 beschreibung: "Du bist in der Küche. Dein Mitbewohner hat schon wieder nicht abgewaschen.", 
                 tueren: {1, 2, -1, -1}  // Indices von anderen Zimmern
                };  
  Raum bad    = {name: "Bad", 
                 beschreibung: "Du bist im Badezimmer. Im Spiegel sieht jemand ganz schön gut aus.",
                 tueren: {0, -1, -1, -1}
                };
  Raum wohnzimmer = {name: "Wohnzimmer", 
                 beschreibung: "Du bist im Wohnzimmer. Dein Mitbewohner haengt auf der Couch herum.",
                 tueren: {0, 3, 4, -1}
                };
  Raum balkon = {name: "Balkon", 
                 beschreibung: "Du stehst auf dem Balkon. Deine Nachbarin ist nicht zu Hause.",
                 tueren: {2, -1, -1, -1}
                };
  Raum ausgang = {name: "Ausgang", 
                 beschreibung: "Du bist nach draußen frische Luft schnappen.",
                 tueren: {2, -1, -1, -1}
                };
  
  Raum haus[5] = {kueche, bad, wohnzimmer, balkon, ausgang};

  Raum aufenthaltsort = kueche;
  int raumnr = 0;

  // jetzt koennen wir durchs Haus laufen bis wir den Ausgang finden
  while (raumnr != 4) {
      cout << "Dein Aufenthaltsort: " << aufenthaltsort.name << endl;
      cout << aufenthaltsort.beschreibung << endl << endl;
      cout << "Türen führen in folgende Räume:" << endl;

      // Auswahlmenue ausgeben
      for (int i=0; i<4; i++) {
          int tuer = aufenthaltsort.tueren[i];
          if (tuer != -1) {
		          Raum ziel = haus[tuer];
              cout << "[" << tuer << "] " << ziel.name << endl; 
          }
      }
      // Eingabe einlesen
      char eingabe[10];
      cout << endl << "Wohin gehst Du? "; 
      cin >> eingabe;
      int auswahl = atoi(eingabe);  // int fuer Index benoetigt

      // ausgewaehltes Ziel ermitteln
      for (int i=0; i<4; i++) {
          // pruefen ob gueltige Tuer existiert
          if (aufenthaltsort.tueren[i] == auswahl) {
              aufenthaltsort = haus[auswahl];
              raumnr = auswahl;
          }
      }
  }

  // Haus wird verlassen, noch den Ausgang ausgeben
  cout << "Dein Aufenthaltsort: " << aufenthaltsort.name << endl;
  cout << aufenthaltsort.beschreibung << endl << endl;
}

