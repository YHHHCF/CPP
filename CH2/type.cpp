#include <iostream>

int main() {
    // 1. Type alias by typedef
    typedef double wage; // wage is double
    typedef wage base; // base is wage, so base is double
    wage w = 10.0;
    base b = 5.0;
    double d = 11.1;

    typedef base *pbase; // pbase is a pointer to base
    // pbasse could refer to double, wage, base interchangibly
    pbase pb1 = &b;
    pbase pb2 = &w;
    pbase pb3 = &d;

    std::cout << w << ", " << b << ", " << *pb1 << ", " << *pb2 << ", " << *pb3 << std::endl;

    typedef char *pchar;
    const pchar pc = 0; // const is top level, not low level, not for char, but for pc
    // pc = 0; // compile error

    // 2. Type alias by using
    using db = double;
    db db1 = 1.1;
    std::cout << db1 << std::endl;

    // 3. auto: decuce type at compile time
    int i = 3;
    auto j = i, *ip = &i;
    // auto j = 1.0, *ip = &i; // compile error, j and ip does not have the same base type
    std::cout << j << ", " << *ip << std::endl;

    // init from reference
    int &ri = i;
    auto ai = ri; // ai is of type int copied from i, not a reference of i
    ai = 4;
    std::cout << ai << ", " << ri << std::endl;

    // top level const is ignored, low level const is kept
    const int ci = i, &cr = ci;
    auto i1 = ci; // copy of ci, no const
    auto i2 = cr; // another copy of ci, no const
    auto i3 = &i; // pointer to i
    auto i4 = &ci; // pointer to ci, keeps low level const

    std::cout << i1 << ", " << i2 << ", " << *i3 << ", " << *i4 << std::endl;
    i1 = 4;
    i2 = 5;
    *i3 = 6;
    // *i4 = 7; // compile error, low level const is kept;

    std::cout << i1 << ", " << i2 << ", " << *i3 << ", " << *i4 << std::endl;

    const auto i5 = ci; // a copy of ci, but has top level const

    // refernce to auto-deduced type
    auto &i6 = ci; // i6 bonds to ci, and has top level const

    // auto &i7 = 11; // compile error
    const auto &i7 = 11; // ok

    auto i8 = ci, &i9 = i; // i8 is int, i9 is int&
    auto &i10 = ci, *i11 = &ci; // i10 is const int&, i11 is a ptr to const int
    // auto &i12 = i, *i13 = &ci; // compile error: i12 is int&, i13 is prt to const int

    // 4. decltype
    const int ci1 = 0, &rci1 = ci1;
    decltype(ci1) x = 1; // x is const int, top level const is kept
    decltype(rci1) y = x; // y is const int&, binding to x

    int ii = 42, *pp = &ii, &rr = ii;
    decltype(rr) aa = ii; // rr is int&, so aa is int&
    decltype(rr + 0) bb; // result of expr: rr + 0 could not be on lhs of assignment, so bb is int
    int c = 43;
    decltype(*pp) cc = c; // result of expr *cc could be on lhs of assignment, so cc is int& not int, must be inited
    decltype(ii) dd; // var ii is not treated as expr, so dd is int
    decltype((ii)) ee = c; // (ii) is expr, and its result could be on lhs, so ee is int&

    return 0;
}
