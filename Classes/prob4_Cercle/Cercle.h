
#ifndef CERCLE_H
#define CERCLE_H

#include <cmath>
using namespace std;

class Cercle {
   float _xcen, _ycen, _radi;
   int _color;
public:
   Cercle();
   Cercle(const Cercle& altre);
   Cercle(float xc, float yc, float r, int c);

   float radi() const { return _radi; }
   float area() const { return M_PI * M_PI * _radi; }

   void mou(float dx, float dy);
   void pinta() const;
   
   bool a_dins(float x, float y) const;
   bool intersecta(const Cercle& c) const;
};

#endif
