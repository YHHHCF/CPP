#include <iostream>
#include "StrVec.h"

using std::cout; using std::endl; using std::pair;

// This is needed to access a static member
std::allocator<string> StrVec::alloc;

void StrVec::push_back(const string &s) {
    cout << "push_back copy: " << s << endl;
    chk_n_alloc();
    // copy construct since parameter is const ref
    alloc.construct(first_free++, s);
}

void StrVec::push_back(string &&s) {
    cout << "push_back move: " << s << endl;
    chk_n_alloc();
    // s is an rvalue ref, but itself is an lvalue
    // std::move(s) gets an rvalue
    alloc.construct(first_free++, std::move(s));
}

pair<string*, string*> StrVec::alloc_n_copy \
    (const string *b, const string *e) {
    cout << "alloc_n_copy called" << endl;
    // allocate (e - b) slots, data is the address of memory start
    auto data = alloc.allocate(e - b);
    // uninitialized_copy: copies elements to uninitialized memory
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    cout << "Free called" << endl;
    if (elements) {
        for (auto p = first_free; p != elements; ) {
            alloc.destroy(--p); // deconstruct the strings
        }
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s) {
    cout << "Copy constructor called" << endl;
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = newdata.second;
    cap = newdata.second;
}

StrVec &StrVec::operator=(const StrVec &rhs) {
    cout << "Copy assignment operator called" << endl;
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free(); // deconstruct and deallocate current memory
    elements = data.first;
    first_free = data.second;
    cap = data.second;

    return *this;
}

StrVec::StrVec(StrVec &&s) noexcept :
    elements(s.elements), first_free(s.first_free), cap(s.cap) {
    cout << "Move constructor called" << endl;
    s.elements = nullptr;
    s.first_free = nullptr;
    s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        cout << "Move assignment operator called" << endl;
        free(); // free existing elements
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;

        rhs.elements = nullptr;
        rhs.first_free = nullptr;
        rhs.cap = nullptr;
    } else {
        cout << "Move assignment operator called on self" << endl;
    }
    return *this;
}

StrVec::~StrVec() {
    cout << "Desctuctor called" << endl;
    free();
}

void StrVec::reallocate() {
    cout << "Reallocate called" << endl;
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);

    auto dest = newdata; // new memory start point
    auto elem = elements; // old memory start point
    for (size_t i = 0; i != size(); ++i) {
        // use move constructor, underlying string data
        // are not copied, now managed by dest
        // elem is able to destruct after being moved
        alloc.construct(dest++, std::move(*elem++));
    }
    free(); // safe to desctruct old memory after move
    elements = newdata;
    first_free = dest;  
    cap = elements + newcapacity;
}

void StrVec::print_addr() {
    cout << elements << ", " << first_free << ", " << cap << endl;
}

int main() {
    StrVec sv1 = StrVec();
    sv1.push_back("erbao");
    sv1.push_back("huang");
    sv1.push_back("1");
    sv1.push_back("2");
    sv1.push_back("3");
    sv1.push_back("4");
    StrVec sv2 = sv1; // copy constructor
    StrVec sv3;
    sv3 = sv2; // copy assignment operator

    StrVec sv4(std::move(StrVec())); // move constructor
    string name = "erbao";
    sv4.push_back(name); // calls copy version of push_back
    sv4.push_back("huang"); // calls move version of push_back

    StrVec sv5;
    sv5 = std::move(sv4); // move assignment operator is called since std::move returns a rvalue
    cout << &sv5 << ", " << &sv4 << endl; // different address
    sv4.print_addr(); // null ptrs
    sv5.print_addr(); // stealed from sv4

    sv5 = std::move(sv5); // move assignment operator called on self
    sv5.print_addr(); // nothing changes

    sv5 = sv5; // copy assignment operator on self
    sv5.print_addr(); // address changed (new allocation and copy happened)

    cout << "=====program end=====" << endl;
    return 0;
}
