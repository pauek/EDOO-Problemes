#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>

class Vector3 {
public:
    Vector3();
    Vector3(const Vector3& other);
    Vector3(double x, double y, double z);

    double x() const { return _x; }
    double y() const { return _y; }
    double z() const { return _z; }

    void operator+=(const Vector3& v);
    void operator-=(const Vector3& v);

    Vector3 operator+(const Vector3&) const;
    Vector3 operator-(const Vector3&) const;
    double  operator*(const Vector3&) const;
    Vector3 operator*(double r) const;

    bool operator==(const Vector3&) const;
    bool operator!=(const Vector3& v) const {
       return ! operator==(v);
    }

    void escriu(std::ostream& o) const;
    void llegeix(std::istream& i);

private:
    double _x;
    double _y;
    double _z;
};

std::ostream& operator<<(std::ostream& o,
                         const Vector3& v);

std::istream& operator>>(std::istream& i,
                         Vector3& v);

Vector3 operator*(double r, const Vector3& v);




#endif // VECTOR3_H
