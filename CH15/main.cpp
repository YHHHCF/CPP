#include <iostream>
// including header files declares Quote and Bulk_quote
// needs to declare both to use them
#include "Quote.h"
#include "Disc_quote.h"
#include "Bulk_quote.h"
#include "Basket.h"

using std::cout; using std::endl;
using std::string; using std::size_t;

int main() {
    // base and derived class assignment
    Quote base("base1", 10); // base class object
    // // cannot create an object of abstract class
    // Disc_quote abstract("derived1", 10, 12, 0.1);
    Bulk_quote derived("derived1", 10, 12, 0.1); // derived class object
    cout << &base << ", " << &derived << endl;

    /* 
     * derived to base assignment compiles
     * it calls Quote's assignment operator and slice down
     * Bulk_quote's members
     */ 
    // base = derived; // compiles
    // cout << &base << ", " << &derived << endl;
    // derived = base; // cannot assign base to derived

    /*
     * Correct dynamic binding
     * can assign base ptr and ref to derived
     * cannot assign plain object as illustrated above
     * derive to base converstion happens implicitly
     */
    Quote *p_quote = &derived;
    Quote &r_quote = derived;
    
    // cannot do base to derive converstion
    // Bulk_quote *p_bulk = &base;
    // Bulk_quote &r_bulk = base;

    print_total(base, 20); // dynamic bind to Quote::net_price
    print_total(derived, 20); // dynamic bind to Bulk_quote::net_price
    cout << base.net_price(20) << endl; // staticly call Quote::net_price
    cout << derived.net_price(20) << endl; // staticly call Bulk_quote::net_price
    cout << derived.Quote::net_price(20) << endl; // staticly call Quote::net_price

    Basket bsk;
    bsk.add_item(std::make_shared<Quote>("111", 10)); // calls shared_ptr version
    bsk.add_item(std::make_shared<Bulk_quote>("222", 20, 3, 0.1)); // calls shared_ptr version
    bsk.add_item(base);
    bsk.add_item(std::move(derived));

    return 0;
}
