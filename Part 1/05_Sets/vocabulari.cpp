/*

Vocabulari
----------

Fes un programa que, donat el text d'un llibre al fitxer "llibre.txt" (pots
suposar que és una seqüència de paraules), crea un fitxer "vocabulari.txt" amb
el llistat de totes les paraules que apareixen en el llibre, una per línia.

*/

#include <set>
#include <fstream>
using namespace std;

int main() {
   ifstream fllibre("llibre.txt");
   string paraula;
   set<string> vocab;
   while (fllibre >> paraula) {
      vocab.insert(paraula);
   }
   ofstream fvocab("vocabulari.txt");
   for (auto it = vocab.begin(); it != vocab.end(); it++) {
      fvocab << *it << endl;
   }
}