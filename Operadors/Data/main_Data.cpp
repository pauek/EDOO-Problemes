
#include <iostream>
#include <sstream>
using namespace std;

#include "Data.h"

int main() {
   Data d;
   cout << d << endl;
   
   Data e(d);
   ++e;
   cout << e << endl;

   ++d;
   if (d == e) {
      cout << "'d' i 'e' són iguals" << endl;
   } else {
      cout << "'d' i 'e' no són iguals" << endl;
   }

   istringstream S("31/12/2011");
   Data f;
   S >> f;
   ++f;
   cout << f << endl;
}
