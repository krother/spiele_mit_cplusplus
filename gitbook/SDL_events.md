
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

Dann benötigen wir eine Schleife, um die Events abzufertigen:

    bool ende = false;
    while(!ende) {
        while( SDL_PollEvent( &e ) != 0 ) { 
            if( e.type == SDL_KEYDOWN ) { 
                taste = e.key.keysym.sym;
                if (taste == SDLK_SPACE) {
                	ende = true;
                }
            }
        }
    }

#### Erläuterungen:

* **Damit das Proramm funktioniert, muß ein SDL-Fenster erstellt werden!**
* Die erste `while`-Schleife wartet, bis die Leertaste gedrückt wird. Die zweite holt ein neues Event aus der Warteschlange.
* `SDL_KEYDOWN` steht für das Ereignis *Taste gedrückt*.
* `e.key.keysym.sym` ist der *"Inhalt"* des Events, die Information welche Taste gedrückt wurde.
* `SDLK_SPACE` ist ein Integer, der für die Leertaste steht.

### Wie kann ich die Taste ausgeben?

Um die eingelesene Taste auszugeben, brauchst Du die Funktion `printf`. `cout` funktioniert mit SDL nicht überall:

    #include <stdlib.h> 
    ..
    printf("%i\n", taste);


### Was für Events gibt es?

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


### Was für Tastenkürzel gibt es?

Grundsätzlich ist jeder Taste auf der Tastatur eine Zahl zugeordnet. Da diese ein Integer ist, könnt Ihr sie einfach ausgeben. Die häufigsten Sondertasten sind als Konstanten in SDL gespeichert (z.B. `SDLK_UP` für *Pfeil nach oben*). Du findest alle in einer [riesigen Tabellle](https://wiki.libsdl.org/SDLKeycodeLookup).

