
#ifndef DATAHORA_H
#define DATAHORA_H

#include "Data.h"
#include "Hora.h"

class DataHora {
   Data _data;
   Hora _hora;
public:
   DataHora();
   DataHora(const Data& data, const Hora& hora);
   DataHora(int any, int mes, int dia, 
            int hora, int minut, int segon);
   DataHora(const DataHora& altra);

   int any()   const { return _data.any(); }
   int mes()   const { return _data.mes(); }
   int dia()   const { return _data.dia(); }
   int hora()  const { return _hora.hora(); }
   int minut() const { return _hora.minut(); }
   int segon() const { return _hora.segon(); }

   bool operator<(const DataHora& altra) const;
   bool operator==(const DataHora& altra) const;
   bool operator>(const DataHora& altra) const;
   bool operator!=(const DataHora& altra) const {
      return ! operator==(altra);
   }

   void operator++() {
      incr_segons(1);
   }

   void incr_segons(int segons);
   void incr_dies(int dies);

   void operator+=(int segons) { incr_segons(segons); }
   DataHora operator+(int segons) const;
   
   void escriu(ostream& o) const;
   void llegeix(istream& i);   
};

ostream& operator<<(ostream& o, const DataHora& dh);
istream& operator>>(istream& i, DataHora& dh);

#endif
