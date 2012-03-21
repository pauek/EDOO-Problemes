
#include "DataHora.h"

DataHora::DataHora() 
// es crida el constructor per defecte de Data i Hora
{}

DataHora::DataHora(const Data& d, const Hora& h)
   : _data(d), _hora(h)
{}

DataHora::DataHora(int any, int mes, int dia,
                   int hora, int minut, int segon)
   : _data(dia, mes, any), _hora(hora, minut, segon) 
{}

DataHora::DataHora(const DataHora& altra) 
   : _data(altra._data), _hora(altra._hora)
{}

bool DataHora::operator<(const DataHora& altra) const {
   if (_data != altra._data) {
      return _data < altra._data;
   } else {
      return _hora < altra._hora;
   }
}

bool DataHora::operator==(const DataHora& altra) const {
   return _data == altra._data && _hora == altra._hora;
}

bool DataHora::operator>(const DataHora& altra) const {
   // utilitzem els altres mètodes
   return !operator==(altra) && !operator<(altra);
}

void DataHora::incr_segons(int segons) {
   int dies = _hora.incrementa(segons);
   _data += dies;
}

void DataHora::incr_dies(int dies) {
   _data += dies;
}

DataHora DataHora::operator+(int segons) const {
   DataHora resultat(_data, _hora);
   resultat += segons;
   return resultat;
}

void DataHora::escriu(ostream& o) const {
   _data.escriu(o);
   o << "-";
   _hora.escriu(o);
}

void DataHora::llegeix(istream& i) {
   char g;
   _data.llegeix(i);
   i >> g; // guió
   _hora.llegeix(i);
}

ostream& operator<<(ostream& o, const DataHora& dh) {
   dh.escriu(o);
   return o;
}

istream& operator>>(istream& i, DataHora& dh) {
   dh.llegeix(i);
   return i;
}
