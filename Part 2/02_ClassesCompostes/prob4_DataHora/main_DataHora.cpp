
#include <iostream>
#include "DataHora.h"
using namespace std;

int main() {
   DataHora d;
   d.incr_dies(5);
   DataHora e(d);
   d.escriu(cout); cout << endl;
   e.incr_segons(50000);
   e.escriu(cout); cout << endl;

   DataHora f(2010, 12, 31, 23, 59, 59);
   DataHora g(f);
   f.escriu(cout); cout << endl;
   f.incr_segons(1);
   f.escriu(cout); cout << endl;
   if (g.anterior(f)) {
      cout << "'g' anterior a 'f'" << endl;
   } else {
      cout << "'g' posterior o igual a 'f'" << endl;
   }
}
