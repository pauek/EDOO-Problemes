
#include "Conjunt.h"
#include <map>
#include <sstream>
using namespace std;

Conjunt::Conjunt() 
// es crida el constructor per defecte de _elems
{}

Conjunt::Conjunt(const Conjunt& altre)
   : _elems(altre._elems)
{}

Conjunt::Conjunt(const map<int, bool>& elems)
   : _elems(elems)
{}

void Conjunt::operator+=(const Conjunt& altre) {
   map<int, bool>::const_iterator it = altre._elems.begin();
   for (; it != altre._elems.end(); it++) {
      _elems[(*it).first] = true;
   }
}

void Conjunt::operator-=(const Conjunt& altre) {
   map<int, bool>::const_iterator it = altre._elems.begin();
   for (; it != altre._elems.end(); it++) {
      _elems.erase((*it).first);
   }
}

Conjunt Conjunt::operator+(const Conjunt& altre) const {
   Conjunt C(_elems);
   C += altre;
   return C;   
}

Conjunt Conjunt::operator-(const Conjunt& altre) const {
   Conjunt C(_elems);
   C -= altre;
   return C;
}

Conjunt Conjunt::operator&&(const Conjunt& altre) const {
   Conjunt C;
   map<int, bool>::const_iterator it = altre._elems.begin();
   for (; it != altre._elems.begin(); it++) {
      if (_elems.find((*it).first) != _elems.end()) {
         C.posa((*it).first);
      }
   }
   return C;
}

bool Conjunt::operator==(const Conjunt& altre) const {
   map<int, bool>::const_iterator it = _elems.begin();
   map<int, bool>::const_iterator jt = altre._elems.begin();
   while (it != _elems.end()) {
      if (jt == altre._elems.end() || 
          (*it).first != (*jt).first) {
         return false;
      }
      it++;
      jt++;
   }
   return jt == altre._elems.end();
}

bool Conjunt::operator!=(const Conjunt& altre) const {
   return ! operator==(altre);
}

bool Conjunt::operator> (const Conjunt& altre) const {
   if (_elems.size() <= altre._elems.size()) {
      return false;
   }
   map<int, bool>::const_iterator it = altre._elems.begin();
   for (; it != altre._elems.end(); it++) {
      if (_elems.find((*it).first) == _elems.end()) {
         return false;
      }
   }
   return true;
}

bool Conjunt::operator<(const Conjunt& altre) const {
   if (altre._elems.size() <= _elems.size()) {
      return false;
   }
   map<int, bool>::const_iterator it = _elems.begin();
   for (; it != _elems.end(); it++) {
      if (altre._elems.find((*it).first) == altre._elems.end()) {
         return false;
      }
   }
   return true;
}

bool Conjunt::operator>=(const Conjunt& altre) const {
   return operator==(altre) || operator>(altre);
}

bool Conjunt::operator<=(const Conjunt& altre) const {
   return operator==(altre) || operator<(altre);
}

// format: "{ 1, 2, 3, 4 }"
void Conjunt::escriu(ostream& o) const {
   o << "{";
   if (!_elems.empty()) {
      map<int, bool>::const_iterator it = _elems.begin();
      o << (*it).first;
      for (it++; it != _elems.end(); it++) {
         o << ", " << (*it).first;
      }
   }
   o << "}";
}

// format: "{ 1, 2, 3, 4 }"
void Conjunt::llegeix(istream& i) {
   _elems.clear();
   char c;
   string elems;
   // posem tot fins al pròxim '}' en un string,
   // substituint ',' per ' '
   i >> c; // el primer "{"
   i >> c; 
   while (c != '}') {
      if (c == ',') c = ' ';
      elems += c;
      i >> c;
   }
   // llegim els elements de l'string
   istringstream S(elems);
   int n;
   S >> n;
   while (!S.fail()) {
      _elems[n] = true;
      S >> n;
   }
}

ostream& operator<<(ostream& o, const Conjunt& C) {
   C.escriu(o); 
   return o;
}

istream& operator>>(istream& i, Conjunt& C) {
   C.llegeix(i);
   return i;
}
