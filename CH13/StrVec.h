#ifndef STRVEC_H
#define STRVEC_H

#include <iostream>

using std::cout; using std::endl; using std::string;

class StrVec {
public:
    StrVec() :
        elements(nullptr), first_free(nullptr), cap(nullptr) {
            cout << "Constructor called" << endl;
        }
    StrVec(const StrVec&); // copy constructor
    StrVec &operator=(const StrVec&);
    ~StrVec();
    void push_back(const string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string *begin() const { return elements; }
    string *end() const { return first_free; }

private:
    static std::allocator<string> alloc;
    void chk_n_alloc() {
        if (size() == capacity()) reallocate();
    }
    std::pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
    string *elements;
    string *first_free;
    string *cap;
};

#endif
