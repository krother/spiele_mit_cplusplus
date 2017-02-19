#include <stdio.h> 
#include <stdlib.h> 

int main() {

    printf("Der Befehl 'print' ist eine Alternative zu cout.\n");

    printf("Wir können %s definieren.\n", "Platzhalter");

    printf("\nEs gibt verschiedene Platzhalter für verschiedene Datentypen, sowohl %s, und Zahlen (%i und %f).\n", "Text", 7, 7.77);

    printf("%3i \n", 7);
    printf("%6i \n", 7);
    printf("%9i \n", 7);

    printf("\nprintf eignet sich hervorragend für die Ausgabe von Tabellen:\n\n");

    printf("%7s \t %7s \t %7s \t %7s \t %7s\n", "Zahl", "+7", "-7", "*7", "/7");
    printf("--------------------------------------------------------------\n");
    for (int i=1;i<7;i++) {
    	printf("%7i \t      -    \t      -   \t      -   \t %7.2f\n", i, i+7, i-7, i*7, i/7.0);
    }

}

