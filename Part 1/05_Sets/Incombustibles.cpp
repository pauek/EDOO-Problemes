/*

Incombustibles
--------------

Haz un programa que lea una serie de líneas de enteros y muestre la lista de 
enteros que salen en todas las líneas. Por ejemplo, si la entrada es

    1 10 3 300 5 5000 7 70000 9 900000
    1 3 5 7 9 11 13 15 17 19 21
    1 1 1 2 3 3 4 5 7 7 7 7 8 9 9
    0 2 -1 3 5 9 1

la salida será

    1 3 5 9

Haz la suposición de que las listas de enteros pueden contener miles de elementos.

*/

#include <iostream>
#include <sstream>
#include <map>
#include <set>
using namespace std;

set<int> line2set(string line) {
   set<int> result;
   istringstream S(line);
   int x;
   while (S >> x) {
      result.insert(x);
   }
   return result;
}

set<int> intersection(const set<int>& A, const set<int>& B) {
   set<int> result;
   for (auto it = A.begin(); it != A.end(); it++) {
      if (B.find(*it) != B.end()) {
         result.insert(*it);
      }
   }
   return result;
}

int main() {
   string linea;
   getline(cin, linea);

   // Agafem la primera línia com a conjunt inicial
   set<int> incombustibles = line2set(linea);
   while (getline(cin, linea)) {
      // intersectem els apareguts en línies anteriors amb els actuals
      incombustibles = intersection(incombustibles, line2set(linea));
   }
   for (auto it = incombustibles.begin(); it != incombustibles.end(); it++) {
      cout << *it << ' ';
   }
   cout << endl;
}
