
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

void llegir_llibre(string nom_fitxer, vector<string>& linies) {
   linies.clear();
   ifstream F(nom_fitxer.c_str());
   string linia;
   getline(F, linia);
   while (!F.eof()) {
      linies.push_back(linia);
      getline(F, linia);
   }
}

void construir_index(const vector<string>& linies, 
                     map<string, vector<int> >& index) {
   string paraula;
   for (int i = 0; i < linies.size(); i++) {
      stringstream S(linies[i]);
      S >> paraula;
      while (!S.eof()) {
         // si la paraula hi és, s'afegeix al vector existent
         // si no hi és, es crearà un vector buit i s'afegeix en aquest
         index[paraula].push_back(i);
         S >> paraula;
      }
   }
}

int main() {
   vector<string> linies;
   map< string, vector<int> > index;

   string nom_fitxer;
   cout << "Fitxer? ";
   cin >> nom_fitxer;
   llegir_llibre(nom_fitxer, linies);
   construir_index(linies, index);

   string cerca;
   cout << '>';
   cin >> cerca;
   while (cerca != "FI") {
      map<string, vector<int> >::iterator it = index.find(cerca);
      if (it != index.end()) {
         for (int i = 0; i < (*it).second.size(); i++) {
            int numlinia = (*it).second[i];
            cout << numlinia << ':' << linies[numlinia] << endl;
         }
      } else {
         cout << "No hi ha resultats" << endl;
      }
      cout << '>';
      cin >> cerca;
   }
}
