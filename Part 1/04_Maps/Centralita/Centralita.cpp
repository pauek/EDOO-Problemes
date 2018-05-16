
#include <iostream>
#include <map>
#include <list>
#include <fstream>
using namespace std;

struct Hora { int h, m; };

class Trucada {
   int  _tel;
   Hora _inici, _fi;
   int  _duracio;
public:
   void comensa(int tel, Hora ini) { _tel = tel; _inici = ini; }
   void acaba(Hora fi);
    int duracio() const { return _duracio; }
   void mostra();
};

void Trucada::acaba(Hora fi) {
   _fi = fi;
   // Calculem duració
   int mini = _inici.h * 60 + _inici.m;
   int mfin = _fi.h * 60 + _fi.m;
   _duracio = mfin - mini;
   while (_duracio < 0) { // per si la trucada dura dies...
      _duracio += 24*60;
   }
}

bool major_duracio(const Trucada& t1, const Trucada& t2) {
   return t1.duracio() > t2.duracio();
}

void Trucada::mostra() {
   cout << _tel << ' ' 
        << _inici.h << ':' << _inici.m << " --> " << _fi.h << ':' << _fi.m << ' '
        << '(' << _duracio << "m)" << endl;
}

int main() {
   map<int, Trucada> en_curs;
   list<Trucada> historial;

   ifstream C("centralita.txt");
   int tel;
   Hora H;
   char c;
   string event;
   while (C >> tel >> H.h >> c >> H.m >> event) {
      /// Suposem que els events són correctes, o sigui totes les 
      /// trucades tenen 'start' i després 'end'
      if (event == "start") {
         en_curs[tel].comensa(tel, H);
      } else if (event == "end") {
         en_curs[tel].acaba(H);
         historial.push_back(en_curs[tel]);
         en_curs.erase(tel);
      } else {
         /// error
      }
   }
   historial.sort(major_duracio);
   auto it = historial.begin();
   for (int i = 0; i < 10; i++) {
      if (it != historial.end()) {
         it->mostra();
         it++;
      }
   }
}