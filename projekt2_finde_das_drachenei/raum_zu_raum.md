
# Von Raum zu Raum

Auf der Suche nach dem Drachenei passiert der Spieler unterschiedliche Landschaften. In unserem Adventure behandeln wir diese als abgegrenzte *"Räume"*. Im ersten Programm soll der Spieler/die Spielerin sich zwischen den Räumen hin- und herbewegen können. 

Wir setzen die erste Spielversion vollständig textbasiert um.

## Anforderungen

* Die Spielwelt besteht aus mindestens vier 'Räumen'
* Zu jedem Raum wird eine Beschreibung ausgegeben.
* Der Spieler/Die Spielerin gibt über die Tastatur ein, ob in den Raum nach links oder rechts gewechselt werden soll.
* Wird der letzte Raum erreicht, endet das Spiel mit einer Erfolgsmeldung.

## Beispielausgabe

    Du befindest Dich in Deiner Heimatstadt.
    Ein kleine Handelsstadt am Rande der Wüste.

    Wohin möchtest Du gehen ( W / O )? w


    Du gehst nach Westen.

    Du befindest Dich in der Wüste. Die Sonne brennt unbarmherzig.

    Wohin möchtest Du gehen ( W / O )? w


    Du gehst nach Westen.

    Auf einer verborgenen Lichtung entdeckst Du das Drachenei.

    Deine Suche war erfolgreich!    


### Infomaterialien

* Arrays
* `while`-Schleifen
* `if`-Anweisungen


## Schritt für Schritt

### Schritt 1: Lege ein neues Projekt an

* Erstelle ein leeres Projekt in *Code::Blocks* an.
* Erstelle in diesem Projekt eine neue Datei.
* Speichere sie unter dem Namen `drachenei.cpp` ab.


### Schritt 2: Das Grundgerüst

Schreibe die üblichen `include`-Befehle ganz oben in den Quelltext:

    #include <iostream>
    using namespace std;

Dieses benötigen wir für die Textausgabe.

Schreibe anschließend eine `main`-Funktion. Wir geben dort eine Erfolgsmeldung aus.

    int main() {

      // weiterer Code wird hier eingesetzt

      cout << "Du hast das Drachenei gefunden" << endl;
    
      return 0;    // ganz am Ende, beendet das Programm
    }

Sämtlichen weiteren Code kannst Du innerhalb der `main` einsetzen.

**Compiliere das Programm und stelle sicher, dass es läuft.**


### Schritt 3: Die Hauptschleife

Nun kommt das wichtigste Strukturelement des Programms. Die Hauptschleife. Das Spiel soll über so viele *"Runden"* laufen, wie der Spieler benötigt, um das Drachenei zu finden. Wir wissen im Voraus nicht, wie viele das sein werden. Für eine unbekannte Anzahl Wiederholungen eignet sich die `while`-Schleife.

Definiere zuerst eine Variable, die die aktuelle Raumnummer enthält (*diese geht von 0-3. Wir haben noch nichts über die Räume selbst gesagt. Darum kümmern wir uns gleich*). Lege Raum 1 als Startwert fest:

    int position = 1;    // Startraum

Sobald Du Raum 3 erreichst, hast Du das Ei gefunden. Daraus kannst Du eine Bedingung für die `while`-Schleife entwickeln:

    while (position != 3) {

    }

Wenn Du das Programm startest, wird es allerdings in einer Endlosschleife enden und ewig laufen! 

Damit die Bedingung beim `while` irgendwann nicht mehr zutrifft, musst Du also dafür sorgen, dass sich die Position ändert. Du könntest also *innerhalb* der `while`-Schleife den Spieler automatisch in Richtung Drachenei laufen lassen. Dazu erhöhen wir die Position um 1:

    cout << "Du läufst nach Westen" << endl;
    position++;

**Compiliere das Programm und stelle sicher, dass es läuft.**


### Schritt 4: Die Steuerung

