
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Poblacio {
  string nom;
  double lat, lon;
};

double distancia(const Poblacio& c1, const Poblacio& c2) {
  const double dlat = c1.lat - c2.lat;
  const double dlon = c1.lon - c2.lon;
  return sqrt(dlat*dlat + dlon*dlon);
}

struct Parella { 
  int c1, c2;
  double dist;
};

bool dist_menor(const Parella& p1, const Parella& p2) {
  return p1.dist < p2.dist;  
}

vector<Parella> distancies_minimes(const vector<Poblacio>& v, int N) {
  vector<Parella> distancies;
  const int tam = v.size();
  for (int i = 0; i < tam; i++) {
    for (int j = i + 1; j < tam; j++) {
      Parella D = { i, j, distancia(v[i], v[j]) };
      distancies.push_back(D);
    }
  }
  sort(distancies.begin(), distancies.end(), dist_menor);
  if (distancies.size() > N) {
    distancies.resize(N);
  }
  return distancies;
}

void llegeix_poblacions(string nom_fitxer, vector<Poblacio>& pobl) {
  ifstream F(nom_fitxer.c_str());
  if (!F.is_open()) {
    cout << "No he pogut obrir el fitxer." << endl;
    return;
  }
  Poblacio C;
  pobl.clear();
  F >> C.nom >> C.lat >> C.lon;
  while (!F.eof()) {
    pobl.push_back(C);
    F >> C.nom >> C.lat >> C.lon;
  }
}

int main() {
  vector<Poblacio> pobl;
  llegeix_poblacions("poblacions.txt", pobl);
  int N;
  cin >> N;
  vector<Parella> res = distancies_minimes(pobl, N);
  vector<Parella>::iterator it = res.begin();
  for (; it != res.end(); it++) {
    cout << (*it).dist << ": " 
	 << pobl[(*it).c1].nom << ' ' 
	 << pobl[(*it).c2].nom << endl;
  }
}
