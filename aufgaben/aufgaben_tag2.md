
# Tag 2: Wie entwickelt man Klassen?

## Kapselung

### Aufgabe 1.1

Findet je ein Beispiel für folgende Begriffe:

* Prototyp
* Zuweisung
* Methodenaufruf
* Zugriff auf Eigenschaften
* Objektinstanzierung
* Kapselung (`public` vs. `private`)

### Aufgabe 1.2

Welche Methoden oder Eigenschaften der Klasse `Spiel` kannst Du als `private` deklarieren, ohne daß die Funktion des Programms beeinträchtigt wird?

### Aufgabe 1.3

Warum ist es sinnvoll, nicht einfach alle Elemente einer Klasse als `public` zu deklarieren?


## 2. Weitere C++ Sprachkonzepte

### Aufgabe 2.1 

Lies Dir den Abschnitt zu Default-Parametern auf **cpp-tutor** durch. Erkläre das Konzept Deinen Teamkollegen.

### Aufgabe 2.2

Baue einen Default-Parameter in die Funktion `feld_fuellen` im Spiel ein.

### Aufgabe 2.3

Erkläre anhand des Programms `ampel.cpp` den Datentyp **enum**.

## 3. Konstruktoren

### Aufgabe 3.1

Lies Dir die ersten drei Abschnitte des Kapitels zu Konstruktoren bei cpp-tutor durch. Erkläre das Konzept Deinen Teamkollegen.

### Aufgabe 3.2

Schreibe einen Konstruktor für die `Spiel` Klasse, der die Fenstergröße, Fensterposition und Spielfeldgröße als Parameter annimmt.


## 4. Neue Klassen identifizieren

### Aufgabe 4.1 

Führe eine **Lexikalische Analyse** durch: Formuliert einen kurzen Text über das geplante Spiel. Schickt den Text zu wordle.com um die häufigsten Wörter herauszubekommen. Diskutiert welche der Wörter sich als Namen von Klassen eignen.

### Aufgabe 4.2

Plane das Spiel in eine Klasse `Spieler` und eine Klasse `Level` zu zerlegen. Überlege im Voraus wofür die Klassen verantwortlich sein sollen.

### Aufgabe 4.3

Implementiere die Klasse `Level`. Schreibt die Klasse so, daß man über den Konstruktor verschiedene Level-Objekte mit unterschiedlichem Aussehen erzeugen kann.

### Aufgabe 4.4

Erstelle ein Level mit Wänden und Punkten als String, z.B.:

    #######
    #..#..#
    ##...##
    #..#..#
    #######

Tauscht die fertigen Levels im Team aus, so daß jeder 4-5 unterschiedliche Levels hat. 

### Aufgabe 4.5

Implementiere die `Spieler`-Klasse. 

Die Methoden der Spieler-Klasse müssen auf das Level zugreifen können. 

### Aufgabe 4.6

Implementiere die *"Wände"*.

### Aufgabe 4.7

Implementiere die *"freßbaren Punkte"*


## 5. UML

### Aufgabe 5.1

Implementiere die Klasse `PunkteZaehler`, die über die gefressenen Punkte Buch führen soll. 

![UML Klassendiagramm](uml_punkte.png)


### Aufgabe 5.2

Zeichne ein UML-Diagramm aller Klassen im Spiel.


## 6. Zufallslevels

**ZUSATZAUFGABE**

Betrachte die Datei `generate_maze.py`. Sie enthält den in Python geschriebenen Prototyp eines Level-Generators. Setze den Algorithmus in C++ um.
