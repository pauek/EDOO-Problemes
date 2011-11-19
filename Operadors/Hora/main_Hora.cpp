
#include <iostream>
using namespace std;

#include "Hora.h"

int main() {
   Hora h;
   cout << h << endl;

   Hora g;
   h += 3725;
   if (g < h) {
      cout << "'g' és anterior a 'h'" << endl;
   } else {
      cout << "'g' és posterior o igual a 'h'" << endl;
   }

   // Diferencia entre hores (sempre positiva)
   Hora r = h - g;
   cout << r << endl;

   r = g - h;
   cout << r << endl;
}
