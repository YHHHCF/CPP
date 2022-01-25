#include <iostream>

int main() {
    // 1. const reference
    const int i = 1;
    const int &ri = i; // const reference or reference to const

    std::cout << i << ", " << ri << std::endl;

    // ri = 2; // compile error, const object cannot be modified
    // int &ri2 = i; // compile error, cannot bind ref to int to const int

    int j = 2;
    const int &rj = j;
    std::cout << j << ", " << rj << std::endl;

    // rj = 3; // compile error, rj is const ref
    j = 3; // j could be modifed
    std::cout << j << ", " << rj << std::endl;

    // 2. pointer to const (low level const, not ignored when copied)
    const double d1 = 1.1;
    double d2 = 2.2;

    const double *d1p = &d1;
    const double *d2p = &d2;
    // double *d1p2 = &d1; // compile error

    std::cout << *d1p << ", " << *d2p << std::endl;
    // d2p = 2.3; // compile time error
    d2 = 2.3;
    std::cout << *d1p << ", " << *d2p << std::endl;

    // 3. const pointer (top level const, ignored when copied)
    double d3 = 3.3;
    double d4 = 4.4;
    double *const d3p = &d3; // const ptr
    // d3p = &d4; // compile error, const ptr could not be reassigned
    std::cout << d3 << ", " << d4 << std::endl;
    *d3p = 3.4; // const ptr could modify the object it points to
    std::cout << d3 << ", " << d4 << std::endl;

    const double *const d4p = &d4; // const ptr to const
    std::cout << d4p << ", " << *d4p << std::endl;

    // 4. top level and low level const
    double d5 = 5.5;
    const double d6 = 6.6;

    double *d5p1 = &d5; // none
    const double *d5p2 = &d5; // low level
    const double *const d5p3 = &d5; // top level and low level

    const double *d6p1 = &d6; // low level
    const double *const d6p2 = &d6; // top level and low level

    // double *d7p1 = d6p1; // compile error, low level const is needed
    // double *const d7p1 = d6p1; // compile error, low level const is needed
    const double *d7p1 = d6p1;
    const double *const d7p2 = d6p1;
    const double *d7p3 = d7p2; // only low level is copied, top level is not

    std::cout << d7p3 << std::endl;
    d7p3 = &d5;
    std::cout << d7p3 << std::endl;

    // 5. constant expression are compile time constants
    int a;
    std::cin >> a;
    const int b = a; // b is const but is not known at compile time
    std::cout << b << std::endl;

    // constexpr int c = b; // illegal
    constexpr int c = 1; // constexpr could be inited from literal types
    constexpr int d = (c + c) * (c + c); // constexpr could be inited from constexpr

    constexpr int *e = nullptr; // const pointer, top level const
    const int *f = nullptr; // pointer to const, low level const

    return 0;
}