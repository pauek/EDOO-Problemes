/*

Telefonos 
---------

Tenemos un fichero 'llamadas.txt' con un listado desordenado de las llamadas
recibidas durante un día, con el teléfono llamado y la hora de la llamada en el
formato "HH:MM"

    789890347 15:45
    979123412 09:09
    655787931 10:43
    934552728 05:31
    ...

Haz un programa que muestra una lista de los teléfonos que han recibido almenos
una llamada para cada valor distinto de las horas (00, 01, 02 hasta 23).

*/

#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace std;

int main() {
   map<int, set<int>> T;
   ifstream F("llamadas.txt");
   char c;
   int tel, hora, minut;
   while (F >> tel >> hora >> c >> minut) {
      T[tel].insert(hora);
   }
   for (auto it = T.begin(); it != T.end(); it++) {
      // Si hi ha 24 valors diferents, vol dir que hi són totes les hores
      if (it->second.size() == 24) { 
         cout << it->first << endl;
      }
   }
}
