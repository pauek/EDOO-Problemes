/*

Parejas Distintas
-----------------

Haz un programa que lea una secuencia de parejas y luego escribe una lista con 
las distintas parejas que han aparecido, una por línea. 
Por ejemplo, si la entrada es:

   1 1 1 0 5 7 7 5 1 0 1 1 7 5 7 5 1 1 1 1

La salida será:

   1 0
   1 1
   5 7
   7 5

*/

#include <map>
#include <set>
#include <iostream>
using namespace std;

int main() {
   map<int, set<int>> parejas;
   int a, b;
   while (cin >> a >> b) {
      parejas[a].insert(b);
   }
   for (auto it1 = parejas.begin(); it1 != parejas.end(); it1++) {
      for (auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++) {
         cout << it1->first << ' ' << *it2 << endl;
      }
   }
}

