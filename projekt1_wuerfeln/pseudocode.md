
# 1.7 Fünferpasch

In diesem Spiel versuchen wir, mit fünf Würfeln die gleiche Zahl zu würfeln. Mit nur einem Wurf bräuchte man sehr viele Versuche, deshalb hat der Spiele mehrere Versuche. Nach jedem Wurf darf der Spieler Würfel auswählen, die nicht weiter gewürfelt werden. Diese sind für den Rest des Spiels gesperrt. Das Spiel endet, sobald alle fünf Würfel das gleiche Ergebnis zeigen oder keine Versuche übrig sind.

### Anforderungen:

* Das Programm würfelt fünf Würfel und gibt sie aus.
* Der Spieler sperrt durch Drücken von `A`, `B`, `C`, `D`, `E` einen Würfel für den Rest des Spiels.
* Andere Tasten würfeln alle nicht gesperrten Würfel erneut.
* Nach 10 Versuchen endet das Spiel.
* Das Spiel endet auch, sobald alle 5 Würfel die gleiche Zahl zeigen.

### Beispielausgabe:

    Würfel zum Sperren auswählen oder x zum Weiterwürfeln: x
    A : 6
    x : 4
    x : 4
    D : 5
    E : 5

    Würfel zum Sperren auswählen oder x zum Weiterwürfeln: x
    A : 4
    x : 4
    x : 4
    D : 4
    E : 1

### Pseudocode

Bevor Du irgend etwas programmierst, notiere die Schritte, die das Programm durchführen muß untereinander in Stichpunkten auf. 

Denke über folgende Fragen nach:

* Welche Variablen sind im Programm notwendig?
* Was passiert in Abhängigkeit von der Eingabe durch den Spieler?
* An welcher Stelle im Programm findet eine Ausgabe statt?
* Wo im Programm gibt es eine Schleife?
* Wo im Programm gibt es Verzweigungen?

Besprich Deine Notizen mit jemand anderem, bevor Du das Programm umsetzt.
