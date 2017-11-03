// Beispiel für den Datentyp enum
#include <iostream>
using namespace std;


int main()
{
   /*
   Ein enum ist eine Aufzählung.
   Wir definieren, welche Werte erlaubt sind.
   */
   enum eSymbol {Schere, Stein, Papier};

   // Nun können wir Variablen mit diesem Typ anlegen:
   eSymbol spieler1=Schere;
   eSymbol spieler2=Stein;

   /*
   Was ist der Vorteil von enums?

   Wir könnten natürlich auch Integers verwenden
   (z.B. 0=Schere, 1=Stein, 2=Papier)
   Dann kommt es aber sehr leicht vor,
   dass jemand aus Versehen den Wert 3 verwendet,
   und das Programm unvorhergesehene Fehler begeht.
   */

   // Vergleiche
   if ((spieler1==Schere && spieler2==Stein) ||
       (spieler1==Stein && spieler2==Papier) ||
       (spieler1==Papier && spieler2==Schere)) {
      cout << "Spieler 2 gewinnt" << endl;
   }
   else if (spieler1 == spieler2) {
      cout << "Unentschieden!" << endl;
   }
   else {
      cout << "Spieler 1 gewinnt" << endl;
   }
}
