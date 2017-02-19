// Beispiel zum enum Datentyp

// Dateien einbinden
#include <iostream>

using std::cout;
using std::endl;

// main() Funktion
int main()
{
   // enum-Variable definieren und initialisieren
   enum eAMPEL {eROT1, eROTGELB, eGRUEN, eGELB, eROT2};
   eAMPEL eAmpel=eROT1;

   // Alle Ampelphasen durchlaufen
   do
   {
      // Aktuelle Ampelphase auswerten, den entsprechenden Text
      // ausgeben und nächste Ampelphase aufschalten
      switch (eAmpel)
      {
      case eROT1:
      case eROT2:
         cout << "Die Ampel hat rot!\n";
         if (eAmpel == eROT1)
            eAmpel = eROTGELB;
         else
            eAmpel = eROT1;
         break;
      case eROTGELB:
         cout << "Die Ampel hat rot-gelb\n";
         eAmpel = eGRUEN;
         break;
      case eGRUEN:
         cout << "Die Ampel hat grün\n";
         eAmpel = eGELB;
         break;
      case eGELB:
         cout << "Die Ampel hat gelb\n";
         eAmpel = eROT2;
         break;
      }
   } while (eAmpel != eROT1);
}
