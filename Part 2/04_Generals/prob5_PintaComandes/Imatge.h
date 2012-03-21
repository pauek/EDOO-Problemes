
#ifndef IMATGE_H
#define IMATGE_H

#include <vector>
#include <string>
using namespace std;

struct RGB {
   int r, g, b; // entre 0 i 255 típicament

   RGB() : r(0), g(0), b(0) {}
   RGB(int _r, int _g, int _b) : r(_r), g(_g), b(_b) {}

   void escriu(ostream& o) const;
   void llegeix(istream& i);
};

class Imatge {
   vector<RGB> _pixels;
   int _amplada, _alsada;
public:
   Imatge();
   Imatge(const Imatge& other);
   Imatge(int amplada, int alsada);

   int amplada() const { return _amplada; }
   int alsada()  const { return _alsada; }

   RGB getpixel(int i, int j) const {
      return _pixels[i*_amplada + j];
   }

   void setpixel(int i, int j, RGB valor) {
      _pixels[i*_amplada + j] = valor;
   }

   void linia_h(int j, int i1, int i2, RGB valor);
   void linia_v(int i, int j1, int j2, RGB valor);

   void redimensiona(int amplada, int alsada);

   void escriu(string nomfitxer) const;
   void llegeix(string nomfitxer);
};

#endif // IMATGE_H
