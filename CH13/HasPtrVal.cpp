#include <iostream>
#include "HasPtrVal.h"

using std::cout; using std::endl;

HasPtrVal& HasPtrVal::operator=(const HasPtrVal &rhs) {
    auto newps = new std::string(*(rhs.ps));
    cout << "Copy assignment called: (" << this->ps << ")";
    cout << " <- " << newps << " <- " << rhs.ps << endl;
    delete ps; // free this->ps, delete after new because rhs could be *this
    ps = newps;
    i = rhs.i;
    return *this;
}

int main() {
    HasPtrVal val1("val1"); // constructor
    HasPtrVal *val2p = new HasPtrVal("val2"); // constructor
    HasPtrVal val3 = *val2p; // copy constructor
    HasPtrVal val4; // constructor
    val4 = val3; // copy assignment

    delete val2p; // dynamic allocated object won't be destructed when out of scope

    cout << "=====program end=====" << endl;
    return 0;
}
// destruct val4
// destruct val3
// destruct val1
