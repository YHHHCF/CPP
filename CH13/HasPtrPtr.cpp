#include <iostream>
#include "HasPtrPtr.h"

using std::cout; using std::endl;

HasPtrPtr::~HasPtrPtr() {
    cout << "Desctuctor called: " << this << ", " << ps << ", ";
    cout << "with ref cnt: " << *use << endl;
    if (--(*use) == 0) {
        cout << "Desctuctor: ref cnt is 0, delete ";
        cout << this << ", " << this->ps << endl;
        delete ps;
        delete use;
    }
}

HasPtrPtr& HasPtrPtr::operator=(const HasPtrPtr &rhs) {
    cout << "Copy assignment called: " << this << ", (" << this->ps << ")";
    cout << " <- " << rhs.ps << endl;
    ++(*(rhs.use));
    cout << "Copy assignment: new ref cnt is " << *(rhs.use) << endl;
    if (--(*use) == 0) {
        cout << "Copy assignment: old ref cnt is 0, delete ";
        cout << this << ", " << this->ps << endl;
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;

    return *this;
}

int main() {
    HasPtrPtr ptr1("ptr1"); // constructor
    HasPtrPtr *ptr2p = new HasPtrPtr("ptr2"); // constructor
    HasPtrPtr ptr3 = *ptr2p; // copy constructor
    HasPtrPtr ptr4; // constructor
    ptr4 = ptr3; // copy assignment

    delete ptr2p;

    cout << "=====program end=====" << endl;
    return 0;
}
// destruct ptr4
// destruct ptr3
// destruct ptr1
