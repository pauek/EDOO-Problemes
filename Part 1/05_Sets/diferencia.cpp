/*

Diferència
----------
Fer una funció que calcula la diferència entre dos conjunts.

*/

#include <iostream>
#include <set>
using namespace std;

set<int> diferencia_v1(const set<int>& A, const set<int>& B) {
   set<int> resultat = A;
   for (auto it = B.begin(); it != B.end(); it++) {
      resultat.erase(*it);
   }
   return resultat;
}

set<int> diferencia_v2(const set<int>& A, const set<int>& B) {
   set<int> resultat;
   for (auto it = A.begin(); it != A.end(); it++) {
      if (B.find(*it) == B.end()) {
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
   set<int> A = {1, 2, 3, 4, 5, 6};
   set<int> B = {2, 3, 5};

   set<int> A_menys_B_1 = diferencia_v1(A, B);
   set<int> A_menys_B_2 = diferencia_v2(A, B);

   print(A_menys_B_1); cout << endl;
   print(A_menys_B_2); cout << endl;

}