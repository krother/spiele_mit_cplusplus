
# Kontrollfluß

C++ kennt zahlreiche Anweisungen, die festlegen, in welcher Reihenfolge die Programmbefehle ausgeführt werden.

## Entscheidungen mit `if`

Die Anweisung `if` erlaubt, Entscheidungen im Programm zu treffen. 

    char eingabe;
    cin >> eingabe;
    if (eingabe == "A") {
    	cout << "Ein A wurde eingetippt." << endl;
    }

Je nachdem ob die Bedingung in der runden Klammer `true` oder `false ist, werden die Anweisungen in den geschweiften Klammern ausgeführt oder nicht.

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


## Bedingte Schleifen

Mit Schleifen können Anweisungen wiederholt werden. 

### Schleifen mit `do..while`

Die `do..while` Schleife wiederholt Anweisungen, solange die Bedingung am Ende wahr ist. Die Schleife wird mindestens ein Mal ausgeführt.

    int a = 10;
    do {
        cout << "Countdown ist bei: " << a << endl;
        a = a - 1;
    } while (a > 0);

Es ist wichtig, daß die Variable in der Bedingung (`a`) *außerhalb* der Schleife definiert wird.

### Schleifen mit `while`

es geht auch umgekehrt. Bei einer `while`-Schleife steht die Bedingung am Anfang. Daher kann es sein, daß eine `while`-Schleife kein Mal ausgeführt wird.

    int a = 10;
    while (a > 0) {
        cout << "Countdown ist bei: " << a << endl;
        a = a - 1;
    }

#### Achtung!

Mit `do..while` und `while` ist es möglich, Endlosschleifen zu bauen. Ein häufiger Fehler ist, die Variable für die Abbruchbedingung zu vergessen. Folgendes Programm läuft ewig weiter:

    int a = 10;
    while (a > 0) {
        cout << "Countdown ist bei: " << a << endl;
    }


## `for`-Schleifen

Schleifen mit `for` haben statt einer Bedingung eine *Zählervariable*. Mit `for`-Schleifen kannst Du Anweisungen eine bestimmte Anzahl von Malen wiederholen.

    for (int i=0; i < 10; i++) {
    	cout << "Zahl: " << i << endl;
    }

Der Ausdruck in der runden Klammer beim `for` bedeutet folgendes:

1. Zu Beginn der Schleife setze die Zählervariable `i` auf 0.
2. Die Schleife soll so lange laufen, wie `i` kleiner als 10 ist.
3. Nach jedem Schleifendurchlauf, erhöhe `i` um 1. (Der Operator `++` tut das gleiche wie `i=i+1`)


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
