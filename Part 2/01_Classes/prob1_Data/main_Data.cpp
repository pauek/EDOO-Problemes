
#include <iostream>
#include <sstream>
using namespace std;

#include "Data.h"

int main() {
   Data d;
   d.escriu(cout);
   cout << endl;
   
   Data e(d);
   e.incrementa();
   e.escriu(cout);
   cout << endl;

   d.incrementa();
   if (d.igual(e)) {
      cout << "'d' i 'e' són iguals" << endl;
   } else {
      cout << "'d' i 'e' no són iguals" << endl;
   }

   istringstream S("31/12/2011");
   Data f;
   f.llegeix(S);
   f.incrementa();
   f.escriu(cout);
   cout << endl;
}
