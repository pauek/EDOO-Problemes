
#ifndef HORA_H
#define HORA_H

#include <iostream>
using namespace std;

class Hora {
   int _hor, _min, _seg;

   int a_segons() const;
   void desde_segons(int segons);

public:
   Hora();
   Hora(int total_segons);
   Hora(const Hora& altra);
   Hora(int h, int m, int s);

   int hora()  const { return _hor; }
   int minut() const { return _min; }
   int segon() const { return _seg; }

   void suma(int s);
   bool anterior(const Hora& altra) const;
   void escriu(ostream& o) const;
   void llegeix(istream& i);   
   Hora resta(const Hora& altra) const;
};

#endif
