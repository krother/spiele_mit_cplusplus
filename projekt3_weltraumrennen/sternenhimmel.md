
# Sternenhimmel

## Ziel

Einen Himmel mit Millionen einzelner Sterne zu zeichnen würde viel zu lange dauern. Für unser Spiel helfen wir uns mit dem gleichen Trick, mit dem Filmemacher in den 20'er Jahren Autofahrten dargestellt haben: *wir lassen den Bildschirm wo er ist und ziehen ein Bild mit Sternen dahinter vorbei.* 

### Anforderungen

* Ein Sternenhimmel bewegt sich von rechts nach links.
* Nach einiger Zeit beendet sich das Programm von selbst.

### Materialien

* schwarzer Hintergrund `background.png`
* Bild mit Sternen `stars1.png`
* `for`-Schleifen
* Erste Schritte mit SDL (Positionieren von Bildern)

### Hinweise

* Lies nach, wie Du eine Grafik mit `SDL_BlitSurface` und `SDL_Rect` genau positionieren kannst.
* Es macht nichts, wenn ein Bild halb außerhalb des Fensters liegt.
* Der zweite Parameter von `SDL_BlitSurface` kann auf `NULL` bleiben, nur der vierte ist wichtig.
* Stelle eine zweite Kopie des Sternbildes dar, damit keine Lücken entstehen (eine links, eine rechts)
* Sobald ein Bild links herausgerollt ist, lasse es rechts ausserhalb des Bildschirms wieder hereinrollen.

### Für Fortgeschrittene

* Stelle die anderen beiden Sternbilder (`stars2.png` und `stars3.png`) als zusätzliche Ebenen dar. 
* Sorge dafür, daß sich die drei Sternbilder mit mit unterschiedlichen Geschwindigkeiten bewegen. Gib der Ebene mit den kleinsten Sternen die langsamste Geschwindigkeit (Parallax-Effekt).
* Lagere das Zeichnen der Bilder in eine Funktion aus, um den Code zu verkürzen.
