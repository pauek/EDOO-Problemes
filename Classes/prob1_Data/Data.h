
#ifndef DATA_H
#define DATA_H

#include <iostream>
using namespace std;

class Data {
public:
   Data();
   Data(const Data& altra);
   Data(int d, int m, int a);

   int dia() const { return _dia; }
   int mes() const { return _mes; }
   int any() const { return _any; }

   void incrementa();
   void incrementa(int dies);

   bool anterior(const Data& altra) const;
   bool igual(const Data& altra) const;
   bool posterior(const Data& altra) const;

   void escriu(ostream& o) const;
   void llegeix(istream& i);

private:
   int _dia, _mes, _any;
};

#endif // DATA_H
