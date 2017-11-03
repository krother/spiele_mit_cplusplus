
# Spezialaufträge für Fortgeschrittene

## 1. Funktionen

Probiere folgende Features von Funktionen in C++ aus (Beispielcode vorhanden):

### 1.1 überladene Funktionen

Probiere das Codebeispiel aus.

Ist es möglich, über optionale Paramter zwei Funktionen mit überlappender Signatur zu deklarieren? Beispielsweise:

    int max(int a, int b, int c=3);

    int max(int a, int b, int c);


### 1.2 inline-Funktionen

Was passiert während der Compilierung mit dem Schlüsselwort `inline`?

Wie kannst Du messen, wie groß der Geschwindigkeitsvorteil von `inline` ist.
(Falls `gprof` installiert ist, prüfe ob sich das Tool dafür eignet).

### 1.3 lambda-Funktionen

Was tut das Schlüsselwort `auto`?


### 1.4 Template-Funktionen

Welche Optionen hast Du, um im Programm `template_mit_lambda.cpp`, die Länge des Arrays im Template dynamisch festzulegen?


## 2. Maussteuerung

Entwickle ein Modul, das eine Maussteuerung für das Adventure bereitstellt.

### 2.1 Schnittstellendesign

Entwerfe eine Schnittstelle für das Modul. Es soll zwei Operationen bereitstellen:

* Eine Funktion um Knöpfe mit Pfeilen zum Bewegen und Benutzen zu zeichnen.
* Eine Funktion, um einen Befehl zu generieren. Es sollen drei Werte möglich sein: LINKS, RECHTS und BENUTZEN.

**Frage:** Eignet sich aus Deiner Sicht die Implementierung als Klasse oder als Funktionen besser?


### 2.2 Implementierung

Implementiere die Funktionen. Weise nach, daß sie funktionieren.

* Wie würdest Du vorgehen, wenn Du die Mauskommandos automatisch testen möchtest? Was läßt sich testen, was nicht?
* Wirf einen Blick auf das Paket [Boost.test](https://accu.org/index.php/journals/1326). Ließe es sich hier sinnvoll anwenden? (entscheide selbst, ob sich der Aufwand lohnt, einen automatischen Test auch tatsächlich zu implementieren).


### 2.3 Refaktorisierung

Lagere die Funktionalität über eine Header-Datei in ein separates Modul aus.

* Was ist beim Verwenden einer Header-Datei zu beachten?
* Was bedeutet die Phrase `#pragma once` und warum ist sie sinnvoll?


### 2.4 Auslieferung

* Ermögliche einem anderen Kursteilnehmer, Deine Maussteuerung zu verwenden.
* Welche Schritte sind zum Einbinden Deines Moduls notwendig?
* Welche Probleme treten dabei auf?
* Wie ließen sich diese lösen?


## 3. Weiterführende Fragen

### 3.1 C++-Standards

 Was sind die wesentlichen Unterschiede zwischen den C++-Standards `C++11` und `C++14`? Erstelle eine kurze tabellarische Übersicht.

### 3.2 STL

Verschaffe Dir einen Überblick über die STL (Standard Template Library). Welchen Typen aus anderen Dir bekannten Programmiersprachen entsprechen die bereitgestellten Templates.


