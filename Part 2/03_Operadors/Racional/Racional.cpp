#include "Racional.h"

int mcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void Racional::normalitza() {
    int M = mcd(_num, _den);
    _num /= M;
    _den /= M;
    if ((_num < 0 && _den < 0) ||
        (_den < 0 && _num > 0)) {
       _num = -_num;
       _den = -_den;
    }
}

Racional::Racional() {
   _num = 0;
   _den = 1;
}

Racional::Racional(const Racional& other) {
   _num = other._num;
   _den = other._den;
}

Racional::Racional(int num, int den) {
   _num = num;
   _den = den;
   normalitza();
}

Racional Racional::operator+(const Racional& altre) const {
   int a = _num, b = _den;
   int c = altre._num, d = altre._den;
   return Racional(a*d + c*b, b*d);
}

Racional Racional::operator-(const Racional& altre) const {
   int a = _num, b = _den;
   int c = altre._num, d = altre._den;
   return Racional(a*d - c*b, b*d);
}

Racional Racional::operator*(const Racional& altre) const {
   Racional resultat(_num, _den);
   resultat *= altre;
   return resultat;
}

Racional Racional::operator/(const Racional& altre) const {
   int a = _num, b = _den;
   int c = altre._num, d = altre._den;
   return Racional(a*d, b*c);
}

Racional Racional::operator*(int n) const {
   return Racional(_num * n, _den);
}

Racional operator*(int n, const Racional& r) {
   return r * n;
}

void Racional::operator*=(const Racional& altre) {
   int a = _num, b = _den;
   int c = altre._num, d = altre._den;
   _num = a*c;
   _den = b*d;
}



void Racional::escriu(std::ostream& o) const {
   o << _num;
   if (_den != 1) o << '/' << _den;
}

void Racional::llegeix(std::istream& i) {
   char b; // per llegir la '/'
   i >> _num >> b >> _den;
   normalitza();
}

std::ostream& operator<<(std::ostream& o, const Racional& r) {
   r.escriu(o);
   return o;
}

std::istream& operator>>(std::istream& i, Racional& r) {
   r.llegeix(i);
   return i;
}














