
#include "DiaSetmana.h"

const string _dies[7] = {
   "dilluns", "dimarts", "dimecres", "dijous", "divendres", 
   "dissabte", "diumenge"
}

DiaSetmana::DiaSetmana(string dia) {
   for (int i = 0; i < 7; i++) {
      if (_dies[i] == dia) {
         _n = i;
         return;
      }
   }
   cout << "Dia '" << dia << "' desconegut" << endl;
   _n = 0;
}

DiaSetmana::mostra(ostream& o) const {
   o << _dies[_n];
}


