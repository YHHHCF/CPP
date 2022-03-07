#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
using std::cout; using std::endl;
using std::string; using std::size_t;

// the base class
class Quote {
public:
    Quote() = default;
    Quote(const string &book, double sales_price) :
        bookNo(book), price(sales_price) {
        cout << "class Quote is constructed: " << bookNo << endl;
    }

    Quote(const Quote&) = default; // copy constructor
    Quote(Quote&&) = default; // move constructor
    Quote &operator=(const Quote&) = default; // copy assign
    Quote &operator=(Quote&&) = default; // move assign

    // virtual function to return a dynamic allocated copy of itself
    // & indicates this points to lvalue ref, so copy constructor used
    virtual Quote *clone() const & {
        cout << "Quote copy constructor clone" << endl;
        return new Quote(*this);
    }
    // && indicates this points to rvalue ref, so move constructor used
    virtual Quote *clone() && {
        cout << "Quote move constructor clone" << endl;
        return new Quote(std::move(*this));
    }

    // derived classes will have the same isbn()
    // this is known at compile time
    string isbn() const { return bookNo; }

    // virtual keyword indicates derived classes will override net_price()
    // this is known at runtime, so it's called dynamic binding
    virtual double net_price(size_t n) const {
        cout << "net_price is called in Quote: " << bookNo << endl;
        return n * price;
    }
    // base class typically needs a virtual destructor
    // because dynamic binding is needed to destruct derived classes
    virtual ~Quote() = default;

// derived classes cannot access bookNo directly
// they are expected to access it using isbn() like other users
private:
    string bookNo;

// derived classes can access, but not other classes
// needed by net_price() defined in derived class
protected:
    double price = 0.0;
};

#endif
