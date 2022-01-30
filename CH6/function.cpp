#include "function.h"

// include the header for compiler to check
// function delaration matches definition

size_t count_calls() {
    static size_t ctr = 0;
    cout << &ctr << endl; // same var with same address
    return ++ctr;
}

void arguments(int *a, int &b, int c) {
    *a += 1;
    b += 1;
    c += 1;
}

void reset(int &i) {
    i = 0;
    return;
}

void reset(int *i) {
    *i = 0;
    return;
}

void print_args(initializer_list<int> l) {
    for (auto it  = l.begin(); it != l.end(); ++it) {
        cout << *it << endl;
    }
}

void dosth(int &a, int &b) {
    cout << "dosth non const: " << (a + b) << endl;
    return;
}

void dosth(const int &a, const int &b) {
    cout << "dosth const: " << (a * b) << endl;
    return;
}

void dosth(const int &a, int &b) {
    cout << "dosth half const: " << (a - b) << endl;
    return;
}
