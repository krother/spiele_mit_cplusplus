# Ein Programm schreiben

Um ein Programm in C++ zu schreiben, sind 3 Schritte notwendig

### Schritt 1: Projekt anlegen

* Starte **Eclipse**
* Erstelle ein neues C++-Projekt.
* Gib als Typ des Projekts *C++-Projekt mit MinGW* an.
* Gib dem Projekt einen Namen.
* Eclipse erstellt automatisch ein Verzeichnis für das Projekt.

### Schritt 2: Quelltext schreiben

Erstelle eine neue C++-Datei mit dem Namen `hallo.cpp`. Gib darin folgenden Programmcode ein:

    #include <iostream>
    using namespace std;

    int main() {
        cout &lt;&lt; "Hello World!" &lt;&lt; endl;
        return 0;
    }

Speichere die Datei anschließend ab.

### Schritt 3: Compilieren

Beim Compilieren wandelt ein spezielles Programm (der Compiler) den menschenlesbaren **Quelltext** in für den Computer lesbaren **Maschinencode** um.
Dies ist eigentlich ein recht komplizierter Prozess. Mit Eclipse bekommen wir davon aber nicht sehr viel mit:

* Drücke den Knopf **"Build Project"** in der Symbolleiste oben.
* Achte auf Fehlermeldungen in der Textausgabe.
* Drücke den Knopf **"Play"**, um das fertige Programm auszuführen.
