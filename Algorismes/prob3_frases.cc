
#include <cstdlib>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

int randint(int N) {
  return (N == 1 ? 0 : lrand48() % N);
}

void llegir_text(map<string, vector<string> >& P) {
  ifstream fin("exemple.txt");
  string upar = ".", par;
  fin >> par;
  while (!fin.eof()) {
    P[upar].push_back(par);
    upar = par;
    fin >> par;
  }
}

string genera_paraula(const map<string, vector<string> >& P, string par) {
  map<string, vector<string> >::const_iterator i = P.find(par);
  if (i == P.end()) {
    cout << "Error, paraula no trobada" << endl;
    exit(1); // aborta el programa
  }
  int N = i->second.size();
  return i->second[randint(N)];
}

void genera_frase(const map<string, vector<string> >& P, ostream& o) {
  string par = genera_paraula(P, ".");
  while (par != ".") {
    o << par << ' ';
    par = genera_paraula(P, par);
  }
}

int main() {
  map<string, vector<string> > P;
  llegir_text(P);

  int nfrases;
  cout << "Quantes frases vols generar? ";
  cin >> nfrases;
  
  for (int i = 0; i < nfrases; i++) {
    genera_frase(P, cout);
    cout << "." << endl;
  }
}
