/*

Repetits
--------

Fes un programa que llegeix un fitxer "reals1.txt" amb una seqüència de reals
i diu si hi ha algun valor repetit.

*/

#include <set>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
   set<double> valors;
   ifstream F("reals1.txt");
   double x;
   bool trobat = false;
   while (!trobat && (F >> x)) {
      if (valors.find(x) != valors.end()) {
         trobat = true;
      } else {
         valors.insert(x);
      }
   }
   if (trobat) {
      cout << "El fitxer conté valors repetits (" << x << ")" << endl;
   } else {
      cout << "No hi ha valors repetits" << endl;
   }
}