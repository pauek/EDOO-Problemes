
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

bool DataHora::anterior(const DataHora& altra) const {
   if (!_data.igual(altra._data)) {
      return _data.anterior(altra._data);
   } else {
      return _hora.anterior(altra._hora);
   }
}

bool DataHora::igual(const DataHora& altra) const {
   return _data.igual(altra._data) && _hora.igual(altra._hora);
}

bool DataHora::posterior(const DataHora& altra) const {
   // utilitzem els altres mètodes
   return !igual(altra) && !anterior(altra);
}

void DataHora::incr_segons(int segons) {
   int dies = _hora.incrementa(segons);
   _data.incrementa(dies);
}

void DataHora::incr_dies(int dies) {
   _data.incrementa(dies);
}

void DataHora::escriu(ostream& o) const {
   _data.escriu(o);
   o << "-";
   _hora.escriu(o);
}

void DataHora::llegeix(istream& i) {
   char g;
   _data.llegeix(i);
   cin >> g; // guió
   _hora.llegeix(i);
}


