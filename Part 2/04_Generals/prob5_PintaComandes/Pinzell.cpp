
#include "Pinzell.h"
#include "Imatge.h"

Pinzell::Pinzell(Imatge& I)
  : _I(I)
{
   _x = 0;
   _y = 0;
   _pintant = false;
   _color = RGB(255, 255, 255);
}

void Pinzell::horiz(int n) {
   if (_pintant) {
      _I.linia_h(_y, _x, _x + n, _color);
   }
   _x += n;
}

void Pinzell::vert(int n) {
   if (_pintant) {
      _I.linia_v(_x, _y, _y + n, _color);
   }
   _y += n;
}
