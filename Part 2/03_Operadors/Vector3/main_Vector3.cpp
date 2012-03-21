
#include <iostream>
#include "Vector3.h"
using namespace std;

int main() {
    Vector3 v;
    Vector3 w(0, 1, 1);
    cin >> v;
    v += w;
    v = w + Vector3(0.5, 0.5, -0.5);
    cout << v << endl;
    w -= Vector3(2, 2, 2);
    cout << w << endl;
    cout << w * 2.5 << endl;
    cout << 2.5 * w << endl;
    cout << v.x() << endl;
    cout << w.z() << endl;
}
