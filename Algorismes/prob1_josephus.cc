
#include <list>
#include <iostream>
using namespace std;

void mostra(const list<int>& L, list<int>::iterator pos) {
   list<int>::const_iterator it = L.begin();
   for (it = L.begin(); it != L.end(); it++) {
      if (it != L.begin()) {
         cout << ' ';
      }
      if (it == pos) {
         cout << '[' << *it << ']';
      } else { 
         cout << *it;
      }
   }
   cout << endl;
}

list<int> rang(int inici, int fi) {
   list<int> res;
   for (int i = inici; i <= fi; i++) {
      res.push_back(i);
   }
   return res;
}

int josephus(int N, int k) {
   list<int> persones = rang(1, N);
   list<int>::iterator it = persones.begin();
   while (persones.size() > 1) {
      // mostra(persones, it);
      it = persones.erase(it);
      if (it == persones.end()) {
         it = persones.begin();
      }
      for (int i = 1; i < k; i++) {
         it++;
         if (it == persones.end()) {
            it = persones.begin();
         }
      }
   }
   return *it;
}

int main() {
   int N, k;
   cin >> N >> k;
   cout << josephus(N, k) << endl;
}
