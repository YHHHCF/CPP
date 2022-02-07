#ifndef HASPTRVAL_H
#define HASPTRVAL_H

#include <iostream>

using std::cout; using std::endl;

class HasPtrVal {
public:
    HasPtrVal(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0) {
        cout << "Constructor called: " << this->ps;
        cout << " <- " << &s << endl;
    }

    // copy constructor allocats a new copy of the string pointed by ps
    // and a copy of i
    HasPtrVal(const HasPtrVal &p) :
        ps(new std::string(*(p.ps))), i(p.i) {
        cout << "Copy constructor called: " << this->ps;
        cout << " <- " << p.ps << endl;
    }

    HasPtrVal& operator=(const HasPtrVal &);

    ~HasPtrVal() {
        cout << "Desctuctor called: " << ps << endl;
        delete ps;
    }

private:
    std::string *ps;
    int i;
};

#endif
