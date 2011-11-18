
#include "Hora.h"

#include <ctime>
#include <sstream>
using namespace std;

Hora::Hora() {
   time_t rawtime;
   time(&rawtime);
   struct tm *timeinfo = localtime(&rawtime);
   _hor = timeinfo->tm_hour;
   _min = timeinfo->tm_min;
   _seg = timeinfo->tm_sec;
}

Hora::Hora(const Hora& altra) {
   desde_segons(altra.a_segons());
}

Hora::Hora(int total_segons) {
   desde_segons(total_segons);
}

Hora::Hora(int h, int m, int s) {
   desde_segons((h * 60 + m) * 60 + s);
}

int Hora::a_segons() const {
   return (_hor * 60 + _min) * 60 + _seg;
}

void Hora::desde_segons(int segons) {
   if (segons < 0) {
      segons += 24 * 60 * 60;
   }
   _hor = (segons / 3600) % 24;
   segons %= 3600;
   _min = segons / 60;
   segons %= 60;
   _seg = segons;
}

void Hora::suma(int s) {
   desde_segons(a_segons() + s);
}

bool  Hora::anterior(const Hora& altra) const {
   return a_segons() < altra.a_segons();
}

string en2digits(int n) {
   ostringstream S;
   if (n < 10) S << '0';
   S << n;
   return S.str();
}

void Hora::escriu(ostream& o) const {
   o << en2digits(_hor) << ':' 
     << en2digits(_min) << ':' 
     << en2digits(_seg);
}

void Hora::llegeix(istream& i) {
   char p; // per llegir els dos punts
   int h, m, s;
   i >> h >> p >> m >> p >> s;
   desde_segons((h * 60 + m) * 60 + s);
}

Hora Hora::resta(const Hora& altra) const {
   Hora resultat(a_segons() - altra.a_segons());
   return resultat;
}