Damit nun auch etwas passiert, werden wir Tastatureingaben verwenden. Dazu lesen wir *innerhalb* der `while`-Schleife Buchstaben von der Tastatur:

    cout << "Wohin möchtest Du gehen? [W/O]" << endl;
    char eingabe[10];
    cin >> eingabe;

Uns interessiert nur der erste Buchstabe, also `eingabe[0]`. Jede Eingabe muss genau *einmal* ausgewertet werden. Dazu bietet sich ein `if..else`-Befehl an:

    if (eingabe[0] == 'w') {
      cout << "Du läufst nach Westen" << endl;
      position++;
    }
    else if (eingabe[0] == 'o') {
      // diesen Teil kannst Du selbst einsetzen
    }

Natürlich kannst Du das Erhöhen der Position aus Schritt 3 nun in den `if`-Block verschieben. 

**Compiliere das Programm und stelle sicher, dass es läuft.**


### Schritt 5: Die Räume

Es fehlt noch etwas wichtiges: Im Spiel gibt es noch keine Räume. Das heißt, der Spieler sieht nicht, wo er sich befindet.

Die einfachste Möglichkeit ist, zu jedem Raum einen kurzen Beschreibungstext zu schreiben. Verwende dazu Strings. Füge ganz oben ein weiteres `include` hinzu:

    #include <string>

Nun können wir String-Variablen definieren (innerhalb von `main`, aber vor dem `while`):

    eiswueste = "Du bist in der Eiswüste. Ganz schön kalt hier";
    wueste    = "Die Wüste. So viel Sand...";
    berge     = ..    
    drachenei = ..     // das kannst Du selbst

Um die Räume anzuzeigen, kannst Du natürlich wieder ein `if` verwenden. Zum Ausprobieren ist das eine gute Idee. Setze in die `while`-Schleife ein:

    if (position == 0) {
    	cout << eiswueste << endl;
    }
    if (position == 1) {
    	cout << wueste << endl;
    }
    ..

Was meinst Du? Sollten diese Anweisungen **vor** oder **nach** dem Block mit der Tastatureingabe stehen?

**Compiliere das Programm und stelle sicher, dass es läuft.**

### Schritt 6: Eine Datenstruktur

Jede Position mit `if` einzeln abzufragen, mag bei unseren 4 Räumen ja noch angehen. Stelle Dir vor, wir hätten stattdessen 100 Räume! Für diesen Fall werden wir unsere **Daten strukturieren**. Dazu verwenden wir ein **Array**, eine Liste aus vier Strings. Definiere dieses vor der `while`-Schleife und gib alle vier Räume als Inhalt vor:

    string raeume[4] = {eiswueste, wueste, wald, drachenei};

Der Vorteil des Arrays ist, dass wir die ganzen `if`-Anweisungen durch einen Zugriff auf das Array ersetzen können. Schreibe innerhalb der `while`-Schleife:

    cout << raeume[position] << endl;

Und wirf die `if`-Anweisungen aus Schritt 5 weg.

**Compiliere das Programm und stelle sicher, dass es läuft.**

### Schritt 7: Plausibilitätskontrollen

Im Moment kannst Du noch beliebig weit nach Osten laufen (nach Westen nicht, weil beim Drachenei das Spiel zu Ende ist). Um das zu unterbinden, kannst Du folgende `if`-Anweisung verwenden:

    if (position > 0) {
    	// hier kommt Code hin, den Du schon geschrieben hast.
    } 
    else {
    	cout << "Stop! Hier geht es nicht weiter." << endl;
    }

Finde heraus, an welcher Stelle diese Zeile eingesetzt werden muss.


## Für Fortgeschrittene

* Implementiere eine `struct Raum`. 
* Gib `Raum` die Attribute `name` und `beschreibung`.
* Gib `Raum` das Attribut `ei` vom Typ `bool`.
* Erstelle ein Array (oder einen Vektor) vom Typ Raum.
