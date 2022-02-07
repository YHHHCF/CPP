#ifndef HASPTRPTR_H
#define HASPTRPTR_H

#include <iostream>

using std::cout; using std::endl;

class HasPtrPtr {
public:
    HasPtrPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0), use(new std::size_t(1)) {
        cout << "Constructor called: " << this << ", " << this->ps;
        cout << " <- " << &s << endl;
    }

    HasPtrPtr(const HasPtrPtr &p) :
        ps(p.ps), i(p.i), use(p.use) {
        ++(*use);
        cout << "Copy constructor called: " << this << ", " << this->ps;
        cout << " <- " << p.ps << endl;
        cout << "Reference count: " << *use << endl;
    }

    HasPtrPtr& operator=(const HasPtrPtr&);
    ~HasPtrPtr();

private:
    std::string *ps;
    int i;
    std::size_t *use; // ref cnt
};

#endif
