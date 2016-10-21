#include "figur.h"

void Figur::position_setzen(int startx, int starty) {
    x = startx;
    y = starty;
}

void Figur::bewegen(char spielfeld[7][7]) {
  // Neue Position ermitteln
  int xneu = x;
  int yneu = y;

  switch(richtung) { 
          case eOBEN: yneu -= 1; break; 
          case eUNTEN: yneu += 1; break; 
          case eLINKS: xneu -= 1; break; 
          case eRECHTS: xneu += 1; break;
  }

  // schauen ob Wand oder Punkt und bewegen
  if (spielfeld[yneu][xneu] != '#') {
      x = xneu;
      y = yneu;
  }
}

