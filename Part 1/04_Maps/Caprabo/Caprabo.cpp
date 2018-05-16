/// Caprabo

#include <map>
#include <fstream>
using namespace std;

struct Producte {
    int stock, ideal;
};

int main() {
   map<int, Producte> productes;

   /// Fase 1: Llegir inventari
   ifstream I("inventario.txt");
   int codi;
   Producte p;
   while (I >> codi >> p.stock >> p.ideal) {
      productes[codi] = p;
   }

   /// Fase 2: actualitzar inventari
   ifstream V("ventas.txt");
   int unitats;
   while (V >> codi >> unitats) {
      productes[codi].stock -= unitats;
   }

   /// Fase 3: Compres
   ofstream C("compras.txt");
   for (auto it = productes.begin(); it != productes.end(); it++) {
      Producte p = it->second;
      if (p.stock < p.ideal) {
         C << it->first << ' ' << (p.ideal - p.stock) << endl;
      }
   }
}