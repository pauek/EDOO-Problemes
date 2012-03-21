
#include <iostream>
#include <fstream>
#include <list>
#include "Data.h"
using namespace std;

// L1 i L2 estan ordenades
int elements_iguals(const list<Data>& L1, const list<Data>& L2) {
   list<Data>::const_iterator it1 = L1.begin();
   list<Data>::const_iterator it2 = L2.begin();
   int iguals = 0;
   while (it1 != L1.end() && it2 != L2.end()) {
      if (*it1 == *it2) {
         iguals++;
         it1++;
         it2++;
      } else if (*it1 < *it2) {
         it1++;
      } else if (*it2 < *it1) {
         it2++;
      }
   }
   return iguals;
}

void llegeix_llista(string fitxer, list<Data>& L1) {
   ifstream F(fitxer.c_str());
   Data d;
   F >> d;
   while (!F.eof()) {
      L1.push_back(d);
      F >> d;
   }
}

int main() {
   list<Data> L1, L2;
   llegeix_llista("llista1.txt", L1);
   llegeix_llista("llista2.txt", L2);
   cout << elements_iguals(L1, L2) << endl;
   cout << elements_iguals(L2, L1) << endl;
}
