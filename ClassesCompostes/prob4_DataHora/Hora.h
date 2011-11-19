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

  bool anterior(const Hora& altra) const;
  bool igual(const Hora& altra) const;
  bool posterior(const Hora& altra) const;

  Hora diferencia(const Hora& altra) const;

  void escriu(ostream& o) const;
  void llegeix(istream& i);

};

#endif // HORA_H
