#ifndef RACIONAL_H
#define RACIONAL_H

#include <iostream>

class Racional {
public:
   Racional();
   Racional(const Racional& other);
   Racional(int num, int den);

   int numerador() const { return _num; }
   int denominador() const { return _den; }

   Racional operator+(const Racional& altre) const;
   Racional operator-(const Racional& altre) const;
   Racional operator/(const Racional& altre) const;
   Racional operator*(const Racional& altre) const;

   void operator+=(const Racional& altre);
   void operator-=(const Racional& altre);
   void operator*=(const Racional& altre);
   void operator/=(const Racional& altre);

   Racional operator*(int n) const;

   void escriu(std::ostream& o) const;
   void llegeix(std::istream& i);

private:
   int _num, _den;

   void normalitza();
};

std::ostream& operator<<(std::ostream& o, const Racional& r);
std::istream& operator>>(std::istream& i, Racional& r);

Racional operator*(int n, const Racional& r);

#endif // RACIONAL_H












