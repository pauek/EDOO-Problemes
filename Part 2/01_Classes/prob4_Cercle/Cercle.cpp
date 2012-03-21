
#include "miniwin.h"
using namespace miniwin;

#include "Cercle.h"

Cercle::Cercle() {
   _xcen = 0.0;
   _ycen = 0.0;
   _radi = 0.0;
   _color = BLANCO;
}

Cercle::Cercle(const Cercle& altre) {
   _xcen  = altre._xcen;
   _ycen  = altre._ycen;
   _radi  = altre._radi;
   _color = altre._color;
}

Cercle::Cercle(float xc, float yc, float radi, int col) {
   _xcen = xc;
   _ycen = yc;
   _radi = radi;
   _color = col;
}

void Cercle::mou(float dx, float dy) {
   _xcen += dx;
   _ycen += dy;
}

void Cercle::pinta() const {
   color(_color);
   circulo(_xcen, _ycen, _radi);
}

bool Cercle::a_dins(float x, float y) const {
   float dx = x - _xcen, dy = y - _ycen;
   return sqrt(dx*dx + dy*dy) < _radi;
}

bool Cercle::intersecta(const Cercle& altre) const {
   float dx = _xcen - altre._xcen, dy = _ycen - altre._ycen;
   return sqrt(dx*dx + dy*dy) < (_radi + altre._radi);
}


