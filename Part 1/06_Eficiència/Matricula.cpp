/*

Matrícula
---------

La ESEIAAAAT ha hecho la matrícula recientemente y tiene un fichero
"matricula.txt" con las asignaturas que ha matriculado cada estudiante en el
formato:

   39326442K: 320092 320023 320166
   39937001F: 320039 320068 320422 320407
   42542730B: 320431 320322 320017 320006 320056
   43566594Y: 320205 320445 320240 320163 320194
   ...

Cada línea representa un estudiante, empezando por el DNI, y después de los
dos puntos hay una lista de las asignaturas a las que se ha matriculado el
estudiante.

También dispone de un fichero "estudiantes.txt" donde aparecen el DNI y el
nombre de cada estudiante, en el formato siguiente:

   38796931X Josué Castilla Pedrero
   45210451V Inocencio Mateos Zegarra
   43297178F Marc Palacios Celaya
   43484277I Godofredo Astorga Weffer
   ...

La ESEIAAAAT quiere una serie de ficheros con los listados de los alumnos
matriculados en cada asignatura. Los ficheros tienen un nombre como
320092.txt, que usa el código de la asignatura como nombre, y en cada fichero
debe haber la lista con los nombres de cada estudiante.

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

int main() {
   map<int, vector<string>> asigs;
   map<string, string> noms;
   string dni, nom, linia;

   // Llegim el fitxer de matrícula i posem cada estudiant 
   // a la seva assignatura, buscant per codi d'assignatura
   ifstream M("matricula.txt");
   while (getline(M, linia)) {
      int p = linia.find(':');
      dni = linia.substr(p);
      istringstream S(linia.substr(p+1));
      int codi;
      while (S >> codi) {
         asigs[codi].push_back(dni);
      }
   }

   // Llegim els noms dels estudiants per poder-los buscar per DNI
   ifstream E("estudiantes.txt");
   while (E >> dni) {
      getline(E, nom);
      nom.replace(0, 1, ""); // Treiem l'espai del davant
      noms[dni] = nom;
   }

   // Escrivim els llistats de cada assignatura
   for (auto it = asigs.begin(); it != asigs.end(); it++) {
      ostringstream oss; // el necessitem per poder produir el nom del fitxer
      oss << it->first << ".txt";
      ofstream A(oss.str());
      for (auto jt = it->second.begin(); jt != it->second.end(); jt++) {
         cout << noms[*jt] << endl;
      }
   }
}
