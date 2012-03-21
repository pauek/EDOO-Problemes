
#ifndef CONJUNT_H
#define CONJUNT_H

#include <map>
#include <iostream>

class Conjunt {
   std::map<int, bool> _elems;

   Conjunt(const std::map<int, bool>& elems);
public:
   Conjunt();
   Conjunt(const Conjunt& altre);

   // afegeix un element al conjunt
   void posa(int n) { _elems[n] = true; }
   
   // treu un element del conjunt
   void treu(int n) { _elems.erase(n); }

   // retorna 'true' si 'n' pertany al conjunt
   bool pertany(int n) const { 
      return _elems.find(n) != _elems.end(); 
   }

   // A += B: Afegeix tots els elements de B a A.
   void operator+=(const Conjunt& altre);

   // A -= B: Treu els elements de B de A.
   void operator-=(const Conjunt& altre);
   
   // A + B: Unió de conjunts
   Conjunt operator+(const Conjunt& altre) const;

   // A - B: Elements de A que no estan a B.
   Conjunt operator-(const Conjunt& altre) const;
   
   // A && B: Intersecció d'A i B.
   Conjunt operator&&(const Conjunt& altre) const;

   bool operator==(const Conjunt& altre) const;
   bool operator!=(const Conjunt& altre) const;
   
   // A > B: Tots els elements de B estan a A, tot i que algun element de A no està a B.
   bool operator> (const Conjunt& altre) const;

   // A < B: B conté a A, però hi ha elements de B que no estan a A.
   bool operator< (const Conjunt& altre) const;

   // A >= B: Tots els elements de B estan a A (i pot ser que A sigui igual que B)
   bool operator>=(const Conjunt& altre) const;

   // A <= B: Tots els elements de A estan a B (i pot ser que B sigui igual que A)
   bool operator<=(const Conjunt& altre) const;


   void escriu(std::ostream& o) const;
   void llegeix(std::istream& i);
};

std::ostream& operator<<(std::ostream& o, const Conjunt& C);
std::istream& operator>>(std::istream& i, Conjunt& C);

#endif
