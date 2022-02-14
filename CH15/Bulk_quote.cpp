#include "Bulk_quote.h"

// derived class can access protected base class member "price"
double Bulk_quote::net_price(size_t cnt) const {
    cout << "net_price is called in Bulk_quote: " << isbn() << endl;
    // net_price(cnt); // this will be an infinite recursive call
    // Quote::net_price(cnt); // this works
    if (cnt >= min_qty) {
        return cnt * (1 - discount) * price;
    } else {
        return cnt * price;
    }
}

