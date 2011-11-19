#ifndef HORA_H
#define HORA_H

#include <iostream>
using namespace std;

class Hora {
   int _hor, _min, _seg;

   void desde_segons(int segons);

public:
   Hora();
   Hora(const Hora& other);
   Hora(int h, int m, int s);

   int a_segons() const {
      return (_hor * 60 + _min) * 60 + _seg;
   }

   int hora()  const { return _hor; }
   int minut() const { return _min; }
   int segon() const { return _seg; }

   // hem canviat el nom del mètode i ara retorna 'int'
   int incrementa(int segons);
   void operator+=(int segons);
   Hora operator+(int segons) const;

   bool operator<(const Hora& altra) const;
   bool operator==(const Hora& altra) const;
   bool operator>(const Hora& altra) const;
   bool operator!=(const Hora& altra) const {
      return ! operator==(altra);
   }

   Hora operator-(const Hora& altra) const;

   void escriu(ostream& o) const;
   void llegeix(istream& i);

};

ostream& operator<<(ostream& o, const Hora& d);
istream& operator>>(istream& i, Hora& d);


#endif // HORA_H
