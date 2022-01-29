#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 1. switch statement
    int flag = 22;

    switch (flag) {
        case 1:
            // string name; // default init, compile error
            // int x = 6; // cannot init here, compile error
            {
                // ok to init here since it is a block scope
                string name;
                int x = 6;
            }

            int ival; // uninited, ok
            int jval; // uninited, ok
            break;
        case 2:
            // int x = 6; // cannot init here, compile error
            ival = 2;
            jval = 3;
            cout << ival << ", " << jval << endl;
            break;
        default:
            string name; // ok to init here since no jump below
            int x = 6; // ok to init here since no jump below
            cout << ival << ", " << jval << endl;
            break;
    }

    // 2. for statement
    vector<int> v = {1, 3, 5, 7, 9};

    for (auto &r : v) { // needs ref to modify
        r *= 2;
    }

    for (auto it = v.begin(); it != v.end(); ++it) {
        auto &r = *it; // could be either ref or copy
        cout << r << endl;
    }

    // 3. goto statement
    goto label;
    // int m = 55; // compile error, cannot init here
    int m;

label:
    cout << m << endl;

    return 0;
}
