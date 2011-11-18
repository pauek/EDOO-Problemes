
#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

string neteja(string& s) {
   string res;
   string::iterator it = s.begin();
   for (; it != s.end(); it++) {
      const string puntuacio = ".!,";
      if (puntuacio.find(*it) == -1) {
         res += *it;
      }
   }
   return res;
}

void llegeix_llibre(string nom_fitxer, map<string, int>& P) {
   ifstream F;
   F.open(nom_fitxer.c_str());
   string paraula;
   F >> paraula;
   while (!F.eof()) {
      paraula = neteja(paraula);
      map<string, int>::iterator it = P.find(paraula);
      if (it != P.end()) {
         (*it).second++;
      } else {
         P[paraula] = 1;
      }
      F >> paraula;
   }
   F.close();
}

int main() {
   map<string, int> P;
   string nom_fitxer;
   cout << "Llibre? ";
   cin >> nom_fitxer;
   llegeix_llibre(nom_fitxer, P);

   // Omplim una llista de parelles (frequencia, paraula)
   // en aquest ordre.
   list< pair<int, string> > L;
   map<string,int>::iterator it = P.begin();
   for (; it != P.end(); it++) {
      L.push_back(make_pair((*it).second, (*it).first));
   }
   L.sort(); // ordena per frequencia (ascendent)

   // En mostrem 100 començant pel final
   list< pair<int, string> >::reverse_iterator rit = L.rbegin();
   for (int k = 0; k < 100 && rit != L.rend(); k++) {
      cout << (*rit).first << ' ' << (*rit).second << endl;
      rit++;
   }
}
