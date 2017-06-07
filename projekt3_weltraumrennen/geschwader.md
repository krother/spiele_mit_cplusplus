
# Geschwader

### Ziel

Lasse die unbekannten Flugobjekte in Gruppen

### Anforderungen

* Es kommen nacheinander 3 oder mehr Gruppen von Flugobjekten angeflogen.
* In jeder Gruppe sind 3-10 Objekte.
* Die Gruppen folgen unterschiedlichen Bewegungsmustern.

### Materialien

* Vektoren (siehe auch [www.cplusplus.com/reference/vector/vector/](http://www.cplusplus.com/reference/vector/vector/))
* Komposition von Objekten (Strategy Pattern)

### Hinweise

* Speichere alle Raumschiffe in einem Vektor, so daß sich deren Anzahl leichter verändern läßt.
* Wenn Du den Bewegungspfad als eigene Klasse definierst, kannst Du **Aussehen** und **Bewegungsverhalten** unabhängig voneinander verändern. Damit sind sehr flexible Kombinationen möglich. Dies ist als **Strategy Pattern** bekannt.