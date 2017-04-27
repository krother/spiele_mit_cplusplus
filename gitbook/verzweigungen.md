
# Verzweigungen

C++ kennt zahlreiche Anweisungen, die festlegen, in welcher Reihenfolge die Programmbefehle ausgeführt werden. Dazu gehören **Verzweigungen**.

## Verzweigungen mit `if`

Die Anweisung `if` erlaubt, Entscheidungen im Programm zu treffen. 

    char eingabe;
    cin >> eingabe;
    if (eingabe == "A") {
    	cout << "Ein A wurde eingetippt." << endl;
    }

Je nachdem ob die Bedingung in der runden Klammer `true` oder `false` ist, werden die Anweisungen in den geschweiften Klammern ausgeführt oder nicht.

### Alternativen mit `else`

Falls die Bedingung einer `if` Anweisung nicht zutrifft, hast Du die Möglichkeit, mit `else` alternative Anweisungen anzugeben.

    int a = 5;
    if (a < 10) {
    	cout << "Die Zahl ist kleiner als 10" << endl;
    } 
    else {
    	cout << "Die Zahl ist größer oder gleich 10" << endl;

    }

Es ist möglich, direkt nach dem `else` ein weiteres `if` anzuhängen.



## Verzweigungen mit `switch`

Die `switch`-Anweisung wählt abhängig von einem Wert unter mehreren Alternativen aus. Damit funktioniert `switch` etwa wie eine Liste einfacher `if..else`-Anweisungen, ist aber übersichtlicher.

Stell Dir vor, die Variable `zahl` enthält die gewünschte Anzahl von Hauptdarstellern für einen Film. Dann schlägt der folgende Code einen Film vor:

    switch (zahl) {
        case 1: cout << "Kevin allein zu Haus" << endl; break;
        case 2: cout << "Romeo und Julia" << endl; break;
        case 3: cout << "Die Drei Musketiere" << endl; break;
        case 137: cout << "Game of Thrones" << endl; break;
        default: cout << "Frühstück bei Tiffany. Geht immer." << endl;
        break;
    }

Die Anweisung bei `default` wird ausgeführt, falls keine der Alternativen paßt.

**Wichtig:** Nach jeder Alternative muß `break` stehen, sonst werden die nachfolgenden Alternativen auch noch ausgeführt!
