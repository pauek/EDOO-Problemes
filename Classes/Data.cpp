
#include "Data.h"

#include <ctime>
using namespace std;

Data::Data() {
   time_t rawtime;
   time(&rawtime);
   struct tm *timeinfo = localtime(&rawtime);
   _dia = timeinfo->tm_mday;
   _mes = timeinfo->tm_mon + 1;
   _any = timeinfo->tm_year + 1900;
}

Data::Data(const Data& altra) {
   _dia = altra._dia;
   _mes = altra._mes;
   _any = altra._any;
}

Data::Data(int dia, int mes, int any) {
   _dia = dia;
   _mes = mes;
   _any = any;
}

bool Data::igual(const Data& altra) const {
   return 
      _dia == altra._dia && 
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

void Data::incrementa() {
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

