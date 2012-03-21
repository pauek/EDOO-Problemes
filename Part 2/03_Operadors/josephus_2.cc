
#include <list>
#include <iostream>
using namespace std;

class Iterador {
   list<int>& _llista;
   list<int>::iterator _i;

   void _comprova() {
      if (_i == _llista.end()) {
         _i = _llista.begin();
      }
   }

public:
   Iterador(list<int>& L) : _llista(L) {
      _i = _llista.begin();
   }

   void operator+=(int n) {
      for (int i = 0; i < n; i++) {
         _i++;
         _comprova();
      }
   }

   void esborra() {
      _i = _llista.erase(_i);
      _comprova();
   }
};

int main() {
   int N, k;
   cin >> N >> k;
   list<int> L;
   for (int i = 1; i <= N; i++) {
      L.push_back(i);
   }
   Iterador i(L);
   while (L.size() > 1) {
      i.esborra();
      i += k - 1;
   }
   cout << L.front() << endl;
}

