
# Operatoren

In C++-Anweisungen gibt es eine große Anzahl Sonderzeichen. Viele davon sind **Operatoren**. Hier folgt ein Überblick über die wichtigsten Operatoren.

### Variablenzuweisung

Der Operator `=` weist einen Wert einer Variablen zu. Er kommt in mehreren Varianten vor. Die einfachste ist:

    a = 0;

Dazu muß der Datentyp von `a` aber vorher definiert worden sein. Das läßt sich auch in der gleichen Zeile tun:

    int a = 0;

Statt `int` könnte hier auch ein selbst definierter Datentyp stehen.

Die Variablenzuweisung läßt sich mit den vier Grundrechenarten kombinieren, so daß sich eine kompaktere Schreibweise ergibt. So ist

    a += 3;

das gleiche wie

    a = a + 1;


### Arithmetik

Die Operatoren `+ - * /` sind für die vier Grundrechenarten zuständig.

    a + 2
    a - 3
    a * 4
    a / 5

Soll eine Zahl um 1 verändert werden, tun dies die Operatoren `++` und `--`.

    a++;
    a--;

Der *Modulo-Operator* ergibt den *Rest* einer ganzzahligen Division, z.B.

    10 % 3 ergibt 1
    10 % 5 ergibt 0
     9 % 4 ergibt 4


### Vergleichsoperatoren

In `if`-Ausdrücken und Schleifen können Werte mit den Operatoren `==`, `!=`, `<`, `<=`, `>` und `>=` verglichen werden.

#### Achtung!

Die Operatoren `==` und `=` sind für das Auge leicht zu verwechseln. Glücklicherweise wird der Compiler meist aus dem Kontext erkennen worum es geht und sich beschweren.

### logische Operatoren (and, or, not)

In `if`-Ausdrücken ist es manchmal hilfreich, mehrere Vergleiche zu verknüpfen. Dazu dienen die logischen Vergleichsoperatoren:

* der Operator `&&` steht für ein logisches *und*
* der Operator `||` steht für ein logisches *oder*
* der Operator `!` steht für ein logisches *nicht*

Beispiel:

    if ((monat >= 1) && (monat <= 12) {
        cout << "Diesen Monat gibt es wirklich";
    }
    if ((monat < 1) || (monat > 12) {
    	cout << "Diesen Monat gibt es gar nicht!";
    }
    if (!ende) {
        cout << "Das Spiel geht weiter.";
    }

### Schiebeoperatoren

Der Schiebeoperator `<<` wird für die Ausgabe mittels `cout` verwendet.

Der Schiebeoperator `>>` wird für die Eingabe mittels `cin` verwendet.

Die Schiebeoperatoren lassen sich auch für Binärarithmetik einsetzen, z.B. Verdoppeln und Halbieren von Zahlen. Das ist aber etwas für fortgeschrittene C-Programmierer.


### Zeigeroperatoren (* und &)

Ein `*` nach einem Variablentyp steht für einen sogenannten *Zeiger* (eine Speicheradresse). Damit läßt sich Speicher effizienter verwalten.

    int *lange_liste[100];

Der Operator `&` liefert die Speicheradresse einer beliebigen Variablen, wandelt sie also in einen Zeiger um.

Wir werden Zeiger im Kurs nicht im Detail behandeln, es genügt zu wissen daß es sich um einen Zeiger handelt, sobald Ihr `*` und `&` seht.

