
# Sternenhimmel

## Ziel

Einen Himmel mit Millionen einzelner Sterne zu zeichnen würde viel zu lange dauern. Für unser Spiel helfen wir uns mit dem gleichen Trick, mit dem Filmemacher in den 20'er Jahren Autofahrten dargestellt haben: *wir lassen den Bildschirm wo er ist und ziehen ein Bild mit Sternen dahinter vorbei.* 

### Anforderungen

* Ein Bild mit Sternen bewegt sich rechts nach links.
* Eine Kopie des gleichen Bildes fährt direkt hinterher, damit es einen nahtlosen Übergang gibt.
* Nach einiger Zeit beendet sich das Programm.

### Materialien

* schwarzer Hintergrund `background.png`
* Bild mit Sternen `stars1.png`
* `for`-Schleifen
* Erste Schritte mit SDL (Positionieren von Bildern)

### Für Fortgeschrittene

* Stelle die anderen beiden Sternbilder (`stars2.png` und `stars3.png`) als zusätzliche Ebenen dar. 
* Sorge dafür, daß sich die drei Sternbilder mit mit unterschiedlichen Geschwindigkeiten bewegen. Gib der Ebene mit den kleinsten Sternen die langsamste Geschwindigkeit (Parallax-Effekt).
* Lagere das Zeichnen der Bilder in eine Funktion aus, um den Code zu verkürzen.
