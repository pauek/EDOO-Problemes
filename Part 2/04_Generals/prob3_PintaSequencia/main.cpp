#include <iostream>
#include <vector>
using namespace std;

#include "Imatge.h"

int main() {
   vector<int> seq;
   int n, max;
   cin >> n;
   max = n;
   while (n != -1) {
       seq.push_back(n);
       if (n > max) max = n;
       cin >> n;
   }

   Imatge I(seq.size(), max);
   for (int i = 0; i < seq.size(); i++) {
       for (int j = 0; j < max; j++) {
           int a = max - j;
           if (a > seq[i]) {
               I.setpixel(j, i, 255);
           } else {
               I.setpixel(j, i, 0);
           }
       }
   }
   I.escriu("imatge.pgm");
}
