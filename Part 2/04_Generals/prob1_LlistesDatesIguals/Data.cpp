
#include <ctime> // per treure l'hora de l'ordinador
using namespace std;

#include "Data.h"

Data::Data() {
   time_t raw;
   time(&raw);
   struct tm *info;
   info = localtime(&raw);
   _dia = info->tm_mday;
   _mes = info->tm_mon + 1;
   _any = info->tm_year + 1900;
}

Data::Data(const Data& altra) {
   _dia = altra._dia;
   _mes = altra._mes;
   _any = altra._any;
}

Data::Data(int d, int m, int a) {
    _dia = d;
    _mes = m;
    _any = a;
}

const int taula_dies_mes[13] = {
   0, // ignorarem la casella 0
   31, 28, 31, 30, 31, 30, 31,
   31, 30, 31, 30, 31
};

bool de_traspas(int a) {
   return (a % 4 == 0 && a % 100 != 0) || a % 400 == 0;
}

int dies_mes(int mes, int any) {
   if (de_traspas(any) && mes == 2) {
      return 29;
   } else {
      return taula_dies_mes[mes];
   }
}

void Data::operator++() {
    _dia++;
    if (_dia > dies_mes(_mes, _any)) {
        _dia = 1;
        _mes++;
        if (_mes > 12) {
            _mes = 1;
            _any++;
        }
    }
}

void Data::operator+=(int dies) {
   while (dies > 0) {
      operator++();
      dies--;
   }
}

Data Data::operator+(int dies) const {
   Data res(_dia, _mes, _any);
   res += dies;
   return res;
}

bool Data::operator<(const Data& altra) const {
   if (_any != altra._any) {
      return _any < altra._any;
   } else if (_mes != altra._mes) {
      return _mes < altra._mes;
   } else {
      return _dia < altra._dia;
   }
}

bool Data::operator>(const Data& altra) const {
   return !(operator==(altra) || operator<(altra));
}

bool Data::operator==(const Data& altra) const {
   return _dia == altra._dia &&
          _mes == altra._mes &&
          _any == altra._any;
}

void Data::escriu(ostream& o) const {
    o << _dia << '/' << _mes << '/' << _any;
}


void Data::llegeix(istream& i) {
   char b; // llegirem la '/'
   i >> _dia >> b >> _mes >> b >> _any;
}

ostream& operator<<(ostream& o, const Data& d) {
   d.escriu(o);
   return o;
}

istream& operator>>(istream& i, Data& d) {
   d.llegeix(i);
   return i;
}


