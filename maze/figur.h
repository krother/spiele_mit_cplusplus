#ifndef _add_figur_
#define _add_figur_

enum eRICHTUNG {eLINKS, eRECHTS, eOBEN, eUNTEN};


class Figur {
  public: int x, y;
          eRICHTUNG richtung;
  public: void position_setzen(int, int);
          void bewegen(char[7][7]);
};

#endif

