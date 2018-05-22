/*

Clones
------

Haz un programa que lee una secuencia de enteros donde todos los elementos 
aparecen 2 veces en la secuencia, excepto uno de ellos, que aparece una sola 
vez. El programa debe escribir el entero que sale una sola vez. Por ejemplo, 
si la entrada es

    2 1 8 9 0 5 7 4 7 2 3 3 1 9 6 6 8 0 5

la salida será

    4

Utiliza maps para agilizar el programa.

*/

#include <iostream>
#include <set>
using namespace std;

int main() {
   set<int> S;
   int x;
   while (cin >> x) {
      auto it = S.find(x);
      if (it != S.end()) {
         S.erase(it);
      } else {
         S.insert(x);
      }
   }
   // Com que sabem que només 1 enter compleix la condició el mostrem directament
   cout << *S.begin() << endl;
}
