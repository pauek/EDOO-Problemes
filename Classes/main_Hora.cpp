
#include <iostream>
using namespace std;

#include "Hora.h"

int main() {
   Hora h;
   h.escriu(cout);
   cout << endl;

   Hora g;
   h.suma(3725);
   if (g.anterior(h)) {
      cout << "'g' és anterior a 'h'" << endl;
   } else {
      cout << "'g' és posterior o igual a 'h'" << endl;
   }

   Hora r = h.resta(g);
   r.escriu(cout);
   cout << endl;
}
