/*

Boyscouts
---------

En una agrupación de boyscouts/girlscouts se otorgan "badges", es decir pins
honoríficos por haber hecho ciertas cosas buenas. Tenemos un fichero
"scouts.txt" en el formato:

    charlie canoeing
    julie cycling
    martin camping
    martha graphic_arts
    paul chess
    ...

Cada línea tiene el nombre de un boyscout/girlscout y el badge otorgado, por 
orden cronológico. El programa debe simplemente mostrar cada boyscout/girlscout
y los badges que tiene en el formato:

    charlie: canoeing chess graphic_arts
    martha: cycling graphic_arts
    ...

Primero se pone el nombre del boyscout/girlscout, seguido de dos puntos y luego
la lista de badges hasta final de línea.

*/

#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace std;

int main() {
    ifstream scouts("scouts.txt");
    string name, badge;
    map<string, set<string>> badges; // clau: nom, valor: conjunt de badges
    while (scouts >> name >> badge) {
        badges[name].insert(badge);
    }

    for (auto it = badges.begin(); it != badges.end(); it++) {
        cout << it->first << ':';
        for (auto jt = it->second.begin(); jt != it->second.end(); jt++) {
            cout << ' ' << *jt;
        }
        cout << endl;
    }
}

