#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include <iostream>
// needs to declare base classes' headers
#include "Quote.h"
#include "Disc_quote.h"
using std::cout; using std::endl;
using std::string; using std::size_t;

// Bulk_quote derived from Quote publicly
class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double price,
               size_t qty, double disc) :
               Disc_quote(book, price, qty, disc) {
        cout << "class Bulk_quote is constructed: " << isbn() << endl;
    }
    // using Disc_quote::Disc_quote; // inherit Disc_quote's constructors

    // overrides Quote's clone() functions
    Bulk_quote *clone() const & override {
        cout << "Bulk_quote copy constructor clone" << endl;
        return new Bulk_quote(*this);
    }
    Bulk_quote *clone() && override {
        cout << "Bulk_quote move constructor clone" << endl;
        return new Bulk_quote(std::move(*this));
    }

    /*
     * overrides base class virtual net_price()
     * if net_prices is declared but not defined
     * then it will compile but has linking error below
     * "Undefined symbols for architecture arm64"
     */
    double net_price(size_t) const override;

private:
    size_t min_qty = 0;
    double discount = 0.0;
};

#endif
