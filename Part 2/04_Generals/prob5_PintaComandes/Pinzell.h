
#ifndef PINZELL_H
#define PINZELL_H

#include "Imatge.h"

class Pinzell {
   int _x, _y;
   RGB _color;
   bool _pintant;
   Imatge& _I;
public:
   Pinzell(Imatge& I);

   void pinta(bool p) { _pintant = p; }
   void color(RGB p)  { _color = p; }

   void horiz(int n);
   void vert(int n);
};

#endif
