
# Events in SDL

Die SDL-Bibliothek bringt einen Mechanismus mit, der die Steuerung von Spielen erheblich vereinfacht. Dies sind **Events** (Ereignisse). 

Events können folgendes sein:

* eine Taste wurde gedrückt
* eine Taste wurde losgelassen
* die Maus wurde bewegt
* eine Maustaste wurde gedrückt
* ein interner Timer ist abgelaufen
* das eigene Programm hat ein Event erzeugt.

SDL speichert Events intern in einer *Warteschlange* (Queue). SDL kümmert sich darum, daß die Events in der Schlange landen. Um Events zu verwenden, muß man ab und zu in der Warteschlange nachschauen, ob dort neue Events vorhanden sind. 

Du kannst Dir Events wie eine Warteschlange im Supermarkt vorstellen. Dein Programm ist der Kassierer, die Events sind die Kunden. Die Arten von Events sind die Waren auf dem Förderband. Dein Programm muß also die Events nacheinander abfertigen, und je nach Art des Events etwas bestimmtes tun (scannen, wiegen, Stornoschlüssel rufen).

## Events in einem Programm verwenden

Um Events in einem Programm zu verwenden, mußt Du zunächst eine Event-Variable definieren:

    SDL_Event e;

Dann benötigen wir eine Schleife, um die Events abzufragen:

    int i = 0;
    while(i < 10) {
        while( SDL_PollEvent( &e ) != 0 ) { 

            cout << e.type << endl;    // Typ des Events ausgeben (eine Zahl)
            i++;                       // weiterzählen bis 10
        }
    }

#### Erläuterungen:

* **Damit das Proramm funktioniert, muss zuerst ein SDL-Fenster erstellt werden!**
* Die erste `while`-Schleife läuft, bis 10 Events vearbeitet wurden.
* Die zweite `while`-Schleife holt ein neues Event aus der Warteschlange.

## Abbruch-Events

Das einfachste Event ist `SDL_QUIT`. Es bedeutet, dass das Programm beendet werden soll (z.B. durch Drücken des **x** oben im Fenster). Der folgende Code wartet einfach auf das Abbruchsignal:

    bool ende = false;
    while(!ende) {
        while( SDL_PollEvent( &e ) != 0 ) { 

            if( e.type == SDL_QUIT ) { 
                ende = true;
            }
        }
    }

Es ist eine gute Angewohnheit, das Event `SDL_QUIT` auf jeden Fall zu behandeln. So wirst Du beim Testen Deine Programmfenster leichter wieder los.

## Tastatur-Events

Tastendrücke sind recht einfach zu vearbeiten, da zu jeder Taste eine Integer-Zahl gehört. SDL definiert Platzhalter für alle wichtigen Tasten. Du musst Dir die Zahlen also nicht merken oder sie mühsam herausfinden. Beispielsweise wartet folgender Code auf das Drücken der Leertaste:

    bool ende = false;
    while(!ende) {
        while( SDL_PollEvent( &e ) != 0 ) { 

            if( e.type == SDL_KEYDOWN ) {      // Taste gedrückt
                taste = e.key.keysym.sym;      // speichern, welche Taste es war
                if (taste == SDLK_SPACE) {     // ist es die Leertaste?
                    ende = true;
                }
            }
        }
    }

#### Erläuterungen:

* `SDL_KEYDOWN` steht für das Ereignis *Taste gedrückt*.
* `e.key.keysym.sym` ist der Code der soeben gedrückten Taste.
* `SDLK_SPACE` ist ein Integer, der für die Leertaste steht.

### Was für Tastenkürzel gibt es?

Grundsätzlich ist jeder Taste auf der Tastatur eine Zahl zugeordnet. Da diese ein Integer ist, könnt Ihr sie einfach ausgeben. Die häufigsten Sondertasten sind als Konstanten in SDL gespeichert (z.B. `SDLK_UP` für *Pfeil nach oben*). Du findest alle in einer [riesigen Tabellle](https://wiki.libsdl.org/SDLKeycodeLookup).


## Maus-Events

Die Mausknöpfe abzufragen ist dann auch nicht weiter kompliziert. Du erhälst so die x- und y-Koordinaten der Stelle, an der die Maus gedrückt wurde. Mit `if` kannst Du prüfen, ob die Koordinaten in einem bestimmten Bereich liegen. Folgender Code fragt die Knöpfe innerhalb einer Event-Schleife ab:

    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int x = e.button.x;
        int y = e.button.y; 
        if (x > 50 && x < 100 && y > 50 && y < 100) {
            cout << "Knopf gedrückt!" << endl;
        }
        cout << x << " " << y << endl;
    }

Mit `e.button.button` kannst Du auch herausfinden, welcher Knopf gedrückt wurde. In der Dokumentation zu [SDL_MouseButtonEvent](https://wiki.libsdl.org/SDL_MouseButtonEvent) findest Du dazu Details.

### Was für andere Events gibt es?

SDL kennt eine [Menge Events](https://wiki.libsdl.org/SDL_EventType). Meist genügen aber:

| Event       | Beschreibung |
|-------------|--------------|
| SDL_KEYDOWN | Taste gedrückt |
| SDL_KEYUP   | Taste losgelassen |
| SDL_MOUSEMOTION | Maus bewegt |
| SDL_MOUSEBUTTONDOWN | Mausknopf gedrückt |
| SDL_MOUSEBUTTONUP | Mausknopf losgelassen |
| SDL_QUIT | Schließen-Feld im Fenster geklickt |

Es lohnt sich, auf `SDL_QUIT` zu reagieren. Dann wirst Du das Programm leichter los, falls alles andere nicht funktioniert.

