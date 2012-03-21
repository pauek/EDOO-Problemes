
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Acumulador {
    double _max, _min, _suma;
    int _cont;
public:
    Acumulador();

    void nou_valor(double x);

    double maxim()   const { return _max; }
    double minim()   const { return _min; }
    double mitjana() const { return _suma / double(_cont); }
};

Acumulador::Acumulador() {
    _suma = 0.0;
    _cont = 0;
}

void Acumulador::nou_valor(double x) {
    if (_cont == 0) {
        _max = x;
        _min = x;
    } else {
        if (x > _max) _max = x;
        if (x < _min) _min = x;
    }
    _suma += x;
    _cont++;
}

int main() {
    ifstream F("dades.txt");
    int N;
    double x;
    F >> N;
    vector<Acumulador> A(N);
    string linia;
    getline(F, linia); // Menjarse el primer "endl"
    getline(F, linia); // Llegir primera linia
    while (!F.eof()) {
        istringstream S(linia);
        for (int i = 0; i < N; i++) {
            S >> x;
            A[i].nou_valor(x);
        }
        getline(F, linia);
    }

    for (int i = 0; i < N; i++) {
        cout << "Columna " << i+1 << ": ";
        cout << A[i].mitjana() << ' '
             << A[i].maxim() << ' '
             << A[i].minim() << endl;
    }
}
