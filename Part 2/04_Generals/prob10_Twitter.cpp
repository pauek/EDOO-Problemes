
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

/// Conjunt ///

class Conjunt {
  map<string, bool> _elems;
public:
  Conjunt() {} // ens va bé el constructor per defecte del map...

  void add(string s) { 
	 _elems[s] = true; 
  }

  bool contains(string s) const {
	 return _elems.find(s) != _elems.end();
  }

  int size() const { 
	 return _elems.size(); 
  }

  Conjunt intersect(const Conjunt& C) const;
  void escriu(ostream& o) const;
};

ostream& operator<<(ostream& o, const Conjunt& C) {
  C.escriu(o);
  return o;
}

Conjunt Conjunt::intersect(const Conjunt& C) const {
  Conjunt res;
  map<string, bool>::const_iterator it = _elems.begin();
  for (; it != _elems.end(); it++) {
	 if (C.contains(it->first)) {
		res.add(it->first);
	 }
  }
  return res;
}

void Conjunt::escriu(ostream& o) const {
  map<string, bool>::const_iterator it = _elems.begin();
  o << '{';
  bool primer = true;
  for (; it != _elems.end(); it++) {
	 if (!primer) o << ", ";
	 o << it->first;
	 primer = false;
  }
  o << '}';
}

/// Problema: Llegim un llistat de parelles de seguidor + seguit.
//  Després, per a cada parella d'usuaris, mostrem els seguidors comuns
//  i els seguits comuns.

struct Usuari {
  Conjunt segueix, el_segueixen;
};

int main() {
  ifstream F("twitter.txt");
  map<string, Usuari> U; // usuaris de Twitter
  string a, b;
  while (F >> a >> b) {   // 'a' segueix a 'b'
	 U[a].segueix.add(b); 
	 U[b].el_segueixen.add(a);
  }
  
  while (cin >> a >> b) {
	 cout << "Usuaris '" << a << "' i '" << b << "'" << endl;
	 cout << "- Seguidors comuns: " 
			<< U[a].el_segueixen.intersect(U[b].el_segueixen) << endl;
	 cout << "- Els dos segueixen: " 
			<< U[a].segueix.intersect(U[b].segueix) << endl;  
  }
}
