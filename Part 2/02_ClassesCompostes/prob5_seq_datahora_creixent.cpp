
#include <iostream>
#include <fstream>
using namespace std;

#include "DataHora.h"

int main() {
   ifstream F("dates.txt");
   bool creix = true;
   DataHora d, ud;
   ud.llegeix(F);
   d.llegeix(F);
   while (!F.eof() && creix) {
      if (ud.posterior(d)) {
         creix = false;
      } else {
         ud = d;
         d.llegeix(F);
      }
   }
   if (creix) {
      cout << "És creixent" << endl;
   } else {
      cout << "NO és creixent" << endl;
   }
}
