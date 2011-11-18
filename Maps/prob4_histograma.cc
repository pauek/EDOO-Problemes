
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main() {
    int n;
    map<int, int> C;
    ifstream F;
    F.open("enters.txt");
    F >> n;
    while (!F.eof()) {
        map<int, int>::iterator it = C.find(n);
        if (it != C.end()) {
            (*it).second++;
        } else {
            C[n] = 1;
        }
        F >> n;
    }
    F.close();
    map<int, int>::iterator it = C.begin();
    for (; it != C.end(); it++) {
        cout << (*it).first << ' '
             << (*it).second << endl;
    }

}
