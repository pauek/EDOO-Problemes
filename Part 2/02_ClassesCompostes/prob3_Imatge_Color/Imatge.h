#ifndef IMATGE_H
#define IMATGE_H

#include <vector>
#include <string>
using namespace std;

struct Pixel {
   int r, g, b; // entre 0 i 255 típicament

   void inverteix();
   void binaritza();
   void afegir_soroll(int max);

   void escriu(ostream& o) const;
   void llegeix(istream& i);
};

class Imatge {
   vector<Pixel> _pixels;
   int _amplada, _alsada;
public:
   Imatge();
   Imatge(const Imatge& other);
   Imatge(int amplada, int alsada);

   int amplada() const { return _amplada; }
   int alsada()  const { return _alsada; }

   Pixel getpixel(int i, int j) const {
      return _pixels[i*_amplada + j];
   }

   void setpixel(int i, int j, Pixel valor) {
      _pixels[i*_amplada + j] = valor;
   }

   void redimensiona(int amplada, int alsada);
   void afegir_soroll(int max);
   void inverteix();
   void binaritza();

   void escriu(string nomfitxer) const;
   void llegeix(string nomfitxer);
};

#endif // IMATGE_H
