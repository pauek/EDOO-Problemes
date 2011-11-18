
#ifndef DATA_H
#define DATA_H

#include <iostream>
using namespace std;

class Data {
   int _dia, _mes, _any;
public:
   Data();
   Data(const Data& altra);
   Data(int dia, int mes, int any);

   int dia() const { return _dia; }
   int mes() const { return _mes; }
   int any() const { return _any; }

   void incrementa();
   bool igual(const Data& altra) const;
   void escriu(ostream& o) const;
   void llegeix(istream& i);
};

#endif
