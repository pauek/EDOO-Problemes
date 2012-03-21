
#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

void calcular_frequencies(map<string, int>& freq,
                          const string& genoma,
                          int N) {
   for (int i = 0; i <= genoma.size() - N; i++) {
       string tros = genoma.substr(i, N);
       freq[tros]++;
/*
       map<string, int>::iterator it = freq.find(tros);
       if (it != freq.end()) {
           (*it).second++;
       } else {
           freq[tros] = 1;
       }
*/
   }
}

void mostrar_frequencies(const map<string, int>& freq) {
   list< pair<int, string> > L;
   map<string, int>::const_iterator it = freq.begin();
   for (; it != freq.end(); it++) {
       L.push_back(make_pair((*it).second, (*it).first));
   }
   L.sort();
   list< pair<int, string> >::reverse_iterator rit = L.rbegin();
   for (int n = 0; rit != L.rend() && n < 10; rit++, n++) {
       cout << (*rit).first << ' ' << (*rit).second << endl;
   }
}

int main() {
    ifstream F("ecoli.txt");
    string genoma;
    char c;
    F >> c;
    while (!F.eof()) {
        genoma += c;
        F >> c;
    }
    int N;
    cout << "Tamany? ";
    cin >> N;
    map<string,int> freq;
    calcular_frequencies(freq, genoma, N);
    mostrar_frequencies(freq);
}
