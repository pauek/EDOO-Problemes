
#ifndef INTERVAL_H
#define INTERVAL_H

class Interval {
   double _baix, _dalt;
public:
   Interval() : _baix(0.0), _dalt(0.0) {}
   Interval(const Interval& I) 
      : _baix(I.min), _dalt(I.max) {}
   Interval(double min, double max)
      : _baix(min), _dalt(max) {}

   double dalt() const { return _dalt; }
   double baix() const { return _baix; }

   double longitud() const { return _dalt - _baix; }

   Interval operator+(double x) const;
   void operator+=(double x) const;

   bool a_dins(double x) const {
      return x > _baix && x < _dalt;
   }
   
   bool inclos(const Interval& I) const {
      return a_dins(I._baix) && a_dins(I._dalt);
   }
   
};

#endif
