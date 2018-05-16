/*

Godó
----

En el trofeo Conde de Godó utilizan un sistema de entradas que te permite
imprimirte las entradas tú mismo. Puedes entrar y salir del recinto tantas veces
como quieras. Para que funcione, al entrar presentas un papel con un código de
barras que te escanean para saber si puedes entrar, y tu código de entrada queda
marcado como "dentro". Al salir, tu entrada queda marcada como "fuera" para
cuando quieras volver a entrar.

Haz un programa que lee una secuencia de códigos de entradas acompañados por el
valor "entra" o "sale" (según la intención de la persona) como el siguiente:

    09834 entra
    00981 entra
    23740 entra
    09834 sale
    23740 sale
    23740 entra
    09834 entra
    18740 sale
    00981 entra
    09834 sale
    23740 sale
    18740 entra

y muestra por pantalla el mensaje de error cada vez que surge
uno de los dos errores siguientes: 
1) porque álguien intenta entrar con una entrada que ya está marcada como "dentro", o 
2) porque al salir la entrada ya estaba marcada como "fuera".

La salida del programa con el ejemplo anterior sería:

    ERROR: 18740 intenta salir pero estaba fuera.
   ERROR: 981 intenta entrar pero estaba dentro.

El número de entradas vendidas es de varios miles.

*/

#include <set>
#include <iostream>
using namespace std;

int main() {
   int entrada;
   string accion;

   set<int> dentro;

   while (cin >> entrada >> accion) {
      if (accion == "entra") {
         if (dentro.find(entrada) != dentro.end()) {
            cout << "ERROR: " << entrada << " intenta entrar pero estaba dentro." << endl;
         } else {
            dentro.insert(entrada);
         }
      } else if (accion == "sale") {
         if (dentro.find(entrada) == dentro.end()) {
            cout << "ERROR: " << entrada << " intenta salir pero estaba fuera." << endl;
         } else {
            dentro.erase(entrada);
         }
      } else {
         cout << "ERROR: accion " << accion << " incorrecta." << endl;
      }
   }
}