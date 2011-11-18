
#include "Rectangle.h"
#include "miniwin.h"
using namespace miniwin;

Rectangle::Rectangle() {
   _esq  = 0.0;
   _dalt = 0.0;
   _dre  = 0.0;
   _baix = 0.0;
   _color = BLANCO;
}

Rectangle::Rectangle(const Rectangle& altre) {
   _esq   = altre._esq;
   _dalt  = altre._dalt;
   _dre   = altre._dre;
   _baix  = altre._baix;
   _color = altre._color;
}

Rectangle::Rectangle(float es, float da, float dr, float ba, int c) {
   _esq   = es;
   _dalt  = da;
   _dre   = dr;
   _baix  = ba;
   _color = c;
}

void Rectangle::mou(float dx, float dy) {
   _esq  += dx;
   _dre  += dx;
   _dalt += dy;
   _baix += dy;
}

void Rectangle::pinta() {
   color(_color);
   rectangulo_lleno(_esq, _dalt, _dre, _baix);
}

bool Rectangle::a_dins(float x, float y) const {
   return (x >= _esq && x <= _dre) && (y >= _baix && y <= _dalt);
}

bool Rectangle::intersecta(const Rectangle& altre) const {
   return 
      ! altre.a_dins(_esq, _dalt) && ! altre.a_dins(_esq, _baix) &&
      ! altre.a_dins(_dre, _dalt) && ! altre.a_dins(_dre, _baix);
}



