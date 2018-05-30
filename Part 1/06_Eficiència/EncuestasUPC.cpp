/*

Encuestas UPC 
-------------

Las encuestas a los estudiantes de la Universidad Polihédrica de Cataluña se
pueden enviar en qualquier momento. Los estudiantes utilizan una web y un
servidor recopila un fichero encuestas.txt de cada envio en el formato
siguiente:

   320099 1 4 3 5 5
   320002 1 1 2 1 1
   288073 4 3 4 5 4
   320099 1 1 1 1 2
   320099 4 4 4 5 4
   288073 4 4 4 4 5
   320099 5 5 5 5 5
   320002 3 4 3 5 3
   320002 5 4 4 4 4

Cada línea es la respuesta de un estudiante, que incluye el código de la
asignatura y la valoración entre 1 y 5 a las cinco preguntas que propone la
encuesta. La universidad tiene miles de asignaturas y cada asignatura decenas
de estudiantes, por tanto el fichero encuestas.txt es largo.

Se pide un programa que para cada asignatura muestre la nota media obtenida en
cada una de las 5 preguntas. Para hacer-lo hay que eliminar, antes de hacer la
media, la mejor y la peor encuesta de cada asignatura, ya que estas suelen ser
casos poco representativos (a menudo son opiniones demasiado sesgadas). Una
excepción a esto es que si hay menos de 3 encuestas no se pueden descartar los
extremos porque entonces no habría datos suficientes. Para comparar dos
encuestas se suman las valoraciones de cada pregunta y se comparan las sumas.

La salida del programa es, entonces, un listado con el código de la asignatura
y las 5 medias correspondientes a cada pregunta. Las asignaturas tienen que
salir por orden del código. Para el ejemplo anterior la salida sería:

   288073 4 3.5 4 4.5 4.5
   320002 3 4 3 5 3
   320099 2.5 4 3.5 5 4.5

*/

#include <map>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Enquesta {
   list<vector<int>> _enq;
public:
   Enquesta() {}
   void afegeix(const vector<int>& v);
   vector<float> mitjana();
};

int main() {
   map<int, Enquesta> E;
   ifstream F("encuestas.txt");
   int codi, x;
   while (F >> codi) {
      vector<int> valors;
      for (int i = 0; i < 5; i++) {
         F >> x;
         valors.push_back(x);
      }
      E[codi].afegeix(valors);
   }

   for (auto it = E.begin(); it != E.end(); it++) {
      vector<float> m = it->second.mitjana();
      cout << it->first;
      for (int j = 0; j < m.size(); j++) {
         cout << ' ' << m[j];
      }
      cout << endl;
   }
}

void Enquesta::afegeix(const vector<int>& v) {
   _enq.push_back(v);
}

bool menor(const vector<int>& a, const vector<int>& b) {
   int suma = 0, sumb = 0;
   for (int i = 0; i < 5; i++) {
      suma += a[i];
      sumb += b[i];
   }
   return suma < sumb;
}

vector<float> Enquesta::mitjana() {
   _enq.sort(menor);
   if (_enq.size() >= 3) {
      _enq.pop_front();
      _enq.pop_back();
   }
   vector<float> res(5, 0.0);
   for (auto it = _enq.begin(); it != _enq.end(); it++) {
      for (int j = 0; j < 5; j++) {
         res[j] += (*it)[j];
      }
   }
   for (int j = 0; j < 5; j++) {
      res[j] /= _enq.size();
   }
   return res;
}