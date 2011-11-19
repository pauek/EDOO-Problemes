
#include <iostream>
#include "DataHora.h"
using namespace std;

int main() {
   DataHora d;
   d.incr_dies(5);
   DataHora e(d);
   cout << d << endl;
   e += 50000;
   cout << e << endl;

   DataHora f(2010, 12, 31, 23, 59, 59);
   DataHora g(f);
   cout << f << endl;
   ++f;
   cout << f << endl;
   if (g < f) {
      cout << "'g' anterior a 'f'" << endl;
   } else {
      cout << "'g' posterior o igual a 'f'" << endl;
   }
}
