
# SDL-Programme unter Eclipse compilieren

Um die Bibliothek SDL in einem Eclipse-Projekt zu verwenden, führe die folgenden Schritte durch:

1. Starte Eclipse
2. Lege ein neues MinGW-C++ Projekt an
3. Erstelle eine neue C++-Datei (Source File)
4. Schreibe den Quelltext in die neue Datei
5. Sage Eclipse, wo die Header-Dateien zu finden sind:

    füge im Dialog:
    Project -> Properties -> C++ Build -> Settings -> C++ Compiler
    zum Eingabefeld **Includes** das Verzeichnis `includes/SDL2` hinzu
    (je nachdem wo dieses auf dem Rechner liegt)

6. Sage Eclipse, welche Bibliotheken nötig sind:

    füge im Dialog:   
    Project -> Properties -> C++ Build -> Settings -> MinGW C++ Linker

    zu **Libraries** die 4 Einträge hinzu:
    
    * mingw32
    * SDL2main
    * SDL2
    * SDL2_image

    zu **Library Search path** das Verzeichnis `lib/` hinzu
    (je nachdem wo dieses auf dem Rechner liegt)

7. Kopiere die Bilder ins Projektverzeichnis unter `sahelXX_bk7/Workspace`
8. Kopiere die DLLs ins Projektverzeichnis unter `sahelXX_bk7/Workspace`
9. Compiliere das Programm (Hammer-Symbol)
10. Führe das Programm aus (Play-Symbol)

