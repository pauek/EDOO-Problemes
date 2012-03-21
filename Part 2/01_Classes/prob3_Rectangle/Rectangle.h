
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <cmath> // per fabs
using namespace std;

class Rectangle {
   float _esq, _dalt, _dre, _baix; 
   int _color;
public:
   Rectangle();
   Rectangle(const Rectangle& altre);
   Rectangle(float es, float da, float dr, float ba, int col);

   float alsada()  const { return fabs(_dalt - _baix); }
   float amplada() const { return fabs(_dre  - _esq);  }
   float area()    const { return amplada() * alsada(); }

   void mou(float dx, float dy);
   void pinta();

   bool a_dins(float x, float y) const;
   bool intersecta(const Rectangle& altre) const;
};

#endif
