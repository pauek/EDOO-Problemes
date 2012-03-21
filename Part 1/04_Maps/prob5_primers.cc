
#include <map>
#include <iostream>
using namespace std;

bool es_primer(int n) {
    for (int d = 2; d*d<n; d++) {
        if (n % d == 0) return false;
    }
    return true;
}

int main() {
    map<int, bool> primers;
    for (int i = 2; i <= 100000; i++) {
        if (es_primer(i)) {
            primers[i] = true;
        }
    }

    // Llegim enters fins el -1
    int n;
    cin >> n;
    while (n != -1) {
        if (primers.find(n) != primers.end()) {
            cout << "primer" << endl;
        }
        cin >> n;
    }
}
