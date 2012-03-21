
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

   void operator++();
   void operator+=(int dies);
   Data operator+(int dies) const;

   bool operator<(const Data& altra) const;
   bool operator==(const Data& altra) const;
   bool operator>(const Data& altra) const;
   bool operator!=(const Data& altra) const {
      return ! operator==(altra);
   }

   void escriu(ostream& o) const;
   void llegeix(istream& i);

private:
   int _dia, _mes, _any;
};

ostream& operator<<(ostream& o, const Data& d);
istream& operator>>(istream& i, Data& d);

#endif // DATA_H
