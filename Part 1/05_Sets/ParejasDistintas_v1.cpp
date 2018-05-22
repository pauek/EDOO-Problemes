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

#include <set>
#include <iostream>
using namespace std;

int main() {
   set<pair<int, int>> parejas;
   int a, b;
   while (cin >> a >> b) {
      parejas.insert(make_pair(a, b));
   }
   for (auto it = parejas.begin(); it != parejas.end(); it++) {
      cout << it->first << ' ' << it->second << endl;
   }
}

