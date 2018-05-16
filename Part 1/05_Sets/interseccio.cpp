/*

Diferència
----------
Fer una funció que calcula la diferència entre dos conjunts.

*/

#include <iostream>
#include <set>
using namespace std;

set<int> interseccio(const set<int>& A, const set<int>& B) {
   set<int> resultat;
   for (auto it = A.begin(); it != A.end(); it++) {
      if (B.find(*it) != B.end()) {
         resultat.insert(*it);
      }
   }
   return resultat;
}

void print(const set<int>& A) {
   cout << '{';
   if (!A.empty()) {
      auto it = A.begin();
      cout << *it;
      for (it++; it != A.end(); it++) {
         cout << ", " << *it;
      }
   }
   cout << "}";
}

int main() {
   set<int> A = {1, 2, 4, 5, 6};
   set<int> B = {0, 2, 3, 5, 8};

   set<int> A_int_B = interseccio(A, B);
   print(A_int_B); cout << endl;
}