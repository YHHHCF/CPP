#include "function.h"

// include the header for compiler to check
// function delaration matches definition

size_t count_calls() {
    static size_t ctr = 0;
    cout << &ctr << endl; // same var with same address
    return ++ctr;
}
