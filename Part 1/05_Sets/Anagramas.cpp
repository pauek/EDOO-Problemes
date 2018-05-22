/*

Anagramas
---------

Haz un programa que lee una secuencia de palabras y escribe por líneas los
grupos de palabras que son anagramas entre sí. Dos palabras son anagramas si
tienen exactamente las mismas letras pero en un orden distinto. Por ejemplo, si
la entrada del programa es

    corked weak strap artist war nails heat waste raw wake
    shape blow eat traps phase apt speak parts hate discern
    altering tea raising heaps

la salida será

    heaps phase shape
    hate heat
    wake weak
    eat tea
    parts strap traps
    raw war

Si una palabra no tiene anagramas no debe aparecer en la salida. Puedes suponer
que tienes una función ordena_letras que dado un string, devuelve otro string
con las letras ordenadas. Por ejemplo, ordena_letras("badc") devuelve "abcd".

*/

#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

string ordena_letras(string s) {
   sort(s.begin(), s.end());
   return s;
}

int main() {
   map<string, set<string>> A;
   string p;
   while (cin >> p) {
      A[ordena_letras(p)].insert(p);
   }
   for (auto it = A.begin(); it != A.end(); it++) {
      if (it->second.size() > 1) {
         for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
            cout << *it2 << ' ';
         }
         cout << endl;
      }
   }
}
