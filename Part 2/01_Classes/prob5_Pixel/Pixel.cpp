
#include "Pixel.h"
#include <algorithm> // std::max i std::min
using namespace std;

Pixel::Pixel() {
   _r = 0;
   _g = 0;
   _b = 0;
}

Pixel::Pixel(const Pixel& P) {
   _r = P._r;
   _g = P._g;
   _b = P._b;
}

Pixel::Pixel(float r, float g, float b) {
   _r = r;
   _g = g;
   _b = b;
}

float Pixel::luminancia() const {
   return (_r + _g + _b) / 3; // divisió entera
}

float Pixel::saturacio() const {
   float mx = max(_r, max(_g, _b)); // fa servir std::max
   float mn = min(_r, min(_g, _b)); // fa servir std::min
   if (mx == 0.0) {
      return 0.0;
   } else {
      return 1.0 - mn/mx;
   }
}

Pixel Pixel::mescla(const Pixel& altre) const {
   float r = (_r + altre._r) / 2.0;
   float g = (_g + altre._g) / 2.0;
   float b = (_b + altre._b) / 2.0;
   Pixel nou(r, g, b);
   return nou;
}
