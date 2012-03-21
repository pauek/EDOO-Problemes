
#include "Vector3.h"
using namespace std;

Vector3::Vector3() {
   _x = 0.0;
   _y = 0.0;
   _z = 0.0;
}

Vector3::Vector3(const Vector3& other) {
   _x = other._x;
   _y = other._y;
   _z = other._z;
}

Vector3::Vector3(double x, double y, double z) {
   _x = x;
   _y = y;
   _z = z;
}

void Vector3::escriu(ostream& o) const {
   o << '(' << _x << ", "
            << _y << ", "
            << _z << ')';
}

void Vector3::llegeix(istream& i) {
   char c;
   i >> c >> _x >> c >> _y >> c >> _z >> c;
}

ostream& operator<<(ostream& o,
                    const Vector3& v) {
   v.escriu(o);
   return o;
}

istream& operator>>(istream& i,
                    Vector3& v) {
   v.llegeix(i);
   return i;
}

void Vector3::operator+=(const Vector3& v) {
   _x += v._x;
   _y += v._y;
   _z += v._z;
}

void Vector3::operator-=(const Vector3& v) {
   _x -= v._x;
   _y -= v._y;
   _z -= v._z;
}

Vector3 Vector3::operator+(const Vector3& altre) const {
   Vector3 resultat(_x, _y, _z);
   resultat += altre;
   return resultat;
}

Vector3 Vector3::operator-(const Vector3& altre) const {
   Vector3 resultat(_x, _y, _z);
   resultat -= altre;
   return resultat;
}

double Vector3::operator*(const Vector3& v) const {
   return _x*v._x + _y*v._y + _z*v._z;
}

Vector3 Vector3::operator*(double r) const {
   return Vector3(_x*r, _y*r, _z*r);
}

Vector3 operator*(double r, const Vector3& v) {
   return v * r;
}

bool Vector3::operator==(const Vector3& altre) const {
   return _x == altre._x &&
          _y == altre._y &&
          _z == altre._z;
}

