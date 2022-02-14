#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include <iostream>
// needs to declare base class by including its header
#include "Quote.h"
using std::cout; using std::endl;
using std::string; using std::size_t;

// Abstract class constains pure virtual function
class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    /*
     * construct base first, then init derived class members
     * derived class should not access base class class members directly
     * instead it should use base class constructor to init base class members
     */
    Disc_quote(const string &book, double price,
               size_t qty, double disc) :
               Quote(book, price),
               quantity(qty), discount(disc) {
        cout << "class Disc_quote is constructed: " << isbn() << endl;
    }

    double net_price(size_t) const = 0; // pure virtual function
private:
    size_t quantity = 0;
    double discount = 0.0;
};

#endif
