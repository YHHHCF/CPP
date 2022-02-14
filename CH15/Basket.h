#ifndef BASKET_H
#define BASKET_H

#include <iostream>
#include <set> // for std::multiset
#include "Quote.h"
#include "Disc_quote.h"
#include "Bulk_quote.h"
using std::cout; using std::endl;
using std::string; using std::size_t;

double print_total(const Quote&, size_t);

// container class to hold base (Quote) and derivative class items
class Basket {
public:
    void add_item(const std::shared_ptr<Quote> &sale) {
        cout << "Add item by passing shared_ptr" << endl;
        items.insert(sale);
    }

    // copy the object
    void add_item(const Quote &sale) {
        cout << "Add item by passing lvalue ref" << endl;
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }

    // move the object
    void add_item(Quote &&sale) {
        cout << "Add item by passing rvalue ref" << endl;
        /*
         *sale is an rvalue ref, but itself is an lvalue
         * need to do std::move(sale) to get rvalue
         * so this will overload the clone version with this being
         * a pointer to rvalue ref
         */
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }

    double total_receipt() const;

private:
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }

    // multiset ordered by compare callable
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};

};

#endif
