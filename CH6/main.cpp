#include "function.h"

int main() {
    // 1. static variable
    // cout << ctr << endl; // compile error, cannot use outside of count_calls()

    for (int i = 0; i < 10; ++i) {
        cout << count_calls() << endl;
    }

    // cout << ctr << endl; // compile error

    // 2. ptr, ref, value args and const
    int a = 10, b = 10, c = 10;
    // arguments are ptr, ref, copy
    // ptr and ref modify a and b, copy of c
    // changed in function but does not modify c
    // better to use ref parameters to avoid copies
    arguments(&a, b, c);

    cout << a << ", " << b << ", " << c << endl;

    int ii = 4;
    cout << ii << endl;
    reset(ii); // calls reset(int &i)
    cout << ii << endl;

    ii =4;
    cout << ii << endl;
    reset(&ii); // calls reset(int *i)
    cout << ii << endl;

    const int cii = ii;
    // reset(&cii); // cannot use const int* to init int*
    // reset(cii); // cannot use const int& to init int&

    // 3. initializer_list with varible number of args
    int i1 = 1, i2 = 2, i3 = 3;
    print_args({i1, i2});
    print_args({11, i2, i3});
}
