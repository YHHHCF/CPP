#include <iostream>
using namespace std;

int main() {
    // 1. static cast
    int a = 1, b = 3;
    double slope = static_cast<double>(a) / b;
    cout << slope << endl;
    cout << static_cast<int>(slope) << endl; // trancate 0.33.. to 0

    void *slopep = &slope;
    // cout << *slopep << endl; // compile error
    cout << *(static_cast<double*>(slopep)) << endl;

    // 2. const_cast (cast away low level const)
    const int c1 = 5;
    const int *c1p = &c1;

    // int *c2p = c1p; // compile error
    int *c2p = const_cast<int*>(c1p);

    // they are exactly same address, but only c2p can modify
    cout << c1p << ", " << c2p << ", " << &c1 << endl;

    // *c1p = 6; // cannot modify
    // c1 = 6; // cannot modify
    *c2p = 6; // ok to modify
    cout << *c2p << endl;

    // 3. reinterpret_cast(reinterpret bit for an address)
    int i1 = -2;
    int *i1p = &i1;
    cout << i1p << ": " << *i1p << endl;

    // same address but interpreted as unsigned int
    unsigned *i2p = reinterpret_cast<unsigned*>(i1p);
    cout << i2p << ": " << *i2p << endl;

    return 0;
}
