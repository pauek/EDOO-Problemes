
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

#include "Data.h"

class Mitjana {
   double total;
   int cont;
public:
   Mitjana() { 
      total = 0.0; 
      cont = 0; 
   }
   
   void afegeix(double x) {
      total += x;
      cont++;
   }

   double mitjana() const {
      return total / double(cont);
   }
};

Data enter_a_data(int data) {
   // posem 0 a l'any perquè sempre sigui el mateix
   return Data(data % 100, (data % 10000) / 100, 0);
}

int main() {
   map<Data, Mitjana> T;
   char coma;
   int data;
   double t;

   ifstream F("McGuireAFB.csv");
   
   F >> data >> coma >> t;
   while (!F.eof()) {
      T[enter_a_data(data)].afegeix(t);
      F >> data >> coma >> t;
   }

   map<Data, Mitjana>::iterator it = T.begin();
   for (; it != T.end(); it++) {
      cout << it->first.dia() << '/' << it->first.mes() 
           << ": " << it->second.mitjana() << endl;
   }
}
