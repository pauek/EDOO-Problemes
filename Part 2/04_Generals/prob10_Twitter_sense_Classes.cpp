
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

/// Problema: Llegim un llistat de parelles de seguidor + seguit.
//  Després, per a cada parella d'usuaris, mostrem els seguidors comuns
//  i els seguits comuns.

struct Usuari {
   map<string, bool> segueix;
   map<string, bool> el_segueixen;
};

map<string, bool> intersecta(map<string, bool>& a, map<string, bool>& b) {
   map<string, bool> res;
   map<string, bool>::iterator it = a.begin();
   for (; it != a.end(); it++) {
      if (b.find(it->first) != b.end()) {
         res[it->first] = true;
      }
   }
   return res;
}

void mostra(const map<string, bool>& M) {
   map<string, bool>::const_iterator it = M.begin();
   cout << '{';
   bool primer = true;
   for (; it != M.end(); it++) {
      if (!primer) {
         cout << ", ";
      }
      cout << it->first;
      primer = false;
   }
   cout << '}';
}

int main() {
   ifstream F("twitter.txt");
   map<string, Usuari> U; // usuaris de Twitter
   string a, b;
   while (F >> a >> b) {  // 'a' segueix a 'b'
      U[a].segueix[b] = true;
      U[b].el_segueixen[a] = true;
   }
  
   while (cin >> a >> b) {
      cout << "Usuaris '" << a << "' i '" << b << "'" << endl;
      map<string, bool> s1 = intersecta(U[a].el_segueixen, U[b].el_segueixen);
      cout << "- Seguidors comuns: ";
      mostra(s1);
      cout << endl;
      map<string, bool> s2 = intersecta(U[a].segueix, U[b].segueix);
      cout << "- Els dos segueixen: ";
      mostra(s2);
      cout << endl;
   }
}
