/// Índice

#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

int main() {
   string nom_fitxer;
   cout << "Indica el nom del fitxer a on està el llibre: ";
   cin >> nom_fitxer;

   /// Fase 1: Omplim l'índex
   ifstream F(nom_fitxer);
   int num = 1;
   string linia;
   vector<string> linies;
   unordered_map<string, vector<int>> index;
   while (getline(F, linia)) {
      linies.push_back(linia);
      istringstream S(linia);
      string par;
      while (S >> par) {
         // Aquí s'hauria de netejar la paraula de signes de puntuació
         // perquè "casa," seria diferent de "casa", per culpa de la coma.
         index[par].push_back(num);
      }
      num++;
   }

   /// Fase 2: Cerca de paraules
   string paraula;
   cout << "Entra una paraula: ";
   while (cin >> paraula) {
      auto it = index.find(paraula);
      if (it != index.end()) {
         for (int i = 0; i < it->second.size(); i++) {
            int num = it->second[i];
            cout << num << ": " << linies[num-1] << endl;
         }
      } else {
         cout << "No s'ha trobat" << endl;
      }
      cout << "Entra una paraula: ";
   }
}