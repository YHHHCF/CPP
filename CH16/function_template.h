#include <iostream>

using std::cout; using std::endl;

/*
 * template parameter list has one item T
 * type template parameter must preceed with typename or class
 * keyword typename and class are used interchangeably
 *
 * template function declaration and definition both in .h file
 *
 * function has parameters as ref to const to ensure function
 * could be used on types that cannot be copied
 */
template <typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2) {
        return -1;
    }
    if (v2 < v1) { // some type may not support v1 > v2
        return 1;
    }
    
    return 0;
}

// nontype template parameter
template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M]) {
    cout << "N, M: " << N << ", " << M << endl;
    return strcmp(p1, p2);
}
